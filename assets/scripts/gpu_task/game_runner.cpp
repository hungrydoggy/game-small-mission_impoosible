#ifndef SERVER_ONLY

#include "./game_runner.h"


NODE_LOADABLE_CREATOR_REGISTERER(GameTaskRunner);


#pragma pack(push, 1)
struct GpuComputeConfigData {
  ALIGNED_ARRAY(64, float   , 16) projview_mat;
  ALIGNED_FIELD( 4, uint32_t    ) object_count;
  ALIGNED_FIELD( 4, uint32_t    ) opaque_object_count;
  ALIGNED_FIELD( 4, uint32_t    ) opaque_index_count;
  ALIGNED_FIELD( 4, uint32_t    ) transparent_index_count;
};
#pragma pack(pop)


#pragma pack(push, 1)
struct GpuGlobalData {
  ALIGNED_FIELD(4, uint32_t) window_width;
  ALIGNED_FIELD(4, uint32_t) window_height;
  ALIGNED_FIELD(4, uint32_t) screen_width;
  ALIGNED_FIELD(4, uint32_t) screen_height;
  ALIGNED_ARRAY(64, float, 16) inv_proj_mat;
};
#pragma pack(pop)



static auto view_group_id = StringRegistry::default_registry().lookUp("view");
static auto vat_group_id  = StringRegistry::default_registry().lookUp("vertex_animation_texture_state");


shared_ptr<Sampler> g_swapchain_scale_sampler;
shared_ptr<Sampler> g_default_sampler;
shared_ptr<Sampler> g_default_comparison_sampler;



static inline void __fillRenderData (GameComponent* root_component, vector<RenderData>& render_datas) {

  render_datas.resize(0);

  for (auto& itr : GameComponentDescendantLooper(root_component, [](auto* cmp){ return cmp->is_drawable_self(); })) {
    // filter
    unlikely (itr->isGameObject() == false)
      continue;

    auto obj = dynamic_cast<GameObject*>(itr.get());
    auto view = obj->getTrait<View>(view_group_id);
    likely (view == null || view->state() == null)
      continue;


    // make render data
    auto render_datas_ok = view->state()->fillRenderDatas(render_datas, obj);
    unlikely (render_datas_ok == false) {
      LOG_ERR("cannot fill render data --- %s", obj->makePath().c_str());
      continue;
    }

  }
}


static inline bool __shouldCullObject (Matrix const& mvp_matrix, BoundingBox const& bb) {
    
  // make corners
  vector<Vector3> corners;
  likely (bb.min().z() == bb.max().z()) {
    corners = {
        Vector3(bb.min().x(), bb.min().y(), bb.min().z()),
        Vector3(bb.max().x(), bb.min().y(), bb.min().z()),
        Vector3(bb.min().x(), bb.max().y(), bb.min().z()),
        Vector3(bb.max().x(), bb.max().y(), bb.min().z()),
    };
  }else {
    corners = {
        Vector3(bb.min().x(), bb.min().y(), bb.min().z()),
        Vector3(bb.max().x(), bb.min().y(), bb.min().z()),
        Vector3(bb.min().x(), bb.max().y(), bb.min().z()),
        Vector3(bb.min().x(), bb.min().y(), bb.max().z()),
        Vector3(bb.max().x(), bb.max().y(), bb.min().z()),
        Vector3(bb.max().x(), bb.min().y(), bb.max().z()),
        Vector3(bb.min().x(), bb.max().y(), bb.max().z()),
        Vector3(bb.max().x(), bb.max().y(), bb.max().z())
    };
  }


  // count outs
  int out_left   = 0, out_right = 0;
  int out_bottom = 0, out_top   = 0;
  int out_near   = 0, out_far   = 0;

  for (auto& c : corners) {
    auto clip_v = mvp_matrix * Vector4(c, REAL(1.0));

    out_left   += (clip_v.x() < -clip_v.w());
    out_right  += (clip_v.x() >  clip_v.w());
    out_bottom += (clip_v.y() < -clip_v.w());
    out_top    += (clip_v.y() >  clip_v.w());
    out_near   += (clip_v.z() <  0.0f      );
    out_far    += (clip_v.z() >  clip_v.w());
  }

  // cull
  auto corner_count = (int)corners.size();
  return
      (out_left == corner_count || out_right == corner_count || out_bottom == corner_count ||
       out_top  == corner_count || out_near  == corner_count || out_far    == corner_count);
}


static inline void __cullRenderData (vector<RenderData>& render_datas) {
  auto new_end = std::remove_if(
      render_datas.begin(), 
      render_datas.end(),
      [](RenderData const& data) {
        auto& bounding_box = data.mesh_handle->bounding_box();
        return __shouldCullObject(data.transform, bounding_box);
      }
  );

  render_datas.erase(new_end, render_datas.end());
}


static inline bool __isTransparentRenderData (RenderData const& rd, StringRegistryIdType transparent_reg) {
  return (rd.material_reg == transparent_reg) || (rd.color_scale.alpha() < REAL(0.996));
}


// returns first idx of transparent material
static inline void __makeObjectData (
    vector<GameTaskRunner::GpuObjectInputData>& obj_datas,
    uint32_t& opaque_object_count,
    uint32_t& opaque_index_count,
    uint32_t& transparent_index_count,
    vector<RenderData> const& render_datas,
    StringRegistryIdType transparent_reg
) {
  
  obj_datas.resize(0);


  opaque_object_count = render_datas.size();
  opaque_index_count      = 0;
  transparent_index_count = 0;
  uint dst_index_offset  = 0;
  uint dst_vertex_offset = 0;
  for (uint32_t ri=0; ri<render_datas.size(); ++ri) {
    auto& rd = render_datas[ri];

    unlikely (opaque_object_count >= render_datas.size() && __isTransparentRenderData(rd, transparent_reg) == true)
      opaque_object_count = math::min(opaque_object_count, ri);


    auto& input_data = obj_datas.emplace_back();

    input_data.index_count.v   = rd.mesh_handle->index_count();
    input_data.first_index.v   = rd.mesh_handle->first_index();
    input_data.vertex_count.v  = rd.mesh_handle->vertex_count();
    input_data.first_vertex.v  = rd.mesh_handle->vertex_offset();
    input_data.dst_index_offset .v = dst_index_offset;
    input_data.dst_vertex_offset.v = dst_vertex_offset;
    dst_index_offset  += rd.mesh_handle->index_count ();
    dst_vertex_offset += rd.mesh_handle->vertex_count();

    likely (ri < opaque_object_count)
      opaque_index_count += rd.mesh_handle->index_count();
    else
      transparent_index_count += rd.mesh_handle->index_count();

    likely (rd.texture_datas.size() > 0) {
      auto& td = rd.texture_datas[0];
      input_data.bpk_3oldvat_3vat_8vatprg_3sam_3tex.v = (td.sampler_idx << 3) | td.texture_page_idx;
      memcpy(input_data.tex_rect.v, td.texture_rect.xywh(), sizeof(float)*4);
    }

    memcpy(input_data.color_scale.v, rd.color_scale.rgba(), sizeof(float)*4);

    memcpy(input_data.transform.v, rd.transform.element_ptr(), sizeof(float)*16);


    // vertex animation texture
    auto vat_state = rd.object->getTrait<VATState>(vat_group_id);
    likely (vat_state == null) {  // case : without vat_state
      input_data.bpk_3oldvat_3vat_8vatprg_3sam_3tex.v |= (0xff << 6);
      input_data.    vat_offset_scl.v[0] = 0.f;
      input_data.    vat_offset_scl.v[1] = 0.f;
      input_data.    vat_offset_scl.v[2] = 0.f;
      input_data.    vat_offset_scl.v[3] = 0.f;
      input_data.old_vat_offset_scl.v[0] = 0.f;
      input_data.old_vat_offset_scl.v[1] = 0.f;
      input_data.old_vat_offset_scl.v[2] = 0.f;
      input_data.old_vat_offset_scl.v[3] = 0.f;
      input_data.    vat_u_unit.v = 0.f;
      input_data.old_vat_u_unit.v = 0.f;
      input_data.    vat_uv.v[0] = 0.f;
      input_data.    vat_uv.v[1] = 0.f;
      input_data.old_vat_uv.v[0] = 0.f;
      input_data.old_vat_uv.v[1] = 0.f;

    }else {  // case : with vat_state

      VATRenderData vrd;
      vat_state->fillRenderData(vrd, rd.mesh_handle->vertex_count());

      input_data.bpk_3oldvat_3vat_8vatprg_3sam_3tex.v |=
          (vrd.old.tex_infos[0].tex_page_idx << 17) |
          (vrd.cur.tex_infos[0].tex_page_idx << 14) |
          (((uint32_t)(vrd.interp_progress * REAL(255.0))) << 6);

      input_data.vat_offset_scl.v[0] = vrd.cur.offset.x();
      input_data.vat_offset_scl.v[1] = vrd.cur.offset.y();
      input_data.vat_offset_scl.v[2] = vrd.cur.offset.z();
      input_data.vat_offset_scl.v[3] = vrd.cur.scale;
      input_data.vat_u_unit.v = vrd.cur.u_unit;
      input_data.vat_uv.v[0]  = vrd.cur.tex_infos[0].uv.x();
      input_data.vat_uv.v[1]  = vrd.cur.tex_infos[0].uv.y();

      input_data.old_vat_offset_scl.v[0] = vrd.old.offset.x();
      input_data.old_vat_offset_scl.v[1] = vrd.old.offset.y();
      input_data.old_vat_offset_scl.v[2] = vrd.old.offset.z();
      input_data.old_vat_offset_scl.v[3] = vrd.old.scale;
      input_data.old_vat_u_unit.v = vrd.old.u_unit;
      input_data.old_vat_uv.v[0]  = vrd.old.tex_infos[0].uv.x();
      input_data.old_vat_uv.v[1]  = vrd.old.tex_infos[0].uv.y();
    }

  }

}


vector<GpuTaskRunner::GpuTaskMemoryUpdater> const& GameTaskRunner::_getGpuTaskMemoryUpdaters () {

  unlikely (g_swapchain_scale_sampler == null) {
    g_swapchain_scale_sampler =
        make_shared<Sampler>(
          Sampler::Filter::LINEAR,
          Sampler::Filter::LINEAR,
          Sampler::WrapOption::CLAMP_TO_EDGE,
          Sampler::WrapOption::CLAMP_TO_EDGE,
          1
        );
    g_swapchain_scale_sampler->build();
  }

  unlikely (g_default_sampler == null) {
    g_default_sampler =
        make_shared<Sampler>(
          Sampler::Filter::LINEAR,
          Sampler::Filter::LINEAR,
          Sampler::WrapOption::CLAMP_TO_EDGE,
          Sampler::WrapOption::CLAMP_TO_EDGE,
          1
        );
    g_default_sampler->build();
  }

  unlikely (g_default_comparison_sampler == null) {
    g_default_comparison_sampler =
        make_shared<Sampler>(
          Sampler::Filter::LINEAR,
          Sampler::Filter::LINEAR,
          Sampler::WrapOption::CLAMP_TO_EDGE,
          Sampler::WrapOption::CLAMP_TO_EDGE,
          1,
          true
        );
    g_default_comparison_sampler->build();
  }

  unlikely (mem_updater_.size() <= 0) {

    mem_updater_ = {
        /// batch
        {
          {[](Gtmu::MemInitParams params, Gtmu::MemInitResult& result)->bool {
            return true;
          }},

          {[this](Gtmu::MemUpdateParams params, Gtmu::MemUpdateResult& result)->bool {
            // ready
            size_t kMaxObjectCount = params.runner->getData("kMaxObjectCount", 0);


            __fillRenderData(root_component(), render_datas_);

            //__cullRenderData(render_datas_);


            // sort render_datas_
            StringRegistryIdType transparent_reg = StringRegistry::default_registry().lookUp("transparent");
            sort(render_datas_.begin(), render_datas_.end(), 
                [transparent_reg](RenderData const& a, RenderData const& b) {

                  bool a_is_transparent = __isTransparentRenderData(a, transparent_reg);
                  bool b_is_transparent = __isTransparentRenderData(b, transparent_reg);

                  unlikely (a_is_transparent != b_is_transparent)
                    return !a_is_transparent;


                  auto a_z = a.transform.getByIdx(14);
                  auto b_z = b.transform.getByIdx(14);
                  return (a_is_transparent == false)? a_z < b_z : a_z > b_z;
                }
            );


            uint32_t opaque_object_count     = 0;
            uint32_t opaque_index_count      = 0;
            uint32_t transparent_index_count = 0;
            __makeObjectData(
                obj_datas_,
                opaque_object_count,
                opaque_index_count,
                transparent_index_count,
                render_datas_,
                transparent_reg
            );



            /// fill shader data
            auto& memory = params.runner->memory();
            
            // global_data
            auto& prj = *Project::active_project();
            GpuGlobalData global_data{
                {(uint32_t)prj.window_width ()},
                {(uint32_t)prj.window_height()},
                {(uint32_t)prj.screen_width ()},
                {(uint32_t)prj.screen_height()},
            };
            auto scn = dynamic_cast<Scene*>(params.runner->root_component());
            auto& camera = scn->cur_camera();
            auto inv_proj_mat = camera->inv_projection_matrix();
            memcpy(global_data.inv_proj_mat.v, inv_proj_mat.element_ptr(), sizeof(float)*16);
            memory.fillShaderData(
                params.frame_idx,
                { "global_data" },
                sizeof(GpuGlobalData),
                &global_data
            );

            // compute config
            GpuComputeConfigData compute_config_data{
                {
                  1, 0, 0, 0,
                  0, 1, 0, 0,
                  0, 0, 1, 0,
                  0, 0, 0, 1,
                },
                {(uint32_t)obj_datas_.size()},
                {opaque_object_count    },
                {opaque_index_count     },
                {transparent_index_count},
            };
            auto projview_mat = camera->projection_matrix();
            memcpy(compute_config_data.projview_mat.v, projview_mat.element_ptr(), sizeof(float)*16);
            memory.fillShaderData(
                params.frame_idx,
                { "com_config" },
                sizeof(compute_config_data),
                &compute_config_data
            );


            unlikely (obj_datas_.size() > kMaxObjectCount)
              LOG_ERR("obj_datas_.size() == %u  is greater than kMaxObjectCount == %u", obj_datas_.size(), kMaxObjectCount);

            memory.fillShaderData(
                params.frame_idx,
                { "obj_buff" },
                math::min(obj_datas_.size(), kMaxObjectCount) * sizeof(GpuObjectInputData),
                obj_datas_.data()
            );


            return true;
          }},

          {[this](Gtmu::RunParamsUpdateParams params, Gtmu::RunParamsUpdateResult& result)->bool {
            uint32_t kMaxObjectCount = params.runner->getData("kMaxObjectCount", 0);

            uint32_t obj_cnt = math::min((uint32_t)obj_datas_.size(), kMaxObjectCount);

            result.cmd_run_params.dispatch = { obj_cnt / 256 + 1, 1, 1};

#if defined(USE_VULKAN)
            result.post_task_barrier_params_listp = _getComputePostBarrierParamsListp(
                params.runner->memory(),
                params.frame_idx
            );
#endif
            return true;
          }},
        },


        /// opaque
        {
          {[](Gtmu::MemInitParams params, Gtmu::MemInitResult& result)->bool {
            auto& memory = params.runner->memory();

            // set samplers
            const size_t kSamplerCount = 4;
            auto& samplers = memory.sampler_book().samplers();
            for (int si=0; si<kSamplerCount; ++si) {
              auto h = params.getUpdateHandle("sampler_" + std::to_string(si));
              auto& sam = memory.sampler_book().samplers()[si % samplers.size()];
              result.desc_set_updater.addSamplerInfo(h.desc_set, {sam}, h.sdbd);
            }

            { // set textures
              auto h = params.getUpdateHandle("texture_array");
              auto& texture_array = memory.texture_book().texture_array();
              result.desc_set_updater.addSampledImageInfo(h.desc_set, {texture_array}, h.sdbd);
            }

            return true;
          }},

          {[](Gtmu::MemUpdateParams params, Gtmu::MemUpdateResult& result)->bool {
#if defined(USE_VULKAN)
            // transition cur images for output
            params.transitionLayoutOfFramebufferAttachmentImage(0, 0, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL);
#endif
            return true;
          }},

          {[this](Gtmu::RunParamsUpdateParams params, Gtmu::RunParamsUpdateResult& result)->bool {

            // cmd run params
            auto& memory = params.runner->memory();
            auto draw_cmd_sdb = memory.getShaderDataBind({ "opaque_draw_cmd_buffer"   });
            auto rw_type =
                GpuTaskMemory::VmpKey::findRwType(
                  draw_cmd_sdb->used_by_read_only, draw_cmd_sdb->used_by_read_write, draw_cmd_sdb->name
                );

            auto& vmp =
                memory.getVideoMemoryPack({
                  draw_cmd_sdb->vmp_usage, draw_cmd_sdb->vmp_property, params.frame_idx, rw_type
                });
            result.cmd_run_params.draw_indexed_indirect = {
                vmp->buffer(),
                draw_cmd_sdb->offset,
                1,
                sizeof(GpuHelper::DrawIndexedIndirectCommand),
            };
            return true;
          }},
        },


        /// transparent
        {
          {[](Gtmu::MemInitParams params, Gtmu::MemInitResult& result)->bool {
            auto& memory = params.runner->memory();

            // set samplers
            const size_t kSamplerCount = 4;
            auto& samplers = memory.sampler_book().samplers();
            for (int si=0; si<kSamplerCount; ++si) {
              auto h = params.getUpdateHandle("sampler_" + std::to_string(si));
              auto& sam = memory.sampler_book().samplers()[si % samplers.size()];
              result.desc_set_updater.addSamplerInfo(h.desc_set, {sam}, h.sdbd);
            }

            { // set textures
              auto h = params.getUpdateHandle("texture_array");
              auto& texture_array = memory.texture_book().texture_array();
              result.desc_set_updater.addSampledImageInfo(h.desc_set, {texture_array}, h.sdbd);
            }

            return true;
          }},

          {[](Gtmu::MemUpdateParams params, Gtmu::MemUpdateResult& result)->bool {
#if defined(USE_VULKAN)
            // transition cur images for output
            params.transitionLayoutOfFramebufferAttachmentImage(0, 0, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL);
#endif
            return true;
          }},

          {[this](Gtmu::RunParamsUpdateParams params, Gtmu::RunParamsUpdateResult& result)->bool {

            // cmd run params
            auto& memory = params.runner->memory();
            auto draw_cmd_sdb = memory.getShaderDataBind({ "transparent_draw_cmd_buffer"   });
            auto rw_type =
                GpuTaskMemory::VmpKey::findRwType(
                  draw_cmd_sdb->used_by_read_only, draw_cmd_sdb->used_by_read_write, draw_cmd_sdb->name
                );

            auto& vmp =
                memory.getVideoMemoryPack({
                  draw_cmd_sdb->vmp_usage, draw_cmd_sdb->vmp_property, params.frame_idx, rw_type
                });
            result.cmd_run_params.draw_indexed_indirect = {
                vmp->buffer(),
                draw_cmd_sdb->offset,
                1,
                sizeof(GpuHelper::DrawIndexedIndirectCommand),
            };
            return true;
          }},
        },


        /// to_swapchain
        {
          {[](Gtmu::MemInitParams params, Gtmu::MemInitResult& result)->bool {

            { // set color_sampler
              auto h = params.getUpdateHandle("color_sampler");
              result.desc_set_updater.addSamplerInfo(h.desc_set, {g_default_sampler}, h.sdbd);
            }

            { // set opaquecolor_texture
              auto h = params.getUpdateHandle("opaque_color_texture");
              auto prev_color_img = params.getFramebufferAttachmentImage(-2, 0);
              result.desc_set_updater.addSampledImageInfo(h.desc_set, { prev_color_img->view() }, h.sdbd);
            }

            { // set transparent_color_texture
              auto h = params.getUpdateHandle("transparent_color_texture");
              auto prev_color_img = params.getFramebufferAttachmentImage(-1, 0);
              result.desc_set_updater.addSampledImageInfo(h.desc_set, { prev_color_img->view() }, h.sdbd);
            }

            return true;
          }},

          {[](Gtmu::MemUpdateParams params, Gtmu::MemUpdateResult& result)->bool {
#if defined(USE_VULKAN)
            // transition prev image for input
            params.transitionLayoutOfFramebufferAttachmentImage(-2, 0, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);
            params.transitionLayoutOfFramebufferAttachmentImage(-1, 0, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);
#endif
            return true;
          }},

          {[](Gtmu::RunParamsUpdateParams params, Gtmu::RunParamsUpdateResult& result)->bool {
            // cmd run params
            result.cmd_run_params.draw = { 6, 1, 0, 0 };
            return true;
          }},
        },
    };
  }

  return mem_updater_;
}


#pragma pack(push, 1)
struct _PreprocessVert {
  ALIGNED_ARRAY(8, float, 2) pos;
};
#pragma pack(pop)
vector<_PreprocessVert> preprocess_verts{
    { -1, -1, },
    { -1,  1, },
    {  1,  1, },

    {  1,  1, },
    {  1, -1, },
    { -1, -1, },
};


void GameTaskRunner::_beforeComputeVertexIndexBytesOfObjects (GpuTaskMemoryBuildContext& ctx) {
  ctx.total_vertex_bytes += sizeof(_PreprocessVert) * preprocess_verts.size();
}


void GameTaskRunner::_beforeBuildGpuTask (CallbackAngel& build_callback_angel) {
  VideoMemoryPack::fillMemory(
      memory().vertex_buffer_vmp(),
      sizeof(_PreprocessVert) * preprocess_verts.size(),
      preprocess_verts.data()
  );
}


#if defined(USE_VULKAN)
vector<PipelineBarrierParams>* GameTaskRunner::_getComputePostBarrierParamsListp (
    GpuTaskMemory const& memory,
    byte frame_idx
) {
  static vector<PipelineBarrierParams> params_list{
      {
        VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
        VK_PIPELINE_STAGE_VERTEX_SHADER_BIT,
        0,
        {},
        {},
        {},
      },
      {
        VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
        VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,
        0,
        {},
        {},
        {},
      },
      {
        VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
        VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT,
        0,
        {},
        {},
        {},
      },
  };


  /// compute - vertex barrier
  {
    auto& params = params_list[0];
    params.buffer_memory_barriers.clear();

    // dynamic buff barrier
    for (auto& key : {"dynamic_vertex_buff", "dynamic_index_buff"}) {
      auto bind = memory.getShaderDataBind({ key });
      auto rw_type = GpuTaskMemory::VmpKey::findRwType(bind->used_by_read_only, bind->used_by_read_write, bind->name);
      auto& vmp = memory.getVideoMemoryPack({ bind->vmp_usage, bind->vmp_property, frame_idx, rw_type });

      auto& obj_buff_barrier = params.buffer_memory_barriers.emplace_back(VkBufferMemoryBarrier{});
      obj_buff_barrier.sType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
      obj_buff_barrier.pNext = nullptr;
      obj_buff_barrier.srcAccessMask = VK_ACCESS_SHADER_WRITE_BIT;
      obj_buff_barrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
      obj_buff_barrier.srcQueueFamilyIndex = VulkanHelper::graphics_queue_family();
      obj_buff_barrier.dstQueueFamilyIndex = VulkanHelper::graphics_queue_family();
      obj_buff_barrier.buffer = vmp->buffer();
      obj_buff_barrier.offset = bind->offset;
      obj_buff_barrier.size   = bind->bytes * bind->arr_len;
    }
  }


  /// compute - fragment barrier
  {
    auto& params = params_list[1];
    params.buffer_memory_barriers.clear();

  }


  /// compute - indirect barrier
  {
    auto& params = params_list[2];
    params.buffer_memory_barriers.clear();

    // indr_buff_barrier
    for (auto& key : {"opaque_draw_cmd_buffer", "transparent_draw_cmd_buffer"}) {
      auto bind = memory.getShaderDataBind({ key });
      auto rw_type = GpuTaskMemory::VmpKey::findRwType(bind->used_by_read_only, bind->used_by_read_write, bind->name);
      auto& vmp = memory.getVideoMemoryPack({ bind->vmp_usage, bind->vmp_property, frame_idx, rw_type });

      auto& indr_buff_barrier = params.buffer_memory_barriers.emplace_back(VkBufferMemoryBarrier{});
      indr_buff_barrier.sType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
      indr_buff_barrier.pNext = nullptr;
      indr_buff_barrier.srcAccessMask = VK_ACCESS_SHADER_WRITE_BIT;
      indr_buff_barrier.dstAccessMask = VK_ACCESS_INDIRECT_COMMAND_READ_BIT;
      indr_buff_barrier.srcQueueFamilyIndex = VulkanHelper::graphics_queue_family();
      indr_buff_barrier.dstQueueFamilyIndex = VulkanHelper::graphics_queue_family();
      indr_buff_barrier.buffer = vmp->buffer();
      indr_buff_barrier.offset = bind->offset;
      indr_buff_barrier.size   = bind->bytes * bind->arr_len;
    }
  }


  return &params_list;
}
#endif  // if defined(USE_VULKAN)




#endif  // ifndef SERVER_ONLY

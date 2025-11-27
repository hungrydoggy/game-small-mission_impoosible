#ifndef SERVER_ONLY

#include "./debug_draw_gtr.h"


NODE_LOADABLE_CREATOR_REGISTERER(DebugDrawGTR);



#pragma pack(push, 1)
struct GpuGlobalData {
  ALIGNED_FIELD(4, uint) window_width;
  ALIGNED_FIELD(4, uint) window_height;
  ALIGNED_FIELD(4, uint) screen_width;
  ALIGNED_FIELD(4, uint) screen_height;
};
#pragma pack(pop)


#pragma pack(push, 1)
struct GpuSceneData {
  ALIGNED_ARRAY(64, float, 16) projview_mat;
  ALIGNED_FIELD( 4, uint     ) line_count;
  ALIGNED_FIELD( 4, float    ) line_alpha;
};
#pragma pack(pop)


#pragma pack(push, 1)
struct LineVertex {
  ALIGNED_ARRAY(4, float, 3) position;
  ALIGNED_ARRAY(4, float, 3) color;
};
#pragma pack(pop)



vector<GpuTaskRunner::GpuTaskMemoryUpdater> const& DebugDrawGTR::_getGpuTaskMemoryUpdaters () {

  unlikely (mem_updater_.size() <= 0) {

    mem_updater_ = {
        /// debug_draw
        {
          {[](Gtmu::MemInitParams params, Gtmu::MemInitResult& result)->bool {
            return true;
          }},

          {[](Gtmu::MemUpdateParams params, Gtmu::MemUpdateResult& result)->bool {

            auto& prj = *Project::active_project();
            auto scene = prj.getTopScene();
            unlikely (scene == null)
              return false;

            auto bullet = dpc<BulletWrapper>(scene->physics());
            unlikely (bullet == null)
              return false;

            auto& debug_drawer = bullet->debug_drawer();
            unlikely (debug_drawer == null)
              return false;

            auto camera = scene->cur_camera().get();
            unlikely (camera == null)
              return false;


            uint kMaxLineCount = params.runner->getData("kMaxLineCount", 0);
            auto line_count = math::min((uint)debug_drawer->line_count(), kMaxLineCount);
            


            /// fill vertex data
            auto& memory = params.runner->memory();
            likely (line_count > 0 && debug_drawer->line_data().size() > 0) {
              VideoMemoryPack::fillMemory(
                  memory.vertex_buffer_vmp(),
                  0,
                  sizeof(LineVertex) * line_count * 2,
                  debug_drawer->line_data().data()
              );
            }



            /// fill shader data
            // global_data
            GpuGlobalData global_data{
                {(uint)prj.window_width ()},
                {(uint)prj.window_height()},
                {(uint)prj.screen_width ()},
                {(uint)prj.screen_height()},
            };
            memory.fillShaderData(
                params.frame_idx,
                { "global_data" },
                sizeof(GpuGlobalData),
                &global_data
            );

            // compute config
            GpuSceneData scene_data{
                {
                  1, 0, 0, 0,
                  0, 1, 0, 0,
                  0, 0, 1, 0,
                  0, 0, 0, 1,
                },
                {line_count},
                {1.f},
            };
            camera->setOrthogonal(prj);
            camera->invalidatePrjMat();
            auto projview_mat = camera->projection_matrix() * camera->view_matrix();
            memcpy(scene_data.projview_mat.v, projview_mat.element_ptr(), sizeof(float)*16);
            memory.fillShaderData(
                params.frame_idx,
                { "scene_data" },
                sizeof(scene_data),
                &scene_data
            );


            return true;
          }},

          {[](Gtmu::RunParamsUpdateParams params, Gtmu::RunParamsUpdateResult& result)->bool {
            auto& prj = *Project::active_project();
            auto scene = prj.getTopScene();
            unlikely (scene == null)
              return false;

            auto bullet = dpc<BulletWrapper>(scene->physics());
            unlikely (bullet == null)
              return false;

            auto& debug_drawer = bullet->debug_drawer();
            unlikely (debug_drawer == null)
              return false;

            auto line_count = (uint)debug_drawer->line_count();
            result.cmd_run_params.draw = { line_count * 2, 1, 0, 0 };

            return true;
          }},
        },

    };
  }

  return mem_updater_;
}


void DebugDrawGTR::_beforeComputeVertexIndexBytesOfObjects (GpuTaskMemoryBuildContext& ctx) {
  uint kMaxLineCount = getData("kMaxLineCount", 0);

  ctx.total_vertex_bytes += sizeof(LineVertex) * kMaxLineCount * 2;
}


void DebugDrawGTR::_beforeBuildGpuTask (CallbackAngel& build_callback_angel) {
}




#endif  // ifndef SERVER_ONLY

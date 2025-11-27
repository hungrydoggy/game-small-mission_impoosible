#ifndef SERVER_ONLY
#ifndef _GPU_TASK_GAME_RUNNER_H_
#define _GPU_TASK_GAME_RUNNER_H_


#include <appetizer.h>


using namespace appetizer;


class GAMECONTENT_API GameTaskRunner : public GpuTaskRunner { GEN_OPT(FOR_CLIENT)
public: // inner types
  #pragma pack(push, 1)
  struct GpuObjectInputData {
    ALIGNED_FIELD( 4, uint32_t    ) index_count;
    ALIGNED_FIELD( 4, uint32_t    ) first_index;
    ALIGNED_FIELD( 4, uint32_t    ) vertex_count;
    ALIGNED_FIELD( 4, uint32_t    ) first_vertex;
    ALIGNED_FIELD( 4, uint32_t    ) dst_index_offset;
    ALIGNED_FIELD( 4, uint32_t    ) dst_vertex_offset;

    ALIGNED_FIELD( 4, uint32_t    ) bpk_3oldvat_3vat_8vatprg_3sam_3tex;

    ALIGNED_FIELD( 4, float       ) vat_u_unit;
    ALIGNED_FIELD( 4, float       ) old_vat_u_unit;
    ALIGNED_ARRAY( 1, uint8_t , 12) __pad__0;

    ALIGNED_ARRAY(16, float   ,  4) vat_offset_scl;
    ALIGNED_ARRAY(16, float   ,  4) old_vat_offset_scl;
 
    ALIGNED_ARRAY(16, float   ,  4) tex_rect;

    ALIGNED_ARRAY( 8, float   ,  2) vat_uv;
    ALIGNED_ARRAY( 8, float   ,  2) old_vat_uv;

    ALIGNED_ARRAY(16, float   ,  4) color_scale;

    ALIGNED_ARRAY(16, float   , 16) transform;
  };
  #pragma pack(pop)

private: // vars
  vector<GpuTaskMemoryUpdater> mem_updater_;
  vector<GpuObjectInputData> obj_datas_;
  vector<RenderData> render_datas_;
  
private: // methods
  vector<GpuTaskMemoryUpdater> const& _getGpuTaskMemoryUpdaters () override;

  void _beforeComputeVertexIndexBytesOfObjects (GpuTaskMemoryBuildContext& ctx) override;

  void _beforeBuildGpuTask (CallbackAngel& build_callback_angel) override;

#if defined(USE_VULKAN)
  vector<PipelineBarrierParams>* _getComputePostBarrierParamsListp (
      GpuTaskMemory const& memory,
      byte frame_idx
  );
#endif

};



#endif  // ifndef _GPU_TASK_GAME_RUNNER_H_
#endif  // ifndef SERVER_ONLY

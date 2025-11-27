#ifndef SERVER_ONLY
#ifndef _SYSTEM_DEBUG_DRAW_DEBUG_DRAW_GTR_H_
#define _SYSTEM_DEBUG_DRAW_DEBUG_DRAW_GTR_H_


#include <appetizer.h>


using namespace appetizer;


class GAMECONTENT_API DebugDrawGTR : public GpuTaskRunner { GEN_OPT(FOR_CLIENT)
private: // vars
  vector<GpuTaskMemoryUpdater> mem_updater_;
  

private: // methods
  vector<GpuTaskMemoryUpdater> const& _getGpuTaskMemoryUpdaters () override;

  void _beforeComputeVertexIndexBytesOfObjects (GpuTaskMemoryBuildContext& ctx) override;

  void _beforeBuildGpuTask (CallbackAngel& build_callback_angel) override;

};



#endif  // ifndef _SYSTEM_DEBUG_DRAW_DEBUG_DRAW_GTR_H_
#endif  // ifndef SERVER_ONLY

#include "./debug_draw_scene.h"



NODE_LOADABLE_CREATOR_REGISTERER(DebugDrawScene);



bool DebugDrawScene::onPostLoad (fun_tree::LoaderContext& ctx, shared_ptr<fun_tree::Node> const& node) {

#ifndef SERVER_ONLY
  auto& gtr = gpu_task_runner();
  unlikely (gtr == null) {
    LOG_ERR("gpu_task_runner is null");
    return false;
  }

  auto& task_def = gtr->task_defs()[0];
  auto& conf = task_def->graphics_config();
  auto& info = conf->attachment_infos()[0];

#if defined(USE_VULKAN)
  info.desc.initialLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
#endif

#endif  // ifndef SERVER_ONLY

  return super::onPostLoad(ctx, node);
}

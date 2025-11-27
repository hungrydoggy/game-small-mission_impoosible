#include "./my_project.h"



bool MyProject::preInitGpu (GLFWwindow*& window, string& project_name) {
  #ifndef SERVER_ONLY
  // settings for vulkan helper
  #endif
  return true;
}


bool MyProject::_onInit () {
  auto is_ok = super::_onInit();
  if (is_ok == false)
    return false;


#if defined(_EDITOR)
  return true;
#endif


  auto scene = fun_tree::NodeLoadable::load<Scene>("scenes/main.scn");
  pushScene(scene);

  return true;
}

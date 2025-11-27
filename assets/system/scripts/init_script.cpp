#include "./init_script.h"



bool InitScript::is_inited_ = false;


// InitScript::init() will be called when all system is inited.
void InitScript::init() {
  if (is_inited_ == true)
    return;

  auto &init_scripts = _init_scripts();
  for (auto &func : init_scripts)
    func();

  init_scripts.clear();

  is_inited_ = true;
}


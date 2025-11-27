#ifndef INIT_SCRIPT_H_
#define INIT_SCRIPT_H_

#include <appetizer.h>
#include <functional>
#include <vector>


using namespace appetizer;

using std::function;
using std::vector;


// InitScript::init() will be called when all system is inited.
class InitScript {
public:
  using InitScriptFunc = function<void()>;


public:
    static void init ();

    static void registerScript (InitScriptFunc const& func) {
      _init_scripts().push_back(func);
    }


private:
    static bool is_inited_;


    static vector<InitScriptFunc>& _init_scripts () {
      static vector<InitScriptFunc> v;
      return v;
    }
};


struct InitScriptRegisterer {
  InitScriptRegisterer (const InitScript::InitScriptFunc &func) {
    InitScript::registerScript(func);
  }
};


#endif

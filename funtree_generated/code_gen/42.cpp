

#include "./42.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/_code_set.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>







namespace appetizer {


using namespace fun_tree;
using namespace fun_tree::node_loader_format;

using std::make_shared;



#if defined(_WINDOWS)
static bool ___CodeSetBundleRegisterer___ = []() {
#else
__attribute__((constructor))
static void ___CodeSetBundleRegisterer___ () {
#endif

  CodeSetBundle::default_bundle().registerCodeSet(
      "plugins/child_selector/select_child.fnc",
      make_shared<Code_PluginsChildselectorSelectchildFnc>(),
      true
  );

#if defined(_WINDOWS)
  return true;
}();
#else
}
#endif



static Var __code_0 (
    vector<Var> const& params
) {

  #include "./42.0.code"
}


Var Code_PluginsChildselectorSelectchildFnc::execute (
    int code_idx, vector<Var> const& params
) {
  switch (code_idx) {
    case 0: return __code_0(params);
    default:
      LOG_ERR("unknown code_idx %u --- \"42.cpp\"", code_idx);
      return null_var;
  }
}


}






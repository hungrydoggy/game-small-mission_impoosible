

#include "./236.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/_code_set.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./236.0.code"






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
      "system/node_loader_format/fsm/fsm_state.nlf",
      make_shared<Code_SystemNodeloaderformatFsmFsmstateNlf>(),
      true
  );

#if defined(_WINDOWS)
  return true;
}();
#else
}
#endif



static Var __code_1 (
    vector<Var> const& params
) {

  #include "./236.1.code"
}


static Var __code_2 (
    vector<Var> const& params
) {

  #include "./236.2.code"
}


static Var __code_3 (
    vector<Var> const& params
) {

  #include "./236.3.code"
}


static Var __code_4 (
    vector<Var> const& params
) {

  #include "./236.4.code"
}


static Var __code_5 (
    vector<Var> const& params
) {

  #include "./236.5.code"
}


static Var __code_6 (
    vector<Var> const& params
) {

  #include "./236.6.code"
}


static Var __code_7 (
    vector<Var> const& params
) {

  #include "./236.7.code"
}


Var Code_SystemNodeloaderformatFsmFsmstateNlf::execute (
    int code_idx, vector<Var> const& params
) {
  switch (code_idx) {
    case 1: return __code_1(params);
    case 2: return __code_2(params);
    case 3: return __code_3(params);
    case 4: return __code_4(params);
    case 5: return __code_5(params);
    case 6: return __code_6(params);
    case 7: return __code_7(params);
    default:
      LOG_ERR("unknown code_idx %u --- \"236.cpp\"", code_idx);
      return null_var;
  }
}


}






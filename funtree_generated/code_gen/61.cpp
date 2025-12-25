

#include "./61.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/_code_set.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./61.0.code"






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
      "system/macroes/condition.switch.mac",
      make_shared<Code_SystemMacroesConditionSwitchMac>(),
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

  #include "./61.1.code"
}


static Var __code_2 (
    vector<Var> const& params
) {

  #include "./61.2.code"
}


static Var __code_3 (
    vector<Var> const& params
) {

  #include "./61.3.code"
}


static Var __code_4 (
    vector<Var> const& params
) {

  #include "./61.4.code"
}


static Var __code_5 (
    vector<Var> const& params
) {

  #include "./61.5.code"
}


static Var __code_6 (
    vector<Var> const& params
) {

  #include "./61.6.code"
}


Var Code_SystemMacroesConditionSwitchMac::execute (
    int code_idx, vector<Var> const& params
) {
  switch (code_idx) {
    case 1: return __code_1(params);
    case 2: return __code_2(params);
    case 3: return __code_3(params);
    case 4: return __code_4(params);
    case 5: return __code_5(params);
    case 6: return __code_6(params);
    default:
      LOG_ERR("unknown code_idx %u --- \"61.cpp\"", code_idx);
      return null_var;
  }
}


}






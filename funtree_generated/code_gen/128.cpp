

#include "./128.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/_code_set.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>







namespace appetizer {


using namespace fun_tree;
using namespace fun_tree::node_loader_format;

using std::make_shared;



__attribute__((constructor))
static void ___CodeSetBundleRegisterer___ () {
  CodeSetBundle::default_bundle().registerCodeSet(
      "system/macroes/sequence.map.mac",
      make_shared<Code_SystemMacroesSequenceMapMac>(),
      true
  );
}



static Var __code_0 (
    vector<Var> const& params
) {

  #include "./128.0.code"
}


static Var __code_1 (
    vector<Var> const& params
) {

  #include "./128.1.code"
}


static Var __code_2 (
    vector<Var> const& params
) {

  #include "./128.2.code"
}


static Var __code_3 (
    vector<Var> const& params
) {

  #include "./128.3.code"
}


static Var __code_4 (
    vector<Var> const& params
) {

  #include "./128.4.code"
}


static Var __code_5 (
    vector<Var> const& params
) {

  #include "./128.5.code"
}


static Var __code_6 (
    vector<Var> const& params
) {

  #include "./128.6.code"
}


static Var __code_7 (
    vector<Var> const& params
) {

  #include "./128.7.code"
}


Var Code_SystemMacroesSequenceMapMac::execute (
    int code_idx, vector<Var> const& params
) {
  switch (code_idx) {
    case 0: return __code_0(params);
    case 1: return __code_1(params);
    case 2: return __code_2(params);
    case 3: return __code_3(params);
    case 4: return __code_4(params);
    case 5: return __code_5(params);
    case 6: return __code_6(params);
    case 7: return __code_7(params);
    default:
      LOG_ERR("unknown code_idx %u --- \"128.cpp\"", code_idx);
      return null_var;
  }
}


}






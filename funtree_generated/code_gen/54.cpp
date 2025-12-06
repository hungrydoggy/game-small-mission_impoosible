

#include "./54.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/_code_set.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./54.0.code"






namespace appetizer {


using namespace fun_tree;
using namespace fun_tree::node_loader_format;

using std::make_shared;



__attribute__((constructor))
static void ___CodeSetBundleRegisterer___ () {
  CodeSetBundle::default_bundle().registerCodeSet(
      "system/macroes/game_component.make_path.mac",
      make_shared<Code_SystemMacroesGamecomponentMakepathMac>(),
      true
  );
}



static Var __code_1 (
    vector<Var> const& params
) {

  #include "./54.1.code"
}


static Var __code_2 (
    vector<Var> const& params
) {

  #include "./54.2.code"
}


Var Code_SystemMacroesGamecomponentMakepathMac::execute (
    int code_idx, vector<Var> const& params
) {
  switch (code_idx) {
    case 1: return __code_1(params);
    case 2: return __code_2(params);
    default:
      LOG_ERR("unknown code_idx %u --- \"54.cpp\"", code_idx);
      return null_var;
  }
}


}






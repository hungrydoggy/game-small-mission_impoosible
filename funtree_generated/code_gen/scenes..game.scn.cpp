

#include "./scenes..game.scn.h"

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
      "scenes/game.scn",
      make_shared<Code_ScenesGameScn>(),
      true
  );
}



static Var __code_0 (
    vector<Var> const& params
) {

  #include "scenes..game.scn.0.code"
}


static Var __code_1 (
    vector<Var> const& params
) {

  #include "scenes..game.scn.1.code"
}


static Var __code_2 (
    vector<Var> const& params
) {

  #include "scenes..game.scn.2.code"
}


Var Code_ScenesGameScn::execute (
    int code_idx, vector<Var> const& params
) {
  switch (code_idx) {
    case 0: return __code_0(params);
    case 1: return __code_1(params);
    case 2: return __code_2(params);
    default:
      LOG_ERR("unknown code_idx %u --- \"scenes..game.scn.cpp\"", code_idx);
      return null_var;
  }
}


}






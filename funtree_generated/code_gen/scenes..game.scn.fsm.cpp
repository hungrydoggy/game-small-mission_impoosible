

#include "./scenes..game.scn.fsm.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/_code_set.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./scenes..game.scn.fsm.0.code"



#include "./scenes..game.scn.fsm.1.code"



namespace appetizer {


using namespace fun_tree;
using namespace fun_tree::node_loader_format;

using std::make_shared;



__attribute__((constructor))
static void ___CodeSetBundleRegisterer___ () {
  CodeSetBundle::default_bundle().registerCodeSet(
      "scenes/game.scn.fsm",
      make_shared<Code_ScenesGameScnFsm>(),
      true
  );
}



static Var __code_2 (
    vector<Var> const& params
) {

  #include "scenes..game.scn.fsm.2.code"
}


static Var __code_3 (
    vector<Var> const& params
) {

  #include "scenes..game.scn.fsm.3.code"
}


Var Code_ScenesGameScnFsm::execute (
    int code_idx, vector<Var> const& params
) {
  switch (code_idx) {
    case 2: return __code_2(params);
    case 3: return __code_3(params);
    default:
      LOG_ERR("unknown code_idx %u --- \"scenes..game.scn.fsm.cpp\"", code_idx);
      return null_var;
  }
}


}

#include "./scenes..game.scn.fsm.4.code"





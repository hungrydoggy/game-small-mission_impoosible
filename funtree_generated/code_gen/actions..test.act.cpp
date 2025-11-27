

#include "./actions..test.act.h"

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
      "actions/test.act",
      make_shared<Code_ActionsTestAct>(),
      true
  );
}



static Var __code_0 (
    vector<Var> const& params
) {

  #include "actions..test.act.0.code"
}


Var Code_ActionsTestAct::execute (
    int code_idx, vector<Var> const& params
) {
  switch (code_idx) {
    case 0: return __code_0(params);
    default:
      LOG_ERR("unknown code_idx %u --- \"actions..test.act.cpp\"", code_idx);
      return null_var;
  }
}


}






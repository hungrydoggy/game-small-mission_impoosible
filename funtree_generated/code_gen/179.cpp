

#include "./179.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/_code_set.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./179.0.code"






namespace appetizer {


using namespace fun_tree;
using namespace fun_tree::node_loader_format;

using std::make_shared;



__attribute__((constructor))
static void ___CodeSetBundleRegisterer___ () {
  CodeSetBundle::default_bundle().registerCodeSet(
      "system/node_loader_format/actions/end_action.nlf",
      make_shared<Code_SystemNodeloaderformatActionsEndactionNlf>(),
      true
  );
}



static Var __code_1 (
    vector<Var> const& params
) {

  #include "./179.1.code"
}


static Var __code_2 (
    vector<Var> const& params
) {

  #include "./179.2.code"
}


static Var __code_3 (
    vector<Var> const& params
) {

  #include "./179.3.code"
}


Var Code_SystemNodeloaderformatActionsEndactionNlf::execute (
    int code_idx, vector<Var> const& params
) {
  switch (code_idx) {
    case 1: return __code_1(params);
    case 2: return __code_2(params);
    case 3: return __code_3(params);
    default:
      LOG_ERR("unknown code_idx %u --- \"179.cpp\"", code_idx);
      return null_var;
  }
}


}






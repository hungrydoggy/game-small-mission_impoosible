

#include "./290.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/_lambda_set.h>
#include <common/loader/fun_tree/_lambda_set_util.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>







namespace appetizer {


using namespace fun_tree;
using namespace fun_tree::node_loader_format;

using std::make_shared;



__attribute__((constructor))
static void ___LambdaSetBundleRegisterer___ () {
  LambdaSetBundle::default_bundle().registerLambdaSet(
      "scenes/game.scn",
      make_shared<Lambda_ScenesGameScn>(),
      true
  );
}



static Var __lambda_code_0 (
    shared_ptr<Node> const& node, shared_ptr<Content> const& content
) {

  #include "./290.0.code"
}


Var Lambda_ScenesGameScn::execute (
    shared_ptr<Node> const& node,
    int code_idx,
    shared_ptr<Content> const& content
) {
  switch (code_idx) {
    case 0: return __lambda_code_0(node, content);
    default:
      LOG_ERR("unknown code_idx %u --- \"290.cpp\"", code_idx);
      return null_var;
  }
}


}






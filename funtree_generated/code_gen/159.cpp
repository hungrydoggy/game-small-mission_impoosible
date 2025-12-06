

#include "./159.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/_code_set.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./144.0.code"






namespace appetizer {


using namespace fun_tree;
using namespace fun_tree::node_loader_format;

using std::make_shared;



__attribute__((constructor))
static void ___CodeSetBundleRegisterer___ () {
  CodeSetBundle::default_bundle().registerCodeSet(
      "system/node_loader_format/actions/scale_x_by.nlf",
      make_shared<Code_SystemNodeloaderformatActionsScalexbyNlf>(),
      true
  );
}



static Var __code_0 (
    vector<Var> const& params
) {

  #include "./159.0.code"
}


Var Code_SystemNodeloaderformatActionsScalexbyNlf::execute (
    int code_idx, vector<Var> const& params
) {
  switch (code_idx) {
    case 0: return __code_0(params);
    default:
      LOG_ERR("unknown code_idx %u --- \"159.cpp\"", code_idx);
      return null_var;
  }
}


}






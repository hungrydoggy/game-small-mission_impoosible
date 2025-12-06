#ifndef SERVER_ONLY

#include "./232.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/_code_set.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./232.0.code"






namespace appetizer {


using namespace fun_tree;
using namespace fun_tree::node_loader_format;

using std::make_shared;



__attribute__((constructor))
static void ___CodeSetBundleRegisterer___ () {
  CodeSetBundle::default_bundle().registerCodeSet(
      "system/node_loader_format/graphics/gpu_task/gpu_task_runner.nlf",
      make_shared<Code_SystemNodeloaderformatGraphicsGputaskGputaskrunnerNlf>(),
      true
  );
}



static Var __code_1 (
    vector<Var> const& params
) {

  #include "./232.1.code"
}


Var Code_SystemNodeloaderformatGraphicsGputaskGputaskrunnerNlf::execute (
    int code_idx, vector<Var> const& params
) {
  switch (code_idx) {
    case 1: return __code_1(params);
    default:
      LOG_ERR("unknown code_idx %u --- \"232.cpp\"", code_idx);
      return null_var;
  }
}


}




#endif

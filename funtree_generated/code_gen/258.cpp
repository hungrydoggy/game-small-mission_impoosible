#ifndef SERVER_ONLY

#include "./258.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/_code_set.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./258.0.code"






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
      "system/node_loader_format/graphics/gpu_task/gpu_task_item.nlf",
      make_shared<Code_SystemNodeloaderformatGraphicsGputaskGputaskitemNlf>(),
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

  #include "./258.1.code"
}


static Var __code_2 (
    vector<Var> const& params
) {

  #include "./258.2.code"
}


Var Code_SystemNodeloaderformatGraphicsGputaskGputaskitemNlf::execute (
    int code_idx, vector<Var> const& params
) {
  switch (code_idx) {
    case 1: return __code_1(params);
    case 2: return __code_2(params);
    default:
      LOG_ERR("unknown code_idx %u --- \"258.cpp\"", code_idx);
      return null_var;
  }
}


}




#endif

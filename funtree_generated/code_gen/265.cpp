#ifndef SERVER_ONLY

#include "./265.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/_code_set.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./265.0.code"






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
      "system/node_loader_format/graphics/gpu_task/vertex_attribute_def.nlf",
      make_shared<Code_SystemNodeloaderformatGraphicsGputaskVertexattributedefNlf>(),
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

  #include "./265.1.code"
}


static Var __code_2 (
    vector<Var> const& params
) {

  #include "./265.2.code"
}


static Var __code_3 (
    vector<Var> const& params
) {

  #include "./265.3.code"
}


static Var __code_4 (
    vector<Var> const& params
) {

  #include "./265.4.code"
}


static Var __code_5 (
    vector<Var> const& params
) {

  #include "./265.5.code"
}


Var Code_SystemNodeloaderformatGraphicsGputaskVertexattributedefNlf::execute (
    int code_idx, vector<Var> const& params
) {
  switch (code_idx) {
    case 1: return __code_1(params);
    case 2: return __code_2(params);
    case 3: return __code_3(params);
    case 4: return __code_4(params);
    case 5: return __code_5(params);
    default:
      LOG_ERR("unknown code_idx %u --- \"265.cpp\"", code_idx);
      return null_var;
  }
}


}




#endif

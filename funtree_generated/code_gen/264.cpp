#ifndef SERVER_ONLY

#include "./264.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/_code_set.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./264.0.code"






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
      "system/node_loader_format/graphics/gpu_task/shader_data_bind_def.nlf",
      make_shared<Code_SystemNodeloaderformatGraphicsGputaskShaderdatabinddefNlf>(),
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

  #include "./264.1.code"
}


static Var __code_2 (
    vector<Var> const& params
) {

  #include "./264.2.code"
}


static Var __code_3 (
    vector<Var> const& params
) {

  #include "./264.3.code"
}


static Var __code_4 (
    vector<Var> const& params
) {

  #include "./264.4.code"
}


static Var __code_5 (
    vector<Var> const& params
) {

  #include "./264.5.code"
}


static Var __code_6 (
    vector<Var> const& params
) {

  #include "./264.6.code"
}


static Var __code_7 (
    vector<Var> const& params
) {

  #include "./264.7.code"
}


static Var __code_8 (
    vector<Var> const& params
) {

  #include "./264.8.code"
}


static Var __code_9 (
    vector<Var> const& params
) {

  #include "./264.9.code"
}


static Var __code_10 (
    vector<Var> const& params
) {

  #include "./264.10.code"
}


static Var __code_11 (
    vector<Var> const& params
) {

  #include "./264.11.code"
}


Var Code_SystemNodeloaderformatGraphicsGputaskShaderdatabinddefNlf::execute (
    int code_idx, vector<Var> const& params
) {
  switch (code_idx) {
    case 1: return __code_1(params);
    case 2: return __code_2(params);
    case 3: return __code_3(params);
    case 4: return __code_4(params);
    case 5: return __code_5(params);
    case 6: return __code_6(params);
    case 7: return __code_7(params);
    case 8: return __code_8(params);
    case 9: return __code_9(params);
    case 10: return __code_10(params);
    case 11: return __code_11(params);
    default:
      LOG_ERR("unknown code_idx %u --- \"264.cpp\"", code_idx);
      return null_var;
  }
}


}




#endif

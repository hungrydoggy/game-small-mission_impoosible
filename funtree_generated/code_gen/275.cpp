

#include "./275.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/_code_set.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./275.0.code"






namespace appetizer {


using namespace fun_tree;
using namespace fun_tree::node_loader_format;

using std::make_shared;



__attribute__((constructor))
static void ___CodeSetBundleRegisterer___ () {
  CodeSetBundle::default_bundle().registerCodeSet(
      "system/node_loader_format/etc/platform_setting.nlf",
      make_shared<Code_SystemNodeloaderformatEtcPlatformsettingNlf>(),
      true
  );
}



static Var __code_1 (
    vector<Var> const& params
) {

  #include "./275.1.code"
}


static Var __code_2 (
    vector<Var> const& params
) {

  #include "./275.2.code"
}


static Var __code_3 (
    vector<Var> const& params
) {

  #include "./275.3.code"
}


static Var __code_4 (
    vector<Var> const& params
) {

  #include "./275.4.code"
}


static Var __code_5 (
    vector<Var> const& params
) {

  #include "./275.5.code"
}


static Var __code_6 (
    vector<Var> const& params
) {

  #include "./275.6.code"
}


static Var __code_7 (
    vector<Var> const& params
) {

  #include "./275.7.code"
}


static Var __code_8 (
    vector<Var> const& params
) {

  #include "./275.8.code"
}


static Var __code_9 (
    vector<Var> const& params
) {

  #include "./275.9.code"
}


Var Code_SystemNodeloaderformatEtcPlatformsettingNlf::execute (
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
    default:
      LOG_ERR("unknown code_idx %u --- \"275.cpp\"", code_idx);
      return null_var;
  }
}


}








#include "./244.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/_code_set.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./244.0.code"






namespace appetizer {


using namespace fun_tree;
using namespace fun_tree::node_loader_format;

using std::make_shared;



__attribute__((constructor))
static void ___CodeSetBundleRegisterer___ () {
  CodeSetBundle::default_bundle().registerCodeSet(
      "system/node_loader_format/game_component/audio_listener.nlf",
      make_shared<Code_SystemNodeloaderformatGamecomponentAudiolistenerNlf>(),
      true
  );
}



static Var __code_1 (
    vector<Var> const& params
) {

  #include "./244.1.code"
}


static Var __code_2 (
    vector<Var> const& params
) {

  #include "./244.2.code"
}


static Var __code_3 (
    vector<Var> const& params
) {

  #include "./244.3.code"
}


Var Code_SystemNodeloaderformatGamecomponentAudiolistenerNlf::execute (
    int code_idx, vector<Var> const& params
) {
  switch (code_idx) {
    case 1: return __code_1(params);
    case 2: return __code_2(params);
    case 3: return __code_3(params);
    default:
      LOG_ERR("unknown code_idx %u --- \"244.cpp\"", code_idx);
      return null_var;
  }
}


}






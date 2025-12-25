

#include "./48.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/_code_set.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./48.0.code"



#include "./48.1.code"



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
      "scenes/game.scn.state.fnc",
      make_shared<Code_ScenesGameScnStateFnc>(),
      true
  );

#if defined(_WINDOWS)
  return true;
}();
#else
}
#endif



static Var __code_2 (
    vector<Var> const& params
) {

  #include "./48.2.code"
}


static Var __code_3 (
    vector<Var> const& params
) {

  #include "./48.3.code"
}


static Var __code_4 (
    vector<Var> const& params
) {

  #include "./48.4.code"
}


Var Code_ScenesGameScnStateFnc::execute (
    int code_idx, vector<Var> const& params
) {
  switch (code_idx) {
    case 2: return __code_2(params);
    case 3: return __code_3(params);
    case 4: return __code_4(params);
    default:
      LOG_ERR("unknown code_idx %u --- \"48.cpp\"", code_idx);
      return null_var;
  }
}


}

#include "./48.5.code"





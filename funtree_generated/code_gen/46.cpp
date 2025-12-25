

#include "./46.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/_code_set.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./46.0.code"



#include "./46.1.code"



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
      "scenes/game.scn.fnc",
      make_shared<Code_ScenesGameScnFnc>(),
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

  #include "./46.2.code"
}


static Var __code_3 (
    vector<Var> const& params
) {

  #include "./46.3.code"
}


Var Code_ScenesGameScnFnc::execute (
    int code_idx, vector<Var> const& params
) {
  switch (code_idx) {
    case 2: return __code_2(params);
    case 3: return __code_3(params);
    default:
      LOG_ERR("unknown code_idx %u --- \"46.cpp\"", code_idx);
      return null_var;
  }
}


}

#include "./46.4.code"





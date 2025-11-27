

#include "./objects..char.main..playable.obj.fsm.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/_code_set.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>




#include "./objects..char.main..playable.obj.fsm.0.code"



namespace appetizer {


using namespace fun_tree;
using namespace fun_tree::node_loader_format;

using std::make_shared;



__attribute__((constructor))
static void ___CodeSetBundleRegisterer___ () {
  CodeSetBundle::default_bundle().registerCodeSet(
      "objects/char.main/playable.obj.fsm",
      make_shared<Code_ObjectsCharMainPlayableObjFsm>(),
      true
  );
}



static Var __code_1 (
    vector<Var> const& params
) {

  #include "objects..char.main..playable.obj.fsm.1.code"
}


static Var __code_2 (
    vector<Var> const& params
) {

  #include "objects..char.main..playable.obj.fsm.2.code"
}


static Var __code_3 (
    vector<Var> const& params
) {

  #include "objects..char.main..playable.obj.fsm.3.code"
}


static Var __code_4 (
    vector<Var> const& params
) {

  #include "objects..char.main..playable.obj.fsm.4.code"
}


static Var __code_5 (
    vector<Var> const& params
) {

  #include "objects..char.main..playable.obj.fsm.5.code"
}


static Var __code_6 (
    vector<Var> const& params
) {

  #include "objects..char.main..playable.obj.fsm.6.code"
}


static Var __code_7 (
    vector<Var> const& params
) {

  #include "objects..char.main..playable.obj.fsm.7.code"
}


static Var __code_8 (
    vector<Var> const& params
) {

  #include "objects..char.main..playable.obj.fsm.8.code"
}


static Var __code_9 (
    vector<Var> const& params
) {

  #include "objects..char.main..playable.obj.fsm.9.code"
}


static Var __code_10 (
    vector<Var> const& params
) {

  #include "objects..char.main..playable.obj.fsm.10.code"
}


static Var __code_11 (
    vector<Var> const& params
) {

  #include "objects..char.main..playable.obj.fsm.11.code"
}


static Var __code_12 (
    vector<Var> const& params
) {

  #include "objects..char.main..playable.obj.fsm.12.code"
}


static Var __code_13 (
    vector<Var> const& params
) {

  #include "objects..char.main..playable.obj.fsm.13.code"
}


static Var __code_14 (
    vector<Var> const& params
) {

  #include "objects..char.main..playable.obj.fsm.14.code"
}


static Var __code_15 (
    vector<Var> const& params
) {

  #include "objects..char.main..playable.obj.fsm.15.code"
}


static Var __code_16 (
    vector<Var> const& params
) {

  #include "objects..char.main..playable.obj.fsm.16.code"
}


Var Code_ObjectsCharMainPlayableObjFsm::execute (
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
    case 12: return __code_12(params);
    case 13: return __code_13(params);
    case 14: return __code_14(params);
    case 15: return __code_15(params);
    case 16: return __code_16(params);
    default:
      LOG_ERR("unknown code_idx %u --- \"objects..char.main..playable.obj.fsm.cpp\"", code_idx);
      return null_var;
  }
}


}

#include "./objects..char.main..playable.obj.fsm.17.code"





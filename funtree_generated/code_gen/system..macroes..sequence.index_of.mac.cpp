

#include "./system..macroes..sequence.index_of.mac.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/_code_set.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>







namespace appetizer {


using namespace fun_tree;
using namespace fun_tree::node_loader_format;

using std::make_shared;



__attribute__((constructor))
static void ___CodeSetBundleRegisterer___ () {
  CodeSetBundle::default_bundle().registerCodeSet(
      "system/macroes/sequence.index_of.mac",
      make_shared<Code_SystemMacroesSequenceIndexofMac>(),
      true
  );
}



static Var __code_0 (
    vector<Var> const& params
) {

  #include "system..macroes..sequence.index_of.mac.0.code"
}


static Var __code_1 (
    vector<Var> const& params
) {

  #include "system..macroes..sequence.index_of.mac.1.code"
}


static Var __code_2 (
    vector<Var> const& params
) {

  #include "system..macroes..sequence.index_of.mac.2.code"
}


static Var __code_3 (
    vector<Var> const& params
) {

  #include "system..macroes..sequence.index_of.mac.3.code"
}


Var Code_SystemMacroesSequenceIndexofMac::execute (
    int code_idx, vector<Var> const& params
) {
  switch (code_idx) {
    case 0: return __code_0(params);
    case 1: return __code_1(params);
    case 2: return __code_2(params);
    case 3: return __code_3(params);
    default:
      LOG_ERR("unknown code_idx %u --- \"system..macroes..sequence.index_of.mac.cpp\"", code_idx);
      return null_var;
  }
}


}








#include "./system..macroes..view.get_image_size.mac.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/_code_set.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./system..macroes..view.get_image_size.mac.0.code"






namespace appetizer {


using namespace fun_tree;
using namespace fun_tree::node_loader_format;

using std::make_shared;



__attribute__((constructor))
static void ___CodeSetBundleRegisterer___ () {
  CodeSetBundle::default_bundle().registerCodeSet(
      "system/macroes/view.get_image_size.mac",
      make_shared<Code_SystemMacroesViewGetimagesizeMac>(),
      true
  );
}



static Var __code_1 (
    vector<Var> const& params
) {

  #include "system..macroes..view.get_image_size.mac.1.code"
}


static Var __code_2 (
    vector<Var> const& params
) {

  #include "system..macroes..view.get_image_size.mac.2.code"
}


Var Code_SystemMacroesViewGetimagesizeMac::execute (
    int code_idx, vector<Var> const& params
) {
  switch (code_idx) {
    case 1: return __code_1(params);
    case 2: return __code_2(params);
    default:
      LOG_ERR("unknown code_idx %u --- \"system..macroes..view.get_image_size.mac.cpp\"", code_idx);
      return null_var;
  }
}


}






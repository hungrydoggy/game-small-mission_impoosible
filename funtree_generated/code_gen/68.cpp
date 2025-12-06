

#include "./68.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/_code_set.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./68.0.code"






namespace appetizer {


using namespace fun_tree;
using namespace fun_tree::node_loader_format;

using std::make_shared;



__attribute__((constructor))
static void ___CodeSetBundleRegisterer___ () {
  CodeSetBundle::default_bundle().registerCodeSet(
      "system/macroes/physics_shape.make_half_size_from_image_size.mac",
      make_shared<Code_SystemMacroesPhysicsshapeMakehalfsizefromimagesizeMac>(),
      true
  );
}



static Var __code_1 (
    vector<Var> const& params
) {

  #include "./68.1.code"
}


static Var __code_2 (
    vector<Var> const& params
) {

  #include "./68.2.code"
}


Var Code_SystemMacroesPhysicsshapeMakehalfsizefromimagesizeMac::execute (
    int code_idx, vector<Var> const& params
) {
  switch (code_idx) {
    case 1: return __code_1(params);
    case 2: return __code_2(params);
    default:
      LOG_ERR("unknown code_idx %u --- \"68.cpp\"", code_idx);
      return null_var;
  }
}


}






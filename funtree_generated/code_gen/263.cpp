

#include "./263.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/_code_set.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./263.0.code"






namespace appetizer {


using namespace fun_tree;
using namespace fun_tree::node_loader_format;

using std::make_shared;



__attribute__((constructor))
static void ___CodeSetBundleRegisterer___ () {
  CodeSetBundle::default_bundle().registerCodeSet(
      "system/node_loader_format/bullet_physics/shape_infos/cylinder.nlf",
      make_shared<Code_SystemNodeloaderformatBulletphysicsShapeinfosCylinderNlf>(),
      true
  );
}



static Var __code_1 (
    vector<Var> const& params
) {

  #include "./263.1.code"
}


static Var __code_2 (
    vector<Var> const& params
) {

  #include "./263.2.code"
}


static Var __code_3 (
    vector<Var> const& params
) {

  #include "./263.3.code"
}


static Var __code_4 (
    vector<Var> const& params
) {

  #include "./263.4.code"
}


Var Code_SystemNodeloaderformatBulletphysicsShapeinfosCylinderNlf::execute (
    int code_idx, vector<Var> const& params
) {
  switch (code_idx) {
    case 1: return __code_1(params);
    case 2: return __code_2(params);
    case 3: return __code_3(params);
    case 4: return __code_4(params);
    default:
      LOG_ERR("unknown code_idx %u --- \"263.cpp\"", code_idx);
      return null_var;
  }
}


}






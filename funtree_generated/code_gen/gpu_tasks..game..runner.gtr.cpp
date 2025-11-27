

#include "./gpu_tasks..game..runner.gtr.h"

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
      "gpu_tasks/game/runner.gtr",
      make_shared<Code_GputasksGameRunnerGtr>(),
      true
  );
}



Var Code_GputasksGameRunnerGtr::execute (
    int code_idx, vector<Var> const& params
) {
  switch (code_idx) {
    default:
      LOG_ERR("unknown code_idx %u --- \"gpu_tasks..game..runner.gtr.cpp\"", code_idx);
      return null_var;
  }
}


}








#include "./227.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/_code_set.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./227.0.code"






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
      "system/node_loader_format/etc/global_object.nlf",
      make_shared<Code_SystemNodeloaderformatEtcGlobalobjectNlf>(),
      true
  );

#if defined(_WINDOWS)
  return true;
}();
#else
}
#endif



Var Code_SystemNodeloaderformatEtcGlobalobjectNlf::execute (
    int code_idx, vector<Var> const& params
) {
  switch (code_idx) {
    default:
      LOG_ERR("unknown code_idx %u --- \"227.cpp\"", code_idx);
      return null_var;
  }
}


}






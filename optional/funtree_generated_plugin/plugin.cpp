
#include <common/loader/fun_tree/bundle_pack.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>


#if defined(_WINDOWS)
  #define PLUGIN_EXPORT __declspec(dllexport)
#else
  #define PLUGIN_EXPORT
#endif


using namespace appetizer;
using namespace appetizer::fun_tree;


extern "C" {
  PLUGIN_EXPORT bool callPluginFunc (void* bundle_pack) {
    //LOG("funtree_generated_plugin");

    // register
    //bundle_pack->code_set_bundle    ->registerAll(&CodeSetBundle    ::default_bundle);
    //bundle_pack->lambda_set_bundle  ->registerAll(&LambdaSetBundle  ::default_bundle);
    //bundle_pack->macro_loader_bundle->registerAll(&MacroLoaderBundle::default_bundle);
    //bundle_pack->node_loader_bundle ->registerAll(&NodeLoaderBundle ::default_bundle);
    return true;
  }
}

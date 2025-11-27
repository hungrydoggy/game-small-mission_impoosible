

#include "./system..node_loader_format..actions..empty.nlf.node_loader.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./system..node_loader_format..actions..empty.nlf.node_loader.0.code"






namespace appetizer {


using namespace fun_tree;
using namespace fun_tree::node_loader_format;

using std::make_shared;



__attribute__((constructor))
static void ___NodeLoaderBundleRegisterer___ () {

  NodeLoaderBundle::default_bundle().registerLoader(
      vector<string>{"Action.Empty", "Empty", },
      vector<string>{"ActionGroup", },
      make_shared<NodeLoader_SystemNodeloaderformatActionsEmptyNlf>(),
      true
  );
}



string const& NodeLoader_SystemNodeloaderformatActionsEmptyNlf::loadable_class () const {
  static string cls = "ActionLoadable";
  return cls;
}


bool NodeLoader_SystemNodeloaderformatActionsEmptyNlf::isCompatibleLoadable (shared_ptr<NodeLoadable> const& loadable) {
  return dpc<ActionLoadable>(loadable) != null;
}


bool NodeLoader_SystemNodeloaderformatActionsEmptyNlf::_preLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  auto super_ok = fun_tree::NodeLoader::_preLoad(ctx, node, loadable);
  if (super_ok == false)
    return false;

  return true;
}


bool NodeLoader_SystemNodeloaderformatActionsEmptyNlf::_postLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  auto super_ok = fun_tree::NodeLoader::_postLoad(ctx, node, loadable);
  if (super_ok == false)
    return false;

  static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/actions/empty.nlf");
  auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
  unlikely (code_set == null) {
    LOG_ERR("code_set is null --- system/node_loader_format/actions/empty.nlf");
    return null;
  }

  auto result = code_set->execute(1, {Var(&ctx), Var(node), Var(loadable)});
  return result.as<bool>();

}


shared_ptr<Format> const&  NodeLoader_SystemNodeloaderformatActionsEmptyNlf::_getFormat () {
  static shared_ptr<Format> format =
    make_shared<ObjectFormat>(
      vector<vector<AttributeLoader>>{
      }
    );
  return format;
}


}






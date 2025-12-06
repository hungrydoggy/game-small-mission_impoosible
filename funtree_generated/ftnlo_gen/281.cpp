

#include "./281.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./281.0.code"






namespace appetizer {


using namespace fun_tree;
using namespace fun_tree::node_loader_format;

using std::make_shared;



__attribute__((constructor))
static void ___NodeLoaderBundleRegisterer___ () {

  NodeLoaderBundle::default_bundle().registerLoader(
      vector<string>{"GlobalObject", },
      vector<string>{},
      make_shared<NodeLoader_SystemNodeloaderformatEtcGlobalobjectNlf>(),
      true
  );
}



string const& NodeLoader_SystemNodeloaderformatEtcGlobalobjectNlf::loadable_class () const {
  static string cls = "GlobalObject";
  return cls;
}


bool NodeLoader_SystemNodeloaderformatEtcGlobalobjectNlf::isCompatibleLoadable (shared_ptr<NodeLoadable> const& loadable) {
  return dpc<GlobalObject>(loadable) != null;
}


bool NodeLoader_SystemNodeloaderformatEtcGlobalobjectNlf::_preLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  auto super_ok = fun_tree::NodeLoader::_preLoad(ctx, node, loadable);
  if (super_ok == false)
    return false;

  return true;
}


bool NodeLoader_SystemNodeloaderformatEtcGlobalobjectNlf::_postLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  auto super_ok = fun_tree::NodeLoader::_postLoad(ctx, node, loadable);
  if (super_ok == false)
    return false;

  return true;
}


shared_ptr<Format> const&  NodeLoader_SystemNodeloaderformatEtcGlobalobjectNlf::_getFormat () {
  static shared_ptr<Format> format =
    make_shared<ObjectFormat>(
      vector<vector<AttributeLoader>>{
      }
    );
  return format;
}


}






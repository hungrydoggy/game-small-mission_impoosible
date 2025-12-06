

#include "./253.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./253.0.code"






namespace appetizer {


using namespace fun_tree;
using namespace fun_tree::node_loader_format;

using std::make_shared;



__attribute__((constructor))
static void ___NodeLoaderBundleRegisterer___ () {

  NodeLoaderBundle::default_bundle().registerLoader(
      vector<string>{"UpdatableSerializer", "UpdatableSttSer", "UpdateSttSer", },
      vector<string>{"StateSerializerGroup", },
      make_shared<NodeLoader_SystemNodeloaderformatStateserializerUpdatableNlf>(),
      true
  );
}



string const& NodeLoader_SystemNodeloaderformatStateserializerUpdatableNlf::loadable_class () const {
  static string cls = "StateSerializerNodeLoadable";
  return cls;
}


bool NodeLoader_SystemNodeloaderformatStateserializerUpdatableNlf::isCompatibleLoadable (shared_ptr<NodeLoadable> const& loadable) {
  return dpc<StateSerializerNodeLoadable>(loadable) != null;
}


bool NodeLoader_SystemNodeloaderformatStateserializerUpdatableNlf::_preLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  auto super_ok = fun_tree::NodeLoader::_preLoad(ctx, node, loadable);
  if (super_ok == false)
    return false;

  return true;
}


bool NodeLoader_SystemNodeloaderformatStateserializerUpdatableNlf::_postLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  auto super_ok = fun_tree::NodeLoader::_postLoad(ctx, node, loadable);
  if (super_ok == false)
    return false;

  static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/state_serializer/updatable.nlf");
  auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
  unlikely (code_set == null) {
    LOG_ERR("code_set is null --- system/node_loader_format/state_serializer/updatable.nlf");
    return null;
  }

  auto result = code_set->execute(1, {Var(&ctx), Var(node), Var(loadable)});
  return result.as<bool>();

}


shared_ptr<Format> const&  NodeLoader_SystemNodeloaderformatStateserializerUpdatableNlf::_getFormat () {
  static shared_ptr<Format> format =
    make_shared<ObjectFormat>(
      vector<vector<AttributeLoader>>{
        vector<AttributeLoader>{
          AttributeLoader{
            "name",
            "nam",
            vector<string>{ },
            false,
            vector<string>{ },
            make_shared<ValueFormat>(
              Content::Type::VALUE,
              VarContentTypes::STRING,
              "",
              [](
                  FormatContext& ctx,
                  shared_ptr<NodeLoadable> const& loadable,
                  shared_ptr<Node> const& node,
                  shared_ptr<Content> const& content
              ) {
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/state_serializer/updatable.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/state_serializer/updatable.nlf");
                  return Var(false);
                }
                return code_set->execute(2, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
        },
      }
    );
  return format;
}


}






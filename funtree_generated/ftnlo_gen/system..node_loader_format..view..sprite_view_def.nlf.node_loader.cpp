

#include "./system..node_loader_format..view..sprite_view_def.nlf.node_loader.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./system..node_loader_format..view..sprite_view_def.nlf.node_loader.0.code"






namespace appetizer {


using namespace fun_tree;
using namespace fun_tree::node_loader_format;

using std::make_shared;



__attribute__((constructor))
static void ___NodeLoaderBundleRegisterer___ () {

  NodeLoaderBundle::default_bundle().registerLoader(
      vector<string>{"SpriteViewDef", "SpriteView", "Sprite", },
      vector<string>{"ViewDefGroup", "ObjectTraitGroup", },
      make_shared<NodeLoader_SystemNodeloaderformatViewSpriteviewdefNlf>(),
      true
  );
}



string const& NodeLoader_SystemNodeloaderformatViewSpriteviewdefNlf::loadable_class () const {
  static string cls = "SpriteViewDef";
  return cls;
}


bool NodeLoader_SystemNodeloaderformatViewSpriteviewdefNlf::isCompatibleLoadable (shared_ptr<NodeLoadable> const& loadable) {
  return dpc<SpriteViewDef>(loadable) != null;
}


bool NodeLoader_SystemNodeloaderformatViewSpriteviewdefNlf::_preLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  auto super_ok = fun_tree::NodeLoader::_preLoad(ctx, node, loadable);
  if (super_ok == false)
    return false;

  return true;
}


bool NodeLoader_SystemNodeloaderformatViewSpriteviewdefNlf::_postLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  auto super_ok = fun_tree::NodeLoader::_postLoad(ctx, node, loadable);
  if (super_ok == false)
    return false;

  return true;
}


shared_ptr<Format> const&  NodeLoader_SystemNodeloaderformatViewSpriteviewdefNlf::_getFormat () {
  static shared_ptr<Format> format =
    make_shared<ObjectFormat>(
      vector<vector<AttributeLoader>>{
        vector<AttributeLoader>{
          AttributeLoader{
            "repeat_count",
            "cnt",
            vector<string>{ },
            false,
            vector<string>{ },
            make_shared<ValueFormat>(
              Content::Type::VALUE,
              VarContentTypes::NUMBER,
              "",
              [](
                  FormatContext& ctx,
                  shared_ptr<NodeLoadable> const& loadable,
                  shared_ptr<Node> const& node,
                  shared_ptr<Content> const& content
              ) {
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/view/sprite_view_def.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/view/sprite_view_def.nlf");
                  return Var(false);
                }
                return code_set->execute(1, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "cells",
            "cel",
            vector<string>{ },
            true,
            vector<string>{ },
            make_shared<SequenceFormat>(
              0,
              0,
              vector<shared_ptr<Format>>{
                make_shared<ValueFormat>(
                  Content::Type::OBJECT,
                  0,
                  "CellDef",
                  [](
                      FormatContext& ctx,
                      shared_ptr<NodeLoadable> const& loadable,
                      shared_ptr<Node> const& node,
                      shared_ptr<Content> const& content
                  ) {
                    static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/view/sprite_view_def.nlf");
                    auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                    unlikely (code_set == null) {
                      LOG_ERR("code_set is null --- system/node_loader_format/view/sprite_view_def.nlf");
                      return Var(false);
                    }
                    return code_set->execute(2, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                  }
                ),
              }
            )
          },
          AttributeLoader{
            "cell_action_list",
            "acl",
            vector<string>{ },
            false,
            vector<string>{ },
            make_shared<SequenceFormat>(
              0,
              0,
              vector<shared_ptr<Format>>{
                make_shared<ValueFormat>(
                  Content::Type::OBJECT,
                  0,
                  "CellActionCallItem",
                  [](
                      FormatContext& ctx,
                      shared_ptr<NodeLoadable> const& loadable,
                      shared_ptr<Node> const& node,
                      shared_ptr<Content> const& content
                  ) {
                    static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/view/sprite_view_def.nlf");
                    auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                    unlikely (code_set == null) {
                      LOG_ERR("code_set is null --- system/node_loader_format/view/sprite_view_def.nlf");
                      return Var(false);
                    }
                    return code_set->execute(3, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                  }
                ),
              }
            )
          },
        },
      }
    );
  return format;
}


}








#include "./system..node_loader_format..etc..vertex_animation_texture..vertex_animation_texture_state_selector.nlf.node_loader.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./system..node_loader_format..etc..vertex_animation_texture..vertex_animation_texture_state_selector.nlf.node_loader.0.code"






namespace appetizer {


using namespace fun_tree;
using namespace fun_tree::node_loader_format;

using std::make_shared;



__attribute__((constructor))
static void ___NodeLoaderBundleRegisterer___ () {

  NodeLoaderBundle::default_bundle().registerLoader(
      vector<string>{"VertexAnimationTextureStateSelector", "VATStateSelector", },
      vector<string>{"ObjectTraitGroup", "VertexAnimationTextureStateGroup", },
      make_shared<NodeLoader_SystemNodeloaderformatEtcVertexanimationtextureVertexanimationtexturestateselectorNlf>(),
      true
  );
}



string const& NodeLoader_SystemNodeloaderformatEtcVertexanimationtextureVertexanimationtexturestateselectorNlf::loadable_class () const {
  static string cls = "VertexAnimationTextureStateSelector";
  return cls;
}


bool NodeLoader_SystemNodeloaderformatEtcVertexanimationtextureVertexanimationtexturestateselectorNlf::isCompatibleLoadable (shared_ptr<NodeLoadable> const& loadable) {
  return dpc<VertexAnimationTextureStateSelector>(loadable) != null;
}


bool NodeLoader_SystemNodeloaderformatEtcVertexanimationtextureVertexanimationtexturestateselectorNlf::_preLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  auto super_ok = fun_tree::NodeLoader::_preLoad(ctx, node, loadable);
  if (super_ok == false)
    return false;

  return true;
}


bool NodeLoader_SystemNodeloaderformatEtcVertexanimationtextureVertexanimationtexturestateselectorNlf::_postLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  auto super_ok = fun_tree::NodeLoader::_postLoad(ctx, node, loadable);
  if (super_ok == false)
    return false;

  return true;
}


shared_ptr<Format> const&  NodeLoader_SystemNodeloaderformatEtcVertexanimationtextureVertexanimationtexturestateselectorNlf::_getFormat () {
  static shared_ptr<Format> format =
    make_shared<ObjectFormat>(
      vector<vector<AttributeLoader>>{
        vector<AttributeLoader>{
          AttributeLoader{
            "vertex_animation_texture_states",
            "stt",
            vector<string>{ "vat_states", },
            true,
            vector<string>{ },
            make_shared<SequenceFormat>(
              1,
              -1,
              vector<shared_ptr<Format>>{
                make_shared<ValueFormat>(
                  Content::Type::OBJECT,
                  0,
                  "VertexAnimationTextureStateItem",
                  [](
                      FormatContext& ctx,
                      shared_ptr<NodeLoadable> const& loadable,
                      shared_ptr<Node> const& node,
                      shared_ptr<Content> const& content
                  ) {
                    static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/etc/vertex_animation_texture/vertex_animation_texture_state_selector.nlf");
                    auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                    unlikely (code_set == null) {
                      LOG_ERR("code_set is null --- system/node_loader_format/etc/vertex_animation_texture/vertex_animation_texture_state_selector.nlf");
                      return Var(false);
                    }
                    return code_set->execute(1, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                  }
                ),
              }
            )
          },
          AttributeLoader{
            "time_scale",
            "tsc",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/etc/vertex_animation_texture/vertex_animation_texture_state_selector.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/etc/vertex_animation_texture/vertex_animation_texture_state_selector.nlf");
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






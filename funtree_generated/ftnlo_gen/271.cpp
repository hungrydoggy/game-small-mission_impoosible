

#include "./271.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./271.0.code"






namespace appetizer {


using namespace fun_tree;
using namespace fun_tree::node_loader_format;

using std::make_shared;



__attribute__((constructor))
static void ___NodeLoaderBundleRegisterer___ () {

  NodeLoaderBundle::default_bundle().registerLoader(
      vector<string>{"VertexAnimationTextureState", "VATState", "VertexAnimationTextureStateSingle", "VATStateSingle", },
      vector<string>{"ObjectTraitGroup", "VertexAnimationTextureStateGroup", },
      make_shared<NodeLoader_SystemNodeloaderformatEtcVertexanimationtextureVertexanimationtexturestatesingleNlf>(),
      true
  );
}



string const& NodeLoader_SystemNodeloaderformatEtcVertexanimationtextureVertexanimationtexturestatesingleNlf::loadable_class () const {
  static string cls = "VertexAnimationTextureStateSingle";
  return cls;
}


bool NodeLoader_SystemNodeloaderformatEtcVertexanimationtextureVertexanimationtexturestatesingleNlf::isCompatibleLoadable (shared_ptr<NodeLoadable> const& loadable) {
  return dpc<VertexAnimationTextureStateSingle>(loadable) != null;
}


bool NodeLoader_SystemNodeloaderformatEtcVertexanimationtextureVertexanimationtexturestatesingleNlf::_preLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  auto super_ok = fun_tree::NodeLoader::_preLoad(ctx, node, loadable);
  if (super_ok == false)
    return false;

  return true;
}


bool NodeLoader_SystemNodeloaderformatEtcVertexanimationtextureVertexanimationtexturestatesingleNlf::_postLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  auto super_ok = fun_tree::NodeLoader::_postLoad(ctx, node, loadable);
  if (super_ok == false)
    return false;

  return true;
}


shared_ptr<Format> const&  NodeLoader_SystemNodeloaderformatEtcVertexanimationtextureVertexanimationtexturestatesingleNlf::_getFormat () {
  static shared_ptr<Format> format =
    make_shared<ObjectFormat>(
      vector<vector<AttributeLoader>>{
        vector<AttributeLoader>{
          AttributeLoader{
            "vertex_animation_texture",
            "vat",
            vector<string>{ },
            true,
            vector<string>{ },
            make_shared<ValueFormat>(
              Content::Type::OBJECT,
              0,
              "VertexAnimationTexture",
              [](
                  FormatContext& ctx,
                  shared_ptr<NodeLoadable> const& loadable,
                  shared_ptr<Node> const& node,
                  shared_ptr<Content> const& content
              ) {
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/etc/vertex_animation_texture/vertex_animation_texture_state_single.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/etc/vertex_animation_texture/vertex_animation_texture_state_single.nlf");
                  return Var(false);
                }
                return code_set->execute(1, {Var(&ctx), Var(loadable), Var(node), Var(content)});
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/etc/vertex_animation_texture/vertex_animation_texture_state_single.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/etc/vertex_animation_texture/vertex_animation_texture_state_single.nlf");
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






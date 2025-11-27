

#include "./system..node_loader_format..mesh..mesh.nlf.node_loader.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./system..node_loader_format..mesh..mesh.nlf.node_loader.0.code"






namespace appetizer {


using namespace fun_tree;
using namespace fun_tree::node_loader_format;

using std::make_shared;



__attribute__((constructor))
static void ___NodeLoaderBundleRegisterer___ () {

  NodeLoaderBundle::default_bundle().registerLoader(
      vector<string>{"Mesh", },
      vector<string>{},
      make_shared<NodeLoader_SystemNodeloaderformatMeshMeshNlf>(),
      true
  );
}



string const& NodeLoader_SystemNodeloaderformatMeshMeshNlf::loadable_class () const {
  static string cls = "Mesh";
  return cls;
}


bool NodeLoader_SystemNodeloaderformatMeshMeshNlf::isCompatibleLoadable (shared_ptr<NodeLoadable> const& loadable) {
  return dpc<Mesh>(loadable) != null;
}


bool NodeLoader_SystemNodeloaderformatMeshMeshNlf::_preLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  auto super_ok = fun_tree::NodeLoader::_preLoad(ctx, node, loadable);
  if (super_ok == false)
    return false;

  return true;
}


bool NodeLoader_SystemNodeloaderformatMeshMeshNlf::_postLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  auto super_ok = fun_tree::NodeLoader::_postLoad(ctx, node, loadable);
  if (super_ok == false)
    return false;

  return true;
}


shared_ptr<Format> const&  NodeLoader_SystemNodeloaderformatMeshMeshNlf::_getFormat () {
  static shared_ptr<Format> format =
    make_shared<ObjectFormat>(
      vector<vector<AttributeLoader>>{
        vector<AttributeLoader>{
          AttributeLoader{
            "vertex_properties",
            "vpr",
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
                  "VertexProperty",
                  [](
                      FormatContext& ctx,
                      shared_ptr<NodeLoadable> const& loadable,
                      shared_ptr<Node> const& node,
                      shared_ptr<Content> const& content
                  ) {
                    static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/mesh/mesh.nlf");
                    auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                    unlikely (code_set == null) {
                      LOG_ERR("code_set is null --- system/node_loader_format/mesh/mesh.nlf");
                      return Var(false);
                    }
                    return code_set->execute(1, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                  }
                ),
              }
            )
          },
          AttributeLoader{
            "vertex_data",
            "vdt",
            vector<string>{ },
            true,
            vector<string>{ },
            make_shared<SequenceFormat>(
              0,
              0,
              vector<shared_ptr<Format>>{
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
                    static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/mesh/mesh.nlf");
                    auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                    unlikely (code_set == null) {
                      LOG_ERR("code_set is null --- system/node_loader_format/mesh/mesh.nlf");
                      return Var(false);
                    }
                    return code_set->execute(2, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                  }
                ),
              }
            )
          },
          AttributeLoader{
            "indices",
            "idx",
            vector<string>{ },
            true,
            vector<string>{ },
            make_shared<SequenceFormat>(
              0,
              0,
              vector<shared_ptr<Format>>{
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
                    static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/mesh/mesh.nlf");
                    auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                    unlikely (code_set == null) {
                      LOG_ERR("code_set is null --- system/node_loader_format/mesh/mesh.nlf");
                      return Var(false);
                    }
                    return code_set->execute(3, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                  }
                ),
              }
            )
          },
          AttributeLoader{
            "bind_shape_matrix",
            "bsm",
            vector<string>{ },
            false,
            vector<string>{ },
            make_shared<SequenceFormat>(
              16,
              16,
              [](
                  FormatContext& ctx,
                  shared_ptr<NodeLoadable> const& loadable,
                  shared_ptr<Node> const& node,
                  shared_ptr<Content> const& content
              ) {
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/mesh/mesh.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/mesh/mesh.nlf");
                  return Var(false);
                }
                return code_set->execute(4, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              },
              vector<shared_ptr<Format>>{
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
                    static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/common/matrix.nlf");
                    auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                    unlikely (code_set == null) {
                      LOG_ERR("code_set is null --- system/node_loader_format/common/matrix.nlf");
                      return Var(false);
                    }
                    return code_set->execute(1, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                  }
                ),
              }
            )
          },
          AttributeLoader{
            "bones",
            "bon",
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
                  "Bone",
                  [](
                      FormatContext& ctx,
                      shared_ptr<NodeLoadable> const& loadable,
                      shared_ptr<Node> const& node,
                      shared_ptr<Content> const& content
                  ) {
                    static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/mesh/mesh.nlf");
                    auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                    unlikely (code_set == null) {
                      LOG_ERR("code_set is null --- system/node_loader_format/mesh/mesh.nlf");
                      return Var(false);
                    }
                    return code_set->execute(5, {Var(&ctx), Var(loadable), Var(node), Var(content)});
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






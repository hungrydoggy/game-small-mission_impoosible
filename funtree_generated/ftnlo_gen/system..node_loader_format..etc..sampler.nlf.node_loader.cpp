

#include "./system..node_loader_format..etc..sampler.nlf.node_loader.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./system..node_loader_format..etc..sampler.nlf.node_loader.0.code"






namespace appetizer {


using namespace fun_tree;
using namespace fun_tree::node_loader_format;

using std::make_shared;



__attribute__((constructor))
static void ___NodeLoaderBundleRegisterer___ () {

  NodeLoaderBundle::default_bundle().registerLoader(
      vector<string>{"Sampler", },
      vector<string>{},
      make_shared<NodeLoader_SystemNodeloaderformatEtcSamplerNlf>(),
      true
  );
}



string const& NodeLoader_SystemNodeloaderformatEtcSamplerNlf::loadable_class () const {
  static string cls = "Sampler";
  return cls;
}


bool NodeLoader_SystemNodeloaderformatEtcSamplerNlf::isCompatibleLoadable (shared_ptr<NodeLoadable> const& loadable) {
  return dpc<Sampler>(loadable) != null;
}


bool NodeLoader_SystemNodeloaderformatEtcSamplerNlf::_preLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  auto super_ok = fun_tree::NodeLoader::_preLoad(ctx, node, loadable);
  if (super_ok == false)
    return false;

  return true;
}


bool NodeLoader_SystemNodeloaderformatEtcSamplerNlf::_postLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  auto super_ok = fun_tree::NodeLoader::_postLoad(ctx, node, loadable);
  if (super_ok == false)
    return false;

  return true;
}


shared_ptr<Format> const&  NodeLoader_SystemNodeloaderformatEtcSamplerNlf::_getFormat () {
  static shared_ptr<Format> format =
    make_shared<ObjectFormat>(
      vector<vector<AttributeLoader>>{
        vector<AttributeLoader>{
          AttributeLoader{
            "mag_filter",
            "mgf",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/etc/sampler.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/etc/sampler.nlf");
                  return Var(false);
                }
                return code_set->execute(1, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "min_filter",
            "mnf",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/etc/sampler.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/etc/sampler.nlf");
                  return Var(false);
                }
                return code_set->execute(2, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "wrap_s",
            "wrs",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/etc/sampler.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/etc/sampler.nlf");
                  return Var(false);
                }
                return code_set->execute(3, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "wrap_t",
            "wrt",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/etc/sampler.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/etc/sampler.nlf");
                  return Var(false);
                }
                return code_set->execute(4, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "mip_levels",
            "mip",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/etc/sampler.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/etc/sampler.nlf");
                  return Var(false);
                }
                return code_set->execute(5, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "compare_enable",
            "cmp",
            vector<string>{ },
            false,
            vector<string>{ },
            make_shared<ValueFormat>(
              Content::Type::VALUE,
              VarContentTypes::BOOL,
              "",
              [](
                  FormatContext& ctx,
                  shared_ptr<NodeLoadable> const& loadable,
                  shared_ptr<Node> const& node,
                  shared_ptr<Content> const& content
              ) {
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/etc/sampler.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/etc/sampler.nlf");
                  return Var(false);
                }
                return code_set->execute(6, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
        },
      }
    );
  return format;
}


}






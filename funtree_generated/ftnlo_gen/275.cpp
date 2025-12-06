

#include "./275.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./275.0.code"






namespace appetizer {


using namespace fun_tree;
using namespace fun_tree::node_loader_format;

using std::make_shared;



__attribute__((constructor))
static void ___NodeLoaderBundleRegisterer___ () {

  NodeLoaderBundle::default_bundle().registerLoader(
      vector<string>{"PlatformSetting", },
      vector<string>{},
      make_shared<NodeLoader_SystemNodeloaderformatEtcPlatformsettingNlf>(),
      true
  );
}



string const& NodeLoader_SystemNodeloaderformatEtcPlatformsettingNlf::loadable_class () const {
  static string cls = "PlatformSetting";
  return cls;
}


bool NodeLoader_SystemNodeloaderformatEtcPlatformsettingNlf::isCompatibleLoadable (shared_ptr<NodeLoadable> const& loadable) {
  return dpc<PlatformSetting>(loadable) != null;
}


bool NodeLoader_SystemNodeloaderformatEtcPlatformsettingNlf::_preLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  auto super_ok = fun_tree::NodeLoader::_preLoad(ctx, node, loadable);
  if (super_ok == false)
    return false;

  return true;
}


bool NodeLoader_SystemNodeloaderformatEtcPlatformsettingNlf::_postLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  auto super_ok = fun_tree::NodeLoader::_postLoad(ctx, node, loadable);
  if (super_ok == false)
    return false;

  return true;
}


shared_ptr<Format> const&  NodeLoader_SystemNodeloaderformatEtcPlatformsettingNlf::_getFormat () {
  static shared_ptr<Format> format =
    make_shared<ObjectFormat>(
      vector<vector<AttributeLoader>>{
        vector<AttributeLoader>{
          AttributeLoader{
            "game_base_axis",
            "bax",
            vector<string>{ },
            false,
            vector<string>{ },
            make_shared<ValueFormat>(
              Content::Type::OBJECT,
              0,
              "GameBaseAxis",
              [](
                  FormatContext& ctx,
                  shared_ptr<NodeLoadable> const& loadable,
                  shared_ptr<Node> const& node,
                  shared_ptr<Content> const& content
              ) {
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/etc/platform_setting.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/etc/platform_setting.nlf");
                  return Var(false);
                }
                return code_set->execute(1, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "resolutions",
            "rsl",
            vector<string>{ },
            false,
            vector<string>{ "game_base_axis", },
            make_shared<SequenceFormat>(
              0,
              0,
              vector<shared_ptr<Format>>{
                make_shared<SequenceFormat>(
                  2,
                  4,
                  [](
                      FormatContext& ctx,
                      shared_ptr<NodeLoadable> const& loadable,
                      shared_ptr<Node> const& node,
                      shared_ptr<Content> const& content
                  ) {
                    static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/etc/platform_setting.nlf");
                    auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                    unlikely (code_set == null) {
                      LOG_ERR("code_set is null --- system/node_loader_format/etc/platform_setting.nlf");
                      return Var(false);
                    }
                    return code_set->execute(2, {Var(&ctx), Var(loadable), Var(node), Var(content)});
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
                        static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/common/resolution.nlf");
                        auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                        unlikely (code_set == null) {
                          LOG_ERR("code_set is null --- system/node_loader_format/common/resolution.nlf");
                          return Var(false);
                        }
                        return code_set->execute(1, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                      }
                    ),
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
                        static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/common/resolution.nlf");
                        auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                        unlikely (code_set == null) {
                          LOG_ERR("code_set is null --- system/node_loader_format/common/resolution.nlf");
                          return Var(false);
                        }
                        return code_set->execute(2, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                      }
                    ),
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
                        static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/common/resolution.nlf");
                        auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                        unlikely (code_set == null) {
                          LOG_ERR("code_set is null --- system/node_loader_format/common/resolution.nlf");
                          return Var(false);
                        }
                        return code_set->execute(3, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                      }
                    ),
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
                        static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/common/resolution.nlf");
                        auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                        unlikely (code_set == null) {
                          LOG_ERR("code_set is null --- system/node_loader_format/common/resolution.nlf");
                          return Var(false);
                        }
                        return code_set->execute(4, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                      }
                    ),
                  }
                ),
              }
            )
          },
          AttributeLoader{
            "width",
            "wid",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/etc/platform_setting.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/etc/platform_setting.nlf");
                  return Var(false);
                }
                return code_set->execute(3, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "height",
            "hei",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/etc/platform_setting.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/etc/platform_setting.nlf");
                  return Var(false);
                }
                return code_set->execute(4, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "width_for_font",
            "wff",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/etc/platform_setting.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/etc/platform_setting.nlf");
                  return Var(false);
                }
                return code_set->execute(5, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "height_for_font",
            "hff",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/etc/platform_setting.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/etc/platform_setting.nlf");
                  return Var(false);
                }
                return code_set->execute(6, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "monitor_index",
            "mid",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/etc/platform_setting.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/etc/platform_setting.nlf");
                  return Var(false);
                }
                return code_set->execute(7, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "fullscreen_mode",
            "ful",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/etc/platform_setting.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/etc/platform_setting.nlf");
                  return Var(false);
                }
                return code_set->execute(8, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "need_title_bar",
            "ttl",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/etc/platform_setting.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/etc/platform_setting.nlf");
                  return Var(false);
                }
                return code_set->execute(9, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
        },
      }
    );
  return format;
}


}






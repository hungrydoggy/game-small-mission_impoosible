

#include "./116.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/_macro_loader.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./116.0.code"



#include "./116.1.code"



namespace appetizer {


using namespace fun_tree;
using namespace fun_tree::node_loader_format;

using std::make_shared;



__attribute__((constructor))
static void ___MacroLoaderBundleRegisterer___ () {

  MacroLoaderBundle::default_bundle().registerMacroLoader(
      vector<string>{"Sprite.makeCellsBySheet", "sprite.makeCellsBySheet", "sprite.cellsBySheet", },
      make_shared<Macro_SystemMacroesSpriteMakecellsMac>(),
      true
  );
}



string const& Macro_SystemMacroesSpriteMakecellsMac::loadable_class () const {
  static string cls = "Macro";
  return cls;
}


bool Macro_SystemMacroesSpriteMakecellsMac::isCompatibleLoadable (shared_ptr<NodeLoadable> const& loadable) {
  return dpc<Macro>(loadable) != null;
}


bool Macro_SystemMacroesSpriteMakecellsMac::preEmbody (
    shared_ptr<Node> const& node,
    shared_ptr<Content> const& call_params,
    EmbodyFunc embody_func
) {
  return true;
}


bool Macro_SystemMacroesSpriteMakecellsMac::_preLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  return true;
}


bool Macro_SystemMacroesSpriteMakecellsMac::_postLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  return true;
}


static shared_ptr<Content> __on_call_code_14 (
    shared_ptr<Node> const& node,
    shared_ptr<Content> const& content,
    shared_ptr<Macro> const& self
) {
  static uint code_path_id = PathRegistry::lookUp("system/macroes/sprite.make_cells.mac");
  auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
  unlikely (code_set == null) {
    LOG_ERR("code_set is null --- system/macroes/sprite.make_cells.mac");
    return null;
  }

  auto result = code_set->execute(14, {Var(node), Var(content), Var(self)});
  return result.v<shared_ptr<Content>>();
}


shared_ptr<Content> Macro_SystemMacroesSpriteMakecellsMac::execute (
    shared_ptr<Node> const& node,
    shared_ptr<Content> const& content,
    int code_idx,
    shared_ptr<Macro> const& macro
) {
  switch (code_idx) {
    case 14: return __on_call_code_14(node, content, macro);
    default:
      LOG_ERR("unknown code_idx %u --- \"116.cpp\"", code_idx);
      return null;
  }
}

shared_ptr<Content> Macro_SystemMacroesSpriteMakecellsMac::execute (
    shared_ptr<Node> const& node,
    shared_ptr<Content> const& content,
    shared_ptr<Macro> const& macro
) {
  return execute(node, content, 14, macro);
}

shared_ptr<Format> const&  Macro_SystemMacroesSpriteMakecellsMac::_getFormat () {
  static shared_ptr<Format> format =
    make_shared<MapFormat>(
      vector<vector<AttributeLoader>>{
        vector<AttributeLoader>{
          AttributeLoader{
            "sheet_texture_path",
            "tex",
            vector<string>{ },
            true,
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
                static uint code_path_id = PathRegistry::lookUp("system/macroes/sprite.make_cells.mac");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/macroes/sprite.make_cells.mac");
                  return Var(false);
                }
                return code_set->execute(2, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "row_count",
            "row",
            vector<string>{ },
            true,
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
                static uint code_path_id = PathRegistry::lookUp("system/macroes/sprite.make_cells.mac");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/macroes/sprite.make_cells.mac");
                  return Var(false);
                }
                return code_set->execute(3, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "col_count",
            "col",
            vector<string>{ },
            true,
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
                static uint code_path_id = PathRegistry::lookUp("system/macroes/sprite.make_cells.mac");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/macroes/sprite.make_cells.mac");
                  return Var(false);
                }
                return code_set->execute(4, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "cell_indices",
            "idx",
            vector<string>{ },
            false,
            vector<string>{ },
            make_shared<FormatGroup>(
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
                    static uint code_path_id = PathRegistry::lookUp("system/macroes/sprite.make_cells.mac");
                    auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                    unlikely (code_set == null) {
                      LOG_ERR("code_set is null --- system/macroes/sprite.make_cells.mac");
                      return Var(false);
                    }
                    return code_set->execute(5, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                  }
                ),
                make_shared<SequenceFormat>(
                  1,
                  -1,
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
                        static uint code_path_id = PathRegistry::lookUp("system/macroes/sprite.make_cells.mac");
                        auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                        unlikely (code_set == null) {
                          LOG_ERR("code_set is null --- system/macroes/sprite.make_cells.mac");
                          return Var(false);
                        }
                        return code_set->execute(6, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                      }
                    ),
                  }
                ),
              }
            )
          },
          AttributeLoader{
            "cell_duration_frames",
            "frm",
            vector<string>{ },
            false,
            vector<string>{ },
            make_shared<FormatGroup>(
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
                    static uint code_path_id = PathRegistry::lookUp("system/macroes/sprite.make_cells.mac");
                    auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                    unlikely (code_set == null) {
                      LOG_ERR("code_set is null --- system/macroes/sprite.make_cells.mac");
                      return Var(false);
                    }
                    return code_set->execute(7, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                  }
                ),
                make_shared<SequenceFormat>(
                  1,
                  -1,
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
                        static uint code_path_id = PathRegistry::lookUp("system/macroes/sprite.make_cells.mac");
                        auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                        unlikely (code_set == null) {
                          LOG_ERR("code_set is null --- system/macroes/sprite.make_cells.mac");
                          return Var(false);
                        }
                        return code_set->execute(8, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                      }
                    ),
                  }
                ),
              }
            )
          },
          AttributeLoader{
            "sampler",
            "sam",
            vector<string>{ },
            false,
            vector<string>{ },
            make_shared<ValueFormat>(
              Content::Type::OBJECT,
              0,
              "Sampler",
              [](
                  FormatContext& ctx,
                  shared_ptr<NodeLoadable> const& loadable,
                  shared_ptr<Node> const& node,
                  shared_ptr<Content> const& content
              ) {
                static uint code_path_id = PathRegistry::lookUp("system/macroes/sprite.make_cells.mac");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/macroes/sprite.make_cells.mac");
                  return Var(false);
                }
                return code_set->execute(9, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "horizontal_align",
            "hor",
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
                static uint code_path_id = PathRegistry::lookUp("system/macroes/sprite.make_cells.mac");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/macroes/sprite.make_cells.mac");
                  return Var(false);
                }
                return code_set->execute(10, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "vertical_align",
            "ver",
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
                static uint code_path_id = PathRegistry::lookUp("system/macroes/sprite.make_cells.mac");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/macroes/sprite.make_cells.mac");
                  return Var(false);
                }
                return code_set->execute(11, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "image_size",
            "siz",
            vector<string>{ },
            true,
            vector<string>{ },
            make_shared<ValueFormat>(
              Content::Type::SEQUENCE,
              0,
              "",
              [](
                  FormatContext& ctx,
                  shared_ptr<NodeLoadable> const& loadable,
                  shared_ptr<Node> const& node,
                  shared_ptr<Content> const& content
              ) {
                static uint code_path_id = PathRegistry::lookUp("system/macroes/sprite.make_cells.mac");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/macroes/sprite.make_cells.mac");
                  return Var(false);
                }
                return code_set->execute(12, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "material",
            "mat",
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
                static uint code_path_id = PathRegistry::lookUp("system/macroes/sprite.make_cells.mac");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/macroes/sprite.make_cells.mac");
                  return Var(false);
                }
                return code_set->execute(13, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
        },
      }
    )
;
  return format;
}


}

#include "./116.15.code"





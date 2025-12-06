

#include "./128.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/_macro_loader.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>







namespace appetizer {


using namespace fun_tree;
using namespace fun_tree::node_loader_format;

using std::make_shared;



__attribute__((constructor))
static void ___MacroLoaderBundleRegisterer___ () {

  MacroLoaderBundle::default_bundle().registerMacroLoader(
      vector<string>{"Sequence.map", "seq.map", },
      make_shared<Macro_SystemMacroesSequenceMapMac>(),
      true
  );
}



string const& Macro_SystemMacroesSequenceMapMac::loadable_class () const {
  static string cls = "Macro";
  return cls;
}


bool Macro_SystemMacroesSequenceMapMac::isCompatibleLoadable (shared_ptr<NodeLoadable> const& loadable) {
  return dpc<Macro>(loadable) != null;
}


bool Macro_SystemMacroesSequenceMapMac::preEmbody (
    shared_ptr<Node> const& node,
    shared_ptr<Content> const& call_params,
    EmbodyFunc embody_func
) {
  static uint code_path_id = PathRegistry::lookUp("system/macroes/sequence.map.mac");
  auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
  unlikely (code_set == null) {
    LOG_ERR("code_set is null --- system/macroes/sequence.map.mac");
    return null;
  }

  auto result = code_set->execute(6, {Var(node), Var(call_params), Var(embody_func)});
  return result.as<bool>();

}


bool Macro_SystemMacroesSequenceMapMac::_preLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  return true;
}


bool Macro_SystemMacroesSequenceMapMac::_postLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  return true;
}


static shared_ptr<Content> __on_call_code_7 (
    shared_ptr<Node> const& node,
    shared_ptr<Content> const& content,
    shared_ptr<Macro> const& self
) {
  static uint code_path_id = PathRegistry::lookUp("system/macroes/sequence.map.mac");
  auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
  unlikely (code_set == null) {
    LOG_ERR("code_set is null --- system/macroes/sequence.map.mac");
    return null;
  }

  auto result = code_set->execute(7, {Var(node), Var(content), Var(self)});
  return result.v<shared_ptr<Content>>();
}


shared_ptr<Content> Macro_SystemMacroesSequenceMapMac::execute (
    shared_ptr<Node> const& node,
    shared_ptr<Content> const& content,
    int code_idx,
    shared_ptr<Macro> const& macro
) {
  switch (code_idx) {
    case 7: return __on_call_code_7(node, content, macro);
    default:
      LOG_ERR("unknown code_idx %u --- \"128.cpp\"", code_idx);
      return null;
  }
}

shared_ptr<Content> Macro_SystemMacroesSequenceMapMac::execute (
    shared_ptr<Node> const& node,
    shared_ptr<Content> const& content,
    shared_ptr<Macro> const& macro
) {
  return execute(node, content, 7, macro);
}

shared_ptr<Format> const&  Macro_SystemMacroesSequenceMapMac::_getFormat () {
  static shared_ptr<Format> format =
    make_shared<FormatGroup>(
      vector<shared_ptr<Format>>{
        make_shared<MapFormat>(
          vector<vector<AttributeLoader>>{
            vector<AttributeLoader>{
              AttributeLoader{
                "source",
                "src",
                vector<string>{ },
                true,
                vector<string>{ },
                make_shared<SequenceFormat>(
                  0,
                  -1,
                  vector<shared_ptr<Format>>{
                    make_shared<ValueFormat>(
                      Content::Type::ANY,
                      0,
                      "",
                      [](
                          FormatContext& ctx,
                          shared_ptr<NodeLoadable> const& loadable,
                          shared_ptr<Node> const& node,
                          shared_ptr<Content> const& content
                      ) {
                        static uint code_path_id = PathRegistry::lookUp("system/macroes/sequence.map.mac");
                        auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                        unlikely (code_set == null) {
                          LOG_ERR("code_set is null --- system/macroes/sequence.map.mac");
                          return Var(false);
                        }
                        return code_set->execute(0, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                      }
                    ),
                  }
                )
              },
              AttributeLoader{
                "node",
                "nod",
                vector<string>{ },
                true,
                vector<string>{ },
                make_shared<ValueFormat>(
                  Content::Type::ANY,
                  0,
                  "",
                  [](
                      FormatContext& ctx,
                      shared_ptr<NodeLoadable> const& loadable,
                      shared_ptr<Node> const& node,
                      shared_ptr<Content> const& content
                  ) {
                    static uint code_path_id = PathRegistry::lookUp("system/macroes/sequence.map.mac");
                    auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                    unlikely (code_set == null) {
                      LOG_ERR("code_set is null --- system/macroes/sequence.map.mac");
                      return Var(false);
                    }
                    return code_set->execute(1, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                  }
                )
              },
              AttributeLoader{
                "element_ref_name",
                "enm",
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
                    static uint code_path_id = PathRegistry::lookUp("system/macroes/sequence.map.mac");
                    auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                    unlikely (code_set == null) {
                      LOG_ERR("code_set is null --- system/macroes/sequence.map.mac");
                      return Var(false);
                    }
                    return code_set->execute(2, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                  }
                )
              },
              AttributeLoader{
                "index_ref_name",
                "idx",
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
                    static uint code_path_id = PathRegistry::lookUp("system/macroes/sequence.map.mac");
                    auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                    unlikely (code_set == null) {
                      LOG_ERR("code_set is null --- system/macroes/sequence.map.mac");
                      return Var(false);
                    }
                    return code_set->execute(3, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                  }
                )
              },
              AttributeLoader{
                "count_ref_name",
                "cnt",
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
                    static uint code_path_id = PathRegistry::lookUp("system/macroes/sequence.map.mac");
                    auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                    unlikely (code_set == null) {
                      LOG_ERR("code_set is null --- system/macroes/sequence.map.mac");
                      return Var(false);
                    }
                    return code_set->execute(4, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                  }
                )
              },
            },
          }
        ),
        make_shared<MapFormat>(
          vector<vector<AttributeLoader>>{
            vector<AttributeLoader>{
              AttributeLoader{
                "result",
                "res",
                vector<string>{ },
                true,
                vector<string>{ },
                make_shared<SequenceFormat>(
                  0,
                  -1,
                  vector<shared_ptr<Format>>{
                    make_shared<ValueFormat>(
                      Content::Type::ANY,
                      0,
                      "",
                      [](
                          FormatContext& ctx,
                          shared_ptr<NodeLoadable> const& loadable,
                          shared_ptr<Node> const& node,
                          shared_ptr<Content> const& content
                      ) {
                        static uint code_path_id = PathRegistry::lookUp("system/macroes/sequence.map.mac");
                        auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                        unlikely (code_set == null) {
                          LOG_ERR("code_set is null --- system/macroes/sequence.map.mac");
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
        ),
      }
    )
;
  return format;
}


}








#include "./102.h"

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
      vector<string>{"Sequence.makeIntSequence", "seq.makeIntSeq", "seq.intSeq", },
      make_shared<Macro_SystemMacroesSequenceMakeintsequenceMac>(),
      true
  );
}



string const& Macro_SystemMacroesSequenceMakeintsequenceMac::loadable_class () const {
  static string cls = "Macro";
  return cls;
}


bool Macro_SystemMacroesSequenceMakeintsequenceMac::isCompatibleLoadable (shared_ptr<NodeLoadable> const& loadable) {
  return dpc<Macro>(loadable) != null;
}


bool Macro_SystemMacroesSequenceMakeintsequenceMac::preEmbody (
    shared_ptr<Node> const& node,
    shared_ptr<Content> const& call_params,
    EmbodyFunc embody_func
) {
  return true;
}


bool Macro_SystemMacroesSequenceMakeintsequenceMac::_preLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  return true;
}


bool Macro_SystemMacroesSequenceMakeintsequenceMac::_postLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  return true;
}


static shared_ptr<Content> __on_call_code_4 (
    shared_ptr<Node> const& node,
    shared_ptr<Content> const& content,
    shared_ptr<Macro> const& self
) {
  static uint code_path_id = PathRegistry::lookUp("system/macroes/sequence.make_int_sequence.mac");
  auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
  unlikely (code_set == null) {
    LOG_ERR("code_set is null --- system/macroes/sequence.make_int_sequence.mac");
    return null;
  }

  auto result = code_set->execute(4, {Var(node), Var(content), Var(self)});
  return result.v<shared_ptr<Content>>();
}


shared_ptr<Content> Macro_SystemMacroesSequenceMakeintsequenceMac::execute (
    shared_ptr<Node> const& node,
    shared_ptr<Content> const& content,
    int code_idx,
    shared_ptr<Macro> const& macro
) {
  switch (code_idx) {
    case 4: return __on_call_code_4(node, content, macro);
    default:
      LOG_ERR("unknown code_idx %u --- \"102.cpp\"", code_idx);
      return null;
  }
}

shared_ptr<Content> Macro_SystemMacroesSequenceMakeintsequenceMac::execute (
    shared_ptr<Node> const& node,
    shared_ptr<Content> const& content,
    shared_ptr<Macro> const& macro
) {
  return execute(node, content, 4, macro);
}

shared_ptr<Format> const&  Macro_SystemMacroesSequenceMakeintsequenceMac::_getFormat () {
  static shared_ptr<Format> format =
    make_shared<FormatGroup>(
      vector<shared_ptr<Format>>{
        make_shared<MapFormat>(
          vector<vector<AttributeLoader>>{
            vector<AttributeLoader>{
              AttributeLoader{
                "start",
                "sta",
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
                    static uint code_path_id = PathRegistry::lookUp("system/macroes/sequence.make_int_sequence.mac");
                    auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                    unlikely (code_set == null) {
                      LOG_ERR("code_set is null --- system/macroes/sequence.make_int_sequence.mac");
                      return Var(false);
                    }
                    return code_set->execute(0, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                  }
                )
              },
              AttributeLoader{
                "end",
                "end",
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
                    static uint code_path_id = PathRegistry::lookUp("system/macroes/sequence.make_int_sequence.mac");
                    auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                    unlikely (code_set == null) {
                      LOG_ERR("code_set is null --- system/macroes/sequence.make_int_sequence.mac");
                      return Var(false);
                    }
                    return code_set->execute(1, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                  }
                )
              },
              AttributeLoader{
                "increment",
                "inc",
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
                    static uint code_path_id = PathRegistry::lookUp("system/macroes/sequence.make_int_sequence.mac");
                    auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                    unlikely (code_set == null) {
                      LOG_ERR("code_set is null --- system/macroes/sequence.make_int_sequence.mac");
                      return Var(false);
                    }
                    return code_set->execute(2, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                  }
                )
              },
            },
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
            static uint code_path_id = PathRegistry::lookUp("system/macroes/sequence.make_int_sequence.mac");
            auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
            unlikely (code_set == null) {
              LOG_ERR("code_set is null --- system/macroes/sequence.make_int_sequence.mac");
              return Var(false);
            }
            return code_set->execute(3, {Var(&ctx), Var(loadable), Var(node), Var(content)});
          }
        ),
      }
    )
;
  return format;
}


}






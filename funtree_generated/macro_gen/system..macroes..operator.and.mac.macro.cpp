

#include "./system..macroes..operator.and.mac.macro.h"

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
      vector<string>{"Operator.and", "and", "&&", },
      make_shared<Macro_SystemMacroesOperatorAndMac>(),
      true
  );
}



string const& Macro_SystemMacroesOperatorAndMac::loadable_class () const {
  static string cls = "Macro";
  return cls;
}


bool Macro_SystemMacroesOperatorAndMac::isCompatibleLoadable (shared_ptr<NodeLoadable> const& loadable) {
  return dpc<Macro>(loadable) != null;
}


bool Macro_SystemMacroesOperatorAndMac::preEmbody (
    shared_ptr<Node> const& node,
    shared_ptr<Content> const& call_params,
    EmbodyFunc embody_func
) {
  return true;
}


bool Macro_SystemMacroesOperatorAndMac::_preLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  return true;
}


bool Macro_SystemMacroesOperatorAndMac::_postLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  return true;
}


static shared_ptr<Content> __on_call_code_1 (
    shared_ptr<Node> const& node,
    shared_ptr<Content> const& content,
    shared_ptr<Macro> const& self
) {
  static uint code_path_id = PathRegistry::lookUp("system/macroes/operator.and.mac");
  auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
  unlikely (code_set == null) {
    LOG_ERR("code_set is null --- system/macroes/operator.and.mac");
    return null;
  }

  auto result = code_set->execute(1, {Var(node), Var(content), Var(self)});
  return result.v<shared_ptr<Content>>();
}


shared_ptr<Content> Macro_SystemMacroesOperatorAndMac::execute (
    shared_ptr<Node> const& node,
    shared_ptr<Content> const& content,
    int code_idx,
    shared_ptr<Macro> const& macro
) {
  switch (code_idx) {
    case 1: return __on_call_code_1(node, content, macro);
    default:
      LOG_ERR("unknown code_idx %u --- \"system..macroes..operator.and.mac.macro.cpp\"", code_idx);
      return null;
  }
}

shared_ptr<Content> Macro_SystemMacroesOperatorAndMac::execute (
    shared_ptr<Node> const& node,
    shared_ptr<Content> const& content,
    shared_ptr<Macro> const& macro
) {
  return execute(node, content, 1, macro);
}

shared_ptr<Format> const&  Macro_SystemMacroesOperatorAndMac::_getFormat () {
  static shared_ptr<Format> format =
    make_shared<SequenceFormat>(
      1,
      -1,
      vector<shared_ptr<Format>>{
        make_shared<ValueFormat>(
          Content::Type::VALUE,
          VarContentTypes::ANY,
          "",
          [](
              FormatContext& ctx,
              shared_ptr<NodeLoadable> const& loadable,
              shared_ptr<Node> const& node,
              shared_ptr<Content> const& content
          ) {
            static uint code_path_id = PathRegistry::lookUp("system/macroes/operator.and.mac");
            auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
            unlikely (code_set == null) {
              LOG_ERR("code_set is null --- system/macroes/operator.and.mac");
              return Var(false);
            }
            return code_set->execute(0, {Var(&ctx), Var(loadable), Var(node), Var(content)});
          }
        ),
      }
    )
;
  return format;
}


}






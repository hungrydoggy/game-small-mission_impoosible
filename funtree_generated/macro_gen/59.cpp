

#include "./59.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/_macro_loader.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./59.0.code"






namespace appetizer {


using namespace fun_tree;
using namespace fun_tree::node_loader_format;

using std::make_shared;



__attribute__((constructor))
static void ___MacroLoaderBundleRegisterer___ () {

  MacroLoaderBundle::default_bundle().registerMacroLoader(
      vector<string>{"Project.isInputProcessable", "prj.isInputProcessable", },
      make_shared<Macro_SystemMacroesProjectIsinputprocessableMac>(),
      true
  );
}



string const& Macro_SystemMacroesProjectIsinputprocessableMac::loadable_class () const {
  static string cls = "Macro";
  return cls;
}


bool Macro_SystemMacroesProjectIsinputprocessableMac::isCompatibleLoadable (shared_ptr<NodeLoadable> const& loadable) {
  return dpc<Macro>(loadable) != null;
}


bool Macro_SystemMacroesProjectIsinputprocessableMac::preEmbody (
    shared_ptr<Node> const& node,
    shared_ptr<Content> const& call_params,
    EmbodyFunc embody_func
) {
  return true;
}


bool Macro_SystemMacroesProjectIsinputprocessableMac::_preLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  return true;
}


bool Macro_SystemMacroesProjectIsinputprocessableMac::_postLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  return true;
}


static shared_ptr<Content> __on_call_code_2 (
    shared_ptr<Node> const& node,
    shared_ptr<Content> const& content,
    shared_ptr<Macro> const& self
) {
  static uint code_path_id = PathRegistry::lookUp("system/macroes/project.is_input_processable.mac");
  auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
  unlikely (code_set == null) {
    LOG_ERR("code_set is null --- system/macroes/project.is_input_processable.mac");
    return null;
  }

  auto result = code_set->execute(2, {Var(node), Var(content), Var(self)});
  return result.v<shared_ptr<Content>>();
}


shared_ptr<Content> Macro_SystemMacroesProjectIsinputprocessableMac::execute (
    shared_ptr<Node> const& node,
    shared_ptr<Content> const& content,
    int code_idx,
    shared_ptr<Macro> const& macro
) {
  switch (code_idx) {
    case 2: return __on_call_code_2(node, content, macro);
    default:
      LOG_ERR("unknown code_idx %u --- \"59.cpp\"", code_idx);
      return null;
  }
}

shared_ptr<Content> Macro_SystemMacroesProjectIsinputprocessableMac::execute (
    shared_ptr<Node> const& node,
    shared_ptr<Content> const& content,
    shared_ptr<Macro> const& macro
) {
  return execute(node, content, 2, macro);
}

shared_ptr<Format> const&  Macro_SystemMacroesProjectIsinputprocessableMac::_getFormat () {
  static shared_ptr<Format> format =
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
        static uint code_path_id = PathRegistry::lookUp("system/macroes/project.is_input_processable.mac");
        auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
        unlikely (code_set == null) {
          LOG_ERR("code_set is null --- system/macroes/project.is_input_processable.mac");
          return Var(false);
        }
        return code_set->execute(1, {Var(&ctx), Var(loadable), Var(node), Var(content)});
      }
    )
;
  return format;
}


}






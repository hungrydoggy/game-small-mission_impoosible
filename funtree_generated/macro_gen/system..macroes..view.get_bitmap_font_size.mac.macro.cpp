

#include "./system..macroes..view.get_bitmap_font_size.mac.macro.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/_macro_loader.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./system..macroes..view.get_bitmap_font_size.mac.macro.0.code"






namespace appetizer {


using namespace fun_tree;
using namespace fun_tree::node_loader_format;

using std::make_shared;



__attribute__((constructor))
static void ___MacroLoaderBundleRegisterer___ () {

  MacroLoaderBundle::default_bundle().registerMacroLoader(
      vector<string>{"View.getBitmapFontSize", "vie.bitmapFontSize", "vie.bmfSize", },
      make_shared<Macro_SystemMacroesViewGetbitmapfontsizeMac>(),
      true
  );
}



string const& Macro_SystemMacroesViewGetbitmapfontsizeMac::loadable_class () const {
  static string cls = "Macro";
  return cls;
}


bool Macro_SystemMacroesViewGetbitmapfontsizeMac::isCompatibleLoadable (shared_ptr<NodeLoadable> const& loadable) {
  return dpc<Macro>(loadable) != null;
}


bool Macro_SystemMacroesViewGetbitmapfontsizeMac::preEmbody (
    shared_ptr<Node> const& node,
    shared_ptr<Content> const& call_params,
    EmbodyFunc embody_func
) {
  return true;
}


bool Macro_SystemMacroesViewGetbitmapfontsizeMac::_preLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  return true;
}


bool Macro_SystemMacroesViewGetbitmapfontsizeMac::_postLoad (
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
  static uint code_path_id = PathRegistry::lookUp("system/macroes/view.get_bitmap_font_size.mac");
  auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
  unlikely (code_set == null) {
    LOG_ERR("code_set is null --- system/macroes/view.get_bitmap_font_size.mac");
    return null;
  }

  auto result = code_set->execute(2, {Var(node), Var(content), Var(self)});
  return result.v<shared_ptr<Content>>();
}


shared_ptr<Content> Macro_SystemMacroesViewGetbitmapfontsizeMac::execute (
    shared_ptr<Node> const& node,
    shared_ptr<Content> const& content,
    int code_idx,
    shared_ptr<Macro> const& macro
) {
  switch (code_idx) {
    case 2: return __on_call_code_2(node, content, macro);
    default:
      LOG_ERR("unknown code_idx %u --- \"system..macroes..view.get_bitmap_font_size.mac.macro.cpp\"", code_idx);
      return null;
  }
}

shared_ptr<Content> Macro_SystemMacroesViewGetbitmapfontsizeMac::execute (
    shared_ptr<Node> const& node,
    shared_ptr<Content> const& content,
    shared_ptr<Macro> const& macro
) {
  return execute(node, content, 2, macro);
}

shared_ptr<Format> const&  Macro_SystemMacroesViewGetbitmapfontsizeMac::_getFormat () {
  static shared_ptr<Format> format =
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
        static uint code_path_id = PathRegistry::lookUp("system/macroes/view.get_bitmap_font_size.mac");
        auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
        unlikely (code_set == null) {
          LOG_ERR("code_set is null --- system/macroes/view.get_bitmap_font_size.mac");
          return Var(false);
        }
        return code_set->execute(1, {Var(&ctx), Var(loadable), Var(node), Var(content)});
      }
    )
;
  return format;
}


}






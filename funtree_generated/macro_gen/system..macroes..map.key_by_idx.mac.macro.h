#ifndef AUTO_GENERATED_FUN_TREE_NODE_LOADER_MACRO_CODE_SYSTEM_MACROES_MAP_KEY_BY_IDX_MAC_MACRO_H_
#define AUTO_GENERATED_FUN_TREE_NODE_LOADER_MACRO_CODE_SYSTEM_MACROES_MAP_KEY_BY_IDX_MAC_MACRO_H_





#include <common/loader/fun_tree/_macro_loader.h>


namespace appetizer {


using std::shared_ptr;


class GAMECONTENT_API Macro_SystemMacroesMapKeybyidxMac : public fun_tree::MacroLoader {
public: // inner types
  using Content       = fun_tree::Content;
  using EmbodyFunc    = fun_tree::EmbodyFunc;
  using Format        = fun_tree::node_loader_format::Format;
  using Macro         = fun_tree::Macro;
  using Node          = fun_tree::Node;
  using NodeLoadable  = fun_tree::NodeLoadable;
  using LoaderContext = fun_tree::LoaderContext;


public: // methods
  string const& loadable_class () const override;

  bool isCompatibleLoadable (shared_ptr<NodeLoadable> const& loadable) override;

  bool preEmbody (
      shared_ptr<Node> const& node,
      shared_ptr<Content> const& call_params,
      EmbodyFunc embody_func
  ) override;
  

  shared_ptr<Content> execute (
      shared_ptr<Node> const& node,
      shared_ptr<Content> const& content,
      shared_ptr<Macro> const& macro
  ) override;

  shared_ptr<Content> execute (
      shared_ptr<Node> const& node,
      shared_ptr<Content> const& content,
      int code_idx,
      shared_ptr<Macro> const& macro
  );


private: // methods
  shared_ptr<Format> const&  _getFormat () override;

  bool _preLoad (
      LoaderContext& ctx,
      shared_ptr<Node> const& node,
      shared_ptr<NodeLoadable> const& loadable
  ) override;

  bool _postLoad (
      LoaderContext& ctx,
      shared_ptr<Node> const& node,
      shared_ptr<NodeLoadable> const& loadable
  ) override;
};


}





#endif  // ifndef AUTO_GENERATED_FUN_TREE_NODE_LOADER_MACRO_CODE_SYSTEM_MACROES_MAP_KEY_BY_IDX_MAC_MACRO_H_

#ifndef AUTO_GENERATED_FUN_TREE_NODE_LOADER_OBJECT_CODE_SYSTEM_NODE_LOADER_FORMAT_GRAPHICS_GPU_TASK_RESOLVE_ATTACHMENT_NLF_NODE_LOADER_H_
#define AUTO_GENERATED_FUN_TREE_NODE_LOADER_OBJECT_CODE_SYSTEM_NODE_LOADER_FORMAT_GRAPHICS_GPU_TASK_RESOLVE_ATTACHMENT_NLF_NODE_LOADER_H_


#ifndef SERVER_ONLY


#include <common/loader/fun_tree/_node_loader.h>


namespace appetizer {


using std::shared_ptr;


class GAMECONTENT_API NodeLoader_SystemNodeloaderformatGraphicsGputaskResolveattachmentNlf : public fun_tree::NodeLoader {
public: // inner types
  using Content       = fun_tree::Content;
  using Format        = fun_tree::node_loader_format::Format;
  using Node          = fun_tree::Node;
  using NodeLoadable  = fun_tree::NodeLoadable;
  using LoaderContext = fun_tree::LoaderContext;


public: // methods
  string const& loadable_class () const override;

  bool isCompatibleLoadable (shared_ptr<NodeLoadable> const& loadable) override;


private: // methods
  shared_ptr<fun_tree::node_loader_format::Format> const&  _getFormat () override;

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


#endif


#endif  // ifndef AUTO_GENERATED_FUN_TREE_NODE_LOADER_OBJECT_CODE_SYSTEM_NODE_LOADER_FORMAT_GRAPHICS_GPU_TASK_RESOLVE_ATTACHMENT_NLF_NODE_LOADER_H_

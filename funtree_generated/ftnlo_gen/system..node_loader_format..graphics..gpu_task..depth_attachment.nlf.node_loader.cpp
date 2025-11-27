#ifndef SERVER_ONLY

#include "./system..node_loader_format..graphics..gpu_task..depth_attachment.nlf.node_loader.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./system..node_loader_format..graphics..gpu_task..color_attachment.nlf.node_loader.0.code"






namespace appetizer {


using namespace fun_tree;
using namespace fun_tree::node_loader_format;

using std::make_shared;



__attribute__((constructor))
static void ___NodeLoaderBundleRegisterer___ () {

  NodeLoaderBundle::default_bundle().registerLoader(
      vector<string>{"DepthAttachment", },
      vector<string>{"AttachmentGroup", },
      make_shared<NodeLoader_SystemNodeloaderformatGraphicsGputaskDepthattachmentNlf>(),
      true
  );
}



string const& NodeLoader_SystemNodeloaderformatGraphicsGputaskDepthattachmentNlf::loadable_class () const {
  static string cls = "AttachmentInfo";
  return cls;
}


bool NodeLoader_SystemNodeloaderformatGraphicsGputaskDepthattachmentNlf::isCompatibleLoadable (shared_ptr<NodeLoadable> const& loadable) {
  return dpc<AttachmentInfo>(loadable) != null;
}


bool NodeLoader_SystemNodeloaderformatGraphicsGputaskDepthattachmentNlf::_preLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  auto super_ok = fun_tree::NodeLoader::_preLoad(ctx, node, loadable);
  if (super_ok == false)
    return false;

  static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/graphics/gpu_task/depth_attachment.nlf");
  auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
  unlikely (code_set == null) {
    LOG_ERR("code_set is null --- system/node_loader_format/graphics/gpu_task/depth_attachment.nlf");
    return null;
  }

  auto result = code_set->execute(0, {Var(&ctx), Var(node), Var(loadable)});
  return result.as<bool>();

}


bool NodeLoader_SystemNodeloaderformatGraphicsGputaskDepthattachmentNlf::_postLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  auto super_ok = fun_tree::NodeLoader::_postLoad(ctx, node, loadable);
  if (super_ok == false)
    return false;

  static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/graphics/gpu_task/color_attachment.nlf");
  auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
  unlikely (code_set == null) {
    LOG_ERR("code_set is null --- system/node_loader_format/graphics/gpu_task/color_attachment.nlf");
    return null;
  }

  auto result = code_set->execute(2, {Var(&ctx), Var(node), Var(loadable)});
  return result.as<bool>();

}


shared_ptr<Format> const&  NodeLoader_SystemNodeloaderformatGraphicsGputaskDepthattachmentNlf::_getFormat () {
  static shared_ptr<Format> format =
    make_shared<ObjectFormat>(
      vector<vector<AttributeLoader>>{
        vector<AttributeLoader>{
          AttributeLoader{
            "name",
            "nam",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/graphics/gpu_task/color_attachment.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/graphics/gpu_task/color_attachment.nlf");
                  return Var(false);
                }
                return code_set->execute(3, {Var(&ctx), Var(loadable), Var(node), Var(content)});
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/graphics/gpu_task/color_attachment.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/graphics/gpu_task/color_attachment.nlf");
                  return Var(false);
                }
                return code_set->execute(4, {Var(&ctx), Var(loadable), Var(node), Var(content)});
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/graphics/gpu_task/color_attachment.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/graphics/gpu_task/color_attachment.nlf");
                  return Var(false);
                }
                return code_set->execute(5, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "format",
            "fmt",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/graphics/gpu_task/color_attachment.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/graphics/gpu_task/color_attachment.nlf");
                  return Var(false);
                }
                return code_set->execute(6, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "sample_count",
            "sam",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/graphics/gpu_task/color_attachment.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/graphics/gpu_task/color_attachment.nlf");
                  return Var(false);
                }
                return code_set->execute(7, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "load_op",
            "lop",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/graphics/gpu_task/color_attachment.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/graphics/gpu_task/color_attachment.nlf");
                  return Var(false);
                }
                return code_set->execute(8, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "store_op",
            "sop",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/graphics/gpu_task/color_attachment.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/graphics/gpu_task/color_attachment.nlf");
                  return Var(false);
                }
                return code_set->execute(9, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "stencil_load_op",
            "slo",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/graphics/gpu_task/color_attachment.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/graphics/gpu_task/color_attachment.nlf");
                  return Var(false);
                }
                return code_set->execute(10, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "stencil_store_op",
            "sso",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/graphics/gpu_task/color_attachment.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/graphics/gpu_task/color_attachment.nlf");
                  return Var(false);
                }
                return code_set->execute(11, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "additional_usage_flags",
            "usf",
            vector<string>{ },
            false,
            vector<string>{ },
            make_shared<SequenceFormat>(
              0,
              -1,
              vector<shared_ptr<Format>>{
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
                    static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/graphics/gpu_task/color_attachment.nlf");
                    auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                    unlikely (code_set == null) {
                      LOG_ERR("code_set is null --- system/node_loader_format/graphics/gpu_task/color_attachment.nlf");
                      return Var(false);
                    }
                    return code_set->execute(12, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                  }
                ),
              }
            )
          },
          AttributeLoader{
            "additional_aspect_flags",
            "asf",
            vector<string>{ },
            false,
            vector<string>{ },
            make_shared<SequenceFormat>(
              0,
              -1,
              vector<shared_ptr<Format>>{
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
                    static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/graphics/gpu_task/color_attachment.nlf");
                    auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                    unlikely (code_set == null) {
                      LOG_ERR("code_set is null --- system/node_loader_format/graphics/gpu_task/color_attachment.nlf");
                      return Var(false);
                    }
                    return code_set->execute(13, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                  }
                ),
              }
            )
          },
          AttributeLoader{
            "color_clear_value",
            "ccv",
            vector<string>{ },
            false,
            vector<string>{ },
            make_shared<SequenceFormat>(
              4,
              4,
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
                    static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/graphics/gpu_task/color_attachment.nlf");
                    auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                    unlikely (code_set == null) {
                      LOG_ERR("code_set is null --- system/node_loader_format/graphics/gpu_task/color_attachment.nlf");
                      return Var(false);
                    }
                    return code_set->execute(14, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                  }
                ),
              }
            )
          },
          AttributeLoader{
            "depth_clear_value",
            "dcv",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/graphics/gpu_task/color_attachment.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/graphics/gpu_task/color_attachment.nlf");
                  return Var(false);
                }
                return code_set->execute(15, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "stencil_clear_value",
            "scv",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/graphics/gpu_task/color_attachment.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/graphics/gpu_task/color_attachment.nlf");
                  return Var(false);
                }
                return code_set->execute(16, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
        },
      }
    );
  return format;
}


}




#endif

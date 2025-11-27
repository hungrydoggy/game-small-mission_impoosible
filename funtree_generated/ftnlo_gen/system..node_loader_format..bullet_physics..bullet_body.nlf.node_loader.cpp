

#include "./system..node_loader_format..bullet_physics..bullet_body.nlf.node_loader.h"

#include <common/path_registry/path_registry.h>
#include <common/loader/fun_tree/fun_tree_format.h>
#include <common/loader/fun_tree/fun_tree.h>
#include <util/var.h>

#include "./system..node_loader_format..bullet_physics..bullet_body.nlf.node_loader.0.code"






namespace appetizer {


using namespace fun_tree;
using namespace fun_tree::node_loader_format;

using std::make_shared;



__attribute__((constructor))
static void ___NodeLoaderBundleRegisterer___ () {

  NodeLoaderBundle::default_bundle().registerLoader(
      vector<string>{"BulletBody", },
      vector<string>{"PhysicsBodyGroup", "ObjectTraitGroup", },
      make_shared<NodeLoader_SystemNodeloaderformatBulletphysicsBulletbodyNlf>(),
      true
  );
}



string const& NodeLoader_SystemNodeloaderformatBulletphysicsBulletbodyNlf::loadable_class () const {
  static string cls = "BulletBody";
  return cls;
}


bool NodeLoader_SystemNodeloaderformatBulletphysicsBulletbodyNlf::isCompatibleLoadable (shared_ptr<NodeLoadable> const& loadable) {
  return dpc<BulletBody>(loadable) != null;
}


bool NodeLoader_SystemNodeloaderformatBulletphysicsBulletbodyNlf::_preLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  auto super_ok = fun_tree::NodeLoader::_preLoad(ctx, node, loadable);
  if (super_ok == false)
    return false;

  return true;
}


bool NodeLoader_SystemNodeloaderformatBulletphysicsBulletbodyNlf::_postLoad (
    LoaderContext& ctx,
    shared_ptr<Node> const& node,
    shared_ptr<NodeLoadable> const& loadable
) {
  auto super_ok = fun_tree::NodeLoader::_postLoad(ctx, node, loadable);
  if (super_ok == false)
    return false;

  return true;
}


shared_ptr<Format> const&  NodeLoader_SystemNodeloaderformatBulletphysicsBulletbodyNlf::_getFormat () {
  static shared_ptr<Format> format =
    make_shared<ObjectFormat>(
      vector<vector<AttributeLoader>>{
        vector<AttributeLoader>{
          AttributeLoader{
            "mass",
            "mas",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/bullet_physics/bullet_body.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/bullet_physics/bullet_body.nlf");
                  return Var(false);
                }
                return code_set->execute(1, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "local_inertia",
            "ine",
            vector<string>{ },
            false,
            vector<string>{ },
            make_shared<SequenceFormat>(
              3,
              3,
              [](
                  FormatContext& ctx,
                  shared_ptr<NodeLoadable> const& loadable,
                  shared_ptr<Node> const& node,
                  shared_ptr<Content> const& content
              ) {
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/bullet_physics/bullet_body.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/bullet_physics/bullet_body.nlf");
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
                    static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/common/vector3.nlf");
                    auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                    unlikely (code_set == null) {
                      LOG_ERR("code_set is null --- system/node_loader_format/common/vector3.nlf");
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
                    static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/common/vector3.nlf");
                    auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                    unlikely (code_set == null) {
                      LOG_ERR("code_set is null --- system/node_loader_format/common/vector3.nlf");
                      return Var(false);
                    }
                    return code_set->execute(2, {Var(&ctx), Var(loadable), Var(node), Var(content)});
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
                    static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/common/vector3.nlf");
                    auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                    unlikely (code_set == null) {
                      LOG_ERR("code_set is null --- system/node_loader_format/common/vector3.nlf");
                      return Var(false);
                    }
                    return code_set->execute(3, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                  }
                ),
              }
            )
          },
          AttributeLoader{
            "linear_damping",
            "lid",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/bullet_physics/bullet_body.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/bullet_physics/bullet_body.nlf");
                  return Var(false);
                }
                return code_set->execute(3, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "angular_damping",
            "and",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/bullet_physics/bullet_body.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/bullet_physics/bullet_body.nlf");
                  return Var(false);
                }
                return code_set->execute(4, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "friction",
            "fri",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/bullet_physics/bullet_body.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/bullet_physics/bullet_body.nlf");
                  return Var(false);
                }
                return code_set->execute(5, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "rolling_friction",
            "rfr",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/bullet_physics/bullet_body.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/bullet_physics/bullet_body.nlf");
                  return Var(false);
                }
                return code_set->execute(6, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "restitution",
            "res",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/bullet_physics/bullet_body.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/bullet_physics/bullet_body.nlf");
                  return Var(false);
                }
                return code_set->execute(7, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "linear_sleeping_threshold",
            "lis",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/bullet_physics/bullet_body.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/bullet_physics/bullet_body.nlf");
                  return Var(false);
                }
                return code_set->execute(8, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "angular_sleeping_threshold",
            "ans",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/bullet_physics/bullet_body.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/bullet_physics/bullet_body.nlf");
                  return Var(false);
                }
                return code_set->execute(9, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "additional_damping",
            "add",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/bullet_physics/bullet_body.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/bullet_physics/bullet_body.nlf");
                  return Var(false);
                }
                return code_set->execute(10, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "additional_damping_factor",
            "adf",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/bullet_physics/bullet_body.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/bullet_physics/bullet_body.nlf");
                  return Var(false);
                }
                return code_set->execute(11, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "additional_linear_damping_threshold_sqr",
            "ald",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/bullet_physics/bullet_body.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/bullet_physics/bullet_body.nlf");
                  return Var(false);
                }
                return code_set->execute(12, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "additional_angular_damping_threshold_sqr",
            "aad",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/bullet_physics/bullet_body.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/bullet_physics/bullet_body.nlf");
                  return Var(false);
                }
                return code_set->execute(13, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "additional_angular_damping_factor",
            "aaf",
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
                static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/bullet_physics/bullet_body.nlf");
                auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                unlikely (code_set == null) {
                  LOG_ERR("code_set is null --- system/node_loader_format/bullet_physics/bullet_body.nlf");
                  return Var(false);
                }
                return code_set->execute(14, {Var(&ctx), Var(loadable), Var(node), Var(content)});
              }
            )
          },
          AttributeLoader{
            "collision_flags",
            "flg",
            vector<string>{ },
            false,
            vector<string>{ },
            make_shared<SequenceFormat>(
              -1,
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
                    static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/bullet_physics/bullet_body.nlf");
                    auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                    unlikely (code_set == null) {
                      LOG_ERR("code_set is null --- system/node_loader_format/bullet_physics/bullet_body.nlf");
                      return Var(false);
                    }
                    return code_set->execute(15, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                  }
                ),
              }
            )
          },
          AttributeLoader{
            "collision_group",
            "grp",
            vector<string>{ },
            false,
            vector<string>{ },
            make_shared<SequenceFormat>(
              -1,
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
                    static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/bullet_physics/bullet_body.nlf");
                    auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                    unlikely (code_set == null) {
                      LOG_ERR("code_set is null --- system/node_loader_format/bullet_physics/bullet_body.nlf");
                      return Var(false);
                    }
                    return code_set->execute(16, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                  }
                ),
              }
            )
          },
          AttributeLoader{
            "collision_mask",
            "msk",
            vector<string>{ },
            false,
            vector<string>{ },
            make_shared<SequenceFormat>(
              -1,
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
                    static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/bullet_physics/bullet_body.nlf");
                    auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                    unlikely (code_set == null) {
                      LOG_ERR("code_set is null --- system/node_loader_format/bullet_physics/bullet_body.nlf");
                      return Var(false);
                    }
                    return code_set->execute(17, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                  }
                ),
              }
            )
          },
          AttributeLoader{
            "joint_items",
            "jnt",
            vector<string>{ },
            false,
            vector<string>{ },
            make_shared<SequenceFormat>(
              -1,
              -1,
              vector<shared_ptr<Format>>{
                make_shared<ValueFormat>(
                  Content::Type::OBJECT,
                  0,
                  "PhysicsJointItem",
                  [](
                      FormatContext& ctx,
                      shared_ptr<NodeLoadable> const& loadable,
                      shared_ptr<Node> const& node,
                      shared_ptr<Content> const& content
                  ) {
                    static uint code_path_id = PathRegistry::lookUp("system/node_loader_format/bullet_physics/bullet_body.nlf");
                    auto code_set = CodeSetBundle::default_bundle().getCodeSet(code_path_id);
                    unlikely (code_set == null) {
                      LOG_ERR("code_set is null --- system/node_loader_format/bullet_physics/bullet_body.nlf");
                      return Var(false);
                    }
                    return code_set->execute(18, {Var(&ctx), Var(loadable), Var(node), Var(content)});
                  }
                ),
              }
            )
          },
        },
      }
    );
  return format;
}


}






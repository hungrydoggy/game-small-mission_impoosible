#ifndef AUTO_GENERATED_FUN_TREE_LAMBDA_SCENES_GAME_SCN_LAMBDA_H_
#define AUTO_GENERATED_FUN_TREE_LAMBDA_SCENES_GAME_SCN_LAMBDA_H_





#include <common/loader/fun_tree/_lambda_set.h>
#include <common/loader/fun_tree/node.h>
#include <appetizer.h>


namespace appetizer {


class GAMECONTENT_API Lambda_ScenesGameScn : public fun_tree::LambdaSet {
public:  // methods
  Var execute (
      shared_ptr<fun_tree::Node> const& node,
      int code_idx,
      shared_ptr<fun_tree::Content> const& content
  ) override;

};


}





#endif  // ifndef AUTO_GENERATED_FUN_TREE_LAMBDA_SCENES_GAME_SCN_LAMBDA_H_

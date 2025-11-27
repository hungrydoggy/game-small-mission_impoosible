#ifndef SYSTEM_DEBUG_DRAW_DEBUG_DRAW_SCENE_H_
#define SYSTEM_DEBUG_DRAW_DEBUG_DRAW_SCENE_H_

#include <appetizer.h>

using namespace appetizer;


class GAMECONTENT_API DebugDrawScene : public Scene {
public: // inner types
  using super = Scene;


public: // methods
  virtual bool onPostLoad (fun_tree::LoaderContext& ctx, shared_ptr<fun_tree::Node> const& node) override;


};


#endif  // ifndef SYSTEM_DEBUG_DRAW_DEBUG_DRAW_SCENE_H_

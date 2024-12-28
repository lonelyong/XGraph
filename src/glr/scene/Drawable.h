#pragma once

#include <glr/glrenderer_global.h>

#include <glr/scene/SceneNode.h>

namespace glr {
class State;
class GLR_API Drawable : public SceneNode {
    VI_OBJECT_META;

  public:
    virtual void draw(State& ctx) = 0;
};
} // namespace glr
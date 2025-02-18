#pragma once

#include <glr/glrenderer_global.h>

#include <glr/scene/Node.h>

namespace glr {
class State;
class GLR_API Drawable : public Node {
    VI_OBJECT_META;

  public:
    virtual void draw(State& ctx) = 0;
};
} // namespace glr
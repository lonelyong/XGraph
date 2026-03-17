#pragma once

#include <glr/glr_global.h>

#include <glr/scene/Node.h>

namespace glr {
class State;
class GLR_API Drawable : public Node {
    V_OBJECT_META_DECL

  public:
    virtual void draw(State& ctx) = 0;
};
} // namespace glr
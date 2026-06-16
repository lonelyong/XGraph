#pragma once

#include <xg/glr/glr_global.hpp>

#include <xg/glr/scene/Node.h>

namespace xg {
namespace glr {
class State;
class GLR_API Drawable : public Node {
    V_OBJECT_META_DECL

  public:
    virtual void draw(State& ctx) = 0;
};
} // namespace glr
} // namespace xg
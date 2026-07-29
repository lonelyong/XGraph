#pragma once

#include <xg/igl/glr_global.hpp>

#include <xg/igl/scene/Node.hpp>

namespace xg
{
namespace glr
{

class State;

class IGL_CORE_API Drawable : public Node {
    V_OBJECT_META_DECL

  public:
    virtual void draw(State& ctx) = 0;
};

} // namespace glr
} // namespace xg
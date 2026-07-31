#include <xg/igl/engine/PolygonMode.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(PolygonMode, StateAttribute);

PolygonMode::PolygonMode() = default;

PolygonMode::PolygonMode(Mode mode)
{ setMode(mode); }

PolygonMode::~PolygonMode() = default;

void PolygonMode::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglPolygonMode(IGL_FRONT_AND_BACK, mode_);
}

} // namespace glr
} // namespace xg
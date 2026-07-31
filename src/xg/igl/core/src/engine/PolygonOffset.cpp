#include <xg/igl/engine/PolygonOffset.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(PolygonOffset, StateAttribute);

PolygonOffset::PolygonOffset() = default;

PolygonOffset::PolygonOffset(GLfloat_t factor, GLfloat_t units)
{
    setFactor(factor);
    setUnits(units);
}

PolygonOffset::~PolygonOffset() = default;

void PolygonOffset::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglPolygonOffset(factor_, units_);
}

} // namespace glr
} // namespace xg
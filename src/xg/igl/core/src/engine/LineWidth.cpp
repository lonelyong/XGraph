#include <xg/igl/engine/LineWidth.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(LineWidth, StateAttribute);

struct LineWidth::Data {};

LineWidth::LineWidth()
  : d(new Data())
{}

LineWidth::~LineWidth()
{}

LineWidth::Type LineWidth::getType() const
{ return LINE_WIDTH; }

void LineWidth::apply(State& state) const
{ auto funcs = state.getContext()->getFuncs(); }

} // namespace glr
} // namespace xg
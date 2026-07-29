#include <xg/igl/engine/PolygonMode.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(PolygonMode, StateAttribute);

struct PolygonMode::Data {
    Mode mode = FILL;
};

PolygonMode::PolygonMode()
  : d(new Data())
{}

PolygonMode::PolygonMode(Mode mode)
  : d(new Data())
{ setMode(mode); }

PolygonMode::~PolygonMode()
{ delete d; }

PolygonMode::Type PolygonMode::getType() const
{ return POLYGON_MODE; }

PolygonMode::Mode PolygonMode::getMode() const
{ return d->mode; }

void PolygonMode::setMode(Mode mode)
{ d->mode = mode; }

void PolygonMode::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglPolygonMode(IGL_FRONT_AND_BACK, d->mode);
}

} // namespace glr
} // namespace xg
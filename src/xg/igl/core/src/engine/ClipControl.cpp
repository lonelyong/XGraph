#include <xg/igl/engine/ClipControl.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(ClipControl, StateAttribute);

struct ClipControl::Data {
    Origin origin = LOWER_LEFT;
    Depth  depth  = NEGATIVE_ONE_TO_ONE;
};

ClipControl::ClipControl()
  : d(new Data())
{}

ClipControl::~ClipControl()
{ delete d; }

ClipControl::Type ClipControl::getType() const
{ return CLIP_CONTROL; }

void ClipControl::setOrigin(Origin origin)
{ d->origin = origin; }

ClipControl::Origin ClipControl::getOrigin() const
{ return d->origin; }

void ClipControl::setDepth(Depth depth)
{ d->depth = depth; }

ClipControl::Depth ClipControl::getDepth() const
{ return d->depth; }

void ClipControl::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglClipControl(d->origin, d->depth);
}

} // namespace glr
} // namespace xg
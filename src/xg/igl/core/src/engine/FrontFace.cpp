#include <xg/igl/engine/FrontFace.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(FrontFace, StateAttribute);

struct FrontFace::Data {
    Mode mode = CCW;
};

FrontFace::FrontFace()
  : d(new Data())
{}

FrontFace::FrontFace(Mode mode)
  : d(new Data())
{ setMode(mode); }

FrontFace::~FrontFace()
{ delete d; }

FrontFace::Mode FrontFace::getMode() const
{ return d->mode; }

void FrontFace::setMode(Mode mode)
{ d->mode = mode; }

FrontFace::Type FrontFace::getType() const
{ return FRONT_FACE; }

void FrontFace::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglFrontFace(d->mode);
}

} // namespace glr
} // namespace xg
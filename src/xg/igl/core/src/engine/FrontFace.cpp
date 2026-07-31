#include <xg/igl/engine/FrontFace.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(FrontFace, StateAttribute);

FrontFace::FrontFace() = default;

FrontFace::FrontFace(Mode mode)
{ setMode(mode); }

FrontFace::~FrontFace() = default;

void FrontFace::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglFrontFace(mode_);
}

} // namespace glr
} // namespace xg
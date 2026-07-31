#include <xg/igl/engine/CullFace.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(CullFace, StateAttribute);

CullFace::CullFace() = default;

CullFace::CullFace(Mode mode)
{ setMode(mode); }

CullFace::~CullFace() = default;

void CullFace::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglCullFace(mode_);
}

} // namespace glr
} // namespace xg
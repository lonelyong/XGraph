#include <xg/igl/engine/Stencil.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

V_OBJECT_META_IMPL(xg::glr::Stencil, xg::glr::StateAttribute)

namespace xg
{
namespace glr
{

Stencil::Stencil() = default;

Stencil::~Stencil() = default;

bool Stencil::equals(const StateAttribute& other) const
{
    if (other.isKindOf(Stencil::desc())) {}
    return false;
}

void Stencil::setFunction(Func fn, GLint_t ref, GLuint_t mask)
{
    fn_      = fn;
    fn_ref_  = ref;
    fn_mask_ = mask;
}

void Stencil::setOperation(Operation sfail, Operation zfail, Operation zpass)
{
    op_sfail_ = sfail;
    op_zfail_ = zfail;
    op_zpass_ = zpass;
}

void Stencil::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglStencilFunc((GLenum_t)fn_, fn_ref_, fn_mask_);
    funcs->oglStencilOp((GLenum_t)op_sfail_, (GLenum_t)op_zfail_, (GLenum_t)op_zpass_);
    funcs->oglStencilMask(write_mask_);
}

} // namespace glr
} // namespace xg
#include <glr/engine/Stencil.h>

#include <glr/engine/GraphicContext.h>
#include <glr/engine/State.h>
#include <glr/igl/GLfuncs.h>

VI_OBJECT_META_IMPL(glr::Stencil, glr::StateAttribute)

namespace glr {
struct Stencil::Data {
    Func     fn      = ALWAYS;
    GLint_t  fn_ref  = 0;
    GLuint_t fn_mask = ~0u;

    Operation op_sfail = KEEP;
    Operation op_zfail = KEEP;
    Operation op_zpass = KEEP;

    GLuint_t write_mask = ~0u;
};

Stencil::Stencil()
  : d(new Data()) {
}

Stencil::~Stencil() {
    delete d;
}

StateAttribute::Type Stencil::getType() const {
    return STENCIL;
}

bool Stencil::equals(const StateAttribute& other) const {
    if (other.isKindOf(Stencil::desc())) {
    }
    return false;
}

void Stencil::setFunction(Func fn, GLint_t ref, GLuint_t mask) {
    d->fn      = fn;
    d->fn_ref  = ref;
    d->fn_mask = mask;
}

void Stencil::setOperation(Operation sfail, Operation zfail, Operation zpass) {
    d->op_sfail = sfail;
    d->op_zfail = zfail;
    d->op_zpass = zpass;
}

inline void Stencil::setWriteMask(GLuint_t mask) {
    d->write_mask = mask;
}

inline GLuint_t Stencil::getWriteMask() const {
    return d->write_mask;
}

void Stencil::apply(State& state) const {
    auto funcs = state.getContext()->getFuncs();
    funcs->iglStencilFunc((GLenum_t)d->fn, d->fn_ref, d->fn_mask);
    funcs->iglStencilOp((GLenum_t)d->op_sfail, (GLenum_t)d->op_zfail, (GLenum_t)d->op_zpass);
    funcs->iglStencilMask(d->write_mask);
}
} // namespace glr
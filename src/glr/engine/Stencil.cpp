#include <glr/engine/Stencil.h>

#include <glad/glad.h>

VI_OBJECT_META_IMPL(glr::Stencil, glr::StateAttribute)

namespace glr {
struct Stencil::Data {
    Func fn = FN_ALWAYS;
    int  fn_ref = 0;
    unsigned int fn_mask = ~0u;

    Operation op_sfail = OP_KEEP;
    Operation op_zfail = OP_KEEP;
    Operation op_zpass = OP_KEEP;

    unsigned int write_mask = ~0u;
};

Stencil::Stencil()
  : d(new Data()) {
}

Stencil::~Stencil() {
    delete d;
}

StateAttribute::Type Stencil::getType() const {
    return ATTR_STENCIL;
}

bool Stencil::equals(const StateAttribute& other) const {
    if (other.isKindOf(Stencil::desc())) {
    }
    return false;
}

void Stencil::setFunction(Func fn, int ref, unsigned int mask) {
    d->fn = fn;
    d->fn_ref = ref;
    d->fn_mask = mask;
}

void Stencil::setOperation(Operation sfail, Operation zfail, Operation zpass) {
    d->op_sfail = sfail;
    d->op_zfail = zfail;
    d->op_zpass = zpass;
}

inline void Stencil::setWriteMask(unsigned int mask) {
    d->write_mask = mask;
}

inline unsigned int Stencil::getWriteMask() const {
    return d->write_mask;
}

void Stencil::apply(State& state) const {
    glStencilFunc((GLenum)d->fn, d->fn_ref, d->fn_mask);
    glStencilOp((GLenum)d->op_sfail, (GLenum)d->op_zfail, (GLenum)d->op_zpass);
    glStencilMask(d->write_mask);
}
} // namespace glr
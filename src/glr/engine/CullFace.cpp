#include <glr/engine/CullFace.h>

#include <glr/engine/GraphicContext.h>
#include <glr/engine/State.h>
#include <glr/igl/GLfuncs.h>

namespace glr {

V_OBJECT_META_IMPL(CullFace, StateAttribute);

struct CullFace::Data {
    Mode mode = BACK;
};

CullFace::CullFace()
  : d(new Data()) {
}

CullFace::CullFace(Mode mode)
  : d(new Data()) {
    setMode(mode);
}

CullFace::~CullFace() {
    delete d;
}

CullFace::Mode CullFace::getMode() const {
    return d->mode;
}

void CullFace::setMode(Mode mode) {
    d->mode = mode;
}

CullFace::Type CullFace::getType() const {
    return CULL_FACE;
}

void CullFace::apply(State& state) const {
    auto funcs = state.getContext()->getFuncs();
    funcs->iglCullFace(d->mode);
}

} // namespace glr
#include <glr/engine/CullFace.h>

#include <glad/glad.h>


namespace glr {

VI_OBJECT_META_IMPL(CullFace, StateAttribute);

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
    glCullFace(d->mode);
}

} // namespace glr
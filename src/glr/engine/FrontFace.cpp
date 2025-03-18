#include <glr/engine/FrontFace.h>

#include <glad/glad.h>


namespace glr {

VI_OBJECT_META_IMPL(FrontFace, StateAttribute);

struct FrontFace::Data {
    Mode mode = CCW;
};

FrontFace::FrontFace()
  : d(new Data()) {
}

FrontFace::FrontFace(Mode mode)
  : d(new Data()) {
    setMode(mode);
}

FrontFace::~FrontFace() {
    delete d;
}

FrontFace::Mode FrontFace::getMode() const {
    return d->mode;
}

void FrontFace::setMode(Mode mode) {
    d->mode = mode;
}

FrontFace::Type FrontFace::getType() const {
    return FRONT_FACE;
}

void FrontFace::apply(State& state) const {
    glFrontFace(d->mode);
}

} // namespace glr
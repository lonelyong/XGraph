#include <glr/engine/BlendEquation.h>

#include <glad/glad.h>

namespace glr {

VI_OBJECT_META_IMPL(BlendEquation, StateAttribute);

struct BlendEquation::Data {
    Mode mode = FUNC_ADD;
};

BlendEquation::BlendEquation()
  : d(new Data()) {
}

BlendEquation::BlendEquation(Mode mode)
  : d(new Data()) {
    d->mode = mode;
}

BlendEquation::~BlendEquation() {
    delete d;
}

BlendEquation::Type BlendEquation::getType() const {
    return BLEND_EQUATION;
}

void BlendEquation::setMode(Mode mode) {
    d->mode = mode;
}

BlendEquation::Mode BlendEquation::getMode() const {
    return d->mode;
}

void BlendEquation::apply(State& state) const {
    glBlendEquation(d->mode);
}

VI_OBJECT_META_IMPL(BlendEquation, StateAttribute);

struct BlendEquationi::Data {
    GLuint_t index = 0;
};

BlendEquationi::BlendEquationi()
  : d(new Data()) {
}

BlendEquationi::BlendEquationi(GLuint_t buf, Mode mode)
  : BlendEquation(mode)
  , d(new Data()) {
    d->index = buf;
}

BlendEquationi::~BlendEquationi() {
    delete d;
}

BlendEquationi::Type BlendEquationi::getType() const {
    return BLEND_EQUATIONI;
}

void BlendEquationi::setIndex(GLuint_t index) {
    d->index = index;
}

GLuint_t BlendEquationi::getIndex() const {
    return d->index;
}

void BlendEquationi::apply(State& state) const {
    glBlendEquationi(d->index, getMode());
}

} // namespace glr
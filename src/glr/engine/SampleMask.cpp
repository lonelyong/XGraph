#include <glr/engine/SampleMask.h>

#include <glad/glad.h>

namespace glr {

VI_OBJECT_META_IMPL(SampleMask, StateAttribute);

struct SampleMask::Data {
    GLuint_t     number = 0;
    GLbitfield_t mask   = 1;
};

SampleMask::SampleMask()
  : d(new Data()) {
}

SampleMask::SampleMask(GLuint_t mask_number, GLbitfield mask)
  : d(new Data()) {
    setNumber(mask_number);
    setMask(mask);
}

SampleMask::~SampleMask() {
    delete d;
}

GLuint_t SampleMask::getNumber() const {
    return d->number;
}

void SampleMask::setNumber(GLuint_t val) {
    d->number = val;
}


GLbitfield_t SampleMask::getMask() const {
    return d->mask;
}

void SampleMask::setMask(GLbitfield_t val) {
    d->mask = val;
}

SampleMask::Type SampleMask::getType() const {
    return SAMPLE_MASK;
}

void SampleMask::apply(State& state) const {
    glSampleMaski(d->number, d->mask);
}

} // namespace glr
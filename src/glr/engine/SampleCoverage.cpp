#include <glr/engine/SampleCoverage.h>

#include <glr/engine/GraphicContext.h>
#include <glr/engine/State.h>
#include <glr/igl/GLfuncs.h>

namespace glr {

VI_OBJECT_META_IMPL(SampleCoverage, StateAttribute);

struct SampleCoverage::Data {
    GLfloat_t   value  = 0.f;
    GLboolean_t invert = 0.f;
};

SampleCoverage::SampleCoverage()
  : d(new Data()) {
}

SampleCoverage::SampleCoverage(GLfloat_t value, GLboolean_t invert)
  : d(new Data()) {
    setValue(value);
    setInvert(invert);
}

SampleCoverage::~SampleCoverage() {
    delete d;
}

GLfloat_t SampleCoverage::getValue() const {
    return d->value;
}

void SampleCoverage::setValue(GLfloat_t val) {
    d->value = val;
}

GLboolean_t SampleCoverage::getInvert() const {
    return d->invert;
}

void SampleCoverage::setInvert(GLboolean_t val) {
    d->invert = val;
}

SampleCoverage::Type SampleCoverage::getType() const {
    return SAMPLE_COVERAGE;
}

void SampleCoverage::apply(State& state) const {
    auto funcs = state.getContext()->getFuncs();
    funcs->iglSampleCoverage(d->value, d->invert);
}

} // namespace glr
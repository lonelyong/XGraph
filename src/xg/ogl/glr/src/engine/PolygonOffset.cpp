#include <xg/glr/engine/PolygonOffset.h>

#include <xg/glr/engine/GraphicContext.h>
#include <xg/glr/engine/State.h>
#include <xg/glr/igl/GLfuncs.h>

namespace glr {

V_OBJECT_META_IMPL(PolygonOffset, StateAttribute);

struct PolygonOffset::Data {
    GLfloat_t factor = 0.f;
    GLfloat_t units  = 0.f;
};

PolygonOffset::PolygonOffset()
  : d(new Data()) {
}

PolygonOffset::PolygonOffset(GLfloat_t factor, GLfloat_t units)
  : d(new Data()) {
    setFactor(factor);
    setUnits(units);
}

PolygonOffset::~PolygonOffset() {
    delete d;
}

GLfloat_t PolygonOffset::getFactor() const {
    return d->factor;
}

void PolygonOffset::setFactor(GLfloat_t val) {
    d->factor = val;
}

GLfloat_t PolygonOffset::getUnits() const {
    return d->units;
}

void PolygonOffset::setUnits(GLfloat_t val) {
    d->units = val;
}

PolygonOffset::Type PolygonOffset::getType() const {
    return POLYGON_OFFSET;
}

void PolygonOffset::apply(State& state) const {
    auto funcs = state.getContext()->getFuncs();
    funcs->iglPolygonMode(d->factor, d->units);
}

} // namespace glr
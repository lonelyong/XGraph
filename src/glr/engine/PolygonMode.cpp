#include <glr/engine/PolygonMode.h>

#include <glad/glad.h>

namespace glr {

VI_OBJECT_META_IMPL(PolygonMode, StateAttribute);

struct PolygonMode::Data {
    Mode mode = FILL;
};

PolygonMode::PolygonMode()
  : d(new Data()) {
}

PolygonMode::PolygonMode(Mode mode)
  : d(new Data()) {
    setMode(mode);
}

PolygonMode::~PolygonMode() {
    delete d;
}

PolygonMode::Type PolygonMode::getType() const {
    return POLYGON_MODE;
}

PolygonMode::Mode PolygonMode::getMode() const {
    return d->mode;
}

void PolygonMode::setMode(Mode mode) {
    d->mode = mode;
}

void PolygonMode::apply(State& state) const {
    glPolygonMode(HGL_FRONT_AND_BACK, d->mode);
}

} // namespace glr
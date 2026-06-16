#include <xg/glr/engine/PolygonMode.h>

#include <xg/glr/engine/GraphicContext.h>
#include <xg/glr/engine/State.h>
#include <xg/glr/igl/GLfuncs.h>

namespace xg {
namespace glr {

V_OBJECT_META_IMPL(PolygonMode, StateAttribute);

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
    auto funcs = state.getContext()->getFuncs();
    funcs->iglPolygonMode(IGL_FRONT_AND_BACK, d->mode);
}

} // namespace glr
} // namespace xg
#include <xg/glr/engine/ClampColor.h>

#include <xg/glr/engine/GraphicContext.h>
#include <xg/glr/engine/State.h>
#include <xg/glr/igl/GLfuncs.h>

namespace glr {

V_OBJECT_META_IMPL(ClampColor, StateAttribute);

struct ClampColor::Data {};

ClampColor::ClampColor()
  : d(new Data()) {
}

ClampColor::~ClampColor() {
}

ClampColor::Type ClampColor::getType() const {
    return CLAMP_COLOR;
}

void ClampColor::apply(State& state) const {
    auto funcs = state.getContext()->getFuncs();
}

} // namespace glr
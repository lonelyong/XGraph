#include <glr/engine/LineWidth.h>

#include <glr/engine/GraphicContext.h>
#include <glr/engine/State.h>
#include <glr/igl/GLfuncs.h>

namespace glr {

V_OBJECT_META_IMPL(LineWidth, StateAttribute);

struct LineWidth::Data {};

LineWidth::LineWidth()
  : d(new Data()) {
}

LineWidth::~LineWidth() {
}

LineWidth::Type LineWidth::getType() const {
    return LINE_WIDTH;
}

void LineWidth::apply(State& state) const {
    auto funcs = state.getContext()->getFuncs();
}

} // namespace glr
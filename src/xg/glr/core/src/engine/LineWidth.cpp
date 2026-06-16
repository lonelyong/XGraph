#include <xg/glr/engine/LineWidth.hpp>

#include <xg/glr/engine/GraphicContext.hpp>
#include <xg/glr/engine/State.hpp>
#include <xg/glr/igl/GLfuncs.hpp>

namespace xg {
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
} // namespace xg
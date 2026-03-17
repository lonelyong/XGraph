#include <glr/engine/BlendColor.h>

#include <glr/engine/GraphicContext.h>
#include <glr/engine/State.h>
#include <glr/igl/GLfuncs.h>

namespace glr {

V_OBJECT_META_IMPL(BlendColor, StateAttribute);

struct BlendColor::Data {
    Vec4f color;
};

BlendColor::BlendColor()
  : d(new Data()) {
}

BlendColor::~BlendColor() {
    delete d;
}

BlendColor::Type BlendColor::getType() const {
    return CLAMP_COLOR;
}

void BlendColor::setColor(const Vec4f& color) {
    d->color = color;
}

Vec4f BlendColor::getColor() const {
    return d->color;
}

void BlendColor::apply(State& state) const {
    auto funcs = state.getContext()->getFuncs();
    funcs->iglBlendColor(d->color.r, d->color.g, d->color.b, d->color.a);
}

} // namespace glr
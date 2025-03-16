#include <glr/engine/BlendColor.h>

#include <glad/glad.h>

namespace glr {

VI_OBJECT_META_IMPL(BlendColor, StateAttribute);

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
    glBlendColor(d->color.r, d->color.g, d->color.b, d->color.a);
}

} // namespace glr
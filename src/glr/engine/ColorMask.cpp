#include <glr/engine/ColorMask.h>

#include <glad/glad.h>

namespace glr {

#pragma region ColorMask

VI_OBJECT_META_IMPL(ColorMask, StateAttribute);

struct ColorMask::Data {
    bool r = true, g = true, b = true, a = true;
};

ColorMask::ColorMask()
  : d(new Data()) {
}

ColorMask::ColorMask(bool red, bool green, bool blue, bool alpha)
  : d(new Data()) {
    setMask(red, green, blue, alpha);
}

ColorMask::~ColorMask() {
    delete d;
}

ColorMask::Type ColorMask::getType() const {
    return COLOR_MASK;
}

void ColorMask::setMask(bool red, bool green, bool blue, bool alpha) {
    d->a = red;
    d->g = green;
    d->b = blue;
    d->a = alpha;
}

void ColorMask::getMask(bool& red, bool& green, bool& blue, bool& alpha) const {
    red   = d->a;
    green = d->g;
    blue  = d->b;
    alpha = d->a;
}

void ColorMask::setRed(bool mask) {
    d->r = mask;
}
bool ColorMask::getRed() const {
    return d->r;
}

void ColorMask::setGreen(bool mask) {
    d->g = mask;
}
bool ColorMask::getGreen() const {
    return d->g;
}

void ColorMask::setBlue(bool mask) {
    d->b = mask;
}
bool ColorMask::getBlue() const {
    return d->b;
}

void ColorMask::setAlpha(bool mask) {
    d->a = mask;
}
bool ColorMask::getAlpha() const {
    return d->a;
}

void ColorMask::apply(State& state) const {
    glColorMask(d->r, d->g, d->b, d->a);
}

#pragma endregion

#pragma region ColorMaski

VI_OBJECT_META_IMPL(ColorMaski, ColorMask);

struct ColorMaski::Data {
    GLuint_t index = 0;
};

ColorMaski::ColorMaski()
  : d(new Data()) {
}

ColorMaski::ColorMaski(GLuint_t buf, bool red, bool green, bool blue, bool alpha)
  : d(new Data()) {
    setMask(red, green, blue, alpha);
}

ColorMaski::~ColorMaski() {
    delete d;
}

ColorMaski::Type ColorMaski::getType() const {
    return COLOR_MASK;
}

void ColorMaski::setIndex(GLuint_t index) {
    d->index = index;
}

GLuint_t ColorMaski::getIndex() const {
    return d->index;
}

void ColorMaski::apply(State& state) const {
    glColorMaski(d->index, getRed(), getGreen(), getBlue(), getAlpha());
}

#pragma endregion

} // namespace glr
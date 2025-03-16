#include <glr/engine/BlendFunc.h>

#include <glad/glad.h>

namespace glr {

VI_OBJECT_META_IMPL(BlendFunc, StateAttribute);

struct BlendFunc::Data {
    Func source_rgb   = SRC_ALPHA;
    Func source_alpha = SRC_ALPHA;
    Func dest_rgb     = ONE_MINUS_SRC_ALPHA;
    Func dest_alpha   = ONE_MINUS_SRC_ALPHA;
};

BlendFunc::BlendFunc()
  : d(new Data()) {
}

BlendFunc::~BlendFunc() {
    delete d;
}

BlendFunc::Type BlendFunc::getType() const {
    return BLEND_FUNC;
}

void BlendFunc::setSource(Func func) const {
    d->source_rgb   = func;
    d->source_alpha = func;
}

BlendFunc::Func BlendFunc::getSource() const {
    return d->source_rgb;
}

void BlendFunc::setSourceRGB(Func func) const {
    d->source_rgb = func;
}

BlendFunc::Func BlendFunc::getSourceRGB() const {
    return d->source_rgb;
}

void BlendFunc::setSourceAlpha(Func func) const {
    d->source_alpha = func;
}

BlendFunc::Func BlendFunc::getSourceAlpha() const {
    return d->source_alpha;
}

void BlendFunc::setDestination(Func func) const {
    d->dest_rgb   = func;
    d->dest_alpha = func;
}

BlendFunc::Func BlendFunc::getDestination() const {
    return d->dest_rgb;
}

void BlendFunc::setDestinationRGB(Func func) const {
    d->dest_rgb = func;
}

BlendFunc::Func BlendFunc::getDestinationRGB() const {
    return d->dest_rgb;
}

void BlendFunc::setDestinationAlpha(Func func) const {
    d->dest_alpha = func;
}

BlendFunc::Func BlendFunc::getDestinationAlpha() const {
    return d->source_alpha;
}

void BlendFunc::apply(State& state) const {
    if (d->source_alpha != d->source_rgb || d->dest_alpha != d->dest_rgb) {
        glBlendFuncSeparate(d->source_rgb, d->dest_rgb, d->source_alpha, d->dest_alpha);
    }
    glBlendFunc(d->source_rgb, d->dest_rgb);
}

} // namespace glr
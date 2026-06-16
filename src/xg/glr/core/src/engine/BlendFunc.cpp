#include <xg/glr/engine/BlendFunc.hpp>

#include <xg/glr/engine/GraphicContext.hpp>
#include <xg/glr/engine/State.hpp>
#include <xg/glr/igl/GLfuncs.hpp>

namespace xg {
namespace glr {
#pragma region BlendFunc

V_OBJECT_META_IMPL(BlendFunc, StateAttribute);

struct BlendFunc::Data {
    Func source_rgb   = SRC_ALPHA;
    Func source_alpha = SRC_ALPHA;
    Func dest_rgb     = ONE_MINUS_SRC_ALPHA;
    Func dest_alpha   = ONE_MINUS_SRC_ALPHA;
};

BlendFunc::BlendFunc()
  : d(new Data()) {
}

BlendFunc::BlendFunc(Func source, Func dest)
  : d(new Data()) {
    setSource(source);
    setDestination(dest);
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

void BlendFunc::apply(State& state) const {     auto funcs = state.getContext()->getFuncs();
    if (d->source_alpha != d->source_rgb || d->dest_alpha != d->dest_rgb) {
        funcs->iglBlendFuncSeparate(d->source_rgb, d->dest_rgb, d->source_alpha, d->dest_alpha);
    }
    funcs->iglBlendFunc(d->source_rgb, d->dest_rgb);
}

#pragma endregion

#pragma region BlendFunci

V_OBJECT_META_IMPL(BlendFunci, BlendFunc);

struct BlendFunci::Data {
    GLuint_t index = 0;
};

BlendFunci::BlendFunci()
  : d(new Data()) {
}

BlendFunci::BlendFunci(GLuint_t buf, Func source, Func dest)
  : BlendFunc(source, dest)
  , d(new Data()) {
    d->index = buf;
}

BlendFunci::~BlendFunci() {
    delete d;
}

BlendFunci::Type BlendFunci::getType() const {
    return BLEND_FUNC;
}

GLuint_t BlendFunci::getIndex() const {
    return d->index;
}

void BlendFunci::setIndex(GLuint_t index) {
    d->index = index;
}

void BlendFunci::apply(State& state) const {     auto funcs = state.getContext()->getFuncs();
    auto source_alpha = getSourceAlpha();
    auto source_rgb   = getSourceRGB();
    auto dest_alpha   = getDestinationAlpha();
    auto dest_rgb     = getDestinationRGB();

    if (source_alpha != source_rgb || dest_alpha != dest_rgb) {
        funcs->iglBlendFuncSeparatei(d->index, source_rgb, dest_rgb, source_alpha, dest_alpha);
    }
    funcs->iglBlendFunci(d->index, source_rgb, dest_rgb);
}
#pragma endregion
} // namespace glr
} // namespace xg
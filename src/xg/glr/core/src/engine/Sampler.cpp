#include <xg/glr/engine/Sampler.hpp>
#include <vector>

#include <xg/glr/engine/GraphicContext.hpp>
#include <xg/glr/engine/State.hpp>
#include <xg/glr/igl/GLfuncs.hpp>

namespace xg {
namespace glr {

#pragma region Sampler
V_OBJECT_META_IMPL(Sampler, StateAttribute);

struct Sampler::Data {
    Texture::WrapMode wrap_s = Texture::WRAP_UNSET;
    Texture::WrapMode wrap_r = Texture::WRAP_UNSET;
    Texture::WrapMode wrap_t = Texture::WRAP_UNSET;

    Texture::FilterMode min_filter = Texture::FILTER_UNSET;
    Texture::FilterMode mag_filter = Texture::FILTER_UNSET;

};

Sampler::Sampler()
  : d(new Data()) {
}

Sampler::~Sampler() {
    delete d;
}

Sampler::Type Sampler::getType() const {
    return SAMPLER;
}

void Sampler::setWrap(Texture::WrapParameter which, Texture::WrapMode wrap) {
}

Texture::WrapMode Sampler::getWrap(Texture::WrapParameter which) const {
    return Texture::WrapMode();
}

void Sampler::setFilter(Texture::FilterParameter which, Texture::FilterMode filter) {
}

Texture::FilterMode Sampler::getFilter(Texture::FilterParameter which) const {
    return Texture::FilterMode();
}

void Sampler::setBorderColor(const Vec4d& color) {
}

const Vec4d& Sampler::getBorderColor() const {
    static Vec4d c;
    return c;
}

void Sampler::setMaxAnisotropy(float anis) {
}

inline float Sampler::getMaxAnisotropy() const {
    return 0.0f;
}

void Sampler::setMinLOD(float anis) {
}

inline float Sampler::getMinLOD() const {
    return 0.0f;
}

void Sampler::setMaxLOD(float anis) {
}

inline float Sampler::getMaxLOD() const {
    return 0.0f;
}

void Sampler::setLODBias(float anis) {
}

inline float Sampler::getLODBias() const {
    return 0.0f;
}

void Sampler::apply(State& state) const {
    auto funcs = state.getContext()->getFuncs();
}

#pragma endregion

} // namespace glr
} // namespace xg
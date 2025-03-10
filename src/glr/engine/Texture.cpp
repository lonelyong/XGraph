
#include <glr/engine/GraphicContext.h>
#include <glr/engine/State.h>
#include <glr/engine/Texture.h>

#include <unordered_set>

namespace glr {
VI_OBJECT_META_IMPL(Texture, PixelData);

struct Texture::Data {
    WrapMode wrap_s = CLAMP_TO_EDGE;
    WrapMode wrap_t = CLAMP_TO_EDGE;
    WrapMode wrap_r = CLAMP_TO_EDGE;

    FilterMode filter_min = LINEAR;
    FilterMode filter_max = LINEAR;

    InternalFormat internal_format = IF_RGBA;

    float max_anisotropy         = 1.0;
    bool  generate_mipmap_levels = 1.0;

    std::unordered_set<int> params_dirty_list;
    std::unordered_set<int> storage_dirty_list;
    std::unordered_set<int> mipmap_dirty_list;
};

Texture::Texture()
  : d(new Data()) {
}

Texture::~Texture() {
    delete d;
}

void Texture::setGenerateMipmapLevels(bool val) {
    if (getType() == TEXTURE_RECTANGLE) {
        printf("\nThe current texture type does not support setting mipmap levels.");
        //return;
    }
    if (val != d->generate_mipmap_levels) {
        d->generate_mipmap_levels = val;
        dirty();
    }
}

bool Texture::getGenerateMipmapLevels() const {
    if (getType() == TEXTURE_RECTANGLE) return false;
    return d->generate_mipmap_levels;
}

bool Texture::onBind(State& state) {
    auto type = getType();
    glBindTexture(type, getId(state));
    return true;
}

bool Texture::onUnbind(State& state) {
    auto type = getType();
    glBindTexture(type, 0);
    return true;
}

bool Texture::onRelease(State& state) {
    auto id = getId(state);
    glDeleteTextures(1, &id);
    return true;
}

void Texture::dirtyParameters() {
    dirty();
}

bool Texture::isParametersDirty(State& state) const {
    return d->params_dirty_list.contains(state.getContext()->getId());
}

void Texture::dirtyStorage() {

}

bool Texture::isStorageDirty(State& state) const {
    return d->storage_dirty_list.contains(state.getContext()->getId());
}

void Texture::dirtyMipmapLevels() {

}

bool Texture::isMipmapLevelsDirty(State& state) const {
    return d->mipmap_dirty_list.contains(state.getContext()->getId());
}

void Texture::setFilter(FilterParameter param, FilterMode mode) {
    if (param == MAX_FILTER) {
        if (mode == d->filter_max) return;
        d->filter_max = mode;
        dirtyParameters();
    }
    else if (param == MIN_FILTER) {
        if (mode == d->filter_min) return;
        d->filter_min = mode;
        dirtyParameters();
    }
}

Texture::FilterMode Texture::getFilter(FilterParameter param) const {
    if (param == MAX_FILTER)
        return d->filter_max;
    else
        return d->filter_min;
}

void Texture::setWrap(WrapParameter param, WrapMode mode) {
    if (param == WRAP_S) {
        if (mode == d->wrap_s) return;
        d->wrap_s = mode;
        dirtyParameters();
    }
    else if (param == WRAP_T) {
        if (mode == d->wrap_t) return;
        d->wrap_t = mode;
        dirtyParameters();
    }
    else if (param == WRAP_R) {
        if (mode == d->wrap_r) return;
        d->wrap_r = mode;
        dirtyParameters();
    }
}

Texture::WrapMode Texture::getWrap(WrapParameter param) const {
    if (param == WRAP_S)
        return d->wrap_s;
    else if (param == WRAP_T)
        return d->wrap_t;
    else if (param == WRAP_R)
        return d->wrap_r;
    return d->wrap_s;
}

void Texture::setInternalFormat(InternalFormat fmt) {
    if (d->internal_format == fmt) return;
    d->internal_format = fmt;
    dirty();
}

Texture::InternalFormat Texture::getInternalFormat() const {
    return d->internal_format;
}

void Texture::setMaxAnisotropy(double val) {
    auto type = getType();
    if (type == TEXTURE_RECTANGLE || type == TEXTURE_1D || type == TEXTURE_CUBE_MAP) {
        printf("\nThe current texture type does not support setting anisotropy.");
        //return;
    }
    if (val != d->max_anisotropy) {
        d->max_anisotropy = val;
        dirty();
    }
}

float Texture::getMaxAnisotropy() const {
    if (getType() == TEXTURE_RECTANGLE) return 1.0;
    return d->max_anisotropy;
}
} // namespace glr
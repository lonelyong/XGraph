#include <xg/igl/engine/Texture.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

#include <unordered_set>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(Texture, PixelData);

Texture::Texture() = default;

Texture::~Texture() = default;

void Texture::setGenerateMipmapLevels(bool val)
{
    if (getType() == TEXTURE_RECTANGLE) {
        printf("\nThe current texture type does not support setting mipmap levels.");
    }
    if (val != generate_mipmap_levels_) {
        generate_mipmap_levels_ = val;
        dirty();
    }
}

bool Texture::getGenerateMipmapLevels() const
{
    if (getType() == TEXTURE_RECTANGLE)
        return false;
    return generate_mipmap_levels_;
}

bool Texture::onBind(State& state)
{
    auto funcs = state.getContext()->getFuncs();
    auto type  = getType();
    funcs->oglBindTexture(type, getId(state));
    return true;
}

bool Texture::onUnbind(State& state)
{
    auto funcs = state.getContext()->getFuncs();
    auto type  = getType();
    funcs->oglBindTexture(type, 0);
    return true;
}

bool Texture::onRelease(State& state)
{
    auto funcs = state.getContext()->getFuncs();
    auto id    = getId(state);
    funcs->oglDeleteTextures(1, &id);
    return true;
}

void Texture::dirtyParameters()
{ dirty(); }

bool Texture::isParametersDirty(State& state) const
{ return params_dirty_list_.contains(state.getContext()->getId()); }

void Texture::dirtyStorage()
{ dirty(); }

bool Texture::isStorageDirty(State& state) const
{ return storage_dirty_list_.contains(state.getContext()->getId()); }

void Texture::dirtyMipmapLevels()
{ dirty(); }

bool Texture::isMipmapLevelsDirty(State& state) const
{ return mipmap_dirty_list_.contains(state.getContext()->getId()); }

void Texture::setFilter(FilterParameter param, FilterMode mode)
{
    if (param == MAG_FILTER) {
        if (mode == filter_mag_)
            return;
        filter_mag_ = mode;
        dirtyParameters();
    }
    else if (param == MIN_FILTER) {
        if (mode == filter_min_)
            return;
        filter_min_ = mode;
        dirtyParameters();
    }
}

Texture::FilterMode Texture::getFilter(FilterParameter param) const
{
    if (param == MAG_FILTER)
        return filter_mag_;
    else if (param == MIN_FILTER)
        return filter_min_;
    else
        return FILTER_UNSET;
}

void Texture::setWrap(WrapParameter param, WrapMode mode)
{
    if (param == WRAP_S) {
        if (mode == wrap_s_)
            return;
        wrap_s_ = mode;
        dirtyParameters();
    }
    else if (param == WRAP_T) {
        if (mode == wrap_t_)
            return;
        wrap_t_ = mode;
        dirtyParameters();
    }
    else if (param == WRAP_R) {
        if (mode == wrap_r_)
            return;
        wrap_r_ = mode;
        dirtyParameters();
    }
}

Texture::WrapMode Texture::getWrap(WrapParameter param) const
{
    if (param == WRAP_S)
        return wrap_s_;
    else if (param == WRAP_T)
        return wrap_t_;
    else if (param == WRAP_R)
        return wrap_r_;
    return WRAP_UNSET;
}

void Texture::setInternalFormat(InternalFormat fmt)
{
    if (internal_format_ == fmt)
        return;
    internal_format_ = fmt;
    dirtyStorage();
}

void Texture::setMaxAnisotropy(double val)
{
    auto type = getType();
    if (type == TEXTURE_RECTANGLE || type == TEXTURE_1D || type == TEXTURE_CUBE_MAP) {
        printf("\nThe current texture type does not support setting anisotropy.");
        // return;
    }
    if (val != max_anisotropy_) {
        max_anisotropy_ = val;
        dirty();
    }
}

} // namespace glr
} // namespace xg
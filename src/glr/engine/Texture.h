#pragma once

#include <glr/glr_global.h>

#include <glr/engine/PixelData.h>

namespace glr {
class GLR_API Texture : public PixelData {
    VI_OBJECT_META;

  public:
    enum Type
    {
        TEXTURE_1D       = GL_TEXTURE_1D,
        TEXTURE_2D       = GL_TEXTURE_2D,
        TEXTURE_3D       = GL_TEXTURE_3D,
        TEXTURE_CUBE_MAP = GL_TEXTURE_CUBE_MAP
    };

    enum FilterParameter
    {
        MIN_FILTER = GL_TEXTURE_MIN_FILTER,
        MAX_FILTER = GL_TEXTURE_MAG_FILTER
    };

    enum FilterMode
    {
        FILTER_UNSET           = GL_ZERO,
        LINEAR                 = GL_LINEAR,
        LINEAR_MIPMAP_LINEAR   = GL_LINEAR_MIPMAP_LINEAR,
        LINEAR_MIPMAP_NEAREST  = GL_LINEAR_MIPMAP_NEAREST,
        NEAREST                = GL_NEAREST,
        NEAREST_MIPMAP_LINEAR  = GL_NEAREST_MIPMAP_LINEAR,
        NEAREST_MIPMAP_NEAREST = GL_NEAREST_MIPMAP_NEAREST
    };

    enum WrapMode
    {
        WRAP_UNSET      = GL_ZERO,
        // Not support in gl3
        CLAMP           = 0x2900,
        CLAMP_TO_EDGE   = GL_CLAMP_TO_EDGE,
        CLAMP_TO_BORDER = GL_CLAMP_TO_BORDER,
        // Not suport NPOT
        REPEAT          = GL_REPEAT,
        MIRROR          = GL_MIRRORED_REPEAT
    };

    enum WrapParameter
    {

        WRAP_S = GL_TEXTURE_WRAP_S,
        WRAP_T = GL_TEXTURE_WRAP_T,
        WRAP_R = GL_TEXTURE_WRAP_R
    };

  public:
    Texture();
    virtual ~Texture();

  public:
    virtual Type getType() const = 0;

    void setFilter(FilterParameter param, FilterMode mode);

    FilterMode getFilter(FilterParameter param) const;

    void setWrap(WrapParameter param, WrapMode mode);

    WrapMode getWrap(WrapParameter param) const;

    // 如果设置了IMAGE，将使用IMAGE的格式
    void           setInternalFormat(InternalFormat fmt);
    InternalFormat getInternalFormat() const;

  protected:
    virtual void onBind(State& state) override;
    virtual void onUnbind(State& state) override;
    virtual void onRelease(State& state) override;

  private:
    VI_OBJECT_DATA;
};
} // namespace glr
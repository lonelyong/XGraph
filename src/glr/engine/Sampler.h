#pragma once

#include <glr/glr_global.h>

#include <glr/engine/StateAttribute.h>
#include <glr/engine/Texture.h>
#include <glr/engine/types.h>

namespace glr {
/**
 * @brief glSampler
 */
class GLR_API Sampler : public StateAttribute {
    VI_OBJECT_META;

  public:
    Sampler();
    virtual ~Sampler();

  public:
    Type getType() const override;

    virtual bool isTextureAttribute() const { return true; }

    /** Sets the texture wrap mode. */
    void setWrap(Texture::WrapParameter which, Texture::WrapMode wrap);

    /** Gets the texture wrap mode. */
    Texture::WrapMode getWrap(Texture::WrapParameter which) const;

    /** Sets the texture filter mode. */
    void setFilter(Texture::FilterParameter which, Texture::FilterMode filter);

    /** Gets the texture filter mode. */
    Texture::FilterMode getFilter(Texture::FilterParameter which) const;

    /** Sets the border color. Only used when wrap mode is CLAMP_TO_BORDER.
     * The border color will be casted to the appropriate type to match the
     * internal pixel format of the texture. */
    void setBorderColor(const Vec4d& color);

    /** Gets the border color. */
    const Vec4d& getBorderColor() const;

    /** Sets the maximum anisotropy value, default value is 1.0 for no
     * anisotropic filtering. If hardware does not support anisotropic
     * filtering, use normal filtering (equivalent to a max anisotropy
     * value of 1.0. Valid range is 1.0f upwards.  The maximum value
     * depends on the graphics system. */
    void setMaxAnisotropy(float anis);

    /** Gets the maximum anisotropy value. */
    inline float getMaxAnisotropy() const;

    void setMinLOD(float anis);

    /** Gets the maximum anisotropy value. */
    inline float getMinLOD() const;

    void setMaxLOD(float anis);

    /** Gets the maximum anisotropy value. */
    inline float getMaxLOD() const;

    void setLODBias(float anis);

    /** Gets the maximum anisotropy value. */
    inline float getLODBias() const;

  protected:
    virtual void apply(State& state) const override;

  private:
    VI_OBJECT_DATA;
};

} // namespace glr
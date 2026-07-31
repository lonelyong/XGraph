#pragma once

#include <xg/igl/glr_global.hpp>

#include <xg/igl/engine/StateAttribute.hpp>
#include <xg/igl/engine/Texture.hpp>
#include <xg/igl/engine/types.hpp>

namespace xg
{
namespace glr
{

/**
 * @brief glSampler
 */
class IGL_CORE_API Sampler : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    Sampler();
    virtual ~Sampler();

  public:
    Type getType() const override { return SAMPLER; }

    virtual bool isTextureAttribute() const
    { return true; }

    /** Sets the texture wrap mode. */
    void setWrap(Texture::WrapParameter which, Texture::WrapMode wrap) {}

    /** Gets the texture wrap mode. */
    Texture::WrapMode getWrap(Texture::WrapParameter which) const { return Texture::WrapMode(); }

    /** Sets the texture filter mode. */
    void setFilter(Texture::FilterParameter which, Texture::FilterMode filter) {}

    /** Gets the texture filter mode. */
    Texture::FilterMode getFilter(Texture::FilterParameter which) const { return Texture::FilterMode(); }

    /** Sets the border color. */
    void setBorderColor(const Vec4d& color) {}

    /** Gets the border color. */
    const Vec4d& getBorderColor() const { static Vec4d c; return c; }

    /** Sets the maximum anisotropy value. */
    void setMaxAnisotropy(float anis) {}

    /** Gets the maximum anisotropy value. */
    inline float getMaxAnisotropy() const { return 0.0f; }

    void setMinLOD(float anis) {}

    /** Gets the maximum anisotropy value. */
    inline float getMinLOD() const { return 0.0f; }

    void setMaxLOD(float anis) {}

    /** Gets the maximum anisotropy value. */
    inline float getMaxLOD() const { return 0.0f; }

    void setLODBias(float anis) {}

    /** Gets the maximum anisotropy value. */
    inline float getLODBias() const { return 0.0f; }

  protected:
    virtual void apply(State& state) const override;

  private:
    Texture::WrapMode   wrap_s_ = Texture::WRAP_UNSET;
    Texture::WrapMode   wrap_r_ = Texture::WRAP_UNSET;
    Texture::WrapMode   wrap_t_ = Texture::WRAP_UNSET;
    Texture::FilterMode min_filter_ = Texture::FILTER_UNSET;
    Texture::FilterMode mag_filter_ = Texture::FILTER_UNSET;
};

} // namespace glr
} // namespace xg
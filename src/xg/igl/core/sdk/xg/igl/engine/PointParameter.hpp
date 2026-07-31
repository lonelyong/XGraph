#pragma once

#include <xg/igl/glr_global.hpp>

#include <xg/igl/engine/StateAttribute.hpp>
#include <xg/igl/engine/types.hpp>

namespace xg
{
namespace glr
{

/**
 *
 */
class IGL_CORE_API PointParameter : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    enum SpriteCoordOrigin
    {
        LOWER_LEFT = IGL_LOWER_LEFT,
        UPPER_LEFT = IGL_UPPER_LEFT
    };

  public:
    PointParameter();
    PointParameter(GLfloat_t size);
    virtual ~PointParameter();

  public:
    virtual Type getType() const override { return POINT_PARAMETER; }

    virtual bool equals(const StateAttribute& other) const override;

    void      setSize(GLfloat_t size) { size_ = size; }
    GLfloat_t getSize() const { return size_; }

    void      setFadeThresholdSize(GLfloat_t size) { fade_threshole_size_ = size; }
    GLfloat_t getFadeThresholdSize() const { return fade_threshole_size_; }

    void              setSpriteCoordOrigin(SpriteCoordOrigin val) { origin_ = val; }
    SpriteCoordOrigin getSpriteCoordOrigin() const { return origin_; }

  protected:
    virtual void apply(State& state) const override;

  private:
    GLfloat_t         size_                 = 1.0f;
    SpriteCoordOrigin origin_               = UPPER_LEFT;
    GLfloat_t         fade_threshole_size_  = 1.0f;
};

} // namespace glr
} // namespace xg
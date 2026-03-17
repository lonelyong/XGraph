#pragma once

#include <glr/glr_global.h>

#include <glr/engine/StateAttribute.h>
#include <glr/engine/types.h>

namespace glr {
/**
 *
 */
class GLR_API PointParameter : public StateAttribute {
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
    virtual Type getType() const override;

    virtual bool equals(const StateAttribute& other) const override;

    void      setSize(GLfloat_t size);
    GLfloat_t getSize() const;

    void      setFadeThresholdSize(GLfloat_t size);
    GLfloat_t getFadeThresholdSize() const;

    void              setSpriteCoordOrigin(SpriteCoordOrigin val);
    SpriteCoordOrigin getSpriteCoordOrigin() const;

  protected:
    virtual void apply(State& state) const override;

  private:
    struct Data; Data* const d;;
};
} // namespace glr
#pragma once

#include <glr/glr_global.h>

#include <glr/engine/StateAttribute.h>
#include <glr/engine/types.h>

namespace glr {
class GLR_API PointParameter : public StateAttribute {
    VI_OBJECT_META;

  public:
    enum SpriteCoordOrigin
    {
        LOWER_LEFT = HGL_LOWER_LEFT,
        UPPER_LEFT = HGL_UPPER_LEFT
    };

  public:
    PointParameter();
    PointParameter(int size);
    virtual ~PointParameter();

  public:
    virtual Type getType() const override;

    virtual bool equals(const StateAttribute& other) const override;

    /**
     * @brief default value is -1
     * @param vertices
     */
    void setSize(int vertices);
    int  getSize() const;

    void              setSpriteCoordOrigin(SpriteCoordOrigin val);
    SpriteCoordOrigin getSpriteCoordOrigin() const;

  protected:
    virtual void apply(State& state) const override;

  private:
    VI_OBJECT_DATA;
};
} // namespace glr
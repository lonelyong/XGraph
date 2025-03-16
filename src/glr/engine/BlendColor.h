#pragma once

#include <glr/engine/StateAttribute.h>

#include <glr/engine/types.h>

namespace glr {
class GLR_API BlendColor : public StateAttribute {
    VI_OBJECT_META;

  public:
    BlendColor();
    virtual ~BlendColor();

  public:
    virtual Type getType() const override;

    void setColor(const Vec4f& color);

    Vec4f getColor() const;

  protected:
    virtual void apply(State& state) const override;

  private:
    VI_OBJECT_DATA;
};
} // namespace glr
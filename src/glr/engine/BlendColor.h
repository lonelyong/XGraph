#pragma once

#include <glr/engine/StateAttribute.h>

#include <glr/engine/types.h>

namespace glr {
class GLR_API BlendColor : public StateAttribute {
    V_OBJECT_META_DECL

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
    struct Data; Data* const d;;
};
} // namespace glr
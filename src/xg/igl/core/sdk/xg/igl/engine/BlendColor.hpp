#pragma once

#include <xg/igl/engine/StateAttribute.hpp>

#include <xg/igl/engine/types.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API BlendColor : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    BlendColor();
    virtual ~BlendColor();

  public:
    virtual Type getType() const override { return BLEND_COLOR; }

    void setColor(const Vec4f& color) { color_ = color; }
    Vec4f getColor() const { return color_; }

  protected:
    virtual void apply(State& state) const override;

  private:
    Vec4f color_;
};

} // namespace glr
} // namespace xg
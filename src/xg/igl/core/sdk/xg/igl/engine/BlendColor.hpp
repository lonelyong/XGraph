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
    virtual Type getType() const override;

    void setColor(const Vec4f& color);

    Vec4f getColor() const;

  protected:
    virtual void apply(State& state) const override;

  private:
    struct Data;
    Data* const d;
    ;
};

} // namespace glr
} // namespace xg
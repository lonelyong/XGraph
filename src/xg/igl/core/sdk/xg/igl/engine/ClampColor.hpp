#pragma once

#include <xg/igl/engine/StateAttribute.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API ClampColor : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    ClampColor();
    virtual ~ClampColor();

  public:
    virtual Type getType() const override { return CLAMP_COLOR; }

  protected:
    virtual void apply(State& state) const override;
};

} // namespace glr
} // namespace xg
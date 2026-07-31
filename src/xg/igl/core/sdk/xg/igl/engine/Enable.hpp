#pragma once

#include <xg/igl/engine/StateAttribute.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API Enable : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    Enable();
    virtual ~Enable();

  public:
    virtual Type getType() const override { return ENABLE; }

  protected:
    virtual void apply(State& state) const override;
};

} // namespace glr
} // namespace xg
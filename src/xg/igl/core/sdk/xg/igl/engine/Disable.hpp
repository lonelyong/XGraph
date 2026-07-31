#pragma once

#include <xg/igl/engine/StateAttribute.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API Disable : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    Disable();
    virtual ~Disable();

  public:
    virtual Type getType() const override { return DISABLE; }

  protected:
    virtual void apply(State& state) const override;
};

} // namespace glr
} // namespace xg
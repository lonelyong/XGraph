#pragma once

#include <xg/igl/engine/StateAttribute.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API LogicOp : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    LogicOp();
    virtual ~LogicOp();

  public:
    virtual Type getType() const override { return LOGICOP; }

  protected:
    virtual void apply(State& state) const override;
};

} // namespace glr
} // namespace xg
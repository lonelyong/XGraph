#pragma once

#include <xg/glr/engine/StateAttribute.h>

namespace xg {
namespace glr {
class GLR_API LogicOp : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    LogicOp();
    virtual ~LogicOp();

  public:
    virtual Type getType() const override;

  protected:
    virtual void apply(State& state) const override;

  private:
    struct Data; Data* const d;;
};
} // namespace glr
} // namespace xg
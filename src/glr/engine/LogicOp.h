#pragma once

#include <glr/engine/StateAttribute.h>

namespace glr {
class GLR_API LogicOp : public StateAttribute {
    VI_OBJECT_META;

  public:
    LogicOp();
    virtual ~LogicOp();

  public:
    virtual Type getType() const override;

  protected:
    virtual void apply(State& state) const override;

  private:
    VI_OBJECT_DATA;
};
} // namespace glr
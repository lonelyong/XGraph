#pragma once

#include <xg/glr/engine/StateAttribute.hpp>

namespace xg {
namespace glr {
class GLR_API Enable : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    Enable();
    virtual ~Enable();

  public:
    virtual Type getType() const override;

  protected:
    virtual void apply(State& state) const override;

  private:
    struct Data; Data* const d;;
};
} // namespace glr
} // namespace xg
#pragma once

#include <glr/engine/StateAttribute.h>

namespace glr {
class GLR_API CullFace : public StateAttribute {
    VI_OBJECT_META;

  public:
    CullFace();
    virtual ~CullFace();

  public:
    virtual Type getType() const override;

  protected:
    virtual void apply(State& state) const override;

  private:
    VI_OBJECT_DATA;
};
} // namespace glr
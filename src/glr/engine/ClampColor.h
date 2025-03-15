#pragma once

#include <glr/engine/StateAttribute.h>

namespace glr {
class GLR_API ClampColor : public StateAttribute {
    VI_OBJECT_META;

  public:
    ClampColor();
    virtual ~ClampColor();

  public:
    virtual Type getType() const override;

  protected:
    virtual void apply(State& state) const override;

  private:
    VI_OBJECT_DATA;
};
} // namespace glr
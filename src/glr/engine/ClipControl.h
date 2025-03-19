#pragma once

#include <glr/engine/StateAttribute.h>

namespace glr {
class GLR_API ClipControl : public StateAttribute {
    VI_OBJECT_META;

  public:
    enum Origin
    {
        LOWER_LEFT = IGL_LOWER_LEFT,
        UPPER_LEFT = IGL_UPPER_LEFT
    };

    enum Depth
    {
        NEGATIVE_ONE_TO_ONE = IGL_NEGATIVE_ONE_TO_ONE,
        ZERO_TO_ONE         = IGL_ZERO_TO_ONE
    };

  public:
    ClipControl();
    ClipControl(Origin origin, Depth depth);
    virtual ~ClipControl();

  public:
    virtual Type getType() const override;

    void   setOrigin(Origin origin);
    Origin getOrigin() const;

    void  setDepth(Depth origin);
    Depth getDepth() const;

  protected:
    virtual void apply(State& state) const override;

  private:
    VI_OBJECT_DATA;
};
} // namespace glr
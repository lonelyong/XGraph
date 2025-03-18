#pragma once

#include <glr/engine/StateAttribute.h>

namespace glr {
class GLR_API FrontFace : public StateAttribute {
    VI_OBJECT_META;

  public:
    enum Mode
    {
        CW  = HGL_CW,
        CCW = HGL_CCW,
    };

  public:
    FrontFace();
    FrontFace(Mode mode);
    virtual ~FrontFace();

  public:
    virtual Type getType() const override;

    Mode getMode() const;
    void setMode(Mode mode);

  protected:
    virtual void apply(State& state) const override;

  private:
    VI_OBJECT_DATA;
};
} // namespace glr
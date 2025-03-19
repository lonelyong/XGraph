#pragma once

#include <glr/engine/StateAttribute.h>

namespace glr {
class GLR_API CullFace : public StateAttribute {
    VI_OBJECT_META;

  public:
    enum Mode
    {
        FRONT          = IGL_FRONT,
        BACK           = IGL_BACK,
        FRONT_AND_BACK = IGL_FRONT_AND_BACK
    };

  public:
    CullFace();
    CullFace(Mode mode);
    virtual ~CullFace();

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
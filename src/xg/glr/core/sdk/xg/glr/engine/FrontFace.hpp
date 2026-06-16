#pragma once

#include <xg/glr/engine/StateAttribute.h>

namespace xg {
namespace glr {
class GLR_API FrontFace : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    enum Mode
    {
        CW  = IGL_CW,
        CCW = IGL_CCW,
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
    struct Data; Data* const d;;
};
} // namespace glr
} // namespace xg
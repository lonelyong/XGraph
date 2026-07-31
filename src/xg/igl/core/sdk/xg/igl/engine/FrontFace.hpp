#pragma once

#include <xg/igl/engine/StateAttribute.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API FrontFace : public StateAttribute {
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
    virtual Type getType() const override { return FRONT_FACE; }

    Mode getMode() const { return mode_; }
    void setMode(Mode mode) { mode_ = mode; }

  protected:
    virtual void apply(State& state) const override;

  private:
    Mode mode_ = CCW;
};

} // namespace glr
} // namespace xg
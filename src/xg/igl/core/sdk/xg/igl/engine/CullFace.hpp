#pragma once

#include <xg/igl/engine/StateAttribute.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API CullFace : public StateAttribute {
    V_OBJECT_META_DECL

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
    virtual Type getType() const override { return CULL_FACE; }

    Mode getMode() const { return mode_; }
    void setMode(Mode mode) { mode_ = mode; }

  protected:
    virtual void apply(State& state) const override;

  private:
    Mode mode_ = BACK;
};

} // namespace glr
} // namespace xg
#pragma once

#include <xg/glr/engine/StateAttribute.h>

namespace xg {
namespace glr {
class GLR_API CullFace : public StateAttribute {
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
#pragma once

#include <xg/igl/engine/StateAttribute.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API PolygonMode : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    enum Mode
    {
        POINT = IGL_POINT,
        LINE  = IGL_LINE,
        FILL  = IGL_FILL
    };

  public:
    PolygonMode();
    PolygonMode(Mode mode);
    virtual ~PolygonMode();

  public:
    virtual Type getType() const override { return POLYGON_MODE; }

    Mode getMode() const { return mode_; }
    void setMode(Mode mode) { mode_ = mode; }

  protected:
    virtual void apply(State& state) const override;

  private:
    Mode mode_ = FILL;
};

} // namespace glr
} // namespace xg
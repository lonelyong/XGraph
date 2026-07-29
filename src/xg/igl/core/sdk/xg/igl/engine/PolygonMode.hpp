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
    virtual Type getType() const override;

    Mode getMode() const;
    void setMode(Mode mode);

  protected:
    virtual void apply(State& state) const override;

  private:
    struct Data;
    Data* const d;
    ;
};

} // namespace glr
} // namespace xg
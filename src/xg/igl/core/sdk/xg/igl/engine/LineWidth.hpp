#pragma once

#include <xg/igl/engine/StateAttribute.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API LineWidth : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    LineWidth();
    virtual ~LineWidth();

  public:
    virtual Type getType() const override { return LINE_WIDTH; }

  protected:
    virtual void apply(State& state) const override;
};

} // namespace glr
} // namespace xg
#pragma once

#include <xg/igl/engine/StateAttribute.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API Hint : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    enum HintType
    {
        LINE_SMOOTH                = IGL_LINE_SMOOTH_HINT,
        POLYGON_SMOOTH             = IGL_POLYGON_SMOOTH_HINT,
        TEXTURE_COMPRESSION        = IGL_TEXTURE_COMPRESSION_HINT,
        FRAGMENT_SHADER_DERIVATIVE = IGL_FRAGMENT_SHADER_DERIVATIVE_HINT
    };

    enum HintValue
    {
        FASTEST   = IGL_FASTEST,
        NICEST    = IGL_NICEST,
        DONT_CARE = IGL_DONT_CARE
    };

  public:
    Hint();
    Hint(HintType type, HintValue val);
    virtual ~Hint();

  public:
    virtual Type getType() const override;

  protected:
    virtual void apply(State& state) const override;

  private:
    struct Data;
    Data* const d;
    ;
};

} // namespace glr
} // namespace xg
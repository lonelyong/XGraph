#pragma once

#include <xg/igl/engine/StateAttribute.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API PolygonOffset : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    PolygonOffset();
    PolygonOffset(GLfloat_t factor, GLfloat_t units);
    virtual ~PolygonOffset();

  public:
    virtual Type getType() const override { return POLYGON_OFFSET; }

    GLfloat_t getFactor() const { return factor_; }
    void      setFactor(GLfloat_t val) { factor_ = val; }

    GLfloat_t getUnits() const { return units_; }
    void      setUnits(GLfloat_t val) { units_ = val; }

  protected:
    virtual void apply(State& state) const override;

  private:
    GLfloat_t factor_ = 0.f;
    GLfloat_t units_  = 0.f;
};

} // namespace glr
} // namespace xg
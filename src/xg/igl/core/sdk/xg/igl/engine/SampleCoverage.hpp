#pragma once

#include <xg/igl/engine/StateAttribute.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API SampleCoverage : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    SampleCoverage();
    SampleCoverage(GLfloat_t value, GLboolean_t invert);
    virtual ~SampleCoverage();

  public:
    virtual Type getType() const override { return SAMPLE_COVERAGE; }

    GLfloat_t getValue() const { return value_; }
    void      setValue(GLfloat_t val) { value_ = val; }

    GLboolean_t getInvert() const { return invert_; }
    void        setInvert(GLboolean_t val) { invert_ = val; }

  protected:
    virtual void apply(State& state) const override;

  private:
    GLfloat_t   value_  = 0.f;
    GLboolean_t invert_ = false;
};

} // namespace glr
} // namespace xg
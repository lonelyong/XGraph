#pragma once

#include <glr/engine/StateAttribute.h>

namespace glr {
class GLR_API SampleCoverage : public StateAttribute {
    VI_OBJECT_META;

  public:
    SampleCoverage();
    SampleCoverage(GLfloat_t value, GLboolean_t invert);
    virtual ~SampleCoverage();

  public:
    virtual Type getType() const override;

    GLfloat_t getValue() const;
    void      setValue(GLfloat_t val);

    GLboolean_t getInvert() const;
    void        setInvert(GLboolean_t val);

  protected:
    virtual void apply(State& state) const override;

  private:
    VI_OBJECT_DATA;
};
} // namespace glr
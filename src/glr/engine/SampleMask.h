#pragma once

#include <glr/engine/StateAttribute.h>

namespace glr {
/**
 * @brief glSampleMask
 */
class GLR_API SampleMask : public StateAttribute {
    VI_OBJECT_META;

  public:
    SampleMask();
    SampleMask(GLuint_t mask_number, GLbitfield_t mask);
    virtual ~SampleMask();

  public:
    virtual Type getType() const override;

    GLuint_t getNumber() const;
    void     setNumber(GLuint_t val);

    GLbitfield_t getMask() const;
    void       setMask(GLbitfield_t val);

  protected:
    virtual void apply(State& state) const override;

  private:
    VI_OBJECT_DATA;
};
} // namespace glr
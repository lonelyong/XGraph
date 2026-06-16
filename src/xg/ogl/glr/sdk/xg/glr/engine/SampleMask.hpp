#pragma once

#include <xg/glr/engine/StateAttribute.h>

namespace glr {
/**
 * @brief glSampleMask
 */
class GLR_API SampleMask : public StateAttribute {
    V_OBJECT_META_DECL

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
    struct Data; Data* const d;;
};
} // namespace glr
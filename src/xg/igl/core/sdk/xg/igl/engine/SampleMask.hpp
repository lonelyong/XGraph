#pragma once

#include <xg/igl/engine/StateAttribute.hpp>

namespace xg
{
namespace glr
{

/**
 * @brief glSampleMask
 */
class IGL_CORE_API SampleMask : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    SampleMask();
    SampleMask(GLuint_t mask_number, GLbitfield_t mask);
    virtual ~SampleMask();

  public:
    virtual Type getType() const override { return SAMPLE_MASK; }

    GLuint_t getNumber() const { return number_; }
    void     setNumber(GLuint_t val) { number_ = val; }

    GLbitfield_t getMask() const { return mask_; }
    void         setMask(GLbitfield_t val) { mask_ = val; }

  protected:
    virtual void apply(State& state) const override;

  private:
    GLuint_t     number_ = 0;
    GLbitfield_t mask_   = 1;
};

} // namespace glr
} // namespace xg
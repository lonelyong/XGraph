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
    virtual Type getType() const override;

    GLuint_t getNumber() const;
    void     setNumber(GLuint_t val);

    GLbitfield_t getMask() const;
    void         setMask(GLbitfield_t val);

  protected:
    virtual void apply(State& state) const override;

  private:
    struct Data;
    Data* const d;
    ;
};

} // namespace glr
} // namespace xg
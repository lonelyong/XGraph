#include <xg/igl/engine/SampleMask.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(SampleMask, StateAttribute);

struct SampleMask::Data {
    GLuint_t     number = 0;
    GLbitfield_t mask   = 1;
};

SampleMask::SampleMask()
  : d(new Data())
{}

SampleMask::SampleMask(GLuint_t mask_number, GLbitfield_t mask)
  : d(new Data())
{
    setNumber(mask_number);
    setMask(mask);
}

SampleMask::~SampleMask()
{ delete d; }

GLuint_t SampleMask::getNumber() const
{ return d->number; }

void SampleMask::setNumber(GLuint_t val)
{ d->number = val; }

GLbitfield_t SampleMask::getMask() const
{ return d->mask; }

void SampleMask::setMask(GLbitfield_t val)
{ d->mask = val; }

SampleMask::Type SampleMask::getType() const
{ return SAMPLE_MASK; }

void SampleMask::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglSampleMaski(d->number, d->mask);
}

} // namespace glr
} // namespace xg
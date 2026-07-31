#include <xg/igl/engine/SampleMask.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(SampleMask, StateAttribute);

SampleMask::SampleMask() = default;

SampleMask::SampleMask(GLuint_t mask_number, GLbitfield_t mask)
{
    setNumber(mask_number);
    setMask(mask);
}

SampleMask::~SampleMask() = default;

void SampleMask::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglSampleMaski(number_, mask_);
}

} // namespace glr
} // namespace xg
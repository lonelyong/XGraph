#include <xg/igl/engine/SampleCoverage.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(SampleCoverage, StateAttribute);

SampleCoverage::SampleCoverage() = default;

SampleCoverage::SampleCoverage(GLfloat_t value, GLboolean_t invert)
{
    setValue(value);
    setInvert(invert);
}

SampleCoverage::~SampleCoverage() = default;

void SampleCoverage::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglSampleCoverage(value_, invert_);
}

} // namespace glr
} // namespace xg
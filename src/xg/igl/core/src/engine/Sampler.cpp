#include <vector>
#include <xg/igl/engine/Sampler.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

#pragma region Sampler
V_OBJECT_META_IMPL(Sampler, StateAttribute);

Sampler::Sampler() = default;

Sampler::~Sampler() = default;

void Sampler::apply(State& state) const
{ auto funcs = state.getContext()->getFuncs(); }

#pragma endregion

} // namespace glr
} // namespace xg
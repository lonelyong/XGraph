#include <xg/igl/engine/PatchParameter.hpp>


#include <glm/gtc/type_ptr.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/engine/types.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

V_OBJECT_META_IMPL(xg::glr::PatchParameter, xg::glr::StateAttribute)

namespace xg
{
namespace glr
{

PatchParameter::PatchParameter() = default;

PatchParameter::PatchParameter(int vertices)
  : vertices_(vertices)
{}

PatchParameter::~PatchParameter() = default;

bool PatchParameter::equals(const StateAttribute& other) const
{
    if (other.isKindOf(PatchParameter::desc())) {}
    return false;
}


void PatchParameter::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglPatchParameteri(IGL_PATCH_VERTICES, vertices_);
    funcs->oglPatchParameterfv(IGL_PATCH_DEFAULT_INNER_LEVEL, glm::value_ptr(patch_def_inner_level_));
    funcs->oglPatchParameterfv(IGL_PATCH_DEFAULT_OUTER_LEVEL, glm::value_ptr(patch_def_outer_level_));
}

} // namespace glr
} // namespace xg
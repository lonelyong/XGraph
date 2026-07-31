#include <xg/igl/engine/PointParameter.hpp>


#include <glm/gtc/type_ptr.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/engine/types.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

V_OBJECT_META_IMPL(xg::glr::PointParameter, xg::glr::StateAttribute)

namespace xg
{
namespace glr
{

PointParameter::PointParameter() = default;

PointParameter::PointParameter(GLfloat_t size)
  : size_(size)
{}

PointParameter::~PointParameter() = default;

bool PointParameter::equals(const StateAttribute& other) const
{
    if (other.isKindOf(PointParameter::desc())) {}
    return false;
}


void PointParameter::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglPointSize(size_);
    funcs->oglPointParameteri(IGL_POINT_SPRITE_COORD_ORIGIN, origin_);
    funcs->oglPointParameterf(IGL_POINT_FADE_THRESHOLD_SIZE, size_);
}

} // namespace glr
} // namespace xg
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

struct PointParameter::Data {
    GLfloat_t         size                = 1.0f;
    SpriteCoordOrigin origin              = UPPER_LEFT;
    GLfloat_t         fade_threshole_size = 1.0f;
};

PointParameter::PointParameter()
  : d(new Data())
{}

PointParameter::PointParameter(GLfloat_t size)
  : d(new Data())
{}

PointParameter::~PointParameter()
{ delete d; }

StateAttribute::Type PointParameter::getType() const
{ return POINT_PARAMETER; }

bool PointParameter::equals(const StateAttribute& other) const
{
    if (other.isKindOf(PointParameter::desc())) {}
    return false;
}

void PointParameter::setSize(GLfloat_t size)
{ d->size = size; }

GLfloat_t PointParameter::getSize() const
{ return d->size; }

void PointParameter::setFadeThresholdSize(GLfloat_t size)
{ d->fade_threshole_size = size; }

GLfloat_t PointParameter::getFadeThresholdSize() const
{ return d->size; }

void PointParameter::setSpriteCoordOrigin(SpriteCoordOrigin val)
{ d->origin = val; }

PointParameter::SpriteCoordOrigin PointParameter::getSpriteCoordOrigin() const
{ return d->origin; }

void PointParameter::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglPointSize(d->size);
    funcs->oglPointParameteri(IGL_POINT_SPRITE_COORD_ORIGIN, d->origin);
    funcs->oglPointParameterf(IGL_POINT_FADE_THRESHOLD_SIZE, d->size);
}

} // namespace glr
} // namespace xg
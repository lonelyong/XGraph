#include <xg/glr/engine/PointParameter.h>


#include <glm/gtc/type_ptr.hpp>

#include <xg/glr/engine/GraphicContext.h>
#include <xg/glr/engine/State.h>
#include <xg/glr/engine/types.h>
#include <xg/glr/igl/GLfuncs.h>

V_OBJECT_META_IMPL(glr::PointParameter, glr::StateAttribute)

namespace xg {
namespace glr {
struct PointParameter::Data {
    GLfloat_t         size                = 1.0f;
    SpriteCoordOrigin origin              = UPPER_LEFT;
    GLfloat_t         fade_threshole_size = 1.0f;
};

PointParameter::PointParameter()
  : d(new Data()) {
}

PointParameter::PointParameter(GLfloat_t size)
  : d(new Data()) {
}

PointParameter::~PointParameter() {
    delete d;
}

StateAttribute::Type PointParameter::getType() const {
    return POINT_PARAMETER;
}

bool PointParameter::equals(const StateAttribute& other) const {
    if (other.isKindOf(PointParameter::desc())) {
    }
    return false;
}

void PointParameter::setSize(GLfloat_t size) {
    d->size = size;
}

GLfloat_t PointParameter::getSize() const {
    return d->size;
}

void PointParameter::setFadeThresholdSize(GLfloat_t size) {
    d->fade_threshole_size = size;
}

GLfloat_t PointParameter::getFadeThresholdSize() const {
    return d->size;
}

void PointParameter::setSpriteCoordOrigin(SpriteCoordOrigin val) {
    d->origin = val;
}

PointParameter::SpriteCoordOrigin PointParameter::getSpriteCoordOrigin() const {
    return d->origin;
}

void PointParameter::apply(State& state) const {
    auto funcs = state.getContext()->getFuncs();
    funcs->iglPointSize(d->size);
    funcs->iglPointParameteri(IGL_POINT_SPRITE_COORD_ORIGIN, d->origin);
    funcs->iglPointParameterf(IGL_POINT_FADE_THRESHOLD_SIZE, d->size);
}
} // namespace glr
} // namespace xg
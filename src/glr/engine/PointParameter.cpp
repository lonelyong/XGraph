#include <glr/engine/PointParameter.h>

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

#include <glr/engine/types.h>

VI_OBJECT_META_IMPL(glr::PointParameter, glr::StateAttribute)

namespace glr {
struct PointParameter::Data {
    int   vertices              = 3;
    Vec2f patch_def_inner_level = { 1.0f, 1.0f };
    Vec4f patch_def_outer_level = { 1.0f, 1.0f, 1.0f, 1.0f };
};

PointParameter::PointParameter()
  : d(new Data()) {
}

PointParameter::PointParameter(int vertices)
  : d(new Data()) {
}

PointParameter::~PointParameter() {
    delete d;
}

StateAttribute::Type PointParameter::getType() const {
    return PATCH_PARAMETER;
}

bool PointParameter::equals(const StateAttribute& other) const {
    if (other.isKindOf(PointParameter::desc())) {
      
    }
    return false;
}

void PointParameter::setSize(int vertices) {
    d->vertices = vertices;
}

int PointParameter::getSize() const {
    return d->vertices;
}

void PointParameter::apply(State& state) const {
    glPointParameteri(GL_PATCH_VERTICES, d->vertices);
    glPointParameterfv(GL_PATCH_DEFAULT_INNER_LEVEL, glm::value_ptr(d->patch_def_inner_level));
    glPointParameterfv(GL_PATCH_DEFAULT_OUTER_LEVEL, glm::value_ptr(d->patch_def_outer_level));
}
} // namespace glr
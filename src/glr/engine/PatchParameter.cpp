#include <glr/engine/PatchParameter.h>


#include <glm/gtc/type_ptr.hpp>

#include <glr/engine/GraphicContext.h>
#include <glr/engine/State.h>
#include <glr/engine/types.h>
#include <glr/igl/GLfuncs.h>

V_OBJECT_META_IMPL(glr::PatchParameter, glr::StateAttribute)

namespace glr {
struct PatchParameter::Data {
    int   vertices              = 3;
    Vec2f patch_def_inner_level = { 1.0f, 1.0f };
    Vec4f patch_def_outer_level = { 1.0f, 1.0f, 1.0f, 1.0f };
};

PatchParameter::PatchParameter()
  : d(new Data()) {
}

PatchParameter::PatchParameter(int vertices)
  : d(new Data()) {
}

PatchParameter::~PatchParameter() {
    delete d;
}

StateAttribute::Type PatchParameter::getType() const {
    return PATCH_PARAMETER;
}

bool PatchParameter::equals(const StateAttribute& other) const {
    if (other.isKindOf(PatchParameter::desc())) {
    }
    return false;
}

void PatchParameter::setVertices(int vertices) {
    d->vertices = vertices;
}

int PatchParameter::getVertices() const {
    return d->vertices;
}

void PatchParameter::setPatchDefaultInnerLevel(const Vec2f& level) {
    d->patch_def_inner_level = level;
}

const Vec2f& PatchParameter::getPatchDefaultInnerLevel() const {
    return d->patch_def_inner_level;
}

void PatchParameter::setPatchDefaultOuterLevel(const Vec4f& level) {
    d->patch_def_outer_level = level;
}

const Vec4f& PatchParameter::getPatchDefaultOuterLevel() const {
    return d->patch_def_outer_level;
}

void PatchParameter::apply(State& state) const {
    auto funcs = state.getContext()->getFuncs();
    funcs->iglPatchParameteri(IGL_PATCH_VERTICES, d->vertices);
    funcs->iglPatchParameterfv(IGL_PATCH_DEFAULT_INNER_LEVEL, glm::value_ptr(d->patch_def_inner_level));
    funcs->iglPatchParameterfv(IGL_PATCH_DEFAULT_OUTER_LEVEL, glm::value_ptr(d->patch_def_outer_level));
}
} // namespace glr
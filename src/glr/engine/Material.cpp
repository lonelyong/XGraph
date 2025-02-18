#include "Material.h"

#include <glr/engine/Shader.h>
#include <glr/engine/State.h>

namespace glr {
VI_OBJECT_META_IMPL(Material, StateAttribute);

Material::Material()
  : a_(Vec4f(0.1f, 0.1f, 0.1f, 1.0f))
  , d_(Vec4f(0.8f, 0.8f, 0.8f, 1.0f))
  , s_(Vec4f(1.0f, 1.0f, 1.0f, 1.0f))
  , e_(Vec4f(0.0f, 0.0f, 0.0f, 1.0f))
  , sh_(32.0f) {
}

Vec4f Material::getAmbient() const {
    return a_;
}

void Material::setAmbient(const Vec4f& color) {
    a_ = color;
}

Vec4f Material::getDiffuse() const {
    return d_;
}

void Material::setDiffuse(const Vec4f& color) {
    d_ = color;
}

Vec4f Material::getSpecular() const {
    return s_;
}

void Material::setSpecular(const Vec4f& color) {
    s_ = color;
}

Vec4f Material::getEmission() const {
    return e_;
}

void Material::setEmission(const Vec4f& color) {
    e_ = color;
}

float Material::getShininess() const {
    return sh_;
}

void Material::setShininess(float shininess) {
    sh_ = shininess;
}

StateAttribute::Type Material::getType() const {
    return ATTR_MATERIAL;
}

void Material::apply(State& state) const {
    auto shader = state.getCurrentShader();
    if (shader) {
        shader->set(state, "mate.a", a_);
        shader->set(state, "mate.d", d_);
        shader->set(state, "mate.s", s_);
        shader->set(state, "mate.e", e_);
        shader->set(state, "mate.sh", sh_);
    }
}

} // namespace glr
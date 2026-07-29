#include <xg/igl/engine/PhongMaterial.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/Program.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(PhongMaterial, UniformBase);

PhongMaterial::PhongMaterial()
  : a_(Vec4f(0.1f, 0.1f, 0.1f, 1.0f))
  , d_(Vec4f(0.8f, 0.8f, 0.8f, 1.0f))
  , s_(Vec4f(1.0f, 1.0f, 1.0f, 1.0f))
  , e_(Vec4f(0.0f, 0.0f, 0.0f, 1.0f))
  , sh_(32.0f)
{ name_ = "mate"; }

Vec4f PhongMaterial::getAmbient() const
{ return a_; }

void PhongMaterial::setAmbient(const Vec4f& color)
{ a_ = color; }

Vec4f PhongMaterial::getDiffuse() const
{ return d_; }

void PhongMaterial::setDiffuse(const Vec4f& color)
{ d_ = color; }

Vec4f PhongMaterial::getSpecular() const
{ return s_; }

void PhongMaterial::setSpecular(const Vec4f& color)
{ s_ = color; }

Vec4f PhongMaterial::getEmission() const
{ return e_; }

void PhongMaterial::setEmission(const Vec4f& color)
{ e_ = color; }

float PhongMaterial::getShininess() const
{ return sh_; }

void PhongMaterial::setShininess(float shininess)
{ sh_ = shininess; }

StateAttribute::Type PhongMaterial::getType() const
{ return PHONG_MATERIAL; }

void PhongMaterial::setName(const std::string& name)
{}

const std::string& PhongMaterial::getName() const
{ return name_; }

void PhongMaterial::apply(State& state) const
{
    auto prog = state.getCurrentProgram();
    if (prog) {
        prog->set(state, name_ + ".ambient", a_);
        prog->set(state, name_ + ".diffuse", d_);
        prog->set(state, name_ + ".specular", s_);
        prog->set(state, name_ + ".emission", e_);
        prog->set(state, name_ + ".shininess", sh_);
    }
}

} // namespace glr
} // namespace xg
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
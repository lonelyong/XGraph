#include <xg/igl/engine/Subroutine.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/Program.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(Subroutine, UniformBase);

Subroutine::Subroutine(ShaderType type, const std::string name)
  : type_(type)
  , name_(name)
{}

Subroutine::~Subroutine() = default;

void Subroutine::apply(State& state) const
{
    auto funcs  = state.getContext()->getFuncs();
    auto shader = state.getCurrentProgram();
    if (shader && type_ != NO_TYPE) {
        if (!name_.empty()) {
            auto loc = funcs->oglGetSubroutineIndex(shader->getId(state), type_, name_.data());
            if (loc != IGL_INVALID_INDEX) { funcs->oglUniformSubroutinesuiv(type_, 1, &loc); }
        }
    }
}

} // namespace glr
} // namespace xg
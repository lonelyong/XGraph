#include <xg/igl/engine/Hint.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(Hint, StateAttribute);

Hint::Hint() = default;

Hint::Hint(HintType type, HintValue val)
  : type_(type)
  , val_(val)
{}

Hint::~Hint() = default;

void Hint::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    if (type_) { funcs->oglHint(type_, val_); }
}

} // namespace glr
} // namespace xg
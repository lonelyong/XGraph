#include <xg/igl/engine/Hint.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(Hint, StateAttribute);

struct Hint::Data {
    HintType  type = HintType(0);
    HintValue val  = DONT_CARE;
};

Hint::Hint()
  : d(new Data())
{}

Hint::Hint(HintType type, HintValue val)
  : d(new Data)
{}

Hint::~Hint()
{ delete d; }

Hint::Type Hint::getType() const
{ return HINT; }

void Hint::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    if (d->type) { funcs->oglHint(d->type, d->val); }
}

} // namespace glr
} // namespace xg
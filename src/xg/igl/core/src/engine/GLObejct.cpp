#include <xg/igl/engine/GLObject.hpp>

#include <unordered_map>
#include <unordered_set>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(GLObject, Object);

struct GLObject::Data {
    std::unordered_map<int, GLuint_t> id_list;
    std::unordered_set<int>           dirty_list;
};

GLObject::GLObject()
  : d(new Data())
{}

GLObject::~GLObject()
{ delete d; }

GLuint_t GLObject::getId(State& state) const
{
    auto ctx_id = state.getContext()->getId();
    if (d->id_list.contains(ctx_id)) { return d->id_list[ctx_id]; }
    return 0;
}

bool GLObject::isCreated(State& state) const
{
    auto ctx_id = state.getContext()->getId();
    return d->id_list.contains(ctx_id);
}

void GLObject::dirty()
{
    d->dirty_list.clear();
    for (auto& kv : d->id_list) { d->dirty_list.insert(kv.first); }
}

bool GLObject::isDirty(State& state) const
{
    auto ctx_id = state.getContext()->getId();
    return d->dirty_list.contains(ctx_id);
}

GLsizei_t GLObject::getNumInstances() const
{ return d->id_list.size(); }

bool GLObject::create(State& state)
{
    if (isCreated(state))
        return true;
    auto id     = onCreate(state);
    auto ctx_id = state.getContext()->getId();
    d->id_list.insert({ ctx_id, id });
    state.attachGLObject(this);
    return true;
}

bool GLObject::update(State& state)
{
    auto ctx_id = state.getContext()->getId();
    if (isDirty(state)) {
        if (onUpdate(state)) {
            d->dirty_list.erase(ctx_id);
            return true;
        }
        return false;
    }
    return true;
}

bool GLObject::release(State& state)
{
    if (isCreated(state)) {
        if (onRelease(state)) {
            auto ctx_id = state.getContext()->getId();
            d->id_list.erase(ctx_id);
            d->dirty_list.erase(ctx_id);
            state.detachGLObject(this);
            return true;
        }
        return false;
    }
    return true;
}

} // namespace glr
} // namespace xg
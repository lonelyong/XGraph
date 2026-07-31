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

GLObject::GLObject() = default;

GLObject::~GLObject() = default;

GLuint_t GLObject::getId(State& state) const
{
    auto ctx_id = state.getContext()->getId();
    if (id_list_.contains(ctx_id)) { return id_list_.at(ctx_id); }
    return 0;
}

bool GLObject::isCreated(State& state) const
{
    auto ctx_id = state.getContext()->getId();
    return id_list_.contains(ctx_id);
}

void GLObject::dirty()
{
    dirty_list_.clear();
    for (auto& kv : id_list_) { dirty_list_.insert(kv.first); }
}

bool GLObject::isDirty(State& state) const
{
    auto ctx_id = state.getContext()->getId();
    return dirty_list_.contains(ctx_id);
}

bool GLObject::create(State& state)
{
    if (isCreated(state))
        return true;
    auto id = onCreate(state);
    if (0 == id)
        return false;
    auto ctx_id = state.getContext()->getId();
    id_list_.insert({ ctx_id, id });
    state.attachGLObject(this);
    return true;
}

bool GLObject::update(State& state)
{
    auto ctx_id = state.getContext()->getId();
    if (isDirty(state)) {
        if (onUpdate(state)) {
            dirty_list_.erase(ctx_id);
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
            id_list_.erase(ctx_id);
            dirty_list_.erase(ctx_id);
            state.detachGLObject(this);
            return true;
        }
        return false;
    }
    return true;
}

} // namespace glr
} // namespace xg
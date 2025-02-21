#include <vkr/engine/State.h>

#include <set>

#include <vine/core/Ptr.h>

#include <vkr/engine/Camera.h>
#include <vkr/engine/VKObject.h>
#include <vkr/engine/GraphicContext.h>
#include <vkr/engine/Renderer.h>
#include <vkr/engine/Shader.h>
#include <vkr/engine/StateSet.h>

namespace vkr {
namespace {
struct StateData {
    vine::RefPtr<GraphicContext> ctx            = nullptr;
    vine::RefPtr<Shader>         current_shader = nullptr;

    std::set<vine::RefPtr<VKObject>> gl_objs;

    bool use_mvp_uniforms = true;
};
} // namespace

VI_OBJECT_META_IMPL(State, Object);

struct State::Data : public StateData {};

State::State(GraphicContext* ctx)
  : d(new Data()) {
    d->ctx = ctx;
}

State::~State() {
    delete d;
}

GraphicContext* State::getContext() const {
    return d->ctx.get();
}

Shader* State::getCurrentShader() const {
    return d->current_shader.get();
}

void State::applyShader(StateSet* ss) {
    d->current_shader = ss->getShader();
    if (d->current_shader.get()) {
        d->current_shader->use(*this);

        if (d->use_mvp_uniforms) {
        }
    }
}

void State::applyAttributes(StateSet* ss) {
    auto nb_attrs = ss->getNbAttributes();
    for (size_t i = 0; i < nb_attrs; i++) {
        ss->getAttributeAt(i)->apply(*this);
    }
}

void State::restoreAttributes(StateSet* ss) {
    auto nb_attrs = ss->getNbAttributes();
    for (size_t i = 0; i < nb_attrs; i++) {
        ss->getAttributeAt(i)->restore(*this);
    }
}

void State::attachGLObject(VKObject* obj) {
    if (!d->gl_objs.contains(obj)) {
        d->gl_objs.insert(obj);
    }
}

void State::detachGLObject(VKObject* obj) {
    d->gl_objs.erase(obj);
}

void State::releaseGLObjects() {
    while (!d->gl_objs.empty()) {
        d->gl_objs.begin()->get()->release(*this);
    }
}

void State::setUseMvpUniforms(bool val) {
    d->use_mvp_uniforms = val;
}

bool State::getUseMvpUniforms() const {
    return d->use_mvp_uniforms;
}

void State::save() {

}

void State::restore() {

}
} // namespace vkr
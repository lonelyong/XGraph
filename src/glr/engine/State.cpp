#include <glr/engine/State.h>

#include <set>

#include <vine/core/Ptr.h>

#include <glr/engine/Camera.h>
#include <glr/engine/GLObject.h>
#include <glr/engine/GraphicContext.h>
#include <glr/engine/Renderer.h>
#include <glr/engine/Shader.h>
#include <glr/engine/StateSet.h>

namespace glr {
namespace {
struct StateData {
    vine::RefPtr<GraphicContext> ctx            = nullptr;
    vine::RefPtr<Shader>         current_shader = nullptr;

    std::set<vine::RefPtr<GLObject>> gl_objs;

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

void State::attachGLObject(GLObject* obj) {
    if (!d->gl_objs.contains(obj)) {
        d->gl_objs.insert(obj);
    }
}

void State::detachGLObject(GLObject* obj) {
    d->gl_objs.erase(obj);
}

void State::releaseGLObjects() {
    d->ctx->makeCurrent();
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
} // namespace glr
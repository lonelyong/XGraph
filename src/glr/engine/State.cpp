#include <glr/engine/State.h>

#include <map>
#include <set>
#include <stack>
#include <vector>

#include <vine/core/Ptr.h>

#include <glr/engine/Camera.h>
#include <glr/engine/GLObject.h>
#include <glr/engine/GraphicContext.h>
#include <glr/engine/Program.h>
#include <glr/engine/Renderer.h>
#include <glr/engine/StateAttribute.h>
#include <glr/engine/StateSet.h>
#include <glr/engine/Uniform.h>

namespace glr {
namespace {
struct StateData {
    vine::RefPtr<GraphicContext>       ctx;
    vine::RefPtr<StateSet>             default_stateset;
    std::stack<vine::RefPtr<Program>>  progs;
    std::stack<vine::RefPtr<StateSet>> statesets;
    std::stack<vine::RefPtr<Camera>>   cameras;
    std::stack<Mat4d>                  model_matrices;
    std::set<vine::RefPtr<GLObject>>   gl_objs;

    bool use_mvp_uniforms   = true;
    bool use_state_uniforms = true;

    vine::RefPtr<Uniform> xg_is_lighting_enabled;
    vine::RefPtr<Uniform> xg_matrix_m;
    vine::RefPtr<Uniform> xg_matrix_v;
    vine::RefPtr<Uniform> xg_matrix_v_inv;
    vine::RefPtr<Uniform> xg_matrix_mv;
    vine::RefPtr<Uniform> xg_matrix_mvp;
    vine::RefPtr<Uniform> xg_view_dir;
};
} // namespace

VI_OBJECT_META_IMPL(State, Object);

struct State::Data : public StateData {};

State::State(GraphicContext* ctx)
  : d(new Data()) {
    d->ctx              = ctx;
    d->default_stateset = new StateSet();
    d->statesets.push(d->default_stateset);

    d->xg_is_lighting_enabled = new Uniform("xg_is_lighting_enabled", true);
    d->xg_matrix_m            = new Uniform("xg_matrix_m", Mat4d());
    d->xg_matrix_v            = new Uniform("xg_matrix_v", Mat4d());
    d->xg_matrix_v_inv        = new Uniform("xg_matrix_v_inv", Mat4d());
    d->xg_matrix_mv           = new Uniform("xg_matrix_mv", Mat4d());
    d->xg_matrix_mvp          = new Uniform("xg_matrix_mvp", Mat4d());
    d->xg_view_dir            = new Uniform("xg_view_dir", Vec3f());

    d->default_stateset->setAttribute(d->xg_is_lighting_enabled.get());
    d->default_stateset->setAttribute(d->xg_matrix_m.get());
    d->default_stateset->setAttribute(d->xg_matrix_v.get());
    d->default_stateset->setAttribute(d->xg_matrix_v_inv.get());
    d->default_stateset->setAttribute(d->xg_matrix_mv.get());
    d->default_stateset->setAttribute(d->xg_matrix_mvp.get());
    d->default_stateset->setAttribute(d->xg_view_dir.get());
}

State::~State() {
    delete d;
}

GraphicContext* State::getContext() const {
    return d->ctx.get();
}

Program* State::getCurrentProgram() const {
    if (d->progs.empty()) return nullptr;
    return d->progs.top().get();
}

Camera* State::getCurrentCamera() const {
    if (d->cameras.empty()) return nullptr;
    return d->cameras.top().get();
}

void State::pushCamera(Camera* cam) {
    if (cam) {
        d->cameras.push(cam);
        cam->apply();
        updateMvpUniforms();
    }
}

void State::popCamera(Camera* cam) {
    if (!d->cameras.empty() && d->cameras.top() == cam) d->cameras.pop();
}

void State::pushModelMatrix(const Mat4d& m) {
    d->model_matrices.push(m);
    updateMvpUniforms();
}

void State::popModelMatrix() {
    d->model_matrices.pop();
}

void State::pushStateSet(StateSet* ss) {
    if (ss) {
        d->statesets.push(ss);
        auto shader = ss->getShader();
        if (shader) {
            shader->use(*this);
            d->progs.push(shader);
        }
    }
}

void State::popStateSet(StateSet* ss) {
    if (!ss) return;
    if (d->statesets.empty() || d->statesets.top() != ss) return;

    auto shader = ss->getShader();
    if (shader) {
        d->progs.pop();
    }

    d->statesets.pop();

    // auto nb_attrs = ss->getNbAttributes();

    // for (size_t i = 0; i < nb_attrs; i++) {
    //     ss->getAttributeAt(i)->restore(*this);
    // }
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
    if (val == d->use_mvp_uniforms) return;
    d->use_mvp_uniforms = val;
    if (val) {
        d->default_stateset->setAttribute(d->xg_matrix_m.get());
        d->default_stateset->setAttribute(d->xg_matrix_v.get());
        d->default_stateset->setAttribute(d->xg_matrix_v_inv.get());
        d->default_stateset->setAttribute(d->xg_matrix_mv.get());
        d->default_stateset->setAttribute(d->xg_matrix_mvp.get());
        d->default_stateset->setAttribute(d->xg_view_dir.get());
    }
    else {
        d->default_stateset->removeAttribute(d->xg_matrix_m.get());
        d->default_stateset->removeAttribute(d->xg_matrix_v.get());
        d->default_stateset->removeAttribute(d->xg_matrix_v_inv.get());
        d->default_stateset->removeAttribute(d->xg_matrix_mv.get());
        d->default_stateset->removeAttribute(d->xg_matrix_mvp.get());
        d->default_stateset->removeAttribute(d->xg_view_dir.get());
    }
}

bool State::getUseMvpUniforms() const {
    return d->use_mvp_uniforms;
}

void State::setUseStateUniforms(bool val) {
    if (val == d->use_state_uniforms) return;
    d->use_state_uniforms = val;
    if (val)
        d->default_stateset->setAttribute(d->xg_is_lighting_enabled.get());
    else
        d->default_stateset->removeAttribute(d->xg_is_lighting_enabled.get());
}

bool State::getUseStateUniforms() const {
    return d->use_state_uniforms;
}

StateSet* State::getDefaultStateSet() const {
    return d->default_stateset.get();
}

void State::updateMvpUniforms() {
    auto cur_shader = getCurrentProgram();
    auto cur_cam    = getCurrentCamera();
    if (cur_shader && cur_cam && getUseMvpUniforms()) {
        auto matrix_v     = cur_cam->getViewMatrix();
        auto matrix_v_inv = glm::inverse(matrix_v);
        auto matrix_p     = cur_cam->getProjectionMatrix();
        auto matrix_vp    = matrix_p * matrix_v;
        auto view_dir     = cur_cam->getViewDir();

        auto model_mats = d->model_matrices;

        Mat4d matrix_m(1.0);
        while (!model_mats.empty()) {
            matrix_m = matrix_m * d->model_matrices.top();
            model_mats.pop();
        }

        d->xg_matrix_m->setValue(matrix_m);
        d->xg_matrix_v->setValue(matrix_v);
        d->xg_matrix_v_inv->setValue(glm::inverse(matrix_v));
        d->xg_matrix_mv->setValue(matrix_v * matrix_m);
        d->xg_matrix_mvp->setValue(matrix_vp * matrix_m);
        d->xg_view_dir->setValue(Vec3f(view_dir));
    }
}

void State::apply() {
    auto                   sss = d->statesets;
    std::vector<StateSet*> sss_;

    while (!sss.empty()) {
        sss_.push_back(sss.top().get());
        sss.pop();
    }

    struct CStrCmp {
        bool operator()(const char* a, const char* b) const { return std::strcmp(a, b) < 0; }
    };

    std::map<StateAttribute::Type, StateAttribute*> attrs;
    std::map<const char*, StateAttribute*, CStrCmp> named_attrs;

    for (auto iter = sss_.rbegin(); iter != sss_.rend(); ++iter) {
        for (size_t i = 0; i < (*iter)->getNbAttributes(); i++) {
            auto        attr      = (*iter)->getAttributeAt(i);
            auto        attr_type = attr->getType();
            const char* name      = nullptr;
            if (attr->isKindOf(UniformBase::desc())) {
                name = vine::obj_cast<UniformBase>(attr)->getName().data();
            }

            if (name) {
                named_attrs[name] = attr;
            }
            else {
                attrs[attr_type] = attr;
            }
        }
    }

    for (auto& kv : attrs) {
        kv.second->apply(*this);
    }
    for (auto& kv : named_attrs) {
        kv.second->apply(*this);
    }
}
} // namespace glr
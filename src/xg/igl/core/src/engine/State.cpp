#include <xg/igl/engine/State.hpp>

#include <cstring>
#include <map>
#include <set>
#include <stack>
#include <vector>

#include <vine/Ptr.hpp>

#include <xg/igl/engine/Camera.hpp>
#include <xg/igl/engine/GLObject.hpp>
#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/Program.hpp>
#include <xg/igl/engine/Renderer.hpp>
#include <xg/igl/engine/StateAttribute.hpp>
#include <xg/igl/engine/StateSet.hpp>
#include <xg/igl/engine/Uniform.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(State, Object);

State::State(GraphicContext* ctx)
{
    ctx_              = ctx;
    default_stateset_ = new StateSet();
    statesets_.push(default_stateset_);

    xg_is_lighting_enabled_ = new Uniform("xg_is_lighting_enabled", true);
    xg_matrix_m_            = new Uniform("xg_matrix_m", Mat4d());
    xg_matrix_v_            = new Uniform("xg_matrix_v", Mat4d());
    xg_matrix_v_inv_        = new Uniform("xg_matrix_v_inv", Mat4d());
    xg_matrix_mv_           = new Uniform("xg_matrix_mv", Mat4d());
    xg_matrix_mvp_          = new Uniform("xg_matrix_mvp", Mat4d());
    xg_view_dir_            = new Uniform("xg_view_dir", Vec3f());

    default_stateset_->setAttribute(xg_is_lighting_enabled_.get());
    default_stateset_->setAttribute(xg_matrix_m_.get());
    default_stateset_->setAttribute(xg_matrix_v_.get());
    default_stateset_->setAttribute(xg_matrix_v_inv_.get());
    default_stateset_->setAttribute(xg_matrix_mv_.get());
    default_stateset_->setAttribute(xg_matrix_mvp_.get());
    default_stateset_->setAttribute(xg_view_dir_.get());
}

State::~State() = default;

Program* State::getCurrentProgram() const
{
    if (progs_.empty())
        return nullptr;
    return progs_.top().get();
}

Camera* State::getCurrentCamera() const
{
    if (cameras_.empty())
        return nullptr;
    return cameras_.top().get();
}

void State::pushCamera(Camera* cam)
{
    if (cam) {
        cameras_.push(cam);
        cam->apply(*this);
        updateMvpUniforms();
    }
}

void State::popCamera(Camera* cam)
{
    if (!cameras_.empty() && cameras_.top() == cam)
        cameras_.pop();
}

void State::pushModelMatrix(const Mat4d& m)
{
    model_matrices_.push(m);
    updateMvpUniforms();
}

void State::popModelMatrix()
{ model_matrices_.pop(); }

void State::pushStateSet(StateSet* ss)
{
    if (ss) {
        statesets_.push(ss);
        auto shader = ss->getShader();
        if (shader) {
            shader->use(*this);
            progs_.push(shader);
        }
    }
}

void State::popStateSet(StateSet* ss)
{
    if (!ss)
        return;
    if (statesets_.empty() || statesets_.top() != ss)
        return;

    auto shader = ss->getShader();
    if (shader) { progs_.pop(); }

    statesets_.pop();

    // auto nb_attrs = ss->getNumAttributes();

    // for (size_t i = 0; i < nb_attrs; i++) {
    //     ss->getAttributeAt(i)->restore(*this);
    // }
}

void State::attachGLObject(GLObject* obj)
{
    if (!gl_objs_.contains(obj)) { gl_objs_.insert(obj); }
}

void State::detachGLObject(GLObject* obj)
{ gl_objs_.erase(obj); }

void State::releaseGLObjects()
{
    ctx_->makeCurrent();
    while (!gl_objs_.empty()) { gl_objs_.begin()->get()->release(*this); }
}

void State::setUseMvpUniforms(bool val)
{
    if (val == use_mvp_uniforms_)
        return;
    use_mvp_uniforms_ = val;
    if (val) {
        default_stateset_->setAttribute(xg_matrix_m_.get());
        default_stateset_->setAttribute(xg_matrix_v_.get());
        default_stateset_->setAttribute(xg_matrix_v_inv_.get());
        default_stateset_->setAttribute(xg_matrix_mv_.get());
        default_stateset_->setAttribute(xg_matrix_mvp_.get());
        default_stateset_->setAttribute(xg_view_dir_.get());
    }
    else {
        default_stateset_->removeAttribute(xg_matrix_m_.get());
        default_stateset_->removeAttribute(xg_matrix_v_.get());
        default_stateset_->removeAttribute(xg_matrix_v_inv_.get());
        default_stateset_->removeAttribute(xg_matrix_mv_.get());
        default_stateset_->removeAttribute(xg_matrix_mvp_.get());
        default_stateset_->removeAttribute(xg_view_dir_.get());
    }
}

void State::setUseStateUniforms(bool val)
{
    if (val == use_state_uniforms_)
        return;
    use_state_uniforms_ = val;
    if (val)
        default_stateset_->setAttribute(xg_is_lighting_enabled_.get());
    else
        default_stateset_->removeAttribute(xg_is_lighting_enabled_.get());
}

void State::updateMvpUniforms()
{
    auto cur_shader = getCurrentProgram();
    auto cur_cam    = getCurrentCamera();
    if (cur_shader && cur_cam && getUseMvpUniforms()) {
        auto matrix_v     = cur_cam->getViewMatrix();
        auto matrix_v_inv = glm::inverse(matrix_v);
        auto matrix_p     = cur_cam->getProjectionMatrix();
        auto matrix_vp    = matrix_p * matrix_v;
        auto view_dir     = cur_cam->getViewDir();

        auto model_mats = model_matrices_;

        Mat4d matrix_m(1.0);
        while (!model_mats.empty()) {
            matrix_m = matrix_m * model_matrices_.top();
            model_mats.pop();
        }

        xg_matrix_m_->setValue(matrix_m);
        xg_matrix_v_->setValue(matrix_v);
        xg_matrix_v_inv_->setValue(glm::inverse(matrix_v));
        xg_matrix_mv_->setValue(matrix_v * matrix_m);
        xg_matrix_mvp_->setValue(matrix_vp * matrix_m);
        xg_view_dir_->setValue(Vec3f(view_dir));
    }
}

void State::apply()
{
    auto                   sss = statesets_;
    std::vector<StateSet*> sss_;

    while (!sss.empty()) {
        sss_.push_back(sss.top().get());
        sss.pop();
    }

    struct CStrCmp {
        bool operator()(const char* a, const char* b) const
        { return strcmp(a, b) < 0; }
    };

    std::map<StateAttribute::Type, StateAttribute*> attrs;
    std::map<const char*, StateAttribute*, CStrCmp> named_attrs;

    for (auto iter = sss_.rbegin(); iter != sss_.rend(); ++iter) {
        for (size_t i = 0; i < (*iter)->getNumAttributes(); i++) {
            auto        attr      = (*iter)->getAttributeAt(i);
            auto        attr_type = attr->getType();
            const char* name      = nullptr;
            if (attr->isKindOf(UniformBase::desc())) { name = vine::obj_cast<UniformBase>(attr)->getName().data(); }

            if (name) { named_attrs[name] = attr; }
            else {
                attrs[attr_type] = attr;
            }
        }
    }

    for (auto& kv : attrs) { kv.second->apply(*this); }
    for (auto& kv : named_attrs) { kv.second->apply(*this); }
}

} // namespace glr
} // namespace xg
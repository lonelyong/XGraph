#pragma once

#include <xg/igl/glr_global.hpp>

#include <set>
#include <stack>

#include <vine/Ptr.hpp>

#include <xg/igl/engine/Object.hpp>
#include <xg/igl/engine/types.hpp>

namespace xg
{
namespace glr
{

class GLObject;
class Program;
class Camera;
class GraphicContext;
class Renderer;
class StateSet;
class Uniform;

class IGL_CORE_API State : public Object {
    V_OBJECT_META_DECL

    friend class Renderer;

  public:
    State(GraphicContext* ctx);
    virtual ~State();

  public:
    Program*        getCurrentProgram() const;
    Camera*         getCurrentCamera() const;
    GraphicContext* getContext() const { return ctx_.get(); }

    void pushCamera(Camera* cam);
    void popCamera(Camera* cam);

    void pushStateSet(StateSet* ss);
    void popStateSet(StateSet* ss);

    void pushModelMatrix(const Mat4d& m);
    void popModelMatrix();

    void attachGLObject(GLObject* obj);
    void detachGLObject(GLObject* obj);
    void releaseGLObjects();

    bool getUseMvpUniforms() const { return use_mvp_uniforms_; }
    void setUseMvpUniforms(bool val);

    void setUseStateUniforms(bool val);
    bool getUseStateUniforms() const { return use_state_uniforms_; }

    StateSet* getDefaultStateSet() const { return default_stateset_.get(); }

    void updateMvpUniforms();

    void apply();

  private:
    vine::RefPtr<GraphicContext>       ctx_;
    vine::RefPtr<StateSet>             default_stateset_;
    std::stack<vine::RefPtr<Program>>  progs_;
    std::stack<vine::RefPtr<StateSet>> statesets_;
    std::stack<vine::RefPtr<Camera>>   cameras_;
    std::stack<Mat4d>                  model_matrices_;
    std::set<vine::RefPtr<GLObject>>   gl_objs_;

    bool use_mvp_uniforms_   = true;
    bool use_state_uniforms_ = true;

    vine::RefPtr<Uniform> xg_is_lighting_enabled_;
    vine::RefPtr<Uniform> xg_matrix_m_;
    vine::RefPtr<Uniform> xg_matrix_v_;
    vine::RefPtr<Uniform> xg_matrix_v_inv_;
    vine::RefPtr<Uniform> xg_matrix_mv_;
    vine::RefPtr<Uniform> xg_matrix_mvp_;
    vine::RefPtr<Uniform> xg_view_dir_;
};

} // namespace glr
} // namespace xg
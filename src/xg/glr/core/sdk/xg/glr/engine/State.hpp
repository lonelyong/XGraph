#pragma once

#include <xg/glr/glr_global.h>

#include <xg/glr/engine/Object.h>
#include <xg/glr/engine/types.h>

namespace xg {
namespace glr {
class GLObject;
class Program;
class Camera;
class GraphicContext;
class Renderer;
class StateSet;
class GLR_API State : public Object {
    V_OBJECT_META_DECL

    friend class Renderer;

  public:
    State(GraphicContext* ctx);
    virtual ~State();

  public:
    Program*         getCurrentProgram() const;
    Camera*         getCurrentCamera() const;
    GraphicContext* getContext() const;

    // void pushShader(StateSet* ss);
    // void popShader(StateSet* ss);

    void pushCamera(Camera* cam);
    void popCamera(Camera* cam);

    void pushStateSet(StateSet* ss);
    void popStateSet(StateSet* ss);

    void pushModelMatrix(const Mat4d& m);
    void popModelMatrix();

    void attachGLObject(GLObject* obj);
    void detachGLObject(GLObject* obj);
    void releaseGLObjects();

    // xg_matrix_v
    // xg_matrix_mvp...
    bool getUseMvpUniforms() const;
    void setUseMvpUniforms(bool val);

    // xg_is_lighting_enabled
    void setUseStateUniforms(bool val);
    bool getUseStateUniforms() const;

    StateSet* getDefaultStateSet() const;

    void updateMvpUniforms();

    void apply();

  private:
    struct Data; Data* const d;;
};
} // namespace glr
} // namespace xg
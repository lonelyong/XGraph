#pragma once

#include <glr/glrenderer_global.h>

#include <glr/engine/Object.h>
#include <glr/engine/types.h>

namespace glr {
class GLObject;
class Shader;
class Camera;
class GraphicContext;
class Renderer;
class StateSet;
class GLR_API State : public Object {
    VI_OBJECT_META;

    friend class Renderer;

  public:
    State(GraphicContext* ctx);
    virtual ~State();

  public:
    Shader*         getCurrentShader() const;
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

  private:
    VI_OBJECT_DATA;
};
} // namespace glr
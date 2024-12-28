#pragma once

#include <glr/glrenderer_global.h>

#include <glr/engine/Object.h>

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
    GraphicContext* getContext() const;

    void applyShader(StateSet* ss);
    void applyAttributes(StateSet* ss);
    void restoreAttributes(StateSet* ss);

    void attachGLObject(GLObject* obj);
    void detachGLObject(GLObject* obj);
    void releaseGLObjects();

    void setUseMvpUniforms(bool val);
    bool getUseMvpUniforms() const;

    void save();
    void restore();

  private:
    VI_OBJECT_DATA;
};
} // namespace glr
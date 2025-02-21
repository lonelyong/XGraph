#pragma once

#include <vkr/vkrenderer_global.h>

#include <vkr/engine/Object.h>

namespace vkr {
class VKObject;
class Shader;
class Camera;
class GraphicContext;
class Renderer;
class StateSet;
class VKR_API State : public Object {
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

    void attachGLObject(VKObject* obj);
    void detachGLObject(VKObject* obj);
    void releaseGLObjects();

    void setUseMvpUniforms(bool val);
    bool getUseMvpUniforms() const;

    void save();
    void restore();

  private:
    VI_OBJECT_DATA;
};
} // namespace vkr
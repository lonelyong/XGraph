#pragma once

#include <vkr/vkrenderer_global.h>

#include <vkr/engine/Object.h>

namespace vkr {
class Renderer;
class Scene;
class StateSet;

class VKR_API Viewer : public Object {
    VI_OBJECT_META;

  public:
    Viewer();
    virtual ~Viewer();

  public:
    virtual int frame();
    virtual int run();
    void        setMasterRenderer(Renderer* renderer);
    Renderer*   getMasterRenderer() const;
    void        addRenderer(Renderer* renderer);
    int         getNbRenderers() const;
    Renderer*   getRendererAt(int idx) const;
    void        removeRenderer(Renderer* renderer);
    void        clearRenderers();

  private:
    VI_OBJECT_DATA;
};
} // namespace vkr
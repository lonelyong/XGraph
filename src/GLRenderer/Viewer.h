#pragma once

#include "glrenderer_global.h"

#include "Object.h"

namespace glr {
class Renderer;
class Scene;
class StateSet;

class GLRENDERER_API Viewer : public Object {
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
} // namespace glr
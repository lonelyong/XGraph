#pragma once

#include <xg/glr/glr_global.hpp>

#include <xg/glr/engine/Object.hpp>

namespace xg {
namespace glr {
class Renderer;
class Scene;
class StateSet;

class GLR_API Viewer : public Object {
    V_OBJECT_META_DECL

  public:
    Viewer();
    virtual ~Viewer();

  public:
    virtual int frame();
    virtual int run();
    void        setMasterRenderer(Renderer* renderer);
    Renderer*   getMasterRenderer() const;
    void        addRenderer(Renderer* renderer);
    int         getNumRenderers() const;
    Renderer*   getRendererAt(int idx) const;
    void        removeRenderer(Renderer* renderer);
    void        clearRenderers();

  private:
    struct Data; Data* const d;;
};
} // namespace glr
} // namespace xg
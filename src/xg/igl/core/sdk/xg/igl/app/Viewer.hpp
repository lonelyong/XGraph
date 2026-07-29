#pragma once

#include <xg/igl/glr_global.hpp>

#include <xg/igl/engine/Object.hpp>

namespace xg
{
namespace glr
{

class Renderer;
class Scene;
class StateSet;

class IGL_CORE_API Viewer : public Object {
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
    struct Data;
    Data* const d;
    ;
};

} // namespace glr
} // namespace xg
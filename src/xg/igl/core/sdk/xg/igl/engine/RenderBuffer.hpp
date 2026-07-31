#pragma once

#include <xg/igl/glr_global.hpp>

#include <vine/Ptr.hpp>

#include <xg/igl/engine/PixelData.hpp>

namespace xg
{
namespace glr
{

class FrameBufferObject;

class IGL_CORE_API RenderBuffer : public PixelData {

    V_OBJECT_META_DECL

    friend class FrameBufferObject;
    friend void RenderBuffer_set_FrameBuffer(RenderBuffer* rb, FrameBufferObject* fbo);

  public:
    RenderBuffer();

  public:
    FrameBufferObject* getFrameBuffer() const { return fbo_.get(); }

    void setWidth(GLsizei_t w) { w_ = w; }

    void setHeight(GLsizei_t h) { h_ = h; }

    GLsizei_t getWidth() const { return w_; }

    GLsizei_t getHeight() const { return h_; }

  protected:
    virtual GLuint_t onCreate(State& state) override;
    virtual bool     onRelease(State& state) override;
    virtual bool     onUnbind(State& state) override;
    virtual bool     onUpdate(State& state) override;
    virtual bool     onBind(State& state) override;

  private:
    vine::RefPtr<FrameBufferObject> fbo_;
    GLuint_t                        w_ = 1920;
    GLuint_t                        h_ = 1080;
};

} // namespace glr
} // namespace xg
#pragma once

#include <xg/glr/glr_global.h>

#include <xg/glr/engine/PixelData.h>

namespace glr {

class FrameBufferObject;

class GLR_API RenderBuffer : public PixelData {

    V_OBJECT_META_DECL

    friend class FrameBufferObject;

  public:
    RenderBuffer();

  public:
    FrameBufferObject* getFrameBuffer() const;

    void setWidth(GLsizei_t w);

    void setHeight(GLsizei_t h);

    GLsizei_t getWidth() const;

    GLsizei_t getHeight() const;

  protected:
    virtual GLuint_t onCreate(State& state) override;
    virtual bool     onRelease(State& state) override;
    virtual bool     onUnbind(State& state) override;
    virtual bool     onUpdate(State& state) override;
    virtual bool     onBind(State& state) override;

  private:
    struct Data; Data* const d;;
};
} // namespace glr
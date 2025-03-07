#pragma once

#include <glr/glr_global.h>

#include <glr/engine/PixelData.h>

namespace glr {

class FrameBufferObject;

class GLR_API RenderBuffer : public PixelData {

    VI_OBJECT_META;

    friend class FrameBufferObject;

  public:
    RenderBuffer();

  public:
    FrameBufferObject* getFrameBuffer() const;

    void setWidth(GLsizei w);

    void setHeight(GLsizei h);

    GLsizei getWidth() const;

    GLsizei getHeight() const;

  protected:
    virtual GLuint onCreate(State& state) override;
    virtual bool   onRelease(State& state) override;
    virtual bool   onUnbind(State& state) override;
    virtual bool   onUpdate(State& state) override;
    virtual bool   onBind(State& state) override;

  private:
    VI_OBJECT_DATA;
};
} // namespace glr
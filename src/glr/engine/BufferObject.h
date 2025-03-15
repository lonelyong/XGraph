#pragma once

#include <glr/glr_global.h>

#include <glr/engine/BindableObject.h>

namespace glr {
class GLR_API BufferObject : public BindableObject {
    VI_OBJECT_META;

  public:
    enum Target
    {
        ARRAY_BUFFER          = HGL_ARRAY_BUFFER,
        ELEMENT_ARRAY_BUFFER  = HGL_ELEMENT_ARRAY_BUFFER,
        PIXEL_PACK_BUFFER     = HGL_PIXEL_PACK_BUFFER,
        PIXEL_UNPACK_BUFFER   = HGL_PIXEL_UNPACK_BUFFER,
        UNIFORM_BUFFER        = HGL_UNIFORM_BUFFER,
        SHADER_STORAGE_BUFFER = HGL_SHADER_STORAGE_BUFFER,
        DRAW_INDIRECT_BUFFER  = HGL_DRAW_INDIRECT_BUFFER
    };

    enum Usage
    {
        STREAM_DRAW  = HGL_STREAM_DRAW,
        STREAM_READ  = HGL_STREAM_READ,
        STREAM_COPY  = HGL_STREAM_COPY,
        STATIC_DRAW  = HGL_STATIC_DRAW,
        STATIC_READ  = HGL_STATIC_READ,
        STATIC_COPY  = HGL_STATIC_COPY,
        DYNAMIC_DRAW = HGL_DYNAMIC_DRAW,
        DYNAMIC_READ = HGL_DYNAMIC_READ,
        DYNAMIC_COPY = HGL_DYNAMIC_COPY,
    };

  public:
    BufferObject();

  public:
    virtual Target getTarget() const = 0;
    virtual Usage  getUsage() const  = 0;

    static GLenum_t getBindingOfTarget(Target target);

  protected:
    virtual GLuint_t onCreate(State& state) override;
    virtual bool     onRelease(State& state) override;
    virtual bool     onBind(State& state) override;
    virtual bool     onUnbind(State& state) override;

  private:
    VI_OBJECT_DATA;
};
} // namespace glr
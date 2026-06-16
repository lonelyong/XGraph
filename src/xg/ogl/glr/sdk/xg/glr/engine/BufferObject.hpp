#pragma once

#include <xg/glr/glr_global.h>

#include <xg/glr/engine/BindableObject.h>

namespace glr {
class GLR_API BufferObject : public BindableObject {
    V_OBJECT_META_DECL

  public:
    enum Target
    {
        ARRAY_BUFFER          = IGL_ARRAY_BUFFER,
        ELEMENT_ARRAY_BUFFER  = IGL_ELEMENT_ARRAY_BUFFER,
        PIXEL_PACK_BUFFER     = IGL_PIXEL_PACK_BUFFER,
        PIXEL_UNPACK_BUFFER   = IGL_PIXEL_UNPACK_BUFFER,
        UNIFORM_BUFFER        = IGL_UNIFORM_BUFFER,
        SHADER_STORAGE_BUFFER = IGL_SHADER_STORAGE_BUFFER,
        DRAW_INDIRECT_BUFFER  = IGL_DRAW_INDIRECT_BUFFER
    };

    enum Usage
    {
        STREAM_DRAW  = IGL_STREAM_DRAW,
        STREAM_READ  = IGL_STREAM_READ,
        STREAM_COPY  = IGL_STREAM_COPY,
        STATIC_DRAW  = IGL_STATIC_DRAW,
        STATIC_READ  = IGL_STATIC_READ,
        STATIC_COPY  = IGL_STATIC_COPY,
        DYNAMIC_DRAW = IGL_DYNAMIC_DRAW,
        DYNAMIC_READ = IGL_DYNAMIC_READ,
        DYNAMIC_COPY = IGL_DYNAMIC_COPY,
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
    struct Data; Data* const d;;
};
} // namespace glr
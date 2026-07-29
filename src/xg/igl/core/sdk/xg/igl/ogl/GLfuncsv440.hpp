#pragma once

#include <xg/igl/ogl/GLfuncsv430.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API GLfuncsv440 : public GLfuncsv430 {

  public:
    typedef void(APIENTRYP PFNGLBUFFERSTORAGEPROC)(GLenum_t target, GLsizeiptr size, const void* data, GLbitfield_t flags);
    PFNGLBUFFERSTORAGEPROC oglBufferStorage;

    typedef void(APIENTRYP PFNGLCLEARTEXIMAGEPROC)(GLuint_t texture, GLint_t level, GLenum_t format, GLenum_t type, const void* data);
    PFNGLCLEARTEXIMAGEPROC oglClearTexImage;

    typedef void(APIENTRYP PFNGLCLEARTEXSUBIMAGEPROC)(GLuint_t    texture,
                                                      GLint_t     level,
                                                      GLint_t     xoffset,
                                                      GLint_t     yoffset,
                                                      GLint_t     zoffset,
                                                      GLsizei_t   width,
                                                      GLsizei_t   height,
                                                      GLsizei_t   depth,
                                                      GLenum_t    format,
                                                      GLenum_t    type,
                                                      const void* data);
    PFNGLCLEARTEXSUBIMAGEPROC oglClearTexSubImage;

    typedef void(APIENTRYP PFNGLBINDBUFFERSBASEPROC)(GLenum_t target, GLuint_t first, GLsizei_t count, const GLuint_t* buffers);
    PFNGLBINDBUFFERSBASEPROC oglBindBuffersBase;

    typedef void(APIENTRYP PFNGLBINDBUFFERSRANGEPROC)(GLenum_t          target,
                                                      GLuint_t          first,
                                                      GLsizei_t         count,
                                                      const GLuint_t*   buffers,
                                                      const GLintptr*   offsets,
                                                      const GLsizeiptr* sizes);
    PFNGLBINDBUFFERSRANGEPROC oglBindBuffersRange;

    typedef void(APIENTRYP PFNGLBINDTEXTURESPROC)(GLuint_t first, GLsizei_t count, const GLuint_t* textures);
    PFNGLBINDTEXTURESPROC oglBindTextures;

    typedef void(APIENTRYP PFNGLBINDSAMPLERSPROC)(GLuint_t first, GLsizei_t count, const GLuint_t* samplers);
    PFNGLBINDSAMPLERSPROC oglBindSamplers;

    typedef void(APIENTRYP PFNGLBINDIMAGETEXTURESPROC)(GLuint_t first, GLsizei_t count, const GLuint_t* textures);
    PFNGLBINDIMAGETEXTURESPROC oglBindImageTextures;

    typedef void(
        APIENTRYP PFNGLBINDVERTEXBUFFERSPROC)(GLuint_t first, GLsizei_t count, const GLuint_t* buffers, const GLintptr* offsets, const GLsizei_t* strides);
    PFNGLBINDVERTEXBUFFERSPROC oglBindVertexBuffers;

  public:
    GLfuncsv440();

  protected:
    virtual void loadFuncs(Loader loader) override;
};

} // namespace glr
} // namespace xg
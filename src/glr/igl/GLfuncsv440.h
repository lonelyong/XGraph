#pragma once

#include <glr/igl/GLfuncsv430.h>

namespace glr {
class GLR_API GLfuncsv440 : public GLfuncsv430 {

  public:
    typedef void(APIENTRYP PFNGLBUFFERSTORAGEPROC)(GLenum_t target, GLsizeiptr size, const void* data, GLbitfield_t flags);
    PFNGLBUFFERSTORAGEPROC iglBufferStorage;

    typedef void(
        APIENTRYP PFNGLCLEARTEXIMAGEPROC)(GLuint_t texture, GLint_t level, GLenum_t format, GLenum_t type, const void* data);
    PFNGLCLEARTEXIMAGEPROC iglClearTexImage;

    typedef void(APIENTRYP PFNGLCLEARTEXSUBIMAGEPROC)(GLuint_t      texture,
                                                      GLint_t       level,
                                                      GLint_t       xoffset,
                                                      GLint_t       yoffset,
                                                      GLint_t       zoffset,
                                                      GLsizei_t     width,
                                                      GLsizei_t     height,
                                                      GLsizei_t     depth,
                                                      GLenum_t      format,
                                                      GLenum_t      type,
                                                      const void* data);
    PFNGLCLEARTEXSUBIMAGEPROC iglClearTexSubImage;

    typedef void(APIENTRYP PFNGLBINDBUFFERSBASEPROC)(GLenum_t target, GLuint_t first, GLsizei_t count, const GLuint_t* buffers);
    PFNGLBINDBUFFERSBASEPROC iglBindBuffersBase;

    typedef void(APIENTRYP PFNGLBINDBUFFERSRANGEPROC)(GLenum_t            target,
                                                      GLuint_t            first,
                                                      GLsizei_t           count,
                                                      const GLuint_t*     buffers,
                                                      const GLintptr*   offsets,
                                                      const GLsizeiptr* sizes);
    PFNGLBINDBUFFERSRANGEPROC iglBindBuffersRange;

    typedef void(APIENTRYP PFNGLBINDTEXTURESPROC)(GLuint_t first, GLsizei_t count, const GLuint_t* textures);
    PFNGLBINDTEXTURESPROC iglBindTextures;

    typedef void(APIENTRYP PFNGLBINDSAMPLERSPROC)(GLuint_t first, GLsizei_t count, const GLuint_t* samplers);
    PFNGLBINDSAMPLERSPROC iglBindSamplers;

    typedef void(APIENTRYP PFNGLBINDIMAGETEXTURESPROC)(GLuint_t first, GLsizei_t count, const GLuint_t* textures);
    PFNGLBINDIMAGETEXTURESPROC iglBindImageTextures;

    typedef void(APIENTRYP PFNGLBINDVERTEXBUFFERSPROC)(GLuint_t          first,
                                                       GLsizei_t         count,
                                                       const GLuint_t*   buffers,
                                                       const GLintptr* offsets,
                                                       const GLsizei_t*  strides);
    PFNGLBINDVERTEXBUFFERSPROC iglBindVertexBuffers;

  public:
    GLfuncsv440();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
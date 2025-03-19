#pragma once

#include <glr/igl/GLfuncsv430.h>

namespace glr {
class GLR_API GLfuncsv440 : public GLfuncsv430 {
  public:
    typedef void(APIENTRYP PFNGLBUFFERSTORAGEPROC)(GLenum target, GLsizeiptr size, const void* data, GLbitfield flags);
    PFNGLBUFFERSTORAGEPROC glBufferStorage;

    typedef void(
        APIENTRYP PFNGLCLEARTEXIMAGEPROC)(GLuint texture, GLint level, GLenum format, GLenum type, const void* data);
    PFNGLCLEARTEXIMAGEPROC glClearTexImage;

    typedef void(APIENTRYP PFNGLCLEARTEXSUBIMAGEPROC)(GLuint      texture,
                                                      GLint       level,
                                                      GLint       xoffset,
                                                      GLint       yoffset,
                                                      GLint       zoffset,
                                                      GLsizei     width,
                                                      GLsizei     height,
                                                      GLsizei     depth,
                                                      GLenum      format,
                                                      GLenum      type,
                                                      const void* data);
    PFNGLCLEARTEXSUBIMAGEPROC glClearTexSubImage;

    typedef void(APIENTRYP PFNGLBINDBUFFERSBASEPROC)(GLenum target, GLuint first, GLsizei count, const GLuint* buffers);
    PFNGLBINDBUFFERSBASEPROC glBindBuffersBase;

    typedef void(APIENTRYP PFNGLBINDBUFFERSRANGEPROC)(GLenum            target,
                                                      GLuint            first,
                                                      GLsizei           count,
                                                      const GLuint*     buffers,
                                                      const GLintptr*   offsets,
                                                      const GLsizeiptr* sizes);
    PFNGLBINDBUFFERSRANGEPROC glBindBuffersRange;

    typedef void(APIENTRYP PFNGLBINDTEXTURESPROC)(GLuint first, GLsizei count, const GLuint* textures);
    PFNGLBINDTEXTURESPROC glBindTextures;

    typedef void(APIENTRYP PFNGLBINDSAMPLERSPROC)(GLuint first, GLsizei count, const GLuint* samplers);
    PFNGLBINDSAMPLERSPROC glBindSamplers;

    typedef void(APIENTRYP PFNGLBINDIMAGETEXTURESPROC)(GLuint first, GLsizei count, const GLuint* textures);
    PFNGLBINDIMAGETEXTURESPROC glBindImageTextures;

    typedef void(APIENTRYP PFNGLBINDVERTEXBUFFERSPROC)(GLuint          first,
                                                       GLsizei         count,
                                                       const GLuint*   buffers,
                                                       const GLintptr* offsets,
                                                       const GLsizei*  strides);
    PFNGLBINDVERTEXBUFFERSPROC glBindVertexBuffers;

  public:
    GLfuncsv440();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
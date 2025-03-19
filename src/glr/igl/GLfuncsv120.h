#pragma once

#include <glr/igl/GLfuncsv110.h>

namespace glr {
class GLR_API GLfuncsv120 : public GLfuncsv110 {
    VI_OBJECT_META;

  public:
    typedef void(APIENTRYP PFNGLDRAWRANGEELEMENTSPROC)(GLenum      mode,
                                                       GLuint      start,
                                                       GLuint      end,
                                                       GLsizei     count,
                                                       GLenum      type,
                                                       const void* indices);
    PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements;

    typedef void(APIENTRYP PFNGLTEXIMAGE3DPROC)(GLenum      target,
                                                GLint       level,
                                                GLint       internalformat,
                                                GLsizei     width,
                                                GLsizei     height,
                                                GLsizei     depth,
                                                GLint       border,
                                                GLenum      format,
                                                GLenum      type,
                                                const void* pixels);
    PFNGLTEXIMAGE3DPROC glTexImage3D;

    typedef void(APIENTRYP PFNGLTEXSUBIMAGE3DPROC)(GLenum      target,
                                                   GLint       level,
                                                   GLint       xoffset,
                                                   GLint       yoffset,
                                                   GLint       zoffset,
                                                   GLsizei     width,
                                                   GLsizei     height,
                                                   GLsizei     depth,
                                                   GLenum      format,
                                                   GLenum      type,
                                                   const void* pixels);
    PFNGLTEXSUBIMAGE3DPROC glTexSubImage3D;

    typedef void(APIENTRYP PFNGLCOPYTEXSUBIMAGE3DPROC)(GLenum  target,
                                                       GLint   level,
                                                       GLint   xoffset,
                                                       GLint   yoffset,
                                                       GLint   zoffset,
                                                       GLint   x,
                                                       GLint   y,
                                                       GLsizei width,
                                                       GLsizei height);
    PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D;

  public:
    GLfuncsv120();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
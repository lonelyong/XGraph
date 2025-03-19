#pragma once

#include <glr/igl/GLfuncsv100.h>

namespace glr {
class GLR_API GLfuncsv110 : public GLfuncsv100 {
  public:
    typedef void(APIENTRYP PFNGLDRAWARRAYSPROC)(GLenum mode, GLint first, GLsizei count);
    PFNGLDRAWARRAYSPROC glDrawArrays;

    typedef void(APIENTRYP PFNGLDRAWELEMENTSPROC)(GLenum mode, GLsizei count, GLenum type, const void* indices);
    PFNGLDRAWELEMENTSPROC glDrawElements;

    typedef void(APIENTRYP PFNGLPOLYGONOFFSETPROC)(GLfloat factor, GLfloat units);
    PFNGLPOLYGONOFFSETPROC glPolygonOffset;

    typedef void(APIENTRYP PFNGLCOPYTEXIMAGE1DPROC)(GLenum  target,
                                                    GLint   level,
                                                    GLenum  internalformat,
                                                    GLint   x,
                                                    GLint   y,
                                                    GLsizei width,
                                                    GLint   border);
    PFNGLCOPYTEXIMAGE1DPROC glCopyTexImage1D;

    typedef void(APIENTRYP PFNGLCOPYTEXIMAGE2DPROC)(GLenum  target,
                                                    GLint   level,
                                                    GLenum  internalformat,
                                                    GLint   x,
                                                    GLint   y,
                                                    GLsizei width,
                                                    GLsizei height,
                                                    GLint   border);
    PFNGLCOPYTEXIMAGE2DPROC glCopyTexImage2D;

    typedef void(APIENTRYP PFNGLCOPYTEXSUBIMAGE1DPROC)(GLenum  target,
                                                       GLint   level,
                                                       GLint   xoffset,
                                                       GLint   x,
                                                       GLint   y,
                                                       GLsizei width);
    PFNGLCOPYTEXSUBIMAGE1DPROC glCopyTexSubImage1D;

    typedef void(APIENTRYP PFNGLCOPYTEXSUBIMAGE2DPROC)(GLenum  target,
                                                       GLint   level,
                                                       GLint   xoffset,
                                                       GLint   yoffset,
                                                       GLint   x,
                                                       GLint   y,
                                                       GLsizei width,
                                                       GLsizei height);
    PFNGLCOPYTEXSUBIMAGE2DPROC glCopyTexSubImage2D;

    typedef void(APIENTRYP PFNGLTEXSUBIMAGE1DPROC)(GLenum      target,
                                                   GLint       level,
                                                   GLint       xoffset,
                                                   GLsizei     width,
                                                   GLenum      format,
                                                   GLenum      type,
                                                   const void* pixels);
    PFNGLTEXSUBIMAGE1DPROC glTexSubImage1D;

    typedef void(APIENTRYP PFNGLTEXSUBIMAGE2DPROC)(GLenum      target,
                                                   GLint       level,
                                                   GLint       xoffset,
                                                   GLint       yoffset,
                                                   GLsizei     width,
                                                   GLsizei     height,
                                                   GLenum      format,
                                                   GLenum      type,
                                                   const void* pixels);
    PFNGLTEXSUBIMAGE2DPROC glTexSubImage2D;

    typedef void(APIENTRYP PFNGLBINDTEXTUREPROC)(GLenum target, GLuint texture);
    PFNGLBINDTEXTUREPROC glBindTexture;

    typedef void(APIENTRYP PFNGLDELETETEXTURESPROC)(GLsizei n, const GLuint* textures);
    PFNGLDELETETEXTURESPROC glDeleteTextures;

    typedef void(APIENTRYP PFNGLGENTEXTURESPROC)(GLsizei n, GLuint* textures);
    PFNGLGENTEXTURESPROC glGenTextures;

    typedef GLboolean(APIENTRYP PFNGLISTEXTUREPROC)(GLuint texture);
    PFNGLISTEXTUREPROC glIsTexture;

  public:
    GLfuncsv110();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
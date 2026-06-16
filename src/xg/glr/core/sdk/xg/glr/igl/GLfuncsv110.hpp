#pragma once

#include <xg/glr/igl/GLfuncsv100.h>

namespace xg {
namespace glr {
class GLR_API GLfuncsv110 : public GLfuncsv100 {

  public:
    typedef void(APIENTRYP PFNGLDRAWARRAYSPROC)(GLenum_t mode, GLint_t first, GLsizei_t count);
    PFNGLDRAWARRAYSPROC iglDrawArrays;

    typedef void(APIENTRYP PFNGLDRAWELEMENTSPROC)(GLenum_t mode, GLsizei_t count, GLenum_t type, const void* indices);
    PFNGLDRAWELEMENTSPROC iglDrawElements;

    typedef void(APIENTRYP PFNGLPOLYGONOFFSETPROC)(GLfloat_t factor, GLfloat_t units);
    PFNGLPOLYGONOFFSETPROC iglPolygonOffset;

    typedef void(APIENTRYP PFNGLCOPYTEXIMAGE1DPROC)(GLenum_t  target,
                                                    GLint_t   level,
                                                    GLenum_t  internalformat,
                                                    GLint_t   x,
                                                    GLint_t   y,
                                                    GLsizei_t width,
                                                    GLint_t   border);
    PFNGLCOPYTEXIMAGE1DPROC iglCopyTexImage1D;

    typedef void(APIENTRYP PFNGLCOPYTEXIMAGE2DPROC)(GLenum_t  target,
                                                    GLint_t   level,
                                                    GLenum_t  internalformat,
                                                    GLint_t   x,
                                                    GLint_t   y,
                                                    GLsizei_t width,
                                                    GLsizei_t height,
                                                    GLint_t   border);
    PFNGLCOPYTEXIMAGE2DPROC iglCopyTexImage2D;

    typedef void(APIENTRYP PFNGLCOPYTEXSUBIMAGE1DPROC)(GLenum_t  target,
                                                       GLint_t   level,
                                                       GLint_t   xoffset,
                                                       GLint_t   x,
                                                       GLint_t   y,
                                                       GLsizei_t width);
    PFNGLCOPYTEXSUBIMAGE1DPROC iglCopyTexSubImage1D;

    typedef void(APIENTRYP PFNGLCOPYTEXSUBIMAGE2DPROC)(GLenum_t  target,
                                                       GLint_t   level,
                                                       GLint_t   xoffset,
                                                       GLint_t   yoffset,
                                                       GLint_t   x,
                                                       GLint_t   y,
                                                       GLsizei_t width,
                                                       GLsizei_t height);
    PFNGLCOPYTEXSUBIMAGE2DPROC iglCopyTexSubImage2D;

    typedef void(APIENTRYP PFNGLTEXSUBIMAGE1DPROC)(GLenum_t      target,
                                                   GLint_t       level,
                                                   GLint_t       xoffset,
                                                   GLsizei_t     width,
                                                   GLenum_t      format,
                                                   GLenum_t      type,
                                                   const void* pixels);
    PFNGLTEXSUBIMAGE1DPROC iglTexSubImage1D;

    typedef void(APIENTRYP PFNGLTEXSUBIMAGE2DPROC)(GLenum_t      target,
                                                   GLint_t       level,
                                                   GLint_t       xoffset,
                                                   GLint_t       yoffset,
                                                   GLsizei_t     width,
                                                   GLsizei_t     height,
                                                   GLenum_t      format,
                                                   GLenum_t      type,
                                                   const void* pixels);
    PFNGLTEXSUBIMAGE2DPROC iglTexSubImage2D;

    typedef void(APIENTRYP PFNGLBINDTEXTUREPROC)(GLenum_t target, GLuint_t texture);
    PFNGLBINDTEXTUREPROC iglBindTexture;

    typedef void(APIENTRYP PFNGLDELETETEXTURESPROC)(GLsizei_t n, const GLuint_t* textures);
    PFNGLDELETETEXTURESPROC iglDeleteTextures;

    typedef void(APIENTRYP PFNGLGENTEXTURESPROC)(GLsizei_t n, GLuint_t* textures);
    PFNGLGENTEXTURESPROC iglGenTextures;

    typedef GLboolean_t(APIENTRYP PFNGLISTEXTUREPROC)(GLuint_t texture);
    PFNGLISTEXTUREPROC iglIsTexture;

  public:
    GLfuncsv110();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
} // namespace xg
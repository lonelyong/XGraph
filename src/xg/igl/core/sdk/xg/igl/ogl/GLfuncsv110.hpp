#pragma once

#include <xg/igl/ogl/GLfuncsv100.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API GLfuncsv110 : public GLfuncsv100 {

  public:
    typedef void(APIENTRYP PFNGLDRAWARRAYSPROC)(GLenum_t mode, GLint_t first, GLsizei_t count);
    PFNGLDRAWARRAYSPROC oglDrawArrays;

    typedef void(APIENTRYP PFNGLDRAWELEMENTSPROC)(GLenum_t mode, GLsizei_t count, GLenum_t type, const void* indices);
    PFNGLDRAWELEMENTSPROC oglDrawElements;

    typedef void(APIENTRYP PFNGLPOLYGONOFFSETPROC)(GLfloat_t factor, GLfloat_t units);
    PFNGLPOLYGONOFFSETPROC oglPolygonOffset;

    typedef void(
        APIENTRYP PFNGLCOPYTEXIMAGE1DPROC)(GLenum_t target, GLint_t level, GLenum_t internalformat, GLint_t x, GLint_t y, GLsizei_t width, GLint_t border);
    PFNGLCOPYTEXIMAGE1DPROC oglCopyTexImage1D;

    typedef void(APIENTRYP PFNGLCOPYTEXIMAGE2DPROC)(GLenum_t  target,
                                                    GLint_t   level,
                                                    GLenum_t  internalformat,
                                                    GLint_t   x,
                                                    GLint_t   y,
                                                    GLsizei_t width,
                                                    GLsizei_t height,
                                                    GLint_t   border);
    PFNGLCOPYTEXIMAGE2DPROC oglCopyTexImage2D;

    typedef void(APIENTRYP PFNGLCOPYTEXSUBIMAGE1DPROC)(GLenum_t target, GLint_t level, GLint_t xoffset, GLint_t x, GLint_t y, GLsizei_t width);
    PFNGLCOPYTEXSUBIMAGE1DPROC oglCopyTexSubImage1D;

    typedef void(APIENTRYP PFNGLCOPYTEXSUBIMAGE2DPROC)(GLenum_t  target,
                                                       GLint_t   level,
                                                       GLint_t   xoffset,
                                                       GLint_t   yoffset,
                                                       GLint_t   x,
                                                       GLint_t   y,
                                                       GLsizei_t width,
                                                       GLsizei_t height);
    PFNGLCOPYTEXSUBIMAGE2DPROC oglCopyTexSubImage2D;

    typedef void(
        APIENTRYP PFNGLTEXSUBIMAGE1DPROC)(GLenum_t target, GLint_t level, GLint_t xoffset, GLsizei_t width, GLenum_t format, GLenum_t type, const void* pixels);
    PFNGLTEXSUBIMAGE1DPROC oglTexSubImage1D;

    typedef void(APIENTRYP PFNGLTEXSUBIMAGE2DPROC)(GLenum_t    target,
                                                   GLint_t     level,
                                                   GLint_t     xoffset,
                                                   GLint_t     yoffset,
                                                   GLsizei_t   width,
                                                   GLsizei_t   height,
                                                   GLenum_t    format,
                                                   GLenum_t    type,
                                                   const void* pixels);
    PFNGLTEXSUBIMAGE2DPROC oglTexSubImage2D;

    typedef void(APIENTRYP PFNGLBINDTEXTUREPROC)(GLenum_t target, GLuint_t texture);
    PFNGLBINDTEXTUREPROC oglBindTexture;

    typedef void(APIENTRYP PFNGLDELETETEXTURESPROC)(GLsizei_t n, const GLuint_t* textures);
    PFNGLDELETETEXTURESPROC oglDeleteTextures;

    typedef void(APIENTRYP PFNGLGENTEXTURESPROC)(GLsizei_t n, GLuint_t* textures);
    PFNGLGENTEXTURESPROC oglGenTextures;

    typedef GLboolean_t(APIENTRYP PFNGLISTEXTUREPROC)(GLuint_t texture);
    PFNGLISTEXTUREPROC oglIsTexture;

  public:
    GLfuncsv110();

  protected:
    virtual void loadFuncs(Loader loader) override;
};

} // namespace glr
} // namespace xg
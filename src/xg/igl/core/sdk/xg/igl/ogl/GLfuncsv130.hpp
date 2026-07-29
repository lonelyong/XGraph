#pragma once

#include <xg/igl/ogl/GLfuncsv120.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API GLfuncsv130 : public GLfuncsv120 {
  public:
    typedef void(APIENTRYP PFNGLACTIVETEXTUREPROC)(GLenum_t texture);
    PFNGLACTIVETEXTUREPROC oglActiveTexture;

    typedef void(APIENTRYP PFNGLSAMPLECOVERAGEPROC)(GLfloat_t value, GLboolean_t invert);
    PFNGLSAMPLECOVERAGEPROC oglSampleCoverage;

    typedef void(APIENTRYP PFNGLCOMPRESSEDTEXIMAGE3DPROC)(GLenum_t    target,
                                                          GLint_t     level,
                                                          GLenum_t    internalformat,
                                                          GLsizei_t   width,
                                                          GLsizei_t   height,
                                                          GLsizei_t   depth,
                                                          GLint_t     border,
                                                          GLsizei_t   imageSize,
                                                          const void* data);
    PFNGLCOMPRESSEDTEXIMAGE3DPROC oglCompressedTexImage3D;

    typedef void(APIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DPROC)(GLenum_t    target,
                                                          GLint_t     level,
                                                          GLenum_t    internalformat,
                                                          GLsizei_t   width,
                                                          GLsizei_t   height,
                                                          GLint_t     border,
                                                          GLsizei_t   imageSize,
                                                          const void* data);
    PFNGLCOMPRESSEDTEXIMAGE2DPROC oglCompressedTexImage2D;

    typedef void(APIENTRYP PFNGLCOMPRESSEDTEXIMAGE1DPROC)(GLenum_t    target,
                                                          GLint_t     level,
                                                          GLenum_t    internalformat,
                                                          GLsizei_t   width,
                                                          GLint_t     border,
                                                          GLsizei_t   imageSize,
                                                          const void* data);
    PFNGLCOMPRESSEDTEXIMAGE1DPROC oglCompressedTexImage1D;

    typedef void(APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)(GLenum_t    target,
                                                             GLint_t     level,
                                                             GLint_t     xoffset,
                                                             GLint_t     yoffset,
                                                             GLint_t     zoffset,
                                                             GLsizei_t   width,
                                                             GLsizei_t   height,
                                                             GLsizei_t   depth,
                                                             GLenum_t    format,
                                                             GLsizei_t   imageSize,
                                                             const void* data);
    PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC oglCompressedTexSubImage3D;

    typedef void(APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)(GLenum_t    target,
                                                             GLint_t     level,
                                                             GLint_t     xoffset,
                                                             GLint_t     yoffset,
                                                             GLsizei_t   width,
                                                             GLsizei_t   height,
                                                             GLenum_t    format,
                                                             GLsizei_t   imageSize,
                                                             const void* data);
    PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC oglCompressedTexSubImage2D;

    typedef void(APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)(GLenum_t    target,
                                                             GLint_t     level,
                                                             GLint_t     xoffset,
                                                             GLsizei_t   width,
                                                             GLenum_t    format,
                                                             GLsizei_t   imageSize,
                                                             const void* data);
    PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC oglCompressedTexSubImage1D;

    typedef void(APIENTRYP PFNGLGETCOMPRESSEDTEXIMAGEPROC)(GLenum_t target, GLint_t level, void* img);
    PFNGLGETCOMPRESSEDTEXIMAGEPROC oglGetCompressedTexImage;

  public:
    GLfuncsv130();

  protected:
    virtual void loadFuncs(Loader loader) override;
};

} // namespace glr
} // namespace xg
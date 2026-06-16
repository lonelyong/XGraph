#pragma once

#include <xg/glr/igl/GLfuncsv120.h>

namespace glr {
class GLR_API GLfuncsv130 : public GLfuncsv120 {
  public:
    typedef void(APIENTRYP PFNGLACTIVETEXTUREPROC)(GLenum_t texture);
    PFNGLACTIVETEXTUREPROC iglActiveTexture;

    typedef void(APIENTRYP PFNGLSAMPLECOVERAGEPROC)(GLfloat_t value, GLboolean_t invert);
    PFNGLSAMPLECOVERAGEPROC iglSampleCoverage;

    typedef void(APIENTRYP PFNGLCOMPRESSEDTEXIMAGE3DPROC)(GLenum_t    target,
                                                          GLint_t     level,
                                                          GLenum_t    internalformat,
                                                          GLsizei_t   width,
                                                          GLsizei_t   height,
                                                          GLsizei_t   depth,
                                                          GLint_t     border,
                                                          GLsizei_t   imageSize,
                                                          const void* data);
    PFNGLCOMPRESSEDTEXIMAGE3DPROC iglCompressedTexImage3D;

    typedef void(APIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DPROC)(GLenum_t    target,
                                                          GLint_t     level,
                                                          GLenum_t    internalformat,
                                                          GLsizei_t   width,
                                                          GLsizei_t   height,
                                                          GLint_t     border,
                                                          GLsizei_t   imageSize,
                                                          const void* data);
    PFNGLCOMPRESSEDTEXIMAGE2DPROC iglCompressedTexImage2D;

    typedef void(APIENTRYP PFNGLCOMPRESSEDTEXIMAGE1DPROC)(GLenum_t    target,
                                                          GLint_t     level,
                                                          GLenum_t    internalformat,
                                                          GLsizei_t   width,
                                                          GLint_t     border,
                                                          GLsizei_t   imageSize,
                                                          const void* data);
    PFNGLCOMPRESSEDTEXIMAGE1DPROC iglCompressedTexImage1D;

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
    PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC iglCompressedTexSubImage3D;

    typedef void(APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)(GLenum_t    target,
                                                             GLint_t     level,
                                                             GLint_t     xoffset,
                                                             GLint_t     yoffset,
                                                             GLsizei_t   width,
                                                             GLsizei_t   height,
                                                             GLenum_t    format,
                                                             GLsizei_t   imageSize,
                                                             const void* data);
    PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC iglCompressedTexSubImage2D;

    typedef void(APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)(GLenum_t    target,
                                                             GLint_t     level,
                                                             GLint_t     xoffset,
                                                             GLsizei_t   width,
                                                             GLenum_t    format,
                                                             GLsizei_t   imageSize,
                                                             const void* data);
    PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC iglCompressedTexSubImage1D;

    typedef void(APIENTRYP PFNGLGETCOMPRESSEDTEXIMAGEPROC)(GLenum_t target, GLint_t level, void* img);
    PFNGLGETCOMPRESSEDTEXIMAGEPROC iglGetCompressedTexImage;

  public:
    GLfuncsv130();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
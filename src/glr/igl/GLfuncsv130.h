#pragma once

#include <glr/igl/GLfuncsv120.h>

namespace glr {
class GLR_API GLfuncsv130 : public GLfuncsv120 {
    VI_OBJECT_META;

    typedef void(APIENTRYP PFNGLACTIVETEXTUREPROC)(GLenum texture);
    PFNGLACTIVETEXTUREPROC glActiveTexture;

    typedef void(APIENTRYP PFNGLSAMPLECOVERAGEPROC)(GLfloat value, GLboolean invert);
    PFNGLSAMPLECOVERAGEPROC glSampleCoverage;

    typedef void(APIENTRYP PFNGLCOMPRESSEDTEXIMAGE3DPROC)(GLenum      target,
                                                          GLint       level,
                                                          GLenum      internalformat,
                                                          GLsizei     width,
                                                          GLsizei     height,
                                                          GLsizei     depth,
                                                          GLint       border,
                                                          GLsizei     imageSize,
                                                          const void* data);
    PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3D;

    typedef void(APIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DPROC)(GLenum      target,
                                                          GLint       level,
                                                          GLenum      internalformat,
                                                          GLsizei     width,
                                                          GLsizei     height,
                                                          GLint       border,
                                                          GLsizei     imageSize,
                                                          const void* data);
    PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D;

    typedef void(APIENTRYP PFNGLCOMPRESSEDTEXIMAGE1DPROC)(GLenum      target,
                                                          GLint       level,
                                                          GLenum      internalformat,
                                                          GLsizei     width,
                                                          GLint       border,
                                                          GLsizei     imageSize,
                                                          const void* data);
    PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1D;

    typedef void(APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)(GLenum      target,
                                                             GLint       level,
                                                             GLint       xoffset,
                                                             GLint       yoffset,
                                                             GLint       zoffset,
                                                             GLsizei     width,
                                                             GLsizei     height,
                                                             GLsizei     depth,
                                                             GLenum      format,
                                                             GLsizei     imageSize,
                                                             const void* data);
    PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3D;

    typedef void(APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)(GLenum      target,
                                                             GLint       level,
                                                             GLint       xoffset,
                                                             GLint       yoffset,
                                                             GLsizei     width,
                                                             GLsizei     height,
                                                             GLenum      format,
                                                             GLsizei     imageSize,
                                                             const void* data);
    PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D;

    typedef void(APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)(GLenum      target,
                                                             GLint       level,
                                                             GLint       xoffset,
                                                             GLsizei     width,
                                                             GLenum      format,
                                                             GLsizei     imageSize,
                                                             const void* data);
    PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1D;

    typedef void(APIENTRYP PFNGLGETCOMPRESSEDTEXIMAGEPROC)(GLenum target, GLint level, void* img);
    PFNGLGETCOMPRESSEDTEXIMAGEPROC glGetCompressedTexImage;

  public:
    GLfuncsv130();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
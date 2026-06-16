#include <xg/glr/igl/GLfuncsv130.h>

namespace glr {


GLfuncsv130::GLfuncsv130()
  : iglActiveTexture(nullptr)
  , iglCompressedTexImage1D(nullptr)
  , iglCompressedTexImage2D(nullptr)
  , iglCompressedTexImage3D(nullptr)
  , iglCompressedTexSubImage1D(nullptr)
  , iglCompressedTexSubImage2D(nullptr)
  , iglCompressedTexSubImage3D(nullptr)
  , iglGetCompressedTexImage(nullptr)
  , iglSampleCoverage(nullptr) {
}

void GLfuncsv130::loadFuncs(Loader loader) {
    GLfuncsv120::loadFuncs(loader);
    iglActiveTexture           = (PFNGLACTIVETEXTUREPROC)loader("glActiveTexture");
    iglSampleCoverage          = (PFNGLSAMPLECOVERAGEPROC)loader("glSampleCoverage");
    iglCompressedTexImage3D    = (PFNGLCOMPRESSEDTEXIMAGE3DPROC)loader("glCompressedTexImage3D");
    iglCompressedTexImage2D    = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)loader("glCompressedTexImage2D");
    iglCompressedTexImage1D    = (PFNGLCOMPRESSEDTEXIMAGE1DPROC)loader("glCompressedTexImage1D");
    iglCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)loader("glCompressedTexSubImage3D");
    iglCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)loader("glCompressedTexSubImage2D");
    iglCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)loader("glCompressedTexSubImage1D");
    iglGetCompressedTexImage   = (PFNGLGETCOMPRESSEDTEXIMAGEPROC)loader("glGetCompressedTexImage");
}
} // namespace glr
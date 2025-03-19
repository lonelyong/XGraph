#include <glr/igl/GLfuncsv130.h>

namespace glr {

VI_OBJECT_META_IMPL(GLfuncsv130, GLfuncsv120);

GLfuncsv130::GLfuncsv130()
  : glActiveTexture(nullptr)
  , glCompressedTexImage1D(nullptr)
  , glCompressedTexImage2D(nullptr)
  , glCompressedTexImage3D(nullptr)
  , glCompressedTexSubImage1D(nullptr)
  , glCompressedTexSubImage2D(nullptr)
  , glCompressedTexSubImage3D(nullptr)
  , glGetCompressedTexImage(nullptr)
  , glSampleCoverage(nullptr) {
}

void GLfuncsv130::loadFuncs(Loader loader) {
    GLfuncsv120::loadFuncs(loader);
    glActiveTexture           = (PFNGLACTIVETEXTUREPROC)loader("glActiveTexture");
    glSampleCoverage          = (PFNGLSAMPLECOVERAGEPROC)loader("glSampleCoverage");
    glCompressedTexImage3D    = (PFNGLCOMPRESSEDTEXIMAGE3DPROC)loader("glCompressedTexImage3D");
    glCompressedTexImage2D    = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)loader("glCompressedTexImage2D");
    glCompressedTexImage1D    = (PFNGLCOMPRESSEDTEXIMAGE1DPROC)loader("glCompressedTexImage1D");
    glCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)loader("glCompressedTexSubImage3D");
    glCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)loader("glCompressedTexSubImage2D");
    glCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)loader("glCompressedTexSubImage1D");
    glGetCompressedTexImage   = (PFNGLGETCOMPRESSEDTEXIMAGEPROC)loader("glGetCompressedTexImage");
}
} // namespace glr
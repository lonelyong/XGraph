#include <xg/igl/ogl/GLfuncsv130.hpp>

namespace xg
{
namespace glr
{


GLfuncsv130::GLfuncsv130()
  : oglActiveTexture(nullptr)
  , oglCompressedTexImage1D(nullptr)
  , oglCompressedTexImage2D(nullptr)
  , oglCompressedTexImage3D(nullptr)
  , oglCompressedTexSubImage1D(nullptr)
  , oglCompressedTexSubImage2D(nullptr)
  , oglCompressedTexSubImage3D(nullptr)
  , oglGetCompressedTexImage(nullptr)
  , oglSampleCoverage(nullptr)
{}

void GLfuncsv130::loadFuncs(Loader loader)
{
    GLfuncsv120::loadFuncs(loader);
    oglActiveTexture           = (PFNGLACTIVETEXTUREPROC)loader("glActiveTexture");
    oglSampleCoverage          = (PFNGLSAMPLECOVERAGEPROC)loader("glSampleCoverage");
    oglCompressedTexImage3D    = (PFNGLCOMPRESSEDTEXIMAGE3DPROC)loader("glCompressedTexImage3D");
    oglCompressedTexImage2D    = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)loader("glCompressedTexImage2D");
    oglCompressedTexImage1D    = (PFNGLCOMPRESSEDTEXIMAGE1DPROC)loader("glCompressedTexImage1D");
    oglCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)loader("glCompressedTexSubImage3D");
    oglCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)loader("glCompressedTexSubImage2D");
    oglCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)loader("glCompressedTexSubImage1D");
    oglGetCompressedTexImage   = (PFNGLGETCOMPRESSEDTEXIMAGEPROC)loader("glGetCompressedTexImage");
}

} // namespace glr
} // namespace xg
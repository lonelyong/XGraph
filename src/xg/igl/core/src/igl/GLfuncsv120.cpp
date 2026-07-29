#include <xg/igl/ogl/GLfuncsv120.hpp>

namespace xg
{
namespace glr
{


GLfuncsv120::GLfuncsv120()
  : oglDrawRangeElements(nullptr)
  , oglTexImage3D(nullptr)
  , oglTexSubImage3D(nullptr)
  , oglCopyTexSubImage3D(nullptr)
{}

void GLfuncsv120::loadFuncs(Loader loader)
{
    GLfuncsv110::loadFuncs(loader);
    oglDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC)loader("glDrawRangeElements");
    oglTexImage3D        = (PFNGLTEXIMAGE3DPROC)loader("glTexImage3D");
    oglTexSubImage3D     = (PFNGLTEXSUBIMAGE3DPROC)loader("glTexSubImage3D");
    oglCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC)loader("glCopyTexSubImage3D");
}

} // namespace glr
} // namespace xg
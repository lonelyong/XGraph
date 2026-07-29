#include <xg/igl/ogl/GLfuncsv110.hpp>

namespace xg
{
namespace glr
{


GLfuncsv110::GLfuncsv110()
  : oglBindTexture(nullptr)
  , oglCopyTexImage1D(nullptr)
  , oglCopyTexImage2D(nullptr)
  , oglCopyTexSubImage1D(nullptr)
  , oglCopyTexSubImage2D(nullptr)
  , oglDeleteTextures(nullptr)
  , oglDrawArrays(nullptr)
  , oglDrawElements(nullptr)
  , oglGenTextures(nullptr)
  , oglIsTexture(nullptr)
  , oglPolygonOffset(nullptr)
  , oglTexSubImage1D(nullptr)
  , oglTexSubImage2D(nullptr)
{}

void GLfuncsv110::loadFuncs(Loader loader)
{
    GLfuncsv100::loadFuncs(loader);
    oglBindTexture       = reinterpret_cast<PFNGLBINDTEXTUREPROC>(loader("glBindTexture"));
    oglCopyTexImage1D    = reinterpret_cast<PFNGLCOPYTEXIMAGE1DPROC>(loader("glCopyTexImage1D"));
    oglCopyTexImage2D    = reinterpret_cast<PFNGLCOPYTEXIMAGE2DPROC>(loader("glCopyTexImage2D"));
    oglCopyTexSubImage1D = reinterpret_cast<PFNGLCOPYTEXSUBIMAGE1DPROC>(loader("glCopyTexSubImage1D"));
    oglCopyTexSubImage2D = reinterpret_cast<PFNGLCOPYTEXSUBIMAGE2DPROC>(loader("glCopyTexSubImage2D"));
    oglDeleteTextures    = reinterpret_cast<PFNGLDELETETEXTURESPROC>(loader("glDeleteTextures"));
    oglDrawArrays        = reinterpret_cast<PFNGLDRAWARRAYSPROC>(loader("glDrawArrays"));
    oglDrawElements      = reinterpret_cast<PFNGLDRAWELEMENTSPROC>(loader("glDrawElements"));
    oglGenTextures       = reinterpret_cast<PFNGLGENTEXTURESPROC>(loader("glGenTextures"));
    oglIsTexture         = reinterpret_cast<PFNGLISTEXTUREPROC>(loader("glIsTexture"));
    oglPolygonOffset     = reinterpret_cast<PFNGLPOLYGONOFFSETPROC>(loader("glPolygonOffset"));
    oglTexSubImage1D     = reinterpret_cast<PFNGLTEXSUBIMAGE1DPROC>(loader("glTexSubImage1D"));
    oglTexSubImage2D     = reinterpret_cast<PFNGLTEXSUBIMAGE2DPROC>(loader("glTexSubImage2D"));
}

} // namespace glr
} // namespace xg

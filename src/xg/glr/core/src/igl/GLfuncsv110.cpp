#include <xg/glr/igl/GLfuncsv110.h>

namespace xg {
namespace glr {


GLfuncsv110::GLfuncsv110()
  : iglBindTexture(nullptr)
  , iglCopyTexImage1D(nullptr)
  , iglCopyTexImage2D(nullptr)
  , iglCopyTexSubImage1D(nullptr)
  , iglCopyTexSubImage2D(nullptr)
  , iglDeleteTextures(nullptr)
  , iglDrawArrays(nullptr)
  , iglDrawElements(nullptr)
  , iglGenTextures(nullptr)
  , iglIsTexture(nullptr)
  , iglPolygonOffset(nullptr)
  , iglTexSubImage1D(nullptr)
  , iglTexSubImage2D(nullptr) {
}


void GLfuncsv110::loadFuncs(Loader loader) {
    GLfuncsv100::loadFuncs(loader);
    iglBindTexture       = reinterpret_cast<PFNGLBINDTEXTUREPROC>(loader("glBindTexture"));
    iglCopyTexImage1D    = reinterpret_cast<PFNGLCOPYTEXIMAGE1DPROC>(loader("glCopyTexImage1D"));
    iglCopyTexImage2D    = reinterpret_cast<PFNGLCOPYTEXIMAGE2DPROC>(loader("glCopyTexImage2D"));
    iglCopyTexSubImage1D = reinterpret_cast<PFNGLCOPYTEXSUBIMAGE1DPROC>(loader("glCopyTexSubImage1D"));
    iglCopyTexSubImage2D = reinterpret_cast<PFNGLCOPYTEXSUBIMAGE2DPROC>(loader("glCopyTexSubImage2D"));
    iglDeleteTextures    = reinterpret_cast<PFNGLDELETETEXTURESPROC>(loader("glDeleteTextures"));
    iglDrawArrays        = reinterpret_cast<PFNGLDRAWARRAYSPROC>(loader("glDrawArrays"));
    iglDrawElements      = reinterpret_cast<PFNGLDRAWELEMENTSPROC>(loader("glDrawElements"));
    iglGenTextures       = reinterpret_cast<PFNGLGENTEXTURESPROC>(loader("glGenTextures"));
    iglIsTexture         = reinterpret_cast<PFNGLISTEXTUREPROC>(loader("glIsTexture"));
    iglPolygonOffset     = reinterpret_cast<PFNGLPOLYGONOFFSETPROC>(loader("glPolygonOffset"));
    iglTexSubImage1D     = reinterpret_cast<PFNGLTEXSUBIMAGE1DPROC>(loader("glTexSubImage1D"));
    iglTexSubImage2D     = reinterpret_cast<PFNGLTEXSUBIMAGE2DPROC>(loader("glTexSubImage2D"));
}
} // namespace glr
} // namespace xg

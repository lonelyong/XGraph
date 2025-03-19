#include <glr/igl/GLfuncsv110.h>

namespace glr {

VI_OBJECT_META_IMPL(GLfuncsv110, GLfuncsv100);

GLfuncsv110::GLfuncsv110()
  : glBindTexture(nullptr)
  , glCopyTexImage1D(nullptr)
  , glCopyTexImage2D(nullptr)
  , glCopyTexSubImage1D(nullptr)
  , glCopyTexSubImage2D(nullptr)
  , glDeleteTextures(nullptr)
  , glDrawArrays(nullptr)
  , glDrawElements(nullptr)
  , glGenTextures(nullptr)
  , glIsTexture(nullptr)
  , glPolygonOffset(nullptr)
  , glTexSubImage1D(nullptr)
  , glTexSubImage2D(nullptr) {
}


void GLfuncsv110::loadFuncs(Loader loader) {
    GLfuncsv100::loadFuncs(loader);
    glBindTexture       = reinterpret_cast<PFNGLBINDTEXTUREPROC>(loader("glBindTexture"));
    glCopyTexImage1D    = reinterpret_cast<PFNGLCOPYTEXIMAGE1DPROC>(loader("glCopyTexImage1D"));
    glCopyTexImage2D    = reinterpret_cast<PFNGLCOPYTEXIMAGE2DPROC>(loader("glCopyTexImage2D"));
    glCopyTexSubImage1D = reinterpret_cast<PFNGLCOPYTEXSUBIMAGE1DPROC>(loader("glCopyTexSubImage1D"));
    glCopyTexSubImage2D = reinterpret_cast<PFNGLCOPYTEXSUBIMAGE2DPROC>(loader("glCopyTexSubImage2D"));
    glDeleteTextures    = reinterpret_cast<PFNGLDELETETEXTURESPROC>(loader("glDeleteTextures"));
    glDrawArrays        = reinterpret_cast<PFNGLDRAWARRAYSPROC>(loader("glDrawArrays"));
    glDrawElements      = reinterpret_cast<PFNGLDRAWELEMENTSPROC>(loader("glDrawElements"));
    glGenTextures       = reinterpret_cast<PFNGLGENTEXTURESPROC>(loader("glGenTextures"));
    glIsTexture         = reinterpret_cast<PFNGLISTEXTUREPROC>(loader("glIsTexture"));
    glPolygonOffset     = reinterpret_cast<PFNGLPOLYGONOFFSETPROC>(loader("glPolygonOffset"));
    glTexSubImage1D     = reinterpret_cast<PFNGLTEXSUBIMAGE1DPROC>(loader("glTexSubImage1D"));
    glTexSubImage2D     = reinterpret_cast<PFNGLTEXSUBIMAGE2DPROC>(loader("glTexSubImage2D"));
}
} // namespace glr

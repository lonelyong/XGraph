#include <xg/glr/igl/GLfuncsv120.h>

namespace glr {


GLfuncsv120::GLfuncsv120()
  : iglDrawRangeElements(nullptr)
  , iglTexImage3D(nullptr)
  , iglTexSubImage3D(nullptr)
  , iglCopyTexSubImage3D(nullptr) {
}

void GLfuncsv120::loadFuncs(Loader loader) {
    GLfuncsv110::loadFuncs(loader);
    iglDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC)loader("glDrawRangeElements");
    iglTexImage3D        = (PFNGLTEXIMAGE3DPROC)loader("glTexImage3D");
    iglTexSubImage3D     = (PFNGLTEXSUBIMAGE3DPROC)loader("glTexSubImage3D");
    iglCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC)loader("glCopyTexSubImage3D");
}

} // namespace glr
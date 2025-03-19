#include <glr/igl/GLfuncsv120.h>

namespace glr {

VI_OBJECT_META_IMPL(GLfuncsv120, GLfuncsv110);

GLfuncsv120::GLfuncsv120()
  : glDrawRangeElements(nullptr)
  , glTexImage3D(nullptr)
  , glTexSubImage3D(nullptr)
  , glCopyTexSubImage3D(nullptr) {
}

void GLfuncsv120::loadFuncs(Loader loader) {
    GLfuncsv110::loadFuncs(loader);
    glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC)loader("glDrawRangeElements");
    glTexImage3D        = (PFNGLTEXIMAGE3DPROC)loader("glTexImage3D");
    glTexSubImage3D     = (PFNGLTEXSUBIMAGE3DPROC)loader("glTexSubImage3D");
    glCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC)loader("glCopyTexSubImage3D");
}

} // namespace glr
#include "GLfuncsv210.h"

namespace glr {

GLfuncsv210::GLfuncsv210()
  : glUniformMatrix2x3fv(nullptr)
  , glUniformMatrix2x4fv(nullptr)
  , glUniformMatrix3x2fv(nullptr)
  , glUniformMatrix3x4fv(nullptr)
  , glUniformMatrix4x2fv(nullptr)
  , glUniformMatrix4x3fv(nullptr) {
}

void GLfuncsv210::loadFuncs(Loader loader) {
    GLfuncsv200::loadFuncs(loader);
    glUniformMatrix2x3fv = reinterpret_cast<PFNGLUNIFORMMATRIX2X3FVPROC>(loader("glUniformMatrix2x3fv"));
    glUniformMatrix3x2fv = reinterpret_cast<PFNGLUNIFORMMATRIX3X2FVPROC>(loader("glUniformMatrix3x2fv"));
    glUniformMatrix2x4fv = reinterpret_cast<PFNGLUNIFORMMATRIX2X4FVPROC>(loader("glUniformMatrix2x4fv"));
    glUniformMatrix4x2fv = reinterpret_cast<PFNGLUNIFORMMATRIX4X2FVPROC>(loader("glUniformMatrix4x2fv"));
    glUniformMatrix3x4fv = reinterpret_cast<PFNGLUNIFORMMATRIX3X4FVPROC>(loader("glUniformMatrix3x4fv"));
    glUniformMatrix4x3fv = reinterpret_cast<PFNGLUNIFORMMATRIX4X3FVPROC>(loader("glUniformMatrix4x3fv"));
}

} // namespace glr

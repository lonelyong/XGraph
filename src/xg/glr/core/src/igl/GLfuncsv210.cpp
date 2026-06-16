#include <xg/glr/igl/GLfuncsv210.h>

namespace xg {
namespace glr {


GLfuncsv210::GLfuncsv210()
  : iglUniformMatrix2x3fv(nullptr)
  , iglUniformMatrix2x4fv(nullptr)
  , iglUniformMatrix3x2fv(nullptr)
  , iglUniformMatrix3x4fv(nullptr)
  , iglUniformMatrix4x2fv(nullptr)
  , iglUniformMatrix4x3fv(nullptr) {
}

void GLfuncsv210::loadFuncs(Loader loader) {
    GLfuncsv200::loadFuncs(loader);
    iglUniformMatrix2x3fv = reinterpret_cast<PFNGLUNIFORMMATRIX2X3FVPROC>(loader("glUniformMatrix2x3fv"));
    iglUniformMatrix3x2fv = reinterpret_cast<PFNGLUNIFORMMATRIX3X2FVPROC>(loader("glUniformMatrix3x2fv"));
    iglUniformMatrix2x4fv = reinterpret_cast<PFNGLUNIFORMMATRIX2X4FVPROC>(loader("glUniformMatrix2x4fv"));
    iglUniformMatrix4x2fv = reinterpret_cast<PFNGLUNIFORMMATRIX4X2FVPROC>(loader("glUniformMatrix4x2fv"));
    iglUniformMatrix3x4fv = reinterpret_cast<PFNGLUNIFORMMATRIX3X4FVPROC>(loader("glUniformMatrix3x4fv"));
    iglUniformMatrix4x3fv = reinterpret_cast<PFNGLUNIFORMMATRIX4X3FVPROC>(loader("glUniformMatrix4x3fv"));
}

} // namespace glr
} // namespace xg

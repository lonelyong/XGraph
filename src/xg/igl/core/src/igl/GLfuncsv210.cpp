#include <xg/igl/ogl/GLfuncsv210.hpp>

namespace xg
{
namespace glr
{


GLfuncsv210::GLfuncsv210()
  : oglUniformMatrix2x3fv(nullptr)
  , oglUniformMatrix2x4fv(nullptr)
  , oglUniformMatrix3x2fv(nullptr)
  , oglUniformMatrix3x4fv(nullptr)
  , oglUniformMatrix4x2fv(nullptr)
  , oglUniformMatrix4x3fv(nullptr)
{}

void GLfuncsv210::loadFuncs(Loader loader)
{
    GLfuncsv200::loadFuncs(loader);
    oglUniformMatrix2x3fv = reinterpret_cast<PFNGLUNIFORMMATRIX2X3FVPROC>(loader("glUniformMatrix2x3fv"));
    oglUniformMatrix3x2fv = reinterpret_cast<PFNGLUNIFORMMATRIX3X2FVPROC>(loader("glUniformMatrix3x2fv"));
    oglUniformMatrix2x4fv = reinterpret_cast<PFNGLUNIFORMMATRIX2X4FVPROC>(loader("glUniformMatrix2x4fv"));
    oglUniformMatrix4x2fv = reinterpret_cast<PFNGLUNIFORMMATRIX4X2FVPROC>(loader("glUniformMatrix4x2fv"));
    oglUniformMatrix3x4fv = reinterpret_cast<PFNGLUNIFORMMATRIX3X4FVPROC>(loader("glUniformMatrix3x4fv"));
    oglUniformMatrix4x3fv = reinterpret_cast<PFNGLUNIFORMMATRIX4X3FVPROC>(loader("glUniformMatrix4x3fv"));
}

} // namespace glr
} // namespace xg

#include <xg/igl/ogl/GLfuncsv460.hpp>

namespace xg
{
namespace glr
{


GLfuncsv460::GLfuncsv460()
  : oglMultiDrawArraysIndirectCount(nullptr)
  , oglMultiDrawElementsIndirectCount(nullptr)
  , oglPolygonOffsetClamp(nullptr)
  , oglSpecializeShader(nullptr)
{}

void GLfuncsv460::loadFuncs(Loader loader)
{
    GLfuncsv450::loadFuncs(loader);
    oglMultiDrawArraysIndirectCount   = reinterpret_cast<PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC>(loader("glMultiDrawArraysIndirectCount"));
    oglMultiDrawElementsIndirectCount = reinterpret_cast<PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC>(loader("glMultiDrawElementsIndirectCount"));
    oglPolygonOffsetClamp             = reinterpret_cast<PFNGLPOLYGONOFFSETCLAMPPROC>(loader("glPolygonOffsetClamp"));
    oglSpecializeShader               = reinterpret_cast<PFNGLSPECIALIZESHADERPROC>(loader("glSpecializeShader"));
}

} // namespace glr
} // namespace xg

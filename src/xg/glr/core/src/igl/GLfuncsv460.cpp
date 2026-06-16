#include <xg/glr/igl/GLfuncsv460.h>

namespace xg {
namespace glr {


GLfuncsv460::GLfuncsv460()
  : iglMultiDrawArraysIndirectCount(nullptr)
  , iglMultiDrawElementsIndirectCount(nullptr)
  , iglPolygonOffsetClamp(nullptr)
  , iglSpecializeShader(nullptr) {
}

void GLfuncsv460::loadFuncs(Loader loader) {
    GLfuncsv450::loadFuncs(loader);
    iglMultiDrawArraysIndirectCount =
        reinterpret_cast<PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC>(loader("glMultiDrawArraysIndirectCount"));
    iglMultiDrawElementsIndirectCount =
        reinterpret_cast<PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC>(loader("glMultiDrawElementsIndirectCount"));
    iglPolygonOffsetClamp = reinterpret_cast<PFNGLPOLYGONOFFSETCLAMPPROC>(loader("glPolygonOffsetClamp"));
    iglSpecializeShader   = reinterpret_cast<PFNGLSPECIALIZESHADERPROC>(loader("glSpecializeShader"));
}
} // namespace glr
} // namespace xg

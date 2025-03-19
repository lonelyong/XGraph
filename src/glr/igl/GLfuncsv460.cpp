#include "GLfuncsv460.h"

namespace glr {
GLfuncsv460::GLfuncsv460()
  : glMultiDrawArraysIndirectCount(nullptr)
  , glMultiDrawElementsIndirectCount(nullptr)
  , glPolygonOffsetClamp(nullptr)
  , glSpecializeShader(nullptr) {
}

void GLfuncsv460::loadFuncs(Loader loader) {
    GLfuncsv450::loadFuncs(loader);
    glMultiDrawArraysIndirectCount =
        reinterpret_cast<PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC>(loader("glMultiDrawArraysIndirectCount"));
    glMultiDrawElementsIndirectCount =
        reinterpret_cast<PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC>(loader("glMultiDrawElementsIndirectCount"));
    glPolygonOffsetClamp = reinterpret_cast<PFNGLPOLYGONOFFSETCLAMPPROC>(loader("glPolygonOffsetClamp"));
    glSpecializeShader   = reinterpret_cast<PFNGLSPECIALIZESHADERPROC>(loader("glSpecializeShader"));
}
} // namespace glr

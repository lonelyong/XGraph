#include <glr/igl/GLfuncsv140.h>


namespace glr {
GLfuncsv140::GLfuncsv140()
  : glBlendColor(nullptr)
  , glBlendEquation(nullptr)
  , glBlendFuncSeparate(nullptr)
  , glMultiDrawArrays(nullptr)
  , glMultiDrawElements(nullptr)
  , glPointParameterfv(nullptr)
  , glPointParameterf(nullptr)
  , glPointParameteriv(nullptr)
  , glPointParameteri(nullptr) {
}
void GLfuncsv140::loadFuncs(Loader loader) {
    GLfuncsv130::loadFuncs(loader);
    glBlendColor        = reinterpret_cast<PFNGLBLENDCOLORPROC>(loader("glBlendColor"));
    glBlendEquation     = reinterpret_cast<PFNGLBLENDEQUATIONPROC>(loader("glBlendEquation"));
    glBlendFuncSeparate = reinterpret_cast<PFNGLBLENDFUNCSEPARATEPROC>(loader("glBlendFuncSeparate"));
    glMultiDrawArrays   = reinterpret_cast<PFNGLMULTIDRAWARRAYSPROC>(loader("glMultiDrawArrays"));
    glMultiDrawElements = reinterpret_cast<PFNGLMULTIDRAWELEMENTSPROC>(loader("glMultiDrawElements"));
    glPointParameterfv  = reinterpret_cast<PFNGLPOINTPARAMETERFVPROC>(loader("glPointParameterfv"));
    glPointParameterf   = reinterpret_cast<PFNGLPOINTPARAMETERFPROC>(loader("glPointParameterf"));
    glPointParameteriv  = reinterpret_cast<PFNGLPOINTPARAMETERIVPROC>(loader("glPointParameteriv"));
    glPointParameteri   = reinterpret_cast<PFNGLPOINTPARAMETERIPROC>(loader("glPointParameteri"));
}
} // namespace glr
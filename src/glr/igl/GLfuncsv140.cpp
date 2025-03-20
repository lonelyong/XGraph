#include <glr/igl/GLfuncsv140.h>


namespace glr {


GLfuncsv140::GLfuncsv140()
  : iglBlendColor(nullptr)
  , iglBlendEquation(nullptr)
  , iglBlendFuncSeparate(nullptr)
  , iglMultiDrawArrays(nullptr)
  , iglMultiDrawElements(nullptr)
  , iglPointParameterfv(nullptr)
  , iglPointParameterf(nullptr)
  , iglPointParameteriv(nullptr)
  , iglPointParameteri(nullptr) {
}
void GLfuncsv140::loadFuncs(Loader loader) {
    GLfuncsv130::loadFuncs(loader);
    iglBlendColor        = reinterpret_cast<PFNGLBLENDCOLORPROC>(loader("glBlendColor"));
    iglBlendEquation     = reinterpret_cast<PFNGLBLENDEQUATIONPROC>(loader("glBlendEquation"));
    iglBlendFuncSeparate = reinterpret_cast<PFNGLBLENDFUNCSEPARATEPROC>(loader("glBlendFuncSeparate"));
    iglMultiDrawArrays   = reinterpret_cast<PFNGLMULTIDRAWARRAYSPROC>(loader("glMultiDrawArrays"));
    iglMultiDrawElements = reinterpret_cast<PFNGLMULTIDRAWELEMENTSPROC>(loader("glMultiDrawElements"));
    iglPointParameterfv  = reinterpret_cast<PFNGLPOINTPARAMETERFVPROC>(loader("glPointParameterfv"));
    iglPointParameterf   = reinterpret_cast<PFNGLPOINTPARAMETERFPROC>(loader("glPointParameterf"));
    iglPointParameteriv  = reinterpret_cast<PFNGLPOINTPARAMETERIVPROC>(loader("glPointParameteriv"));
    iglPointParameteri   = reinterpret_cast<PFNGLPOINTPARAMETERIPROC>(loader("glPointParameteri"));
}
} // namespace glr
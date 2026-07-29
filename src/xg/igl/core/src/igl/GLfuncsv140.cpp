#include <xg/igl/ogl/GLfuncsv140.hpp>

namespace xg
{
namespace glr
{


GLfuncsv140::GLfuncsv140()
  : oglBlendColor(nullptr)
  , oglBlendEquation(nullptr)
  , oglBlendFuncSeparate(nullptr)
  , oglMultiDrawArrays(nullptr)
  , oglMultiDrawElements(nullptr)
  , oglPointParameterfv(nullptr)
  , oglPointParameterf(nullptr)
  , oglPointParameteriv(nullptr)
  , oglPointParameteri(nullptr)
{}

void GLfuncsv140::loadFuncs(Loader loader)
{
    GLfuncsv130::loadFuncs(loader);
    oglBlendColor        = reinterpret_cast<PFNGLBLENDCOLORPROC>(loader("glBlendColor"));
    oglBlendEquation     = reinterpret_cast<PFNGLBLENDEQUATIONPROC>(loader("glBlendEquation"));
    oglBlendFuncSeparate = reinterpret_cast<PFNGLBLENDFUNCSEPARATEPROC>(loader("glBlendFuncSeparate"));
    oglMultiDrawArrays   = reinterpret_cast<PFNGLMULTIDRAWARRAYSPROC>(loader("glMultiDrawArrays"));
    oglMultiDrawElements = reinterpret_cast<PFNGLMULTIDRAWELEMENTSPROC>(loader("glMultiDrawElements"));
    oglPointParameterfv  = reinterpret_cast<PFNGLPOINTPARAMETERFVPROC>(loader("glPointParameterfv"));
    oglPointParameterf   = reinterpret_cast<PFNGLPOINTPARAMETERFPROC>(loader("glPointParameterf"));
    oglPointParameteriv  = reinterpret_cast<PFNGLPOINTPARAMETERIVPROC>(loader("glPointParameteriv"));
    oglPointParameteri   = reinterpret_cast<PFNGLPOINTPARAMETERIPROC>(loader("glPointParameteri"));
}

} // namespace glr
} // namespace xg
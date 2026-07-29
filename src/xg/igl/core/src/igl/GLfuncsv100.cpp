#include <xg/igl/ogl/GLfuncsv100.hpp>

namespace xg
{
namespace glr
{


GLfuncsv100::GLfuncsv100()
  : oglCullFace(nullptr)
  , oglFrontFace(nullptr)
  , oglHint(nullptr)
  , oglLineWidth(nullptr)
  , oglPointSize(nullptr)
  , oglPolygonMode(nullptr)
  , oglScissor(nullptr)
  , oglTexParameterf(nullptr)
  , oglTexParameterfv(nullptr)
  , oglTexParameteri(nullptr)
  , oglTexParameteriv(nullptr)
  , oglTexImage1D(nullptr)
  , oglTexImage2D(nullptr)
  , oglDrawBuffer(nullptr)
  , oglClear(nullptr)
  , oglClearColor(nullptr)
  , oglClearStencil(nullptr)
  , oglClearDepth(nullptr)
  , oglStencilMask(nullptr)
  , oglColorMask(nullptr)
  , oglDepthMask(nullptr)
  , oglDisable(nullptr)
  , oglEnable(nullptr)
  , oglFinish(nullptr)
  , oglFlush(nullptr)
  , oglBlendFunc(nullptr)
  , oglLogicOp(nullptr)
  , oglStencilFunc(nullptr)
  , oglStencilOp(nullptr)
  , oglDepthFunc(nullptr)
  , oglPixelStoref(nullptr)
  , oglPixelStorei(nullptr)
  , oglReadBuffer(nullptr)
  , oglReadPixels(nullptr)
  , oglGetBooleanv(nullptr)
  , oglGetDoublev(nullptr)
  , oglGetError(nullptr)
  , oglGetFloatv(nullptr)
  , oglGetIntegerv(nullptr)
  , oglGetString(nullptr)
  , oglGetTexImage(nullptr)
  , oglGetTexParameterfv(nullptr)
  , oglGetTexParameteriv(nullptr)
  , oglGetTexLevelParameterfv(nullptr)
  , oglGetTexLevelParameteriv(nullptr)
  , oglIsEnabled(nullptr)
  , oglDepthRange(nullptr)
  , oglViewport(nullptr)
{}

void GLfuncsv100::loadFuncs(Loader loader)
{
    oglCullFace               = (PFNGLCULLFACEPROC)loader("glCullFace");
    oglFrontFace              = (PFNGLFRONTFACEPROC)loader("glFrontFace");
    oglHint                   = (PFNGLHINTPROC)loader("glHint");
    oglLineWidth              = (PFNGLLINEWIDTHPROC)loader("glLineWidth");
    oglPointSize              = (PFNGLPOINTSIZEPROC)loader("glPointSize");
    oglPolygonMode            = (PFNGLPOLYGONMODEPROC)loader("glPolygonMode");
    oglScissor                = (PFNGLSCISSORPROC)loader("glScissor");
    oglTexParameterf          = (PFNGLTEXPARAMETERFPROC)loader("glTexParameterf");
    oglTexParameterfv         = (PFNGLTEXPARAMETERFVPROC)loader("glTexParameterfv");
    oglTexParameteri          = (PFNGLTEXPARAMETERIPROC)loader("glTexParameteri");
    oglTexParameteriv         = (PFNGLTEXPARAMETERIVPROC)loader("glTexParameteriv");
    oglTexImage1D             = (PFNGLTEXIMAGE1DPROC)loader("glTexImage1D");
    oglTexImage2D             = (PFNGLTEXIMAGE2DPROC)loader("glTexImage2D");
    oglDrawBuffer             = (PFNGLDRAWBUFFERPROC)loader("glDrawBuffer");
    oglClear                  = (PFNGLCLEARPROC)loader("glClear");
    oglClearColor             = (PFNGLCLEARCOLORPROC)loader("glClearColor");
    oglClearStencil           = (PFNGLCLEARSTENCILPROC)loader("glClearStencil");
    oglClearDepth             = (PFNGLCLEARDEPTHPROC)loader("glClearDepth");
    oglStencilMask            = (PFNGLSTENCILMASKPROC)loader("glStencilMask");
    oglColorMask              = (PFNGLCOLORMASKPROC)loader("glColorMask");
    oglDepthMask              = (PFNGLDEPTHMASKPROC)loader("glDepthMask");
    oglDisable                = (PFNGLDISABLEPROC)loader("glDisable");
    oglEnable                 = (PFNGLENABLEPROC)loader("glEnable");
    oglFinish                 = (PFNGLFINISHPROC)loader("glFinish");
    oglFlush                  = (PFNGLFLUSHPROC)loader("glFlush");
    oglBlendFunc              = (PFNGLBLENDFUNCPROC)loader("glBlendFunc");
    oglLogicOp                = (PFNGLLOGICOPPROC)loader("glLogicOp");
    oglStencilFunc            = (PFNGLSTENCILFUNCPROC)loader("glStencilFunc");
    oglStencilOp              = (PFNGLSTENCILOPPROC)loader("glStencilOp");
    oglDepthFunc              = (PFNGLDEPTHFUNCPROC)loader("glDepthFunc");
    oglPixelStoref            = (PFNGLPIXELSTOREFPROC)loader("glPixelStoref");
    oglPixelStorei            = (PFNGLPIXELSTOREIPROC)loader("glPixelStorei");
    oglReadBuffer             = (PFNGLREADBUFFERPROC)loader("glReadBuffer");
    oglReadPixels             = (PFNGLREADPIXELSPROC)loader("glReadPixels");
    oglGetBooleanv            = (PFNGLGETBOOLEANVPROC)loader("glGetBooleanv");
    oglGetDoublev             = (PFNGLGETDOUBLEVPROC)loader("glGetDoublev");
    oglGetError               = (PFNGLGETERRORPROC)loader("glGetError");
    oglGetFloatv              = (PFNGLGETFLOATVPROC)loader("glGetFloatv");
    oglGetIntegerv            = (PFNGLGETINTEGERVPROC)loader("glGetIntegerv");
    oglGetString              = (PFNGLGETSTRINGPROC)loader("glGetString");
    oglGetTexImage            = (PFNGLGETTEXIMAGEPROC)loader("glGetTexImage");
    oglGetTexParameterfv      = (PFNGLGETTEXPARAMETERFVPROC)loader("glGetTexParameterfv");
    oglGetTexParameteriv      = (PFNGLGETTEXPARAMETERIVPROC)loader("glGetTexParameteriv");
    oglGetTexLevelParameterfv = (PFNGLGETTEXLEVELPARAMETERFVPROC)loader("glGetTexLevelParameterfv");
    oglGetTexLevelParameteriv = (PFNGLGETTEXLEVELPARAMETERIVPROC)loader("glGetTexLevelParameteriv");
    oglIsEnabled              = (PFNGLISENABLEDPROC)loader("glIsEnabled");
    oglDepthRange             = (PFNGLDEPTHRANGEPROC)loader("glDepthRange");
    oglViewport               = (PFNGLVIEWPORTPROC)loader("glViewport");
}

} // namespace glr
} // namespace xg

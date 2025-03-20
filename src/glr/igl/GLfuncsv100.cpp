#include <glr/igl/GLfuncsv100.h>

namespace glr {


GLfuncsv100::GLfuncsv100()
  : iglCullFace(nullptr)
  , iglFrontFace(nullptr)
  , iglHint(nullptr)
  , iglLineWidth(nullptr)
  , iglPointSize(nullptr)
  , iglPolygonMode(nullptr)
  , iglScissor(nullptr)
  , iglTexParameterf(nullptr)
  , iglTexParameterfv(nullptr)
  , iglTexParameteri(nullptr)
  , iglTexParameteriv(nullptr)
  , iglTexImage1D(nullptr)
  , iglTexImage2D(nullptr)
  , iglDrawBuffer(nullptr)
  , iglClear(nullptr)
  , iglClearColor(nullptr)
  , iglClearStencil(nullptr)
  , iglClearDepth(nullptr)
  , iglStencilMask(nullptr)
  , iglColorMask(nullptr)
  , iglDepthMask(nullptr)
  , iglDisable(nullptr)
  , iglEnable(nullptr)
  , iglFinish(nullptr)
  , iglFlush(nullptr)
  , iglBlendFunc(nullptr)
  , iglLogicOp(nullptr)
  , iglStencilFunc(nullptr)
  , iglStencilOp(nullptr)
  , iglDepthFunc(nullptr)
  , iglPixelStoref(nullptr)
  , iglPixelStorei(nullptr)
  , iglReadBuffer(nullptr)
  , iglReadPixels(nullptr)
  , iglGetBooleanv(nullptr)
  , iglGetDoublev(nullptr)
  , iglGetError(nullptr)
  , iglGetFloatv(nullptr)
  , iglGetIntegerv(nullptr)
  , iglGetString(nullptr)
  , iglGetTexImage(nullptr)
  , iglGetTexParameterfv(nullptr)
  , iglGetTexParameteriv(nullptr)
  , iglGetTexLevelParameterfv(nullptr)
  , iglGetTexLevelParameteriv(nullptr)
  , iglIsEnabled(nullptr)
  , iglDepthRange(nullptr)
  , iglViewport(nullptr) {
}

void GLfuncsv100::loadFuncs(Loader loader) {
    iglCullFace               = (PFNGLCULLFACEPROC)loader("glCullFace");
    iglFrontFace              = (PFNGLFRONTFACEPROC)loader("glFrontFace");
    iglHint                   = (PFNGLHINTPROC)loader("glHint");
    iglLineWidth              = (PFNGLLINEWIDTHPROC)loader("glLineWidth");
    iglPointSize              = (PFNGLPOINTSIZEPROC)loader("glPointSize");
    iglPolygonMode            = (PFNGLPOLYGONMODEPROC)loader("glPolygonMode");
    iglScissor                = (PFNGLSCISSORPROC)loader("glScissor");
    iglTexParameterf          = (PFNGLTEXPARAMETERFPROC)loader("glTexParameterf");
    iglTexParameterfv         = (PFNGLTEXPARAMETERFVPROC)loader("glTexParameterfv");
    iglTexParameteri          = (PFNGLTEXPARAMETERIPROC)loader("glTexParameteri");
    iglTexParameteriv         = (PFNGLTEXPARAMETERIVPROC)loader("glTexParameteriv");
    iglTexImage1D             = (PFNGLTEXIMAGE1DPROC)loader("glTexImage1D");
    iglTexImage2D             = (PFNGLTEXIMAGE2DPROC)loader("glTexImage2D");
    iglDrawBuffer             = (PFNGLDRAWBUFFERPROC)loader("glDrawBuffer");
    iglClear                  = (PFNGLCLEARPROC)loader("glClear");
    iglClearColor             = (PFNGLCLEARCOLORPROC)loader("glClearColor");
    iglClearStencil           = (PFNGLCLEARSTENCILPROC)loader("glClearStencil");
    iglClearDepth             = (PFNGLCLEARDEPTHPROC)loader("glClearDepth");
    iglStencilMask            = (PFNGLSTENCILMASKPROC)loader("glStencilMask");
    iglColorMask              = (PFNGLCOLORMASKPROC)loader("glColorMask");
    iglDepthMask              = (PFNGLDEPTHMASKPROC)loader("glDepthMask");
    iglDisable                = (PFNGLDISABLEPROC)loader("glDisable");
    iglEnable                 = (PFNGLENABLEPROC)loader("glEnable");
    iglFinish                 = (PFNGLFINISHPROC)loader("glFinish");
    iglFlush                  = (PFNGLFLUSHPROC)loader("glFlush");
    iglBlendFunc              = (PFNGLBLENDFUNCPROC)loader("glBlendFunc");
    iglLogicOp                = (PFNGLLOGICOPPROC)loader("glLogicOp");
    iglStencilFunc            = (PFNGLSTENCILFUNCPROC)loader("glStencilFunc");
    iglStencilOp              = (PFNGLSTENCILOPPROC)loader("glStencilOp");
    iglDepthFunc              = (PFNGLDEPTHFUNCPROC)loader("glDepthFunc");
    iglPixelStoref            = (PFNGLPIXELSTOREFPROC)loader("glPixelStoref");
    iglPixelStorei            = (PFNGLPIXELSTOREIPROC)loader("glPixelStorei");
    iglReadBuffer             = (PFNGLREADBUFFERPROC)loader("glReadBuffer");
    iglReadPixels             = (PFNGLREADPIXELSPROC)loader("glReadPixels");
    iglGetBooleanv            = (PFNGLGETBOOLEANVPROC)loader("glGetBooleanv");
    iglGetDoublev             = (PFNGLGETDOUBLEVPROC)loader("glGetDoublev");
    iglGetError               = (PFNGLGETERRORPROC)loader("glGetError");
    iglGetFloatv              = (PFNGLGETFLOATVPROC)loader("glGetFloatv");
    iglGetIntegerv            = (PFNGLGETINTEGERVPROC)loader("glGetIntegerv");
    iglGetString              = (PFNGLGETSTRINGPROC)loader("glGetString");
    iglGetTexImage            = (PFNGLGETTEXIMAGEPROC)loader("glGetTexImage");
    iglGetTexParameterfv      = (PFNGLGETTEXPARAMETERFVPROC)loader("glGetTexParameterfv");
    iglGetTexParameteriv      = (PFNGLGETTEXPARAMETERIVPROC)loader("glGetTexParameteriv");
    iglGetTexLevelParameterfv = (PFNGLGETTEXLEVELPARAMETERFVPROC)loader("glGetTexLevelParameterfv");
    iglGetTexLevelParameteriv = (PFNGLGETTEXLEVELPARAMETERIVPROC)loader("glGetTexLevelParameteriv");
    iglIsEnabled              = (PFNGLISENABLEDPROC)loader("glIsEnabled");
    iglDepthRange             = (PFNGLDEPTHRANGEPROC)loader("glDepthRange");
    iglViewport               = (PFNGLVIEWPORTPROC)loader("glViewport");
}

} // namespace glr

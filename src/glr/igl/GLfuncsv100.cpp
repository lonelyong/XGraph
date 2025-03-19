#include <glr/igl/GLfuncsv100.h>

namespace glr {

VI_OBJECT_META_IMPL(GLfuncsv100, GLfuncs);

GLfuncsv100::GLfuncsv100()
  : glCullFace(nullptr)
  , glFrontFace(nullptr)
  , glHint(nullptr)
  , glLineWidth(nullptr)
  , glPointSize(nullptr)
  , glPolygonMode(nullptr)
  , glScissor(nullptr)
  , glTexParameterf(nullptr)
  , glTexParameterfv(nullptr)
  , glTexParameteri(nullptr)
  , glTexParameteriv(nullptr)
  , glTexImage1D(nullptr)
  , glTexImage2D(nullptr)
  , glDrawBuffer(nullptr)
  , glClear(nullptr)
  , glClearColor(nullptr)
  , glClearStencil(nullptr)
  , glClearDepth(nullptr)
  , glStencilMask(nullptr)
  , glColorMask(nullptr)
  , glDepthMask(nullptr)
  , glDisable(nullptr)
  , glEnable(nullptr)
  , glFinish(nullptr)
  , glFlush(nullptr)
  , glBlendFunc(nullptr)
  , glLogicOp(nullptr)
  , glStencilFunc(nullptr)
  , glStencilOp(nullptr)
  , glDepthFunc(nullptr)
  , glPixelStoref(nullptr)
  , glPixelStorei(nullptr)
  , glReadBuffer(nullptr)
  , glReadPixels(nullptr)
  , glGetBooleanv(nullptr)
  , glGetDoublev(nullptr)
  , glGetError(nullptr)
  , glGetFloatv(nullptr)
  , glGetIntegerv(nullptr)
  , glGetString(nullptr)
  , glGetTexImage(nullptr)
  , glGetTexParameterfv(nullptr)
  , glGetTexParameteriv(nullptr)
  , glGetTexLevelParameterfv(nullptr)
  , glGetTexLevelParameteriv(nullptr)
  , glIsEnabled(nullptr)
  , glDepthRange(nullptr)
  , glViewport(nullptr) {
}

void GLfuncsv100::loadFuncs(Loader loader) {
    glCullFace               = (PFNGLCULLFACEPROC)loader("glCullFace");
    glFrontFace              = (PFNGLFRONTFACEPROC)loader("glFrontFace");
    glHint                   = (PFNGLHINTPROC)loader("glHint");
    glLineWidth              = (PFNGLLINEWIDTHPROC)loader("glLineWidth");
    glPointSize              = (PFNGLPOINTSIZEPROC)loader("glPointSize");
    glPolygonMode            = (PFNGLPOLYGONMODEPROC)loader("glPolygonMode");
    glScissor                = (PFNGLSCISSORPROC)loader("glScissor");
    glTexParameterf          = (PFNGLTEXPARAMETERFPROC)loader("glTexParameterf");
    glTexParameterfv         = (PFNGLTEXPARAMETERFVPROC)loader("glTexParameterfv");
    glTexParameteri          = (PFNGLTEXPARAMETERIPROC)loader("glTexParameteri");
    glTexParameteriv         = (PFNGLTEXPARAMETERIVPROC)loader("glTexParameteriv");
    glTexImage1D             = (PFNGLTEXIMAGE1DPROC)loader("glTexImage1D");
    glTexImage2D             = (PFNGLTEXIMAGE2DPROC)loader("glTexImage2D");
    glDrawBuffer             = (PFNGLDRAWBUFFERPROC)loader("glDrawBuffer");
    glClear                  = (PFNGLCLEARPROC)loader("glClear");
    glClearColor             = (PFNGLCLEARCOLORPROC)loader("glClearColor");
    glClearStencil           = (PFNGLCLEARSTENCILPROC)loader("glClearStencil");
    glClearDepth             = (PFNGLCLEARDEPTHPROC)loader("glClearDepth");
    glStencilMask            = (PFNGLSTENCILMASKPROC)loader("glStencilMask");
    glColorMask              = (PFNGLCOLORMASKPROC)loader("glColorMask");
    glDepthMask              = (PFNGLDEPTHMASKPROC)loader("glDepthMask");
    glDisable                = (PFNGLDISABLEPROC)loader("glDisable");
    glEnable                 = (PFNGLENABLEPROC)loader("glEnable");
    glFinish                 = (PFNGLFINISHPROC)loader("glFinish");
    glFlush                  = (PFNGLFLUSHPROC)loader("glFlush");
    glBlendFunc              = (PFNGLBLENDFUNCPROC)loader("glBlendFunc");
    glLogicOp                = (PFNGLLOGICOPPROC)loader("glLogicOp");
    glStencilFunc            = (PFNGLSTENCILFUNCPROC)loader("glStencilFunc");
    glStencilOp              = (PFNGLSTENCILOPPROC)loader("glStencilOp");
    glDepthFunc              = (PFNGLDEPTHFUNCPROC)loader("glDepthFunc");
    glPixelStoref            = (PFNGLPIXELSTOREFPROC)loader("glPixelStoref");
    glPixelStorei            = (PFNGLPIXELSTOREIPROC)loader("glPixelStorei");
    glReadBuffer             = (PFNGLREADBUFFERPROC)loader("glReadBuffer");
    glReadPixels             = (PFNGLREADPIXELSPROC)loader("glReadPixels");
    glGetBooleanv            = (PFNGLGETBOOLEANVPROC)loader("glGetBooleanv");
    glGetDoublev             = (PFNGLGETDOUBLEVPROC)loader("glGetDoublev");
    glGetError               = (PFNGLGETERRORPROC)loader("glGetError");
    glGetFloatv              = (PFNGLGETFLOATVPROC)loader("glGetFloatv");
    glGetIntegerv            = (PFNGLGETINTEGERVPROC)loader("glGetIntegerv");
    glGetString              = (PFNGLGETSTRINGPROC)loader("glGetString");
    glGetTexImage            = (PFNGLGETTEXIMAGEPROC)loader("glGetTexImage");
    glGetTexParameterfv      = (PFNGLGETTEXPARAMETERFVPROC)loader("glGetTexParameterfv");
    glGetTexParameteriv      = (PFNGLGETTEXPARAMETERIVPROC)loader("glGetTexParameteriv");
    glGetTexLevelParameterfv = (PFNGLGETTEXLEVELPARAMETERFVPROC)loader("glGetTexLevelParameterfv");
    glGetTexLevelParameteriv = (PFNGLGETTEXLEVELPARAMETERIVPROC)loader("glGetTexLevelParameteriv");
    glIsEnabled              = (PFNGLISENABLEDPROC)loader("glIsEnabled");
    glDepthRange             = (PFNGLDEPTHRANGEPROC)loader("glDepthRange");
    glViewport               = (PFNGLVIEWPORTPROC)loader("glViewport");
}

} // namespace glr

#include "GLfuncsv400.h"

namespace glr {
GLfuncsv400::GLfuncsv400()
  : glBeginQueryIndexed(nullptr)
  , glBindTransformFeedback(nullptr)
  , glBlendEquationSeparatei(nullptr)
  , glBlendEquationi(nullptr)
  , glBlendFuncSeparatei(nullptr)
  , glBlendFunci(nullptr)
  , glDeleteTransformFeedbacks(nullptr)
  , glDrawArraysIndirect(nullptr)
  , glDrawElementsIndirect(nullptr)
  , glDrawTransformFeedbackStream(nullptr)
  , glDrawTransformFeedback(nullptr)
  , glEndQueryIndexed(nullptr)
  , glGenTransformFeedbacks(nullptr)
  , glGetActiveSubroutineName(nullptr)
  , glGetActiveSubroutineUniformName(nullptr)
  , glGetActiveSubroutineUniformiv(nullptr)
  , glGetProgramStageiv(nullptr)
  , glGetQueryIndexediv(nullptr)
  , glGetSubroutineIndex(nullptr)
  , glGetSubroutineUniformLocation(nullptr)
  , glGetUniformSubroutineuiv(nullptr)
  , glGetUniformdv(nullptr)
  , glIsTransformFeedback(nullptr)
  , glMinSampleShading(nullptr)
  , glPatchParameterfv(nullptr)
  , glPatchParameteri(nullptr)
  , glPauseTransformFeedback(nullptr)
  , glResumeTransformFeedback(nullptr)
  , glUniform1dv(nullptr)
  , glUniform1d(nullptr)
  , glUniform2dv(nullptr)
  , glUniform2d(nullptr)
  , glUniform3dv(nullptr)
  , glUniform3d(nullptr)
  , glUniform4dv(nullptr)
  , glUniform4d(nullptr)
  , glUniformMatrix2dv(nullptr)
  , glUniformMatrix2x3dv(nullptr)
  , glUniformMatrix2x4dv(nullptr)
  , glUniformMatrix3dv(nullptr)
  , glUniformMatrix3x2dv(nullptr)
  , glUniformMatrix3x4dv(nullptr)
  , glUniformMatrix4dv(nullptr)
  , glUniformMatrix4x2dv(nullptr)
  , glUniformMatrix4x3dv(nullptr)
  , glUniformSubroutinesuiv(nullptr) {
}

void GLfuncsv400::loadFuncs(Loader loader) {
    GLfuncsv330::loadFuncs(loader);
    glBeginQueryIndexed      = reinterpret_cast<PFNGLBEGINQUERYINDEXEDPROC>(loader("glBeginQueryIndexed"));
    glBindTransformFeedback  = reinterpret_cast<PFNGLBINDTRANSFORMFEEDBACKPROC>(loader("glBindTransformFeedback"));
    glBlendEquationSeparatei = reinterpret_cast<PFNGLBLENDEQUATIONSEPARATEIPROC>(loader("glBlendEquationSeparatei"));
    glBlendEquationi         = reinterpret_cast<PFNGLBLENDEQUATIONIPROC>(loader("glBlendEquationi"));
    glBlendFuncSeparatei     = reinterpret_cast<PFNGLBLENDFUNCSEPARATEIPROC>(loader("glBlendFuncSeparatei"));
    glBlendFunci             = reinterpret_cast<PFNGLBLENDFUNCIPROC>(loader("glBlendFunci"));
    glDeleteTransformFeedbacks =
        reinterpret_cast<PFNGLDELETETRANSFORMFEEDBACKSPROC>(loader("glDeleteTransformFeedbacks"));
    glDrawArraysIndirect   = reinterpret_cast<PFNGLDRAWARRAYSINDIRECTPROC>(loader("glDrawArraysIndirect"));
    glDrawElementsIndirect = reinterpret_cast<PFNGLDRAWELEMENTSINDIRECTPROC>(loader("glDrawElementsIndirect"));
    glDrawTransformFeedbackStream =
        reinterpret_cast<PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC>(loader("glDrawTransformFeedbackStream"));
    glDrawTransformFeedback   = reinterpret_cast<PFNGLDRAWTRANSFORMFEEDBACKPROC>(loader("glDrawTransformFeedback"));
    glEndQueryIndexed         = reinterpret_cast<PFNGLENDQUERYINDEXEDPROC>(loader("glEndQueryIndexed"));
    glGenTransformFeedbacks   = reinterpret_cast<PFNGLGENTRANSFORMFEEDBACKSPROC>(loader("glGenTransformFeedbacks"));
    glGetActiveSubroutineName = reinterpret_cast<PFNGLGETACTIVESUBROUTINENAMEPROC>(loader("glGetActiveSubroutineName"));
    glGetActiveSubroutineUniformName =
        reinterpret_cast<PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC>(loader("glGetActiveSubroutineUniformName"));
    glGetActiveSubroutineUniformiv =
        reinterpret_cast<PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC>(loader("glGetActiveSubroutineUniformiv"));
    glGetProgramStageiv  = reinterpret_cast<PFNGLGETPROGRAMSTAGEIVPROC>(loader("glGetProgramStageiv"));
    glGetQueryIndexediv  = reinterpret_cast<PFNGLGETQUERYINDEXEDIVPROC>(loader("glGetQueryIndexediv"));
    glGetSubroutineIndex = reinterpret_cast<PFNGLGETSUBROUTINEINDEXPROC>(loader("glGetSubroutineIndex"));
    glGetSubroutineUniformLocation =
        reinterpret_cast<PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC>(loader("glGetSubroutineUniformLocation"));
    glGetUniformSubroutineuiv = reinterpret_cast<PFNGLGETUNIFORMSUBROUTINEUIVPROC>(loader("glGetUniformSubroutineuiv"));
    glGetUniformdv            = reinterpret_cast<PFNGLGETUNIFORMDVPROC>(loader("glGetUniformdv"));
    glIsTransformFeedback     = reinterpret_cast<PFNGLISTRANSFORMFEEDBACKPROC>(loader("glIsTransformFeedback"));
    glMinSampleShading        = reinterpret_cast<PFNGLMINSAMPLESHADINGPROC>(loader("glMinSampleShading"));
    glPatchParameterfv        = reinterpret_cast<PFNGLPATCHPARAMETERFVPROC>(loader("glPatchParameterfv"));
    glPatchParameteri         = reinterpret_cast<PFNGLPATCHPARAMETERIPROC>(loader("glPatchParameteri"));
    glPauseTransformFeedback  = reinterpret_cast<PFNGLPAUSETRANSFORMFEEDBACKPROC>(loader("glPauseTransformFeedback"));
    glResumeTransformFeedback = reinterpret_cast<PFNGLRESUMETRANSFORMFEEDBACKPROC>(loader("glResumeTransformFeedback"));
    glUniform1dv              = reinterpret_cast<PFNGLUNIFORM1DVPROC>(loader("glUniform1dv"));
    glUniform1d               = reinterpret_cast<PFNGLUNIFORM1DPROC>(loader("glUniform1d"));
    glUniform2dv              = reinterpret_cast<PFNGLUNIFORM2DVPROC>(loader("glUniform2dv"));
    glUniform2d               = reinterpret_cast<PFNGLUNIFORM2DPROC>(loader("glUniform2d"));
    glUniform3dv              = reinterpret_cast<PFNGLUNIFORM3DVPROC>(loader("glUniform3dv"));
    glUniform3d               = reinterpret_cast<PFNGLUNIFORM3DPROC>(loader("glUniform3d"));
    glUniform4dv              = reinterpret_cast<PFNGLUNIFORM4DVPROC>(loader("glUniform4dv"));
    glUniform4d               = reinterpret_cast<PFNGLUNIFORM4DPROC>(loader("glUniform4d"));
    glUniformMatrix2dv        = reinterpret_cast<PFNGLUNIFORMMATRIX2DVPROC>(loader("glUniformMatrix2dv"));
    glUniformMatrix2x3dv      = reinterpret_cast<PFNGLUNIFORMMATRIX2X3DVPROC>(loader("glUniformMatrix2x3dv"));
    glUniformMatrix2x4dv      = reinterpret_cast<PFNGLUNIFORMMATRIX2X4DVPROC>(loader("glUniformMatrix2x4dv"));
    glUniformMatrix3dv        = reinterpret_cast<PFNGLUNIFORMMATRIX3DVPROC>(loader("glUniformMatrix3dv"));
    glUniformMatrix3x2dv      = reinterpret_cast<PFNGLUNIFORMMATRIX3X2DVPROC>(loader("glUniformMatrix3x2dv"));
    glUniformMatrix3x4dv      = reinterpret_cast<PFNGLUNIFORMMATRIX3X4DVPROC>(loader("glUniformMatrix3x4dv"));
    glUniformMatrix4dv        = reinterpret_cast<PFNGLUNIFORMMATRIX4DVPROC>(loader("glUniformMatrix4dv"));
    glUniformMatrix4x2dv      = reinterpret_cast<PFNGLUNIFORMMATRIX4X2DVPROC>(loader("glUniformMatrix4x2dv"));
    glUniformMatrix4x3dv      = reinterpret_cast<PFNGLUNIFORMMATRIX4X3DVPROC>(loader("glUniformMatrix4x3dv"));
    glUniformSubroutinesuiv   = reinterpret_cast<PFNGLUNIFORMSUBROUTINESUIVPROC>(loader("glUniformSubroutinesuiv"));
}
} // namespace glr
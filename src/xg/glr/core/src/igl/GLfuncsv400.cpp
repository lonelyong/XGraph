#include <xg/glr/igl/GLfuncsv400.h>

namespace xg {
namespace glr {


GLfuncsv400::GLfuncsv400()
  : iglBeginQueryIndexed(nullptr)
  , iglBindTransformFeedback(nullptr)
  , iglBlendEquationSeparatei(nullptr)
  , iglBlendEquationi(nullptr)
  , iglBlendFuncSeparatei(nullptr)
  , iglBlendFunci(nullptr)
  , iglDeleteTransformFeedbacks(nullptr)
  , iglDrawArraysIndirect(nullptr)
  , iglDrawElementsIndirect(nullptr)
  , iglDrawTransformFeedbackStream(nullptr)
  , iglDrawTransformFeedback(nullptr)
  , iglEndQueryIndexed(nullptr)
  , iglGenTransformFeedbacks(nullptr)
  , iglGetActiveSubroutineName(nullptr)
  , iglGetActiveSubroutineUniformName(nullptr)
  , iglGetActiveSubroutineUniformiv(nullptr)
  , iglGetProgramStageiv(nullptr)
  , iglGetQueryIndexediv(nullptr)
  , iglGetSubroutineIndex(nullptr)
  , iglGetSubroutineUniformLocation(nullptr)
  , iglGetUniformSubroutineuiv(nullptr)
  , iglGetUniformdv(nullptr)
  , iglIsTransformFeedback(nullptr)
  , iglMinSampleShading(nullptr)
  , iglPatchParameterfv(nullptr)
  , iglPatchParameteri(nullptr)
  , iglPauseTransformFeedback(nullptr)
  , iglResumeTransformFeedback(nullptr)
  , iglUniform1dv(nullptr)
  , iglUniform1d(nullptr)
  , iglUniform2dv(nullptr)
  , iglUniform2d(nullptr)
  , iglUniform3dv(nullptr)
  , iglUniform3d(nullptr)
  , iglUniform4dv(nullptr)
  , iglUniform4d(nullptr)
  , iglUniformMatrix2dv(nullptr)
  , iglUniformMatrix2x3dv(nullptr)
  , iglUniformMatrix2x4dv(nullptr)
  , iglUniformMatrix3dv(nullptr)
  , iglUniformMatrix3x2dv(nullptr)
  , iglUniformMatrix3x4dv(nullptr)
  , iglUniformMatrix4dv(nullptr)
  , iglUniformMatrix4x2dv(nullptr)
  , iglUniformMatrix4x3dv(nullptr)
  , iglUniformSubroutinesuiv(nullptr) {
}

void GLfuncsv400::loadFuncs(Loader loader) {
    GLfuncsv330::loadFuncs(loader);
    iglBeginQueryIndexed      = reinterpret_cast<PFNGLBEGINQUERYINDEXEDPROC>(loader("glBeginQueryIndexed"));
    iglBindTransformFeedback  = reinterpret_cast<PFNGLBINDTRANSFORMFEEDBACKPROC>(loader("glBindTransformFeedback"));
    iglBlendEquationSeparatei = reinterpret_cast<PFNGLBLENDEQUATIONSEPARATEIPROC>(loader("glBlendEquationSeparatei"));
    iglBlendEquationi         = reinterpret_cast<PFNGLBLENDEQUATIONIPROC>(loader("glBlendEquationi"));
    iglBlendFuncSeparatei     = reinterpret_cast<PFNGLBLENDFUNCSEPARATEIPROC>(loader("glBlendFuncSeparatei"));
    iglBlendFunci             = reinterpret_cast<PFNGLBLENDFUNCIPROC>(loader("glBlendFunci"));
    iglDeleteTransformFeedbacks =
        reinterpret_cast<PFNGLDELETETRANSFORMFEEDBACKSPROC>(loader("glDeleteTransformFeedbacks"));
    iglDrawArraysIndirect   = reinterpret_cast<PFNGLDRAWARRAYSINDIRECTPROC>(loader("glDrawArraysIndirect"));
    iglDrawElementsIndirect = reinterpret_cast<PFNGLDRAWELEMENTSINDIRECTPROC>(loader("glDrawElementsIndirect"));
    iglDrawTransformFeedbackStream =
        reinterpret_cast<PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC>(loader("glDrawTransformFeedbackStream"));
    iglDrawTransformFeedback   = reinterpret_cast<PFNGLDRAWTRANSFORMFEEDBACKPROC>(loader("glDrawTransformFeedback"));
    iglEndQueryIndexed         = reinterpret_cast<PFNGLENDQUERYINDEXEDPROC>(loader("glEndQueryIndexed"));
    iglGenTransformFeedbacks   = reinterpret_cast<PFNGLGENTRANSFORMFEEDBACKSPROC>(loader("glGenTransformFeedbacks"));
    iglGetActiveSubroutineName = reinterpret_cast<PFNGLGETACTIVESUBROUTINENAMEPROC>(loader("glGetActiveSubroutineName"));
    iglGetActiveSubroutineUniformName =
        reinterpret_cast<PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC>(loader("glGetActiveSubroutineUniformName"));
    iglGetActiveSubroutineUniformiv =
        reinterpret_cast<PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC>(loader("glGetActiveSubroutineUniformiv"));
    iglGetProgramStageiv  = reinterpret_cast<PFNGLGETPROGRAMSTAGEIVPROC>(loader("glGetProgramStageiv"));
    iglGetQueryIndexediv  = reinterpret_cast<PFNGLGETQUERYINDEXEDIVPROC>(loader("glGetQueryIndexediv"));
    iglGetSubroutineIndex = reinterpret_cast<PFNGLGETSUBROUTINEINDEXPROC>(loader("glGetSubroutineIndex"));
    iglGetSubroutineUniformLocation =
        reinterpret_cast<PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC>(loader("glGetSubroutineUniformLocation"));
    iglGetUniformSubroutineuiv = reinterpret_cast<PFNGLGETUNIFORMSUBROUTINEUIVPROC>(loader("glGetUniformSubroutineuiv"));
    iglGetUniformdv            = reinterpret_cast<PFNGLGETUNIFORMDVPROC>(loader("glGetUniformdv"));
    iglIsTransformFeedback     = reinterpret_cast<PFNGLISTRANSFORMFEEDBACKPROC>(loader("glIsTransformFeedback"));
    iglMinSampleShading        = reinterpret_cast<PFNGLMINSAMPLESHADINGPROC>(loader("glMinSampleShading"));
    iglPatchParameterfv        = reinterpret_cast<PFNGLPATCHPARAMETERFVPROC>(loader("glPatchParameterfv"));
    iglPatchParameteri         = reinterpret_cast<PFNGLPATCHPARAMETERIPROC>(loader("glPatchParameteri"));
    iglPauseTransformFeedback  = reinterpret_cast<PFNGLPAUSETRANSFORMFEEDBACKPROC>(loader("glPauseTransformFeedback"));
    iglResumeTransformFeedback = reinterpret_cast<PFNGLRESUMETRANSFORMFEEDBACKPROC>(loader("glResumeTransformFeedback"));
    iglUniform1dv              = reinterpret_cast<PFNGLUNIFORM1DVPROC>(loader("glUniform1dv"));
    iglUniform1d               = reinterpret_cast<PFNGLUNIFORM1DPROC>(loader("glUniform1d"));
    iglUniform2dv              = reinterpret_cast<PFNGLUNIFORM2DVPROC>(loader("glUniform2dv"));
    iglUniform2d               = reinterpret_cast<PFNGLUNIFORM2DPROC>(loader("glUniform2d"));
    iglUniform3dv              = reinterpret_cast<PFNGLUNIFORM3DVPROC>(loader("glUniform3dv"));
    iglUniform3d               = reinterpret_cast<PFNGLUNIFORM3DPROC>(loader("glUniform3d"));
    iglUniform4dv              = reinterpret_cast<PFNGLUNIFORM4DVPROC>(loader("glUniform4dv"));
    iglUniform4d               = reinterpret_cast<PFNGLUNIFORM4DPROC>(loader("glUniform4d"));
    iglUniformMatrix2dv        = reinterpret_cast<PFNGLUNIFORMMATRIX2DVPROC>(loader("glUniformMatrix2dv"));
    iglUniformMatrix2x3dv      = reinterpret_cast<PFNGLUNIFORMMATRIX2X3DVPROC>(loader("glUniformMatrix2x3dv"));
    iglUniformMatrix2x4dv      = reinterpret_cast<PFNGLUNIFORMMATRIX2X4DVPROC>(loader("glUniformMatrix2x4dv"));
    iglUniformMatrix3dv        = reinterpret_cast<PFNGLUNIFORMMATRIX3DVPROC>(loader("glUniformMatrix3dv"));
    iglUniformMatrix3x2dv      = reinterpret_cast<PFNGLUNIFORMMATRIX3X2DVPROC>(loader("glUniformMatrix3x2dv"));
    iglUniformMatrix3x4dv      = reinterpret_cast<PFNGLUNIFORMMATRIX3X4DVPROC>(loader("glUniformMatrix3x4dv"));
    iglUniformMatrix4dv        = reinterpret_cast<PFNGLUNIFORMMATRIX4DVPROC>(loader("glUniformMatrix4dv"));
    iglUniformMatrix4x2dv      = reinterpret_cast<PFNGLUNIFORMMATRIX4X2DVPROC>(loader("glUniformMatrix4x2dv"));
    iglUniformMatrix4x3dv      = reinterpret_cast<PFNGLUNIFORMMATRIX4X3DVPROC>(loader("glUniformMatrix4x3dv"));
    iglUniformSubroutinesuiv   = reinterpret_cast<PFNGLUNIFORMSUBROUTINESUIVPROC>(loader("glUniformSubroutinesuiv"));
}
} // namespace glr
} // namespace xg
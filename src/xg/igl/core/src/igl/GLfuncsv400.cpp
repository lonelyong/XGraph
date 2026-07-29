#include <xg/igl/ogl/GLfuncsv400.hpp>

namespace xg
{
namespace glr
{


GLfuncsv400::GLfuncsv400()
  : oglBeginQueryIndexed(nullptr)
  , oglBindTransformFeedback(nullptr)
  , oglBlendEquationSeparatei(nullptr)
  , oglBlendEquationi(nullptr)
  , oglBlendFuncSeparatei(nullptr)
  , oglBlendFunci(nullptr)
  , oglDeleteTransformFeedbacks(nullptr)
  , oglDrawArraysIndirect(nullptr)
  , oglDrawElementsIndirect(nullptr)
  , oglDrawTransformFeedbackStream(nullptr)
  , oglDrawTransformFeedback(nullptr)
  , oglEndQueryIndexed(nullptr)
  , oglGenTransformFeedbacks(nullptr)
  , oglGetActiveSubroutineName(nullptr)
  , oglGetActiveSubroutineUniformName(nullptr)
  , oglGetActiveSubroutineUniformiv(nullptr)
  , oglGetProgramStageiv(nullptr)
  , oglGetQueryIndexediv(nullptr)
  , oglGetSubroutineIndex(nullptr)
  , oglGetSubroutineUniformLocation(nullptr)
  , oglGetUniformSubroutineuiv(nullptr)
  , oglGetUniformdv(nullptr)
  , oglIsTransformFeedback(nullptr)
  , oglMinSampleShading(nullptr)
  , oglPatchParameterfv(nullptr)
  , oglPatchParameteri(nullptr)
  , oglPauseTransformFeedback(nullptr)
  , oglResumeTransformFeedback(nullptr)
  , oglUniform1dv(nullptr)
  , oglUniform1d(nullptr)
  , oglUniform2dv(nullptr)
  , oglUniform2d(nullptr)
  , oglUniform3dv(nullptr)
  , oglUniform3d(nullptr)
  , oglUniform4dv(nullptr)
  , oglUniform4d(nullptr)
  , oglUniformMatrix2dv(nullptr)
  , oglUniformMatrix2x3dv(nullptr)
  , oglUniformMatrix2x4dv(nullptr)
  , oglUniformMatrix3dv(nullptr)
  , oglUniformMatrix3x2dv(nullptr)
  , oglUniformMatrix3x4dv(nullptr)
  , oglUniformMatrix4dv(nullptr)
  , oglUniformMatrix4x2dv(nullptr)
  , oglUniformMatrix4x3dv(nullptr)
  , oglUniformSubroutinesuiv(nullptr)
{}

void GLfuncsv400::loadFuncs(Loader loader)
{
    GLfuncsv330::loadFuncs(loader);
    oglBeginQueryIndexed              = reinterpret_cast<PFNGLBEGINQUERYINDEXEDPROC>(loader("glBeginQueryIndexed"));
    oglBindTransformFeedback          = reinterpret_cast<PFNGLBINDTRANSFORMFEEDBACKPROC>(loader("glBindTransformFeedback"));
    oglBlendEquationSeparatei         = reinterpret_cast<PFNGLBLENDEQUATIONSEPARATEIPROC>(loader("glBlendEquationSeparatei"));
    oglBlendEquationi                 = reinterpret_cast<PFNGLBLENDEQUATIONIPROC>(loader("glBlendEquationi"));
    oglBlendFuncSeparatei             = reinterpret_cast<PFNGLBLENDFUNCSEPARATEIPROC>(loader("glBlendFuncSeparatei"));
    oglBlendFunci                     = reinterpret_cast<PFNGLBLENDFUNCIPROC>(loader("glBlendFunci"));
    oglDeleteTransformFeedbacks       = reinterpret_cast<PFNGLDELETETRANSFORMFEEDBACKSPROC>(loader("glDeleteTransformFeedbacks"));
    oglDrawArraysIndirect             = reinterpret_cast<PFNGLDRAWARRAYSINDIRECTPROC>(loader("glDrawArraysIndirect"));
    oglDrawElementsIndirect           = reinterpret_cast<PFNGLDRAWELEMENTSINDIRECTPROC>(loader("glDrawElementsIndirect"));
    oglDrawTransformFeedbackStream    = reinterpret_cast<PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC>(loader("glDrawTransformFeedbackStream"));
    oglDrawTransformFeedback          = reinterpret_cast<PFNGLDRAWTRANSFORMFEEDBACKPROC>(loader("glDrawTransformFeedback"));
    oglEndQueryIndexed                = reinterpret_cast<PFNGLENDQUERYINDEXEDPROC>(loader("glEndQueryIndexed"));
    oglGenTransformFeedbacks          = reinterpret_cast<PFNGLGENTRANSFORMFEEDBACKSPROC>(loader("glGenTransformFeedbacks"));
    oglGetActiveSubroutineName        = reinterpret_cast<PFNGLGETACTIVESUBROUTINENAMEPROC>(loader("glGetActiveSubroutineName"));
    oglGetActiveSubroutineUniformName = reinterpret_cast<PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC>(loader("glGetActiveSubroutineUniformName"));
    oglGetActiveSubroutineUniformiv   = reinterpret_cast<PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC>(loader("glGetActiveSubroutineUniformiv"));
    oglGetProgramStageiv              = reinterpret_cast<PFNGLGETPROGRAMSTAGEIVPROC>(loader("glGetProgramStageiv"));
    oglGetQueryIndexediv              = reinterpret_cast<PFNGLGETQUERYINDEXEDIVPROC>(loader("glGetQueryIndexediv"));
    oglGetSubroutineIndex             = reinterpret_cast<PFNGLGETSUBROUTINEINDEXPROC>(loader("glGetSubroutineIndex"));
    oglGetSubroutineUniformLocation   = reinterpret_cast<PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC>(loader("glGetSubroutineUniformLocation"));
    oglGetUniformSubroutineuiv        = reinterpret_cast<PFNGLGETUNIFORMSUBROUTINEUIVPROC>(loader("glGetUniformSubroutineuiv"));
    oglGetUniformdv                   = reinterpret_cast<PFNGLGETUNIFORMDVPROC>(loader("glGetUniformdv"));
    oglIsTransformFeedback            = reinterpret_cast<PFNGLISTRANSFORMFEEDBACKPROC>(loader("glIsTransformFeedback"));
    oglMinSampleShading               = reinterpret_cast<PFNGLMINSAMPLESHADINGPROC>(loader("glMinSampleShading"));
    oglPatchParameterfv               = reinterpret_cast<PFNGLPATCHPARAMETERFVPROC>(loader("glPatchParameterfv"));
    oglPatchParameteri                = reinterpret_cast<PFNGLPATCHPARAMETERIPROC>(loader("glPatchParameteri"));
    oglPauseTransformFeedback         = reinterpret_cast<PFNGLPAUSETRANSFORMFEEDBACKPROC>(loader("glPauseTransformFeedback"));
    oglResumeTransformFeedback        = reinterpret_cast<PFNGLRESUMETRANSFORMFEEDBACKPROC>(loader("glResumeTransformFeedback"));
    oglUniform1dv                     = reinterpret_cast<PFNGLUNIFORM1DVPROC>(loader("glUniform1dv"));
    oglUniform1d                      = reinterpret_cast<PFNGLUNIFORM1DPROC>(loader("glUniform1d"));
    oglUniform2dv                     = reinterpret_cast<PFNGLUNIFORM2DVPROC>(loader("glUniform2dv"));
    oglUniform2d                      = reinterpret_cast<PFNGLUNIFORM2DPROC>(loader("glUniform2d"));
    oglUniform3dv                     = reinterpret_cast<PFNGLUNIFORM3DVPROC>(loader("glUniform3dv"));
    oglUniform3d                      = reinterpret_cast<PFNGLUNIFORM3DPROC>(loader("glUniform3d"));
    oglUniform4dv                     = reinterpret_cast<PFNGLUNIFORM4DVPROC>(loader("glUniform4dv"));
    oglUniform4d                      = reinterpret_cast<PFNGLUNIFORM4DPROC>(loader("glUniform4d"));
    oglUniformMatrix2dv               = reinterpret_cast<PFNGLUNIFORMMATRIX2DVPROC>(loader("glUniformMatrix2dv"));
    oglUniformMatrix2x3dv             = reinterpret_cast<PFNGLUNIFORMMATRIX2X3DVPROC>(loader("glUniformMatrix2x3dv"));
    oglUniformMatrix2x4dv             = reinterpret_cast<PFNGLUNIFORMMATRIX2X4DVPROC>(loader("glUniformMatrix2x4dv"));
    oglUniformMatrix3dv               = reinterpret_cast<PFNGLUNIFORMMATRIX3DVPROC>(loader("glUniformMatrix3dv"));
    oglUniformMatrix3x2dv             = reinterpret_cast<PFNGLUNIFORMMATRIX3X2DVPROC>(loader("glUniformMatrix3x2dv"));
    oglUniformMatrix3x4dv             = reinterpret_cast<PFNGLUNIFORMMATRIX3X4DVPROC>(loader("glUniformMatrix3x4dv"));
    oglUniformMatrix4dv               = reinterpret_cast<PFNGLUNIFORMMATRIX4DVPROC>(loader("glUniformMatrix4dv"));
    oglUniformMatrix4x2dv             = reinterpret_cast<PFNGLUNIFORMMATRIX4X2DVPROC>(loader("glUniformMatrix4x2dv"));
    oglUniformMatrix4x3dv             = reinterpret_cast<PFNGLUNIFORMMATRIX4X3DVPROC>(loader("glUniformMatrix4x3dv"));
    oglUniformSubroutinesuiv          = reinterpret_cast<PFNGLUNIFORMSUBROUTINESUIVPROC>(loader("glUniformSubroutinesuiv"));
}

} // namespace glr
} // namespace xg
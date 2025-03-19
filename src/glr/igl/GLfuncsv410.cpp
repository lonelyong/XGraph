#include "GLfuncsv410.h"

namespace glr {

VI_OBJECT_META_IMPL(GLfuncsv410, GLfuncsv400);

GLfuncsv410::GLfuncsv410()
  : glActiveShaderProgram(nullptr)
  , glBindProgramPipeline(nullptr)
  , glClearDepthf(nullptr)
  , glCreateShaderProgramv(nullptr)
  , glDeleteProgramPipelines(nullptr)
  , glDepthRangeArrayv(nullptr)
  , glDepthRangeIndexed(nullptr)
  , glDepthRangef(nullptr)
  , glGenProgramPipelines(nullptr)
  , glGetDoublei_v(nullptr)
  , glGetFloati_v(nullptr)
  , glGetProgramBinary(nullptr)
  , glGetProgramPipelineInfoLog(nullptr)
  , glGetProgramPipelineiv(nullptr)
  , glGetShaderPrecisionFormat(nullptr)
  , glGetVertexAttribLdv(nullptr)
  , glIsProgramPipeline(nullptr)
  , glProgramBinary(nullptr)
  , glProgramParameteri(nullptr)
  , glProgramUniform1dv(nullptr)
  , glProgramUniform1d(nullptr)
  , glProgramUniform1fv(nullptr)
  , glProgramUniform1f(nullptr)
  , glProgramUniform1iv(nullptr)
  , glProgramUniform1i(nullptr)
  , glProgramUniform1uiv(nullptr)
  , glProgramUniform1ui(nullptr)
  , glProgramUniform2dv(nullptr)
  , glProgramUniform2d(nullptr)
  , glProgramUniform2fv(nullptr)
  , glProgramUniform2f(nullptr)
  , glProgramUniform2iv(nullptr)
  , glProgramUniform2i(nullptr)
  , glProgramUniform2uiv(nullptr)
  , glProgramUniform2ui(nullptr)
  , glProgramUniform3dv(nullptr)
  , glProgramUniform3d(nullptr)
  , glProgramUniform3fv(nullptr)
  , glProgramUniform3f(nullptr)
  , glProgramUniform3iv(nullptr)
  , glProgramUniform3i(nullptr)
  , glProgramUniform3uiv(nullptr)
  , glProgramUniform3ui(nullptr)
  , glProgramUniform4dv(nullptr)
  , glProgramUniform4d(nullptr)
  , glProgramUniform4fv(nullptr)
  , glProgramUniform4f(nullptr)
  , glProgramUniform4iv(nullptr)
  , glProgramUniform4i(nullptr)
  , glProgramUniform4uiv(nullptr)
  , glProgramUniform4ui(nullptr)
  , glProgramUniformMatrix2dv(nullptr)
  , glProgramUniformMatrix2fv(nullptr)
  , glProgramUniformMatrix2x3dv(nullptr)
  , glProgramUniformMatrix2x3fv(nullptr)
  , glProgramUniformMatrix2x4dv(nullptr)
  , glProgramUniformMatrix2x4fv(nullptr)
  , glProgramUniformMatrix3dv(nullptr)
  , glProgramUniformMatrix3fv(nullptr)
  , glProgramUniformMatrix3x2dv(nullptr)
  , glProgramUniformMatrix3x2fv(nullptr)
  , glProgramUniformMatrix3x4dv(nullptr)
  , glProgramUniformMatrix3x4fv(nullptr)
  , glProgramUniformMatrix4dv(nullptr)
  , glProgramUniformMatrix4fv(nullptr)
  , glProgramUniformMatrix4x2dv(nullptr)
  , glProgramUniformMatrix4x2fv(nullptr)
  , glProgramUniformMatrix4x3dv(nullptr)
  , glProgramUniformMatrix4x3fv(nullptr)
  , glReleaseShaderCompiler(nullptr)
  , glScissorArrayv(nullptr)
  , glScissorIndexedv(nullptr)
  , glScissorIndexed(nullptr)
  , glShaderBinary(nullptr)
  , glUseProgramStages(nullptr)
  , glValidateProgramPipeline(nullptr)
  , glVertexAttribL1dv(nullptr)
  , glVertexAttribL1d(nullptr)
  , glVertexAttribL2dv(nullptr)
  , glVertexAttribL2d(nullptr)
  , glVertexAttribL3dv(nullptr)
  , glVertexAttribL3d(nullptr)
  , glVertexAttribL4dv(nullptr)
  , glVertexAttribL4d(nullptr)
  , glVertexAttribLPointer(nullptr)
  , glViewportArrayv(nullptr)
  , glViewportIndexedfv(nullptr)
  , glViewportIndexedf(nullptr) {
}

void GLfuncsv410::loadFuncs(Loader loader) {
    glActiveShaderProgram    = reinterpret_cast<PFNGLACTIVESHADERPROGRAMPROC>(loader("glActiveShaderProgram"));
    glBindProgramPipeline    = reinterpret_cast<PFNGLBINDPROGRAMPIPELINEPROC>(loader("glBindProgramPipeline"));
    glClearDepthf            = reinterpret_cast<PFNGLCLEARDEPTHFPROC>(loader("glClearDepthf"));
    glCreateShaderProgramv   = reinterpret_cast<PFNGLCREATESHADERPROGRAMVPROC>(loader("glCreateShaderProgramv"));
    glDeleteProgramPipelines = reinterpret_cast<PFNGLDELETEPROGRAMPIPELINESPROC>(loader("glDeleteProgramPipelines"));
    glDepthRangeArrayv       = reinterpret_cast<PFNGLDEPTHRANGEARRAYVPROC>(loader("glDepthRangeArrayv"));
    glDepthRangeIndexed      = reinterpret_cast<PFNGLDEPTHRANGEINDEXEDPROC>(loader("glDepthRangeIndexed"));
    glDepthRangef            = reinterpret_cast<PFNGLDEPTHRANGEFPROC>(loader("glDepthRangef"));
    glGenProgramPipelines    = reinterpret_cast<PFNGLGENPROGRAMPIPELINESPROC>(loader("glGenProgramPipelines"));
    glGetDoublei_v           = reinterpret_cast<PFNGLGETDOUBLEI_VPROC>(loader("glGetDoublei_v"));
    glGetFloati_v            = reinterpret_cast<PFNGLGETFLOATI_VPROC>(loader("glGetFloati_v"));
    glGetProgramBinary       = reinterpret_cast<PFNGLGETPROGRAMBINARYPROC>(loader("glGetProgramBinary"));
    glGetProgramPipelineInfoLog =
        reinterpret_cast<PFNGLGETPROGRAMPIPELINEINFOLOGPROC>(loader("glGetProgramPipelineInfoLog"));
    glGetProgramPipelineiv = reinterpret_cast<PFNGLGETPROGRAMPIPELINEIVPROC>(loader("glGetProgramPipelineiv"));
    glGetShaderPrecisionFormat =
        reinterpret_cast<PFNGLGETSHADERPRECISIONFORMATPROC>(loader("glGetShaderPrecisionFormat"));
    glGetVertexAttribLdv      = reinterpret_cast<PFNGLGETVERTEXATTRIBLDVPROC>(loader("glGetVertexAttribLdv"));
    glIsProgramPipeline       = reinterpret_cast<PFNGLISPROGRAMPIPELINEPROC>(loader("glIsProgramPipeline"));
    glProgramBinary           = reinterpret_cast<PFNGLPROGRAMBINARYPROC>(loader("glProgramBinary"));
    glProgramParameteri       = reinterpret_cast<PFNGLPROGRAMPARAMETERIPROC>(loader("glProgramParameteri"));
    glProgramUniform1dv       = reinterpret_cast<PFNGLPROGRAMUNIFORM1DVPROC>(loader("glProgramUniform1dv"));
    glProgramUniform1d        = reinterpret_cast<PFNGLPROGRAMUNIFORM1DPROC>(loader("glProgramUniform1d"));
    glProgramUniform1fv       = reinterpret_cast<PFNGLPROGRAMUNIFORM1FVPROC>(loader("glProgramUniform1fv"));
    glProgramUniform1f        = reinterpret_cast<PFNGLPROGRAMUNIFORM1FPROC>(loader("glProgramUniform1f"));
    glProgramUniform1iv       = reinterpret_cast<PFNGLPROGRAMUNIFORM1IVPROC>(loader("glProgramUniform1iv"));
    glProgramUniform1i        = reinterpret_cast<PFNGLPROGRAMUNIFORM1IPROC>(loader("glProgramUniform1i"));
    glProgramUniform1uiv      = reinterpret_cast<PFNGLPROGRAMUNIFORM1UIVPROC>(loader("glProgramUniform1uiv"));
    glProgramUniform1ui       = reinterpret_cast<PFNGLPROGRAMUNIFORM1UIPROC>(loader("glProgramUniform1ui"));
    glProgramUniform2dv       = reinterpret_cast<PFNGLPROGRAMUNIFORM2DVPROC>(loader("glProgramUniform2dv"));
    glProgramUniform2d        = reinterpret_cast<PFNGLPROGRAMUNIFORM2DPROC>(loader("glProgramUniform2d"));
    glProgramUniform2fv       = reinterpret_cast<PFNGLPROGRAMUNIFORM2FVPROC>(loader("glProgramUniform2fv"));
    glProgramUniform2f        = reinterpret_cast<PFNGLPROGRAMUNIFORM2FPROC>(loader("glProgramUniform2f"));
    glProgramUniform2iv       = reinterpret_cast<PFNGLPROGRAMUNIFORM2IVPROC>(loader("glProgramUniform2iv"));
    glProgramUniform2i        = reinterpret_cast<PFNGLPROGRAMUNIFORM2IPROC>(loader("glProgramUniform2i"));
    glProgramUniform2uiv      = reinterpret_cast<PFNGLPROGRAMUNIFORM2UIVPROC>(loader("glProgramUniform2uiv"));
    glProgramUniform2ui       = reinterpret_cast<PFNGLPROGRAMUNIFORM2UIPROC>(loader("glProgramUniform2ui"));
    glProgramUniform3dv       = reinterpret_cast<PFNGLPROGRAMUNIFORM3DVPROC>(loader("glProgramUniform3dv"));
    glProgramUniform3d        = reinterpret_cast<PFNGLPROGRAMUNIFORM3DPROC>(loader("glProgramUniform3d"));
    glProgramUniform3fv       = reinterpret_cast<PFNGLPROGRAMUNIFORM3FVPROC>(loader("glProgramUniform3fv"));
    glProgramUniform3f        = reinterpret_cast<PFNGLPROGRAMUNIFORM3FPROC>(loader("glProgramUniform3f"));
    glProgramUniform3iv       = reinterpret_cast<PFNGLPROGRAMUNIFORM3IVPROC>(loader("glProgramUniform3iv"));
    glProgramUniform3i        = reinterpret_cast<PFNGLPROGRAMUNIFORM3IPROC>(loader("glProgramUniform3i"));
    glProgramUniform3uiv      = reinterpret_cast<PFNGLPROGRAMUNIFORM3UIVPROC>(loader("glProgramUniform3uiv"));
    glProgramUniform3ui       = reinterpret_cast<PFNGLPROGRAMUNIFORM3UIPROC>(loader("glProgramUniform3ui"));
    glProgramUniform4dv       = reinterpret_cast<PFNGLPROGRAMUNIFORM4DVPROC>(loader("glProgramUniform4dv"));
    glProgramUniform4d        = reinterpret_cast<PFNGLPROGRAMUNIFORM4DPROC>(loader("glProgramUniform4d"));
    glProgramUniform4fv       = reinterpret_cast<PFNGLPROGRAMUNIFORM4FVPROC>(loader("glProgramUniform4fv"));
    glProgramUniform4f        = reinterpret_cast<PFNGLPROGRAMUNIFORM4FPROC>(loader("glProgramUniform4f"));
    glProgramUniform4iv       = reinterpret_cast<PFNGLPROGRAMUNIFORM4IVPROC>(loader("glProgramUniform4iv"));
    glProgramUniform4i        = reinterpret_cast<PFNGLPROGRAMUNIFORM4IPROC>(loader("glProgramUniform4i"));
    glProgramUniform4uiv      = reinterpret_cast<PFNGLPROGRAMUNIFORM4UIVPROC>(loader("glProgramUniform4uiv"));
    glProgramUniform4ui       = reinterpret_cast<PFNGLPROGRAMUNIFORM4UIPROC>(loader("glProgramUniform4ui"));
    glProgramUniformMatrix2dv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX2DVPROC>(loader("glProgramUniformMatrix2dv"));
    glProgramUniformMatrix2fv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX2FVPROC>(loader("glProgramUniformMatrix2fv"));
    glProgramUniformMatrix2x3dv =
        reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC>(loader("glProgramUniformMatrix2x3dv"));
    glProgramUniformMatrix2x3fv =
        reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC>(loader("glProgramUniformMatrix2x3fv"));
    glProgramUniformMatrix2x4dv =
        reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC>(loader("glProgramUniformMatrix2x4dv"));
    glProgramUniformMatrix2x4fv =
        reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC>(loader("glProgramUniformMatrix2x4fv"));
    glProgramUniformMatrix3dv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX3DVPROC>(loader("glProgramUniformMatrix3dv"));
    glProgramUniformMatrix3fv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX3FVPROC>(loader("glProgramUniformMatrix3fv"));
    glProgramUniformMatrix3x2dv =
        reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC>(loader("glProgramUniformMatrix3x2dv"));
    glProgramUniformMatrix3x2fv =
        reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC>(loader("glProgramUniformMatrix3x2fv"));
    glProgramUniformMatrix3x4dv =
        reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC>(loader("glProgramUniformMatrix3x4dv"));
    glProgramUniformMatrix3x4fv =
        reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC>(loader("glProgramUniformMatrix3x4fv"));
    glProgramUniformMatrix4dv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX4DVPROC>(loader("glProgramUniformMatrix4dv"));
    glProgramUniformMatrix4fv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX4FVPROC>(loader("glProgramUniformMatrix4fv"));
    glProgramUniformMatrix4x2dv =
        reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC>(loader("glProgramUniformMatrix4x2dv"));
    glProgramUniformMatrix4x2fv =
        reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC>(loader("glProgramUniformMatrix4x2fv"));
    glProgramUniformMatrix4x3dv =
        reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC>(loader("glProgramUniformMatrix4x3dv"));
    glProgramUniformMatrix4x3fv =
        reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC>(loader("glProgramUniformMatrix4x3fv"));
    glReleaseShaderCompiler   = reinterpret_cast<PFNGLRELEASESHADERCOMPILERPROC>(loader("glReleaseShaderCompiler"));
    glScissorArrayv           = reinterpret_cast<PFNGLSCISSORARRAYVPROC>(loader("glScissorArrayv"));
    glScissorIndexedv         = reinterpret_cast<PFNGLSCISSORINDEXEDVPROC>(loader("glScissorIndexedv"));
    glScissorIndexed          = reinterpret_cast<PFNGLSCISSORINDEXEDPROC>(loader("glScissorIndexed"));
    glShaderBinary            = reinterpret_cast<PFNGLSHADERBINARYPROC>(loader("glShaderBinary"));
    glUseProgramStages        = reinterpret_cast<PFNGLUSEPROGRAMSTAGESPROC>(loader("glUseProgramStages"));
    glValidateProgramPipeline = reinterpret_cast<PFNGLVALIDATEPROGRAMPIPELINEPROC>(loader("glValidateProgramPipeline"));
    glVertexAttribL1dv        = reinterpret_cast<PFNGLVERTEXATTRIBL1DVPROC>(loader("glVertexAttribL1dv"));
    glVertexAttribL1d         = reinterpret_cast<PFNGLVERTEXATTRIBL1DPROC>(loader("glVertexAttribL1d"));
    glVertexAttribL2dv        = reinterpret_cast<PFNGLVERTEXATTRIBL2DVPROC>(loader("glVertexAttribL2dv"));
    glVertexAttribL2d         = reinterpret_cast<PFNGLVERTEXATTRIBL2DPROC>(loader("glVertexAttribL2d"));
    glVertexAttribL3dv        = reinterpret_cast<PFNGLVERTEXATTRIBL3DVPROC>(loader("glVertexAttribL3dv"));
    glVertexAttribL3d         = reinterpret_cast<PFNGLVERTEXATTRIBL3DPROC>(loader("glVertexAttribL3d"));
    glVertexAttribL4dv        = reinterpret_cast<PFNGLVERTEXATTRIBL4DVPROC>(loader("glVertexAttribL4dv"));
    glVertexAttribL4d         = reinterpret_cast<PFNGLVERTEXATTRIBL4DPROC>(loader("glVertexAttribL4d"));
    glVertexAttribLPointer    = reinterpret_cast<PFNGLVERTEXATTRIBLPOINTERPROC>(loader("glVertexAttribLPointer"));
    glViewportArrayv          = reinterpret_cast<PFNGLVIEWPORTARRAYVPROC>(loader("glViewportArrayv"));
    glViewportIndexedfv       = reinterpret_cast<PFNGLVIEWPORTINDEXEDFVPROC>(loader("glViewportIndexedfv"));
    glViewportIndexedf        = reinterpret_cast<PFNGLVIEWPORTINDEXEDFPROC>(loader("glViewportIndexedf"));
}

} // namespace glr
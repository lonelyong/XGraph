#include <xg/glr/igl/GLfuncsv410.h>

namespace xg {
namespace glr {


GLfuncsv410::GLfuncsv410()
  : iglActiveShaderProgram(nullptr)
  , iglBindProgramPipeline(nullptr)
  , iglClearDepthf(nullptr)
  , iglCreateShaderProgramv(nullptr)
  , iglDeleteProgramPipelines(nullptr)
  , iglDepthRangeArrayv(nullptr)
  , iglDepthRangeIndexed(nullptr)
  , iglDepthRangef(nullptr)
  , iglGenProgramPipelines(nullptr)
  , iglGetDoublei_v(nullptr)
  , iglGetFloati_v(nullptr)
  , iglGetProgramBinary(nullptr)
  , iglGetProgramPipelineInfoLog(nullptr)
  , iglGetProgramPipelineiv(nullptr)
  , iglGetShaderPrecisionFormat(nullptr)
  , iglGetVertexAttribLdv(nullptr)
  , iglIsProgramPipeline(nullptr)
  , iglProgramBinary(nullptr)
  , iglProgramParameteri(nullptr)
  , iglProgramUniform1dv(nullptr)
  , iglProgramUniform1d(nullptr)
  , iglProgramUniform1fv(nullptr)
  , iglProgramUniform1f(nullptr)
  , iglProgramUniform1iv(nullptr)
  , iglProgramUniform1i(nullptr)
  , iglProgramUniform1uiv(nullptr)
  , iglProgramUniform1ui(nullptr)
  , iglProgramUniform2dv(nullptr)
  , iglProgramUniform2d(nullptr)
  , iglProgramUniform2fv(nullptr)
  , iglProgramUniform2f(nullptr)
  , iglProgramUniform2iv(nullptr)
  , iglProgramUniform2i(nullptr)
  , iglProgramUniform2uiv(nullptr)
  , iglProgramUniform2ui(nullptr)
  , iglProgramUniform3dv(nullptr)
  , iglProgramUniform3d(nullptr)
  , iglProgramUniform3fv(nullptr)
  , iglProgramUniform3f(nullptr)
  , iglProgramUniform3iv(nullptr)
  , iglProgramUniform3i(nullptr)
  , iglProgramUniform3uiv(nullptr)
  , iglProgramUniform3ui(nullptr)
  , iglProgramUniform4dv(nullptr)
  , iglProgramUniform4d(nullptr)
  , iglProgramUniform4fv(nullptr)
  , iglProgramUniform4f(nullptr)
  , iglProgramUniform4iv(nullptr)
  , iglProgramUniform4i(nullptr)
  , iglProgramUniform4uiv(nullptr)
  , iglProgramUniform4ui(nullptr)
  , iglProgramUniformMatrix2dv(nullptr)
  , iglProgramUniformMatrix2fv(nullptr)
  , iglProgramUniformMatrix2x3dv(nullptr)
  , iglProgramUniformMatrix2x3fv(nullptr)
  , iglProgramUniformMatrix2x4dv(nullptr)
  , iglProgramUniformMatrix2x4fv(nullptr)
  , iglProgramUniformMatrix3dv(nullptr)
  , iglProgramUniformMatrix3fv(nullptr)
  , iglProgramUniformMatrix3x2dv(nullptr)
  , iglProgramUniformMatrix3x2fv(nullptr)
  , iglProgramUniformMatrix3x4dv(nullptr)
  , iglProgramUniformMatrix3x4fv(nullptr)
  , iglProgramUniformMatrix4dv(nullptr)
  , iglProgramUniformMatrix4fv(nullptr)
  , iglProgramUniformMatrix4x2dv(nullptr)
  , iglProgramUniformMatrix4x2fv(nullptr)
  , iglProgramUniformMatrix4x3dv(nullptr)
  , iglProgramUniformMatrix4x3fv(nullptr)
  , iglReleaseShaderCompiler(nullptr)
  , iglScissorArrayv(nullptr)
  , iglScissorIndexedv(nullptr)
  , iglScissorIndexed(nullptr)
  , iglShaderBinary(nullptr)
  , iglUseProgramStages(nullptr)
  , iglValidateProgramPipeline(nullptr)
  , iglVertexAttribL1dv(nullptr)
  , iglVertexAttribL1d(nullptr)
  , iglVertexAttribL2dv(nullptr)
  , iglVertexAttribL2d(nullptr)
  , iglVertexAttribL3dv(nullptr)
  , iglVertexAttribL3d(nullptr)
  , iglVertexAttribL4dv(nullptr)
  , iglVertexAttribL4d(nullptr)
  , iglVertexAttribLPointer(nullptr)
  , iglViewportArrayv(nullptr)
  , iglViewportIndexedfv(nullptr)
  , iglViewportIndexedf(nullptr) {
}

void GLfuncsv410::loadFuncs(Loader loader) {
    GLfuncsv400::loadFuncs(loader);
    iglActiveShaderProgram    = reinterpret_cast<PFNGLACTIVESHADERPROGRAMPROC>(loader("glActiveShaderProgram"));
    iglBindProgramPipeline    = reinterpret_cast<PFNGLBINDPROGRAMPIPELINEPROC>(loader("glBindProgramPipeline"));
    iglClearDepthf            = reinterpret_cast<PFNGLCLEARDEPTHFPROC>(loader("glClearDepthf"));
    iglCreateShaderProgramv   = reinterpret_cast<PFNGLCREATESHADERPROGRAMVPROC>(loader("glCreateShaderProgramv"));
    iglDeleteProgramPipelines = reinterpret_cast<PFNGLDELETEPROGRAMPIPELINESPROC>(loader("glDeleteProgramPipelines"));
    iglDepthRangeArrayv       = reinterpret_cast<PFNGLDEPTHRANGEARRAYVPROC>(loader("glDepthRangeArrayv"));
    iglDepthRangeIndexed      = reinterpret_cast<PFNGLDEPTHRANGEINDEXEDPROC>(loader("glDepthRangeIndexed"));
    iglDepthRangef            = reinterpret_cast<PFNGLDEPTHRANGEFPROC>(loader("glDepthRangef"));
    iglGenProgramPipelines    = reinterpret_cast<PFNGLGENPROGRAMPIPELINESPROC>(loader("glGenProgramPipelines"));
    iglGetDoublei_v           = reinterpret_cast<PFNGLGETDOUBLEI_VPROC>(loader("glGetDoublei_v"));
    iglGetFloati_v            = reinterpret_cast<PFNGLGETFLOATI_VPROC>(loader("glGetFloati_v"));
    iglGetProgramBinary       = reinterpret_cast<PFNGLGETPROGRAMBINARYPROC>(loader("glGetProgramBinary"));
    iglGetProgramPipelineInfoLog =
        reinterpret_cast<PFNGLGETPROGRAMPIPELINEINFOLOGPROC>(loader("glGetProgramPipelineInfoLog"));
    iglGetProgramPipelineiv = reinterpret_cast<PFNGLGETPROGRAMPIPELINEIVPROC>(loader("glGetProgramPipelineiv"));
    iglGetShaderPrecisionFormat =
        reinterpret_cast<PFNGLGETSHADERPRECISIONFORMATPROC>(loader("glGetShaderPrecisionFormat"));
    iglGetVertexAttribLdv      = reinterpret_cast<PFNGLGETVERTEXATTRIBLDVPROC>(loader("glGetVertexAttribLdv"));
    iglIsProgramPipeline       = reinterpret_cast<PFNGLISPROGRAMPIPELINEPROC>(loader("glIsProgramPipeline"));
    iglProgramBinary           = reinterpret_cast<PFNGLPROGRAMBINARYPROC>(loader("glProgramBinary"));
    iglProgramParameteri       = reinterpret_cast<PFNGLPROGRAMPARAMETERIPROC>(loader("glProgramParameteri"));
    iglProgramUniform1dv       = reinterpret_cast<PFNGLPROGRAMUNIFORM1DVPROC>(loader("glProgramUniform1dv"));
    iglProgramUniform1d        = reinterpret_cast<PFNGLPROGRAMUNIFORM1DPROC>(loader("glProgramUniform1d"));
    iglProgramUniform1fv       = reinterpret_cast<PFNGLPROGRAMUNIFORM1FVPROC>(loader("glProgramUniform1fv"));
    iglProgramUniform1f        = reinterpret_cast<PFNGLPROGRAMUNIFORM1FPROC>(loader("glProgramUniform1f"));
    iglProgramUniform1iv       = reinterpret_cast<PFNGLPROGRAMUNIFORM1IVPROC>(loader("glProgramUniform1iv"));
    iglProgramUniform1i        = reinterpret_cast<PFNGLPROGRAMUNIFORM1IPROC>(loader("glProgramUniform1i"));
    iglProgramUniform1uiv      = reinterpret_cast<PFNGLPROGRAMUNIFORM1UIVPROC>(loader("glProgramUniform1uiv"));
    iglProgramUniform1ui       = reinterpret_cast<PFNGLPROGRAMUNIFORM1UIPROC>(loader("glProgramUniform1ui"));
    iglProgramUniform2dv       = reinterpret_cast<PFNGLPROGRAMUNIFORM2DVPROC>(loader("glProgramUniform2dv"));
    iglProgramUniform2d        = reinterpret_cast<PFNGLPROGRAMUNIFORM2DPROC>(loader("glProgramUniform2d"));
    iglProgramUniform2fv       = reinterpret_cast<PFNGLPROGRAMUNIFORM2FVPROC>(loader("glProgramUniform2fv"));
    iglProgramUniform2f        = reinterpret_cast<PFNGLPROGRAMUNIFORM2FPROC>(loader("glProgramUniform2f"));
    iglProgramUniform2iv       = reinterpret_cast<PFNGLPROGRAMUNIFORM2IVPROC>(loader("glProgramUniform2iv"));
    iglProgramUniform2i        = reinterpret_cast<PFNGLPROGRAMUNIFORM2IPROC>(loader("glProgramUniform2i"));
    iglProgramUniform2uiv      = reinterpret_cast<PFNGLPROGRAMUNIFORM2UIVPROC>(loader("glProgramUniform2uiv"));
    iglProgramUniform2ui       = reinterpret_cast<PFNGLPROGRAMUNIFORM2UIPROC>(loader("glProgramUniform2ui"));
    iglProgramUniform3dv       = reinterpret_cast<PFNGLPROGRAMUNIFORM3DVPROC>(loader("glProgramUniform3dv"));
    iglProgramUniform3d        = reinterpret_cast<PFNGLPROGRAMUNIFORM3DPROC>(loader("glProgramUniform3d"));
    iglProgramUniform3fv       = reinterpret_cast<PFNGLPROGRAMUNIFORM3FVPROC>(loader("glProgramUniform3fv"));
    iglProgramUniform3f        = reinterpret_cast<PFNGLPROGRAMUNIFORM3FPROC>(loader("glProgramUniform3f"));
    iglProgramUniform3iv       = reinterpret_cast<PFNGLPROGRAMUNIFORM3IVPROC>(loader("glProgramUniform3iv"));
    iglProgramUniform3i        = reinterpret_cast<PFNGLPROGRAMUNIFORM3IPROC>(loader("glProgramUniform3i"));
    iglProgramUniform3uiv      = reinterpret_cast<PFNGLPROGRAMUNIFORM3UIVPROC>(loader("glProgramUniform3uiv"));
    iglProgramUniform3ui       = reinterpret_cast<PFNGLPROGRAMUNIFORM3UIPROC>(loader("glProgramUniform3ui"));
    iglProgramUniform4dv       = reinterpret_cast<PFNGLPROGRAMUNIFORM4DVPROC>(loader("glProgramUniform4dv"));
    iglProgramUniform4d        = reinterpret_cast<PFNGLPROGRAMUNIFORM4DPROC>(loader("glProgramUniform4d"));
    iglProgramUniform4fv       = reinterpret_cast<PFNGLPROGRAMUNIFORM4FVPROC>(loader("glProgramUniform4fv"));
    iglProgramUniform4f        = reinterpret_cast<PFNGLPROGRAMUNIFORM4FPROC>(loader("glProgramUniform4f"));
    iglProgramUniform4iv       = reinterpret_cast<PFNGLPROGRAMUNIFORM4IVPROC>(loader("glProgramUniform4iv"));
    iglProgramUniform4i        = reinterpret_cast<PFNGLPROGRAMUNIFORM4IPROC>(loader("glProgramUniform4i"));
    iglProgramUniform4uiv      = reinterpret_cast<PFNGLPROGRAMUNIFORM4UIVPROC>(loader("glProgramUniform4uiv"));
    iglProgramUniform4ui       = reinterpret_cast<PFNGLPROGRAMUNIFORM4UIPROC>(loader("glProgramUniform4ui"));
    iglProgramUniformMatrix2dv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX2DVPROC>(loader("glProgramUniformMatrix2dv"));
    iglProgramUniformMatrix2fv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX2FVPROC>(loader("glProgramUniformMatrix2fv"));
    iglProgramUniformMatrix2x3dv =
        reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC>(loader("glProgramUniformMatrix2x3dv"));
    iglProgramUniformMatrix2x3fv =
        reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC>(loader("glProgramUniformMatrix2x3fv"));
    iglProgramUniformMatrix2x4dv =
        reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC>(loader("glProgramUniformMatrix2x4dv"));
    iglProgramUniformMatrix2x4fv =
        reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC>(loader("glProgramUniformMatrix2x4fv"));
    iglProgramUniformMatrix3dv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX3DVPROC>(loader("glProgramUniformMatrix3dv"));
    iglProgramUniformMatrix3fv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX3FVPROC>(loader("glProgramUniformMatrix3fv"));
    iglProgramUniformMatrix3x2dv =
        reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC>(loader("glProgramUniformMatrix3x2dv"));
    iglProgramUniformMatrix3x2fv =
        reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC>(loader("glProgramUniformMatrix3x2fv"));
    iglProgramUniformMatrix3x4dv =
        reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC>(loader("glProgramUniformMatrix3x4dv"));
    iglProgramUniformMatrix3x4fv =
        reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC>(loader("glProgramUniformMatrix3x4fv"));
    iglProgramUniformMatrix4dv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX4DVPROC>(loader("glProgramUniformMatrix4dv"));
    iglProgramUniformMatrix4fv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX4FVPROC>(loader("glProgramUniformMatrix4fv"));
    iglProgramUniformMatrix4x2dv =
        reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC>(loader("glProgramUniformMatrix4x2dv"));
    iglProgramUniformMatrix4x2fv =
        reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC>(loader("glProgramUniformMatrix4x2fv"));
    iglProgramUniformMatrix4x3dv =
        reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC>(loader("glProgramUniformMatrix4x3dv"));
    iglProgramUniformMatrix4x3fv =
        reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC>(loader("glProgramUniformMatrix4x3fv"));
    iglReleaseShaderCompiler   = reinterpret_cast<PFNGLRELEASESHADERCOMPILERPROC>(loader("glReleaseShaderCompiler"));
    iglScissorArrayv           = reinterpret_cast<PFNGLSCISSORARRAYVPROC>(loader("glScissorArrayv"));
    iglScissorIndexedv         = reinterpret_cast<PFNGLSCISSORINDEXEDVPROC>(loader("glScissorIndexedv"));
    iglScissorIndexed          = reinterpret_cast<PFNGLSCISSORINDEXEDPROC>(loader("glScissorIndexed"));
    iglShaderBinary            = reinterpret_cast<PFNGLSHADERBINARYPROC>(loader("glShaderBinary"));
    iglUseProgramStages        = reinterpret_cast<PFNGLUSEPROGRAMSTAGESPROC>(loader("glUseProgramStages"));
    iglValidateProgramPipeline = reinterpret_cast<PFNGLVALIDATEPROGRAMPIPELINEPROC>(loader("glValidateProgramPipeline"));
    iglVertexAttribL1dv        = reinterpret_cast<PFNGLVERTEXATTRIBL1DVPROC>(loader("glVertexAttribL1dv"));
    iglVertexAttribL1d         = reinterpret_cast<PFNGLVERTEXATTRIBL1DPROC>(loader("glVertexAttribL1d"));
    iglVertexAttribL2dv        = reinterpret_cast<PFNGLVERTEXATTRIBL2DVPROC>(loader("glVertexAttribL2dv"));
    iglVertexAttribL2d         = reinterpret_cast<PFNGLVERTEXATTRIBL2DPROC>(loader("glVertexAttribL2d"));
    iglVertexAttribL3dv        = reinterpret_cast<PFNGLVERTEXATTRIBL3DVPROC>(loader("glVertexAttribL3dv"));
    iglVertexAttribL3d         = reinterpret_cast<PFNGLVERTEXATTRIBL3DPROC>(loader("glVertexAttribL3d"));
    iglVertexAttribL4dv        = reinterpret_cast<PFNGLVERTEXATTRIBL4DVPROC>(loader("glVertexAttribL4dv"));
    iglVertexAttribL4d         = reinterpret_cast<PFNGLVERTEXATTRIBL4DPROC>(loader("glVertexAttribL4d"));
    iglVertexAttribLPointer    = reinterpret_cast<PFNGLVERTEXATTRIBLPOINTERPROC>(loader("glVertexAttribLPointer"));
    iglViewportArrayv          = reinterpret_cast<PFNGLVIEWPORTARRAYVPROC>(loader("glViewportArrayv"));
    iglViewportIndexedfv       = reinterpret_cast<PFNGLVIEWPORTINDEXEDFVPROC>(loader("glViewportIndexedfv"));
    iglViewportIndexedf        = reinterpret_cast<PFNGLVIEWPORTINDEXEDFPROC>(loader("glViewportIndexedf"));
}

} // namespace glr
} // namespace xg
#include <xg/igl/ogl/GLfuncsv410.hpp>

namespace xg
{
namespace glr
{


GLfuncsv410::GLfuncsv410()
  : oglActiveShaderProgram(nullptr)
  , oglBindProgramPipeline(nullptr)
  , oglClearDepthf(nullptr)
  , oglCreateShaderProgramv(nullptr)
  , oglDeleteProgramPipelines(nullptr)
  , oglDepthRangeArrayv(nullptr)
  , oglDepthRangeIndexed(nullptr)
  , oglDepthRangef(nullptr)
  , oglGenProgramPipelines(nullptr)
  , oglGetDoublei_v(nullptr)
  , oglGetFloati_v(nullptr)
  , oglGetProgramBinary(nullptr)
  , oglGetProgramPipelineInfoLog(nullptr)
  , oglGetProgramPipelineiv(nullptr)
  , oglGetShaderPrecisionFormat(nullptr)
  , oglGetVertexAttribLdv(nullptr)
  , oglIsProgramPipeline(nullptr)
  , oglProgramBinary(nullptr)
  , oglProgramParameteri(nullptr)
  , oglProgramUniform1dv(nullptr)
  , oglProgramUniform1d(nullptr)
  , oglProgramUniform1fv(nullptr)
  , oglProgramUniform1f(nullptr)
  , oglProgramUniform1iv(nullptr)
  , oglProgramUniform1i(nullptr)
  , oglProgramUniform1uiv(nullptr)
  , oglProgramUniform1ui(nullptr)
  , oglProgramUniform2dv(nullptr)
  , oglProgramUniform2d(nullptr)
  , oglProgramUniform2fv(nullptr)
  , oglProgramUniform2f(nullptr)
  , oglProgramUniform2iv(nullptr)
  , oglProgramUniform2i(nullptr)
  , oglProgramUniform2uiv(nullptr)
  , oglProgramUniform2ui(nullptr)
  , oglProgramUniform3dv(nullptr)
  , oglProgramUniform3d(nullptr)
  , oglProgramUniform3fv(nullptr)
  , oglProgramUniform3f(nullptr)
  , oglProgramUniform3iv(nullptr)
  , oglProgramUniform3i(nullptr)
  , oglProgramUniform3uiv(nullptr)
  , oglProgramUniform3ui(nullptr)
  , oglProgramUniform4dv(nullptr)
  , oglProgramUniform4d(nullptr)
  , oglProgramUniform4fv(nullptr)
  , oglProgramUniform4f(nullptr)
  , oglProgramUniform4iv(nullptr)
  , oglProgramUniform4i(nullptr)
  , oglProgramUniform4uiv(nullptr)
  , oglProgramUniform4ui(nullptr)
  , oglProgramUniformMatrix2dv(nullptr)
  , oglProgramUniformMatrix2fv(nullptr)
  , oglProgramUniformMatrix2x3dv(nullptr)
  , oglProgramUniformMatrix2x3fv(nullptr)
  , oglProgramUniformMatrix2x4dv(nullptr)
  , oglProgramUniformMatrix2x4fv(nullptr)
  , oglProgramUniformMatrix3dv(nullptr)
  , oglProgramUniformMatrix3fv(nullptr)
  , oglProgramUniformMatrix3x2dv(nullptr)
  , oglProgramUniformMatrix3x2fv(nullptr)
  , oglProgramUniformMatrix3x4dv(nullptr)
  , oglProgramUniformMatrix3x4fv(nullptr)
  , oglProgramUniformMatrix4dv(nullptr)
  , oglProgramUniformMatrix4fv(nullptr)
  , oglProgramUniformMatrix4x2dv(nullptr)
  , oglProgramUniformMatrix4x2fv(nullptr)
  , oglProgramUniformMatrix4x3dv(nullptr)
  , oglProgramUniformMatrix4x3fv(nullptr)
  , oglReleaseShaderCompiler(nullptr)
  , oglScissorArrayv(nullptr)
  , oglScissorIndexedv(nullptr)
  , oglScissorIndexed(nullptr)
  , oglShaderBinary(nullptr)
  , oglUseProgramStages(nullptr)
  , oglValidateProgramPipeline(nullptr)
  , oglVertexAttribL1dv(nullptr)
  , oglVertexAttribL1d(nullptr)
  , oglVertexAttribL2dv(nullptr)
  , oglVertexAttribL2d(nullptr)
  , oglVertexAttribL3dv(nullptr)
  , oglVertexAttribL3d(nullptr)
  , oglVertexAttribL4dv(nullptr)
  , oglVertexAttribL4d(nullptr)
  , oglVertexAttribLPointer(nullptr)
  , oglViewportArrayv(nullptr)
  , oglViewportIndexedfv(nullptr)
  , oglViewportIndexedf(nullptr)
{}

void GLfuncsv410::loadFuncs(Loader loader)
{
    GLfuncsv400::loadFuncs(loader);
    oglActiveShaderProgram       = reinterpret_cast<PFNGLACTIVESHADERPROGRAMPROC>(loader("glActiveShaderProgram"));
    oglBindProgramPipeline       = reinterpret_cast<PFNGLBINDPROGRAMPIPELINEPROC>(loader("glBindProgramPipeline"));
    oglClearDepthf               = reinterpret_cast<PFNGLCLEARDEPTHFPROC>(loader("glClearDepthf"));
    oglCreateShaderProgramv      = reinterpret_cast<PFNGLCREATESHADERPROGRAMVPROC>(loader("glCreateShaderProgramv"));
    oglDeleteProgramPipelines    = reinterpret_cast<PFNGLDELETEPROGRAMPIPELINESPROC>(loader("glDeleteProgramPipelines"));
    oglDepthRangeArrayv          = reinterpret_cast<PFNGLDEPTHRANGEARRAYVPROC>(loader("glDepthRangeArrayv"));
    oglDepthRangeIndexed         = reinterpret_cast<PFNGLDEPTHRANGEINDEXEDPROC>(loader("glDepthRangeIndexed"));
    oglDepthRangef               = reinterpret_cast<PFNGLDEPTHRANGEFPROC>(loader("glDepthRangef"));
    oglGenProgramPipelines       = reinterpret_cast<PFNGLGENPROGRAMPIPELINESPROC>(loader("glGenProgramPipelines"));
    oglGetDoublei_v              = reinterpret_cast<PFNGLGETDOUBLEI_VPROC>(loader("glGetDoublei_v"));
    oglGetFloati_v               = reinterpret_cast<PFNGLGETFLOATI_VPROC>(loader("glGetFloati_v"));
    oglGetProgramBinary          = reinterpret_cast<PFNGLGETPROGRAMBINARYPROC>(loader("glGetProgramBinary"));
    oglGetProgramPipelineInfoLog = reinterpret_cast<PFNGLGETPROGRAMPIPELINEINFOLOGPROC>(loader("glGetProgramPipelineInfoLog"));
    oglGetProgramPipelineiv      = reinterpret_cast<PFNGLGETPROGRAMPIPELINEIVPROC>(loader("glGetProgramPipelineiv"));
    oglGetShaderPrecisionFormat  = reinterpret_cast<PFNGLGETSHADERPRECISIONFORMATPROC>(loader("glGetShaderPrecisionFormat"));
    oglGetVertexAttribLdv        = reinterpret_cast<PFNGLGETVERTEXATTRIBLDVPROC>(loader("glGetVertexAttribLdv"));
    oglIsProgramPipeline         = reinterpret_cast<PFNGLISPROGRAMPIPELINEPROC>(loader("glIsProgramPipeline"));
    oglProgramBinary             = reinterpret_cast<PFNGLPROGRAMBINARYPROC>(loader("glProgramBinary"));
    oglProgramParameteri         = reinterpret_cast<PFNGLPROGRAMPARAMETERIPROC>(loader("glProgramParameteri"));
    oglProgramUniform1dv         = reinterpret_cast<PFNGLPROGRAMUNIFORM1DVPROC>(loader("glProgramUniform1dv"));
    oglProgramUniform1d          = reinterpret_cast<PFNGLPROGRAMUNIFORM1DPROC>(loader("glProgramUniform1d"));
    oglProgramUniform1fv         = reinterpret_cast<PFNGLPROGRAMUNIFORM1FVPROC>(loader("glProgramUniform1fv"));
    oglProgramUniform1f          = reinterpret_cast<PFNGLPROGRAMUNIFORM1FPROC>(loader("glProgramUniform1f"));
    oglProgramUniform1iv         = reinterpret_cast<PFNGLPROGRAMUNIFORM1IVPROC>(loader("glProgramUniform1iv"));
    oglProgramUniform1i          = reinterpret_cast<PFNGLPROGRAMUNIFORM1IPROC>(loader("glProgramUniform1i"));
    oglProgramUniform1uiv        = reinterpret_cast<PFNGLPROGRAMUNIFORM1UIVPROC>(loader("glProgramUniform1uiv"));
    oglProgramUniform1ui         = reinterpret_cast<PFNGLPROGRAMUNIFORM1UIPROC>(loader("glProgramUniform1ui"));
    oglProgramUniform2dv         = reinterpret_cast<PFNGLPROGRAMUNIFORM2DVPROC>(loader("glProgramUniform2dv"));
    oglProgramUniform2d          = reinterpret_cast<PFNGLPROGRAMUNIFORM2DPROC>(loader("glProgramUniform2d"));
    oglProgramUniform2fv         = reinterpret_cast<PFNGLPROGRAMUNIFORM2FVPROC>(loader("glProgramUniform2fv"));
    oglProgramUniform2f          = reinterpret_cast<PFNGLPROGRAMUNIFORM2FPROC>(loader("glProgramUniform2f"));
    oglProgramUniform2iv         = reinterpret_cast<PFNGLPROGRAMUNIFORM2IVPROC>(loader("glProgramUniform2iv"));
    oglProgramUniform2i          = reinterpret_cast<PFNGLPROGRAMUNIFORM2IPROC>(loader("glProgramUniform2i"));
    oglProgramUniform2uiv        = reinterpret_cast<PFNGLPROGRAMUNIFORM2UIVPROC>(loader("glProgramUniform2uiv"));
    oglProgramUniform2ui         = reinterpret_cast<PFNGLPROGRAMUNIFORM2UIPROC>(loader("glProgramUniform2ui"));
    oglProgramUniform3dv         = reinterpret_cast<PFNGLPROGRAMUNIFORM3DVPROC>(loader("glProgramUniform3dv"));
    oglProgramUniform3d          = reinterpret_cast<PFNGLPROGRAMUNIFORM3DPROC>(loader("glProgramUniform3d"));
    oglProgramUniform3fv         = reinterpret_cast<PFNGLPROGRAMUNIFORM3FVPROC>(loader("glProgramUniform3fv"));
    oglProgramUniform3f          = reinterpret_cast<PFNGLPROGRAMUNIFORM3FPROC>(loader("glProgramUniform3f"));
    oglProgramUniform3iv         = reinterpret_cast<PFNGLPROGRAMUNIFORM3IVPROC>(loader("glProgramUniform3iv"));
    oglProgramUniform3i          = reinterpret_cast<PFNGLPROGRAMUNIFORM3IPROC>(loader("glProgramUniform3i"));
    oglProgramUniform3uiv        = reinterpret_cast<PFNGLPROGRAMUNIFORM3UIVPROC>(loader("glProgramUniform3uiv"));
    oglProgramUniform3ui         = reinterpret_cast<PFNGLPROGRAMUNIFORM3UIPROC>(loader("glProgramUniform3ui"));
    oglProgramUniform4dv         = reinterpret_cast<PFNGLPROGRAMUNIFORM4DVPROC>(loader("glProgramUniform4dv"));
    oglProgramUniform4d          = reinterpret_cast<PFNGLPROGRAMUNIFORM4DPROC>(loader("glProgramUniform4d"));
    oglProgramUniform4fv         = reinterpret_cast<PFNGLPROGRAMUNIFORM4FVPROC>(loader("glProgramUniform4fv"));
    oglProgramUniform4f          = reinterpret_cast<PFNGLPROGRAMUNIFORM4FPROC>(loader("glProgramUniform4f"));
    oglProgramUniform4iv         = reinterpret_cast<PFNGLPROGRAMUNIFORM4IVPROC>(loader("glProgramUniform4iv"));
    oglProgramUniform4i          = reinterpret_cast<PFNGLPROGRAMUNIFORM4IPROC>(loader("glProgramUniform4i"));
    oglProgramUniform4uiv        = reinterpret_cast<PFNGLPROGRAMUNIFORM4UIVPROC>(loader("glProgramUniform4uiv"));
    oglProgramUniform4ui         = reinterpret_cast<PFNGLPROGRAMUNIFORM4UIPROC>(loader("glProgramUniform4ui"));
    oglProgramUniformMatrix2dv   = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX2DVPROC>(loader("glProgramUniformMatrix2dv"));
    oglProgramUniformMatrix2fv   = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX2FVPROC>(loader("glProgramUniformMatrix2fv"));
    oglProgramUniformMatrix2x3dv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC>(loader("glProgramUniformMatrix2x3dv"));
    oglProgramUniformMatrix2x3fv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC>(loader("glProgramUniformMatrix2x3fv"));
    oglProgramUniformMatrix2x4dv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC>(loader("glProgramUniformMatrix2x4dv"));
    oglProgramUniformMatrix2x4fv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC>(loader("glProgramUniformMatrix2x4fv"));
    oglProgramUniformMatrix3dv   = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX3DVPROC>(loader("glProgramUniformMatrix3dv"));
    oglProgramUniformMatrix3fv   = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX3FVPROC>(loader("glProgramUniformMatrix3fv"));
    oglProgramUniformMatrix3x2dv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC>(loader("glProgramUniformMatrix3x2dv"));
    oglProgramUniformMatrix3x2fv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC>(loader("glProgramUniformMatrix3x2fv"));
    oglProgramUniformMatrix3x4dv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC>(loader("glProgramUniformMatrix3x4dv"));
    oglProgramUniformMatrix3x4fv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC>(loader("glProgramUniformMatrix3x4fv"));
    oglProgramUniformMatrix4dv   = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX4DVPROC>(loader("glProgramUniformMatrix4dv"));
    oglProgramUniformMatrix4fv   = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX4FVPROC>(loader("glProgramUniformMatrix4fv"));
    oglProgramUniformMatrix4x2dv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC>(loader("glProgramUniformMatrix4x2dv"));
    oglProgramUniformMatrix4x2fv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC>(loader("glProgramUniformMatrix4x2fv"));
    oglProgramUniformMatrix4x3dv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC>(loader("glProgramUniformMatrix4x3dv"));
    oglProgramUniformMatrix4x3fv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC>(loader("glProgramUniformMatrix4x3fv"));
    oglReleaseShaderCompiler     = reinterpret_cast<PFNGLRELEASESHADERCOMPILERPROC>(loader("glReleaseShaderCompiler"));
    oglScissorArrayv             = reinterpret_cast<PFNGLSCISSORARRAYVPROC>(loader("glScissorArrayv"));
    oglScissorIndexedv           = reinterpret_cast<PFNGLSCISSORINDEXEDVPROC>(loader("glScissorIndexedv"));
    oglScissorIndexed            = reinterpret_cast<PFNGLSCISSORINDEXEDPROC>(loader("glScissorIndexed"));
    oglShaderBinary              = reinterpret_cast<PFNGLSHADERBINARYPROC>(loader("glShaderBinary"));
    oglUseProgramStages          = reinterpret_cast<PFNGLUSEPROGRAMSTAGESPROC>(loader("glUseProgramStages"));
    oglValidateProgramPipeline   = reinterpret_cast<PFNGLVALIDATEPROGRAMPIPELINEPROC>(loader("glValidateProgramPipeline"));
    oglVertexAttribL1dv          = reinterpret_cast<PFNGLVERTEXATTRIBL1DVPROC>(loader("glVertexAttribL1dv"));
    oglVertexAttribL1d           = reinterpret_cast<PFNGLVERTEXATTRIBL1DPROC>(loader("glVertexAttribL1d"));
    oglVertexAttribL2dv          = reinterpret_cast<PFNGLVERTEXATTRIBL2DVPROC>(loader("glVertexAttribL2dv"));
    oglVertexAttribL2d           = reinterpret_cast<PFNGLVERTEXATTRIBL2DPROC>(loader("glVertexAttribL2d"));
    oglVertexAttribL3dv          = reinterpret_cast<PFNGLVERTEXATTRIBL3DVPROC>(loader("glVertexAttribL3dv"));
    oglVertexAttribL3d           = reinterpret_cast<PFNGLVERTEXATTRIBL3DPROC>(loader("glVertexAttribL3d"));
    oglVertexAttribL4dv          = reinterpret_cast<PFNGLVERTEXATTRIBL4DVPROC>(loader("glVertexAttribL4dv"));
    oglVertexAttribL4d           = reinterpret_cast<PFNGLVERTEXATTRIBL4DPROC>(loader("glVertexAttribL4d"));
    oglVertexAttribLPointer      = reinterpret_cast<PFNGLVERTEXATTRIBLPOINTERPROC>(loader("glVertexAttribLPointer"));
    oglViewportArrayv            = reinterpret_cast<PFNGLVIEWPORTARRAYVPROC>(loader("glViewportArrayv"));
    oglViewportIndexedfv         = reinterpret_cast<PFNGLVIEWPORTINDEXEDFVPROC>(loader("glViewportIndexedfv"));
    oglViewportIndexedf          = reinterpret_cast<PFNGLVIEWPORTINDEXEDFPROC>(loader("glViewportIndexedf"));
}

} // namespace glr
} // namespace xg
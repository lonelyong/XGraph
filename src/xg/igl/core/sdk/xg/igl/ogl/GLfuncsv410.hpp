#pragma once

#include <xg/igl/ogl/GLfuncsv400.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API GLfuncsv410 : public GLfuncsv400 {

  public:
    typedef void(APIENTRYP PFNGLRELEASESHADERCOMPILERPROC)(void);
    PFNGLRELEASESHADERCOMPILERPROC oglReleaseShaderCompiler;

    typedef void(APIENTRYP PFNGLSHADERBINARYPROC)(GLsizei_t count, const GLuint_t* shaders, GLenum_t binaryFormat, const void* binary, GLsizei_t length);
    PFNGLSHADERBINARYPROC oglShaderBinary;

    typedef void(APIENTRYP PFNGLGETSHADERPRECISIONFORMATPROC)(GLenum_t shadertype, GLenum_t precisiontype, GLint_t* range, GLint_t* precision);
    PFNGLGETSHADERPRECISIONFORMATPROC oglGetShaderPrecisionFormat;

    typedef void(APIENTRYP PFNGLDEPTHRANGEFPROC)(GLfloat_t n, GLfloat_t f);
    PFNGLDEPTHRANGEFPROC oglDepthRangef;

    typedef void(APIENTRYP PFNGLCLEARDEPTHFPROC)(GLfloat_t d);
    PFNGLCLEARDEPTHFPROC oglClearDepthf;

    typedef void(APIENTRYP PFNGLGETPROGRAMBINARYPROC)(GLuint_t program, GLsizei_t bufSize, GLsizei_t* length, GLenum_t* binaryFormat, void* binary);
    PFNGLGETPROGRAMBINARYPROC oglGetProgramBinary;

    typedef void(APIENTRYP PFNGLPROGRAMBINARYPROC)(GLuint_t program, GLenum_t binaryFormat, const void* binary, GLsizei_t length);
    PFNGLPROGRAMBINARYPROC oglProgramBinary;

    typedef void(APIENTRYP PFNGLPROGRAMPARAMETERIPROC)(GLuint_t program, GLenum_t pname, GLint_t value);
    PFNGLPROGRAMPARAMETERIPROC oglProgramParameteri;

    typedef void(APIENTRYP PFNGLUSEPROGRAMSTAGESPROC)(GLuint_t pipeline, GLbitfield_t stages, GLuint_t program);
    PFNGLUSEPROGRAMSTAGESPROC oglUseProgramStages;

    typedef void(APIENTRYP PFNGLACTIVESHADERPROGRAMPROC)(GLuint_t pipeline, GLuint_t program);
    PFNGLACTIVESHADERPROGRAMPROC oglActiveShaderProgram;

    typedef GLuint_t(APIENTRYP PFNGLCREATESHADERPROGRAMVPROC)(GLenum_t type, GLsizei_t count, const GLchar_t* const* strings);
    PFNGLCREATESHADERPROGRAMVPROC oglCreateShaderProgramv;

    typedef void(APIENTRYP PFNGLBINDPROGRAMPIPELINEPROC)(GLuint_t pipeline);
    PFNGLBINDPROGRAMPIPELINEPROC oglBindProgramPipeline;

    typedef void(APIENTRYP PFNGLDELETEPROGRAMPIPELINESPROC)(GLsizei_t n, const GLuint_t* pipelines);
    PFNGLDELETEPROGRAMPIPELINESPROC oglDeleteProgramPipelines;

    typedef void(APIENTRYP PFNGLGENPROGRAMPIPELINESPROC)(GLsizei_t n, GLuint_t* pipelines);
    PFNGLGENPROGRAMPIPELINESPROC oglGenProgramPipelines;

    typedef GLboolean_t(APIENTRYP PFNGLISPROGRAMPIPELINEPROC)(GLuint_t pipeline);
    PFNGLISPROGRAMPIPELINEPROC oglIsProgramPipeline;

    typedef void(APIENTRYP PFNGLGETPROGRAMPIPELINEIVPROC)(GLuint_t pipeline, GLenum_t pname, GLint_t* params);
    PFNGLGETPROGRAMPIPELINEIVPROC oglGetProgramPipelineiv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1IPROC)(GLuint_t program, GLint_t location, GLint_t v0);
    PFNGLPROGRAMUNIFORM1IPROC oglProgramUniform1i;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1IVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, const GLint_t* value);
    PFNGLPROGRAMUNIFORM1IVPROC oglProgramUniform1iv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1FPROC)(GLuint_t program, GLint_t location, GLfloat_t v0);
    PFNGLPROGRAMUNIFORM1FPROC oglProgramUniform1f;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1FVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, const GLfloat_t* value);
    PFNGLPROGRAMUNIFORM1FVPROC oglProgramUniform1fv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1DPROC)(GLuint_t program, GLint_t location, GLdouble_t v0);
    PFNGLPROGRAMUNIFORM1DPROC oglProgramUniform1d;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1DVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, const GLdouble_t* value);
    PFNGLPROGRAMUNIFORM1DVPROC oglProgramUniform1dv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1UIPROC)(GLuint_t program, GLint_t location, GLuint_t v0);
    PFNGLPROGRAMUNIFORM1UIPROC oglProgramUniform1ui;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1UIVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, const GLuint_t* value);
    PFNGLPROGRAMUNIFORM1UIVPROC oglProgramUniform1uiv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2IPROC)(GLuint_t program, GLint_t location, GLint_t v0, GLint_t v1);
    PFNGLPROGRAMUNIFORM2IPROC oglProgramUniform2i;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2IVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, const GLint_t* value);
    PFNGLPROGRAMUNIFORM2IVPROC oglProgramUniform2iv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2FPROC)(GLuint_t program, GLint_t location, GLfloat_t v0, GLfloat_t v1);
    PFNGLPROGRAMUNIFORM2FPROC oglProgramUniform2f;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2FVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, const GLfloat_t* value);
    PFNGLPROGRAMUNIFORM2FVPROC oglProgramUniform2fv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2DPROC)(GLuint_t program, GLint_t location, GLdouble_t v0, GLdouble_t v1);
    PFNGLPROGRAMUNIFORM2DPROC oglProgramUniform2d;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2DVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, const GLdouble_t* value);
    PFNGLPROGRAMUNIFORM2DVPROC oglProgramUniform2dv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2UIPROC)(GLuint_t program, GLint_t location, GLuint_t v0, GLuint_t v1);
    PFNGLPROGRAMUNIFORM2UIPROC oglProgramUniform2ui;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2UIVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, const GLuint_t* value);
    PFNGLPROGRAMUNIFORM2UIVPROC oglProgramUniform2uiv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3IPROC)(GLuint_t program, GLint_t location, GLint_t v0, GLint_t v1, GLint_t v2);
    PFNGLPROGRAMUNIFORM3IPROC oglProgramUniform3i;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3IVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, const GLint_t* value);
    PFNGLPROGRAMUNIFORM3IVPROC oglProgramUniform3iv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3FPROC)(GLuint_t program, GLint_t location, GLfloat_t v0, GLfloat_t v1, GLfloat_t v2);
    PFNGLPROGRAMUNIFORM3FPROC oglProgramUniform3f;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3FVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, const GLfloat_t* value);
    PFNGLPROGRAMUNIFORM3FVPROC oglProgramUniform3fv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3DPROC)(GLuint_t program, GLint_t location, GLdouble_t v0, GLdouble_t v1, GLdouble_t v2);
    PFNGLPROGRAMUNIFORM3DPROC oglProgramUniform3d;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3DVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, const GLdouble_t* value);
    PFNGLPROGRAMUNIFORM3DVPROC oglProgramUniform3dv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3UIPROC)(GLuint_t program, GLint_t location, GLuint_t v0, GLuint_t v1, GLuint_t v2);
    PFNGLPROGRAMUNIFORM3UIPROC oglProgramUniform3ui;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3UIVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, const GLuint_t* value);
    PFNGLPROGRAMUNIFORM3UIVPROC oglProgramUniform3uiv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4IPROC)(GLuint_t program, GLint_t location, GLint_t v0, GLint_t v1, GLint_t v2, GLint_t v3);
    PFNGLPROGRAMUNIFORM4IPROC oglProgramUniform4i;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4IVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, const GLint_t* value);
    PFNGLPROGRAMUNIFORM4IVPROC oglProgramUniform4iv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4FPROC)(GLuint_t program, GLint_t location, GLfloat_t v0, GLfloat_t v1, GLfloat_t v2, GLfloat_t v3);
    PFNGLPROGRAMUNIFORM4FPROC oglProgramUniform4f;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4FVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, const GLfloat_t* value);
    PFNGLPROGRAMUNIFORM4FVPROC oglProgramUniform4fv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4DPROC)(GLuint_t program, GLint_t location, GLdouble_t v0, GLdouble_t v1, GLdouble_t v2, GLdouble_t v3);
    PFNGLPROGRAMUNIFORM4DPROC oglProgramUniform4d;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4DVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, const GLdouble_t* value);
    PFNGLPROGRAMUNIFORM4DVPROC oglProgramUniform4dv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4UIPROC)(GLuint_t program, GLint_t location, GLuint_t v0, GLuint_t v1, GLuint_t v2, GLuint_t v3);
    PFNGLPROGRAMUNIFORM4UIPROC oglProgramUniform4ui;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4UIVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, const GLuint_t* value);
    PFNGLPROGRAMUNIFORM4UIVPROC oglProgramUniform4uiv;

    typedef void(
        APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2FVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLfloat_t* value);
    PFNGLPROGRAMUNIFORMMATRIX2FVPROC oglProgramUniformMatrix2fv;

    typedef void(
        APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3FVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLfloat_t* value);
    PFNGLPROGRAMUNIFORMMATRIX3FVPROC oglProgramUniformMatrix3fv;

    typedef void(
        APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4FVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLfloat_t* value);
    PFNGLPROGRAMUNIFORMMATRIX4FVPROC oglProgramUniformMatrix4fv;

    typedef void(
        APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2DVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLdouble_t* value);
    PFNGLPROGRAMUNIFORMMATRIX2DVPROC oglProgramUniformMatrix2dv;

    typedef void(
        APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3DVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLdouble_t* value);
    PFNGLPROGRAMUNIFORMMATRIX3DVPROC oglProgramUniformMatrix3dv;

    typedef void(
        APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4DVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLdouble_t* value);
    PFNGLPROGRAMUNIFORMMATRIX4DVPROC oglProgramUniformMatrix4dv;

    typedef void(
        APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLfloat_t* value);
    PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC oglProgramUniformMatrix2x3fv;

    typedef void(
        APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLfloat_t* value);
    PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC oglProgramUniformMatrix3x2fv;

    typedef void(
        APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLfloat_t* value);
    PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC oglProgramUniformMatrix2x4fv;

    typedef void(
        APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLfloat_t* value);
    PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC oglProgramUniformMatrix4x2fv;

    typedef void(
        APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLfloat_t* value);
    PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC oglProgramUniformMatrix3x4fv;

    typedef void(
        APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLfloat_t* value);
    PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC oglProgramUniformMatrix4x3fv;

    typedef void(
        APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLdouble_t* value);
    PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC oglProgramUniformMatrix2x3dv;

    typedef void(
        APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLdouble_t* value);
    PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC oglProgramUniformMatrix3x2dv;

    typedef void(
        APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLdouble_t* value);
    PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC oglProgramUniformMatrix2x4dv;

    typedef void(
        APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLdouble_t* value);
    PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC oglProgramUniformMatrix4x2dv;

    typedef void(
        APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLdouble_t* value);
    PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC oglProgramUniformMatrix3x4dv;

    typedef void(
        APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)(GLuint_t program, GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLdouble_t* value);
    PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC oglProgramUniformMatrix4x3dv;

    typedef void(APIENTRYP PFNGLVALIDATEPROGRAMPIPELINEPROC)(GLuint_t pipeline);
    PFNGLVALIDATEPROGRAMPIPELINEPROC oglValidateProgramPipeline;

    typedef void(APIENTRYP PFNGLGETPROGRAMPIPELINEINFOLOGPROC)(GLuint_t pipeline, GLsizei_t bufSize, GLsizei_t* length, GLchar_t* infoLog);
    PFNGLGETPROGRAMPIPELINEINFOLOGPROC oglGetProgramPipelineInfoLog;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBL1DPROC)(GLuint_t index, GLdouble_t x);
    PFNGLVERTEXATTRIBL1DPROC oglVertexAttribL1d;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBL2DPROC)(GLuint_t index, GLdouble_t x, GLdouble_t y);
    PFNGLVERTEXATTRIBL2DPROC oglVertexAttribL2d;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBL3DPROC)(GLuint_t index, GLdouble_t x, GLdouble_t y, GLdouble_t z);
    PFNGLVERTEXATTRIBL3DPROC oglVertexAttribL3d;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBL4DPROC)(GLuint_t index, GLdouble_t x, GLdouble_t y, GLdouble_t z, GLdouble_t w);
    PFNGLVERTEXATTRIBL4DPROC oglVertexAttribL4d;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBL1DVPROC)(GLuint_t index, const GLdouble_t* v);
    PFNGLVERTEXATTRIBL1DVPROC oglVertexAttribL1dv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBL2DVPROC)(GLuint_t index, const GLdouble_t* v);
    PFNGLVERTEXATTRIBL2DVPROC oglVertexAttribL2dv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBL3DVPROC)(GLuint_t index, const GLdouble_t* v);
    PFNGLVERTEXATTRIBL3DVPROC oglVertexAttribL3dv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBL4DVPROC)(GLuint_t index, const GLdouble_t* v);
    PFNGLVERTEXATTRIBL4DVPROC oglVertexAttribL4dv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBLPOINTERPROC)(GLuint_t index, GLint_t size, GLenum_t type, GLsizei_t stride, const void* pointer);
    PFNGLVERTEXATTRIBLPOINTERPROC oglVertexAttribLPointer;

    typedef void(APIENTRYP PFNGLGETVERTEXATTRIBLDVPROC)(GLuint_t index, GLenum_t pname, GLdouble_t* params);
    PFNGLGETVERTEXATTRIBLDVPROC oglGetVertexAttribLdv;

    typedef void(APIENTRYP PFNGLVIEWPORTARRAYVPROC)(GLuint_t first, GLsizei_t count, const GLfloat_t* v);
    PFNGLVIEWPORTARRAYVPROC oglViewportArrayv;

    typedef void(APIENTRYP PFNGLVIEWPORTINDEXEDFPROC)(GLuint_t index, GLfloat_t x, GLfloat_t y, GLfloat_t w, GLfloat_t h);
    PFNGLVIEWPORTINDEXEDFPROC oglViewportIndexedf;

    typedef void(APIENTRYP PFNGLVIEWPORTINDEXEDFVPROC)(GLuint_t index, const GLfloat_t* v);
    PFNGLVIEWPORTINDEXEDFVPROC oglViewportIndexedfv;

    typedef void(APIENTRYP PFNGLSCISSORARRAYVPROC)(GLuint_t first, GLsizei_t count, const GLint_t* v);
    PFNGLSCISSORARRAYVPROC oglScissorArrayv;

    typedef void(APIENTRYP PFNGLSCISSORINDEXEDPROC)(GLuint_t index, GLint_t left, GLint_t bottom, GLsizei_t width, GLsizei_t height);
    PFNGLSCISSORINDEXEDPROC oglScissorIndexed;

    typedef void(APIENTRYP PFNGLSCISSORINDEXEDVPROC)(GLuint_t index, const GLint_t* v);
    PFNGLSCISSORINDEXEDVPROC oglScissorIndexedv;

    typedef void(APIENTRYP PFNGLDEPTHRANGEARRAYVPROC)(GLuint_t first, GLsizei_t count, const GLdouble_t* v);
    PFNGLDEPTHRANGEARRAYVPROC oglDepthRangeArrayv;

    typedef void(APIENTRYP PFNGLDEPTHRANGEINDEXEDPROC)(GLuint_t index, GLdouble_t n, GLdouble_t f);
    PFNGLDEPTHRANGEINDEXEDPROC oglDepthRangeIndexed;

    typedef void(APIENTRYP PFNGLGETFLOATI_VPROC)(GLenum_t target, GLuint_t index, GLfloat_t* data);
    PFNGLGETFLOATI_VPROC oglGetFloati_v;

    typedef void(APIENTRYP PFNGLGETDOUBLEI_VPROC)(GLenum_t target, GLuint_t index, GLdouble_t* data);
    PFNGLGETDOUBLEI_VPROC oglGetDoublei_v;

  public:
    GLfuncsv410();

  protected:
    virtual void loadFuncs(Loader loader) override;
};

} // namespace glr
} // namespace xg
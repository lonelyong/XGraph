#pragma once

#include <glr/igl/GLfuncsv400.h>

namespace glr {
class GLR_API GLfuncsv410 : public GLfuncsv400 {
  public:
    typedef void(APIENTRYP PFNGLRELEASESHADERCOMPILERPROC)(void);
    PFNGLRELEASESHADERCOMPILERPROC glReleaseShaderCompiler;

    typedef void(APIENTRYP PFNGLSHADERBINARYPROC)(GLsizei       count,
                                                  const GLuint* shaders,
                                                  GLenum        binaryFormat,
                                                  const void*   binary,
                                                  GLsizei       length);
    PFNGLSHADERBINARYPROC glShaderBinary;

    typedef void(APIENTRYP PFNGLGETSHADERPRECISIONFORMATPROC)(GLenum shadertype,
                                                              GLenum precisiontype,
                                                              GLint* range,
                                                              GLint* precision);
    PFNGLGETSHADERPRECISIONFORMATPROC glGetShaderPrecisionFormat;

    typedef void(APIENTRYP PFNGLDEPTHRANGEFPROC)(GLfloat n, GLfloat f);
    PFNGLDEPTHRANGEFPROC glDepthRangef;

    typedef void(APIENTRYP PFNGLCLEARDEPTHFPROC)(GLfloat d);
    PFNGLCLEARDEPTHFPROC glClearDepthf;

    typedef void(APIENTRYP PFNGLGETPROGRAMBINARYPROC)(GLuint   program,
                                                      GLsizei  bufSize,
                                                      GLsizei* length,
                                                      GLenum*  binaryFormat,
                                                      void*    binary);
    PFNGLGETPROGRAMBINARYPROC glGetProgramBinary;

    typedef void(APIENTRYP PFNGLPROGRAMBINARYPROC)(GLuint      program,
                                                   GLenum      binaryFormat,
                                                   const void* binary,
                                                   GLsizei     length);
    PFNGLPROGRAMBINARYPROC glProgramBinary;

    typedef void(APIENTRYP PFNGLPROGRAMPARAMETERIPROC)(GLuint program, GLenum pname, GLint value);
    PFNGLPROGRAMPARAMETERIPROC glProgramParameteri;

    typedef void(APIENTRYP PFNGLUSEPROGRAMSTAGESPROC)(GLuint pipeline, GLbitfield stages, GLuint program);
    PFNGLUSEPROGRAMSTAGESPROC glUseProgramStages;

    typedef void(APIENTRYP PFNGLACTIVESHADERPROGRAMPROC)(GLuint pipeline, GLuint program);
    PFNGLACTIVESHADERPROGRAMPROC glActiveShaderProgram;

    typedef GLuint(APIENTRYP PFNGLCREATESHADERPROGRAMVPROC)(GLenum type, GLsizei count, const GLchar* const* strings);
    PFNGLCREATESHADERPROGRAMVPROC glCreateShaderProgramv;

    typedef void(APIENTRYP PFNGLBINDPROGRAMPIPELINEPROC)(GLuint pipeline);
    PFNGLBINDPROGRAMPIPELINEPROC glBindProgramPipeline;

    typedef void(APIENTRYP PFNGLDELETEPROGRAMPIPELINESPROC)(GLsizei n, const GLuint* pipelines);
    PFNGLDELETEPROGRAMPIPELINESPROC glDeleteProgramPipelines;

    typedef void(APIENTRYP PFNGLGENPROGRAMPIPELINESPROC)(GLsizei n, GLuint* pipelines);
    PFNGLGENPROGRAMPIPELINESPROC glGenProgramPipelines;

    typedef GLboolean(APIENTRYP PFNGLISPROGRAMPIPELINEPROC)(GLuint pipeline);
    PFNGLISPROGRAMPIPELINEPROC glIsProgramPipeline;

    typedef void(APIENTRYP PFNGLGETPROGRAMPIPELINEIVPROC)(GLuint pipeline, GLenum pname, GLint* params);
    PFNGLGETPROGRAMPIPELINEIVPROC glGetProgramPipelineiv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1IPROC)(GLuint program, GLint location, GLint v0);
    PFNGLPROGRAMUNIFORM1IPROC glProgramUniform1i;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1IVPROC)(GLuint       program,
                                                       GLint        location,
                                                       GLsizei      count,
                                                       const GLint* value);
    PFNGLPROGRAMUNIFORM1IVPROC glProgramUniform1iv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1FPROC)(GLuint program, GLint location, GLfloat v0);
    PFNGLPROGRAMUNIFORM1FPROC glProgramUniform1f;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1FVPROC)(GLuint         program,
                                                       GLint          location,
                                                       GLsizei        count,
                                                       const GLfloat* value);
    PFNGLPROGRAMUNIFORM1FVPROC glProgramUniform1fv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1DPROC)(GLuint program, GLint location, GLdouble v0);
    PFNGLPROGRAMUNIFORM1DPROC glProgramUniform1d;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1DVPROC)(GLuint          program,
                                                       GLint           location,
                                                       GLsizei         count,
                                                       const GLdouble* value);
    PFNGLPROGRAMUNIFORM1DVPROC glProgramUniform1dv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1UIPROC)(GLuint program, GLint location, GLuint v0);
    PFNGLPROGRAMUNIFORM1UIPROC glProgramUniform1ui;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1UIVPROC)(GLuint        program,
                                                        GLint         location,
                                                        GLsizei       count,
                                                        const GLuint* value);
    PFNGLPROGRAMUNIFORM1UIVPROC glProgramUniform1uiv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2IPROC)(GLuint program, GLint location, GLint v0, GLint v1);
    PFNGLPROGRAMUNIFORM2IPROC glProgramUniform2i;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2IVPROC)(GLuint       program,
                                                       GLint        location,
                                                       GLsizei      count,
                                                       const GLint* value);
    PFNGLPROGRAMUNIFORM2IVPROC glProgramUniform2iv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
    PFNGLPROGRAMUNIFORM2FPROC glProgramUniform2f;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2FVPROC)(GLuint         program,
                                                       GLint          location,
                                                       GLsizei        count,
                                                       const GLfloat* value);
    PFNGLPROGRAMUNIFORM2FVPROC glProgramUniform2fv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2DPROC)(GLuint program, GLint location, GLdouble v0, GLdouble v1);
    PFNGLPROGRAMUNIFORM2DPROC glProgramUniform2d;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2DVPROC)(GLuint          program,
                                                       GLint           location,
                                                       GLsizei         count,
                                                       const GLdouble* value);
    PFNGLPROGRAMUNIFORM2DVPROC glProgramUniform2dv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1);
    PFNGLPROGRAMUNIFORM2UIPROC glProgramUniform2ui;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2UIVPROC)(GLuint        program,
                                                        GLint         location,
                                                        GLsizei       count,
                                                        const GLuint* value);
    PFNGLPROGRAMUNIFORM2UIVPROC glProgramUniform2uiv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3IPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
    PFNGLPROGRAMUNIFORM3IPROC glProgramUniform3i;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3IVPROC)(GLuint       program,
                                                       GLint        location,
                                                       GLsizei      count,
                                                       const GLint* value);
    PFNGLPROGRAMUNIFORM3IVPROC glProgramUniform3iv;

    typedef void(
        APIENTRYP PFNGLPROGRAMUNIFORM3FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
    PFNGLPROGRAMUNIFORM3FPROC glProgramUniform3f;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3FVPROC)(GLuint         program,
                                                       GLint          location,
                                                       GLsizei        count,
                                                       const GLfloat* value);
    PFNGLPROGRAMUNIFORM3FVPROC glProgramUniform3fv;

    typedef void(
        APIENTRYP PFNGLPROGRAMUNIFORM3DPROC)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
    PFNGLPROGRAMUNIFORM3DPROC glProgramUniform3d;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3DVPROC)(GLuint          program,
                                                       GLint           location,
                                                       GLsizei         count,
                                                       const GLdouble* value);
    PFNGLPROGRAMUNIFORM3DVPROC glProgramUniform3dv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
    PFNGLPROGRAMUNIFORM3UIPROC glProgramUniform3ui;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3UIVPROC)(GLuint        program,
                                                        GLint         location,
                                                        GLsizei       count,
                                                        const GLuint* value);
    PFNGLPROGRAMUNIFORM3UIVPROC glProgramUniform3uiv;

    typedef void(
        APIENTRYP PFNGLPROGRAMUNIFORM4IPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
    PFNGLPROGRAMUNIFORM4IPROC glProgramUniform4i;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4IVPROC)(GLuint       program,
                                                       GLint        location,
                                                       GLsizei      count,
                                                       const GLint* value);
    PFNGLPROGRAMUNIFORM4IVPROC glProgramUniform4iv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4FPROC)(GLuint  program,
                                                      GLint   location,
                                                      GLfloat v0,
                                                      GLfloat v1,
                                                      GLfloat v2,
                                                      GLfloat v3);
    PFNGLPROGRAMUNIFORM4FPROC glProgramUniform4f;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4FVPROC)(GLuint         program,
                                                       GLint          location,
                                                       GLsizei        count,
                                                       const GLfloat* value);
    PFNGLPROGRAMUNIFORM4FVPROC glProgramUniform4fv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4DPROC)(GLuint   program,
                                                      GLint    location,
                                                      GLdouble v0,
                                                      GLdouble v1,
                                                      GLdouble v2,
                                                      GLdouble v3);
    PFNGLPROGRAMUNIFORM4DPROC glProgramUniform4d;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4DVPROC)(GLuint          program,
                                                       GLint           location,
                                                       GLsizei         count,
                                                       const GLdouble* value);
    PFNGLPROGRAMUNIFORM4DVPROC glProgramUniform4dv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4UIPROC)(GLuint program,
                                                       GLint  location,
                                                       GLuint v0,
                                                       GLuint v1,
                                                       GLuint v2,
                                                       GLuint v3);
    PFNGLPROGRAMUNIFORM4UIPROC glProgramUniform4ui;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4UIVPROC)(GLuint        program,
                                                        GLint         location,
                                                        GLsizei       count,
                                                        const GLuint* value);
    PFNGLPROGRAMUNIFORM4UIVPROC glProgramUniform4uiv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2FVPROC)(GLuint         program,
                                                             GLint          location,
                                                             GLsizei        count,
                                                             GLboolean      transpose,
                                                             const GLfloat* value);
    PFNGLPROGRAMUNIFORMMATRIX2FVPROC glProgramUniformMatrix2fv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3FVPROC)(GLuint         program,
                                                             GLint          location,
                                                             GLsizei        count,
                                                             GLboolean      transpose,
                                                             const GLfloat* value);
    PFNGLPROGRAMUNIFORMMATRIX3FVPROC glProgramUniformMatrix3fv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4FVPROC)(GLuint         program,
                                                             GLint          location,
                                                             GLsizei        count,
                                                             GLboolean      transpose,
                                                             const GLfloat* value);
    PFNGLPROGRAMUNIFORMMATRIX4FVPROC glProgramUniformMatrix4fv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2DVPROC)(GLuint          program,
                                                             GLint           location,
                                                             GLsizei         count,
                                                             GLboolean       transpose,
                                                             const GLdouble* value);
    PFNGLPROGRAMUNIFORMMATRIX2DVPROC glProgramUniformMatrix2dv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3DVPROC)(GLuint          program,
                                                             GLint           location,
                                                             GLsizei         count,
                                                             GLboolean       transpose,
                                                             const GLdouble* value);
    PFNGLPROGRAMUNIFORMMATRIX3DVPROC glProgramUniformMatrix3dv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4DVPROC)(GLuint          program,
                                                             GLint           location,
                                                             GLsizei         count,
                                                             GLboolean       transpose,
                                                             const GLdouble* value);
    PFNGLPROGRAMUNIFORMMATRIX4DVPROC glProgramUniformMatrix4dv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)(GLuint         program,
                                                               GLint          location,
                                                               GLsizei        count,
                                                               GLboolean      transpose,
                                                               const GLfloat* value);
    PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC glProgramUniformMatrix2x3fv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)(GLuint         program,
                                                               GLint          location,
                                                               GLsizei        count,
                                                               GLboolean      transpose,
                                                               const GLfloat* value);
    PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC glProgramUniformMatrix3x2fv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)(GLuint         program,
                                                               GLint          location,
                                                               GLsizei        count,
                                                               GLboolean      transpose,
                                                               const GLfloat* value);
    PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC glProgramUniformMatrix2x4fv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)(GLuint         program,
                                                               GLint          location,
                                                               GLsizei        count,
                                                               GLboolean      transpose,
                                                               const GLfloat* value);
    PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC glProgramUniformMatrix4x2fv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)(GLuint         program,
                                                               GLint          location,
                                                               GLsizei        count,
                                                               GLboolean      transpose,
                                                               const GLfloat* value);
    PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC glProgramUniformMatrix3x4fv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)(GLuint         program,
                                                               GLint          location,
                                                               GLsizei        count,
                                                               GLboolean      transpose,
                                                               const GLfloat* value);
    PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC glProgramUniformMatrix4x3fv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)(GLuint          program,
                                                               GLint           location,
                                                               GLsizei         count,
                                                               GLboolean       transpose,
                                                               const GLdouble* value);
    PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC glProgramUniformMatrix2x3dv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)(GLuint          program,
                                                               GLint           location,
                                                               GLsizei         count,
                                                               GLboolean       transpose,
                                                               const GLdouble* value);
    PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC glProgramUniformMatrix3x2dv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)(GLuint          program,
                                                               GLint           location,
                                                               GLsizei         count,
                                                               GLboolean       transpose,
                                                               const GLdouble* value);
    PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC glProgramUniformMatrix2x4dv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)(GLuint          program,
                                                               GLint           location,
                                                               GLsizei         count,
                                                               GLboolean       transpose,
                                                               const GLdouble* value);
    PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC glProgramUniformMatrix4x2dv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)(GLuint          program,
                                                               GLint           location,
                                                               GLsizei         count,
                                                               GLboolean       transpose,
                                                               const GLdouble* value);
    PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC glProgramUniformMatrix3x4dv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)(GLuint          program,
                                                               GLint           location,
                                                               GLsizei         count,
                                                               GLboolean       transpose,
                                                               const GLdouble* value);
    PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC glProgramUniformMatrix4x3dv;

    typedef void(APIENTRYP PFNGLVALIDATEPROGRAMPIPELINEPROC)(GLuint pipeline);
    PFNGLVALIDATEPROGRAMPIPELINEPROC glValidateProgramPipeline;

    typedef void(APIENTRYP PFNGLGETPROGRAMPIPELINEINFOLOGPROC)(GLuint   pipeline,
                                                               GLsizei  bufSize,
                                                               GLsizei* length,
                                                               GLchar*  infoLog);
    PFNGLGETPROGRAMPIPELINEINFOLOGPROC glGetProgramPipelineInfoLog;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBL1DPROC)(GLuint index, GLdouble x);
    PFNGLVERTEXATTRIBL1DPROC glVertexAttribL1d;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBL2DPROC)(GLuint index, GLdouble x, GLdouble y);
    PFNGLVERTEXATTRIBL2DPROC glVertexAttribL2d;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBL3DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
    PFNGLVERTEXATTRIBL3DPROC glVertexAttribL3d;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBL4DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    PFNGLVERTEXATTRIBL4DPROC glVertexAttribL4d;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBL1DVPROC)(GLuint index, const GLdouble* v);
    PFNGLVERTEXATTRIBL1DVPROC glVertexAttribL1dv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBL2DVPROC)(GLuint index, const GLdouble* v);
    PFNGLVERTEXATTRIBL2DVPROC glVertexAttribL2dv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBL3DVPROC)(GLuint index, const GLdouble* v);
    PFNGLVERTEXATTRIBL3DVPROC glVertexAttribL3dv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBL4DVPROC)(GLuint index, const GLdouble* v);
    PFNGLVERTEXATTRIBL4DVPROC glVertexAttribL4dv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBLPOINTERPROC)(GLuint      index,
                                                          GLint       size,
                                                          GLenum      type,
                                                          GLsizei     stride,
                                                          const void* pointer);
    PFNGLVERTEXATTRIBLPOINTERPROC glVertexAttribLPointer;

    typedef void(APIENTRYP PFNGLGETVERTEXATTRIBLDVPROC)(GLuint index, GLenum pname, GLdouble* params);
    PFNGLGETVERTEXATTRIBLDVPROC glGetVertexAttribLdv;

    typedef void(APIENTRYP PFNGLVIEWPORTARRAYVPROC)(GLuint first, GLsizei count, const GLfloat* v);
    PFNGLVIEWPORTARRAYVPROC glViewportArrayv;

    typedef void(APIENTRYP PFNGLVIEWPORTINDEXEDFPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
    PFNGLVIEWPORTINDEXEDFPROC glViewportIndexedf;

    typedef void(APIENTRYP PFNGLVIEWPORTINDEXEDFVPROC)(GLuint index, const GLfloat* v);
    PFNGLVIEWPORTINDEXEDFVPROC glViewportIndexedfv;

    typedef void(APIENTRYP PFNGLSCISSORARRAYVPROC)(GLuint first, GLsizei count, const GLint* v);
    PFNGLSCISSORARRAYVPROC glScissorArrayv;

    typedef void(
        APIENTRYP PFNGLSCISSORINDEXEDPROC)(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
    PFNGLSCISSORINDEXEDPROC glScissorIndexed;

    typedef void(APIENTRYP PFNGLSCISSORINDEXEDVPROC)(GLuint index, const GLint* v);
    PFNGLSCISSORINDEXEDVPROC glScissorIndexedv;

    typedef void(APIENTRYP PFNGLDEPTHRANGEARRAYVPROC)(GLuint first, GLsizei count, const GLdouble* v);
    PFNGLDEPTHRANGEARRAYVPROC glDepthRangeArrayv;

    typedef void(APIENTRYP PFNGLDEPTHRANGEINDEXEDPROC)(GLuint index, GLdouble n, GLdouble f);
    PFNGLDEPTHRANGEINDEXEDPROC glDepthRangeIndexed;

    typedef void(APIENTRYP PFNGLGETFLOATI_VPROC)(GLenum target, GLuint index, GLfloat* data);
    PFNGLGETFLOATI_VPROC glGetFloati_v;

    typedef void(APIENTRYP PFNGLGETDOUBLEI_VPROC)(GLenum target, GLuint index, GLdouble* data);
    PFNGLGETDOUBLEI_VPROC glGetDoublei_v;

  public:
    GLfuncsv410();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
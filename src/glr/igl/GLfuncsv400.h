#pragma once

#include <glr/igl/GLfuncsv330.h>

namespace glr {
class GLR_API GLfuncsv400 : public GLfuncsv330 {
  public:
    typedef void(APIENTRYP PFNGLMINSAMPLESHADINGPROC)(GLfloat value);
    PFNGLMINSAMPLESHADINGPROC glMinSampleShading;

    typedef void(APIENTRYP PFNGLBLENDEQUATIONIPROC)(GLuint buf, GLenum mode);
    PFNGLBLENDEQUATIONIPROC glBlendEquationi;

    typedef void(APIENTRYP PFNGLBLENDEQUATIONSEPARATEIPROC)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
    PFNGLBLENDEQUATIONSEPARATEIPROC glBlendEquationSeparatei;

    typedef void(APIENTRYP PFNGLBLENDFUNCIPROC)(GLuint buf, GLenum src, GLenum dst);
    PFNGLBLENDFUNCIPROC glBlendFunci;

    typedef void(APIENTRYP PFNGLBLENDFUNCSEPARATEIPROC)(GLuint buf,
                                                        GLenum srcRGB,
                                                        GLenum dstRGB,
                                                        GLenum srcAlpha,
                                                        GLenum dstAlpha);
    PFNGLBLENDFUNCSEPARATEIPROC glBlendFuncSeparatei;

    typedef void(APIENTRYP PFNGLDRAWARRAYSINDIRECTPROC)(GLenum mode, const void* indirect);
    PFNGLDRAWARRAYSINDIRECTPROC glDrawArraysIndirect;

    typedef void(APIENTRYP PFNGLDRAWELEMENTSINDIRECTPROC)(GLenum mode, GLenum type, const void* indirect);
    PFNGLDRAWELEMENTSINDIRECTPROC glDrawElementsIndirect;

    typedef void(APIENTRYP PFNGLUNIFORM1DPROC)(GLint location, GLdouble x);
    PFNGLUNIFORM1DPROC glUniform1d;

    typedef void(APIENTRYP PFNGLUNIFORM2DPROC)(GLint location, GLdouble x, GLdouble y);
    PFNGLUNIFORM2DPROC glUniform2d;

    typedef void(APIENTRYP PFNGLUNIFORM3DPROC)(GLint location, GLdouble x, GLdouble y, GLdouble z);
    PFNGLUNIFORM3DPROC glUniform3d;

    typedef void(APIENTRYP PFNGLUNIFORM4DPROC)(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    PFNGLUNIFORM4DPROC glUniform4d;

    typedef void(APIENTRYP PFNGLUNIFORM1DVPROC)(GLint location, GLsizei count, const GLdouble* value);
    PFNGLUNIFORM1DVPROC glUniform1dv;

    typedef void(APIENTRYP PFNGLUNIFORM2DVPROC)(GLint location, GLsizei count, const GLdouble* value);
    PFNGLUNIFORM2DVPROC glUniform2dv;

    typedef void(APIENTRYP PFNGLUNIFORM3DVPROC)(GLint location, GLsizei count, const GLdouble* value);
    PFNGLUNIFORM3DVPROC glUniform3dv;

    typedef void(APIENTRYP PFNGLUNIFORM4DVPROC)(GLint location, GLsizei count, const GLdouble* value);
    PFNGLUNIFORM4DVPROC glUniform4dv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX2DVPROC)(GLint           location,
                                                      GLsizei         count,
                                                      GLboolean       transpose,
                                                      const GLdouble* value);
    PFNGLUNIFORMMATRIX2DVPROC glUniformMatrix2dv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX3DVPROC)(GLint           location,
                                                      GLsizei         count,
                                                      GLboolean       transpose,
                                                      const GLdouble* value);
    PFNGLUNIFORMMATRIX3DVPROC glUniformMatrix3dv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX4DVPROC)(GLint           location,
                                                      GLsizei         count,
                                                      GLboolean       transpose,
                                                      const GLdouble* value);
    PFNGLUNIFORMMATRIX4DVPROC glUniformMatrix4dv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX2X3DVPROC)(GLint           location,
                                                        GLsizei         count,
                                                        GLboolean       transpose,
                                                        const GLdouble* value);
    PFNGLUNIFORMMATRIX2X3DVPROC glUniformMatrix2x3dv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX2X4DVPROC)(GLint           location,
                                                        GLsizei         count,
                                                        GLboolean       transpose,
                                                        const GLdouble* value);
    PFNGLUNIFORMMATRIX2X4DVPROC glUniformMatrix2x4dv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX3X2DVPROC)(GLint           location,
                                                        GLsizei         count,
                                                        GLboolean       transpose,
                                                        const GLdouble* value);
    PFNGLUNIFORMMATRIX3X2DVPROC glUniformMatrix3x2dv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX3X4DVPROC)(GLint           location,
                                                        GLsizei         count,
                                                        GLboolean       transpose,
                                                        const GLdouble* value);
    PFNGLUNIFORMMATRIX3X4DVPROC glUniformMatrix3x4dv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX4X2DVPROC)(GLint           location,
                                                        GLsizei         count,
                                                        GLboolean       transpose,
                                                        const GLdouble* value);
    PFNGLUNIFORMMATRIX4X2DVPROC glUniformMatrix4x2dv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX4X3DVPROC)(GLint           location,
                                                        GLsizei         count,
                                                        GLboolean       transpose,
                                                        const GLdouble* value);
    PFNGLUNIFORMMATRIX4X3DVPROC glUniformMatrix4x3dv;

    typedef void(APIENTRYP PFNGLGETUNIFORMDVPROC)(GLuint program, GLint location, GLdouble* params);
    PFNGLGETUNIFORMDVPROC glGetUniformdv;

    typedef GLint(APIENTRYP PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)(GLuint        program,
                                                                   GLenum        shadertype,
                                                                   const GLchar* name);
    PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC glGetSubroutineUniformLocation;

    typedef GLuint(APIENTRYP PFNGLGETSUBROUTINEINDEXPROC)(GLuint program, GLenum shadertype, const GLchar* name);
    PFNGLGETSUBROUTINEINDEXPROC glGetSubroutineIndex;

    typedef void(APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)(GLuint program,
                                                                  GLenum shadertype,
                                                                  GLuint index,
                                                                  GLenum pname,
                                                                  GLint* values);
    PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC glGetActiveSubroutineUniformiv;

    typedef void(APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)(GLuint   program,
                                                                    GLenum   shadertype,
                                                                    GLuint   index,
                                                                    GLsizei  bufSize,
                                                                    GLsizei* length,
                                                                    GLchar*  name);
    PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC glGetActiveSubroutineUniformName;

    typedef void(APIENTRYP PFNGLGETACTIVESUBROUTINENAMEPROC)(GLuint   program,
                                                             GLenum   shadertype,
                                                             GLuint   index,
                                                             GLsizei  bufSize,
                                                             GLsizei* length,
                                                             GLchar*  name);
    PFNGLGETACTIVESUBROUTINENAMEPROC glGetActiveSubroutineName;

    typedef void(APIENTRYP PFNGLUNIFORMSUBROUTINESUIVPROC)(GLenum shadertype, GLsizei count, const GLuint* indices);
    PFNGLUNIFORMSUBROUTINESUIVPROC glUniformSubroutinesuiv;

    typedef void(APIENTRYP PFNGLGETUNIFORMSUBROUTINEUIVPROC)(GLenum shadertype, GLint location, GLuint* params);
    PFNGLGETUNIFORMSUBROUTINEUIVPROC glGetUniformSubroutineuiv;

    typedef void(APIENTRYP PFNGLGETPROGRAMSTAGEIVPROC)(GLuint program, GLenum shadertype, GLenum pname, GLint* values);
    PFNGLGETPROGRAMSTAGEIVPROC glGetProgramStageiv;

    typedef void(APIENTRYP PFNGLPATCHPARAMETERIPROC)(GLenum pname, GLint value);
    PFNGLPATCHPARAMETERIPROC glPatchParameteri;

    typedef void(APIENTRYP PFNGLPATCHPARAMETERFVPROC)(GLenum pname, const GLfloat* values);
    PFNGLPATCHPARAMETERFVPROC glPatchParameterfv;

    typedef void(APIENTRYP PFNGLBINDTRANSFORMFEEDBACKPROC)(GLenum target, GLuint id);
    PFNGLBINDTRANSFORMFEEDBACKPROC glBindTransformFeedback;

    typedef void(APIENTRYP PFNGLDELETETRANSFORMFEEDBACKSPROC)(GLsizei n, const GLuint* ids);
    PFNGLDELETETRANSFORMFEEDBACKSPROC glDeleteTransformFeedbacks;

    typedef void(APIENTRYP PFNGLGENTRANSFORMFEEDBACKSPROC)(GLsizei n, GLuint* ids);
    PFNGLGENTRANSFORMFEEDBACKSPROC glGenTransformFeedbacks;

    typedef GLboolean(APIENTRYP PFNGLISTRANSFORMFEEDBACKPROC)(GLuint id);
    PFNGLISTRANSFORMFEEDBACKPROC glIsTransformFeedback;

    typedef void(APIENTRYP PFNGLPAUSETRANSFORMFEEDBACKPROC)(void);
    PFNGLPAUSETRANSFORMFEEDBACKPROC glPauseTransformFeedback;

    typedef void(APIENTRYP PFNGLRESUMETRANSFORMFEEDBACKPROC)(void);
    PFNGLRESUMETRANSFORMFEEDBACKPROC glResumeTransformFeedback;

    typedef void(APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKPROC)(GLenum mode, GLuint id);
    PFNGLDRAWTRANSFORMFEEDBACKPROC glDrawTransformFeedback;

    typedef void(APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)(GLenum mode, GLuint id, GLuint stream);
    PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC glDrawTransformFeedbackStream;

    typedef void(APIENTRYP PFNGLBEGINQUERYINDEXEDPROC)(GLenum target, GLuint index, GLuint id);
    PFNGLBEGINQUERYINDEXEDPROC glBeginQueryIndexed;

    typedef void(APIENTRYP PFNGLENDQUERYINDEXEDPROC)(GLenum target, GLuint index);
    PFNGLENDQUERYINDEXEDPROC glEndQueryIndexed;

    typedef void(APIENTRYP PFNGLGETQUERYINDEXEDIVPROC)(GLenum target, GLuint index, GLenum pname, GLint* params);
    PFNGLGETQUERYINDEXEDIVPROC glGetQueryIndexediv;

  public:
    GLfuncsv400();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
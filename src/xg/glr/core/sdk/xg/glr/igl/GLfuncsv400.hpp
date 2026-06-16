#pragma once

#include <xg/glr/igl/GLfuncsv330.hpp>

namespace xg {
namespace glr {
class GLR_API GLfuncsv400 : public GLfuncsv330 {

  public:
    typedef void(APIENTRYP PFNGLMINSAMPLESHADINGPROC)(GLfloat_t value);
    PFNGLMINSAMPLESHADINGPROC iglMinSampleShading;

    typedef void(APIENTRYP PFNGLBLENDEQUATIONIPROC)(GLuint_t buf, GLenum_t mode);
    PFNGLBLENDEQUATIONIPROC iglBlendEquationi;

    typedef void(APIENTRYP PFNGLBLENDEQUATIONSEPARATEIPROC)(GLuint_t buf, GLenum_t modeRGB, GLenum_t modeAlpha);
    PFNGLBLENDEQUATIONSEPARATEIPROC iglBlendEquationSeparatei;

    typedef void(APIENTRYP PFNGLBLENDFUNCIPROC)(GLuint_t buf, GLenum_t src, GLenum_t dst);
    PFNGLBLENDFUNCIPROC iglBlendFunci;

    typedef void(APIENTRYP PFNGLBLENDFUNCSEPARATEIPROC)(GLuint_t buf,
                                                        GLenum_t srcRGB,
                                                        GLenum_t dstRGB,
                                                        GLenum_t srcAlpha,
                                                        GLenum_t dstAlpha);
    PFNGLBLENDFUNCSEPARATEIPROC iglBlendFuncSeparatei;

    typedef void(APIENTRYP PFNGLDRAWARRAYSINDIRECTPROC)(GLenum_t mode, const void* indirect);
    PFNGLDRAWARRAYSINDIRECTPROC iglDrawArraysIndirect;

    typedef void(APIENTRYP PFNGLDRAWELEMENTSINDIRECTPROC)(GLenum_t mode, GLenum_t type, const void* indirect);
    PFNGLDRAWELEMENTSINDIRECTPROC iglDrawElementsIndirect;

    typedef void(APIENTRYP PFNGLUNIFORM1DPROC)(GLint_t location, GLdouble_t x);
    PFNGLUNIFORM1DPROC iglUniform1d;

    typedef void(APIENTRYP PFNGLUNIFORM2DPROC)(GLint_t location, GLdouble_t x, GLdouble_t y);
    PFNGLUNIFORM2DPROC iglUniform2d;

    typedef void(APIENTRYP PFNGLUNIFORM3DPROC)(GLint_t location, GLdouble_t x, GLdouble_t y, GLdouble_t z);
    PFNGLUNIFORM3DPROC iglUniform3d;

    typedef void(APIENTRYP PFNGLUNIFORM4DPROC)(GLint_t location, GLdouble_t x, GLdouble_t y, GLdouble_t z, GLdouble_t w);
    PFNGLUNIFORM4DPROC iglUniform4d;

    typedef void(APIENTRYP PFNGLUNIFORM1DVPROC)(GLint_t location, GLsizei_t count, const GLdouble_t* value);
    PFNGLUNIFORM1DVPROC iglUniform1dv;

    typedef void(APIENTRYP PFNGLUNIFORM2DVPROC)(GLint_t location, GLsizei_t count, const GLdouble_t* value);
    PFNGLUNIFORM2DVPROC iglUniform2dv;

    typedef void(APIENTRYP PFNGLUNIFORM3DVPROC)(GLint_t location, GLsizei_t count, const GLdouble_t* value);
    PFNGLUNIFORM3DVPROC iglUniform3dv;

    typedef void(APIENTRYP PFNGLUNIFORM4DVPROC)(GLint_t location, GLsizei_t count, const GLdouble_t* value);
    PFNGLUNIFORM4DVPROC iglUniform4dv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX2DVPROC)(GLint_t           location,
                                                      GLsizei_t         count,
                                                      GLboolean_t       transpose,
                                                      const GLdouble_t* value);
    PFNGLUNIFORMMATRIX2DVPROC iglUniformMatrix2dv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX3DVPROC)(GLint_t           location,
                                                      GLsizei_t         count,
                                                      GLboolean_t       transpose,
                                                      const GLdouble_t* value);
    PFNGLUNIFORMMATRIX3DVPROC iglUniformMatrix3dv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX4DVPROC)(GLint_t           location,
                                                      GLsizei_t         count,
                                                      GLboolean_t       transpose,
                                                      const GLdouble_t* value);
    PFNGLUNIFORMMATRIX4DVPROC iglUniformMatrix4dv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX2X3DVPROC)(GLint_t           location,
                                                        GLsizei_t         count,
                                                        GLboolean_t       transpose,
                                                        const GLdouble_t* value);
    PFNGLUNIFORMMATRIX2X3DVPROC iglUniformMatrix2x3dv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX2X4DVPROC)(GLint_t           location,
                                                        GLsizei_t         count,
                                                        GLboolean_t       transpose,
                                                        const GLdouble_t* value);
    PFNGLUNIFORMMATRIX2X4DVPROC iglUniformMatrix2x4dv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX3X2DVPROC)(GLint_t           location,
                                                        GLsizei_t         count,
                                                        GLboolean_t       transpose,
                                                        const GLdouble_t* value);
    PFNGLUNIFORMMATRIX3X2DVPROC iglUniformMatrix3x2dv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX3X4DVPROC)(GLint_t           location,
                                                        GLsizei_t         count,
                                                        GLboolean_t       transpose,
                                                        const GLdouble_t* value);
    PFNGLUNIFORMMATRIX3X4DVPROC iglUniformMatrix3x4dv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX4X2DVPROC)(GLint_t           location,
                                                        GLsizei_t         count,
                                                        GLboolean_t       transpose,
                                                        const GLdouble_t* value);
    PFNGLUNIFORMMATRIX4X2DVPROC iglUniformMatrix4x2dv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX4X3DVPROC)(GLint_t           location,
                                                        GLsizei_t         count,
                                                        GLboolean_t       transpose,
                                                        const GLdouble_t* value);
    PFNGLUNIFORMMATRIX4X3DVPROC iglUniformMatrix4x3dv;

    typedef void(APIENTRYP PFNGLGETUNIFORMDVPROC)(GLuint_t program, GLint_t location, GLdouble_t* params);
    PFNGLGETUNIFORMDVPROC iglGetUniformdv;

    typedef GLint_t(APIENTRYP PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)(GLuint_t        program,
                                                                   GLenum_t        shadertype,
                                                                   const GLchar_t* name);
    PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC iglGetSubroutineUniformLocation;

    typedef GLuint_t(APIENTRYP PFNGLGETSUBROUTINEINDEXPROC)(GLuint_t program, GLenum_t shadertype, const GLchar_t* name);
    PFNGLGETSUBROUTINEINDEXPROC iglGetSubroutineIndex;

    typedef void(APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)(GLuint_t program,
                                                                  GLenum_t shadertype,
                                                                  GLuint_t index,
                                                                  GLenum_t pname,
                                                                  GLint_t* values);
    PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC iglGetActiveSubroutineUniformiv;

    typedef void(APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)(GLuint_t   program,
                                                                    GLenum_t   shadertype,
                                                                    GLuint_t   index,
                                                                    GLsizei_t  bufSize,
                                                                    GLsizei_t* length,
                                                                    GLchar_t*  name);
    PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC iglGetActiveSubroutineUniformName;

    typedef void(APIENTRYP PFNGLGETACTIVESUBROUTINENAMEPROC)(GLuint_t   program,
                                                             GLenum_t   shadertype,
                                                             GLuint_t   index,
                                                             GLsizei_t  bufSize,
                                                             GLsizei_t* length,
                                                             GLchar_t*  name);
    PFNGLGETACTIVESUBROUTINENAMEPROC iglGetActiveSubroutineName;

    typedef void(APIENTRYP PFNGLUNIFORMSUBROUTINESUIVPROC)(GLenum_t shadertype, GLsizei_t count, const GLuint_t* indices);
    PFNGLUNIFORMSUBROUTINESUIVPROC iglUniformSubroutinesuiv;

    typedef void(APIENTRYP PFNGLGETUNIFORMSUBROUTINEUIVPROC)(GLenum_t shadertype, GLint_t location, GLuint_t* params);
    PFNGLGETUNIFORMSUBROUTINEUIVPROC iglGetUniformSubroutineuiv;

    typedef void(APIENTRYP PFNGLGETPROGRAMSTAGEIVPROC)(GLuint_t program, GLenum_t shadertype, GLenum_t pname, GLint_t* values);
    PFNGLGETPROGRAMSTAGEIVPROC iglGetProgramStageiv;

    typedef void(APIENTRYP PFNGLPATCHPARAMETERIPROC)(GLenum_t pname, GLint_t value);
    PFNGLPATCHPARAMETERIPROC iglPatchParameteri;

    typedef void(APIENTRYP PFNGLPATCHPARAMETERFVPROC)(GLenum_t pname, const GLfloat_t* values);
    PFNGLPATCHPARAMETERFVPROC iglPatchParameterfv;

    typedef void(APIENTRYP PFNGLBINDTRANSFORMFEEDBACKPROC)(GLenum_t target, GLuint_t id);
    PFNGLBINDTRANSFORMFEEDBACKPROC iglBindTransformFeedback;

    typedef void(APIENTRYP PFNGLDELETETRANSFORMFEEDBACKSPROC)(GLsizei_t n, const GLuint_t* ids);
    PFNGLDELETETRANSFORMFEEDBACKSPROC iglDeleteTransformFeedbacks;

    typedef void(APIENTRYP PFNGLGENTRANSFORMFEEDBACKSPROC)(GLsizei_t n, GLuint_t* ids);
    PFNGLGENTRANSFORMFEEDBACKSPROC iglGenTransformFeedbacks;

    typedef GLboolean_t(APIENTRYP PFNGLISTRANSFORMFEEDBACKPROC)(GLuint_t id);
    PFNGLISTRANSFORMFEEDBACKPROC iglIsTransformFeedback;

    typedef void(APIENTRYP PFNGLPAUSETRANSFORMFEEDBACKPROC)(void);
    PFNGLPAUSETRANSFORMFEEDBACKPROC iglPauseTransformFeedback;

    typedef void(APIENTRYP PFNGLRESUMETRANSFORMFEEDBACKPROC)(void);
    PFNGLRESUMETRANSFORMFEEDBACKPROC iglResumeTransformFeedback;

    typedef void(APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKPROC)(GLenum_t mode, GLuint_t id);
    PFNGLDRAWTRANSFORMFEEDBACKPROC iglDrawTransformFeedback;

    typedef void(APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)(GLenum_t mode, GLuint_t id, GLuint_t stream);
    PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC iglDrawTransformFeedbackStream;

    typedef void(APIENTRYP PFNGLBEGINQUERYINDEXEDPROC)(GLenum_t target, GLuint_t index, GLuint_t id);
    PFNGLBEGINQUERYINDEXEDPROC iglBeginQueryIndexed;

    typedef void(APIENTRYP PFNGLENDQUERYINDEXEDPROC)(GLenum_t target, GLuint_t index);
    PFNGLENDQUERYINDEXEDPROC iglEndQueryIndexed;

    typedef void(APIENTRYP PFNGLGETQUERYINDEXEDIVPROC)(GLenum_t target, GLuint_t index, GLenum_t pname, GLint_t* params);
    PFNGLGETQUERYINDEXEDIVPROC iglGetQueryIndexediv;

  public:
    GLfuncsv400();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
} // namespace xg
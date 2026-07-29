#pragma once

#include <xg/igl/ogl/GLfuncsv330.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API GLfuncsv400 : public GLfuncsv330 {

  public:
    typedef void(APIENTRYP PFNGLMINSAMPLESHADINGPROC)(GLfloat_t value);
    PFNGLMINSAMPLESHADINGPROC oglMinSampleShading;

    typedef void(APIENTRYP PFNGLBLENDEQUATIONIPROC)(GLuint_t buf, GLenum_t mode);
    PFNGLBLENDEQUATIONIPROC oglBlendEquationi;

    typedef void(APIENTRYP PFNGLBLENDEQUATIONSEPARATEIPROC)(GLuint_t buf, GLenum_t modeRGB, GLenum_t modeAlpha);
    PFNGLBLENDEQUATIONSEPARATEIPROC oglBlendEquationSeparatei;

    typedef void(APIENTRYP PFNGLBLENDFUNCIPROC)(GLuint_t buf, GLenum_t src, GLenum_t dst);
    PFNGLBLENDFUNCIPROC oglBlendFunci;

    typedef void(APIENTRYP PFNGLBLENDFUNCSEPARATEIPROC)(GLuint_t buf, GLenum_t srcRGB, GLenum_t dstRGB, GLenum_t srcAlpha, GLenum_t dstAlpha);
    PFNGLBLENDFUNCSEPARATEIPROC oglBlendFuncSeparatei;

    typedef void(APIENTRYP PFNGLDRAWARRAYSINDIRECTPROC)(GLenum_t mode, const void* indirect);
    PFNGLDRAWARRAYSINDIRECTPROC oglDrawArraysIndirect;

    typedef void(APIENTRYP PFNGLDRAWELEMENTSINDIRECTPROC)(GLenum_t mode, GLenum_t type, const void* indirect);
    PFNGLDRAWELEMENTSINDIRECTPROC oglDrawElementsIndirect;

    typedef void(APIENTRYP PFNGLUNIFORM1DPROC)(GLint_t location, GLdouble_t x);
    PFNGLUNIFORM1DPROC oglUniform1d;

    typedef void(APIENTRYP PFNGLUNIFORM2DPROC)(GLint_t location, GLdouble_t x, GLdouble_t y);
    PFNGLUNIFORM2DPROC oglUniform2d;

    typedef void(APIENTRYP PFNGLUNIFORM3DPROC)(GLint_t location, GLdouble_t x, GLdouble_t y, GLdouble_t z);
    PFNGLUNIFORM3DPROC oglUniform3d;

    typedef void(APIENTRYP PFNGLUNIFORM4DPROC)(GLint_t location, GLdouble_t x, GLdouble_t y, GLdouble_t z, GLdouble_t w);
    PFNGLUNIFORM4DPROC oglUniform4d;

    typedef void(APIENTRYP PFNGLUNIFORM1DVPROC)(GLint_t location, GLsizei_t count, const GLdouble_t* value);
    PFNGLUNIFORM1DVPROC oglUniform1dv;

    typedef void(APIENTRYP PFNGLUNIFORM2DVPROC)(GLint_t location, GLsizei_t count, const GLdouble_t* value);
    PFNGLUNIFORM2DVPROC oglUniform2dv;

    typedef void(APIENTRYP PFNGLUNIFORM3DVPROC)(GLint_t location, GLsizei_t count, const GLdouble_t* value);
    PFNGLUNIFORM3DVPROC oglUniform3dv;

    typedef void(APIENTRYP PFNGLUNIFORM4DVPROC)(GLint_t location, GLsizei_t count, const GLdouble_t* value);
    PFNGLUNIFORM4DVPROC oglUniform4dv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX2DVPROC)(GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLdouble_t* value);
    PFNGLUNIFORMMATRIX2DVPROC oglUniformMatrix2dv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX3DVPROC)(GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLdouble_t* value);
    PFNGLUNIFORMMATRIX3DVPROC oglUniformMatrix3dv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX4DVPROC)(GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLdouble_t* value);
    PFNGLUNIFORMMATRIX4DVPROC oglUniformMatrix4dv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX2X3DVPROC)(GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLdouble_t* value);
    PFNGLUNIFORMMATRIX2X3DVPROC oglUniformMatrix2x3dv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX2X4DVPROC)(GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLdouble_t* value);
    PFNGLUNIFORMMATRIX2X4DVPROC oglUniformMatrix2x4dv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX3X2DVPROC)(GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLdouble_t* value);
    PFNGLUNIFORMMATRIX3X2DVPROC oglUniformMatrix3x2dv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX3X4DVPROC)(GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLdouble_t* value);
    PFNGLUNIFORMMATRIX3X4DVPROC oglUniformMatrix3x4dv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX4X2DVPROC)(GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLdouble_t* value);
    PFNGLUNIFORMMATRIX4X2DVPROC oglUniformMatrix4x2dv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX4X3DVPROC)(GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLdouble_t* value);
    PFNGLUNIFORMMATRIX4X3DVPROC oglUniformMatrix4x3dv;

    typedef void(APIENTRYP PFNGLGETUNIFORMDVPROC)(GLuint_t program, GLint_t location, GLdouble_t* params);
    PFNGLGETUNIFORMDVPROC oglGetUniformdv;

    typedef GLint_t(APIENTRYP PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)(GLuint_t program, GLenum_t shadertype, const GLchar_t* name);
    PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC oglGetSubroutineUniformLocation;

    typedef GLuint_t(APIENTRYP PFNGLGETSUBROUTINEINDEXPROC)(GLuint_t program, GLenum_t shadertype, const GLchar_t* name);
    PFNGLGETSUBROUTINEINDEXPROC oglGetSubroutineIndex;

    typedef void(APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)(GLuint_t program, GLenum_t shadertype, GLuint_t index, GLenum_t pname, GLint_t* values);
    PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC oglGetActiveSubroutineUniformiv;

    typedef void(APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)(GLuint_t   program,
                                                                    GLenum_t   shadertype,
                                                                    GLuint_t   index,
                                                                    GLsizei_t  bufSize,
                                                                    GLsizei_t* length,
                                                                    GLchar_t*  name);
    PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC oglGetActiveSubroutineUniformName;

    typedef void(APIENTRYP PFNGLGETACTIVESUBROUTINENAMEPROC)(GLuint_t   program,
                                                             GLenum_t   shadertype,
                                                             GLuint_t   index,
                                                             GLsizei_t  bufSize,
                                                             GLsizei_t* length,
                                                             GLchar_t*  name);
    PFNGLGETACTIVESUBROUTINENAMEPROC oglGetActiveSubroutineName;

    typedef void(APIENTRYP PFNGLUNIFORMSUBROUTINESUIVPROC)(GLenum_t shadertype, GLsizei_t count, const GLuint_t* indices);
    PFNGLUNIFORMSUBROUTINESUIVPROC oglUniformSubroutinesuiv;

    typedef void(APIENTRYP PFNGLGETUNIFORMSUBROUTINEUIVPROC)(GLenum_t shadertype, GLint_t location, GLuint_t* params);
    PFNGLGETUNIFORMSUBROUTINEUIVPROC oglGetUniformSubroutineuiv;

    typedef void(APIENTRYP PFNGLGETPROGRAMSTAGEIVPROC)(GLuint_t program, GLenum_t shadertype, GLenum_t pname, GLint_t* values);
    PFNGLGETPROGRAMSTAGEIVPROC oglGetProgramStageiv;

    typedef void(APIENTRYP PFNGLPATCHPARAMETERIPROC)(GLenum_t pname, GLint_t value);
    PFNGLPATCHPARAMETERIPROC oglPatchParameteri;

    typedef void(APIENTRYP PFNGLPATCHPARAMETERFVPROC)(GLenum_t pname, const GLfloat_t* values);
    PFNGLPATCHPARAMETERFVPROC oglPatchParameterfv;

    typedef void(APIENTRYP PFNGLBINDTRANSFORMFEEDBACKPROC)(GLenum_t target, GLuint_t id);
    PFNGLBINDTRANSFORMFEEDBACKPROC oglBindTransformFeedback;

    typedef void(APIENTRYP PFNGLDELETETRANSFORMFEEDBACKSPROC)(GLsizei_t n, const GLuint_t* ids);
    PFNGLDELETETRANSFORMFEEDBACKSPROC oglDeleteTransformFeedbacks;

    typedef void(APIENTRYP PFNGLGENTRANSFORMFEEDBACKSPROC)(GLsizei_t n, GLuint_t* ids);
    PFNGLGENTRANSFORMFEEDBACKSPROC oglGenTransformFeedbacks;

    typedef GLboolean_t(APIENTRYP PFNGLISTRANSFORMFEEDBACKPROC)(GLuint_t id);
    PFNGLISTRANSFORMFEEDBACKPROC oglIsTransformFeedback;

    typedef void(APIENTRYP PFNGLPAUSETRANSFORMFEEDBACKPROC)(void);
    PFNGLPAUSETRANSFORMFEEDBACKPROC oglPauseTransformFeedback;

    typedef void(APIENTRYP PFNGLRESUMETRANSFORMFEEDBACKPROC)(void);
    PFNGLRESUMETRANSFORMFEEDBACKPROC oglResumeTransformFeedback;

    typedef void(APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKPROC)(GLenum_t mode, GLuint_t id);
    PFNGLDRAWTRANSFORMFEEDBACKPROC oglDrawTransformFeedback;

    typedef void(APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)(GLenum_t mode, GLuint_t id, GLuint_t stream);
    PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC oglDrawTransformFeedbackStream;

    typedef void(APIENTRYP PFNGLBEGINQUERYINDEXEDPROC)(GLenum_t target, GLuint_t index, GLuint_t id);
    PFNGLBEGINQUERYINDEXEDPROC oglBeginQueryIndexed;

    typedef void(APIENTRYP PFNGLENDQUERYINDEXEDPROC)(GLenum_t target, GLuint_t index);
    PFNGLENDQUERYINDEXEDPROC oglEndQueryIndexed;

    typedef void(APIENTRYP PFNGLGETQUERYINDEXEDIVPROC)(GLenum_t target, GLuint_t index, GLenum_t pname, GLint_t* params);
    PFNGLGETQUERYINDEXEDIVPROC oglGetQueryIndexediv;

  public:
    GLfuncsv400();

  protected:
    virtual void loadFuncs(Loader loader) override;
};

} // namespace glr
} // namespace xg
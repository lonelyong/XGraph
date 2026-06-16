#pragma once

#include <xg/glr/igl/GLfuncsv400.hpp>

namespace xg {
namespace glr {
class GLR_API GLfuncsv410 : public GLfuncsv400 {

  public:
    typedef void(APIENTRYP PFNGLRELEASESHADERCOMPILERPROC)(void);
    PFNGLRELEASESHADERCOMPILERPROC iglReleaseShaderCompiler;

    typedef void(APIENTRYP PFNGLSHADERBINARYPROC)(GLsizei_t       count,
                                                  const GLuint_t* shaders,
                                                  GLenum_t        binaryFormat,
                                                  const void*   binary,
                                                  GLsizei_t       length);
    PFNGLSHADERBINARYPROC iglShaderBinary;

    typedef void(APIENTRYP PFNGLGETSHADERPRECISIONFORMATPROC)(GLenum_t shadertype,
                                                              GLenum_t precisiontype,
                                                              GLint_t* range,
                                                              GLint_t* precision);
    PFNGLGETSHADERPRECISIONFORMATPROC iglGetShaderPrecisionFormat;

    typedef void(APIENTRYP PFNGLDEPTHRANGEFPROC)(GLfloat_t n, GLfloat_t f);
    PFNGLDEPTHRANGEFPROC iglDepthRangef;

    typedef void(APIENTRYP PFNGLCLEARDEPTHFPROC)(GLfloat_t d);
    PFNGLCLEARDEPTHFPROC iglClearDepthf;

    typedef void(APIENTRYP PFNGLGETPROGRAMBINARYPROC)(GLuint_t   program,
                                                      GLsizei_t  bufSize,
                                                      GLsizei_t* length,
                                                      GLenum_t*  binaryFormat,
                                                      void*    binary);
    PFNGLGETPROGRAMBINARYPROC iglGetProgramBinary;

    typedef void(APIENTRYP PFNGLPROGRAMBINARYPROC)(GLuint_t      program,
                                                   GLenum_t      binaryFormat,
                                                   const void* binary,
                                                   GLsizei_t     length);
    PFNGLPROGRAMBINARYPROC iglProgramBinary;

    typedef void(APIENTRYP PFNGLPROGRAMPARAMETERIPROC)(GLuint_t program, GLenum_t pname, GLint_t value);
    PFNGLPROGRAMPARAMETERIPROC iglProgramParameteri;

    typedef void(APIENTRYP PFNGLUSEPROGRAMSTAGESPROC)(GLuint_t pipeline, GLbitfield_t stages, GLuint_t program);
    PFNGLUSEPROGRAMSTAGESPROC iglUseProgramStages;

    typedef void(APIENTRYP PFNGLACTIVESHADERPROGRAMPROC)(GLuint_t pipeline, GLuint_t program);
    PFNGLACTIVESHADERPROGRAMPROC iglActiveShaderProgram;

    typedef GLuint_t(APIENTRYP PFNGLCREATESHADERPROGRAMVPROC)(GLenum_t type, GLsizei_t count, const GLchar_t* const* strings);
    PFNGLCREATESHADERPROGRAMVPROC iglCreateShaderProgramv;

    typedef void(APIENTRYP PFNGLBINDPROGRAMPIPELINEPROC)(GLuint_t pipeline);
    PFNGLBINDPROGRAMPIPELINEPROC iglBindProgramPipeline;

    typedef void(APIENTRYP PFNGLDELETEPROGRAMPIPELINESPROC)(GLsizei_t n, const GLuint_t* pipelines);
    PFNGLDELETEPROGRAMPIPELINESPROC iglDeleteProgramPipelines;

    typedef void(APIENTRYP PFNGLGENPROGRAMPIPELINESPROC)(GLsizei_t n, GLuint_t* pipelines);
    PFNGLGENPROGRAMPIPELINESPROC iglGenProgramPipelines;

    typedef GLboolean_t(APIENTRYP PFNGLISPROGRAMPIPELINEPROC)(GLuint_t pipeline);
    PFNGLISPROGRAMPIPELINEPROC iglIsProgramPipeline;

    typedef void(APIENTRYP PFNGLGETPROGRAMPIPELINEIVPROC)(GLuint_t pipeline, GLenum_t pname, GLint_t* params);
    PFNGLGETPROGRAMPIPELINEIVPROC iglGetProgramPipelineiv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1IPROC)(GLuint_t program, GLint_t location, GLint_t v0);
    PFNGLPROGRAMUNIFORM1IPROC iglProgramUniform1i;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1IVPROC)(GLuint_t       program,
                                                       GLint_t        location,
                                                       GLsizei_t      count,
                                                       const GLint_t* value);
    PFNGLPROGRAMUNIFORM1IVPROC iglProgramUniform1iv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1FPROC)(GLuint_t program, GLint_t location, GLfloat_t v0);
    PFNGLPROGRAMUNIFORM1FPROC iglProgramUniform1f;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1FVPROC)(GLuint_t         program,
                                                       GLint_t          location,
                                                       GLsizei_t        count,
                                                       const GLfloat_t* value);
    PFNGLPROGRAMUNIFORM1FVPROC iglProgramUniform1fv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1DPROC)(GLuint_t program, GLint_t location, GLdouble_t v0);
    PFNGLPROGRAMUNIFORM1DPROC iglProgramUniform1d;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1DVPROC)(GLuint_t          program,
                                                       GLint_t           location,
                                                       GLsizei_t         count,
                                                       const GLdouble_t* value);
    PFNGLPROGRAMUNIFORM1DVPROC iglProgramUniform1dv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1UIPROC)(GLuint_t program, GLint_t location, GLuint_t v0);
    PFNGLPROGRAMUNIFORM1UIPROC iglProgramUniform1ui;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1UIVPROC)(GLuint_t        program,
                                                        GLint_t         location,
                                                        GLsizei_t       count,
                                                        const GLuint_t* value);
    PFNGLPROGRAMUNIFORM1UIVPROC iglProgramUniform1uiv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2IPROC)(GLuint_t program, GLint_t location, GLint_t v0, GLint_t v1);
    PFNGLPROGRAMUNIFORM2IPROC iglProgramUniform2i;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2IVPROC)(GLuint_t       program,
                                                       GLint_t        location,
                                                       GLsizei_t      count,
                                                       const GLint_t* value);
    PFNGLPROGRAMUNIFORM2IVPROC iglProgramUniform2iv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2FPROC)(GLuint_t program, GLint_t location, GLfloat_t v0, GLfloat_t v1);
    PFNGLPROGRAMUNIFORM2FPROC iglProgramUniform2f;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2FVPROC)(GLuint_t         program,
                                                       GLint_t          location,
                                                       GLsizei_t        count,
                                                       const GLfloat_t* value);
    PFNGLPROGRAMUNIFORM2FVPROC iglProgramUniform2fv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2DPROC)(GLuint_t program, GLint_t location, GLdouble_t v0, GLdouble_t v1);
    PFNGLPROGRAMUNIFORM2DPROC iglProgramUniform2d;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2DVPROC)(GLuint_t          program,
                                                       GLint_t           location,
                                                       GLsizei_t         count,
                                                       const GLdouble_t* value);
    PFNGLPROGRAMUNIFORM2DVPROC iglProgramUniform2dv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2UIPROC)(GLuint_t program, GLint_t location, GLuint_t v0, GLuint_t v1);
    PFNGLPROGRAMUNIFORM2UIPROC iglProgramUniform2ui;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2UIVPROC)(GLuint_t        program,
                                                        GLint_t         location,
                                                        GLsizei_t       count,
                                                        const GLuint_t* value);
    PFNGLPROGRAMUNIFORM2UIVPROC iglProgramUniform2uiv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3IPROC)(GLuint_t program, GLint_t location, GLint_t v0, GLint_t v1, GLint_t v2);
    PFNGLPROGRAMUNIFORM3IPROC iglProgramUniform3i;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3IVPROC)(GLuint_t       program,
                                                       GLint_t        location,
                                                       GLsizei_t      count,
                                                       const GLint_t* value);
    PFNGLPROGRAMUNIFORM3IVPROC iglProgramUniform3iv;

    typedef void(
        APIENTRYP PFNGLPROGRAMUNIFORM3FPROC)(GLuint_t program, GLint_t location, GLfloat_t v0, GLfloat_t v1, GLfloat_t v2);
    PFNGLPROGRAMUNIFORM3FPROC iglProgramUniform3f;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3FVPROC)(GLuint_t         program,
                                                       GLint_t          location,
                                                       GLsizei_t        count,
                                                       const GLfloat_t* value);
    PFNGLPROGRAMUNIFORM3FVPROC iglProgramUniform3fv;

    typedef void(
        APIENTRYP PFNGLPROGRAMUNIFORM3DPROC)(GLuint_t program, GLint_t location, GLdouble_t v0, GLdouble_t v1, GLdouble_t v2);
    PFNGLPROGRAMUNIFORM3DPROC iglProgramUniform3d;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3DVPROC)(GLuint_t          program,
                                                       GLint_t           location,
                                                       GLsizei_t         count,
                                                       const GLdouble_t* value);
    PFNGLPROGRAMUNIFORM3DVPROC iglProgramUniform3dv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3UIPROC)(GLuint_t program, GLint_t location, GLuint_t v0, GLuint_t v1, GLuint_t v2);
    PFNGLPROGRAMUNIFORM3UIPROC iglProgramUniform3ui;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3UIVPROC)(GLuint_t        program,
                                                        GLint_t         location,
                                                        GLsizei_t       count,
                                                        const GLuint_t* value);
    PFNGLPROGRAMUNIFORM3UIVPROC iglProgramUniform3uiv;

    typedef void(
        APIENTRYP PFNGLPROGRAMUNIFORM4IPROC)(GLuint_t program, GLint_t location, GLint_t v0, GLint_t v1, GLint_t v2, GLint_t v3);
    PFNGLPROGRAMUNIFORM4IPROC iglProgramUniform4i;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4IVPROC)(GLuint_t       program,
                                                       GLint_t        location,
                                                       GLsizei_t      count,
                                                       const GLint_t* value);
    PFNGLPROGRAMUNIFORM4IVPROC iglProgramUniform4iv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4FPROC)(GLuint_t  program,
                                                      GLint_t   location,
                                                      GLfloat_t v0,
                                                      GLfloat_t v1,
                                                      GLfloat_t v2,
                                                      GLfloat_t v3);
    PFNGLPROGRAMUNIFORM4FPROC iglProgramUniform4f;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4FVPROC)(GLuint_t         program,
                                                       GLint_t          location,
                                                       GLsizei_t        count,
                                                       const GLfloat_t* value);
    PFNGLPROGRAMUNIFORM4FVPROC iglProgramUniform4fv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4DPROC)(GLuint_t   program,
                                                      GLint_t    location,
                                                      GLdouble_t v0,
                                                      GLdouble_t v1,
                                                      GLdouble_t v2,
                                                      GLdouble_t v3);
    PFNGLPROGRAMUNIFORM4DPROC iglProgramUniform4d;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4DVPROC)(GLuint_t          program,
                                                       GLint_t           location,
                                                       GLsizei_t         count,
                                                       const GLdouble_t* value);
    PFNGLPROGRAMUNIFORM4DVPROC iglProgramUniform4dv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4UIPROC)(GLuint_t program,
                                                       GLint_t  location,
                                                       GLuint_t v0,
                                                       GLuint_t v1,
                                                       GLuint_t v2,
                                                       GLuint_t v3);
    PFNGLPROGRAMUNIFORM4UIPROC iglProgramUniform4ui;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4UIVPROC)(GLuint_t        program,
                                                        GLint_t         location,
                                                        GLsizei_t       count,
                                                        const GLuint_t* value);
    PFNGLPROGRAMUNIFORM4UIVPROC iglProgramUniform4uiv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2FVPROC)(GLuint_t         program,
                                                             GLint_t          location,
                                                             GLsizei_t        count,
                                                             GLboolean_t      transpose,
                                                             const GLfloat_t* value);
    PFNGLPROGRAMUNIFORMMATRIX2FVPROC iglProgramUniformMatrix2fv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3FVPROC)(GLuint_t         program,
                                                             GLint_t          location,
                                                             GLsizei_t        count,
                                                             GLboolean_t      transpose,
                                                             const GLfloat_t* value);
    PFNGLPROGRAMUNIFORMMATRIX3FVPROC iglProgramUniformMatrix3fv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4FVPROC)(GLuint_t         program,
                                                             GLint_t          location,
                                                             GLsizei_t        count,
                                                             GLboolean_t      transpose,
                                                             const GLfloat_t* value);
    PFNGLPROGRAMUNIFORMMATRIX4FVPROC iglProgramUniformMatrix4fv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2DVPROC)(GLuint_t          program,
                                                             GLint_t           location,
                                                             GLsizei_t         count,
                                                             GLboolean_t       transpose,
                                                             const GLdouble_t* value);
    PFNGLPROGRAMUNIFORMMATRIX2DVPROC iglProgramUniformMatrix2dv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3DVPROC)(GLuint_t          program,
                                                             GLint_t           location,
                                                             GLsizei_t         count,
                                                             GLboolean_t       transpose,
                                                             const GLdouble_t* value);
    PFNGLPROGRAMUNIFORMMATRIX3DVPROC iglProgramUniformMatrix3dv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4DVPROC)(GLuint_t          program,
                                                             GLint_t           location,
                                                             GLsizei_t         count,
                                                             GLboolean_t       transpose,
                                                             const GLdouble_t* value);
    PFNGLPROGRAMUNIFORMMATRIX4DVPROC iglProgramUniformMatrix4dv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)(GLuint_t         program,
                                                               GLint_t          location,
                                                               GLsizei_t        count,
                                                               GLboolean_t      transpose,
                                                               const GLfloat_t* value);
    PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC iglProgramUniformMatrix2x3fv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)(GLuint_t         program,
                                                               GLint_t          location,
                                                               GLsizei_t        count,
                                                               GLboolean_t      transpose,
                                                               const GLfloat_t* value);
    PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC iglProgramUniformMatrix3x2fv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)(GLuint_t         program,
                                                               GLint_t          location,
                                                               GLsizei_t        count,
                                                               GLboolean_t      transpose,
                                                               const GLfloat_t* value);
    PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC iglProgramUniformMatrix2x4fv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)(GLuint_t         program,
                                                               GLint_t          location,
                                                               GLsizei_t        count,
                                                               GLboolean_t      transpose,
                                                               const GLfloat_t* value);
    PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC iglProgramUniformMatrix4x2fv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)(GLuint_t         program,
                                                               GLint_t          location,
                                                               GLsizei_t        count,
                                                               GLboolean_t      transpose,
                                                               const GLfloat_t* value);
    PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC iglProgramUniformMatrix3x4fv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)(GLuint_t         program,
                                                               GLint_t          location,
                                                               GLsizei_t        count,
                                                               GLboolean_t      transpose,
                                                               const GLfloat_t* value);
    PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC iglProgramUniformMatrix4x3fv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)(GLuint_t          program,
                                                               GLint_t           location,
                                                               GLsizei_t         count,
                                                               GLboolean_t       transpose,
                                                               const GLdouble_t* value);
    PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC iglProgramUniformMatrix2x3dv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)(GLuint_t          program,
                                                               GLint_t           location,
                                                               GLsizei_t         count,
                                                               GLboolean_t       transpose,
                                                               const GLdouble_t* value);
    PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC iglProgramUniformMatrix3x2dv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)(GLuint_t          program,
                                                               GLint_t           location,
                                                               GLsizei_t         count,
                                                               GLboolean_t       transpose,
                                                               const GLdouble_t* value);
    PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC iglProgramUniformMatrix2x4dv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)(GLuint_t          program,
                                                               GLint_t           location,
                                                               GLsizei_t         count,
                                                               GLboolean_t       transpose,
                                                               const GLdouble_t* value);
    PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC iglProgramUniformMatrix4x2dv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)(GLuint_t          program,
                                                               GLint_t           location,
                                                               GLsizei_t         count,
                                                               GLboolean_t       transpose,
                                                               const GLdouble_t* value);
    PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC iglProgramUniformMatrix3x4dv;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)(GLuint_t          program,
                                                               GLint_t           location,
                                                               GLsizei_t         count,
                                                               GLboolean_t       transpose,
                                                               const GLdouble_t* value);
    PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC iglProgramUniformMatrix4x3dv;

    typedef void(APIENTRYP PFNGLVALIDATEPROGRAMPIPELINEPROC)(GLuint_t pipeline);
    PFNGLVALIDATEPROGRAMPIPELINEPROC iglValidateProgramPipeline;

    typedef void(APIENTRYP PFNGLGETPROGRAMPIPELINEINFOLOGPROC)(GLuint_t   pipeline,
                                                               GLsizei_t  bufSize,
                                                               GLsizei_t* length,
                                                               GLchar_t*  infoLog);
    PFNGLGETPROGRAMPIPELINEINFOLOGPROC iglGetProgramPipelineInfoLog;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBL1DPROC)(GLuint_t index, GLdouble_t x);
    PFNGLVERTEXATTRIBL1DPROC iglVertexAttribL1d;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBL2DPROC)(GLuint_t index, GLdouble_t x, GLdouble_t y);
    PFNGLVERTEXATTRIBL2DPROC iglVertexAttribL2d;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBL3DPROC)(GLuint_t index, GLdouble_t x, GLdouble_t y, GLdouble_t z);
    PFNGLVERTEXATTRIBL3DPROC iglVertexAttribL3d;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBL4DPROC)(GLuint_t index, GLdouble_t x, GLdouble_t y, GLdouble_t z, GLdouble_t w);
    PFNGLVERTEXATTRIBL4DPROC iglVertexAttribL4d;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBL1DVPROC)(GLuint_t index, const GLdouble_t* v);
    PFNGLVERTEXATTRIBL1DVPROC iglVertexAttribL1dv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBL2DVPROC)(GLuint_t index, const GLdouble_t* v);
    PFNGLVERTEXATTRIBL2DVPROC iglVertexAttribL2dv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBL3DVPROC)(GLuint_t index, const GLdouble_t* v);
    PFNGLVERTEXATTRIBL3DVPROC iglVertexAttribL3dv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBL4DVPROC)(GLuint_t index, const GLdouble_t* v);
    PFNGLVERTEXATTRIBL4DVPROC iglVertexAttribL4dv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBLPOINTERPROC)(GLuint_t      index,
                                                          GLint_t       size,
                                                          GLenum_t      type,
                                                          GLsizei_t     stride,
                                                          const void* pointer);
    PFNGLVERTEXATTRIBLPOINTERPROC iglVertexAttribLPointer;

    typedef void(APIENTRYP PFNGLGETVERTEXATTRIBLDVPROC)(GLuint_t index, GLenum_t pname, GLdouble_t* params);
    PFNGLGETVERTEXATTRIBLDVPROC iglGetVertexAttribLdv;

    typedef void(APIENTRYP PFNGLVIEWPORTARRAYVPROC)(GLuint_t first, GLsizei_t count, const GLfloat_t* v);
    PFNGLVIEWPORTARRAYVPROC iglViewportArrayv;

    typedef void(APIENTRYP PFNGLVIEWPORTINDEXEDFPROC)(GLuint_t index, GLfloat_t x, GLfloat_t y, GLfloat_t w, GLfloat_t h);
    PFNGLVIEWPORTINDEXEDFPROC iglViewportIndexedf;

    typedef void(APIENTRYP PFNGLVIEWPORTINDEXEDFVPROC)(GLuint_t index, const GLfloat_t* v);
    PFNGLVIEWPORTINDEXEDFVPROC iglViewportIndexedfv;

    typedef void(APIENTRYP PFNGLSCISSORARRAYVPROC)(GLuint_t first, GLsizei_t count, const GLint_t* v);
    PFNGLSCISSORARRAYVPROC iglScissorArrayv;

    typedef void(
        APIENTRYP PFNGLSCISSORINDEXEDPROC)(GLuint_t index, GLint_t left, GLint_t bottom, GLsizei_t width, GLsizei_t height);
    PFNGLSCISSORINDEXEDPROC iglScissorIndexed;

    typedef void(APIENTRYP PFNGLSCISSORINDEXEDVPROC)(GLuint_t index, const GLint_t* v);
    PFNGLSCISSORINDEXEDVPROC iglScissorIndexedv;

    typedef void(APIENTRYP PFNGLDEPTHRANGEARRAYVPROC)(GLuint_t first, GLsizei_t count, const GLdouble_t* v);
    PFNGLDEPTHRANGEARRAYVPROC iglDepthRangeArrayv;

    typedef void(APIENTRYP PFNGLDEPTHRANGEINDEXEDPROC)(GLuint_t index, GLdouble_t n, GLdouble_t f);
    PFNGLDEPTHRANGEINDEXEDPROC iglDepthRangeIndexed;

    typedef void(APIENTRYP PFNGLGETFLOATI_VPROC)(GLenum_t target, GLuint_t index, GLfloat_t* data);
    PFNGLGETFLOATI_VPROC iglGetFloati_v;

    typedef void(APIENTRYP PFNGLGETDOUBLEI_VPROC)(GLenum_t target, GLuint_t index, GLdouble_t* data);
    PFNGLGETDOUBLEI_VPROC iglGetDoublei_v;

  public:
    GLfuncsv410();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
} // namespace xg
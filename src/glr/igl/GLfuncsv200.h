#pragma once

#include <glr/igl/GLfuncsv150.h>

namespace glr {
class GLR_API GLfuncsv200 : public GLfuncsv150 {

  public:
    using GLshort  = GLshort_t;
    using GLushort = GLushort_t;
    using GLbyte   = GLbyte_t;

  public:
    typedef void(APIENTRYP PFNGLBLENDEQUATIONSEPARATEPROC)(GLenum_t modeRGB, GLenum_t modeAlpha);
    PFNGLBLENDEQUATIONSEPARATEPROC iglBlendEquationSeparate;

    typedef void(APIENTRYP PFNGLDRAWBUFFERSPROC)(GLsizei_t n, const GLenum_t* bufs);
    PFNGLDRAWBUFFERSPROC iglDrawBuffers;

    typedef void(APIENTRYP PFNGLSTENCILOPSEPARATEPROC)(GLenum_t face, GLenum_t sfail, GLenum_t dpfail, GLenum_t dppass);
    PFNGLSTENCILOPSEPARATEPROC iglStencilOpSeparate;

    typedef void(APIENTRYP PFNGLSTENCILFUNCSEPARATEPROC)(GLenum_t face, GLenum_t func, GLint_t ref, GLuint_t mask);
    PFNGLSTENCILFUNCSEPARATEPROC iglStencilFuncSeparate;

    typedef void(APIENTRYP PFNGLSTENCILMASKSEPARATEPROC)(GLenum_t face, GLuint_t mask);
    PFNGLSTENCILMASKSEPARATEPROC iglStencilMaskSeparate;

    typedef void(APIENTRYP PFNGLATTACHSHADERPROC)(GLuint_t program, GLuint_t shader);
    PFNGLATTACHSHADERPROC iglAttachShader;

    typedef void(APIENTRYP PFNGLBINDATTRIBLOCATIONPROC)(GLuint_t program, GLuint_t index, const GLchar_t* name);
    PFNGLBINDATTRIBLOCATIONPROC iglBindAttribLocation;

    typedef void(APIENTRYP PFNGLCOMPILESHADERPROC)(GLuint_t shader);
    PFNGLCOMPILESHADERPROC iglCompileShader;

    typedef GLuint_t(APIENTRYP PFNGLCREATEPROGRAMPROC)(void);
    PFNGLCREATEPROGRAMPROC iglCreateProgram;

    typedef GLuint_t(APIENTRYP PFNGLCREATESHADERPROC)(GLenum_t type);
    PFNGLCREATESHADERPROC iglCreateShader;

    typedef void(APIENTRYP PFNGLDELETEPROGRAMPROC)(GLuint_t program);
    PFNGLDELETEPROGRAMPROC iglDeleteProgram;

    typedef void(APIENTRYP PFNGLDELETESHADERPROC)(GLuint_t shader);
    PFNGLDELETESHADERPROC iglDeleteShader;

    typedef void(APIENTRYP PFNGLDETACHSHADERPROC)(GLuint_t program, GLuint_t shader);
    PFNGLDETACHSHADERPROC iglDetachShader;

    typedef void(APIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYPROC)(GLuint_t index);
    PFNGLDISABLEVERTEXATTRIBARRAYPROC iglDisableVertexAttribArray;

    typedef void(APIENTRYP PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint_t index);
    PFNGLENABLEVERTEXATTRIBARRAYPROC iglEnableVertexAttribArray;

    typedef void(APIENTRYP PFNGLGETACTIVEATTRIBPROC)(GLuint_t   program,
                                                     GLuint_t   index,
                                                     GLsizei_t  bufSize,
                                                     GLsizei_t* length,
                                                     GLint_t*   size,
                                                     GLenum_t*  type,
                                                     GLchar_t*  name);
    PFNGLGETACTIVEATTRIBPROC iglGetActiveAttrib;

    typedef void(APIENTRYP PFNGLGETACTIVEUNIFORMPROC)(GLuint_t   program,
                                                      GLuint_t   index,
                                                      GLsizei_t  bufSize,
                                                      GLsizei_t* length,
                                                      GLint_t*   size,
                                                      GLenum_t*  type,
                                                      GLchar_t*  name);
    PFNGLGETACTIVEUNIFORMPROC iglGetActiveUniform;

    typedef void(APIENTRYP PFNGLGETATTACHEDSHADERSPROC)(GLuint_t   program,
                                                        GLsizei_t  maxCount,
                                                        GLsizei_t* count,
                                                        GLuint_t*  shaders);
    PFNGLGETATTACHEDSHADERSPROC iglGetAttachedShaders;

    typedef GLint_t(APIENTRYP PFNGLGETATTRIBLOCATIONPROC)(GLuint_t program, const GLchar_t* name);
    PFNGLGETATTRIBLOCATIONPROC iglGetAttribLocation;

    typedef void(APIENTRYP PFNGLGETPROGRAMIVPROC)(GLuint_t program, GLenum_t pname, GLint_t* params);
    PFNGLGETPROGRAMIVPROC iglGetProgramiv;

    typedef void(APIENTRYP PFNGLGETPROGRAMINFOLOGPROC)(GLuint_t   program,
                                                       GLsizei_t  bufSize,
                                                       GLsizei_t* length,
                                                       GLchar_t*  infoLog);
    PFNGLGETPROGRAMINFOLOGPROC iglGetProgramInfoLog;

    typedef void(APIENTRYP PFNGLGETSHADERIVPROC)(GLuint_t shader, GLenum_t pname, GLint_t* params);
    PFNGLGETSHADERIVPROC iglGetShaderiv;

    typedef void(APIENTRYP PFNGLGETSHADERINFOLOGPROC)(GLuint_t shader, GLsizei_t bufSize, GLsizei_t* length, GLchar_t* infoLog);
    PFNGLGETSHADERINFOLOGPROC iglGetShaderInfoLog;

    typedef void(APIENTRYP PFNGLGETSHADERSOURCEPROC)(GLuint_t shader, GLsizei_t bufSize, GLsizei_t* length, GLchar_t* source);
    PFNGLGETSHADERSOURCEPROC iglGetShaderSource;

    typedef GLint_t(APIENTRYP PFNGLGETUNIFORMLOCATIONPROC)(GLuint_t program, const GLchar_t* name);
    PFNGLGETUNIFORMLOCATIONPROC iglGetUniformLocation;

    typedef void(APIENTRYP PFNGLGETUNIFORMFVPROC)(GLuint_t program, GLint_t location, GLfloat_t* params);
    PFNGLGETUNIFORMFVPROC iglGetUniformfv;

    typedef void(APIENTRYP PFNGLGETUNIFORMIVPROC)(GLuint_t program, GLint_t location, GLint_t* params);
    PFNGLGETUNIFORMIVPROC iglGetUniformiv;

    typedef void(APIENTRYP PFNGLGETVERTEXATTRIBDVPROC)(GLuint_t index, GLenum_t pname, GLdouble_t* params);
    PFNGLGETVERTEXATTRIBDVPROC iglGetVertexAttribdv;

    typedef void(APIENTRYP PFNGLGETVERTEXATTRIBFVPROC)(GLuint_t index, GLenum_t pname, GLfloat_t* params);
    PFNGLGETVERTEXATTRIBFVPROC iglGetVertexAttribfv;

    typedef void(APIENTRYP PFNGLGETVERTEXATTRIBIVPROC)(GLuint_t index, GLenum_t pname, GLint_t* params);
    PFNGLGETVERTEXATTRIBIVPROC iglGetVertexAttribiv;

    typedef void(APIENTRYP PFNGLGETVERTEXATTRIBPOINTERVPROC)(GLuint_t index, GLenum_t pname, void** pointer);
    PFNGLGETVERTEXATTRIBPOINTERVPROC iglGetVertexAttribPointerv;

    typedef GLboolean_t(APIENTRYP PFNGLISPROGRAMPROC)(GLuint_t program);
    PFNGLISPROGRAMPROC iglIsProgram;

    typedef GLboolean_t(APIENTRYP PFNGLISSHADERPROC)(GLuint_t shader);
    PFNGLISSHADERPROC iglIsShader;

    typedef void(APIENTRYP PFNGLLINKPROGRAMPROC)(GLuint_t program);
    PFNGLLINKPROGRAMPROC iglLinkProgram;

    typedef void(APIENTRYP PFNGLSHADERSOURCEPROC)(GLuint_t               shader,
                                                  GLsizei_t              count,
                                                  const GLchar_t* const* string,
                                                  const GLint_t*         length);
    PFNGLSHADERSOURCEPROC iglShaderSource;

    typedef void(APIENTRYP PFNGLUSEPROGRAMPROC)(GLuint_t program);
    PFNGLUSEPROGRAMPROC iglUseProgram;

    typedef void(APIENTRYP PFNGLUNIFORM1FPROC)(GLint_t location, GLfloat_t v0);
    PFNGLUNIFORM1FPROC iglUniform1f;

    typedef void(APIENTRYP PFNGLUNIFORM2FPROC)(GLint_t location, GLfloat_t v0, GLfloat_t v1);
    PFNGLUNIFORM2FPROC iglUniform2f;

    typedef void(APIENTRYP PFNGLUNIFORM3FPROC)(GLint_t location, GLfloat_t v0, GLfloat_t v1, GLfloat_t v2);
    PFNGLUNIFORM3FPROC iglUniform3f;

    typedef void(APIENTRYP PFNGLUNIFORM4FPROC)(GLint_t location, GLfloat_t v0, GLfloat_t v1, GLfloat_t v2, GLfloat_t v3);
    PFNGLUNIFORM4FPROC iglUniform4f;

    typedef void(APIENTRYP PFNGLUNIFORM1IPROC)(GLint_t location, GLint_t v0);
    PFNGLUNIFORM1IPROC iglUniform1i;

    typedef void(APIENTRYP PFNGLUNIFORM2IPROC)(GLint_t location, GLint_t v0, GLint_t v1);
    PFNGLUNIFORM2IPROC iglUniform2i;

    typedef void(APIENTRYP PFNGLUNIFORM3IPROC)(GLint_t location, GLint_t v0, GLint_t v1, GLint_t v2);
    PFNGLUNIFORM3IPROC iglUniform3i;

    typedef void(APIENTRYP PFNGLUNIFORM4IPROC)(GLint_t location, GLint_t v0, GLint_t v1, GLint_t v2, GLint_t v3);
    PFNGLUNIFORM4IPROC iglUniform4i;

    typedef void(APIENTRYP PFNGLUNIFORM1FVPROC)(GLint_t location, GLsizei_t count, const GLfloat_t* value);
    PFNGLUNIFORM1FVPROC iglUniform1fv;

    typedef void(APIENTRYP PFNGLUNIFORM2FVPROC)(GLint_t location, GLsizei_t count, const GLfloat_t* value);
    PFNGLUNIFORM2FVPROC iglUniform2fv;

    typedef void(APIENTRYP PFNGLUNIFORM3FVPROC)(GLint_t location, GLsizei_t count, const GLfloat_t* value);
    PFNGLUNIFORM3FVPROC iglUniform3fv;

    typedef void(APIENTRYP PFNGLUNIFORM4FVPROC)(GLint_t location, GLsizei_t count, const GLfloat_t* value);
    PFNGLUNIFORM4FVPROC iglUniform4fv;

    typedef void(APIENTRYP PFNGLUNIFORM1IVPROC)(GLint_t location, GLsizei_t count, const GLint_t* value);
    PFNGLUNIFORM1IVPROC iglUniform1iv;

    typedef void(APIENTRYP PFNGLUNIFORM2IVPROC)(GLint_t location, GLsizei_t count, const GLint_t* value);
    PFNGLUNIFORM2IVPROC iglUniform2iv;

    typedef void(APIENTRYP PFNGLUNIFORM3IVPROC)(GLint_t location, GLsizei_t count, const GLint_t* value);
    PFNGLUNIFORM3IVPROC iglUniform3iv;

    typedef void(APIENTRYP PFNGLUNIFORM4IVPROC)(GLint_t location, GLsizei_t count, const GLint_t* value);
    PFNGLUNIFORM4IVPROC iglUniform4iv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX2FVPROC)(GLint_t          location,
                                                      GLsizei_t        count,
                                                      GLboolean_t      transpose,
                                                      const GLfloat_t* value);
    PFNGLUNIFORMMATRIX2FVPROC iglUniformMatrix2fv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX3FVPROC)(GLint_t          location,
                                                      GLsizei_t        count,
                                                      GLboolean_t      transpose,
                                                      const GLfloat_t* value);
    PFNGLUNIFORMMATRIX3FVPROC iglUniformMatrix3fv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX4FVPROC)(GLint_t          location,
                                                      GLsizei_t        count,
                                                      GLboolean_t      transpose,
                                                      const GLfloat_t* value);
    PFNGLUNIFORMMATRIX4FVPROC iglUniformMatrix4fv;

    typedef void(APIENTRYP PFNGLVALIDATEPROGRAMPROC)(GLuint_t program);
    PFNGLVALIDATEPROGRAMPROC iglValidateProgram;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB1DPROC)(GLuint_t index, GLdouble_t x);
    PFNGLVERTEXATTRIB1DPROC iglVertexAttrib1d;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB1DVPROC)(GLuint_t index, const GLdouble_t* v);
    PFNGLVERTEXATTRIB1DVPROC iglVertexAttrib1dv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB1FPROC)(GLuint_t index, GLfloat_t x);
    PFNGLVERTEXATTRIB1FPROC iglVertexAttrib1f;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB1FVPROC)(GLuint_t index, const GLfloat_t* v);
    PFNGLVERTEXATTRIB1FVPROC iglVertexAttrib1fv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB1SPROC)(GLuint_t index, GLshort x);
    PFNGLVERTEXATTRIB1SPROC iglVertexAttrib1s;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB1SVPROC)(GLuint_t index, const GLshort* v);
    PFNGLVERTEXATTRIB1SVPROC iglVertexAttrib1sv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB2DPROC)(GLuint_t index, GLdouble_t x, GLdouble_t y);
    PFNGLVERTEXATTRIB2DPROC iglVertexAttrib2d;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB2DVPROC)(GLuint_t index, const GLdouble_t* v);
    PFNGLVERTEXATTRIB2DVPROC iglVertexAttrib2dv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB2FPROC)(GLuint_t index, GLfloat_t x, GLfloat_t y);
    PFNGLVERTEXATTRIB2FPROC iglVertexAttrib2f;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB2FVPROC)(GLuint_t index, const GLfloat_t* v);
    PFNGLVERTEXATTRIB2FVPROC iglVertexAttrib2fv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB2SPROC)(GLuint_t index, GLshort x, GLshort y);
    PFNGLVERTEXATTRIB2SPROC iglVertexAttrib2s;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB2SVPROC)(GLuint_t index, const GLshort* v);
    PFNGLVERTEXATTRIB2SVPROC iglVertexAttrib2sv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB3DPROC)(GLuint_t index, GLdouble_t x, GLdouble_t y, GLdouble_t z);
    PFNGLVERTEXATTRIB3DPROC iglVertexAttrib3d;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB3DVPROC)(GLuint_t index, const GLdouble_t* v);
    PFNGLVERTEXATTRIB3DVPROC iglVertexAttrib3dv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB3FPROC)(GLuint_t index, GLfloat_t x, GLfloat_t y, GLfloat_t z);
    PFNGLVERTEXATTRIB3FPROC iglVertexAttrib3f;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB3FVPROC)(GLuint_t index, const GLfloat_t* v);
    PFNGLVERTEXATTRIB3FVPROC iglVertexAttrib3fv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB3SPROC)(GLuint_t index, GLshort x, GLshort y, GLshort z);
    PFNGLVERTEXATTRIB3SPROC iglVertexAttrib3s;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB3SVPROC)(GLuint_t index, const GLshort* v);
    PFNGLVERTEXATTRIB3SVPROC iglVertexAttrib3sv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4NBVPROC)(GLuint_t index, const GLbyte* v);
    PFNGLVERTEXATTRIB4NBVPROC iglVertexAttrib4Nbv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4NIVPROC)(GLuint_t index, const GLint_t* v);
    PFNGLVERTEXATTRIB4NIVPROC iglVertexAttrib4Niv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4NSVPROC)(GLuint_t index, const GLshort* v);
    PFNGLVERTEXATTRIB4NSVPROC iglVertexAttrib4Nsv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4NUBPROC)(GLuint_t index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
    PFNGLVERTEXATTRIB4NUBPROC iglVertexAttrib4Nub;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4NUBVPROC)(GLuint_t index, const GLubyte* v);
    PFNGLVERTEXATTRIB4NUBVPROC iglVertexAttrib4Nubv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4NUIVPROC)(GLuint_t index, const GLuint_t* v);
    PFNGLVERTEXATTRIB4NUIVPROC iglVertexAttrib4Nuiv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4NUSVPROC)(GLuint_t index, const GLushort* v);
    PFNGLVERTEXATTRIB4NUSVPROC iglVertexAttrib4Nusv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4BVPROC)(GLuint_t index, const GLbyte* v);
    PFNGLVERTEXATTRIB4BVPROC iglVertexAttrib4bv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4DPROC)(GLuint_t index, GLdouble_t x, GLdouble_t y, GLdouble_t z, GLdouble_t w);
    PFNGLVERTEXATTRIB4DPROC iglVertexAttrib4d;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4DVPROC)(GLuint_t index, const GLdouble_t* v);
    PFNGLVERTEXATTRIB4DVPROC iglVertexAttrib4dv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4FPROC)(GLuint_t index, GLfloat_t x, GLfloat_t y, GLfloat_t z, GLfloat_t w);
    PFNGLVERTEXATTRIB4FPROC iglVertexAttrib4f;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4FVPROC)(GLuint_t index, const GLfloat_t* v);
    PFNGLVERTEXATTRIB4FVPROC iglVertexAttrib4fv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4IVPROC)(GLuint_t index, const GLint_t* v);
    PFNGLVERTEXATTRIB4IVPROC iglVertexAttrib4iv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4SPROC)(GLuint_t index, GLshort x, GLshort y, GLshort z, GLshort w);
    PFNGLVERTEXATTRIB4SPROC iglVertexAttrib4s;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4SVPROC)(GLuint_t index, const GLshort* v);
    PFNGLVERTEXATTRIB4SVPROC iglVertexAttrib4sv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4UBVPROC)(GLuint_t index, const GLubyte* v);
    PFNGLVERTEXATTRIB4UBVPROC iglVertexAttrib4ubv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4UIVPROC)(GLuint_t index, const GLuint_t* v);
    PFNGLVERTEXATTRIB4UIVPROC iglVertexAttrib4uiv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4USVPROC)(GLuint_t index, const GLushort* v);
    PFNGLVERTEXATTRIB4USVPROC iglVertexAttrib4usv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBPOINTERPROC)(GLuint_t      index,
                                                         GLint_t       size,
                                                         GLenum_t      type,
                                                         GLboolean_t   normalized,
                                                         GLsizei_t     stride,
                                                         const void* pointer);
    PFNGLVERTEXATTRIBPOINTERPROC iglVertexAttribPointer;

  public:
    GLfuncsv200();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
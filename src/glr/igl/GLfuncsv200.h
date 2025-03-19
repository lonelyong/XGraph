#pragma once

#include <glr/igl/GLfuncsv150.h>

namespace glr {
class GLR_API GLfuncsv200 : public GLfuncsv150 {
  public:
    using GLshort  = GLshort_t;
    using GLushort = GLushort_t;
    using GLbyte   = GLbyte_t;

  public:
    typedef void(APIENTRYP PFNGLBLENDEQUATIONSEPARATEPROC)(GLenum modeRGB, GLenum modeAlpha);
    PFNGLBLENDEQUATIONSEPARATEPROC glad_glBlendEquationSeparate;

    typedef void(APIENTRYP PFNGLDRAWBUFFERSPROC)(GLsizei n, const GLenum* bufs);
    PFNGLDRAWBUFFERSPROC glad_glDrawBuffers;

    typedef void(APIENTRYP PFNGLSTENCILOPSEPARATEPROC)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
    PFNGLSTENCILOPSEPARATEPROC glad_glStencilOpSeparate;

    typedef void(APIENTRYP PFNGLSTENCILFUNCSEPARATEPROC)(GLenum face, GLenum func, GLint ref, GLuint mask);
    PFNGLSTENCILFUNCSEPARATEPROC glad_glStencilFuncSeparate;

    typedef void(APIENTRYP PFNGLSTENCILMASKSEPARATEPROC)(GLenum face, GLuint mask);
    PFNGLSTENCILMASKSEPARATEPROC glad_glStencilMaskSeparate;

    typedef void(APIENTRYP PFNGLATTACHSHADERPROC)(GLuint program, GLuint shader);
    PFNGLATTACHSHADERPROC glad_glAttachShader;

    typedef void(APIENTRYP PFNGLBINDATTRIBLOCATIONPROC)(GLuint program, GLuint index, const GLchar* name);
    PFNGLBINDATTRIBLOCATIONPROC glad_glBindAttribLocation;

    typedef void(APIENTRYP PFNGLCOMPILESHADERPROC)(GLuint shader);
    PFNGLCOMPILESHADERPROC glad_glCompileShader;

    typedef GLuint(APIENTRYP PFNGLCREATEPROGRAMPROC)(void);
    PFNGLCREATEPROGRAMPROC glad_glCreateProgram;

    typedef GLuint(APIENTRYP PFNGLCREATESHADERPROC)(GLenum type);
    PFNGLCREATESHADERPROC glad_glCreateShader;

    typedef void(APIENTRYP PFNGLDELETEPROGRAMPROC)(GLuint program);
    PFNGLDELETEPROGRAMPROC glad_glDeleteProgram;

    typedef void(APIENTRYP PFNGLDELETESHADERPROC)(GLuint shader);
    PFNGLDELETESHADERPROC glad_glDeleteShader;

    typedef void(APIENTRYP PFNGLDETACHSHADERPROC)(GLuint program, GLuint shader);
    PFNGLDETACHSHADERPROC glad_glDetachShader;

    typedef void(APIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYPROC)(GLuint index);
    PFNGLDISABLEVERTEXATTRIBARRAYPROC glad_glDisableVertexAttribArray;

    typedef void(APIENTRYP PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint index);
    PFNGLENABLEVERTEXATTRIBARRAYPROC glad_glEnableVertexAttribArray;

    typedef void(APIENTRYP PFNGLGETACTIVEATTRIBPROC)(GLuint   program,
                                                     GLuint   index,
                                                     GLsizei  bufSize,
                                                     GLsizei* length,
                                                     GLint*   size,
                                                     GLenum*  type,
                                                     GLchar*  name);
    PFNGLGETACTIVEATTRIBPROC glad_glGetActiveAttrib;

    typedef void(APIENTRYP PFNGLGETACTIVEUNIFORMPROC)(GLuint   program,
                                                      GLuint   index,
                                                      GLsizei  bufSize,
                                                      GLsizei* length,
                                                      GLint*   size,
                                                      GLenum*  type,
                                                      GLchar*  name);
    PFNGLGETACTIVEUNIFORMPROC glad_glGetActiveUniform;

    typedef void(APIENTRYP PFNGLGETATTACHEDSHADERSPROC)(GLuint   program,
                                                        GLsizei  maxCount,
                                                        GLsizei* count,
                                                        GLuint*  shaders);
    PFNGLGETATTACHEDSHADERSPROC glad_glGetAttachedShaders;

    typedef GLint(APIENTRYP PFNGLGETATTRIBLOCATIONPROC)(GLuint program, const GLchar* name);
    PFNGLGETATTRIBLOCATIONPROC glad_glGetAttribLocation;

    typedef void(APIENTRYP PFNGLGETPROGRAMIVPROC)(GLuint program, GLenum pname, GLint* params);
    PFNGLGETPROGRAMIVPROC glad_glGetProgramiv;

    typedef void(APIENTRYP PFNGLGETPROGRAMINFOLOGPROC)(GLuint   program,
                                                       GLsizei  bufSize,
                                                       GLsizei* length,
                                                       GLchar*  infoLog);
    PFNGLGETPROGRAMINFOLOGPROC glad_glGetProgramInfoLog;

    typedef void(APIENTRYP PFNGLGETSHADERIVPROC)(GLuint shader, GLenum pname, GLint* params);
    PFNGLGETSHADERIVPROC glad_glGetShaderiv;

    typedef void(APIENTRYP PFNGLGETSHADERINFOLOGPROC)(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
    PFNGLGETSHADERINFOLOGPROC glad_glGetShaderInfoLog;

    typedef void(APIENTRYP PFNGLGETSHADERSOURCEPROC)(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source);
    PFNGLGETSHADERSOURCEPROC glad_glGetShaderSource;

    typedef GLint(APIENTRYP PFNGLGETUNIFORMLOCATIONPROC)(GLuint program, const GLchar* name);
    PFNGLGETUNIFORMLOCATIONPROC glad_glGetUniformLocation;

    typedef void(APIENTRYP PFNGLGETUNIFORMFVPROC)(GLuint program, GLint location, GLfloat* params);
    PFNGLGETUNIFORMFVPROC glad_glGetUniformfv;

    typedef void(APIENTRYP PFNGLGETUNIFORMIVPROC)(GLuint program, GLint location, GLint* params);
    PFNGLGETUNIFORMIVPROC glad_glGetUniformiv;

    typedef void(APIENTRYP PFNGLGETVERTEXATTRIBDVPROC)(GLuint index, GLenum pname, GLdouble* params);
    PFNGLGETVERTEXATTRIBDVPROC glad_glGetVertexAttribdv;

    typedef void(APIENTRYP PFNGLGETVERTEXATTRIBFVPROC)(GLuint index, GLenum pname, GLfloat* params);
    PFNGLGETVERTEXATTRIBFVPROC glad_glGetVertexAttribfv;

    typedef void(APIENTRYP PFNGLGETVERTEXATTRIBIVPROC)(GLuint index, GLenum pname, GLint* params);
    PFNGLGETVERTEXATTRIBIVPROC glad_glGetVertexAttribiv;

    typedef void(APIENTRYP PFNGLGETVERTEXATTRIBPOINTERVPROC)(GLuint index, GLenum pname, void** pointer);
    PFNGLGETVERTEXATTRIBPOINTERVPROC glad_glGetVertexAttribPointerv;

    typedef GLboolean(APIENTRYP PFNGLISPROGRAMPROC)(GLuint program);
    PFNGLISPROGRAMPROC glad_glIsProgram;

    typedef GLboolean(APIENTRYP PFNGLISSHADERPROC)(GLuint shader);
    PFNGLISSHADERPROC glad_glIsShader;

    typedef void(APIENTRYP PFNGLLINKPROGRAMPROC)(GLuint program);
    PFNGLLINKPROGRAMPROC glad_glLinkProgram;

    typedef void(APIENTRYP PFNGLSHADERSOURCEPROC)(GLuint               shader,
                                                  GLsizei              count,
                                                  const GLchar* const* string,
                                                  const GLint*         length);
    PFNGLSHADERSOURCEPROC glad_glShaderSource;

    typedef void(APIENTRYP PFNGLUSEPROGRAMPROC)(GLuint program);
    PFNGLUSEPROGRAMPROC glad_glUseProgram;

    typedef void(APIENTRYP PFNGLUNIFORM1FPROC)(GLint location, GLfloat v0);
    PFNGLUNIFORM1FPROC glad_glUniform1f;

    typedef void(APIENTRYP PFNGLUNIFORM2FPROC)(GLint location, GLfloat v0, GLfloat v1);
    PFNGLUNIFORM2FPROC glad_glUniform2f;

    typedef void(APIENTRYP PFNGLUNIFORM3FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
    PFNGLUNIFORM3FPROC glad_glUniform3f;

    typedef void(APIENTRYP PFNGLUNIFORM4FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
    PFNGLUNIFORM4FPROC glad_glUniform4f;

    typedef void(APIENTRYP PFNGLUNIFORM1IPROC)(GLint location, GLint v0);
    PFNGLUNIFORM1IPROC glad_glUniform1i;

    typedef void(APIENTRYP PFNGLUNIFORM2IPROC)(GLint location, GLint v0, GLint v1);
    PFNGLUNIFORM2IPROC glad_glUniform2i;

    typedef void(APIENTRYP PFNGLUNIFORM3IPROC)(GLint location, GLint v0, GLint v1, GLint v2);
    PFNGLUNIFORM3IPROC glad_glUniform3i;

    typedef void(APIENTRYP PFNGLUNIFORM4IPROC)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
    PFNGLUNIFORM4IPROC glad_glUniform4i;

    typedef void(APIENTRYP PFNGLUNIFORM1FVPROC)(GLint location, GLsizei count, const GLfloat* value);
    PFNGLUNIFORM1FVPROC glad_glUniform1fv;

    typedef void(APIENTRYP PFNGLUNIFORM2FVPROC)(GLint location, GLsizei count, const GLfloat* value);
    PFNGLUNIFORM2FVPROC glad_glUniform2fv;

    typedef void(APIENTRYP PFNGLUNIFORM3FVPROC)(GLint location, GLsizei count, const GLfloat* value);
    PFNGLUNIFORM3FVPROC glad_glUniform3fv;

    typedef void(APIENTRYP PFNGLUNIFORM4FVPROC)(GLint location, GLsizei count, const GLfloat* value);
    PFNGLUNIFORM4FVPROC glad_glUniform4fv;

    typedef void(APIENTRYP PFNGLUNIFORM1IVPROC)(GLint location, GLsizei count, const GLint* value);
    PFNGLUNIFORM1IVPROC glad_glUniform1iv;

    typedef void(APIENTRYP PFNGLUNIFORM2IVPROC)(GLint location, GLsizei count, const GLint* value);
    PFNGLUNIFORM2IVPROC glad_glUniform2iv;

    typedef void(APIENTRYP PFNGLUNIFORM3IVPROC)(GLint location, GLsizei count, const GLint* value);
    PFNGLUNIFORM3IVPROC glad_glUniform3iv;

    typedef void(APIENTRYP PFNGLUNIFORM4IVPROC)(GLint location, GLsizei count, const GLint* value);
    PFNGLUNIFORM4IVPROC glad_glUniform4iv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX2FVPROC)(GLint          location,
                                                      GLsizei        count,
                                                      GLboolean      transpose,
                                                      const GLfloat* value);
    PFNGLUNIFORMMATRIX2FVPROC glad_glUniformMatrix2fv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX3FVPROC)(GLint          location,
                                                      GLsizei        count,
                                                      GLboolean      transpose,
                                                      const GLfloat* value);
    PFNGLUNIFORMMATRIX3FVPROC glad_glUniformMatrix3fv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX4FVPROC)(GLint          location,
                                                      GLsizei        count,
                                                      GLboolean      transpose,
                                                      const GLfloat* value);
    PFNGLUNIFORMMATRIX4FVPROC glad_glUniformMatrix4fv;

    typedef void(APIENTRYP PFNGLVALIDATEPROGRAMPROC)(GLuint program);
    PFNGLVALIDATEPROGRAMPROC glad_glValidateProgram;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB1DPROC)(GLuint index, GLdouble x);
    PFNGLVERTEXATTRIB1DPROC glad_glVertexAttrib1d;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB1DVPROC)(GLuint index, const GLdouble* v);
    PFNGLVERTEXATTRIB1DVPROC glad_glVertexAttrib1dv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB1FPROC)(GLuint index, GLfloat x);
    PFNGLVERTEXATTRIB1FPROC glad_glVertexAttrib1f;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB1FVPROC)(GLuint index, const GLfloat* v);
    PFNGLVERTEXATTRIB1FVPROC glad_glVertexAttrib1fv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB1SPROC)(GLuint index, GLshort x);
    PFNGLVERTEXATTRIB1SPROC glad_glVertexAttrib1s;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB1SVPROC)(GLuint index, const GLshort* v);
    PFNGLVERTEXATTRIB1SVPROC glad_glVertexAttrib1sv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB2DPROC)(GLuint index, GLdouble x, GLdouble y);
    PFNGLVERTEXATTRIB2DPROC glad_glVertexAttrib2d;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB2DVPROC)(GLuint index, const GLdouble* v);
    PFNGLVERTEXATTRIB2DVPROC glad_glVertexAttrib2dv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB2FPROC)(GLuint index, GLfloat x, GLfloat y);
    PFNGLVERTEXATTRIB2FPROC glad_glVertexAttrib2f;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB2FVPROC)(GLuint index, const GLfloat* v);
    PFNGLVERTEXATTRIB2FVPROC glad_glVertexAttrib2fv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB2SPROC)(GLuint index, GLshort x, GLshort y);
    PFNGLVERTEXATTRIB2SPROC glad_glVertexAttrib2s;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB2SVPROC)(GLuint index, const GLshort* v);
    PFNGLVERTEXATTRIB2SVPROC glad_glVertexAttrib2sv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB3DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
    PFNGLVERTEXATTRIB3DPROC glad_glVertexAttrib3d;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB3DVPROC)(GLuint index, const GLdouble* v);
    PFNGLVERTEXATTRIB3DVPROC glad_glVertexAttrib3dv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB3FPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
    PFNGLVERTEXATTRIB3FPROC glad_glVertexAttrib3f;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB3FVPROC)(GLuint index, const GLfloat* v);
    PFNGLVERTEXATTRIB3FVPROC glad_glVertexAttrib3fv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB3SPROC)(GLuint index, GLshort x, GLshort y, GLshort z);
    PFNGLVERTEXATTRIB3SPROC glad_glVertexAttrib3s;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB3SVPROC)(GLuint index, const GLshort* v);
    PFNGLVERTEXATTRIB3SVPROC glad_glVertexAttrib3sv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4NBVPROC)(GLuint index, const GLbyte* v);
    PFNGLVERTEXATTRIB4NBVPROC glad_glVertexAttrib4Nbv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4NIVPROC)(GLuint index, const GLint* v);
    PFNGLVERTEXATTRIB4NIVPROC glad_glVertexAttrib4Niv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4NSVPROC)(GLuint index, const GLshort* v);
    PFNGLVERTEXATTRIB4NSVPROC glad_glVertexAttrib4Nsv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4NUBPROC)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
    PFNGLVERTEXATTRIB4NUBPROC glad_glVertexAttrib4Nub;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4NUBVPROC)(GLuint index, const GLubyte* v);
    PFNGLVERTEXATTRIB4NUBVPROC glad_glVertexAttrib4Nubv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4NUIVPROC)(GLuint index, const GLuint* v);
    PFNGLVERTEXATTRIB4NUIVPROC glad_glVertexAttrib4Nuiv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4NUSVPROC)(GLuint index, const GLushort* v);
    PFNGLVERTEXATTRIB4NUSVPROC glad_glVertexAttrib4Nusv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4BVPROC)(GLuint index, const GLbyte* v);
    PFNGLVERTEXATTRIB4BVPROC glad_glVertexAttrib4bv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    PFNGLVERTEXATTRIB4DPROC glad_glVertexAttrib4d;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4DVPROC)(GLuint index, const GLdouble* v);
    PFNGLVERTEXATTRIB4DVPROC glad_glVertexAttrib4dv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4FPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    PFNGLVERTEXATTRIB4FPROC glad_glVertexAttrib4f;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4FVPROC)(GLuint index, const GLfloat* v);
    PFNGLVERTEXATTRIB4FVPROC glad_glVertexAttrib4fv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4IVPROC)(GLuint index, const GLint* v);
    PFNGLVERTEXATTRIB4IVPROC glad_glVertexAttrib4iv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4SPROC)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
    PFNGLVERTEXATTRIB4SPROC glad_glVertexAttrib4s;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4SVPROC)(GLuint index, const GLshort* v);
    PFNGLVERTEXATTRIB4SVPROC glad_glVertexAttrib4sv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4UBVPROC)(GLuint index, const GLubyte* v);
    PFNGLVERTEXATTRIB4UBVPROC glad_glVertexAttrib4ubv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4UIVPROC)(GLuint index, const GLuint* v);
    PFNGLVERTEXATTRIB4UIVPROC glad_glVertexAttrib4uiv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4USVPROC)(GLuint index, const GLushort* v);
    PFNGLVERTEXATTRIB4USVPROC glad_glVertexAttrib4usv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBPOINTERPROC)(GLuint      index,
                                                         GLint       size,
                                                         GLenum      type,
                                                         GLboolean   normalized,
                                                         GLsizei     stride,
                                                         const void* pointer);
    PFNGLVERTEXATTRIBPOINTERPROC glad_glVertexAttribPointer;

  public:
    GLfuncsv200();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
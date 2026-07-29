#pragma once

#include <xg/igl/ogl/GLfuncsv150.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API GLfuncsv200 : public GLfuncsv150 {

  public:
    using GLshort  = GLshort_t;
    using GLushort = GLushort_t;
    using GLbyte   = GLbyte_t;

  public:
    typedef void(APIENTRYP PFNGLBLENDEQUATIONSEPARATEPROC)(GLenum_t modeRGB, GLenum_t modeAlpha);
    PFNGLBLENDEQUATIONSEPARATEPROC oglBlendEquationSeparate;

    typedef void(APIENTRYP PFNGLDRAWBUFFERSPROC)(GLsizei_t n, const GLenum_t* bufs);
    PFNGLDRAWBUFFERSPROC oglDrawBuffers;

    typedef void(APIENTRYP PFNGLSTENCILOPSEPARATEPROC)(GLenum_t face, GLenum_t sfail, GLenum_t dpfail, GLenum_t dppass);
    PFNGLSTENCILOPSEPARATEPROC oglStencilOpSeparate;

    typedef void(APIENTRYP PFNGLSTENCILFUNCSEPARATEPROC)(GLenum_t face, GLenum_t func, GLint_t ref, GLuint_t mask);
    PFNGLSTENCILFUNCSEPARATEPROC oglStencilFuncSeparate;

    typedef void(APIENTRYP PFNGLSTENCILMASKSEPARATEPROC)(GLenum_t face, GLuint_t mask);
    PFNGLSTENCILMASKSEPARATEPROC oglStencilMaskSeparate;

    typedef void(APIENTRYP PFNGLATTACHSHADERPROC)(GLuint_t program, GLuint_t shader);
    PFNGLATTACHSHADERPROC oglAttachShader;

    typedef void(APIENTRYP PFNGLBINDATTRIBLOCATIONPROC)(GLuint_t program, GLuint_t index, const GLchar_t* name);
    PFNGLBINDATTRIBLOCATIONPROC oglBindAttribLocation;

    typedef void(APIENTRYP PFNGLCOMPILESHADERPROC)(GLuint_t shader);
    PFNGLCOMPILESHADERPROC oglCompileShader;

    typedef GLuint_t(APIENTRYP PFNGLCREATEPROGRAMPROC)(void);
    PFNGLCREATEPROGRAMPROC oglCreateProgram;

    typedef GLuint_t(APIENTRYP PFNGLCREATESHADERPROC)(GLenum_t type);
    PFNGLCREATESHADERPROC oglCreateShader;

    typedef void(APIENTRYP PFNGLDELETEPROGRAMPROC)(GLuint_t program);
    PFNGLDELETEPROGRAMPROC oglDeleteProgram;

    typedef void(APIENTRYP PFNGLDELETESHADERPROC)(GLuint_t shader);
    PFNGLDELETESHADERPROC oglDeleteShader;

    typedef void(APIENTRYP PFNGLDETACHSHADERPROC)(GLuint_t program, GLuint_t shader);
    PFNGLDETACHSHADERPROC oglDetachShader;

    typedef void(APIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYPROC)(GLuint_t index);
    PFNGLDISABLEVERTEXATTRIBARRAYPROC oglDisableVertexAttribArray;

    typedef void(APIENTRYP PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint_t index);
    PFNGLENABLEVERTEXATTRIBARRAYPROC oglEnableVertexAttribArray;

    typedef void(APIENTRYP PFNGLGETACTIVEATTRIBPROC)(GLuint_t   program,
                                                     GLuint_t   index,
                                                     GLsizei_t  bufSize,
                                                     GLsizei_t* length,
                                                     GLint_t*   size,
                                                     GLenum_t*  type,
                                                     GLchar_t*  name);
    PFNGLGETACTIVEATTRIBPROC oglGetActiveAttrib;

    typedef void(APIENTRYP PFNGLGETACTIVEUNIFORMPROC)(GLuint_t   program,
                                                      GLuint_t   index,
                                                      GLsizei_t  bufSize,
                                                      GLsizei_t* length,
                                                      GLint_t*   size,
                                                      GLenum_t*  type,
                                                      GLchar_t*  name);
    PFNGLGETACTIVEUNIFORMPROC oglGetActiveUniform;

    typedef void(APIENTRYP PFNGLGETATTACHEDSHADERSPROC)(GLuint_t program, GLsizei_t maxCount, GLsizei_t* count, GLuint_t* shaders);
    PFNGLGETATTACHEDSHADERSPROC oglGetAttachedShaders;

    typedef GLint_t(APIENTRYP PFNGLGETATTRIBLOCATIONPROC)(GLuint_t program, const GLchar_t* name);
    PFNGLGETATTRIBLOCATIONPROC oglGetAttribLocation;

    typedef void(APIENTRYP PFNGLGETPROGRAMIVPROC)(GLuint_t program, GLenum_t pname, GLint_t* params);
    PFNGLGETPROGRAMIVPROC oglGetProgramiv;

    typedef void(APIENTRYP PFNGLGETPROGRAMINFOLOGPROC)(GLuint_t program, GLsizei_t bufSize, GLsizei_t* length, GLchar_t* infoLog);
    PFNGLGETPROGRAMINFOLOGPROC oglGetProgramInfoLog;

    typedef void(APIENTRYP PFNGLGETSHADERIVPROC)(GLuint_t shader, GLenum_t pname, GLint_t* params);
    PFNGLGETSHADERIVPROC oglGetShaderiv;

    typedef void(APIENTRYP PFNGLGETSHADERINFOLOGPROC)(GLuint_t shader, GLsizei_t bufSize, GLsizei_t* length, GLchar_t* infoLog);
    PFNGLGETSHADERINFOLOGPROC oglGetShaderInfoLog;

    typedef void(APIENTRYP PFNGLGETSHADERSOURCEPROC)(GLuint_t shader, GLsizei_t bufSize, GLsizei_t* length, GLchar_t* source);
    PFNGLGETSHADERSOURCEPROC oglGetShaderSource;

    typedef GLint_t(APIENTRYP PFNGLGETUNIFORMLOCATIONPROC)(GLuint_t program, const GLchar_t* name);
    PFNGLGETUNIFORMLOCATIONPROC oglGetUniformLocation;

    typedef void(APIENTRYP PFNGLGETUNIFORMFVPROC)(GLuint_t program, GLint_t location, GLfloat_t* params);
    PFNGLGETUNIFORMFVPROC oglGetUniformfv;

    typedef void(APIENTRYP PFNGLGETUNIFORMIVPROC)(GLuint_t program, GLint_t location, GLint_t* params);
    PFNGLGETUNIFORMIVPROC oglGetUniformiv;

    typedef void(APIENTRYP PFNGLGETVERTEXATTRIBDVPROC)(GLuint_t index, GLenum_t pname, GLdouble_t* params);
    PFNGLGETVERTEXATTRIBDVPROC oglGetVertexAttribdv;

    typedef void(APIENTRYP PFNGLGETVERTEXATTRIBFVPROC)(GLuint_t index, GLenum_t pname, GLfloat_t* params);
    PFNGLGETVERTEXATTRIBFVPROC oglGetVertexAttribfv;

    typedef void(APIENTRYP PFNGLGETVERTEXATTRIBIVPROC)(GLuint_t index, GLenum_t pname, GLint_t* params);
    PFNGLGETVERTEXATTRIBIVPROC oglGetVertexAttribiv;

    typedef void(APIENTRYP PFNGLGETVERTEXATTRIBPOINTERVPROC)(GLuint_t index, GLenum_t pname, void** pointer);
    PFNGLGETVERTEXATTRIBPOINTERVPROC oglGetVertexAttribPointerv;

    typedef GLboolean_t(APIENTRYP PFNGLISPROGRAMPROC)(GLuint_t program);
    PFNGLISPROGRAMPROC oglIsProgram;

    typedef GLboolean_t(APIENTRYP PFNGLISSHADERPROC)(GLuint_t shader);
    PFNGLISSHADERPROC oglIsShader;

    typedef void(APIENTRYP PFNGLLINKPROGRAMPROC)(GLuint_t program);
    PFNGLLINKPROGRAMPROC oglLinkProgram;

    typedef void(APIENTRYP PFNGLSHADERSOURCEPROC)(GLuint_t shader, GLsizei_t count, const GLchar_t* const* string, const GLint_t* length);
    PFNGLSHADERSOURCEPROC oglShaderSource;

    typedef void(APIENTRYP PFNGLUSEPROGRAMPROC)(GLuint_t program);
    PFNGLUSEPROGRAMPROC oglUseProgram;

    typedef void(APIENTRYP PFNGLUNIFORM1FPROC)(GLint_t location, GLfloat_t v0);
    PFNGLUNIFORM1FPROC oglUniform1f;

    typedef void(APIENTRYP PFNGLUNIFORM2FPROC)(GLint_t location, GLfloat_t v0, GLfloat_t v1);
    PFNGLUNIFORM2FPROC oglUniform2f;

    typedef void(APIENTRYP PFNGLUNIFORM3FPROC)(GLint_t location, GLfloat_t v0, GLfloat_t v1, GLfloat_t v2);
    PFNGLUNIFORM3FPROC oglUniform3f;

    typedef void(APIENTRYP PFNGLUNIFORM4FPROC)(GLint_t location, GLfloat_t v0, GLfloat_t v1, GLfloat_t v2, GLfloat_t v3);
    PFNGLUNIFORM4FPROC oglUniform4f;

    typedef void(APIENTRYP PFNGLUNIFORM1IPROC)(GLint_t location, GLint_t v0);
    PFNGLUNIFORM1IPROC oglUniform1i;

    typedef void(APIENTRYP PFNGLUNIFORM2IPROC)(GLint_t location, GLint_t v0, GLint_t v1);
    PFNGLUNIFORM2IPROC oglUniform2i;

    typedef void(APIENTRYP PFNGLUNIFORM3IPROC)(GLint_t location, GLint_t v0, GLint_t v1, GLint_t v2);
    PFNGLUNIFORM3IPROC oglUniform3i;

    typedef void(APIENTRYP PFNGLUNIFORM4IPROC)(GLint_t location, GLint_t v0, GLint_t v1, GLint_t v2, GLint_t v3);
    PFNGLUNIFORM4IPROC oglUniform4i;

    typedef void(APIENTRYP PFNGLUNIFORM1FVPROC)(GLint_t location, GLsizei_t count, const GLfloat_t* value);
    PFNGLUNIFORM1FVPROC oglUniform1fv;

    typedef void(APIENTRYP PFNGLUNIFORM2FVPROC)(GLint_t location, GLsizei_t count, const GLfloat_t* value);
    PFNGLUNIFORM2FVPROC oglUniform2fv;

    typedef void(APIENTRYP PFNGLUNIFORM3FVPROC)(GLint_t location, GLsizei_t count, const GLfloat_t* value);
    PFNGLUNIFORM3FVPROC oglUniform3fv;

    typedef void(APIENTRYP PFNGLUNIFORM4FVPROC)(GLint_t location, GLsizei_t count, const GLfloat_t* value);
    PFNGLUNIFORM4FVPROC oglUniform4fv;

    typedef void(APIENTRYP PFNGLUNIFORM1IVPROC)(GLint_t location, GLsizei_t count, const GLint_t* value);
    PFNGLUNIFORM1IVPROC oglUniform1iv;

    typedef void(APIENTRYP PFNGLUNIFORM2IVPROC)(GLint_t location, GLsizei_t count, const GLint_t* value);
    PFNGLUNIFORM2IVPROC oglUniform2iv;

    typedef void(APIENTRYP PFNGLUNIFORM3IVPROC)(GLint_t location, GLsizei_t count, const GLint_t* value);
    PFNGLUNIFORM3IVPROC oglUniform3iv;

    typedef void(APIENTRYP PFNGLUNIFORM4IVPROC)(GLint_t location, GLsizei_t count, const GLint_t* value);
    PFNGLUNIFORM4IVPROC oglUniform4iv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX2FVPROC)(GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLfloat_t* value);
    PFNGLUNIFORMMATRIX2FVPROC oglUniformMatrix2fv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX3FVPROC)(GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLfloat_t* value);
    PFNGLUNIFORMMATRIX3FVPROC oglUniformMatrix3fv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX4FVPROC)(GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLfloat_t* value);
    PFNGLUNIFORMMATRIX4FVPROC oglUniformMatrix4fv;

    typedef void(APIENTRYP PFNGLVALIDATEPROGRAMPROC)(GLuint_t program);
    PFNGLVALIDATEPROGRAMPROC oglValidateProgram;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB1DPROC)(GLuint_t index, GLdouble_t x);
    PFNGLVERTEXATTRIB1DPROC oglVertexAttrib1d;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB1DVPROC)(GLuint_t index, const GLdouble_t* v);
    PFNGLVERTEXATTRIB1DVPROC oglVertexAttrib1dv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB1FPROC)(GLuint_t index, GLfloat_t x);
    PFNGLVERTEXATTRIB1FPROC oglVertexAttrib1f;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB1FVPROC)(GLuint_t index, const GLfloat_t* v);
    PFNGLVERTEXATTRIB1FVPROC oglVertexAttrib1fv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB1SPROC)(GLuint_t index, GLshort x);
    PFNGLVERTEXATTRIB1SPROC oglVertexAttrib1s;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB1SVPROC)(GLuint_t index, const GLshort* v);
    PFNGLVERTEXATTRIB1SVPROC oglVertexAttrib1sv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB2DPROC)(GLuint_t index, GLdouble_t x, GLdouble_t y);
    PFNGLVERTEXATTRIB2DPROC oglVertexAttrib2d;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB2DVPROC)(GLuint_t index, const GLdouble_t* v);
    PFNGLVERTEXATTRIB2DVPROC oglVertexAttrib2dv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB2FPROC)(GLuint_t index, GLfloat_t x, GLfloat_t y);
    PFNGLVERTEXATTRIB2FPROC oglVertexAttrib2f;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB2FVPROC)(GLuint_t index, const GLfloat_t* v);
    PFNGLVERTEXATTRIB2FVPROC oglVertexAttrib2fv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB2SPROC)(GLuint_t index, GLshort x, GLshort y);
    PFNGLVERTEXATTRIB2SPROC oglVertexAttrib2s;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB2SVPROC)(GLuint_t index, const GLshort* v);
    PFNGLVERTEXATTRIB2SVPROC oglVertexAttrib2sv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB3DPROC)(GLuint_t index, GLdouble_t x, GLdouble_t y, GLdouble_t z);
    PFNGLVERTEXATTRIB3DPROC oglVertexAttrib3d;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB3DVPROC)(GLuint_t index, const GLdouble_t* v);
    PFNGLVERTEXATTRIB3DVPROC oglVertexAttrib3dv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB3FPROC)(GLuint_t index, GLfloat_t x, GLfloat_t y, GLfloat_t z);
    PFNGLVERTEXATTRIB3FPROC oglVertexAttrib3f;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB3FVPROC)(GLuint_t index, const GLfloat_t* v);
    PFNGLVERTEXATTRIB3FVPROC oglVertexAttrib3fv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB3SPROC)(GLuint_t index, GLshort x, GLshort y, GLshort z);
    PFNGLVERTEXATTRIB3SPROC oglVertexAttrib3s;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB3SVPROC)(GLuint_t index, const GLshort* v);
    PFNGLVERTEXATTRIB3SVPROC oglVertexAttrib3sv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4NBVPROC)(GLuint_t index, const GLbyte* v);
    PFNGLVERTEXATTRIB4NBVPROC oglVertexAttrib4Nbv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4NIVPROC)(GLuint_t index, const GLint_t* v);
    PFNGLVERTEXATTRIB4NIVPROC oglVertexAttrib4Niv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4NSVPROC)(GLuint_t index, const GLshort* v);
    PFNGLVERTEXATTRIB4NSVPROC oglVertexAttrib4Nsv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4NUBPROC)(GLuint_t index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
    PFNGLVERTEXATTRIB4NUBPROC oglVertexAttrib4Nub;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4NUBVPROC)(GLuint_t index, const GLubyte* v);
    PFNGLVERTEXATTRIB4NUBVPROC oglVertexAttrib4Nubv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4NUIVPROC)(GLuint_t index, const GLuint_t* v);
    PFNGLVERTEXATTRIB4NUIVPROC oglVertexAttrib4Nuiv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4NUSVPROC)(GLuint_t index, const GLushort* v);
    PFNGLVERTEXATTRIB4NUSVPROC oglVertexAttrib4Nusv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4BVPROC)(GLuint_t index, const GLbyte* v);
    PFNGLVERTEXATTRIB4BVPROC oglVertexAttrib4bv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4DPROC)(GLuint_t index, GLdouble_t x, GLdouble_t y, GLdouble_t z, GLdouble_t w);
    PFNGLVERTEXATTRIB4DPROC oglVertexAttrib4d;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4DVPROC)(GLuint_t index, const GLdouble_t* v);
    PFNGLVERTEXATTRIB4DVPROC oglVertexAttrib4dv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4FPROC)(GLuint_t index, GLfloat_t x, GLfloat_t y, GLfloat_t z, GLfloat_t w);
    PFNGLVERTEXATTRIB4FPROC oglVertexAttrib4f;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4FVPROC)(GLuint_t index, const GLfloat_t* v);
    PFNGLVERTEXATTRIB4FVPROC oglVertexAttrib4fv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4IVPROC)(GLuint_t index, const GLint_t* v);
    PFNGLVERTEXATTRIB4IVPROC oglVertexAttrib4iv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4SPROC)(GLuint_t index, GLshort x, GLshort y, GLshort z, GLshort w);
    PFNGLVERTEXATTRIB4SPROC oglVertexAttrib4s;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4SVPROC)(GLuint_t index, const GLshort* v);
    PFNGLVERTEXATTRIB4SVPROC oglVertexAttrib4sv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4UBVPROC)(GLuint_t index, const GLubyte* v);
    PFNGLVERTEXATTRIB4UBVPROC oglVertexAttrib4ubv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4UIVPROC)(GLuint_t index, const GLuint_t* v);
    PFNGLVERTEXATTRIB4UIVPROC oglVertexAttrib4uiv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIB4USVPROC)(GLuint_t index, const GLushort* v);
    PFNGLVERTEXATTRIB4USVPROC oglVertexAttrib4usv;

    typedef void(
        APIENTRYP PFNGLVERTEXATTRIBPOINTERPROC)(GLuint_t index, GLint_t size, GLenum_t type, GLboolean_t normalized, GLsizei_t stride, const void* pointer);
    PFNGLVERTEXATTRIBPOINTERPROC oglVertexAttribPointer;

  public:
    GLfuncsv200();

  protected:
    virtual void loadFuncs(Loader loader) override;
};

} // namespace glr
} // namespace xg
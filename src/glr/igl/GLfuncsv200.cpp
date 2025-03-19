#include <glr/igl/GLfuncsv200.h>

namespace glr {
GLfuncsv200::GLfuncsv200()
  : glad_glAttachShader(nullptr)
  , glad_glBindAttribLocation(nullptr)
  , glad_glBlendEquationSeparate(nullptr)
  , glad_glCompileShader(nullptr)
  , glad_glCreateProgram(nullptr)
  , glad_glCreateShader(nullptr)
  , glad_glDeleteProgram(nullptr)
  , glad_glDeleteShader(nullptr)
  , glad_glDetachShader(nullptr)
  , glad_glDisableVertexAttribArray(nullptr)
  , glad_glDrawBuffers(nullptr)
  , glad_glEnableVertexAttribArray(nullptr)
  , glad_glGetActiveAttrib(nullptr)
  , glad_glGetActiveUniform(nullptr)
  , glad_glGetAttachedShaders(nullptr)
  , glad_glGetAttribLocation(nullptr)
  , glad_glGetProgramInfoLog(nullptr)
  , glad_glGetProgramiv(nullptr)
  , glad_glGetShaderInfoLog(nullptr)
  , glad_glGetShaderSource(nullptr)
  , glad_glGetShaderiv(nullptr)
  , glad_glGetUniformLocation(nullptr)
  , glad_glGetUniformfv(nullptr)
  , glad_glGetUniformiv(nullptr)
  , glad_glGetVertexAttribPointerv(nullptr)
  , glad_glGetVertexAttribdv(nullptr)
  , glad_glGetVertexAttribfv(nullptr)
  , glad_glGetVertexAttribiv(nullptr)
  , glad_glIsProgram(nullptr)
  , glad_glIsShader(nullptr)
  , glad_glLinkProgram(nullptr)
  , glad_glShaderSource(nullptr)
  , glad_glStencilFuncSeparate(nullptr)
  , glad_glStencilMaskSeparate(nullptr)
  , glad_glStencilOpSeparate(nullptr)
  , glad_glUniform1fv(nullptr)
  , glad_glUniform1f(nullptr)
  , glad_glUniform1iv(nullptr)
  , glad_glUniform1i(nullptr)
  , glad_glUniform2fv(nullptr)
  , glad_glUniform2f(nullptr)
  , glad_glUniform2iv(nullptr)
  , glad_glUniform2i(nullptr)
  , glad_glUniform3fv(nullptr)
  , glad_glUniform3f(nullptr)
  , glad_glUniform3iv(nullptr)
  , glad_glUniform3i(nullptr)
  , glad_glUniform4fv(nullptr)
  , glad_glUniform4f(nullptr)
  , glad_glUniform4iv(nullptr)
  , glad_glUniform4i(nullptr)
  , glad_glUniformMatrix2fv(nullptr)
  , glad_glUniformMatrix3fv(nullptr)
  , glad_glUniformMatrix4fv(nullptr)
  , glad_glUseProgram(nullptr)
  , glad_glValidateProgram(nullptr)
  , glad_glVertexAttrib1dv(nullptr)
  , glad_glVertexAttrib1d(nullptr)
  , glad_glVertexAttrib1fv(nullptr)
  , glad_glVertexAttrib1f(nullptr)
  , glad_glVertexAttrib1sv(nullptr)
  , glad_glVertexAttrib1s(nullptr)
  , glad_glVertexAttrib2dv(nullptr)
  , glad_glVertexAttrib2d(nullptr)
  , glad_glVertexAttrib2fv(nullptr)
  , glad_glVertexAttrib2f(nullptr)
  , glad_glVertexAttrib2sv(nullptr)
  , glad_glVertexAttrib2s(nullptr)
  , glad_glVertexAttrib3dv(nullptr)
  , glad_glVertexAttrib3d(nullptr)
  , glad_glVertexAttrib3fv(nullptr)
  , glad_glVertexAttrib3f(nullptr)
  , glad_glVertexAttrib3sv(nullptr)
  , glad_glVertexAttrib3s(nullptr)
  , glad_glVertexAttrib4Nbv(nullptr)
  , glad_glVertexAttrib4Niv(nullptr)
  , glad_glVertexAttrib4Nsv(nullptr)
  , glad_glVertexAttrib4Nubv(nullptr)
  , glad_glVertexAttrib4Nub(nullptr)
  , glad_glVertexAttrib4Nuiv(nullptr)
  , glad_glVertexAttrib4Nusv(nullptr)
  , glad_glVertexAttrib4bv(nullptr)
  , glad_glVertexAttrib4dv(nullptr)
  , glad_glVertexAttrib4d(nullptr)
  , glad_glVertexAttrib4fv(nullptr)
  , glad_glVertexAttrib4f(nullptr)
  , glad_glVertexAttrib4iv(nullptr)
  , glad_glVertexAttrib4sv(nullptr)
  , glad_glVertexAttrib4s(nullptr)
  , glad_glVertexAttrib4ubv(nullptr)
  , glad_glVertexAttrib4uiv(nullptr)
  , glad_glVertexAttrib4usv(nullptr)
  , glad_glVertexAttribPointer(nullptr) {
}

void GLfuncsv200::loadFuncs(Loader loader) {
    GLfuncsv150::loadFuncs(loader);
    glad_glAttachShader          = reinterpret_cast<PFNGLATTACHSHADERPROC>(loader("glAttachShader"));
    glad_glBindAttribLocation    = reinterpret_cast<PFNGLBINDATTRIBLOCATIONPROC>(loader("glBindAttribLocation"));
    glad_glBlendEquationSeparate = reinterpret_cast<PFNGLBLENDEQUATIONSEPARATEPROC>(loader("glBlendEquationSeparate"));
    glad_glCompileShader         = reinterpret_cast<PFNGLCOMPILESHADERPROC>(loader("glCompileShader"));
    glad_glCreateProgram         = reinterpret_cast<PFNGLCREATEPROGRAMPROC>(loader("glCreateProgram"));
    glad_glCreateShader          = reinterpret_cast<PFNGLCREATESHADERPROC>(loader("glCreateShader"));
    glad_glDeleteProgram         = reinterpret_cast<PFNGLDELETEPROGRAMPROC>(loader("glDeleteProgram"));
    glad_glDeleteShader          = reinterpret_cast<PFNGLDELETESHADERPROC>(loader("glDeleteShader"));
    glad_glDetachShader          = reinterpret_cast<PFNGLDETACHSHADERPROC>(loader("glDetachShader"));
    glad_glDisableVertexAttribArray =
        reinterpret_cast<PFNGLDISABLEVERTEXATTRIBARRAYPROC>(loader("glDisableVertexAttribArray"));
    glad_glDrawBuffers = reinterpret_cast<PFNGLDRAWBUFFERSPROC>(loader("glDrawBuffers"));
    glad_glEnableVertexAttribArray =
        reinterpret_cast<PFNGLENABLEVERTEXATTRIBARRAYPROC>(loader("glEnableVertexAttribArray"));
    glad_glGetActiveAttrib    = reinterpret_cast<PFNGLGETACTIVEATTRIBPROC>(loader("glGetActiveAttrib"));
    glad_glGetActiveUniform   = reinterpret_cast<PFNGLGETACTIVEUNIFORMPROC>(loader("glGetActiveUniform"));
    glad_glGetAttachedShaders = reinterpret_cast<PFNGLGETATTACHEDSHADERSPROC>(loader("glGetAttachedShaders"));
    glad_glGetAttribLocation  = reinterpret_cast<PFNGLGETATTRIBLOCATIONPROC>(loader("glGetAttribLocation"));
    glad_glGetProgramInfoLog  = reinterpret_cast<PFNGLGETPROGRAMINFOLOGPROC>(loader("glGetProgramInfoLog"));
    glad_glGetProgramiv       = reinterpret_cast<PFNGLGETPROGRAMIVPROC>(loader("glGetProgramiv"));
    glad_glGetShaderInfoLog   = reinterpret_cast<PFNGLGETSHADERINFOLOGPROC>(loader("glGetShaderInfoLog"));
    glad_glGetShaderSource    = reinterpret_cast<PFNGLGETSHADERSOURCEPROC>(loader("glGetShaderSource"));
    glad_glGetShaderiv        = reinterpret_cast<PFNGLGETSHADERIVPROC>(loader("glGetShaderiv"));
    glad_glGetUniformLocation = reinterpret_cast<PFNGLGETUNIFORMLOCATIONPROC>(loader("glGetUniformLocation"));
    glad_glGetUniformfv       = reinterpret_cast<PFNGLGETUNIFORMFVPROC>(loader("glGetUniformfv"));
    glad_glGetUniformiv       = reinterpret_cast<PFNGLGETUNIFORMIVPROC>(loader("glGetUniformiv"));
    glad_glGetVertexAttribPointerv =
        reinterpret_cast<PFNGLGETVERTEXATTRIBPOINTERVPROC>(loader("glGetVertexAttribPointerv"));
    glad_glGetVertexAttribdv   = reinterpret_cast<PFNGLGETVERTEXATTRIBDVPROC>(loader("glGetVertexAttribdv"));
    glad_glGetVertexAttribfv   = reinterpret_cast<PFNGLGETVERTEXATTRIBFVPROC>(loader("glGetVertexAttribfv"));
    glad_glGetVertexAttribiv   = reinterpret_cast<PFNGLGETVERTEXATTRIBIVPROC>(loader("glGetVertexAttribiv"));
    glad_glIsProgram           = reinterpret_cast<PFNGLISPROGRAMPROC>(loader("glIsProgram"));
    glad_glIsShader            = reinterpret_cast<PFNGLISSHADERPROC>(loader("glIsShader"));
    glad_glLinkProgram         = reinterpret_cast<PFNGLLINKPROGRAMPROC>(loader("glLinkProgram"));
    glad_glShaderSource        = reinterpret_cast<PFNGLSHADERSOURCEPROC>(loader("glShaderSource"));
    glad_glStencilFuncSeparate = reinterpret_cast<PFNGLSTENCILFUNCSEPARATEPROC>(loader("glStencilFuncSeparate"));
    glad_glStencilMaskSeparate = reinterpret_cast<PFNGLSTENCILMASKSEPARATEPROC>(loader("glStencilMaskSeparate"));
    glad_glStencilOpSeparate   = reinterpret_cast<PFNGLSTENCILOPSEPARATEPROC>(loader("glStencilOpSeparate"));
    glad_glUniform1fv          = reinterpret_cast<PFNGLUNIFORM1FVPROC>(loader("glUniform1fv"));
    glad_glUniform1f           = reinterpret_cast<PFNGLUNIFORM1FPROC>(loader("glUniform1f"));
    glad_glUniform1iv          = reinterpret_cast<PFNGLUNIFORM1IVPROC>(loader("glUniform1iv"));
    glad_glUniform1i           = reinterpret_cast<PFNGLUNIFORM1IPROC>(loader("glUniform1i"));
    glad_glUniform2fv          = reinterpret_cast<PFNGLUNIFORM2FVPROC>(loader("glUniform2fv"));
    glad_glUniform2f           = reinterpret_cast<PFNGLUNIFORM2FPROC>(loader("glUniform2f"));
    glad_glUniform2iv          = reinterpret_cast<PFNGLUNIFORM2IVPROC>(loader("glUniform2iv"));
    glad_glUniform2i           = reinterpret_cast<PFNGLUNIFORM2IPROC>(loader("glUniform2i"));
    glad_glUniform3fv          = reinterpret_cast<PFNGLUNIFORM3FVPROC>(loader("glUniform3fv"));
    glad_glUniform3f           = reinterpret_cast<PFNGLUNIFORM3FPROC>(loader("glUniform3f"));
    glad_glUniform3iv          = reinterpret_cast<PFNGLUNIFORM3IVPROC>(loader("glUniform3iv"));
    glad_glUniform3i           = reinterpret_cast<PFNGLUNIFORM3IPROC>(loader("glUniform3i"));
    glad_glUniform4fv          = reinterpret_cast<PFNGLUNIFORM4FVPROC>(loader("glUniform4fv"));
    glad_glUniform4f           = reinterpret_cast<PFNGLUNIFORM4FPROC>(loader("glUniform4f"));
    glad_glUniform4iv          = reinterpret_cast<PFNGLUNIFORM4IVPROC>(loader("glUniform4iv"));
    glad_glUniform4i           = reinterpret_cast<PFNGLUNIFORM4IPROC>(loader("glUniform4i"));
    glad_glUniformMatrix2fv    = reinterpret_cast<PFNGLUNIFORMMATRIX2FVPROC>(loader("glUniformMatrix2fv"));
    glad_glUniformMatrix3fv    = reinterpret_cast<PFNGLUNIFORMMATRIX3FVPROC>(loader("glUniformMatrix3fv"));
    glad_glUniformMatrix4fv    = reinterpret_cast<PFNGLUNIFORMMATRIX4FVPROC>(loader("glUniformMatrix4fv"));
    glad_glUseProgram          = reinterpret_cast<PFNGLUSEPROGRAMPROC>(loader("glUseProgram"));
    glad_glValidateProgram     = reinterpret_cast<PFNGLVALIDATEPROGRAMPROC>(loader("glValidateProgram"));
    glad_glVertexAttrib1dv     = reinterpret_cast<PFNGLVERTEXATTRIB1DVPROC>(loader("glVertexAttrib1dv"));
    glad_glVertexAttrib1d      = reinterpret_cast<PFNGLVERTEXATTRIB1DPROC>(loader("glVertexAttrib1d"));
    glad_glVertexAttrib1fv     = reinterpret_cast<PFNGLVERTEXATTRIB1FVPROC>(loader("glVertexAttrib1fv"));
    glad_glVertexAttrib1f      = reinterpret_cast<PFNGLVERTEXATTRIB1FPROC>(loader("glVertexAttrib1f"));
    glad_glVertexAttrib1sv     = reinterpret_cast<PFNGLVERTEXATTRIB1SVPROC>(loader("glVertexAttrib1sv"));
    glad_glVertexAttrib1s      = reinterpret_cast<PFNGLVERTEXATTRIB1SPROC>(loader("glVertexAttrib1s"));
    glad_glVertexAttrib2dv     = reinterpret_cast<PFNGLVERTEXATTRIB2DVPROC>(loader("glVertexAttrib2dv"));
    glad_glVertexAttrib2d      = reinterpret_cast<PFNGLVERTEXATTRIB2DPROC>(loader("glVertexAttrib2d"));
    glad_glVertexAttrib2fv     = reinterpret_cast<PFNGLVERTEXATTRIB2FVPROC>(loader("glVertexAttrib2fv"));
    glad_glVertexAttrib2f      = reinterpret_cast<PFNGLVERTEXATTRIB2FPROC>(loader("glVertexAttrib2f"));
    glad_glVertexAttrib2sv     = reinterpret_cast<PFNGLVERTEXATTRIB2SVPROC>(loader("glVertexAttrib2sv"));
    glad_glVertexAttrib2s      = reinterpret_cast<PFNGLVERTEXATTRIB2SPROC>(loader("glVertexAttrib2s"));
    glad_glVertexAttrib3dv     = reinterpret_cast<PFNGLVERTEXATTRIB3DVPROC>(loader("glVertexAttrib3dv"));
    glad_glVertexAttrib3d      = reinterpret_cast<PFNGLVERTEXATTRIB3DPROC>(loader("glVertexAttrib3d"));
    glad_glVertexAttrib3fv     = reinterpret_cast<PFNGLVERTEXATTRIB3FVPROC>(loader("glVertexAttrib3fv"));
    glad_glVertexAttrib3f      = reinterpret_cast<PFNGLVERTEXATTRIB3FPROC>(loader("glVertexAttrib3f"));
    glad_glVertexAttrib3sv     = reinterpret_cast<PFNGLVERTEXATTRIB3SVPROC>(loader("glVertexAttrib3sv"));
    glad_glVertexAttrib3s      = reinterpret_cast<PFNGLVERTEXATTRIB3SPROC>(loader("glVertexAttrib3s"));
    glad_glVertexAttrib4Nbv    = reinterpret_cast<PFNGLVERTEXATTRIB4NBVPROC>(loader("glVertexAttrib4Nbv"));
    glad_glVertexAttrib4Niv    = reinterpret_cast<PFNGLVERTEXATTRIB4NIVPROC>(loader("glVertexAttrib4Niv"));
    glad_glVertexAttrib4Nsv    = reinterpret_cast<PFNGLVERTEXATTRIB4NSVPROC>(loader("glVertexAttrib4Nsv"));
    glad_glVertexAttrib4Nubv   = reinterpret_cast<PFNGLVERTEXATTRIB4NUBVPROC>(loader("glVertexAttrib4Nubv"));
    glad_glVertexAttrib4Nub    = reinterpret_cast<PFNGLVERTEXATTRIB4NUBPROC>(loader("glVertexAttrib4Nub"));
    glad_glVertexAttrib4Nuiv   = reinterpret_cast<PFNGLVERTEXATTRIB4NUIVPROC>(loader("glVertexAttrib4Nuiv"));
    glad_glVertexAttrib4Nusv   = reinterpret_cast<PFNGLVERTEXATTRIB4NUSVPROC>(loader("glVertexAttrib4Nusv"));
    glad_glVertexAttrib4bv     = reinterpret_cast<PFNGLVERTEXATTRIB4BVPROC>(loader("glVertexAttrib4bv"));
    glad_glVertexAttrib4dv     = reinterpret_cast<PFNGLVERTEXATTRIB4DVPROC>(loader("glVertexAttrib4dv"));
    glad_glVertexAttrib4d      = reinterpret_cast<PFNGLVERTEXATTRIB4DPROC>(loader("glVertexAttrib4d"));
    glad_glVertexAttrib4fv     = reinterpret_cast<PFNGLVERTEXATTRIB4FVPROC>(loader("glVertexAttrib4fv"));
    glad_glVertexAttrib4f      = reinterpret_cast<PFNGLVERTEXATTRIB4FPROC>(loader("glVertexAttrib4f"));
    glad_glVertexAttrib4iv     = reinterpret_cast<PFNGLVERTEXATTRIB4IVPROC>(loader("glVertexAttrib4iv"));
    glad_glVertexAttrib4sv     = reinterpret_cast<PFNGLVERTEXATTRIB4SVPROC>(loader("glVertexAttrib4sv"));
    glad_glVertexAttrib4s      = reinterpret_cast<PFNGLVERTEXATTRIB4SPROC>(loader("glVertexAttrib4s"));
    glad_glVertexAttrib4ubv    = reinterpret_cast<PFNGLVERTEXATTRIB4UBVPROC>(loader("glVertexAttrib4ubv"));
    glad_glVertexAttrib4uiv    = reinterpret_cast<PFNGLVERTEXATTRIB4UIVPROC>(loader("glVertexAttrib4uiv"));
    glad_glVertexAttrib4usv    = reinterpret_cast<PFNGLVERTEXATTRIB4USVPROC>(loader("glVertexAttrib4usv"));
    glad_glVertexAttribPointer = reinterpret_cast<PFNGLVERTEXATTRIBPOINTERPROC>(loader("glVertexAttribPointer"));
}
} // namespace glr
#include <xg/glr/igl/GLfuncsv200.hpp>

namespace xg {
namespace glr {


GLfuncsv200::GLfuncsv200()
  : iglAttachShader(nullptr)
  , iglBindAttribLocation(nullptr)
  , iglBlendEquationSeparate(nullptr)
  , iglCompileShader(nullptr)
  , iglCreateProgram(nullptr)
  , iglCreateShader(nullptr)
  , iglDeleteProgram(nullptr)
  , iglDeleteShader(nullptr)
  , iglDetachShader(nullptr)
  , iglDisableVertexAttribArray(nullptr)
  , iglDrawBuffers(nullptr)
  , iglEnableVertexAttribArray(nullptr)
  , iglGetActiveAttrib(nullptr)
  , iglGetActiveUniform(nullptr)
  , iglGetAttachedShaders(nullptr)
  , iglGetAttribLocation(nullptr)
  , iglGetProgramInfoLog(nullptr)
  , iglGetProgramiv(nullptr)
  , iglGetShaderInfoLog(nullptr)
  , iglGetShaderSource(nullptr)
  , iglGetShaderiv(nullptr)
  , iglGetUniformLocation(nullptr)
  , iglGetUniformfv(nullptr)
  , iglGetUniformiv(nullptr)
  , iglGetVertexAttribPointerv(nullptr)
  , iglGetVertexAttribdv(nullptr)
  , iglGetVertexAttribfv(nullptr)
  , iglGetVertexAttribiv(nullptr)
  , iglIsProgram(nullptr)
  , iglIsShader(nullptr)
  , iglLinkProgram(nullptr)
  , iglShaderSource(nullptr)
  , iglStencilFuncSeparate(nullptr)
  , iglStencilMaskSeparate(nullptr)
  , iglStencilOpSeparate(nullptr)
  , iglUniform1fv(nullptr)
  , iglUniform1f(nullptr)
  , iglUniform1iv(nullptr)
  , iglUniform1i(nullptr)
  , iglUniform2fv(nullptr)
  , iglUniform2f(nullptr)
  , iglUniform2iv(nullptr)
  , iglUniform2i(nullptr)
  , iglUniform3fv(nullptr)
  , iglUniform3f(nullptr)
  , iglUniform3iv(nullptr)
  , iglUniform3i(nullptr)
  , iglUniform4fv(nullptr)
  , iglUniform4f(nullptr)
  , iglUniform4iv(nullptr)
  , iglUniform4i(nullptr)
  , iglUniformMatrix2fv(nullptr)
  , iglUniformMatrix3fv(nullptr)
  , iglUniformMatrix4fv(nullptr)
  , iglUseProgram(nullptr)
  , iglValidateProgram(nullptr)
  , iglVertexAttrib1dv(nullptr)
  , iglVertexAttrib1d(nullptr)
  , iglVertexAttrib1fv(nullptr)
  , iglVertexAttrib1f(nullptr)
  , iglVertexAttrib1sv(nullptr)
  , iglVertexAttrib1s(nullptr)
  , iglVertexAttrib2dv(nullptr)
  , iglVertexAttrib2d(nullptr)
  , iglVertexAttrib2fv(nullptr)
  , iglVertexAttrib2f(nullptr)
  , iglVertexAttrib2sv(nullptr)
  , iglVertexAttrib2s(nullptr)
  , iglVertexAttrib3dv(nullptr)
  , iglVertexAttrib3d(nullptr)
  , iglVertexAttrib3fv(nullptr)
  , iglVertexAttrib3f(nullptr)
  , iglVertexAttrib3sv(nullptr)
  , iglVertexAttrib3s(nullptr)
  , iglVertexAttrib4Nbv(nullptr)
  , iglVertexAttrib4Niv(nullptr)
  , iglVertexAttrib4Nsv(nullptr)
  , iglVertexAttrib4Nubv(nullptr)
  , iglVertexAttrib4Nub(nullptr)
  , iglVertexAttrib4Nuiv(nullptr)
  , iglVertexAttrib4Nusv(nullptr)
  , iglVertexAttrib4bv(nullptr)
  , iglVertexAttrib4dv(nullptr)
  , iglVertexAttrib4d(nullptr)
  , iglVertexAttrib4fv(nullptr)
  , iglVertexAttrib4f(nullptr)
  , iglVertexAttrib4iv(nullptr)
  , iglVertexAttrib4sv(nullptr)
  , iglVertexAttrib4s(nullptr)
  , iglVertexAttrib4ubv(nullptr)
  , iglVertexAttrib4uiv(nullptr)
  , iglVertexAttrib4usv(nullptr)
  , iglVertexAttribPointer(nullptr) {
}

void GLfuncsv200::loadFuncs(Loader loader) {
    GLfuncsv150::loadFuncs(loader);
    iglAttachShader          = reinterpret_cast<PFNGLATTACHSHADERPROC>(loader("glAttachShader"));
    iglBindAttribLocation    = reinterpret_cast<PFNGLBINDATTRIBLOCATIONPROC>(loader("glBindAttribLocation"));
    iglBlendEquationSeparate = reinterpret_cast<PFNGLBLENDEQUATIONSEPARATEPROC>(loader("glBlendEquationSeparate"));
    iglCompileShader         = reinterpret_cast<PFNGLCOMPILESHADERPROC>(loader("glCompileShader"));
    iglCreateProgram         = reinterpret_cast<PFNGLCREATEPROGRAMPROC>(loader("glCreateProgram"));
    iglCreateShader          = reinterpret_cast<PFNGLCREATESHADERPROC>(loader("glCreateShader"));
    iglDeleteProgram         = reinterpret_cast<PFNGLDELETEPROGRAMPROC>(loader("glDeleteProgram"));
    iglDeleteShader          = reinterpret_cast<PFNGLDELETESHADERPROC>(loader("glDeleteShader"));
    iglDetachShader          = reinterpret_cast<PFNGLDETACHSHADERPROC>(loader("glDetachShader"));
    iglDisableVertexAttribArray =
        reinterpret_cast<PFNGLDISABLEVERTEXATTRIBARRAYPROC>(loader("glDisableVertexAttribArray"));
    iglDrawBuffers = reinterpret_cast<PFNGLDRAWBUFFERSPROC>(loader("glDrawBuffers"));
    iglEnableVertexAttribArray =
        reinterpret_cast<PFNGLENABLEVERTEXATTRIBARRAYPROC>(loader("glEnableVertexAttribArray"));
    iglGetActiveAttrib    = reinterpret_cast<PFNGLGETACTIVEATTRIBPROC>(loader("glGetActiveAttrib"));
    iglGetActiveUniform   = reinterpret_cast<PFNGLGETACTIVEUNIFORMPROC>(loader("glGetActiveUniform"));
    iglGetAttachedShaders = reinterpret_cast<PFNGLGETATTACHEDSHADERSPROC>(loader("glGetAttachedShaders"));
    iglGetAttribLocation  = reinterpret_cast<PFNGLGETATTRIBLOCATIONPROC>(loader("glGetAttribLocation"));
    iglGetProgramInfoLog  = reinterpret_cast<PFNGLGETPROGRAMINFOLOGPROC>(loader("glGetProgramInfoLog"));
    iglGetProgramiv       = reinterpret_cast<PFNGLGETPROGRAMIVPROC>(loader("glGetProgramiv"));
    iglGetShaderInfoLog   = reinterpret_cast<PFNGLGETSHADERINFOLOGPROC>(loader("glGetShaderInfoLog"));
    iglGetShaderSource    = reinterpret_cast<PFNGLGETSHADERSOURCEPROC>(loader("glGetShaderSource"));
    iglGetShaderiv        = reinterpret_cast<PFNGLGETSHADERIVPROC>(loader("glGetShaderiv"));
    iglGetUniformLocation = reinterpret_cast<PFNGLGETUNIFORMLOCATIONPROC>(loader("glGetUniformLocation"));
    iglGetUniformfv       = reinterpret_cast<PFNGLGETUNIFORMFVPROC>(loader("glGetUniformfv"));
    iglGetUniformiv       = reinterpret_cast<PFNGLGETUNIFORMIVPROC>(loader("glGetUniformiv"));
    iglGetVertexAttribPointerv =
        reinterpret_cast<PFNGLGETVERTEXATTRIBPOINTERVPROC>(loader("glGetVertexAttribPointerv"));
    iglGetVertexAttribdv   = reinterpret_cast<PFNGLGETVERTEXATTRIBDVPROC>(loader("glGetVertexAttribdv"));
    iglGetVertexAttribfv   = reinterpret_cast<PFNGLGETVERTEXATTRIBFVPROC>(loader("glGetVertexAttribfv"));
    iglGetVertexAttribiv   = reinterpret_cast<PFNGLGETVERTEXATTRIBIVPROC>(loader("glGetVertexAttribiv"));
    iglIsProgram           = reinterpret_cast<PFNGLISPROGRAMPROC>(loader("glIsProgram"));
    iglIsShader            = reinterpret_cast<PFNGLISSHADERPROC>(loader("glIsShader"));
    iglLinkProgram         = reinterpret_cast<PFNGLLINKPROGRAMPROC>(loader("glLinkProgram"));
    iglShaderSource        = reinterpret_cast<PFNGLSHADERSOURCEPROC>(loader("glShaderSource"));
    iglStencilFuncSeparate = reinterpret_cast<PFNGLSTENCILFUNCSEPARATEPROC>(loader("glStencilFuncSeparate"));
    iglStencilMaskSeparate = reinterpret_cast<PFNGLSTENCILMASKSEPARATEPROC>(loader("glStencilMaskSeparate"));
    iglStencilOpSeparate   = reinterpret_cast<PFNGLSTENCILOPSEPARATEPROC>(loader("glStencilOpSeparate"));
    iglUniform1fv          = reinterpret_cast<PFNGLUNIFORM1FVPROC>(loader("glUniform1fv"));
    iglUniform1f           = reinterpret_cast<PFNGLUNIFORM1FPROC>(loader("glUniform1f"));
    iglUniform1iv          = reinterpret_cast<PFNGLUNIFORM1IVPROC>(loader("glUniform1iv"));
    iglUniform1i           = reinterpret_cast<PFNGLUNIFORM1IPROC>(loader("glUniform1i"));
    iglUniform2fv          = reinterpret_cast<PFNGLUNIFORM2FVPROC>(loader("glUniform2fv"));
    iglUniform2f           = reinterpret_cast<PFNGLUNIFORM2FPROC>(loader("glUniform2f"));
    iglUniform2iv          = reinterpret_cast<PFNGLUNIFORM2IVPROC>(loader("glUniform2iv"));
    iglUniform2i           = reinterpret_cast<PFNGLUNIFORM2IPROC>(loader("glUniform2i"));
    iglUniform3fv          = reinterpret_cast<PFNGLUNIFORM3FVPROC>(loader("glUniform3fv"));
    iglUniform3f           = reinterpret_cast<PFNGLUNIFORM3FPROC>(loader("glUniform3f"));
    iglUniform3iv          = reinterpret_cast<PFNGLUNIFORM3IVPROC>(loader("glUniform3iv"));
    iglUniform3i           = reinterpret_cast<PFNGLUNIFORM3IPROC>(loader("glUniform3i"));
    iglUniform4fv          = reinterpret_cast<PFNGLUNIFORM4FVPROC>(loader("glUniform4fv"));
    iglUniform4f           = reinterpret_cast<PFNGLUNIFORM4FPROC>(loader("glUniform4f"));
    iglUniform4iv          = reinterpret_cast<PFNGLUNIFORM4IVPROC>(loader("glUniform4iv"));
    iglUniform4i           = reinterpret_cast<PFNGLUNIFORM4IPROC>(loader("glUniform4i"));
    iglUniformMatrix2fv    = reinterpret_cast<PFNGLUNIFORMMATRIX2FVPROC>(loader("glUniformMatrix2fv"));
    iglUniformMatrix3fv    = reinterpret_cast<PFNGLUNIFORMMATRIX3FVPROC>(loader("glUniformMatrix3fv"));
    iglUniformMatrix4fv    = reinterpret_cast<PFNGLUNIFORMMATRIX4FVPROC>(loader("glUniformMatrix4fv"));
    iglUseProgram          = reinterpret_cast<PFNGLUSEPROGRAMPROC>(loader("glUseProgram"));
    iglValidateProgram     = reinterpret_cast<PFNGLVALIDATEPROGRAMPROC>(loader("glValidateProgram"));
    iglVertexAttrib1dv     = reinterpret_cast<PFNGLVERTEXATTRIB1DVPROC>(loader("glVertexAttrib1dv"));
    iglVertexAttrib1d      = reinterpret_cast<PFNGLVERTEXATTRIB1DPROC>(loader("glVertexAttrib1d"));
    iglVertexAttrib1fv     = reinterpret_cast<PFNGLVERTEXATTRIB1FVPROC>(loader("glVertexAttrib1fv"));
    iglVertexAttrib1f      = reinterpret_cast<PFNGLVERTEXATTRIB1FPROC>(loader("glVertexAttrib1f"));
    iglVertexAttrib1sv     = reinterpret_cast<PFNGLVERTEXATTRIB1SVPROC>(loader("glVertexAttrib1sv"));
    iglVertexAttrib1s      = reinterpret_cast<PFNGLVERTEXATTRIB1SPROC>(loader("glVertexAttrib1s"));
    iglVertexAttrib2dv     = reinterpret_cast<PFNGLVERTEXATTRIB2DVPROC>(loader("glVertexAttrib2dv"));
    iglVertexAttrib2d      = reinterpret_cast<PFNGLVERTEXATTRIB2DPROC>(loader("glVertexAttrib2d"));
    iglVertexAttrib2fv     = reinterpret_cast<PFNGLVERTEXATTRIB2FVPROC>(loader("glVertexAttrib2fv"));
    iglVertexAttrib2f      = reinterpret_cast<PFNGLVERTEXATTRIB2FPROC>(loader("glVertexAttrib2f"));
    iglVertexAttrib2sv     = reinterpret_cast<PFNGLVERTEXATTRIB2SVPROC>(loader("glVertexAttrib2sv"));
    iglVertexAttrib2s      = reinterpret_cast<PFNGLVERTEXATTRIB2SPROC>(loader("glVertexAttrib2s"));
    iglVertexAttrib3dv     = reinterpret_cast<PFNGLVERTEXATTRIB3DVPROC>(loader("glVertexAttrib3dv"));
    iglVertexAttrib3d      = reinterpret_cast<PFNGLVERTEXATTRIB3DPROC>(loader("glVertexAttrib3d"));
    iglVertexAttrib3fv     = reinterpret_cast<PFNGLVERTEXATTRIB3FVPROC>(loader("glVertexAttrib3fv"));
    iglVertexAttrib3f      = reinterpret_cast<PFNGLVERTEXATTRIB3FPROC>(loader("glVertexAttrib3f"));
    iglVertexAttrib3sv     = reinterpret_cast<PFNGLVERTEXATTRIB3SVPROC>(loader("glVertexAttrib3sv"));
    iglVertexAttrib3s      = reinterpret_cast<PFNGLVERTEXATTRIB3SPROC>(loader("glVertexAttrib3s"));
    iglVertexAttrib4Nbv    = reinterpret_cast<PFNGLVERTEXATTRIB4NBVPROC>(loader("glVertexAttrib4Nbv"));
    iglVertexAttrib4Niv    = reinterpret_cast<PFNGLVERTEXATTRIB4NIVPROC>(loader("glVertexAttrib4Niv"));
    iglVertexAttrib4Nsv    = reinterpret_cast<PFNGLVERTEXATTRIB4NSVPROC>(loader("glVertexAttrib4Nsv"));
    iglVertexAttrib4Nubv   = reinterpret_cast<PFNGLVERTEXATTRIB4NUBVPROC>(loader("glVertexAttrib4Nubv"));
    iglVertexAttrib4Nub    = reinterpret_cast<PFNGLVERTEXATTRIB4NUBPROC>(loader("glVertexAttrib4Nub"));
    iglVertexAttrib4Nuiv   = reinterpret_cast<PFNGLVERTEXATTRIB4NUIVPROC>(loader("glVertexAttrib4Nuiv"));
    iglVertexAttrib4Nusv   = reinterpret_cast<PFNGLVERTEXATTRIB4NUSVPROC>(loader("glVertexAttrib4Nusv"));
    iglVertexAttrib4bv     = reinterpret_cast<PFNGLVERTEXATTRIB4BVPROC>(loader("glVertexAttrib4bv"));
    iglVertexAttrib4dv     = reinterpret_cast<PFNGLVERTEXATTRIB4DVPROC>(loader("glVertexAttrib4dv"));
    iglVertexAttrib4d      = reinterpret_cast<PFNGLVERTEXATTRIB4DPROC>(loader("glVertexAttrib4d"));
    iglVertexAttrib4fv     = reinterpret_cast<PFNGLVERTEXATTRIB4FVPROC>(loader("glVertexAttrib4fv"));
    iglVertexAttrib4f      = reinterpret_cast<PFNGLVERTEXATTRIB4FPROC>(loader("glVertexAttrib4f"));
    iglVertexAttrib4iv     = reinterpret_cast<PFNGLVERTEXATTRIB4IVPROC>(loader("glVertexAttrib4iv"));
    iglVertexAttrib4sv     = reinterpret_cast<PFNGLVERTEXATTRIB4SVPROC>(loader("glVertexAttrib4sv"));
    iglVertexAttrib4s      = reinterpret_cast<PFNGLVERTEXATTRIB4SPROC>(loader("glVertexAttrib4s"));
    iglVertexAttrib4ubv    = reinterpret_cast<PFNGLVERTEXATTRIB4UBVPROC>(loader("glVertexAttrib4ubv"));
    iglVertexAttrib4uiv    = reinterpret_cast<PFNGLVERTEXATTRIB4UIVPROC>(loader("glVertexAttrib4uiv"));
    iglVertexAttrib4usv    = reinterpret_cast<PFNGLVERTEXATTRIB4USVPROC>(loader("glVertexAttrib4usv"));
    iglVertexAttribPointer = reinterpret_cast<PFNGLVERTEXATTRIBPOINTERPROC>(loader("glVertexAttribPointer"));
}
} // namespace glr
} // namespace xg
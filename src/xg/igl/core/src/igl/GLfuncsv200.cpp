#include <xg/igl/ogl/GLfuncsv200.hpp>

namespace xg
{
namespace glr
{


GLfuncsv200::GLfuncsv200()
  : oglAttachShader(nullptr)
  , oglBindAttribLocation(nullptr)
  , oglBlendEquationSeparate(nullptr)
  , oglCompileShader(nullptr)
  , oglCreateProgram(nullptr)
  , oglCreateShader(nullptr)
  , oglDeleteProgram(nullptr)
  , oglDeleteShader(nullptr)
  , oglDetachShader(nullptr)
  , oglDisableVertexAttribArray(nullptr)
  , oglDrawBuffers(nullptr)
  , oglEnableVertexAttribArray(nullptr)
  , oglGetActiveAttrib(nullptr)
  , oglGetActiveUniform(nullptr)
  , oglGetAttachedShaders(nullptr)
  , oglGetAttribLocation(nullptr)
  , oglGetProgramInfoLog(nullptr)
  , oglGetProgramiv(nullptr)
  , oglGetShaderInfoLog(nullptr)
  , oglGetShaderSource(nullptr)
  , oglGetShaderiv(nullptr)
  , oglGetUniformLocation(nullptr)
  , oglGetUniformfv(nullptr)
  , oglGetUniformiv(nullptr)
  , oglGetVertexAttribPointerv(nullptr)
  , oglGetVertexAttribdv(nullptr)
  , oglGetVertexAttribfv(nullptr)
  , oglGetVertexAttribiv(nullptr)
  , oglIsProgram(nullptr)
  , oglIsShader(nullptr)
  , oglLinkProgram(nullptr)
  , oglShaderSource(nullptr)
  , oglStencilFuncSeparate(nullptr)
  , oglStencilMaskSeparate(nullptr)
  , oglStencilOpSeparate(nullptr)
  , oglUniform1fv(nullptr)
  , oglUniform1f(nullptr)
  , oglUniform1iv(nullptr)
  , oglUniform1i(nullptr)
  , oglUniform2fv(nullptr)
  , oglUniform2f(nullptr)
  , oglUniform2iv(nullptr)
  , oglUniform2i(nullptr)
  , oglUniform3fv(nullptr)
  , oglUniform3f(nullptr)
  , oglUniform3iv(nullptr)
  , oglUniform3i(nullptr)
  , oglUniform4fv(nullptr)
  , oglUniform4f(nullptr)
  , oglUniform4iv(nullptr)
  , oglUniform4i(nullptr)
  , oglUniformMatrix2fv(nullptr)
  , oglUniformMatrix3fv(nullptr)
  , oglUniformMatrix4fv(nullptr)
  , oglUseProgram(nullptr)
  , oglValidateProgram(nullptr)
  , oglVertexAttrib1dv(nullptr)
  , oglVertexAttrib1d(nullptr)
  , oglVertexAttrib1fv(nullptr)
  , oglVertexAttrib1f(nullptr)
  , oglVertexAttrib1sv(nullptr)
  , oglVertexAttrib1s(nullptr)
  , oglVertexAttrib2dv(nullptr)
  , oglVertexAttrib2d(nullptr)
  , oglVertexAttrib2fv(nullptr)
  , oglVertexAttrib2f(nullptr)
  , oglVertexAttrib2sv(nullptr)
  , oglVertexAttrib2s(nullptr)
  , oglVertexAttrib3dv(nullptr)
  , oglVertexAttrib3d(nullptr)
  , oglVertexAttrib3fv(nullptr)
  , oglVertexAttrib3f(nullptr)
  , oglVertexAttrib3sv(nullptr)
  , oglVertexAttrib3s(nullptr)
  , oglVertexAttrib4Nbv(nullptr)
  , oglVertexAttrib4Niv(nullptr)
  , oglVertexAttrib4Nsv(nullptr)
  , oglVertexAttrib4Nubv(nullptr)
  , oglVertexAttrib4Nub(nullptr)
  , oglVertexAttrib4Nuiv(nullptr)
  , oglVertexAttrib4Nusv(nullptr)
  , oglVertexAttrib4bv(nullptr)
  , oglVertexAttrib4dv(nullptr)
  , oglVertexAttrib4d(nullptr)
  , oglVertexAttrib4fv(nullptr)
  , oglVertexAttrib4f(nullptr)
  , oglVertexAttrib4iv(nullptr)
  , oglVertexAttrib4sv(nullptr)
  , oglVertexAttrib4s(nullptr)
  , oglVertexAttrib4ubv(nullptr)
  , oglVertexAttrib4uiv(nullptr)
  , oglVertexAttrib4usv(nullptr)
  , oglVertexAttribPointer(nullptr)
{}

void GLfuncsv200::loadFuncs(Loader loader)
{
    GLfuncsv150::loadFuncs(loader);
    oglAttachShader             = reinterpret_cast<PFNGLATTACHSHADERPROC>(loader("glAttachShader"));
    oglBindAttribLocation       = reinterpret_cast<PFNGLBINDATTRIBLOCATIONPROC>(loader("glBindAttribLocation"));
    oglBlendEquationSeparate    = reinterpret_cast<PFNGLBLENDEQUATIONSEPARATEPROC>(loader("glBlendEquationSeparate"));
    oglCompileShader            = reinterpret_cast<PFNGLCOMPILESHADERPROC>(loader("glCompileShader"));
    oglCreateProgram            = reinterpret_cast<PFNGLCREATEPROGRAMPROC>(loader("glCreateProgram"));
    oglCreateShader             = reinterpret_cast<PFNGLCREATESHADERPROC>(loader("glCreateShader"));
    oglDeleteProgram            = reinterpret_cast<PFNGLDELETEPROGRAMPROC>(loader("glDeleteProgram"));
    oglDeleteShader             = reinterpret_cast<PFNGLDELETESHADERPROC>(loader("glDeleteShader"));
    oglDetachShader             = reinterpret_cast<PFNGLDETACHSHADERPROC>(loader("glDetachShader"));
    oglDisableVertexAttribArray = reinterpret_cast<PFNGLDISABLEVERTEXATTRIBARRAYPROC>(loader("glDisableVertexAttribArray"));
    oglDrawBuffers              = reinterpret_cast<PFNGLDRAWBUFFERSPROC>(loader("glDrawBuffers"));
    oglEnableVertexAttribArray  = reinterpret_cast<PFNGLENABLEVERTEXATTRIBARRAYPROC>(loader("glEnableVertexAttribArray"));
    oglGetActiveAttrib          = reinterpret_cast<PFNGLGETACTIVEATTRIBPROC>(loader("glGetActiveAttrib"));
    oglGetActiveUniform         = reinterpret_cast<PFNGLGETACTIVEUNIFORMPROC>(loader("glGetActiveUniform"));
    oglGetAttachedShaders       = reinterpret_cast<PFNGLGETATTACHEDSHADERSPROC>(loader("glGetAttachedShaders"));
    oglGetAttribLocation        = reinterpret_cast<PFNGLGETATTRIBLOCATIONPROC>(loader("glGetAttribLocation"));
    oglGetProgramInfoLog        = reinterpret_cast<PFNGLGETPROGRAMINFOLOGPROC>(loader("glGetProgramInfoLog"));
    oglGetProgramiv             = reinterpret_cast<PFNGLGETPROGRAMIVPROC>(loader("glGetProgramiv"));
    oglGetShaderInfoLog         = reinterpret_cast<PFNGLGETSHADERINFOLOGPROC>(loader("glGetShaderInfoLog"));
    oglGetShaderSource          = reinterpret_cast<PFNGLGETSHADERSOURCEPROC>(loader("glGetShaderSource"));
    oglGetShaderiv              = reinterpret_cast<PFNGLGETSHADERIVPROC>(loader("glGetShaderiv"));
    oglGetUniformLocation       = reinterpret_cast<PFNGLGETUNIFORMLOCATIONPROC>(loader("glGetUniformLocation"));
    oglGetUniformfv             = reinterpret_cast<PFNGLGETUNIFORMFVPROC>(loader("glGetUniformfv"));
    oglGetUniformiv             = reinterpret_cast<PFNGLGETUNIFORMIVPROC>(loader("glGetUniformiv"));
    oglGetVertexAttribPointerv  = reinterpret_cast<PFNGLGETVERTEXATTRIBPOINTERVPROC>(loader("glGetVertexAttribPointerv"));
    oglGetVertexAttribdv        = reinterpret_cast<PFNGLGETVERTEXATTRIBDVPROC>(loader("glGetVertexAttribdv"));
    oglGetVertexAttribfv        = reinterpret_cast<PFNGLGETVERTEXATTRIBFVPROC>(loader("glGetVertexAttribfv"));
    oglGetVertexAttribiv        = reinterpret_cast<PFNGLGETVERTEXATTRIBIVPROC>(loader("glGetVertexAttribiv"));
    oglIsProgram                = reinterpret_cast<PFNGLISPROGRAMPROC>(loader("glIsProgram"));
    oglIsShader                 = reinterpret_cast<PFNGLISSHADERPROC>(loader("glIsShader"));
    oglLinkProgram              = reinterpret_cast<PFNGLLINKPROGRAMPROC>(loader("glLinkProgram"));
    oglShaderSource             = reinterpret_cast<PFNGLSHADERSOURCEPROC>(loader("glShaderSource"));
    oglStencilFuncSeparate      = reinterpret_cast<PFNGLSTENCILFUNCSEPARATEPROC>(loader("glStencilFuncSeparate"));
    oglStencilMaskSeparate      = reinterpret_cast<PFNGLSTENCILMASKSEPARATEPROC>(loader("glStencilMaskSeparate"));
    oglStencilOpSeparate        = reinterpret_cast<PFNGLSTENCILOPSEPARATEPROC>(loader("glStencilOpSeparate"));
    oglUniform1fv               = reinterpret_cast<PFNGLUNIFORM1FVPROC>(loader("glUniform1fv"));
    oglUniform1f                = reinterpret_cast<PFNGLUNIFORM1FPROC>(loader("glUniform1f"));
    oglUniform1iv               = reinterpret_cast<PFNGLUNIFORM1IVPROC>(loader("glUniform1iv"));
    oglUniform1i                = reinterpret_cast<PFNGLUNIFORM1IPROC>(loader("glUniform1i"));
    oglUniform2fv               = reinterpret_cast<PFNGLUNIFORM2FVPROC>(loader("glUniform2fv"));
    oglUniform2f                = reinterpret_cast<PFNGLUNIFORM2FPROC>(loader("glUniform2f"));
    oglUniform2iv               = reinterpret_cast<PFNGLUNIFORM2IVPROC>(loader("glUniform2iv"));
    oglUniform2i                = reinterpret_cast<PFNGLUNIFORM2IPROC>(loader("glUniform2i"));
    oglUniform3fv               = reinterpret_cast<PFNGLUNIFORM3FVPROC>(loader("glUniform3fv"));
    oglUniform3f                = reinterpret_cast<PFNGLUNIFORM3FPROC>(loader("glUniform3f"));
    oglUniform3iv               = reinterpret_cast<PFNGLUNIFORM3IVPROC>(loader("glUniform3iv"));
    oglUniform3i                = reinterpret_cast<PFNGLUNIFORM3IPROC>(loader("glUniform3i"));
    oglUniform4fv               = reinterpret_cast<PFNGLUNIFORM4FVPROC>(loader("glUniform4fv"));
    oglUniform4f                = reinterpret_cast<PFNGLUNIFORM4FPROC>(loader("glUniform4f"));
    oglUniform4iv               = reinterpret_cast<PFNGLUNIFORM4IVPROC>(loader("glUniform4iv"));
    oglUniform4i                = reinterpret_cast<PFNGLUNIFORM4IPROC>(loader("glUniform4i"));
    oglUniformMatrix2fv         = reinterpret_cast<PFNGLUNIFORMMATRIX2FVPROC>(loader("glUniformMatrix2fv"));
    oglUniformMatrix3fv         = reinterpret_cast<PFNGLUNIFORMMATRIX3FVPROC>(loader("glUniformMatrix3fv"));
    oglUniformMatrix4fv         = reinterpret_cast<PFNGLUNIFORMMATRIX4FVPROC>(loader("glUniformMatrix4fv"));
    oglUseProgram               = reinterpret_cast<PFNGLUSEPROGRAMPROC>(loader("glUseProgram"));
    oglValidateProgram          = reinterpret_cast<PFNGLVALIDATEPROGRAMPROC>(loader("glValidateProgram"));
    oglVertexAttrib1dv          = reinterpret_cast<PFNGLVERTEXATTRIB1DVPROC>(loader("glVertexAttrib1dv"));
    oglVertexAttrib1d           = reinterpret_cast<PFNGLVERTEXATTRIB1DPROC>(loader("glVertexAttrib1d"));
    oglVertexAttrib1fv          = reinterpret_cast<PFNGLVERTEXATTRIB1FVPROC>(loader("glVertexAttrib1fv"));
    oglVertexAttrib1f           = reinterpret_cast<PFNGLVERTEXATTRIB1FPROC>(loader("glVertexAttrib1f"));
    oglVertexAttrib1sv          = reinterpret_cast<PFNGLVERTEXATTRIB1SVPROC>(loader("glVertexAttrib1sv"));
    oglVertexAttrib1s           = reinterpret_cast<PFNGLVERTEXATTRIB1SPROC>(loader("glVertexAttrib1s"));
    oglVertexAttrib2dv          = reinterpret_cast<PFNGLVERTEXATTRIB2DVPROC>(loader("glVertexAttrib2dv"));
    oglVertexAttrib2d           = reinterpret_cast<PFNGLVERTEXATTRIB2DPROC>(loader("glVertexAttrib2d"));
    oglVertexAttrib2fv          = reinterpret_cast<PFNGLVERTEXATTRIB2FVPROC>(loader("glVertexAttrib2fv"));
    oglVertexAttrib2f           = reinterpret_cast<PFNGLVERTEXATTRIB2FPROC>(loader("glVertexAttrib2f"));
    oglVertexAttrib2sv          = reinterpret_cast<PFNGLVERTEXATTRIB2SVPROC>(loader("glVertexAttrib2sv"));
    oglVertexAttrib2s           = reinterpret_cast<PFNGLVERTEXATTRIB2SPROC>(loader("glVertexAttrib2s"));
    oglVertexAttrib3dv          = reinterpret_cast<PFNGLVERTEXATTRIB3DVPROC>(loader("glVertexAttrib3dv"));
    oglVertexAttrib3d           = reinterpret_cast<PFNGLVERTEXATTRIB3DPROC>(loader("glVertexAttrib3d"));
    oglVertexAttrib3fv          = reinterpret_cast<PFNGLVERTEXATTRIB3FVPROC>(loader("glVertexAttrib3fv"));
    oglVertexAttrib3f           = reinterpret_cast<PFNGLVERTEXATTRIB3FPROC>(loader("glVertexAttrib3f"));
    oglVertexAttrib3sv          = reinterpret_cast<PFNGLVERTEXATTRIB3SVPROC>(loader("glVertexAttrib3sv"));
    oglVertexAttrib3s           = reinterpret_cast<PFNGLVERTEXATTRIB3SPROC>(loader("glVertexAttrib3s"));
    oglVertexAttrib4Nbv         = reinterpret_cast<PFNGLVERTEXATTRIB4NBVPROC>(loader("glVertexAttrib4Nbv"));
    oglVertexAttrib4Niv         = reinterpret_cast<PFNGLVERTEXATTRIB4NIVPROC>(loader("glVertexAttrib4Niv"));
    oglVertexAttrib4Nsv         = reinterpret_cast<PFNGLVERTEXATTRIB4NSVPROC>(loader("glVertexAttrib4Nsv"));
    oglVertexAttrib4Nubv        = reinterpret_cast<PFNGLVERTEXATTRIB4NUBVPROC>(loader("glVertexAttrib4Nubv"));
    oglVertexAttrib4Nub         = reinterpret_cast<PFNGLVERTEXATTRIB4NUBPROC>(loader("glVertexAttrib4Nub"));
    oglVertexAttrib4Nuiv        = reinterpret_cast<PFNGLVERTEXATTRIB4NUIVPROC>(loader("glVertexAttrib4Nuiv"));
    oglVertexAttrib4Nusv        = reinterpret_cast<PFNGLVERTEXATTRIB4NUSVPROC>(loader("glVertexAttrib4Nusv"));
    oglVertexAttrib4bv          = reinterpret_cast<PFNGLVERTEXATTRIB4BVPROC>(loader("glVertexAttrib4bv"));
    oglVertexAttrib4dv          = reinterpret_cast<PFNGLVERTEXATTRIB4DVPROC>(loader("glVertexAttrib4dv"));
    oglVertexAttrib4d           = reinterpret_cast<PFNGLVERTEXATTRIB4DPROC>(loader("glVertexAttrib4d"));
    oglVertexAttrib4fv          = reinterpret_cast<PFNGLVERTEXATTRIB4FVPROC>(loader("glVertexAttrib4fv"));
    oglVertexAttrib4f           = reinterpret_cast<PFNGLVERTEXATTRIB4FPROC>(loader("glVertexAttrib4f"));
    oglVertexAttrib4iv          = reinterpret_cast<PFNGLVERTEXATTRIB4IVPROC>(loader("glVertexAttrib4iv"));
    oglVertexAttrib4sv          = reinterpret_cast<PFNGLVERTEXATTRIB4SVPROC>(loader("glVertexAttrib4sv"));
    oglVertexAttrib4s           = reinterpret_cast<PFNGLVERTEXATTRIB4SPROC>(loader("glVertexAttrib4s"));
    oglVertexAttrib4ubv         = reinterpret_cast<PFNGLVERTEXATTRIB4UBVPROC>(loader("glVertexAttrib4ubv"));
    oglVertexAttrib4uiv         = reinterpret_cast<PFNGLVERTEXATTRIB4UIVPROC>(loader("glVertexAttrib4uiv"));
    oglVertexAttrib4usv         = reinterpret_cast<PFNGLVERTEXATTRIB4USVPROC>(loader("glVertexAttrib4usv"));
    oglVertexAttribPointer      = reinterpret_cast<PFNGLVERTEXATTRIBPOINTERPROC>(loader("glVertexAttribPointer"));
}

} // namespace glr
} // namespace xg
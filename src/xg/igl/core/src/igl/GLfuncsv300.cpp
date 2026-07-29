#include <xg/igl/ogl/GLfuncsv300.hpp>

namespace xg
{
namespace glr
{


GLfuncsv300::GLfuncsv300()
  : oglBeginConditionalRender(nullptr)
  , oglBeginTransformFeedback(nullptr)
  , oglBindBufferBase(nullptr)
  , oglBindBufferRange(nullptr)
  , oglBindFragDataLocation(nullptr)
  , oglBindFramebuffer(nullptr)
  , oglBindRenderbuffer(nullptr)
  , oglBindVertexArray(nullptr)
  , oglBlitFramebuffer(nullptr)
  , oglCheckFramebufferStatus(nullptr)
  , oglClampColor(nullptr)
  , oglClearBufferfi(nullptr)
  , oglClearBufferfv(nullptr)
  , oglClearBufferiv(nullptr)
  , oglClearBufferuiv(nullptr)
  , oglColorMaski(nullptr)
  , oglDeleteFramebuffers(nullptr)
  , oglDeleteRenderbuffers(nullptr)
  , oglDeleteVertexArrays(nullptr)
  , oglDisablei(nullptr)
  , oglEnablei(nullptr)
  , oglEndConditionalRender(nullptr)
  , oglEndTransformFeedback(nullptr)
  , oglFlushMappedBufferRange(nullptr)
  , oglFramebufferRenderbuffer(nullptr)
  , oglFramebufferTexture1D(nullptr)
  , oglFramebufferTexture2D(nullptr)
  , oglFramebufferTexture3D(nullptr)
  , oglFramebufferTextureLayer(nullptr)
  , oglGenFramebuffers(nullptr)
  , oglGenRenderbuffers(nullptr)
  , oglGenVertexArrays(nullptr)
  , oglGenerateMipmap(nullptr)
  , oglGetBooleani_v(nullptr)
  , oglGetFragDataLocation(nullptr)
  , oglGetFramebufferAttachmentParameteriv(nullptr)
  , oglGetIntegeri_v(nullptr)
  , oglGetRenderbufferParameteriv(nullptr)
  , oglGetStringi(nullptr)
  , oglGetTexParameterIiv(nullptr)
  , oglGetTexParameterIuiv(nullptr)
  , oglGetTransformFeedbackVarying(nullptr)
  , oglGetUniformuiv(nullptr)
  , oglGetVertexAttribIiv(nullptr)
  , oglGetVertexAttribIuiv(nullptr)
  , oglIsEnabledi(nullptr)
  , oglIsFramebuffer(nullptr)
  , oglIsRenderbuffer(nullptr)
  , oglIsVertexArray(nullptr)
  , oglMapBufferRange(nullptr)
  , oglRenderbufferStorageMultisample(nullptr)
  , oglRenderbufferStorage(nullptr)
  , oglTexParameterIiv(nullptr)
  , oglTexParameterIuiv(nullptr)
  , oglTransformFeedbackVaryings(nullptr)
  , oglUniform1uiv(nullptr)
  , oglUniform1ui(nullptr)
  , oglUniform2uiv(nullptr)
  , oglUniform2ui(nullptr)
  , oglUniform3uiv(nullptr)
  , oglUniform3ui(nullptr)
  , oglUniform4uiv(nullptr)
  , oglUniform4ui(nullptr)
  , oglVertexAttribI1iv(nullptr)
  , oglVertexAttribI1i(nullptr)
  , oglVertexAttribI1uiv(nullptr)
  , oglVertexAttribI1ui(nullptr)
  , oglVertexAttribI2iv(nullptr)
  , oglVertexAttribI2i(nullptr)
  , oglVertexAttribI2uiv(nullptr)
  , oglVertexAttribI2ui(nullptr)
  , oglVertexAttribI3iv(nullptr)
  , oglVertexAttribI3i(nullptr)
  , oglVertexAttribI3uiv(nullptr)
  , oglVertexAttribI3ui(nullptr)
  , oglVertexAttribI4bv(nullptr)
  , oglVertexAttribI4iv(nullptr)
  , oglVertexAttribI4i(nullptr)
  , oglVertexAttribI4sv(nullptr)
  , oglVertexAttribI4ubv(nullptr)
  , oglVertexAttribI4uiv(nullptr)
  , oglVertexAttribI4ui(nullptr)
  , oglVertexAttribI4usv(nullptr)
  , oglVertexAttribIPointer(nullptr)
{}

void GLfuncsv300::loadFuncs(Loader loader)
{
    GLfuncsv210::loadFuncs(loader);
    oglBeginConditionalRender              = reinterpret_cast<PFNGLBEGINCONDITIONALRENDERPROC>(loader("glBeginConditionalRender"));
    oglBeginTransformFeedback              = reinterpret_cast<PFNGLBEGINTRANSFORMFEEDBACKPROC>(loader("glBeginTransformFeedback"));
    oglBindBufferBase                      = reinterpret_cast<PFNGLBINDBUFFERBASEPROC>(loader("glBindBufferBase"));
    oglBindBufferRange                     = reinterpret_cast<PFNGLBINDBUFFERRANGEPROC>(loader("glBindBufferRange"));
    oglBindFragDataLocation                = reinterpret_cast<PFNGLBINDFRAGDATALOCATIONPROC>(loader("glBindFragDataLocation"));
    oglBindFramebuffer                     = reinterpret_cast<PFNGLBINDFRAMEBUFFERPROC>(loader("glBindFramebuffer"));
    oglBindRenderbuffer                    = reinterpret_cast<PFNGLBINDRENDERBUFFERPROC>(loader("glBindRenderbuffer"));
    oglBindVertexArray                     = reinterpret_cast<PFNGLBINDVERTEXARRAYPROC>(loader("glBindVertexArray"));
    oglBlitFramebuffer                     = reinterpret_cast<PFNGLBLITFRAMEBUFFERPROC>(loader("glBlitFramebuffer"));
    oglCheckFramebufferStatus              = reinterpret_cast<PFNGLCHECKFRAMEBUFFERSTATUSPROC>(loader("glCheckFramebufferStatus"));
    oglClampColor                          = reinterpret_cast<PFNGLCLAMPCOLORPROC>(loader("glClampColor"));
    oglClearBufferfi                       = reinterpret_cast<PFNGLCLEARBUFFERFIPROC>(loader("glClearBufferfi"));
    oglClearBufferfv                       = reinterpret_cast<PFNGLCLEARBUFFERFVPROC>(loader("glClearBufferfv"));
    oglClearBufferiv                       = reinterpret_cast<PFNGLCLEARBUFFERIVPROC>(loader("glClearBufferiv"));
    oglClearBufferuiv                      = reinterpret_cast<PFNGLCLEARBUFFERUIVPROC>(loader("glClearBufferuiv"));
    oglColorMaski                          = reinterpret_cast<PFNGLCOLORMASKIPROC>(loader("glColorMaski"));
    oglDeleteFramebuffers                  = reinterpret_cast<PFNGLDELETEFRAMEBUFFERSPROC>(loader("glDeleteFramebuffers"));
    oglDeleteRenderbuffers                 = reinterpret_cast<PFNGLDELETERENDERBUFFERSPROC>(loader("glDeleteRenderbuffers"));
    oglDeleteVertexArrays                  = reinterpret_cast<PFNGLDELETEVERTEXARRAYSPROC>(loader("glDeleteVertexArrays"));
    oglDisablei                            = reinterpret_cast<PFNGLDISABLEIPROC>(loader("glDisablei"));
    oglEnablei                             = reinterpret_cast<PFNGLENABLEIPROC>(loader("glEnablei"));
    oglEndConditionalRender                = reinterpret_cast<PFNGLENDCONDITIONALRENDERPROC>(loader("glEndConditionalRender"));
    oglEndTransformFeedback                = reinterpret_cast<PFNGLENDTRANSFORMFEEDBACKPROC>(loader("glEndTransformFeedback"));
    oglFlushMappedBufferRange              = reinterpret_cast<PFNGLFLUSHMAPPEDBUFFERRANGEPROC>(loader("glFlushMappedBufferRange"));
    oglFramebufferRenderbuffer             = reinterpret_cast<PFNGLFRAMEBUFFERRENDERBUFFERPROC>(loader("glFramebufferRenderbuffer"));
    oglFramebufferTexture1D                = reinterpret_cast<PFNGLFRAMEBUFFERTEXTURE1DPROC>(loader("glFramebufferTexture1D"));
    oglFramebufferTexture2D                = reinterpret_cast<PFNGLFRAMEBUFFERTEXTURE2DPROC>(loader("glFramebufferTexture2D"));
    oglFramebufferTexture3D                = reinterpret_cast<PFNGLFRAMEBUFFERTEXTURE3DPROC>(loader("glFramebufferTexture3D"));
    oglFramebufferTextureLayer             = reinterpret_cast<PFNGLFRAMEBUFFERTEXTURELAYERPROC>(loader("glFramebufferTextureLayer"));
    oglGenFramebuffers                     = reinterpret_cast<PFNGLGENFRAMEBUFFERSPROC>(loader("glGenFramebuffers"));
    oglGenRenderbuffers                    = reinterpret_cast<PFNGLGENRENDERBUFFERSPROC>(loader("glGenRenderbuffers"));
    oglGenVertexArrays                     = reinterpret_cast<PFNGLGENVERTEXARRAYSPROC>(loader("glGenVertexArrays"));
    oglGenerateMipmap                      = reinterpret_cast<PFNGLGENERATEMIPMAPPROC>(loader("glGenerateMipmap"));
    oglGetBooleani_v                       = reinterpret_cast<PFNGLGETBOOLEANI_VPROC>(loader("glGetBooleani_v"));
    oglGetFragDataLocation                 = reinterpret_cast<PFNGLGETFRAGDATALOCATIONPROC>(loader("glGetFragDataLocation"));
    oglGetFramebufferAttachmentParameteriv = reinterpret_cast<PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC>(loader("glGetFramebufferAttachmentParameteriv"));
    oglGetIntegeri_v                       = reinterpret_cast<PFNGLGETINTEGERI_VPROC>(loader("glGetIntegeri_v"));
    oglGetRenderbufferParameteriv          = reinterpret_cast<PFNGLGETRENDERBUFFERPARAMETERIVPROC>(loader("glGetRenderbufferParameteriv"));
    oglGetStringi                          = reinterpret_cast<PFNGLGETSTRINGIPROC>(loader("glGetStringi"));
    oglGetTexParameterIiv                  = reinterpret_cast<PFNGLGETTEXPARAMETERIIVPROC>(loader("glGetTexParameterIiv"));
    oglGetTexParameterIuiv                 = reinterpret_cast<PFNGLGETTEXPARAMETERIUIVPROC>(loader("glGetTexParameterIuiv"));
    oglGetTransformFeedbackVarying         = reinterpret_cast<PFNGLGETTRANSFORMFEEDBACKVARYINGPROC>(loader("glGetTransformFeedbackVarying"));
    oglGetUniformuiv                       = reinterpret_cast<PFNGLGETUNIFORMUIVPROC>(loader("glGetUniformuiv"));
    oglGetVertexAttribIiv                  = reinterpret_cast<PFNGLGETVERTEXATTRIBIIVPROC>(loader("glGetVertexAttribIiv"));
    oglGetVertexAttribIuiv                 = reinterpret_cast<PFNGLGETVERTEXATTRIBIUIVPROC>(loader("glGetVertexAttribIuiv"));
    oglIsEnabledi                          = reinterpret_cast<PFNGLISENABLEDIPROC>(loader("glIsEnabledi"));
    oglIsFramebuffer                       = reinterpret_cast<PFNGLISFRAMEBUFFERPROC>(loader("glIsFramebuffer"));
    oglIsRenderbuffer                      = reinterpret_cast<PFNGLISRENDERBUFFERPROC>(loader("glIsRenderbuffer"));
    oglIsVertexArray                       = reinterpret_cast<PFNGLISVERTEXARRAYPROC>(loader("glIsVertexArray"));
    oglMapBufferRange                      = reinterpret_cast<PFNGLMAPBUFFERRANGEPROC>(loader("glMapBufferRange"));
    oglRenderbufferStorageMultisample      = reinterpret_cast<PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC>(loader("glRenderbufferStorageMultisample"));
    oglRenderbufferStorage                 = reinterpret_cast<PFNGLRENDERBUFFERSTORAGEPROC>(loader("glRenderbufferStorage"));
    oglTexParameterIiv                     = reinterpret_cast<PFNGLTEXPARAMETERIIVPROC>(loader("glTexParameterIiv"));
    oglTexParameterIuiv                    = reinterpret_cast<PFNGLTEXPARAMETERIUIVPROC>(loader("glTexParameterIuiv"));
    oglTransformFeedbackVaryings           = reinterpret_cast<PFNGLTRANSFORMFEEDBACKVARYINGSPROC>(loader("glTransformFeedbackVaryings"));
    oglUniform1uiv                         = reinterpret_cast<PFNGLUNIFORM1UIVPROC>(loader("glUniform1uiv"));
    oglUniform1ui                          = reinterpret_cast<PFNGLUNIFORM1UIPROC>(loader("glUniform1ui"));
    oglUniform2uiv                         = reinterpret_cast<PFNGLUNIFORM2UIVPROC>(loader("glUniform2uiv"));
    oglUniform2ui                          = reinterpret_cast<PFNGLUNIFORM2UIPROC>(loader("glUniform2ui"));
    oglUniform3uiv                         = reinterpret_cast<PFNGLUNIFORM3UIVPROC>(loader("glUniform3uiv"));
    oglUniform3ui                          = reinterpret_cast<PFNGLUNIFORM3UIPROC>(loader("glUniform3ui"));
    oglUniform4uiv                         = reinterpret_cast<PFNGLUNIFORM4UIVPROC>(loader("glUniform4uiv"));
    oglUniform4ui                          = reinterpret_cast<PFNGLUNIFORM4UIPROC>(loader("glUniform4ui"));
    oglVertexAttribI1iv                    = reinterpret_cast<PFNGLVERTEXATTRIBI1IVPROC>(loader("glVertexAttribI1iv"));
    oglVertexAttribI1i                     = reinterpret_cast<PFNGLVERTEXATTRIBI1IPROC>(loader("glVertexAttribI1i"));
    oglVertexAttribI1uiv                   = reinterpret_cast<PFNGLVERTEXATTRIBI1UIVPROC>(loader("glVertexAttribI1uiv"));
    oglVertexAttribI1ui                    = reinterpret_cast<PFNGLVERTEXATTRIBI1UIPROC>(loader("glVertexAttribI1ui"));
    oglVertexAttribI2iv                    = reinterpret_cast<PFNGLVERTEXATTRIBI2IVPROC>(loader("glVertexAttribI2iv"));
    oglVertexAttribI2i                     = reinterpret_cast<PFNGLVERTEXATTRIBI2IPROC>(loader("glVertexAttribI2i"));
    oglVertexAttribI2uiv                   = reinterpret_cast<PFNGLVERTEXATTRIBI2UIVPROC>(loader("glVertexAttribI2uiv"));
    oglVertexAttribI2ui                    = reinterpret_cast<PFNGLVERTEXATTRIBI2UIPROC>(loader("glVertexAttribI2ui"));
    oglVertexAttribI3iv                    = reinterpret_cast<PFNGLVERTEXATTRIBI3IVPROC>(loader("glVertexAttribI3iv"));
    oglVertexAttribI3i                     = reinterpret_cast<PFNGLVERTEXATTRIBI3IPROC>(loader("glVertexAttribI3i"));
    oglVertexAttribI3uiv                   = reinterpret_cast<PFNGLVERTEXATTRIBI3UIVPROC>(loader("glVertexAttribI3uiv"));
    oglVertexAttribI3ui                    = reinterpret_cast<PFNGLVERTEXATTRIBI3UIPROC>(loader("glVertexAttribI3ui"));
    oglVertexAttribI4bv                    = reinterpret_cast<PFNGLVERTEXATTRIBI4BVPROC>(loader("glVertexAttribI4bv"));
    oglVertexAttribI4iv                    = reinterpret_cast<PFNGLVERTEXATTRIBI4IVPROC>(loader("glVertexAttribI4iv"));
    oglVertexAttribI4i                     = reinterpret_cast<PFNGLVERTEXATTRIBI4IPROC>(loader("glVertexAttribI4i"));
    oglVertexAttribI4sv                    = reinterpret_cast<PFNGLVERTEXATTRIBI4SVPROC>(loader("glVertexAttribI4sv"));
    oglVertexAttribI4ubv                   = reinterpret_cast<PFNGLVERTEXATTRIBI4UBVPROC>(loader("glVertexAttribI4ubv"));
    oglVertexAttribI4uiv                   = reinterpret_cast<PFNGLVERTEXATTRIBI4UIVPROC>(loader("glVertexAttribI4uiv"));
    oglVertexAttribI4ui                    = reinterpret_cast<PFNGLVERTEXATTRIBI4UIPROC>(loader("glVertexAttribI4ui"));
    oglVertexAttribI4usv                   = reinterpret_cast<PFNGLVERTEXATTRIBI4USVPROC>(loader("glVertexAttribI4usv"));
    oglVertexAttribIPointer                = reinterpret_cast<PFNGLVERTEXATTRIBIPOINTERPROC>(loader("glVertexAttribIPointer"));
}

} // namespace glr
} // namespace xg

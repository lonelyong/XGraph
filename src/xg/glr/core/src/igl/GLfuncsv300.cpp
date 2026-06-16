#include <xg/glr/igl/GLfuncsv300.h>

namespace xg {
namespace glr {


GLfuncsv300::GLfuncsv300()
  : iglBeginConditionalRender(nullptr)
  , iglBeginTransformFeedback(nullptr)
  , iglBindBufferBase(nullptr)
  , iglBindBufferRange(nullptr)
  , iglBindFragDataLocation(nullptr)
  , iglBindFramebuffer(nullptr)
  , iglBindRenderbuffer(nullptr)
  , iglBindVertexArray(nullptr)
  , iglBlitFramebuffer(nullptr)
  , iglCheckFramebufferStatus(nullptr)
  , iglClampColor(nullptr)
  , iglClearBufferfi(nullptr)
  , iglClearBufferfv(nullptr)
  , iglClearBufferiv(nullptr)
  , iglClearBufferuiv(nullptr)
  , iglColorMaski(nullptr)
  , iglDeleteFramebuffers(nullptr)
  , iglDeleteRenderbuffers(nullptr)
  , iglDeleteVertexArrays(nullptr)
  , iglDisablei(nullptr)
  , iglEnablei(nullptr)
  , iglEndConditionalRender(nullptr)
  , iglEndTransformFeedback(nullptr)
  , iglFlushMappedBufferRange(nullptr)
  , iglFramebufferRenderbuffer(nullptr)
  , iglFramebufferTexture1D(nullptr)
  , iglFramebufferTexture2D(nullptr)
  , iglFramebufferTexture3D(nullptr)
  , iglFramebufferTextureLayer(nullptr)
  , iglGenFramebuffers(nullptr)
  , iglGenRenderbuffers(nullptr)
  , iglGenVertexArrays(nullptr)
  , iglGenerateMipmap(nullptr)
  , iglGetBooleani_v(nullptr)
  , iglGetFragDataLocation(nullptr)
  , iglGetFramebufferAttachmentParameteriv(nullptr)
  , iglGetIntegeri_v(nullptr)
  , iglGetRenderbufferParameteriv(nullptr)
  , iglGetStringi(nullptr)
  , iglGetTexParameterIiv(nullptr)
  , iglGetTexParameterIuiv(nullptr)
  , iglGetTransformFeedbackVarying(nullptr)
  , iglGetUniformuiv(nullptr)
  , iglGetVertexAttribIiv(nullptr)
  , iglGetVertexAttribIuiv(nullptr)
  , iglIsEnabledi(nullptr)
  , iglIsFramebuffer(nullptr)
  , iglIsRenderbuffer(nullptr)
  , iglIsVertexArray(nullptr)
  , iglMapBufferRange(nullptr)
  , iglRenderbufferStorageMultisample(nullptr)
  , iglRenderbufferStorage(nullptr)
  , iglTexParameterIiv(nullptr)
  , iglTexParameterIuiv(nullptr)
  , iglTransformFeedbackVaryings(nullptr)
  , iglUniform1uiv(nullptr)
  , iglUniform1ui(nullptr)
  , iglUniform2uiv(nullptr)
  , iglUniform2ui(nullptr)
  , iglUniform3uiv(nullptr)
  , iglUniform3ui(nullptr)
  , iglUniform4uiv(nullptr)
  , iglUniform4ui(nullptr)
  , iglVertexAttribI1iv(nullptr)
  , iglVertexAttribI1i(nullptr)
  , iglVertexAttribI1uiv(nullptr)
  , iglVertexAttribI1ui(nullptr)
  , iglVertexAttribI2iv(nullptr)
  , iglVertexAttribI2i(nullptr)
  , iglVertexAttribI2uiv(nullptr)
  , iglVertexAttribI2ui(nullptr)
  , iglVertexAttribI3iv(nullptr)
  , iglVertexAttribI3i(nullptr)
  , iglVertexAttribI3uiv(nullptr)
  , iglVertexAttribI3ui(nullptr)
  , iglVertexAttribI4bv(nullptr)
  , iglVertexAttribI4iv(nullptr)
  , iglVertexAttribI4i(nullptr)
  , iglVertexAttribI4sv(nullptr)
  , iglVertexAttribI4ubv(nullptr)
  , iglVertexAttribI4uiv(nullptr)
  , iglVertexAttribI4ui(nullptr)
  , iglVertexAttribI4usv(nullptr)
  , iglVertexAttribIPointer(nullptr) {
}

void GLfuncsv300::loadFuncs(Loader loader) {
    GLfuncsv210::loadFuncs(loader);
    iglBeginConditionalRender  = reinterpret_cast<PFNGLBEGINCONDITIONALRENDERPROC>(loader("glBeginConditionalRender"));
    iglBeginTransformFeedback  = reinterpret_cast<PFNGLBEGINTRANSFORMFEEDBACKPROC>(loader("glBeginTransformFeedback"));
    iglBindBufferBase          = reinterpret_cast<PFNGLBINDBUFFERBASEPROC>(loader("glBindBufferBase"));
    iglBindBufferRange         = reinterpret_cast<PFNGLBINDBUFFERRANGEPROC>(loader("glBindBufferRange"));
    iglBindFragDataLocation    = reinterpret_cast<PFNGLBINDFRAGDATALOCATIONPROC>(loader("glBindFragDataLocation"));
    iglBindFramebuffer         = reinterpret_cast<PFNGLBINDFRAMEBUFFERPROC>(loader("glBindFramebuffer"));
    iglBindRenderbuffer        = reinterpret_cast<PFNGLBINDRENDERBUFFERPROC>(loader("glBindRenderbuffer"));
    iglBindVertexArray         = reinterpret_cast<PFNGLBINDVERTEXARRAYPROC>(loader("glBindVertexArray"));
    iglBlitFramebuffer         = reinterpret_cast<PFNGLBLITFRAMEBUFFERPROC>(loader("glBlitFramebuffer"));
    iglCheckFramebufferStatus  = reinterpret_cast<PFNGLCHECKFRAMEBUFFERSTATUSPROC>(loader("glCheckFramebufferStatus"));
    iglClampColor              = reinterpret_cast<PFNGLCLAMPCOLORPROC>(loader("glClampColor"));
    iglClearBufferfi           = reinterpret_cast<PFNGLCLEARBUFFERFIPROC>(loader("glClearBufferfi"));
    iglClearBufferfv           = reinterpret_cast<PFNGLCLEARBUFFERFVPROC>(loader("glClearBufferfv"));
    iglClearBufferiv           = reinterpret_cast<PFNGLCLEARBUFFERIVPROC>(loader("glClearBufferiv"));
    iglClearBufferuiv          = reinterpret_cast<PFNGLCLEARBUFFERUIVPROC>(loader("glClearBufferuiv"));
    iglColorMaski              = reinterpret_cast<PFNGLCOLORMASKIPROC>(loader("glColorMaski"));
    iglDeleteFramebuffers      = reinterpret_cast<PFNGLDELETEFRAMEBUFFERSPROC>(loader("glDeleteFramebuffers"));
    iglDeleteRenderbuffers     = reinterpret_cast<PFNGLDELETERENDERBUFFERSPROC>(loader("glDeleteRenderbuffers"));
    iglDeleteVertexArrays      = reinterpret_cast<PFNGLDELETEVERTEXARRAYSPROC>(loader("glDeleteVertexArrays"));
    iglDisablei                = reinterpret_cast<PFNGLDISABLEIPROC>(loader("glDisablei"));
    iglEnablei                 = reinterpret_cast<PFNGLENABLEIPROC>(loader("glEnablei"));
    iglEndConditionalRender    = reinterpret_cast<PFNGLENDCONDITIONALRENDERPROC>(loader("glEndConditionalRender"));
    iglEndTransformFeedback    = reinterpret_cast<PFNGLENDTRANSFORMFEEDBACKPROC>(loader("glEndTransformFeedback"));
    iglFlushMappedBufferRange  = reinterpret_cast<PFNGLFLUSHMAPPEDBUFFERRANGEPROC>(loader("glFlushMappedBufferRange"));
    iglFramebufferRenderbuffer = reinterpret_cast<PFNGLFRAMEBUFFERRENDERBUFFERPROC>(loader("glFramebufferRenderbuffer"));
    iglFramebufferTexture1D    = reinterpret_cast<PFNGLFRAMEBUFFERTEXTURE1DPROC>(loader("glFramebufferTexture1D"));
    iglFramebufferTexture2D    = reinterpret_cast<PFNGLFRAMEBUFFERTEXTURE2DPROC>(loader("glFramebufferTexture2D"));
    iglFramebufferTexture3D    = reinterpret_cast<PFNGLFRAMEBUFFERTEXTURE3DPROC>(loader("glFramebufferTexture3D"));
    iglFramebufferTextureLayer = reinterpret_cast<PFNGLFRAMEBUFFERTEXTURELAYERPROC>(loader("glFramebufferTextureLayer"));
    iglGenFramebuffers         = reinterpret_cast<PFNGLGENFRAMEBUFFERSPROC>(loader("glGenFramebuffers"));
    iglGenRenderbuffers        = reinterpret_cast<PFNGLGENRENDERBUFFERSPROC>(loader("glGenRenderbuffers"));
    iglGenVertexArrays         = reinterpret_cast<PFNGLGENVERTEXARRAYSPROC>(loader("glGenVertexArrays"));
    iglGenerateMipmap          = reinterpret_cast<PFNGLGENERATEMIPMAPPROC>(loader("glGenerateMipmap"));
    iglGetBooleani_v           = reinterpret_cast<PFNGLGETBOOLEANI_VPROC>(loader("glGetBooleani_v"));
    iglGetFragDataLocation     = reinterpret_cast<PFNGLGETFRAGDATALOCATIONPROC>(loader("glGetFragDataLocation"));
    iglGetFramebufferAttachmentParameteriv =
        reinterpret_cast<PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC>(loader("glGetFramebufferAttachmentParameteriv"));
    iglGetIntegeri_v = reinterpret_cast<PFNGLGETINTEGERI_VPROC>(loader("glGetIntegeri_v"));
    iglGetRenderbufferParameteriv =
        reinterpret_cast<PFNGLGETRENDERBUFFERPARAMETERIVPROC>(loader("glGetRenderbufferParameteriv"));
    iglGetStringi          = reinterpret_cast<PFNGLGETSTRINGIPROC>(loader("glGetStringi"));
    iglGetTexParameterIiv  = reinterpret_cast<PFNGLGETTEXPARAMETERIIVPROC>(loader("glGetTexParameterIiv"));
    iglGetTexParameterIuiv = reinterpret_cast<PFNGLGETTEXPARAMETERIUIVPROC>(loader("glGetTexParameterIuiv"));
    iglGetTransformFeedbackVarying =
        reinterpret_cast<PFNGLGETTRANSFORMFEEDBACKVARYINGPROC>(loader("glGetTransformFeedbackVarying"));
    iglGetUniformuiv       = reinterpret_cast<PFNGLGETUNIFORMUIVPROC>(loader("glGetUniformuiv"));
    iglGetVertexAttribIiv  = reinterpret_cast<PFNGLGETVERTEXATTRIBIIVPROC>(loader("glGetVertexAttribIiv"));
    iglGetVertexAttribIuiv = reinterpret_cast<PFNGLGETVERTEXATTRIBIUIVPROC>(loader("glGetVertexAttribIuiv"));
    iglIsEnabledi          = reinterpret_cast<PFNGLISENABLEDIPROC>(loader("glIsEnabledi"));
    iglIsFramebuffer       = reinterpret_cast<PFNGLISFRAMEBUFFERPROC>(loader("glIsFramebuffer"));
    iglIsRenderbuffer      = reinterpret_cast<PFNGLISRENDERBUFFERPROC>(loader("glIsRenderbuffer"));
    iglIsVertexArray       = reinterpret_cast<PFNGLISVERTEXARRAYPROC>(loader("glIsVertexArray"));
    iglMapBufferRange      = reinterpret_cast<PFNGLMAPBUFFERRANGEPROC>(loader("glMapBufferRange"));
    iglRenderbufferStorageMultisample =
        reinterpret_cast<PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC>(loader("glRenderbufferStorageMultisample"));
    iglRenderbufferStorage = reinterpret_cast<PFNGLRENDERBUFFERSTORAGEPROC>(loader("glRenderbufferStorage"));
    iglTexParameterIiv     = reinterpret_cast<PFNGLTEXPARAMETERIIVPROC>(loader("glTexParameterIiv"));
    iglTexParameterIuiv    = reinterpret_cast<PFNGLTEXPARAMETERIUIVPROC>(loader("glTexParameterIuiv"));
    iglTransformFeedbackVaryings =
        reinterpret_cast<PFNGLTRANSFORMFEEDBACKVARYINGSPROC>(loader("glTransformFeedbackVaryings"));
    iglUniform1uiv          = reinterpret_cast<PFNGLUNIFORM1UIVPROC>(loader("glUniform1uiv"));
    iglUniform1ui           = reinterpret_cast<PFNGLUNIFORM1UIPROC>(loader("glUniform1ui"));
    iglUniform2uiv          = reinterpret_cast<PFNGLUNIFORM2UIVPROC>(loader("glUniform2uiv"));
    iglUniform2ui           = reinterpret_cast<PFNGLUNIFORM2UIPROC>(loader("glUniform2ui"));
    iglUniform3uiv          = reinterpret_cast<PFNGLUNIFORM3UIVPROC>(loader("glUniform3uiv"));
    iglUniform3ui           = reinterpret_cast<PFNGLUNIFORM3UIPROC>(loader("glUniform3ui"));
    iglUniform4uiv          = reinterpret_cast<PFNGLUNIFORM4UIVPROC>(loader("glUniform4uiv"));
    iglUniform4ui           = reinterpret_cast<PFNGLUNIFORM4UIPROC>(loader("glUniform4ui"));
    iglVertexAttribI1iv     = reinterpret_cast<PFNGLVERTEXATTRIBI1IVPROC>(loader("glVertexAttribI1iv"));
    iglVertexAttribI1i      = reinterpret_cast<PFNGLVERTEXATTRIBI1IPROC>(loader("glVertexAttribI1i"));
    iglVertexAttribI1uiv    = reinterpret_cast<PFNGLVERTEXATTRIBI1UIVPROC>(loader("glVertexAttribI1uiv"));
    iglVertexAttribI1ui     = reinterpret_cast<PFNGLVERTEXATTRIBI1UIPROC>(loader("glVertexAttribI1ui"));
    iglVertexAttribI2iv     = reinterpret_cast<PFNGLVERTEXATTRIBI2IVPROC>(loader("glVertexAttribI2iv"));
    iglVertexAttribI2i      = reinterpret_cast<PFNGLVERTEXATTRIBI2IPROC>(loader("glVertexAttribI2i"));
    iglVertexAttribI2uiv    = reinterpret_cast<PFNGLVERTEXATTRIBI2UIVPROC>(loader("glVertexAttribI2uiv"));
    iglVertexAttribI2ui     = reinterpret_cast<PFNGLVERTEXATTRIBI2UIPROC>(loader("glVertexAttribI2ui"));
    iglVertexAttribI3iv     = reinterpret_cast<PFNGLVERTEXATTRIBI3IVPROC>(loader("glVertexAttribI3iv"));
    iglVertexAttribI3i      = reinterpret_cast<PFNGLVERTEXATTRIBI3IPROC>(loader("glVertexAttribI3i"));
    iglVertexAttribI3uiv    = reinterpret_cast<PFNGLVERTEXATTRIBI3UIVPROC>(loader("glVertexAttribI3uiv"));
    iglVertexAttribI3ui     = reinterpret_cast<PFNGLVERTEXATTRIBI3UIPROC>(loader("glVertexAttribI3ui"));
    iglVertexAttribI4bv     = reinterpret_cast<PFNGLVERTEXATTRIBI4BVPROC>(loader("glVertexAttribI4bv"));
    iglVertexAttribI4iv     = reinterpret_cast<PFNGLVERTEXATTRIBI4IVPROC>(loader("glVertexAttribI4iv"));
    iglVertexAttribI4i      = reinterpret_cast<PFNGLVERTEXATTRIBI4IPROC>(loader("glVertexAttribI4i"));
    iglVertexAttribI4sv     = reinterpret_cast<PFNGLVERTEXATTRIBI4SVPROC>(loader("glVertexAttribI4sv"));
    iglVertexAttribI4ubv    = reinterpret_cast<PFNGLVERTEXATTRIBI4UBVPROC>(loader("glVertexAttribI4ubv"));
    iglVertexAttribI4uiv    = reinterpret_cast<PFNGLVERTEXATTRIBI4UIVPROC>(loader("glVertexAttribI4uiv"));
    iglVertexAttribI4ui     = reinterpret_cast<PFNGLVERTEXATTRIBI4UIPROC>(loader("glVertexAttribI4ui"));
    iglVertexAttribI4usv    = reinterpret_cast<PFNGLVERTEXATTRIBI4USVPROC>(loader("glVertexAttribI4usv"));
    iglVertexAttribIPointer = reinterpret_cast<PFNGLVERTEXATTRIBIPOINTERPROC>(loader("glVertexAttribIPointer"));
}

} // namespace glr
} // namespace xg


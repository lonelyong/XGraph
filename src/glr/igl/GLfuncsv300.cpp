#include "GLfuncsv300.h"

namespace glr {

GLfuncsv300::GLfuncsv300()
  : glBeginConditionalRender(nullptr)
  , glBeginTransformFeedback(nullptr)
  , glBindBufferBase(nullptr)
  , glBindBufferRange(nullptr)
  , glBindFragDataLocation(nullptr)
  , glBindFramebuffer(nullptr)
  , glBindRenderbuffer(nullptr)
  , glBindVertexArray(nullptr)
  , glBlitFramebuffer(nullptr)
  , glCheckFramebufferStatus(nullptr)
  , glClampColor(nullptr)
  , glClearBufferfi(nullptr)
  , glClearBufferfv(nullptr)
  , glClearBufferiv(nullptr)
  , glClearBufferuiv(nullptr)
  , glColorMaski(nullptr)
  , glDeleteFramebuffers(nullptr)
  , glDeleteRenderbuffers(nullptr)
  , glDeleteVertexArrays(nullptr)
  , glDisablei(nullptr)
  , glEnablei(nullptr)
  , glEndConditionalRender(nullptr)
  , glEndTransformFeedback(nullptr)
  , glFlushMappedBufferRange(nullptr)
  , glFramebufferRenderbuffer(nullptr)
  , glFramebufferTexture1D(nullptr)
  , glFramebufferTexture2D(nullptr)
  , glFramebufferTexture3D(nullptr)
  , glFramebufferTextureLayer(nullptr)
  , glGenFramebuffers(nullptr)
  , glGenRenderbuffers(nullptr)
  , glGenVertexArrays(nullptr)
  , glGenerateMipmap(nullptr)
  , glGetBooleani_v(nullptr)
  , glGetFragDataLocation(nullptr)
  , glGetFramebufferAttachmentParameteriv(nullptr)
  , glGetIntegeri_v(nullptr)
  , glGetRenderbufferParameteriv(nullptr)
  , glGetStringi(nullptr)
  , glGetTexParameterIiv(nullptr)
  , glGetTexParameterIuiv(nullptr)
  , glGetTransformFeedbackVarying(nullptr)
  , glGetUniformuiv(nullptr)
  , glGetVertexAttribIiv(nullptr)
  , glGetVertexAttribIuiv(nullptr)
  , glIsEnabledi(nullptr)
  , glIsFramebuffer(nullptr)
  , glIsRenderbuffer(nullptr)
  , glIsVertexArray(nullptr)
  , glMapBufferRange(nullptr)
  , glRenderbufferStorageMultisample(nullptr)
  , glRenderbufferStorage(nullptr)
  , glTexParameterIiv(nullptr)
  , glTexParameterIuiv(nullptr)
  , glTransformFeedbackVaryings(nullptr)
  , glUniform1uiv(nullptr)
  , glUniform1ui(nullptr)
  , glUniform2uiv(nullptr)
  , glUniform2ui(nullptr)
  , glUniform3uiv(nullptr)
  , glUniform3ui(nullptr)
  , glUniform4uiv(nullptr)
  , glUniform4ui(nullptr)
  , glVertexAttribI1iv(nullptr)
  , glVertexAttribI1i(nullptr)
  , glVertexAttribI1uiv(nullptr)
  , glVertexAttribI1ui(nullptr)
  , glVertexAttribI2iv(nullptr)
  , glVertexAttribI2i(nullptr)
  , glVertexAttribI2uiv(nullptr)
  , glVertexAttribI2ui(nullptr)
  , glVertexAttribI3iv(nullptr)
  , glVertexAttribI3i(nullptr)
  , glVertexAttribI3uiv(nullptr)
  , glVertexAttribI3ui(nullptr)
  , glVertexAttribI4bv(nullptr)
  , glVertexAttribI4iv(nullptr)
  , glVertexAttribI4i(nullptr)
  , glVertexAttribI4sv(nullptr)
  , glVertexAttribI4ubv(nullptr)
  , glVertexAttribI4uiv(nullptr)
  , glVertexAttribI4ui(nullptr)
  , glVertexAttribI4usv(nullptr)
  , glVertexAttribIPointer(nullptr) {
}

void GLfuncsv300::loadFuncs(Loader loader) {
    glBeginConditionalRender  = reinterpret_cast<PFNGLBEGINCONDITIONALRENDERPROC>(loader("glBeginConditionalRender"));
    glBeginTransformFeedback  = reinterpret_cast<PFNGLBEGINTRANSFORMFEEDBACKPROC>(loader("glBeginTransformFeedback"));
    glBindBufferBase          = reinterpret_cast<PFNGLBINDBUFFERBASEPROC>(loader("glBindBufferBase"));
    glBindBufferRange         = reinterpret_cast<PFNGLBINDBUFFERRANGEPROC>(loader("glBindBufferRange"));
    glBindFragDataLocation    = reinterpret_cast<PFNGLBINDFRAGDATALOCATIONPROC>(loader("glBindFragDataLocation"));
    glBindFramebuffer         = reinterpret_cast<PFNGLBINDFRAMEBUFFERPROC>(loader("glBindFramebuffer"));
    glBindRenderbuffer        = reinterpret_cast<PFNGLBINDRENDERBUFFERPROC>(loader("glBindRenderbuffer"));
    glBindVertexArray         = reinterpret_cast<PFNGLBINDVERTEXARRAYPROC>(loader("glBindVertexArray"));
    glBlitFramebuffer         = reinterpret_cast<PFNGLBLITFRAMEBUFFERPROC>(loader("glBlitFramebuffer"));
    glCheckFramebufferStatus  = reinterpret_cast<PFNGLCHECKFRAMEBUFFERSTATUSPROC>(loader("glCheckFramebufferStatus"));
    glClampColor              = reinterpret_cast<PFNGLCLAMPCOLORPROC>(loader("glClampColor"));
    glClearBufferfi           = reinterpret_cast<PFNGLCLEARBUFFERFIPROC>(loader("glClearBufferfi"));
    glClearBufferfv           = reinterpret_cast<PFNGLCLEARBUFFERFVPROC>(loader("glClearBufferfv"));
    glClearBufferiv           = reinterpret_cast<PFNGLCLEARBUFFERIVPROC>(loader("glClearBufferiv"));
    glClearBufferuiv          = reinterpret_cast<PFNGLCLEARBUFFERUIVPROC>(loader("glClearBufferuiv"));
    glColorMaski              = reinterpret_cast<PFNGLCOLORMASKIPROC>(loader("glColorMaski"));
    glDeleteFramebuffers      = reinterpret_cast<PFNGLDELETEFRAMEBUFFERSPROC>(loader("glDeleteFramebuffers"));
    glDeleteRenderbuffers     = reinterpret_cast<PFNGLDELETERENDERBUFFERSPROC>(loader("glDeleteRenderbuffers"));
    glDeleteVertexArrays      = reinterpret_cast<PFNGLDELETEVERTEXARRAYSPROC>(loader("glDeleteVertexArrays"));
    glDisablei                = reinterpret_cast<PFNGLDISABLEIPROC>(loader("glDisablei"));
    glEnablei                 = reinterpret_cast<PFNGLENABLEIPROC>(loader("glEnablei"));
    glEndConditionalRender    = reinterpret_cast<PFNGLENDCONDITIONALRENDERPROC>(loader("glEndConditionalRender"));
    glEndTransformFeedback    = reinterpret_cast<PFNGLENDTRANSFORMFEEDBACKPROC>(loader("glEndTransformFeedback"));
    glFlushMappedBufferRange  = reinterpret_cast<PFNGLFLUSHMAPPEDBUFFERRANGEPROC>(loader("glFlushMappedBufferRange"));
    glFramebufferRenderbuffer = reinterpret_cast<PFNGLFRAMEBUFFERRENDERBUFFERPROC>(loader("glFramebufferRenderbuffer"));
    glFramebufferTexture1D    = reinterpret_cast<PFNGLFRAMEBUFFERTEXTURE1DPROC>(loader("glFramebufferTexture1D"));
    glFramebufferTexture2D    = reinterpret_cast<PFNGLFRAMEBUFFERTEXTURE2DPROC>(loader("glFramebufferTexture2D"));
    glFramebufferTexture3D    = reinterpret_cast<PFNGLFRAMEBUFFERTEXTURE3DPROC>(loader("glFramebufferTexture3D"));
    glFramebufferTextureLayer = reinterpret_cast<PFNGLFRAMEBUFFERTEXTURELAYERPROC>(loader("glFramebufferTextureLayer"));
    glGenFramebuffers         = reinterpret_cast<PFNGLGENFRAMEBUFFERSPROC>(loader("glGenFramebuffers"));
    glGenRenderbuffers        = reinterpret_cast<PFNGLGENRENDERBUFFERSPROC>(loader("glGenRenderbuffers"));
    glGenVertexArrays         = reinterpret_cast<PFNGLGENVERTEXARRAYSPROC>(loader("glGenVertexArrays"));
    glGenerateMipmap          = reinterpret_cast<PFNGLGENERATEMIPMAPPROC>(loader("glGenerateMipmap"));
    glGetBooleani_v           = reinterpret_cast<PFNGLGETBOOLEANI_VPROC>(loader("glGetBooleani_v"));
    glGetFragDataLocation     = reinterpret_cast<PFNGLGETFRAGDATALOCATIONPROC>(loader("glGetFragDataLocation"));
    glGetFramebufferAttachmentParameteriv =
        reinterpret_cast<PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC>(loader("glGetFramebufferAttachmentParameteriv"));
    glGetIntegeri_v = reinterpret_cast<PFNGLGETINTEGERI_VPROC>(loader("glGetIntegeri_v"));
    glGetRenderbufferParameteriv =
        reinterpret_cast<PFNGLGETRENDERBUFFERPARAMETERIVPROC>(loader("glGetRenderbufferParameteriv"));
    glGetStringi          = reinterpret_cast<PFNGLGETSTRINGIPROC>(loader("glGetStringi"));
    glGetTexParameterIiv  = reinterpret_cast<PFNGLGETTEXPARAMETERIIVPROC>(loader("glGetTexParameterIiv"));
    glGetTexParameterIuiv = reinterpret_cast<PFNGLGETTEXPARAMETERIUIVPROC>(loader("glGetTexParameterIuiv"));
    glGetTransformFeedbackVarying =
        reinterpret_cast<PFNGLGETTRANSFORMFEEDBACKVARYINGPROC>(loader("glGetTransformFeedbackVarying"));
    glGetUniformuiv       = reinterpret_cast<PFNGLGETUNIFORMUIVPROC>(loader("glGetUniformuiv"));
    glGetVertexAttribIiv  = reinterpret_cast<PFNGLGETVERTEXATTRIBIIVPROC>(loader("glGetVertexAttribIiv"));
    glGetVertexAttribIuiv = reinterpret_cast<PFNGLGETVERTEXATTRIBIUIVPROC>(loader("glGetVertexAttribIuiv"));
    glIsEnabledi          = reinterpret_cast<PFNGLISENABLEDIPROC>(loader("glIsEnabledi"));
    glIsFramebuffer       = reinterpret_cast<PFNGLISFRAMEBUFFERPROC>(loader("glIsFramebuffer"));
    glIsRenderbuffer      = reinterpret_cast<PFNGLISRENDERBUFFERPROC>(loader("glIsRenderbuffer"));
    glIsVertexArray       = reinterpret_cast<PFNGLISVERTEXARRAYPROC>(loader("glIsVertexArray"));
    glMapBufferRange      = reinterpret_cast<PFNGLMAPBUFFERRANGEPROC>(loader("glMapBufferRange"));
    glRenderbufferStorageMultisample =
        reinterpret_cast<PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC>(loader("glRenderbufferStorageMultisample"));
    glRenderbufferStorage = reinterpret_cast<PFNGLRENDERBUFFERSTORAGEPROC>(loader("glRenderbufferStorage"));
    glTexParameterIiv     = reinterpret_cast<PFNGLTEXPARAMETERIIVPROC>(loader("glTexParameterIiv"));
    glTexParameterIuiv    = reinterpret_cast<PFNGLTEXPARAMETERIUIVPROC>(loader("glTexParameterIuiv"));
    glTransformFeedbackVaryings =
        reinterpret_cast<PFNGLTRANSFORMFEEDBACKVARYINGSPROC>(loader("glTransformFeedbackVaryings"));
    glUniform1uiv          = reinterpret_cast<PFNGLUNIFORM1UIVPROC>(loader("glUniform1uiv"));
    glUniform1ui           = reinterpret_cast<PFNGLUNIFORM1UIPROC>(loader("glUniform1ui"));
    glUniform2uiv          = reinterpret_cast<PFNGLUNIFORM2UIVPROC>(loader("glUniform2uiv"));
    glUniform2ui           = reinterpret_cast<PFNGLUNIFORM2UIPROC>(loader("glUniform2ui"));
    glUniform3uiv          = reinterpret_cast<PFNGLUNIFORM3UIVPROC>(loader("glUniform3uiv"));
    glUniform3ui           = reinterpret_cast<PFNGLUNIFORM3UIPROC>(loader("glUniform3ui"));
    glUniform4uiv          = reinterpret_cast<PFNGLUNIFORM4UIVPROC>(loader("glUniform4uiv"));
    glUniform4ui           = reinterpret_cast<PFNGLUNIFORM4UIPROC>(loader("glUniform4ui"));
    glVertexAttribI1iv     = reinterpret_cast<PFNGLVERTEXATTRIBI1IVPROC>(loader("glVertexAttribI1iv"));
    glVertexAttribI1i      = reinterpret_cast<PFNGLVERTEXATTRIBI1IPROC>(loader("glVertexAttribI1i"));
    glVertexAttribI1uiv    = reinterpret_cast<PFNGLVERTEXATTRIBI1UIVPROC>(loader("glVertexAttribI1uiv"));
    glVertexAttribI1ui     = reinterpret_cast<PFNGLVERTEXATTRIBI1UIPROC>(loader("glVertexAttribI1ui"));
    glVertexAttribI2iv     = reinterpret_cast<PFNGLVERTEXATTRIBI2IVPROC>(loader("glVertexAttribI2iv"));
    glVertexAttribI2i      = reinterpret_cast<PFNGLVERTEXATTRIBI2IPROC>(loader("glVertexAttribI2i"));
    glVertexAttribI2uiv    = reinterpret_cast<PFNGLVERTEXATTRIBI2UIVPROC>(loader("glVertexAttribI2uiv"));
    glVertexAttribI2ui     = reinterpret_cast<PFNGLVERTEXATTRIBI2UIPROC>(loader("glVertexAttribI2ui"));
    glVertexAttribI3iv     = reinterpret_cast<PFNGLVERTEXATTRIBI3IVPROC>(loader("glVertexAttribI3iv"));
    glVertexAttribI3i      = reinterpret_cast<PFNGLVERTEXATTRIBI3IPROC>(loader("glVertexAttribI3i"));
    glVertexAttribI3uiv    = reinterpret_cast<PFNGLVERTEXATTRIBI3UIVPROC>(loader("glVertexAttribI3uiv"));
    glVertexAttribI3ui     = reinterpret_cast<PFNGLVERTEXATTRIBI3UIPROC>(loader("glVertexAttribI3ui"));
    glVertexAttribI4bv     = reinterpret_cast<PFNGLVERTEXATTRIBI4BVPROC>(loader("glVertexAttribI4bv"));
    glVertexAttribI4iv     = reinterpret_cast<PFNGLVERTEXATTRIBI4IVPROC>(loader("glVertexAttribI4iv"));
    glVertexAttribI4i      = reinterpret_cast<PFNGLVERTEXATTRIBI4IPROC>(loader("glVertexAttribI4i"));
    glVertexAttribI4sv     = reinterpret_cast<PFNGLVERTEXATTRIBI4SVPROC>(loader("glVertexAttribI4sv"));
    glVertexAttribI4ubv    = reinterpret_cast<PFNGLVERTEXATTRIBI4UBVPROC>(loader("glVertexAttribI4ubv"));
    glVertexAttribI4uiv    = reinterpret_cast<PFNGLVERTEXATTRIBI4UIVPROC>(loader("glVertexAttribI4uiv"));
    glVertexAttribI4ui     = reinterpret_cast<PFNGLVERTEXATTRIBI4UIPROC>(loader("glVertexAttribI4ui"));
    glVertexAttribI4usv    = reinterpret_cast<PFNGLVERTEXATTRIBI4USVPROC>(loader("glVertexAttribI4usv"));
    glVertexAttribIPointer = reinterpret_cast<PFNGLVERTEXATTRIBIPOINTERPROC>(loader("glVertexAttribIPointer"));
}

}


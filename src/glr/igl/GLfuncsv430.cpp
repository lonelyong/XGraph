#include "GLfuncsv430.h"

namespace glr {

VI_OBJECT_META_IMPL(GLfuncsv430, GLfuncsv420);

GLfuncsv430::GLfuncsv430()
  : glBindVertexBuffer(nullptr)
  , glClearBufferData(nullptr)
  , glClearBufferSubData(nullptr)
  , glCopyImageSubData(nullptr)
  , glDebugMessageCallback(nullptr)
  , glDebugMessageControl(nullptr)
  , glDebugMessageInsert(nullptr)
  , glDispatchComputeIndirect(nullptr)
  , glDispatchCompute(nullptr)
  , glFramebufferParameteri(nullptr)
  , glGetDebugMessageLog(nullptr)
  , glGetFramebufferParameteriv(nullptr)
  , glGetInternalformati64v(nullptr)
  , glGetObjectLabel(nullptr)
  , glGetObjectPtrLabel(nullptr)
  , glGetPointerv(nullptr)
  , glGetProgramInterfaceiv(nullptr)
  , glGetProgramResourceIndex(nullptr)
  , glGetProgramResourceLocationIndex(nullptr)
  , glGetProgramResourceLocation(nullptr)
  , glGetProgramResourceName(nullptr)
  , glGetProgramResourceiv(nullptr)
  , glInvalidateBufferData(nullptr)
  , glInvalidateBufferSubData(nullptr)
  , glInvalidateFramebuffer(nullptr)
  , glInvalidateSubFramebuffer(nullptr)
  , glInvalidateTexImage(nullptr)
  , glInvalidateTexSubImage(nullptr)
  , glMultiDrawArraysIndirect(nullptr)
  , glMultiDrawElementsIndirect(nullptr)
  , glObjectLabel(nullptr)
  , glObjectPtrLabel(nullptr)
  , glPopDebugGroup(nullptr)
  , glPushDebugGroup(nullptr)
  , glShaderStorageBlockBinding(nullptr)
  , glTexBufferRange(nullptr)
  , glTexStorage2DMultisample(nullptr)
  , glTexStorage3DMultisample(nullptr)
  , glTextureView(nullptr)
  , glVertexAttribBinding(nullptr)
  , glVertexAttribFormat(nullptr)
  , glVertexAttribIFormat(nullptr)
  , glVertexAttribLFormat(nullptr)
  , glVertexBindingDivisor(nullptr) {
}

void GLfuncsv430::loadFuncs(Loader loader) {
    GLfuncsv420::loadFuncs(loader);
    glBindVertexBuffer        = reinterpret_cast<PFNGLBINDVERTEXBUFFERPROC>(loader("glBindVertexBuffer"));
    glClearBufferData         = reinterpret_cast<PFNGLCLEARBUFFERDATAPROC>(loader("glClearBufferData"));
    glClearBufferSubData      = reinterpret_cast<PFNGLCLEARBUFFERSUBDATAPROC>(loader("glClearBufferSubData"));
    glCopyImageSubData        = reinterpret_cast<PFNGLCOPYIMAGESUBDATAPROC>(loader("glCopyImageSubData"));
    glDebugMessageCallback    = reinterpret_cast<PFNGLDEBUGMESSAGECALLBACKPROC>(loader("glDebugMessageCallback"));
    glDebugMessageControl     = reinterpret_cast<PFNGLDEBUGMESSAGECONTROLPROC>(loader("glDebugMessageControl"));
    glDebugMessageInsert      = reinterpret_cast<PFNGLDEBUGMESSAGEINSERTPROC>(loader("glDebugMessageInsert"));
    glDispatchComputeIndirect = reinterpret_cast<PFNGLDISPATCHCOMPUTEINDIRECTPROC>(loader("glDispatchComputeIndirect"));
    glDispatchCompute         = reinterpret_cast<PFNGLDISPATCHCOMPUTEPROC>(loader("glDispatchCompute"));
    glFramebufferParameteri   = reinterpret_cast<PFNGLFRAMEBUFFERPARAMETERIPROC>(loader("glFramebufferParameteri"));
    glGetDebugMessageLog      = reinterpret_cast<PFNGLGETDEBUGMESSAGELOGPROC>(loader("glGetDebugMessageLog"));
    glGetFramebufferParameteriv =
        reinterpret_cast<PFNGLGETFRAMEBUFFERPARAMETERIVPROC>(loader("glGetFramebufferParameteriv"));
    glGetInternalformati64v   = reinterpret_cast<PFNGLGETINTERNALFORMATI64VPROC>(loader("glGetInternalformati64v"));
    glGetObjectLabel          = reinterpret_cast<PFNGLGETOBJECTLABELPROC>(loader("glGetObjectLabel"));
    glGetObjectPtrLabel       = reinterpret_cast<PFNGLGETOBJECTPTRLABELPROC>(loader("glGetObjectPtrLabel"));
    glGetPointerv             = reinterpret_cast<PFNGLGETPOINTERVPROC>(loader("glGetPointerv"));
    glGetProgramInterfaceiv   = reinterpret_cast<PFNGLGETPROGRAMINTERFACEIVPROC>(loader("glGetProgramInterfaceiv"));
    glGetProgramResourceIndex = reinterpret_cast<PFNGLGETPROGRAMRESOURCEINDEXPROC>(loader("glGetProgramResourceIndex"));
    glGetProgramResourceLocationIndex =
        reinterpret_cast<PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC>(loader("glGetProgramResourceLocationIndex"));
    glGetProgramResourceLocation =
        reinterpret_cast<PFNGLGETPROGRAMRESOURCELOCATIONPROC>(loader("glGetProgramResourceLocation"));
    glGetProgramResourceName  = reinterpret_cast<PFNGLGETPROGRAMRESOURCENAMEPROC>(loader("glGetProgramResourceName"));
    glGetProgramResourceiv    = reinterpret_cast<PFNGLGETPROGRAMRESOURCEIVPROC>(loader("glGetProgramResourceiv"));
    glInvalidateBufferData    = reinterpret_cast<PFNGLINVALIDATEBUFFERDATAPROC>(loader("glInvalidateBufferData"));
    glInvalidateBufferSubData = reinterpret_cast<PFNGLINVALIDATEBUFFERSUBDATAPROC>(loader("glInvalidateBufferSubData"));
    glInvalidateFramebuffer   = reinterpret_cast<PFNGLINVALIDATEFRAMEBUFFERPROC>(loader("glInvalidateFramebuffer"));
    glInvalidateSubFramebuffer =
        reinterpret_cast<PFNGLINVALIDATESUBFRAMEBUFFERPROC>(loader("glInvalidateSubFramebuffer"));
    glInvalidateTexImage      = reinterpret_cast<PFNGLINVALIDATETEXIMAGEPROC>(loader("glInvalidateTexImage"));
    glInvalidateTexSubImage   = reinterpret_cast<PFNGLINVALIDATETEXSUBIMAGEPROC>(loader("glInvalidateTexSubImage"));
    glMultiDrawArraysIndirect = reinterpret_cast<PFNGLMULTIDRAWARRAYSINDIRECTPROC>(loader("glMultiDrawArraysIndirect"));
    glMultiDrawElementsIndirect =
        reinterpret_cast<PFNGLMULTIDRAWELEMENTSINDIRECTPROC>(loader("glMultiDrawElementsIndirect"));
    glObjectLabel    = reinterpret_cast<PFNGLOBJECTLABELPROC>(loader("glObjectLabel"));
    glObjectPtrLabel = reinterpret_cast<PFNGLOBJECTPTRLABELPROC>(loader("glObjectPtrLabel"));
    glPopDebugGroup  = reinterpret_cast<PFNGLPOPDEBUGGROUPPROC>(loader("glPopDebugGroup"));
    glPushDebugGroup = reinterpret_cast<PFNGLPUSHDEBUGGROUPPROC>(loader("glPushDebugGroup"));
    glShaderStorageBlockBinding =
        reinterpret_cast<PFNGLSHADERSTORAGEBLOCKBINDINGPROC>(loader("glShaderStorageBlockBinding"));
    glTexBufferRange          = reinterpret_cast<PFNGLTEXBUFFERRANGEPROC>(loader("glTexBufferRange"));
    glTexStorage2DMultisample = reinterpret_cast<PFNGLTEXSTORAGE2DMULTISAMPLEPROC>(loader("glTexStorage2DMultisample"));
    glTexStorage3DMultisample = reinterpret_cast<PFNGLTEXSTORAGE3DMULTISAMPLEPROC>(loader("glTexStorage3DMultisample"));
    glTextureView             = reinterpret_cast<PFNGLTEXTUREVIEWPROC>(loader("glTextureView"));
    glVertexAttribBinding     = reinterpret_cast<PFNGLVERTEXATTRIBBINDINGPROC>(loader("glVertexAttribBinding"));
    glVertexAttribFormat      = reinterpret_cast<PFNGLVERTEXATTRIBFORMATPROC>(loader("glVertexAttribFormat"));
    glVertexAttribIFormat     = reinterpret_cast<PFNGLVERTEXATTRIBIFORMATPROC>(loader("glVertexAttribIFormat"));
    glVertexAttribLFormat     = reinterpret_cast<PFNGLVERTEXATTRIBLFORMATPROC>(loader("glVertexAttribLFormat"));
    glVertexBindingDivisor    = reinterpret_cast<PFNGLVERTEXBINDINGDIVISORPROC>(loader("glVertexBindingDivisor"));
}
} // namespace glr

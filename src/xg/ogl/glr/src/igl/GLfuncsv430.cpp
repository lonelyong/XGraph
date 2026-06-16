#include "GLfuncsv430.h"

namespace glr {


GLfuncsv430::GLfuncsv430()
  : iglBindVertexBuffer(nullptr)
  , iglClearBufferData(nullptr)
  , iglClearBufferSubData(nullptr)
  , iglCopyImageSubData(nullptr)
  , iglDebugMessageCallback(nullptr)
  , iglDebugMessageControl(nullptr)
  , iglDebugMessageInsert(nullptr)
  , iglDispatchComputeIndirect(nullptr)
  , iglDispatchCompute(nullptr)
  , iglFramebufferParameteri(nullptr)
  , iglGetDebugMessageLog(nullptr)
  , iglGetFramebufferParameteriv(nullptr)
  , iglGetInternalformati64v(nullptr)
  , iglGetObjectLabel(nullptr)
  , iglGetObjectPtrLabel(nullptr)
  , iglGetPointerv(nullptr)
  , iglGetProgramInterfaceiv(nullptr)
  , iglGetProgramResourceIndex(nullptr)
  , iglGetProgramResourceLocationIndex(nullptr)
  , iglGetProgramResourceLocation(nullptr)
  , iglGetProgramResourceName(nullptr)
  , iglGetProgramResourceiv(nullptr)
  , iglInvalidateBufferData(nullptr)
  , iglInvalidateBufferSubData(nullptr)
  , iglInvalidateFramebuffer(nullptr)
  , iglInvalidateSubFramebuffer(nullptr)
  , iglInvalidateTexImage(nullptr)
  , iglInvalidateTexSubImage(nullptr)
  , iglMultiDrawArraysIndirect(nullptr)
  , iglMultiDrawElementsIndirect(nullptr)
  , iglObjectLabel(nullptr)
  , iglObjectPtrLabel(nullptr)
  , iglPopDebugGroup(nullptr)
  , iglPushDebugGroup(nullptr)
  , iglShaderStorageBlockBinding(nullptr)
  , iglTexBufferRange(nullptr)
  , iglTexStorage2DMultisample(nullptr)
  , iglTexStorage3DMultisample(nullptr)
  , iglTextureView(nullptr)
  , iglVertexAttribBinding(nullptr)
  , iglVertexAttribFormat(nullptr)
  , iglVertexAttribIFormat(nullptr)
  , iglVertexAttribLFormat(nullptr)
  , iglVertexBindingDivisor(nullptr) {
}

void GLfuncsv430::loadFuncs(Loader loader) {
    GLfuncsv420::loadFuncs(loader);
    iglBindVertexBuffer        = reinterpret_cast<PFNGLBINDVERTEXBUFFERPROC>(loader("glBindVertexBuffer"));
    iglClearBufferData         = reinterpret_cast<PFNGLCLEARBUFFERDATAPROC>(loader("glClearBufferData"));
    iglClearBufferSubData      = reinterpret_cast<PFNGLCLEARBUFFERSUBDATAPROC>(loader("glClearBufferSubData"));
    iglCopyImageSubData        = reinterpret_cast<PFNGLCOPYIMAGESUBDATAPROC>(loader("glCopyImageSubData"));
    iglDebugMessageCallback    = reinterpret_cast<PFNGLDEBUGMESSAGECALLBACKPROC>(loader("glDebugMessageCallback"));
    iglDebugMessageControl     = reinterpret_cast<PFNGLDEBUGMESSAGECONTROLPROC>(loader("glDebugMessageControl"));
    iglDebugMessageInsert      = reinterpret_cast<PFNGLDEBUGMESSAGEINSERTPROC>(loader("glDebugMessageInsert"));
    iglDispatchComputeIndirect = reinterpret_cast<PFNGLDISPATCHCOMPUTEINDIRECTPROC>(loader("glDispatchComputeIndirect"));
    iglDispatchCompute         = reinterpret_cast<PFNGLDISPATCHCOMPUTEPROC>(loader("glDispatchCompute"));
    iglFramebufferParameteri   = reinterpret_cast<PFNGLFRAMEBUFFERPARAMETERIPROC>(loader("glFramebufferParameteri"));
    iglGetDebugMessageLog      = reinterpret_cast<PFNGLGETDEBUGMESSAGELOGPROC>(loader("glGetDebugMessageLog"));
    iglGetFramebufferParameteriv =
        reinterpret_cast<PFNGLGETFRAMEBUFFERPARAMETERIVPROC>(loader("glGetFramebufferParameteriv"));
    iglGetInternalformati64v   = reinterpret_cast<PFNGLGETINTERNALFORMATI64VPROC>(loader("glGetInternalformati64v"));
    iglGetObjectLabel          = reinterpret_cast<PFNGLGETOBJECTLABELPROC>(loader("glGetObjectLabel"));
    iglGetObjectPtrLabel       = reinterpret_cast<PFNGLGETOBJECTPTRLABELPROC>(loader("glGetObjectPtrLabel"));
    iglGetPointerv             = reinterpret_cast<PFNGLGETPOINTERVPROC>(loader("glGetPointerv"));
    iglGetProgramInterfaceiv   = reinterpret_cast<PFNGLGETPROGRAMINTERFACEIVPROC>(loader("glGetProgramInterfaceiv"));
    iglGetProgramResourceIndex = reinterpret_cast<PFNGLGETPROGRAMRESOURCEINDEXPROC>(loader("glGetProgramResourceIndex"));
    iglGetProgramResourceLocationIndex =
        reinterpret_cast<PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC>(loader("glGetProgramResourceLocationIndex"));
    iglGetProgramResourceLocation =
        reinterpret_cast<PFNGLGETPROGRAMRESOURCELOCATIONPROC>(loader("glGetProgramResourceLocation"));
    iglGetProgramResourceName  = reinterpret_cast<PFNGLGETPROGRAMRESOURCENAMEPROC>(loader("glGetProgramResourceName"));
    iglGetProgramResourceiv    = reinterpret_cast<PFNGLGETPROGRAMRESOURCEIVPROC>(loader("glGetProgramResourceiv"));
    iglInvalidateBufferData    = reinterpret_cast<PFNGLINVALIDATEBUFFERDATAPROC>(loader("glInvalidateBufferData"));
    iglInvalidateBufferSubData = reinterpret_cast<PFNGLINVALIDATEBUFFERSUBDATAPROC>(loader("glInvalidateBufferSubData"));
    iglInvalidateFramebuffer   = reinterpret_cast<PFNGLINVALIDATEFRAMEBUFFERPROC>(loader("glInvalidateFramebuffer"));
    iglInvalidateSubFramebuffer =
        reinterpret_cast<PFNGLINVALIDATESUBFRAMEBUFFERPROC>(loader("glInvalidateSubFramebuffer"));
    iglInvalidateTexImage      = reinterpret_cast<PFNGLINVALIDATETEXIMAGEPROC>(loader("glInvalidateTexImage"));
    iglInvalidateTexSubImage   = reinterpret_cast<PFNGLINVALIDATETEXSUBIMAGEPROC>(loader("glInvalidateTexSubImage"));
    iglMultiDrawArraysIndirect = reinterpret_cast<PFNGLMULTIDRAWARRAYSINDIRECTPROC>(loader("glMultiDrawArraysIndirect"));
    iglMultiDrawElementsIndirect =
        reinterpret_cast<PFNGLMULTIDRAWELEMENTSINDIRECTPROC>(loader("glMultiDrawElementsIndirect"));
    iglObjectLabel    = reinterpret_cast<PFNGLOBJECTLABELPROC>(loader("glObjectLabel"));
    iglObjectPtrLabel = reinterpret_cast<PFNGLOBJECTPTRLABELPROC>(loader("glObjectPtrLabel"));
    iglPopDebugGroup  = reinterpret_cast<PFNGLPOPDEBUGGROUPPROC>(loader("glPopDebugGroup"));
    iglPushDebugGroup = reinterpret_cast<PFNGLPUSHDEBUGGROUPPROC>(loader("glPushDebugGroup"));
    iglShaderStorageBlockBinding =
        reinterpret_cast<PFNGLSHADERSTORAGEBLOCKBINDINGPROC>(loader("glShaderStorageBlockBinding"));
    iglTexBufferRange          = reinterpret_cast<PFNGLTEXBUFFERRANGEPROC>(loader("glTexBufferRange"));
    iglTexStorage2DMultisample = reinterpret_cast<PFNGLTEXSTORAGE2DMULTISAMPLEPROC>(loader("glTexStorage2DMultisample"));
    iglTexStorage3DMultisample = reinterpret_cast<PFNGLTEXSTORAGE3DMULTISAMPLEPROC>(loader("glTexStorage3DMultisample"));
    iglTextureView             = reinterpret_cast<PFNGLTEXTUREVIEWPROC>(loader("glTextureView"));
    iglVertexAttribBinding     = reinterpret_cast<PFNGLVERTEXATTRIBBINDINGPROC>(loader("glVertexAttribBinding"));
    iglVertexAttribFormat      = reinterpret_cast<PFNGLVERTEXATTRIBFORMATPROC>(loader("glVertexAttribFormat"));
    iglVertexAttribIFormat     = reinterpret_cast<PFNGLVERTEXATTRIBIFORMATPROC>(loader("glVertexAttribIFormat"));
    iglVertexAttribLFormat     = reinterpret_cast<PFNGLVERTEXATTRIBLFORMATPROC>(loader("glVertexAttribLFormat"));
    iglVertexBindingDivisor    = reinterpret_cast<PFNGLVERTEXBINDINGDIVISORPROC>(loader("glVertexBindingDivisor"));
}
} // namespace glr

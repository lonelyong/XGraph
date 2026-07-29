#include <xg/igl/ogl/GLfuncsv430.hpp>

namespace xg
{
namespace glr
{


GLfuncsv430::GLfuncsv430()
  : oglBindVertexBuffer(nullptr)
  , oglClearBufferData(nullptr)
  , oglClearBufferSubData(nullptr)
  , oglCopyImageSubData(nullptr)
  , oglDebugMessageCallback(nullptr)
  , oglDebugMessageControl(nullptr)
  , oglDebugMessageInsert(nullptr)
  , oglDispatchComputeIndirect(nullptr)
  , oglDispatchCompute(nullptr)
  , oglFramebufferParameteri(nullptr)
  , oglGetDebugMessageLog(nullptr)
  , oglGetFramebufferParameteriv(nullptr)
  , oglGetInternalformati64v(nullptr)
  , oglGetObjectLabel(nullptr)
  , oglGetObjectPtrLabel(nullptr)
  , oglGetPointerv(nullptr)
  , oglGetProgramInterfaceiv(nullptr)
  , oglGetProgramResourceIndex(nullptr)
  , oglGetProgramResourceLocationIndex(nullptr)
  , oglGetProgramResourceLocation(nullptr)
  , oglGetProgramResourceName(nullptr)
  , oglGetProgramResourceiv(nullptr)
  , oglInvalidateBufferData(nullptr)
  , oglInvalidateBufferSubData(nullptr)
  , oglInvalidateFramebuffer(nullptr)
  , oglInvalidateSubFramebuffer(nullptr)
  , oglInvalidateTexImage(nullptr)
  , oglInvalidateTexSubImage(nullptr)
  , oglMultiDrawArraysIndirect(nullptr)
  , oglMultiDrawElementsIndirect(nullptr)
  , oglObjectLabel(nullptr)
  , oglObjectPtrLabel(nullptr)
  , oglPopDebugGroup(nullptr)
  , oglPushDebugGroup(nullptr)
  , oglShaderStorageBlockBinding(nullptr)
  , oglTexBufferRange(nullptr)
  , oglTexStorage2DMultisample(nullptr)
  , oglTexStorage3DMultisample(nullptr)
  , oglTextureView(nullptr)
  , oglVertexAttribBinding(nullptr)
  , oglVertexAttribFormat(nullptr)
  , oglVertexAttribIFormat(nullptr)
  , oglVertexAttribLFormat(nullptr)
  , oglVertexBindingDivisor(nullptr)
{}

void GLfuncsv430::loadFuncs(Loader loader)
{
    GLfuncsv420::loadFuncs(loader);
    oglBindVertexBuffer                = reinterpret_cast<PFNGLBINDVERTEXBUFFERPROC>(loader("glBindVertexBuffer"));
    oglClearBufferData                 = reinterpret_cast<PFNGLCLEARBUFFERDATAPROC>(loader("glClearBufferData"));
    oglClearBufferSubData              = reinterpret_cast<PFNGLCLEARBUFFERSUBDATAPROC>(loader("glClearBufferSubData"));
    oglCopyImageSubData                = reinterpret_cast<PFNGLCOPYIMAGESUBDATAPROC>(loader("glCopyImageSubData"));
    oglDebugMessageCallback            = reinterpret_cast<PFNGLDEBUGMESSAGECALLBACKPROC>(loader("glDebugMessageCallback"));
    oglDebugMessageControl             = reinterpret_cast<PFNGLDEBUGMESSAGECONTROLPROC>(loader("glDebugMessageControl"));
    oglDebugMessageInsert              = reinterpret_cast<PFNGLDEBUGMESSAGEINSERTPROC>(loader("glDebugMessageInsert"));
    oglDispatchComputeIndirect         = reinterpret_cast<PFNGLDISPATCHCOMPUTEINDIRECTPROC>(loader("glDispatchComputeIndirect"));
    oglDispatchCompute                 = reinterpret_cast<PFNGLDISPATCHCOMPUTEPROC>(loader("glDispatchCompute"));
    oglFramebufferParameteri           = reinterpret_cast<PFNGLFRAMEBUFFERPARAMETERIPROC>(loader("glFramebufferParameteri"));
    oglGetDebugMessageLog              = reinterpret_cast<PFNGLGETDEBUGMESSAGELOGPROC>(loader("glGetDebugMessageLog"));
    oglGetFramebufferParameteriv       = reinterpret_cast<PFNGLGETFRAMEBUFFERPARAMETERIVPROC>(loader("glGetFramebufferParameteriv"));
    oglGetInternalformati64v           = reinterpret_cast<PFNGLGETINTERNALFORMATI64VPROC>(loader("glGetInternalformati64v"));
    oglGetObjectLabel                  = reinterpret_cast<PFNGLGETOBJECTLABELPROC>(loader("glGetObjectLabel"));
    oglGetObjectPtrLabel               = reinterpret_cast<PFNGLGETOBJECTPTRLABELPROC>(loader("glGetObjectPtrLabel"));
    oglGetPointerv                     = reinterpret_cast<PFNGLGETPOINTERVPROC>(loader("glGetPointerv"));
    oglGetProgramInterfaceiv           = reinterpret_cast<PFNGLGETPROGRAMINTERFACEIVPROC>(loader("glGetProgramInterfaceiv"));
    oglGetProgramResourceIndex         = reinterpret_cast<PFNGLGETPROGRAMRESOURCEINDEXPROC>(loader("glGetProgramResourceIndex"));
    oglGetProgramResourceLocationIndex = reinterpret_cast<PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC>(loader("glGetProgramResourceLocationIndex"));
    oglGetProgramResourceLocation      = reinterpret_cast<PFNGLGETPROGRAMRESOURCELOCATIONPROC>(loader("glGetProgramResourceLocation"));
    oglGetProgramResourceName          = reinterpret_cast<PFNGLGETPROGRAMRESOURCENAMEPROC>(loader("glGetProgramResourceName"));
    oglGetProgramResourceiv            = reinterpret_cast<PFNGLGETPROGRAMRESOURCEIVPROC>(loader("glGetProgramResourceiv"));
    oglInvalidateBufferData            = reinterpret_cast<PFNGLINVALIDATEBUFFERDATAPROC>(loader("glInvalidateBufferData"));
    oglInvalidateBufferSubData         = reinterpret_cast<PFNGLINVALIDATEBUFFERSUBDATAPROC>(loader("glInvalidateBufferSubData"));
    oglInvalidateFramebuffer           = reinterpret_cast<PFNGLINVALIDATEFRAMEBUFFERPROC>(loader("glInvalidateFramebuffer"));
    oglInvalidateSubFramebuffer        = reinterpret_cast<PFNGLINVALIDATESUBFRAMEBUFFERPROC>(loader("glInvalidateSubFramebuffer"));
    oglInvalidateTexImage              = reinterpret_cast<PFNGLINVALIDATETEXIMAGEPROC>(loader("glInvalidateTexImage"));
    oglInvalidateTexSubImage           = reinterpret_cast<PFNGLINVALIDATETEXSUBIMAGEPROC>(loader("glInvalidateTexSubImage"));
    oglMultiDrawArraysIndirect         = reinterpret_cast<PFNGLMULTIDRAWARRAYSINDIRECTPROC>(loader("glMultiDrawArraysIndirect"));
    oglMultiDrawElementsIndirect       = reinterpret_cast<PFNGLMULTIDRAWELEMENTSINDIRECTPROC>(loader("glMultiDrawElementsIndirect"));
    oglObjectLabel                     = reinterpret_cast<PFNGLOBJECTLABELPROC>(loader("glObjectLabel"));
    oglObjectPtrLabel                  = reinterpret_cast<PFNGLOBJECTPTRLABELPROC>(loader("glObjectPtrLabel"));
    oglPopDebugGroup                   = reinterpret_cast<PFNGLPOPDEBUGGROUPPROC>(loader("glPopDebugGroup"));
    oglPushDebugGroup                  = reinterpret_cast<PFNGLPUSHDEBUGGROUPPROC>(loader("glPushDebugGroup"));
    oglShaderStorageBlockBinding       = reinterpret_cast<PFNGLSHADERSTORAGEBLOCKBINDINGPROC>(loader("glShaderStorageBlockBinding"));
    oglTexBufferRange                  = reinterpret_cast<PFNGLTEXBUFFERRANGEPROC>(loader("glTexBufferRange"));
    oglTexStorage2DMultisample         = reinterpret_cast<PFNGLTEXSTORAGE2DMULTISAMPLEPROC>(loader("glTexStorage2DMultisample"));
    oglTexStorage3DMultisample         = reinterpret_cast<PFNGLTEXSTORAGE3DMULTISAMPLEPROC>(loader("glTexStorage3DMultisample"));
    oglTextureView                     = reinterpret_cast<PFNGLTEXTUREVIEWPROC>(loader("glTextureView"));
    oglVertexAttribBinding             = reinterpret_cast<PFNGLVERTEXATTRIBBINDINGPROC>(loader("glVertexAttribBinding"));
    oglVertexAttribFormat              = reinterpret_cast<PFNGLVERTEXATTRIBFORMATPROC>(loader("glVertexAttribFormat"));
    oglVertexAttribIFormat             = reinterpret_cast<PFNGLVERTEXATTRIBIFORMATPROC>(loader("glVertexAttribIFormat"));
    oglVertexAttribLFormat             = reinterpret_cast<PFNGLVERTEXATTRIBLFORMATPROC>(loader("glVertexAttribLFormat"));
    oglVertexBindingDivisor            = reinterpret_cast<PFNGLVERTEXBINDINGDIVISORPROC>(loader("glVertexBindingDivisor"));
}

} // namespace glr
} // namespace xg

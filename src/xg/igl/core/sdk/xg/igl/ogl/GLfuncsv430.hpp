#pragma once

#include <xg/igl/ogl/GLfuncsv420.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API GLfuncsv430 : public GLfuncsv420 {

  public:
    typedef void(APIENTRY* GLDEBUGPROC)(GLenum_t        source,
                                        GLenum_t        type,
                                        GLuint_t        id,
                                        GLenum_t        severity,
                                        GLsizei_t       length,
                                        const GLchar_t* message,
                                        const void*     userParam);
    typedef void(APIENTRY* GLDEBUGPROCARB)(GLenum_t        source,
                                           GLenum_t        type,
                                           GLuint_t        id,
                                           GLenum_t        severity,
                                           GLsizei_t       length,
                                           const GLchar_t* message,
                                           const void*     userParam);
    typedef void(APIENTRY* GLDEBUGPROCKHR)(GLenum_t        source,
                                           GLenum_t        type,
                                           GLuint_t        id,
                                           GLenum_t        severity,
                                           GLsizei_t       length,
                                           const GLchar_t* message,
                                           const void*     userParam);
    typedef void(APIENTRY* GLDEBUGPROCAMD)(GLuint_t id, GLenum_t category, GLenum_t severity, GLsizei_t length, const GLchar_t* message, void* userParam);


    typedef void(APIENTRYP PFNGLCLEARBUFFERDATAPROC)(GLenum_t target, GLenum_t internalformat, GLenum_t format, GLenum_t type, const void* data);
    PFNGLCLEARBUFFERDATAPROC oglClearBufferData;

    typedef void(APIENTRYP PFNGLCLEARBUFFERSUBDATAPROC)(GLenum_t    target,
                                                        GLenum_t    internalformat,
                                                        GLintptr    offset,
                                                        GLsizeiptr  size,
                                                        GLenum_t    format,
                                                        GLenum_t    type,
                                                        const void* data);
    PFNGLCLEARBUFFERSUBDATAPROC oglClearBufferSubData;

    typedef void(APIENTRYP PFNGLDISPATCHCOMPUTEPROC)(GLuint_t num_groups_x, GLuint_t num_groups_y, GLuint_t num_groups_z);
    PFNGLDISPATCHCOMPUTEPROC oglDispatchCompute;

    typedef void(APIENTRYP PFNGLDISPATCHCOMPUTEINDIRECTPROC)(GLintptr indirect);
    PFNGLDISPATCHCOMPUTEINDIRECTPROC oglDispatchComputeIndirect;

    typedef void(APIENTRYP PFNGLCOPYIMAGESUBDATAPROC)(GLuint_t  srcName,
                                                      GLenum_t  srcTarget,
                                                      GLint_t   srcLevel,
                                                      GLint_t   srcX,
                                                      GLint_t   srcY,
                                                      GLint_t   srcZ,
                                                      GLuint_t  dstName,
                                                      GLenum_t  dstTarget,
                                                      GLint_t   dstLevel,
                                                      GLint_t   dstX,
                                                      GLint_t   dstY,
                                                      GLint_t   dstZ,
                                                      GLsizei_t srcWidth,
                                                      GLsizei_t srcHeight,
                                                      GLsizei_t srcDepth);
    PFNGLCOPYIMAGESUBDATAPROC oglCopyImageSubData;

    typedef void(APIENTRYP PFNGLFRAMEBUFFERPARAMETERIPROC)(GLenum_t target, GLenum_t pname, GLint_t param);
    PFNGLFRAMEBUFFERPARAMETERIPROC oglFramebufferParameteri;

    typedef void(APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVPROC)(GLenum_t target, GLenum_t pname, GLint_t* params);
    PFNGLGETFRAMEBUFFERPARAMETERIVPROC oglGetFramebufferParameteriv;

    typedef void(APIENTRYP PFNGLGETINTERNALFORMATI64VPROC)(GLenum_t target, GLenum_t internalformat, GLenum_t pname, GLsizei_t count, GLint64* params);
    PFNGLGETINTERNALFORMATI64VPROC oglGetInternalformati64v;

    typedef void(APIENTRYP PFNGLINVALIDATETEXSUBIMAGEPROC)(GLuint_t  texture,
                                                           GLint_t   level,
                                                           GLint_t   xoffset,
                                                           GLint_t   yoffset,
                                                           GLint_t   zoffset,
                                                           GLsizei_t width,
                                                           GLsizei_t height,
                                                           GLsizei_t depth);
    PFNGLINVALIDATETEXSUBIMAGEPROC oglInvalidateTexSubImage;

    typedef void(APIENTRYP PFNGLINVALIDATETEXIMAGEPROC)(GLuint_t texture, GLint_t level);
    PFNGLINVALIDATETEXIMAGEPROC oglInvalidateTexImage;

    typedef void(APIENTRYP PFNGLINVALIDATEBUFFERSUBDATAPROC)(GLuint_t buffer, GLintptr offset, GLsizeiptr length);
    PFNGLINVALIDATEBUFFERSUBDATAPROC oglInvalidateBufferSubData;

    typedef void(APIENTRYP PFNGLINVALIDATEBUFFERDATAPROC)(GLuint_t buffer);
    PFNGLINVALIDATEBUFFERDATAPROC oglInvalidateBufferData;

    typedef void(APIENTRYP PFNGLINVALIDATEFRAMEBUFFERPROC)(GLenum_t target, GLsizei_t numAttachments, const GLenum_t* attachments);
    PFNGLINVALIDATEFRAMEBUFFERPROC oglInvalidateFramebuffer;

    typedef void(APIENTRYP PFNGLINVALIDATESUBFRAMEBUFFERPROC)(GLenum_t        target,
                                                              GLsizei_t       numAttachments,
                                                              const GLenum_t* attachments,
                                                              GLint_t         x,
                                                              GLint_t         y,
                                                              GLsizei_t       width,
                                                              GLsizei_t       height);
    PFNGLINVALIDATESUBFRAMEBUFFERPROC oglInvalidateSubFramebuffer;

    typedef void(APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTPROC)(GLenum_t mode, const void* indirect, GLsizei_t drawcount, GLsizei_t stride);
    PFNGLMULTIDRAWARRAYSINDIRECTPROC oglMultiDrawArraysIndirect;

    typedef void(APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTPROC)(GLenum_t mode, GLenum_t type, const void* indirect, GLsizei_t drawcount, GLsizei_t stride);
    PFNGLMULTIDRAWELEMENTSINDIRECTPROC oglMultiDrawElementsIndirect;

    typedef void(APIENTRYP PFNGLGETPROGRAMINTERFACEIVPROC)(GLuint_t program, GLenum_t programInterface, GLenum_t pname, GLint_t* params);
    PFNGLGETPROGRAMINTERFACEIVPROC oglGetProgramInterfaceiv;

    typedef GLuint_t(APIENTRYP PFNGLGETPROGRAMRESOURCEINDEXPROC)(GLuint_t program, GLenum_t programInterface, const GLchar_t* name);
    PFNGLGETPROGRAMRESOURCEINDEXPROC oglGetProgramResourceIndex;

    typedef void(APIENTRYP PFNGLGETPROGRAMRESOURCENAMEPROC)(GLuint_t   program,
                                                            GLenum_t   programInterface,
                                                            GLuint_t   index,
                                                            GLsizei_t  bufSize,
                                                            GLsizei_t* length,
                                                            GLchar_t*  name);
    PFNGLGETPROGRAMRESOURCENAMEPROC oglGetProgramResourceName;

    typedef void(APIENTRYP PFNGLGETPROGRAMRESOURCEIVPROC)(GLuint_t        program,
                                                          GLenum_t        programInterface,
                                                          GLuint_t        index,
                                                          GLsizei_t       propCount,
                                                          const GLenum_t* props,
                                                          GLsizei_t       count,
                                                          GLsizei_t*      length,
                                                          GLint_t*        params);
    PFNGLGETPROGRAMRESOURCEIVPROC oglGetProgramResourceiv;

    typedef GLint_t(APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONPROC)(GLuint_t program, GLenum_t programInterface, const GLchar_t* name);
    PFNGLGETPROGRAMRESOURCELOCATIONPROC oglGetProgramResourceLocation;

    typedef GLint_t(APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)(GLuint_t program, GLenum_t programInterface, const GLchar_t* name);
    PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC oglGetProgramResourceLocationIndex;

    typedef void(APIENTRYP PFNGLSHADERSTORAGEBLOCKBINDINGPROC)(GLuint_t program, GLuint_t storageBlockIndex, GLuint_t storageBlockBinding);
    PFNGLSHADERSTORAGEBLOCKBINDINGPROC oglShaderStorageBlockBinding;

    typedef void(APIENTRYP PFNGLTEXBUFFERRANGEPROC)(GLenum_t target, GLenum_t internalformat, GLuint_t buffer, GLintptr offset, GLsizeiptr size);
    PFNGLTEXBUFFERRANGEPROC oglTexBufferRange;

    typedef void(APIENTRYP PFNGLTEXSTORAGE2DMULTISAMPLEPROC)(GLenum_t    target,
                                                             GLsizei_t   samples,
                                                             GLenum_t    internalformat,
                                                             GLsizei_t   width,
                                                             GLsizei_t   height,
                                                             GLboolean_t fixedsamplelocations);
    PFNGLTEXSTORAGE2DMULTISAMPLEPROC oglTexStorage2DMultisample;

    typedef void(APIENTRYP PFNGLTEXSTORAGE3DMULTISAMPLEPROC)(GLenum_t    target,
                                                             GLsizei_t   samples,
                                                             GLenum_t    internalformat,
                                                             GLsizei_t   width,
                                                             GLsizei_t   height,
                                                             GLsizei_t   depth,
                                                             GLboolean_t fixedsamplelocations);
    PFNGLTEXSTORAGE3DMULTISAMPLEPROC oglTexStorage3DMultisample;

    typedef void(APIENTRYP PFNGLTEXTUREVIEWPROC)(GLuint_t texture,
                                                 GLenum_t target,
                                                 GLuint_t origtexture,
                                                 GLenum_t internalformat,
                                                 GLuint_t minlevel,
                                                 GLuint_t numlevels,
                                                 GLuint_t minlayer,
                                                 GLuint_t numlayers);
    PFNGLTEXTUREVIEWPROC oglTextureView;

    typedef void(APIENTRYP PFNGLBINDVERTEXBUFFERPROC)(GLuint_t bindingindex, GLuint_t buffer, GLintptr offset, GLsizei_t stride);
    PFNGLBINDVERTEXBUFFERPROC oglBindVertexBuffer;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBFORMATPROC)(GLuint_t attribindex, GLint_t size, GLenum_t type, GLboolean_t normalized, GLuint_t relativeoffset);
    PFNGLVERTEXATTRIBFORMATPROC oglVertexAttribFormat;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBIFORMATPROC)(GLuint_t attribindex, GLint_t size, GLenum_t type, GLuint_t relativeoffset);
    PFNGLVERTEXATTRIBIFORMATPROC oglVertexAttribIFormat;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBLFORMATPROC)(GLuint_t attribindex, GLint_t size, GLenum_t type, GLuint_t relativeoffset);
    PFNGLVERTEXATTRIBLFORMATPROC oglVertexAttribLFormat;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBBINDINGPROC)(GLuint_t attribindex, GLuint_t bindingindex);
    PFNGLVERTEXATTRIBBINDINGPROC oglVertexAttribBinding;

    typedef void(APIENTRYP PFNGLVERTEXBINDINGDIVISORPROC)(GLuint_t bindingindex, GLuint_t divisor);
    PFNGLVERTEXBINDINGDIVISORPROC oglVertexBindingDivisor;

    typedef void(
        APIENTRYP PFNGLDEBUGMESSAGECONTROLPROC)(GLenum_t source, GLenum_t type, GLenum_t severity, GLsizei_t count, const GLuint_t* ids, GLboolean_t enabled);
    PFNGLDEBUGMESSAGECONTROLPROC oglDebugMessageControl;

    typedef void(APIENTRYP PFNGLDEBUGMESSAGEINSERTPROC)(GLenum_t source, GLenum_t type, GLuint_t id, GLenum_t severity, GLsizei_t length, const GLchar_t* buf);
    PFNGLDEBUGMESSAGEINSERTPROC oglDebugMessageInsert;

    typedef void(APIENTRYP PFNGLDEBUGMESSAGECALLBACKPROC)(GLDEBUGPROC callback, const void* userParam);
    PFNGLDEBUGMESSAGECALLBACKPROC oglDebugMessageCallback;

    typedef GLuint_t(APIENTRYP PFNGLGETDEBUGMESSAGELOGPROC)(GLuint_t   count,
                                                            GLsizei_t  bufSize,
                                                            GLenum_t*  sources,
                                                            GLenum_t*  types,
                                                            GLuint_t*  ids,
                                                            GLenum_t*  severities,
                                                            GLsizei_t* lengths,
                                                            GLchar_t*  messageLog);
    PFNGLGETDEBUGMESSAGELOGPROC oglGetDebugMessageLog;

    typedef void(APIENTRYP PFNGLPUSHDEBUGGROUPPROC)(GLenum_t source, GLuint_t id, GLsizei_t length, const GLchar_t* message);
    PFNGLPUSHDEBUGGROUPPROC oglPushDebugGroup;

    typedef void(APIENTRYP PFNGLPOPDEBUGGROUPPROC)(void);
    PFNGLPOPDEBUGGROUPPROC oglPopDebugGroup;

    typedef void(APIENTRYP PFNGLOBJECTLABELPROC)(GLenum_t identifier, GLuint_t name, GLsizei_t length, const GLchar_t* label);
    PFNGLOBJECTLABELPROC oglObjectLabel;

    typedef void(APIENTRYP PFNGLGETOBJECTLABELPROC)(GLenum_t identifier, GLuint_t name, GLsizei_t bufSize, GLsizei_t* length, GLchar_t* label);
    PFNGLGETOBJECTLABELPROC oglGetObjectLabel;

    typedef void(APIENTRYP PFNGLOBJECTPTRLABELPROC)(const void* ptr, GLsizei_t length, const GLchar_t* label);
    PFNGLOBJECTPTRLABELPROC oglObjectPtrLabel;

    typedef void(APIENTRYP PFNGLGETOBJECTPTRLABELPROC)(const void* ptr, GLsizei_t bufSize, GLsizei_t* length, GLchar_t* label);
    PFNGLGETOBJECTPTRLABELPROC oglGetObjectPtrLabel;

    typedef void(APIENTRYP PFNGLGETPOINTERVPROC)(GLenum_t pname, void** params);
    PFNGLGETPOINTERVPROC oglGetPointerv;


  public:
    GLfuncsv430();

  protected:
    virtual void loadFuncs(Loader loader) override;
};

} // namespace glr
} // namespace xg
#pragma once

#include <glr/igl/GLfuncsv420.h>

namespace glr {
class GLR_API GLfuncsv430 : public GLfuncsv420 {

  public:
    typedef void(APIENTRY* GLDEBUGPROC)(GLenum_t        source,
                                        GLenum_t        type,
                                        GLuint_t        id,
                                        GLenum_t        severity,
                                        GLsizei_t       length,
                                        const GLchar_t* message,
                                        const void*   userParam);
    typedef void(APIENTRY* GLDEBUGPROCARB)(GLenum_t        source,
                                           GLenum_t        type,
                                           GLuint_t        id,
                                           GLenum_t        severity,
                                           GLsizei_t       length,
                                           const GLchar_t* message,
                                           const void*   userParam);
    typedef void(APIENTRY* GLDEBUGPROCKHR)(GLenum_t        source,
                                           GLenum_t        type,
                                           GLuint_t        id,
                                           GLenum_t        severity,
                                           GLsizei_t       length,
                                           const GLchar_t* message,
                                           const void*   userParam);
    typedef void(APIENTRY* GLDEBUGPROCAMD)(GLuint_t        id,
                                           GLenum_t        category,
                                           GLenum_t        severity,
                                           GLsizei_t       length,
                                           const GLchar_t* message,
                                           void*         userParam);


    typedef void(APIENTRYP PFNGLCLEARBUFFERDATAPROC)(GLenum_t      target,
                                                     GLenum_t      internalformat,
                                                     GLenum_t      format,
                                                     GLenum_t      type,
                                                     const void* data);
    PFNGLCLEARBUFFERDATAPROC iglClearBufferData;

    typedef void(APIENTRYP PFNGLCLEARBUFFERSUBDATAPROC)(GLenum_t      target,
                                                        GLenum_t      internalformat,
                                                        GLintptr    offset,
                                                        GLsizeiptr  size,
                                                        GLenum_t      format,
                                                        GLenum_t      type,
                                                        const void* data);
    PFNGLCLEARBUFFERSUBDATAPROC iglClearBufferSubData;

    typedef void(APIENTRYP PFNGLDISPATCHCOMPUTEPROC)(GLuint_t num_groups_x, GLuint_t num_groups_y, GLuint_t num_groups_z);
    PFNGLDISPATCHCOMPUTEPROC iglDispatchCompute;

    typedef void(APIENTRYP PFNGLDISPATCHCOMPUTEINDIRECTPROC)(GLintptr indirect);
    PFNGLDISPATCHCOMPUTEINDIRECTPROC iglDispatchComputeIndirect;

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
    PFNGLCOPYIMAGESUBDATAPROC iglCopyImageSubData;

    typedef void(APIENTRYP PFNGLFRAMEBUFFERPARAMETERIPROC)(GLenum_t target, GLenum_t pname, GLint_t param);
    PFNGLFRAMEBUFFERPARAMETERIPROC iglFramebufferParameteri;

    typedef void(APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVPROC)(GLenum_t target, GLenum_t pname, GLint_t* params);
    PFNGLGETFRAMEBUFFERPARAMETERIVPROC iglGetFramebufferParameteriv;

    typedef void(APIENTRYP PFNGLGETINTERNALFORMATI64VPROC)(GLenum_t   target,
                                                           GLenum_t   internalformat,
                                                           GLenum_t   pname,
                                                           GLsizei_t  count,
                                                           GLint64* params);
    PFNGLGETINTERNALFORMATI64VPROC iglGetInternalformati64v;

    typedef void(APIENTRYP PFNGLINVALIDATETEXSUBIMAGEPROC)(GLuint_t  texture,
                                                           GLint_t   level,
                                                           GLint_t   xoffset,
                                                           GLint_t   yoffset,
                                                           GLint_t   zoffset,
                                                           GLsizei_t width,
                                                           GLsizei_t height,
                                                           GLsizei_t depth);
    PFNGLINVALIDATETEXSUBIMAGEPROC iglInvalidateTexSubImage;

    typedef void(APIENTRYP PFNGLINVALIDATETEXIMAGEPROC)(GLuint_t texture, GLint_t level);
    PFNGLINVALIDATETEXIMAGEPROC iglInvalidateTexImage;

    typedef void(APIENTRYP PFNGLINVALIDATEBUFFERSUBDATAPROC)(GLuint_t buffer, GLintptr offset, GLsizeiptr length);
    PFNGLINVALIDATEBUFFERSUBDATAPROC iglInvalidateBufferSubData;

    typedef void(APIENTRYP PFNGLINVALIDATEBUFFERDATAPROC)(GLuint_t buffer);
    PFNGLINVALIDATEBUFFERDATAPROC iglInvalidateBufferData;

    typedef void(APIENTRYP PFNGLINVALIDATEFRAMEBUFFERPROC)(GLenum_t        target,
                                                           GLsizei_t       numAttachments,
                                                           const GLenum_t* attachments);
    PFNGLINVALIDATEFRAMEBUFFERPROC iglInvalidateFramebuffer;

    typedef void(APIENTRYP PFNGLINVALIDATESUBFRAMEBUFFERPROC)(GLenum_t        target,
                                                              GLsizei_t       numAttachments,
                                                              const GLenum_t* attachments,
                                                              GLint_t         x,
                                                              GLint_t         y,
                                                              GLsizei_t       width,
                                                              GLsizei_t       height);
    PFNGLINVALIDATESUBFRAMEBUFFERPROC iglInvalidateSubFramebuffer;

    typedef void(APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTPROC)(GLenum_t      mode,
                                                             const void* indirect,
                                                             GLsizei_t     drawcount,
                                                             GLsizei_t     stride);
    PFNGLMULTIDRAWARRAYSINDIRECTPROC iglMultiDrawArraysIndirect;

    typedef void(APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTPROC)(GLenum_t      mode,
                                                               GLenum_t      type,
                                                               const void* indirect,
                                                               GLsizei_t     drawcount,
                                                               GLsizei_t     stride);
    PFNGLMULTIDRAWELEMENTSINDIRECTPROC iglMultiDrawElementsIndirect;

    typedef void(APIENTRYP PFNGLGETPROGRAMINTERFACEIVPROC)(GLuint_t program,
                                                           GLenum_t programInterface,
                                                           GLenum_t pname,
                                                           GLint_t* params);
    PFNGLGETPROGRAMINTERFACEIVPROC iglGetProgramInterfaceiv;

    typedef GLuint_t(APIENTRYP PFNGLGETPROGRAMRESOURCEINDEXPROC)(GLuint_t        program,
                                                               GLenum_t        programInterface,
                                                               const GLchar_t* name);
    PFNGLGETPROGRAMRESOURCEINDEXPROC iglGetProgramResourceIndex;

    typedef void(APIENTRYP PFNGLGETPROGRAMRESOURCENAMEPROC)(GLuint_t   program,
                                                            GLenum_t   programInterface,
                                                            GLuint_t   index,
                                                            GLsizei_t  bufSize,
                                                            GLsizei_t* length,
                                                            GLchar_t*  name);
    PFNGLGETPROGRAMRESOURCENAMEPROC iglGetProgramResourceName;

    typedef void(APIENTRYP PFNGLGETPROGRAMRESOURCEIVPROC)(GLuint_t        program,
                                                          GLenum_t        programInterface,
                                                          GLuint_t        index,
                                                          GLsizei_t       propCount,
                                                          const GLenum_t* props,
                                                          GLsizei_t       count,
                                                          GLsizei_t*      length,
                                                          GLint_t*        params);
    PFNGLGETPROGRAMRESOURCEIVPROC iglGetProgramResourceiv;

    typedef GLint_t(APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONPROC)(GLuint_t        program,
                                                                 GLenum_t        programInterface,
                                                                 const GLchar_t* name);
    PFNGLGETPROGRAMRESOURCELOCATIONPROC iglGetProgramResourceLocation;

    typedef GLint_t(APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)(GLuint_t        program,
                                                                      GLenum_t        programInterface,
                                                                      const GLchar_t* name);
    PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC iglGetProgramResourceLocationIndex;

    typedef void(APIENTRYP PFNGLSHADERSTORAGEBLOCKBINDINGPROC)(GLuint_t program,
                                                               GLuint_t storageBlockIndex,
                                                               GLuint_t storageBlockBinding);
    PFNGLSHADERSTORAGEBLOCKBINDINGPROC iglShaderStorageBlockBinding;

    typedef void(APIENTRYP PFNGLTEXBUFFERRANGEPROC)(GLenum_t     target,
                                                    GLenum_t     internalformat,
                                                    GLuint_t     buffer,
                                                    GLintptr   offset,
                                                    GLsizeiptr size);
    PFNGLTEXBUFFERRANGEPROC iglTexBufferRange;

    typedef void(APIENTRYP PFNGLTEXSTORAGE2DMULTISAMPLEPROC)(GLenum_t    target,
                                                             GLsizei_t   samples,
                                                             GLenum_t    internalformat,
                                                             GLsizei_t   width,
                                                             GLsizei_t   height,
                                                             GLboolean_t fixedsamplelocations);
    PFNGLTEXSTORAGE2DMULTISAMPLEPROC iglTexStorage2DMultisample;

    typedef void(APIENTRYP PFNGLTEXSTORAGE3DMULTISAMPLEPROC)(GLenum_t    target,
                                                             GLsizei_t   samples,
                                                             GLenum_t    internalformat,
                                                             GLsizei_t   width,
                                                             GLsizei_t   height,
                                                             GLsizei_t   depth,
                                                             GLboolean_t fixedsamplelocations);
    PFNGLTEXSTORAGE3DMULTISAMPLEPROC iglTexStorage3DMultisample;

    typedef void(APIENTRYP PFNGLTEXTUREVIEWPROC)(GLuint_t texture,
                                                 GLenum_t target,
                                                 GLuint_t origtexture,
                                                 GLenum_t internalformat,
                                                 GLuint_t minlevel,
                                                 GLuint_t numlevels,
                                                 GLuint_t minlayer,
                                                 GLuint_t numlayers);
    PFNGLTEXTUREVIEWPROC iglTextureView;

    typedef void(APIENTRYP PFNGLBINDVERTEXBUFFERPROC)(GLuint_t   bindingindex,
                                                      GLuint_t   buffer,
                                                      GLintptr offset,
                                                      GLsizei_t  stride);
    PFNGLBINDVERTEXBUFFERPROC iglBindVertexBuffer;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBFORMATPROC)(GLuint_t    attribindex,
                                                        GLint_t     size,
                                                        GLenum_t    type,
                                                        GLboolean_t normalized,
                                                        GLuint_t    relativeoffset);
    PFNGLVERTEXATTRIBFORMATPROC iglVertexAttribFormat;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBIFORMATPROC)(GLuint_t attribindex,
                                                         GLint_t  size,
                                                         GLenum_t type,
                                                         GLuint_t relativeoffset);
    PFNGLVERTEXATTRIBIFORMATPROC iglVertexAttribIFormat;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBLFORMATPROC)(GLuint_t attribindex,
                                                         GLint_t  size,
                                                         GLenum_t type,
                                                         GLuint_t relativeoffset);
    PFNGLVERTEXATTRIBLFORMATPROC iglVertexAttribLFormat;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBBINDINGPROC)(GLuint_t attribindex, GLuint_t bindingindex);
    PFNGLVERTEXATTRIBBINDINGPROC iglVertexAttribBinding;

    typedef void(APIENTRYP PFNGLVERTEXBINDINGDIVISORPROC)(GLuint_t bindingindex, GLuint_t divisor);
    PFNGLVERTEXBINDINGDIVISORPROC iglVertexBindingDivisor;

    typedef void(APIENTRYP PFNGLDEBUGMESSAGECONTROLPROC)(GLenum_t        source,
                                                         GLenum_t        type,
                                                         GLenum_t        severity,
                                                         GLsizei_t       count,
                                                         const GLuint_t* ids,
                                                         GLboolean_t     enabled);
    PFNGLDEBUGMESSAGECONTROLPROC iglDebugMessageControl;

    typedef void(APIENTRYP PFNGLDEBUGMESSAGEINSERTPROC)(GLenum_t        source,
                                                        GLenum_t        type,
                                                        GLuint_t        id,
                                                        GLenum_t        severity,
                                                        GLsizei_t       length,
                                                        const GLchar_t* buf);
    PFNGLDEBUGMESSAGEINSERTPROC iglDebugMessageInsert;

    typedef void(APIENTRYP PFNGLDEBUGMESSAGECALLBACKPROC)(GLDEBUGPROC callback, const void* userParam);
    PFNGLDEBUGMESSAGECALLBACKPROC iglDebugMessageCallback;

    typedef GLuint_t(APIENTRYP PFNGLGETDEBUGMESSAGELOGPROC)(GLuint_t   count,
                                                          GLsizei_t  bufSize,
                                                          GLenum_t*  sources,
                                                          GLenum_t*  types,
                                                          GLuint_t*  ids,
                                                          GLenum_t*  severities,
                                                          GLsizei_t* lengths,
                                                          GLchar_t*  messageLog);
    PFNGLGETDEBUGMESSAGELOGPROC iglGetDebugMessageLog;

    typedef void(APIENTRYP PFNGLPUSHDEBUGGROUPPROC)(GLenum_t source, GLuint_t id, GLsizei_t length, const GLchar_t* message);
    PFNGLPUSHDEBUGGROUPPROC iglPushDebugGroup;

    typedef void(APIENTRYP PFNGLPOPDEBUGGROUPPROC)(void);
    PFNGLPOPDEBUGGROUPPROC iglPopDebugGroup;

    typedef void(APIENTRYP PFNGLOBJECTLABELPROC)(GLenum_t identifier, GLuint_t name, GLsizei_t length, const GLchar_t* label);
    PFNGLOBJECTLABELPROC iglObjectLabel;

    typedef void(APIENTRYP PFNGLGETOBJECTLABELPROC)(GLenum_t   identifier,
                                                    GLuint_t   name,
                                                    GLsizei_t  bufSize,
                                                    GLsizei_t* length,
                                                    GLchar_t*  label);
    PFNGLGETOBJECTLABELPROC iglGetObjectLabel;

    typedef void(APIENTRYP PFNGLOBJECTPTRLABELPROC)(const void* ptr, GLsizei_t length, const GLchar_t* label);
    PFNGLOBJECTPTRLABELPROC iglObjectPtrLabel;

    typedef void(APIENTRYP PFNGLGETOBJECTPTRLABELPROC)(const void* ptr,
                                                       GLsizei_t     bufSize,
                                                       GLsizei_t*    length,
                                                       GLchar_t*     label);
    PFNGLGETOBJECTPTRLABELPROC iglGetObjectPtrLabel;

    typedef void(APIENTRYP PFNGLGETPOINTERVPROC)(GLenum_t pname, void** params);
    PFNGLGETPOINTERVPROC iglGetPointerv;


  public:
    GLfuncsv430();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
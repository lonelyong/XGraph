#pragma once

#include <glr/igl/GLfuncsv420.h>

namespace glr {
class GLR_API GLfuncsv430 : public GLfuncsv420 {
  public:
    typedef void(APIENTRY* GLDEBUGPROC)(GLenum        source,
                                        GLenum        type,
                                        GLuint        id,
                                        GLenum        severity,
                                        GLsizei       length,
                                        const GLchar* message,
                                        const void*   userParam);
    typedef void(APIENTRY* GLDEBUGPROCARB)(GLenum        source,
                                           GLenum        type,
                                           GLuint        id,
                                           GLenum        severity,
                                           GLsizei       length,
                                           const GLchar* message,
                                           const void*   userParam);
    typedef void(APIENTRY* GLDEBUGPROCKHR)(GLenum        source,
                                           GLenum        type,
                                           GLuint        id,
                                           GLenum        severity,
                                           GLsizei       length,
                                           const GLchar* message,
                                           const void*   userParam);
    typedef void(APIENTRY* GLDEBUGPROCAMD)(GLuint        id,
                                           GLenum        category,
                                           GLenum        severity,
                                           GLsizei       length,
                                           const GLchar* message,
                                           void*         userParam);


    typedef void(APIENTRYP PFNGLCLEARBUFFERDATAPROC)(GLenum      target,
                                                     GLenum      internalformat,
                                                     GLenum      format,
                                                     GLenum      type,
                                                     const void* data);
    PFNGLCLEARBUFFERDATAPROC glClearBufferData;

    typedef void(APIENTRYP PFNGLCLEARBUFFERSUBDATAPROC)(GLenum      target,
                                                        GLenum      internalformat,
                                                        GLintptr    offset,
                                                        GLsizeiptr  size,
                                                        GLenum      format,
                                                        GLenum      type,
                                                        const void* data);
    PFNGLCLEARBUFFERSUBDATAPROC glClearBufferSubData;

    typedef void(APIENTRYP PFNGLDISPATCHCOMPUTEPROC)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
    PFNGLDISPATCHCOMPUTEPROC glDispatchCompute;

    typedef void(APIENTRYP PFNGLDISPATCHCOMPUTEINDIRECTPROC)(GLintptr indirect);
    PFNGLDISPATCHCOMPUTEINDIRECTPROC glDispatchComputeIndirect;

    typedef void(APIENTRYP PFNGLCOPYIMAGESUBDATAPROC)(GLuint  srcName,
                                                      GLenum  srcTarget,
                                                      GLint   srcLevel,
                                                      GLint   srcX,
                                                      GLint   srcY,
                                                      GLint   srcZ,
                                                      GLuint  dstName,
                                                      GLenum  dstTarget,
                                                      GLint   dstLevel,
                                                      GLint   dstX,
                                                      GLint   dstY,
                                                      GLint   dstZ,
                                                      GLsizei srcWidth,
                                                      GLsizei srcHeight,
                                                      GLsizei srcDepth);
    PFNGLCOPYIMAGESUBDATAPROC glCopyImageSubData;

    typedef void(APIENTRYP PFNGLFRAMEBUFFERPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
    PFNGLFRAMEBUFFERPARAMETERIPROC glFramebufferParameteri;

    typedef void(APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint* params);
    PFNGLGETFRAMEBUFFERPARAMETERIVPROC glGetFramebufferParameteriv;

    typedef void(APIENTRYP PFNGLGETINTERNALFORMATI64VPROC)(GLenum   target,
                                                           GLenum   internalformat,
                                                           GLenum   pname,
                                                           GLsizei  count,
                                                           GLint64* params);
    PFNGLGETINTERNALFORMATI64VPROC glGetInternalformati64v;

    typedef void(APIENTRYP PFNGLINVALIDATETEXSUBIMAGEPROC)(GLuint  texture,
                                                           GLint   level,
                                                           GLint   xoffset,
                                                           GLint   yoffset,
                                                           GLint   zoffset,
                                                           GLsizei width,
                                                           GLsizei height,
                                                           GLsizei depth);
    PFNGLINVALIDATETEXSUBIMAGEPROC glInvalidateTexSubImage;

    typedef void(APIENTRYP PFNGLINVALIDATETEXIMAGEPROC)(GLuint texture, GLint level);
    PFNGLINVALIDATETEXIMAGEPROC glInvalidateTexImage;

    typedef void(APIENTRYP PFNGLINVALIDATEBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length);
    PFNGLINVALIDATEBUFFERSUBDATAPROC glInvalidateBufferSubData;

    typedef void(APIENTRYP PFNGLINVALIDATEBUFFERDATAPROC)(GLuint buffer);
    PFNGLINVALIDATEBUFFERDATAPROC glInvalidateBufferData;

    typedef void(APIENTRYP PFNGLINVALIDATEFRAMEBUFFERPROC)(GLenum        target,
                                                           GLsizei       numAttachments,
                                                           const GLenum* attachments);
    PFNGLINVALIDATEFRAMEBUFFERPROC glInvalidateFramebuffer;

    typedef void(APIENTRYP PFNGLINVALIDATESUBFRAMEBUFFERPROC)(GLenum        target,
                                                              GLsizei       numAttachments,
                                                              const GLenum* attachments,
                                                              GLint         x,
                                                              GLint         y,
                                                              GLsizei       width,
                                                              GLsizei       height);
    PFNGLINVALIDATESUBFRAMEBUFFERPROC glInvalidateSubFramebuffer;

    typedef void(APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTPROC)(GLenum      mode,
                                                             const void* indirect,
                                                             GLsizei     drawcount,
                                                             GLsizei     stride);
    PFNGLMULTIDRAWARRAYSINDIRECTPROC glMultiDrawArraysIndirect;

    typedef void(APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTPROC)(GLenum      mode,
                                                               GLenum      type,
                                                               const void* indirect,
                                                               GLsizei     drawcount,
                                                               GLsizei     stride);
    PFNGLMULTIDRAWELEMENTSINDIRECTPROC glMultiDrawElementsIndirect;

    typedef void(APIENTRYP PFNGLGETPROGRAMINTERFACEIVPROC)(GLuint program,
                                                           GLenum programInterface,
                                                           GLenum pname,
                                                           GLint* params);
    PFNGLGETPROGRAMINTERFACEIVPROC glGetProgramInterfaceiv;

    typedef GLuint(APIENTRYP PFNGLGETPROGRAMRESOURCEINDEXPROC)(GLuint        program,
                                                               GLenum        programInterface,
                                                               const GLchar* name);
    PFNGLGETPROGRAMRESOURCEINDEXPROC glGetProgramResourceIndex;

    typedef void(APIENTRYP PFNGLGETPROGRAMRESOURCENAMEPROC)(GLuint   program,
                                                            GLenum   programInterface,
                                                            GLuint   index,
                                                            GLsizei  bufSize,
                                                            GLsizei* length,
                                                            GLchar*  name);
    PFNGLGETPROGRAMRESOURCENAMEPROC glGetProgramResourceName;

    typedef void(APIENTRYP PFNGLGETPROGRAMRESOURCEIVPROC)(GLuint        program,
                                                          GLenum        programInterface,
                                                          GLuint        index,
                                                          GLsizei       propCount,
                                                          const GLenum* props,
                                                          GLsizei       count,
                                                          GLsizei*      length,
                                                          GLint*        params);
    PFNGLGETPROGRAMRESOURCEIVPROC glGetProgramResourceiv;

    typedef GLint(APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONPROC)(GLuint        program,
                                                                 GLenum        programInterface,
                                                                 const GLchar* name);
    PFNGLGETPROGRAMRESOURCELOCATIONPROC glGetProgramResourceLocation;

    typedef GLint(APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)(GLuint        program,
                                                                      GLenum        programInterface,
                                                                      const GLchar* name);
    PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC glGetProgramResourceLocationIndex;

    typedef void(APIENTRYP PFNGLSHADERSTORAGEBLOCKBINDINGPROC)(GLuint program,
                                                               GLuint storageBlockIndex,
                                                               GLuint storageBlockBinding);
    PFNGLSHADERSTORAGEBLOCKBINDINGPROC glShaderStorageBlockBinding;

    typedef void(APIENTRYP PFNGLTEXBUFFERRANGEPROC)(GLenum     target,
                                                    GLenum     internalformat,
                                                    GLuint     buffer,
                                                    GLintptr   offset,
                                                    GLsizeiptr size);
    PFNGLTEXBUFFERRANGEPROC glTexBufferRange;

    typedef void(APIENTRYP PFNGLTEXSTORAGE2DMULTISAMPLEPROC)(GLenum    target,
                                                             GLsizei   samples,
                                                             GLenum    internalformat,
                                                             GLsizei   width,
                                                             GLsizei   height,
                                                             GLboolean fixedsamplelocations);
    PFNGLTEXSTORAGE2DMULTISAMPLEPROC glTexStorage2DMultisample;

    typedef void(APIENTRYP PFNGLTEXSTORAGE3DMULTISAMPLEPROC)(GLenum    target,
                                                             GLsizei   samples,
                                                             GLenum    internalformat,
                                                             GLsizei   width,
                                                             GLsizei   height,
                                                             GLsizei   depth,
                                                             GLboolean fixedsamplelocations);
    PFNGLTEXSTORAGE3DMULTISAMPLEPROC glTexStorage3DMultisample;

    typedef void(APIENTRYP PFNGLTEXTUREVIEWPROC)(GLuint texture,
                                                 GLenum target,
                                                 GLuint origtexture,
                                                 GLenum internalformat,
                                                 GLuint minlevel,
                                                 GLuint numlevels,
                                                 GLuint minlayer,
                                                 GLuint numlayers);
    PFNGLTEXTUREVIEWPROC glTextureView;

    typedef void(APIENTRYP PFNGLBINDVERTEXBUFFERPROC)(GLuint   bindingindex,
                                                      GLuint   buffer,
                                                      GLintptr offset,
                                                      GLsizei  stride);
    PFNGLBINDVERTEXBUFFERPROC glBindVertexBuffer;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBFORMATPROC)(GLuint    attribindex,
                                                        GLint     size,
                                                        GLenum    type,
                                                        GLboolean normalized,
                                                        GLuint    relativeoffset);
    PFNGLVERTEXATTRIBFORMATPROC glVertexAttribFormat;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBIFORMATPROC)(GLuint attribindex,
                                                         GLint  size,
                                                         GLenum type,
                                                         GLuint relativeoffset);
    PFNGLVERTEXATTRIBIFORMATPROC glVertexAttribIFormat;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBLFORMATPROC)(GLuint attribindex,
                                                         GLint  size,
                                                         GLenum type,
                                                         GLuint relativeoffset);
    PFNGLVERTEXATTRIBLFORMATPROC glVertexAttribLFormat;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBBINDINGPROC)(GLuint attribindex, GLuint bindingindex);
    PFNGLVERTEXATTRIBBINDINGPROC glVertexAttribBinding;

    typedef void(APIENTRYP PFNGLVERTEXBINDINGDIVISORPROC)(GLuint bindingindex, GLuint divisor);
    PFNGLVERTEXBINDINGDIVISORPROC glVertexBindingDivisor;

    typedef void(APIENTRYP PFNGLDEBUGMESSAGECONTROLPROC)(GLenum        source,
                                                         GLenum        type,
                                                         GLenum        severity,
                                                         GLsizei       count,
                                                         const GLuint* ids,
                                                         GLboolean     enabled);
    PFNGLDEBUGMESSAGECONTROLPROC glDebugMessageControl;

    typedef void(APIENTRYP PFNGLDEBUGMESSAGEINSERTPROC)(GLenum        source,
                                                        GLenum        type,
                                                        GLuint        id,
                                                        GLenum        severity,
                                                        GLsizei       length,
                                                        const GLchar* buf);
    PFNGLDEBUGMESSAGEINSERTPROC glDebugMessageInsert;

    typedef void(APIENTRYP PFNGLDEBUGMESSAGECALLBACKPROC)(GLDEBUGPROC callback, const void* userParam);
    PFNGLDEBUGMESSAGECALLBACKPROC glDebugMessageCallback;

    typedef GLuint(APIENTRYP PFNGLGETDEBUGMESSAGELOGPROC)(GLuint   count,
                                                          GLsizei  bufSize,
                                                          GLenum*  sources,
                                                          GLenum*  types,
                                                          GLuint*  ids,
                                                          GLenum*  severities,
                                                          GLsizei* lengths,
                                                          GLchar*  messageLog);
    PFNGLGETDEBUGMESSAGELOGPROC glGetDebugMessageLog;

    typedef void(APIENTRYP PFNGLPUSHDEBUGGROUPPROC)(GLenum source, GLuint id, GLsizei length, const GLchar* message);
    PFNGLPUSHDEBUGGROUPPROC glPushDebugGroup;

    typedef void(APIENTRYP PFNGLPOPDEBUGGROUPPROC)(void);
    PFNGLPOPDEBUGGROUPPROC glPopDebugGroup;

    typedef void(APIENTRYP PFNGLOBJECTLABELPROC)(GLenum identifier, GLuint name, GLsizei length, const GLchar* label);
    PFNGLOBJECTLABELPROC glObjectLabel;

    typedef void(APIENTRYP PFNGLGETOBJECTLABELPROC)(GLenum   identifier,
                                                    GLuint   name,
                                                    GLsizei  bufSize,
                                                    GLsizei* length,
                                                    GLchar*  label);
    PFNGLGETOBJECTLABELPROC glGetObjectLabel;

    typedef void(APIENTRYP PFNGLOBJECTPTRLABELPROC)(const void* ptr, GLsizei length, const GLchar* label);
    PFNGLOBJECTPTRLABELPROC glObjectPtrLabel;

    typedef void(APIENTRYP PFNGLGETOBJECTPTRLABELPROC)(const void* ptr,
                                                       GLsizei     bufSize,
                                                       GLsizei*    length,
                                                       GLchar*     label);
    PFNGLGETOBJECTPTRLABELPROC glGetObjectPtrLabel;

    typedef void(APIENTRYP PFNGLGETPOINTERVPROC)(GLenum pname, void** params);
    PFNGLGETPOINTERVPROC glGetPointerv;


  public:
    GLfuncsv430();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
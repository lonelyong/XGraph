#pragma once

#include <glr/igl/GLfuncsv440.h>

namespace glr {
class GLR_API GLfuncsv450 : public GLfuncsv440 {
  public:
    typedef void(APIENTRYP PFNGLCLIPCONTROLPROC)(GLenum origin, GLenum depth);
    PFNGLCLIPCONTROLPROC glClipControl;

    typedef void(APIENTRYP PFNGLCREATETRANSFORMFEEDBACKSPROC)(GLsizei n, GLuint* ids);
    PFNGLCREATETRANSFORMFEEDBACKSPROC glCreateTransformFeedbacks;

    typedef void(APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC)(GLuint xfb, GLuint index, GLuint buffer);
    PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC glTransformFeedbackBufferBase;

    typedef void(APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC)(GLuint     xfb,
                                                                  GLuint     index,
                                                                  GLuint     buffer,
                                                                  GLintptr   offset,
                                                                  GLsizeiptr size);
    PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC glTransformFeedbackBufferRange;

    typedef void(APIENTRYP PFNGLGETTRANSFORMFEEDBACKIVPROC)(GLuint xfb, GLenum pname, GLint* param);
    PFNGLGETTRANSFORMFEEDBACKIVPROC glGetTransformFeedbackiv;

    typedef void(APIENTRYP PFNGLGETTRANSFORMFEEDBACKI_VPROC)(GLuint xfb, GLenum pname, GLuint index, GLint* param);
    PFNGLGETTRANSFORMFEEDBACKI_VPROC glGetTransformFeedbacki_v;

    typedef void(APIENTRYP PFNGLGETTRANSFORMFEEDBACKI64_VPROC)(GLuint xfb, GLenum pname, GLuint index, GLint64* param);
    PFNGLGETTRANSFORMFEEDBACKI64_VPROC glGetTransformFeedbacki64_v;

    typedef void(APIENTRYP PFNGLCREATEBUFFERSPROC)(GLsizei n, GLuint* buffers);
    PFNGLCREATEBUFFERSPROC glCreateBuffers;

    typedef void(APIENTRYP PFNGLNAMEDBUFFERSTORAGEPROC)(GLuint      buffer,
                                                        GLsizeiptr  size,
                                                        const void* data,
                                                        GLbitfield  flags);
    PFNGLNAMEDBUFFERSTORAGEPROC glNamedBufferStorage;

    typedef void(APIENTRYP PFNGLNAMEDBUFFERDATAPROC)(GLuint buffer, GLsizeiptr size, const void* data, GLenum usage);
    PFNGLNAMEDBUFFERDATAPROC glNamedBufferData;

    typedef void(APIENTRYP PFNGLNAMEDBUFFERSUBDATAPROC)(GLuint      buffer,
                                                        GLintptr    offset,
                                                        GLsizeiptr  size,
                                                        const void* data);
    PFNGLNAMEDBUFFERSUBDATAPROC glNamedBufferSubData;

    typedef void(APIENTRYP PFNGLCOPYNAMEDBUFFERSUBDATAPROC)(GLuint     readBuffer,
                                                            GLuint     writeBuffer,
                                                            GLintptr   readOffset,
                                                            GLintptr   writeOffset,
                                                            GLsizeiptr size);
    PFNGLCOPYNAMEDBUFFERSUBDATAPROC glCopyNamedBufferSubData;

    typedef void(APIENTRYP PFNGLCLEARNAMEDBUFFERDATAPROC)(GLuint      buffer,
                                                          GLenum      internalformat,
                                                          GLenum      format,
                                                          GLenum      type,
                                                          const void* data);
    PFNGLCLEARNAMEDBUFFERDATAPROC glClearNamedBufferData;

    typedef void(APIENTRYP PFNGLCLEARNAMEDBUFFERSUBDATAPROC)(GLuint      buffer,
                                                             GLenum      internalformat,
                                                             GLintptr    offset,
                                                             GLsizeiptr  size,
                                                             GLenum      format,
                                                             GLenum      type,
                                                             const void* data);
    PFNGLCLEARNAMEDBUFFERSUBDATAPROC glClearNamedBufferSubData;

    typedef void*(APIENTRYP PFNGLMAPNAMEDBUFFERPROC)(GLuint buffer, GLenum access);
    PFNGLMAPNAMEDBUFFERPROC glMapNamedBuffer;

    typedef void*(APIENTRYP PFNGLMAPNAMEDBUFFERRANGEPROC)(GLuint     buffer,
                                                          GLintptr   offset,
                                                          GLsizeiptr length,
                                                          GLbitfield access);
    PFNGLMAPNAMEDBUFFERRANGEPROC glMapNamedBufferRange;

    typedef GLboolean(APIENTRYP PFNGLUNMAPNAMEDBUFFERPROC)(GLuint buffer);
    PFNGLUNMAPNAMEDBUFFERPROC glUnmapNamedBuffer;

    typedef void(APIENTRYP PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length);
    PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC glFlushMappedNamedBufferRange;

    typedef void(APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERIVPROC)(GLuint buffer, GLenum pname, GLint* params);
    PFNGLGETNAMEDBUFFERPARAMETERIVPROC glGetNamedBufferParameteriv;

    typedef void(APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERI64VPROC)(GLuint buffer, GLenum pname, GLint64* params);
    PFNGLGETNAMEDBUFFERPARAMETERI64VPROC glGetNamedBufferParameteri64v;

    typedef void(APIENTRYP PFNGLGETNAMEDBUFFERPOINTERVPROC)(GLuint buffer, GLenum pname, void** params);
    PFNGLGETNAMEDBUFFERPOINTERVPROC glGetNamedBufferPointerv;

    typedef void(APIENTRYP PFNGLGETNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, void* data);
    PFNGLGETNAMEDBUFFERSUBDATAPROC glGetNamedBufferSubData;

    typedef void(APIENTRYP PFNGLCREATEFRAMEBUFFERSPROC)(GLsizei n, GLuint* framebuffers);
    PFNGLCREATEFRAMEBUFFERSPROC glCreateFramebuffers;

    typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC)(GLuint framebuffer,
                                                                  GLenum attachment,
                                                                  GLenum renderbuffertarget,
                                                                  GLuint renderbuffer);
    PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC glNamedFramebufferRenderbuffer;

    typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC)(GLuint framebuffer, GLenum pname, GLint param);
    PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC glNamedFramebufferParameteri;

    typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREPROC)(GLuint framebuffer,
                                                             GLenum attachment,
                                                             GLuint texture,
                                                             GLint  level);
    PFNGLNAMEDFRAMEBUFFERTEXTUREPROC glNamedFramebufferTexture;

    typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC)(GLuint framebuffer,
                                                                  GLenum attachment,
                                                                  GLuint texture,
                                                                  GLint  level,
                                                                  GLint  layer);
    PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC glNamedFramebufferTextureLayer;

    typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC)(GLuint framebuffer, GLenum buf);
    PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC glNamedFramebufferDrawBuffer;

    typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC)(GLuint framebuffer, GLsizei n, const GLenum* bufs);
    PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC glNamedFramebufferDrawBuffers;

    typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC)(GLuint framebuffer, GLenum src);
    PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC glNamedFramebufferReadBuffer;

    typedef void(APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC)(GLuint        framebuffer,
                                                                    GLsizei       numAttachments,
                                                                    const GLenum* attachments);
    PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC glInvalidateNamedFramebufferData;

    typedef void(APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC)(GLuint        framebuffer,
                                                                       GLsizei       numAttachments,
                                                                       const GLenum* attachments,
                                                                       GLint         x,
                                                                       GLint         y,
                                                                       GLsizei       width,
                                                                       GLsizei       height);
    PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC glInvalidateNamedFramebufferSubData;

    typedef void(APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERIVPROC)(GLuint       framebuffer,
                                                             GLenum       buffer,
                                                             GLint        drawbuffer,
                                                             const GLint* value);
    PFNGLCLEARNAMEDFRAMEBUFFERIVPROC glClearNamedFramebufferiv;

    typedef void(APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC)(GLuint        framebuffer,
                                                              GLenum        buffer,
                                                              GLint         drawbuffer,
                                                              const GLuint* value);
    PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC glClearNamedFramebufferuiv;

    typedef void(APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)(GLuint         framebuffer,
                                                             GLenum         buffer,
                                                             GLint          drawbuffer,
                                                             const GLfloat* value);
    PFNGLCLEARNAMEDFRAMEBUFFERFVPROC glClearNamedFramebufferfv;

    typedef void(APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFIPROC)(GLuint  framebuffer,
                                                             GLenum  buffer,
                                                             GLint   drawbuffer,
                                                             GLfloat depth,
                                                             GLint   stencil);
    PFNGLCLEARNAMEDFRAMEBUFFERFIPROC glClearNamedFramebufferfi;

    typedef void(APIENTRYP PFNGLBLITNAMEDFRAMEBUFFERPROC)(GLuint     readFramebuffer,
                                                          GLuint     drawFramebuffer,
                                                          GLint      srcX0,
                                                          GLint      srcY0,
                                                          GLint      srcX1,
                                                          GLint      srcY1,
                                                          GLint      dstX0,
                                                          GLint      dstY0,
                                                          GLint      dstX1,
                                                          GLint      dstY1,
                                                          GLbitfield mask,
                                                          GLenum     filter);
    PFNGLBLITNAMEDFRAMEBUFFERPROC glBlitNamedFramebuffer;

    typedef GLenum(APIENTRYP PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC)(GLuint framebuffer, GLenum target);
    PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC glCheckNamedFramebufferStatus;

    typedef void(APIENTRYP PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC)(GLuint framebuffer, GLenum pname, GLint* param);
    PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC glGetNamedFramebufferParameteriv;

    typedef void(APIENTRYP PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLuint framebuffer,
                                                                              GLenum attachment,
                                                                              GLenum pname,
                                                                              GLint* params);
    PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetNamedFramebufferAttachmentParameteriv;

    typedef void(APIENTRYP PFNGLCREATERENDERBUFFERSPROC)(GLsizei n, GLuint* renderbuffers);
    PFNGLCREATERENDERBUFFERSPROC glCreateRenderbuffers;

    typedef void(APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEPROC)(GLuint  renderbuffer,
                                                              GLenum  internalformat,
                                                              GLsizei width,
                                                              GLsizei height);
    PFNGLNAMEDRENDERBUFFERSTORAGEPROC glNamedRenderbufferStorage;

    typedef void(APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLuint  renderbuffer,
                                                                         GLsizei samples,
                                                                         GLenum  internalformat,
                                                                         GLsizei width,
                                                                         GLsizei height);
    PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC glNamedRenderbufferStorageMultisample;

    typedef void(APIENTRYP PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC)(GLuint renderbuffer, GLenum pname, GLint* params);
    PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC glGetNamedRenderbufferParameteriv;

    typedef void(APIENTRYP PFNGLCREATETEXTURESPROC)(GLenum target, GLsizei n, GLuint* textures);
    PFNGLCREATETEXTURESPROC glCreateTextures;

    typedef void(APIENTRYP PFNGLTEXTUREBUFFERPROC)(GLuint texture, GLenum internalformat, GLuint buffer);
    PFNGLTEXTUREBUFFERPROC glTextureBuffer;

    typedef void(APIENTRYP PFNGLTEXTUREBUFFERRANGEPROC)(GLuint     texture,
                                                        GLenum     internalformat,
                                                        GLuint     buffer,
                                                        GLintptr   offset,
                                                        GLsizeiptr size);
    PFNGLTEXTUREBUFFERRANGEPROC glTextureBufferRange;

    typedef void(APIENTRYP PFNGLTEXTURESTORAGE1DPROC)(GLuint  texture,
                                                      GLsizei levels,
                                                      GLenum  internalformat,
                                                      GLsizei width);
    PFNGLTEXTURESTORAGE1DPROC glTextureStorage1D;

    typedef void(APIENTRYP PFNGLTEXTURESTORAGE2DPROC)(GLuint  texture,
                                                      GLsizei levels,
                                                      GLenum  internalformat,
                                                      GLsizei width,
                                                      GLsizei height);
    PFNGLTEXTURESTORAGE2DPROC glTextureStorage2D;

    typedef void(APIENTRYP PFNGLTEXTURESTORAGE3DPROC)(GLuint  texture,
                                                      GLsizei levels,
                                                      GLenum  internalformat,
                                                      GLsizei width,
                                                      GLsizei height,
                                                      GLsizei depth);
    PFNGLTEXTURESTORAGE3DPROC glTextureStorage3D;

    typedef void(APIENTRYP PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC)(GLuint    texture,
                                                                 GLsizei   samples,
                                                                 GLenum    internalformat,
                                                                 GLsizei   width,
                                                                 GLsizei   height,
                                                                 GLboolean fixedsamplelocations);
    PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC glTextureStorage2DMultisample;

    typedef void(APIENTRYP PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC)(GLuint    texture,
                                                                 GLsizei   samples,
                                                                 GLenum    internalformat,
                                                                 GLsizei   width,
                                                                 GLsizei   height,
                                                                 GLsizei   depth,
                                                                 GLboolean fixedsamplelocations);
    PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC glTextureStorage3DMultisample;

    typedef void(APIENTRYP PFNGLTEXTURESUBIMAGE1DPROC)(GLuint      texture,
                                                       GLint       level,
                                                       GLint       xoffset,
                                                       GLsizei     width,
                                                       GLenum      format,
                                                       GLenum      type,
                                                       const void* pixels);
    PFNGLTEXTURESUBIMAGE1DPROC glTextureSubImage1D;

    typedef void(APIENTRYP PFNGLTEXTURESUBIMAGE2DPROC)(GLuint      texture,
                                                       GLint       level,
                                                       GLint       xoffset,
                                                       GLint       yoffset,
                                                       GLsizei     width,
                                                       GLsizei     height,
                                                       GLenum      format,
                                                       GLenum      type,
                                                       const void* pixels);
    PFNGLTEXTURESUBIMAGE2DPROC glTextureSubImage2D;

    typedef void(APIENTRYP PFNGLTEXTURESUBIMAGE3DPROC)(GLuint      texture,
                                                       GLint       level,
                                                       GLint       xoffset,
                                                       GLint       yoffset,
                                                       GLint       zoffset,
                                                       GLsizei     width,
                                                       GLsizei     height,
                                                       GLsizei     depth,
                                                       GLenum      format,
                                                       GLenum      type,
                                                       const void* pixels);
    PFNGLTEXTURESUBIMAGE3DPROC glTextureSubImage3D;

    typedef void(APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC)(GLuint      texture,
                                                                 GLint       level,
                                                                 GLint       xoffset,
                                                                 GLsizei     width,
                                                                 GLenum      format,
                                                                 GLsizei     imageSize,
                                                                 const void* data);
    PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC glCompressedTextureSubImage1D;

    typedef void(APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC)(GLuint      texture,
                                                                 GLint       level,
                                                                 GLint       xoffset,
                                                                 GLint       yoffset,
                                                                 GLsizei     width,
                                                                 GLsizei     height,
                                                                 GLenum      format,
                                                                 GLsizei     imageSize,
                                                                 const void* data);
    PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC glCompressedTextureSubImage2D;

    typedef void(APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC)(GLuint      texture,
                                                                 GLint       level,
                                                                 GLint       xoffset,
                                                                 GLint       yoffset,
                                                                 GLint       zoffset,
                                                                 GLsizei     width,
                                                                 GLsizei     height,
                                                                 GLsizei     depth,
                                                                 GLenum      format,
                                                                 GLsizei     imageSize,
                                                                 const void* data);
    PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC glCompressedTextureSubImage3D;

    typedef void(APIENTRYP PFNGLCOPYTEXTURESUBIMAGE1DPROC)(GLuint  texture,
                                                           GLint   level,
                                                           GLint   xoffset,
                                                           GLint   x,
                                                           GLint   y,
                                                           GLsizei width);
    PFNGLCOPYTEXTURESUBIMAGE1DPROC glCopyTextureSubImage1D;

    typedef void(APIENTRYP PFNGLCOPYTEXTURESUBIMAGE2DPROC)(GLuint  texture,
                                                           GLint   level,
                                                           GLint   xoffset,
                                                           GLint   yoffset,
                                                           GLint   x,
                                                           GLint   y,
                                                           GLsizei width,
                                                           GLsizei height);
    PFNGLCOPYTEXTURESUBIMAGE2DPROC glCopyTextureSubImage2D;

    typedef void(APIENTRYP PFNGLCOPYTEXTURESUBIMAGE3DPROC)(GLuint  texture,
                                                           GLint   level,
                                                           GLint   xoffset,
                                                           GLint   yoffset,
                                                           GLint   zoffset,
                                                           GLint   x,
                                                           GLint   y,
                                                           GLsizei width,
                                                           GLsizei height);
    PFNGLCOPYTEXTURESUBIMAGE3DPROC glCopyTextureSubImage3D;

    typedef void(APIENTRYP PFNGLTEXTUREPARAMETERFPROC)(GLuint texture, GLenum pname, GLfloat param);
    PFNGLTEXTUREPARAMETERFPROC glTextureParameterf;

    typedef void(APIENTRYP PFNGLTEXTUREPARAMETERFVPROC)(GLuint texture, GLenum pname, const GLfloat* param);
    PFNGLTEXTUREPARAMETERFVPROC glTextureParameterfv;

    typedef void(APIENTRYP PFNGLTEXTUREPARAMETERIPROC)(GLuint texture, GLenum pname, GLint param);
    PFNGLTEXTUREPARAMETERIPROC glTextureParameteri;

    typedef void(APIENTRYP PFNGLTEXTUREPARAMETERIIVPROC)(GLuint texture, GLenum pname, const GLint* params);
    PFNGLTEXTUREPARAMETERIIVPROC glTextureParameterIiv;

    typedef void(APIENTRYP PFNGLTEXTUREPARAMETERIUIVPROC)(GLuint texture, GLenum pname, const GLuint* params);
    PFNGLTEXTUREPARAMETERIUIVPROC glTextureParameterIuiv;

    typedef void(APIENTRYP PFNGLTEXTUREPARAMETERIVPROC)(GLuint texture, GLenum pname, const GLint* param);
    PFNGLTEXTUREPARAMETERIVPROC glTextureParameteriv;

    typedef void(APIENTRYP PFNGLGENERATETEXTUREMIPMAPPROC)(GLuint texture);
    PFNGLGENERATETEXTUREMIPMAPPROC glGenerateTextureMipmap;

    typedef void(APIENTRYP PFNGLBINDTEXTUREUNITPROC)(GLuint unit, GLuint texture);
    PFNGLBINDTEXTUREUNITPROC glBindTextureUnit;

    typedef void(APIENTRYP PFNGLGETTEXTUREIMAGEPROC)(GLuint  texture,
                                                     GLint   level,
                                                     GLenum  format,
                                                     GLenum  type,
                                                     GLsizei bufSize,
                                                     void*   pixels);
    PFNGLGETTEXTUREIMAGEPROC glGetTextureImage;

    typedef void(APIENTRYP PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC)(GLuint  texture,
                                                               GLint   level,
                                                               GLsizei bufSize,
                                                               void*   pixels);
    PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC glGetCompressedTextureImage;

    typedef void(APIENTRYP PFNGLGETTEXTURELEVELPARAMETERFVPROC)(GLuint   texture,
                                                                GLint    level,
                                                                GLenum   pname,
                                                                GLfloat* params);
    PFNGLGETTEXTURELEVELPARAMETERFVPROC glGetTextureLevelParameterfv;

    typedef void(APIENTRYP PFNGLGETTEXTURELEVELPARAMETERIVPROC)(GLuint texture,
                                                                GLint  level,
                                                                GLenum pname,
                                                                GLint* params);
    PFNGLGETTEXTURELEVELPARAMETERIVPROC glGetTextureLevelParameteriv;

    typedef void(APIENTRYP PFNGLGETTEXTUREPARAMETERFVPROC)(GLuint texture, GLenum pname, GLfloat* params);
    PFNGLGETTEXTUREPARAMETERFVPROC glGetTextureParameterfv;

    typedef void(APIENTRYP PFNGLGETTEXTUREPARAMETERIIVPROC)(GLuint texture, GLenum pname, GLint* params);
    PFNGLGETTEXTUREPARAMETERIIVPROC glGetTextureParameterIiv;

    typedef void(APIENTRYP PFNGLGETTEXTUREPARAMETERIUIVPROC)(GLuint texture, GLenum pname, GLuint* params);
    PFNGLGETTEXTUREPARAMETERIUIVPROC glGetTextureParameterIuiv;

    typedef void(APIENTRYP PFNGLGETTEXTUREPARAMETERIVPROC)(GLuint texture, GLenum pname, GLint* params);
    PFNGLGETTEXTUREPARAMETERIVPROC glGetTextureParameteriv;

    typedef void(APIENTRYP PFNGLCREATEVERTEXARRAYSPROC)(GLsizei n, GLuint* arrays);
    PFNGLCREATEVERTEXARRAYSPROC glCreateVertexArrays;

    typedef void(APIENTRYP PFNGLDISABLEVERTEXARRAYATTRIBPROC)(GLuint vaobj, GLuint index);
    PFNGLDISABLEVERTEXARRAYATTRIBPROC glDisableVertexArrayAttrib;

    typedef void(APIENTRYP PFNGLENABLEVERTEXARRAYATTRIBPROC)(GLuint vaobj, GLuint index);
    PFNGLENABLEVERTEXARRAYATTRIBPROC glEnableVertexArrayAttrib;

    typedef void(APIENTRYP PFNGLVERTEXARRAYELEMENTBUFFERPROC)(GLuint vaobj, GLuint buffer);
    PFNGLVERTEXARRAYELEMENTBUFFERPROC glVertexArrayElementBuffer;

    typedef void(APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERPROC)(GLuint   vaobj,
                                                             GLuint   bindingindex,
                                                             GLuint   buffer,
                                                             GLintptr offset,
                                                             GLsizei  stride);
    PFNGLVERTEXARRAYVERTEXBUFFERPROC glVertexArrayVertexBuffer;

    typedef void(APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERSPROC)(GLuint          vaobj,
                                                              GLuint          first,
                                                              GLsizei         count,
                                                              const GLuint*   buffers,
                                                              const GLintptr* offsets,
                                                              const GLsizei*  strides);
    PFNGLVERTEXARRAYVERTEXBUFFERSPROC glVertexArrayVertexBuffers;

    typedef void(APIENTRYP PFNGLVERTEXARRAYATTRIBBINDINGPROC)(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
    PFNGLVERTEXARRAYATTRIBBINDINGPROC glVertexArrayAttribBinding;

    typedef void(APIENTRYP PFNGLVERTEXARRAYATTRIBFORMATPROC)(GLuint    vaobj,
                                                             GLuint    attribindex,
                                                             GLint     size,
                                                             GLenum    type,
                                                             GLboolean normalized,
                                                             GLuint    relativeoffset);
    PFNGLVERTEXARRAYATTRIBFORMATPROC glVertexArrayAttribFormat;

    typedef void(APIENTRYP PFNGLVERTEXARRAYATTRIBIFORMATPROC)(GLuint vaobj,
                                                              GLuint attribindex,
                                                              GLint  size,
                                                              GLenum type,
                                                              GLuint relativeoffset);
    PFNGLVERTEXARRAYATTRIBIFORMATPROC glVertexArrayAttribIFormat;

    typedef void(APIENTRYP PFNGLVERTEXARRAYATTRIBLFORMATPROC)(GLuint vaobj,
                                                              GLuint attribindex,
                                                              GLint  size,
                                                              GLenum type,
                                                              GLuint relativeoffset);
    PFNGLVERTEXARRAYATTRIBLFORMATPROC glVertexArrayAttribLFormat;

    typedef void(APIENTRYP PFNGLVERTEXARRAYBINDINGDIVISORPROC)(GLuint vaobj, GLuint bindingindex, GLuint divisor);
    PFNGLVERTEXARRAYBINDINGDIVISORPROC glVertexArrayBindingDivisor;

    typedef void(APIENTRYP PFNGLGETVERTEXARRAYIVPROC)(GLuint vaobj, GLenum pname, GLint* param);
    PFNGLGETVERTEXARRAYIVPROC glGetVertexArrayiv;

    typedef void(APIENTRYP PFNGLGETVERTEXARRAYINDEXEDIVPROC)(GLuint vaobj, GLuint index, GLenum pname, GLint* param);
    PFNGLGETVERTEXARRAYINDEXEDIVPROC glGetVertexArrayIndexediv;

    typedef void(APIENTRYP PFNGLGETVERTEXARRAYINDEXED64IVPROC)(GLuint   vaobj,
                                                               GLuint   index,
                                                               GLenum   pname,
                                                               GLint64* param);
    PFNGLGETVERTEXARRAYINDEXED64IVPROC glGetVertexArrayIndexed64iv;

    typedef void(APIENTRYP PFNGLCREATESAMPLERSPROC)(GLsizei n, GLuint* samplers);
    PFNGLCREATESAMPLERSPROC glCreateSamplers;

    typedef void(APIENTRYP PFNGLCREATEPROGRAMPIPELINESPROC)(GLsizei n, GLuint* pipelines);
    PFNGLCREATEPROGRAMPIPELINESPROC glCreateProgramPipelines;

    typedef void(APIENTRYP PFNGLCREATEQUERIESPROC)(GLenum target, GLsizei n, GLuint* ids);
    PFNGLCREATEQUERIESPROC glCreateQueries;

    typedef void(APIENTRYP PFNGLGETQUERYBUFFEROBJECTI64VPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
    PFNGLGETQUERYBUFFEROBJECTI64VPROC glGetQueryBufferObjecti64v;

    typedef void(APIENTRYP PFNGLGETQUERYBUFFEROBJECTIVPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
    PFNGLGETQUERYBUFFEROBJECTIVPROC glGetQueryBufferObjectiv;

    typedef void(APIENTRYP PFNGLGETQUERYBUFFEROBJECTUI64VPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
    PFNGLGETQUERYBUFFEROBJECTUI64VPROC glGetQueryBufferObjectui64v;

    typedef void(APIENTRYP PFNGLGETQUERYBUFFEROBJECTUIVPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
    PFNGLGETQUERYBUFFEROBJECTUIVPROC glGetQueryBufferObjectuiv;

    typedef void(APIENTRYP PFNGLMEMORYBARRIERBYREGIONPROC)(GLbitfield barriers);
    PFNGLMEMORYBARRIERBYREGIONPROC glMemoryBarrierByRegion;

    typedef void(APIENTRYP PFNGLGETTEXTURESUBIMAGEPROC)(GLuint  texture,
                                                        GLint   level,
                                                        GLint   xoffset,
                                                        GLint   yoffset,
                                                        GLint   zoffset,
                                                        GLsizei width,
                                                        GLsizei height,
                                                        GLsizei depth,
                                                        GLenum  format,
                                                        GLenum  type,
                                                        GLsizei bufSize,
                                                        void*   pixels);
    PFNGLGETTEXTURESUBIMAGEPROC glGetTextureSubImage;

    typedef void(APIENTRYP PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC)(GLuint  texture,
                                                                  GLint   level,
                                                                  GLint   xoffset,
                                                                  GLint   yoffset,
                                                                  GLint   zoffset,
                                                                  GLsizei width,
                                                                  GLsizei height,
                                                                  GLsizei depth,
                                                                  GLsizei bufSize,
                                                                  void*   pixels);
    PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC glGetCompressedTextureSubImage;

    typedef GLenum(APIENTRYP PFNGLGETGRAPHICSRESETSTATUSPROC)(void);
    PFNGLGETGRAPHICSRESETSTATUSPROC glGetGraphicsResetStatus;

    typedef void(APIENTRYP PFNGLGETNCOMPRESSEDTEXIMAGEPROC)(GLenum target, GLint lod, GLsizei bufSize, void* pixels);
    PFNGLGETNCOMPRESSEDTEXIMAGEPROC glGetnCompressedTexImage;

    typedef void(APIENTRYP PFNGLGETNTEXIMAGEPROC)(GLenum  target,
                                                  GLint   level,
                                                  GLenum  format,
                                                  GLenum  type,
                                                  GLsizei bufSize,
                                                  void*   pixels);
    PFNGLGETNTEXIMAGEPROC glGetnTexImage;

    typedef void(APIENTRYP PFNGLGETNUNIFORMDVPROC)(GLuint program, GLint location, GLsizei bufSize, GLdouble* params);
    PFNGLGETNUNIFORMDVPROC glGetnUniformdv;

    typedef void(APIENTRYP PFNGLGETNUNIFORMFVPROC)(GLuint program, GLint location, GLsizei bufSize, GLfloat* params);
    PFNGLGETNUNIFORMFVPROC glGetnUniformfv;

    typedef void(APIENTRYP PFNGLGETNUNIFORMIVPROC)(GLuint program, GLint location, GLsizei bufSize, GLint* params);
    PFNGLGETNUNIFORMIVPROC glGetnUniformiv;

    typedef void(APIENTRYP PFNGLGETNUNIFORMUIVPROC)(GLuint program, GLint location, GLsizei bufSize, GLuint* params);
    PFNGLGETNUNIFORMUIVPROC glGetnUniformuiv;

    typedef void(APIENTRYP PFNGLREADNPIXELSPROC)(GLint   x,
                                                 GLint   y,
                                                 GLsizei width,
                                                 GLsizei height,
                                                 GLenum  format,
                                                 GLenum  type,
                                                 GLsizei bufSize,
                                                 void*   data);
    PFNGLREADNPIXELSPROC glReadnPixels;

    typedef void(APIENTRYP PFNGLGETNMAPDVPROC)(GLenum target, GLenum query, GLsizei bufSize, GLdouble* v);
    PFNGLGETNMAPDVPROC glGetnMapdv;

    typedef void(APIENTRYP PFNGLGETNMAPFVPROC)(GLenum target, GLenum query, GLsizei bufSize, GLfloat* v);
    PFNGLGETNMAPFVPROC glGetnMapfv;

    typedef void(APIENTRYP PFNGLGETNMAPIVPROC)(GLenum target, GLenum query, GLsizei bufSize, GLint* v);
    PFNGLGETNMAPIVPROC glGetnMapiv;

    typedef void(APIENTRYP PFNGLGETNPIXELMAPFVPROC)(GLenum map, GLsizei bufSize, GLfloat* values);
    PFNGLGETNPIXELMAPFVPROC glGetnPixelMapfv;

    typedef void(APIENTRYP PFNGLGETNPIXELMAPUIVPROC)(GLenum map, GLsizei bufSize, GLuint* values);
    PFNGLGETNPIXELMAPUIVPROC glGetnPixelMapuiv;

    typedef void(APIENTRYP PFNGLGETNPIXELMAPUSVPROC)(GLenum map, GLsizei bufSize, GLushort* values);
    PFNGLGETNPIXELMAPUSVPROC glGetnPixelMapusv;

    typedef void(APIENTRYP PFNGLGETNPOLYGONSTIPPLEPROC)(GLsizei bufSize, GLubyte* pattern);
    PFNGLGETNPOLYGONSTIPPLEPROC glGetnPolygonStipple;

    typedef void(
        APIENTRYP PFNGLGETNCOLORTABLEPROC)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void* table);
    PFNGLGETNCOLORTABLEPROC glGetnColorTable;

    typedef void(APIENTRYP PFNGLGETNCONVOLUTIONFILTERPROC)(GLenum  target,
                                                           GLenum  format,
                                                           GLenum  type,
                                                           GLsizei bufSize,
                                                           void*   image);
    PFNGLGETNCONVOLUTIONFILTERPROC glGetnConvolutionFilter;

    typedef void(APIENTRYP PFNGLGETNSEPARABLEFILTERPROC)(GLenum  target,
                                                         GLenum  format,
                                                         GLenum  type,
                                                         GLsizei rowBufSize,
                                                         void*   row,
                                                         GLsizei columnBufSize,
                                                         void*   column,
                                                         void*   span);
    PFNGLGETNSEPARABLEFILTERPROC glGetnSeparableFilter;

    typedef void(APIENTRYP PFNGLGETNHISTOGRAMPROC)(GLenum    target,
                                                   GLboolean reset,
                                                   GLenum    format,
                                                   GLenum    type,
                                                   GLsizei   bufSize,
                                                   void*     values);
    PFNGLGETNHISTOGRAMPROC glGetnHistogram;

    typedef void(APIENTRYP PFNGLGETNMINMAXPROC)(GLenum    target,
                                                GLboolean reset,
                                                GLenum    format,
                                                GLenum    type,
                                                GLsizei   bufSize,
                                                void*     values);
    PFNGLGETNMINMAXPROC glGetnMinmax;

    typedef void(APIENTRYP PFNGLTEXTUREBARRIERPROC)(void);
    PFNGLTEXTUREBARRIERPROC glTextureBarrier;

  public:
    GLfuncsv450();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
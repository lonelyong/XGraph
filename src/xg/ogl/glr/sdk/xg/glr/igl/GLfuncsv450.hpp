#pragma once

#include <xg/glr/igl/GLfuncsv440.h>

namespace glr {
class GLR_API GLfuncsv450 : public GLfuncsv440 {

  public:
    typedef void(APIENTRYP PFNGLCLIPCONTROLPROC)(GLenum_t origin, GLenum_t depth);
    PFNGLCLIPCONTROLPROC iglClipControl;

    typedef void(APIENTRYP PFNGLCREATETRANSFORMFEEDBACKSPROC)(GLsizei_t n, GLuint_t* ids);
    PFNGLCREATETRANSFORMFEEDBACKSPROC iglCreateTransformFeedbacks;

    typedef void(APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC)(GLuint_t xfb, GLuint_t index, GLuint_t buffer);
    PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC iglTransformFeedbackBufferBase;

    typedef void(APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC)(GLuint_t     xfb,
                                                                  GLuint_t     index,
                                                                  GLuint_t     buffer,
                                                                  GLintptr   offset,
                                                                  GLsizeiptr size);
    PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC iglTransformFeedbackBufferRange;

    typedef void(APIENTRYP PFNGLGETTRANSFORMFEEDBACKIVPROC)(GLuint_t xfb, GLenum_t pname, GLint_t* param);
    PFNGLGETTRANSFORMFEEDBACKIVPROC iglGetTransformFeedbackiv;

    typedef void(APIENTRYP PFNGLGETTRANSFORMFEEDBACKI_VPROC)(GLuint_t xfb, GLenum_t pname, GLuint_t index, GLint_t* param);
    PFNGLGETTRANSFORMFEEDBACKI_VPROC iglGetTransformFeedbacki_v;

    typedef void(APIENTRYP PFNGLGETTRANSFORMFEEDBACKI64_VPROC)(GLuint_t xfb, GLenum_t pname, GLuint_t index, GLint64* param);
    PFNGLGETTRANSFORMFEEDBACKI64_VPROC iglGetTransformFeedbacki64_v;

    typedef void(APIENTRYP PFNGLCREATEBUFFERSPROC)(GLsizei_t n, GLuint_t* buffers);
    PFNGLCREATEBUFFERSPROC iglCreateBuffers;

    typedef void(APIENTRYP PFNGLNAMEDBUFFERSTORAGEPROC)(GLuint_t      buffer,
                                                        GLsizeiptr  size,
                                                        const void* data,
                                                        GLbitfield_t  flags);
    PFNGLNAMEDBUFFERSTORAGEPROC iglNamedBufferStorage;

    typedef void(APIENTRYP PFNGLNAMEDBUFFERDATAPROC)(GLuint_t buffer, GLsizeiptr size, const void* data, GLenum_t usage);
    PFNGLNAMEDBUFFERDATAPROC iglNamedBufferData;

    typedef void(APIENTRYP PFNGLNAMEDBUFFERSUBDATAPROC)(GLuint_t      buffer,
                                                        GLintptr    offset,
                                                        GLsizeiptr  size,
                                                        const void* data);
    PFNGLNAMEDBUFFERSUBDATAPROC iglNamedBufferSubData;

    typedef void(APIENTRYP PFNGLCOPYNAMEDBUFFERSUBDATAPROC)(GLuint_t     readBuffer,
                                                            GLuint_t     writeBuffer,
                                                            GLintptr   readOffset,
                                                            GLintptr   writeOffset,
                                                            GLsizeiptr size);
    PFNGLCOPYNAMEDBUFFERSUBDATAPROC iglCopyNamedBufferSubData;

    typedef void(APIENTRYP PFNGLCLEARNAMEDBUFFERDATAPROC)(GLuint_t      buffer,
                                                          GLenum_t      internalformat,
                                                          GLenum_t      format,
                                                          GLenum_t      type,
                                                          const void* data);
    PFNGLCLEARNAMEDBUFFERDATAPROC iglClearNamedBufferData;

    typedef void(APIENTRYP PFNGLCLEARNAMEDBUFFERSUBDATAPROC)(GLuint_t      buffer,
                                                             GLenum_t      internalformat,
                                                             GLintptr    offset,
                                                             GLsizeiptr  size,
                                                             GLenum_t      format,
                                                             GLenum_t      type,
                                                             const void* data);
    PFNGLCLEARNAMEDBUFFERSUBDATAPROC iglClearNamedBufferSubData;

    typedef void*(APIENTRYP PFNGLMAPNAMEDBUFFERPROC)(GLuint_t buffer, GLenum_t access);
    PFNGLMAPNAMEDBUFFERPROC iglMapNamedBuffer;

    typedef void*(APIENTRYP PFNGLMAPNAMEDBUFFERRANGEPROC)(GLuint_t     buffer,
                                                          GLintptr   offset,
                                                          GLsizeiptr length,
                                                          GLbitfield_t access);
    PFNGLMAPNAMEDBUFFERRANGEPROC iglMapNamedBufferRange;

    typedef GLboolean_t(APIENTRYP PFNGLUNMAPNAMEDBUFFERPROC)(GLuint_t buffer);
    PFNGLUNMAPNAMEDBUFFERPROC iglUnmapNamedBuffer;

    typedef void(APIENTRYP PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC)(GLuint_t buffer, GLintptr offset, GLsizeiptr length);
    PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC iglFlushMappedNamedBufferRange;

    typedef void(APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERIVPROC)(GLuint_t buffer, GLenum_t pname, GLint_t* params);
    PFNGLGETNAMEDBUFFERPARAMETERIVPROC iglGetNamedBufferParameteriv;

    typedef void(APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERI64VPROC)(GLuint_t buffer, GLenum_t pname, GLint64* params);
    PFNGLGETNAMEDBUFFERPARAMETERI64VPROC iglGetNamedBufferParameteri64v;

    typedef void(APIENTRYP PFNGLGETNAMEDBUFFERPOINTERVPROC)(GLuint_t buffer, GLenum_t pname, void** params);
    PFNGLGETNAMEDBUFFERPOINTERVPROC iglGetNamedBufferPointerv;

    typedef void(APIENTRYP PFNGLGETNAMEDBUFFERSUBDATAPROC)(GLuint_t buffer, GLintptr offset, GLsizeiptr size, void* data);
    PFNGLGETNAMEDBUFFERSUBDATAPROC iglGetNamedBufferSubData;

    typedef void(APIENTRYP PFNGLCREATEFRAMEBUFFERSPROC)(GLsizei_t n, GLuint_t* framebuffers);
    PFNGLCREATEFRAMEBUFFERSPROC iglCreateFramebuffers;

    typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC)(GLuint_t framebuffer,
                                                                  GLenum_t attachment,
                                                                  GLenum_t renderbuffertarget,
                                                                  GLuint_t renderbuffer);
    PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC iglNamedFramebufferRenderbuffer;

    typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC)(GLuint_t framebuffer, GLenum_t pname, GLint_t param);
    PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC iglNamedFramebufferParameteri;

    typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREPROC)(GLuint_t framebuffer,
                                                             GLenum_t attachment,
                                                             GLuint_t texture,
                                                             GLint_t  level);
    PFNGLNAMEDFRAMEBUFFERTEXTUREPROC iglNamedFramebufferTexture;

    typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC)(GLuint_t framebuffer,
                                                                  GLenum_t attachment,
                                                                  GLuint_t texture,
                                                                  GLint_t  level,
                                                                  GLint_t  layer);
    PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC iglNamedFramebufferTextureLayer;

    typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC)(GLuint_t framebuffer, GLenum_t buf);
    PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC iglNamedFramebufferDrawBuffer;

    typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC)(GLuint_t framebuffer, GLsizei_t n, const GLenum_t* bufs);
    PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC iglNamedFramebufferDrawBuffers;

    typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC)(GLuint_t framebuffer, GLenum_t src);
    PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC iglNamedFramebufferReadBuffer;

    typedef void(APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC)(GLuint_t        framebuffer,
                                                                    GLsizei_t       numAttachments,
                                                                    const GLenum_t* attachments);
    PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC iglInvalidateNamedFramebufferData;

    typedef void(APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC)(GLuint_t        framebuffer,
                                                                       GLsizei_t       numAttachments,
                                                                       const GLenum_t* attachments,
                                                                       GLint_t         x,
                                                                       GLint_t         y,
                                                                       GLsizei_t       width,
                                                                       GLsizei_t       height);
    PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC iglInvalidateNamedFramebufferSubData;

    typedef void(APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERIVPROC)(GLuint_t       framebuffer,
                                                             GLenum_t       buffer,
                                                             GLint_t        drawbuffer,
                                                             const GLint_t* value);
    PFNGLCLEARNAMEDFRAMEBUFFERIVPROC iglClearNamedFramebufferiv;

    typedef void(APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC)(GLuint_t        framebuffer,
                                                              GLenum_t        buffer,
                                                              GLint_t         drawbuffer,
                                                              const GLuint_t* value);
    PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC iglClearNamedFramebufferuiv;

    typedef void(APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)(GLuint_t         framebuffer,
                                                             GLenum_t         buffer,
                                                             GLint_t          drawbuffer,
                                                             const GLfloat_t* value);
    PFNGLCLEARNAMEDFRAMEBUFFERFVPROC iglClearNamedFramebufferfv;

    typedef void(APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFIPROC)(GLuint_t  framebuffer,
                                                             GLenum_t  buffer,
                                                             GLint_t   drawbuffer,
                                                             GLfloat_t depth,
                                                             GLint_t   stencil);
    PFNGLCLEARNAMEDFRAMEBUFFERFIPROC iglClearNamedFramebufferfi;

    typedef void(APIENTRYP PFNGLBLITNAMEDFRAMEBUFFERPROC)(GLuint_t     readFramebuffer,
                                                          GLuint_t     drawFramebuffer,
                                                          GLint_t      srcX0,
                                                          GLint_t      srcY0,
                                                          GLint_t      srcX1,
                                                          GLint_t      srcY1,
                                                          GLint_t      dstX0,
                                                          GLint_t      dstY0,
                                                          GLint_t      dstX1,
                                                          GLint_t      dstY1,
                                                          GLbitfield_t mask,
                                                          GLenum_t     filter);
    PFNGLBLITNAMEDFRAMEBUFFERPROC iglBlitNamedFramebuffer;

    typedef GLenum_t(APIENTRYP PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC)(GLuint_t framebuffer, GLenum_t target);
    PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC iglCheckNamedFramebufferStatus;

    typedef void(APIENTRYP PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC)(GLuint_t framebuffer, GLenum_t pname, GLint_t* param);
    PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC iglGetNamedFramebufferParameteriv;

    typedef void(APIENTRYP PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLuint_t framebuffer,
                                                                              GLenum_t attachment,
                                                                              GLenum_t pname,
                                                                              GLint_t* params);
    PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC iglGetNamedFramebufferAttachmentParameteriv;

    typedef void(APIENTRYP PFNGLCREATERENDERBUFFERSPROC)(GLsizei_t n, GLuint_t* renderbuffers);
    PFNGLCREATERENDERBUFFERSPROC iglCreateRenderbuffers;

    typedef void(APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEPROC)(GLuint_t  renderbuffer,
                                                              GLenum_t  internalformat,
                                                              GLsizei_t width,
                                                              GLsizei_t height);
    PFNGLNAMEDRENDERBUFFERSTORAGEPROC iglNamedRenderbufferStorage;

    typedef void(APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLuint_t  renderbuffer,
                                                                         GLsizei_t samples,
                                                                         GLenum_t  internalformat,
                                                                         GLsizei_t width,
                                                                         GLsizei_t height);
    PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC iglNamedRenderbufferStorageMultisample;

    typedef void(APIENTRYP PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC)(GLuint_t renderbuffer, GLenum_t pname, GLint_t* params);
    PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC iglGetNamedRenderbufferParameteriv;

    typedef void(APIENTRYP PFNGLCREATETEXTURESPROC)(GLenum_t target, GLsizei_t n, GLuint_t* textures);
    PFNGLCREATETEXTURESPROC iglCreateTextures;

    typedef void(APIENTRYP PFNGLTEXTUREBUFFERPROC)(GLuint_t texture, GLenum_t internalformat, GLuint_t buffer);
    PFNGLTEXTUREBUFFERPROC iglTextureBuffer;

    typedef void(APIENTRYP PFNGLTEXTUREBUFFERRANGEPROC)(GLuint_t     texture,
                                                        GLenum_t     internalformat,
                                                        GLuint_t     buffer,
                                                        GLintptr   offset,
                                                        GLsizeiptr size);
    PFNGLTEXTUREBUFFERRANGEPROC iglTextureBufferRange;

    typedef void(APIENTRYP PFNGLTEXTURESTORAGE1DPROC)(GLuint_t  texture,
                                                      GLsizei_t levels,
                                                      GLenum_t  internalformat,
                                                      GLsizei_t width);
    PFNGLTEXTURESTORAGE1DPROC iglTextureStorage1D;

    typedef void(APIENTRYP PFNGLTEXTURESTORAGE2DPROC)(GLuint_t  texture,
                                                      GLsizei_t levels,
                                                      GLenum_t  internalformat,
                                                      GLsizei_t width,
                                                      GLsizei_t height);
    PFNGLTEXTURESTORAGE2DPROC iglTextureStorage2D;

    typedef void(APIENTRYP PFNGLTEXTURESTORAGE3DPROC)(GLuint_t  texture,
                                                      GLsizei_t levels,
                                                      GLenum_t  internalformat,
                                                      GLsizei_t width,
                                                      GLsizei_t height,
                                                      GLsizei_t depth);
    PFNGLTEXTURESTORAGE3DPROC iglTextureStorage3D;

    typedef void(APIENTRYP PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC)(GLuint_t    texture,
                                                                 GLsizei_t   samples,
                                                                 GLenum_t    internalformat,
                                                                 GLsizei_t   width,
                                                                 GLsizei_t   height,
                                                                 GLboolean_t fixedsamplelocations);
    PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC iglTextureStorage2DMultisample;

    typedef void(APIENTRYP PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC)(GLuint_t    texture,
                                                                 GLsizei_t   samples,
                                                                 GLenum_t    internalformat,
                                                                 GLsizei_t   width,
                                                                 GLsizei_t   height,
                                                                 GLsizei_t   depth,
                                                                 GLboolean_t fixedsamplelocations);
    PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC iglTextureStorage3DMultisample;

    typedef void(APIENTRYP PFNGLTEXTURESUBIMAGE1DPROC)(GLuint_t      texture,
                                                       GLint_t       level,
                                                       GLint_t       xoffset,
                                                       GLsizei_t     width,
                                                       GLenum_t      format,
                                                       GLenum_t      type,
                                                       const void* pixels);
    PFNGLTEXTURESUBIMAGE1DPROC iglTextureSubImage1D;

    typedef void(APIENTRYP PFNGLTEXTURESUBIMAGE2DPROC)(GLuint_t      texture,
                                                       GLint_t       level,
                                                       GLint_t       xoffset,
                                                       GLint_t       yoffset,
                                                       GLsizei_t     width,
                                                       GLsizei_t     height,
                                                       GLenum_t      format,
                                                       GLenum_t      type,
                                                       const void* pixels);
    PFNGLTEXTURESUBIMAGE2DPROC iglTextureSubImage2D;

    typedef void(APIENTRYP PFNGLTEXTURESUBIMAGE3DPROC)(GLuint_t      texture,
                                                       GLint_t       level,
                                                       GLint_t       xoffset,
                                                       GLint_t       yoffset,
                                                       GLint_t       zoffset,
                                                       GLsizei_t     width,
                                                       GLsizei_t     height,
                                                       GLsizei_t     depth,
                                                       GLenum_t      format,
                                                       GLenum_t      type,
                                                       const void* pixels);
    PFNGLTEXTURESUBIMAGE3DPROC iglTextureSubImage3D;

    typedef void(APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC)(GLuint_t      texture,
                                                                 GLint_t       level,
                                                                 GLint_t       xoffset,
                                                                 GLsizei_t     width,
                                                                 GLenum_t      format,
                                                                 GLsizei_t     imageSize,
                                                                 const void* data);
    PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC iglCompressedTextureSubImage1D;

    typedef void(APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC)(GLuint_t      texture,
                                                                 GLint_t       level,
                                                                 GLint_t       xoffset,
                                                                 GLint_t       yoffset,
                                                                 GLsizei_t     width,
                                                                 GLsizei_t     height,
                                                                 GLenum_t      format,
                                                                 GLsizei_t     imageSize,
                                                                 const void* data);
    PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC iglCompressedTextureSubImage2D;

    typedef void(APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC)(GLuint_t      texture,
                                                                 GLint_t       level,
                                                                 GLint_t       xoffset,
                                                                 GLint_t       yoffset,
                                                                 GLint_t       zoffset,
                                                                 GLsizei_t     width,
                                                                 GLsizei_t     height,
                                                                 GLsizei_t     depth,
                                                                 GLenum_t      format,
                                                                 GLsizei_t     imageSize,
                                                                 const void* data);
    PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC iglCompressedTextureSubImage3D;

    typedef void(APIENTRYP PFNGLCOPYTEXTURESUBIMAGE1DPROC)(GLuint_t  texture,
                                                           GLint_t   level,
                                                           GLint_t   xoffset,
                                                           GLint_t   x,
                                                           GLint_t   y,
                                                           GLsizei_t width);
    PFNGLCOPYTEXTURESUBIMAGE1DPROC iglCopyTextureSubImage1D;

    typedef void(APIENTRYP PFNGLCOPYTEXTURESUBIMAGE2DPROC)(GLuint_t  texture,
                                                           GLint_t   level,
                                                           GLint_t   xoffset,
                                                           GLint_t   yoffset,
                                                           GLint_t   x,
                                                           GLint_t   y,
                                                           GLsizei_t width,
                                                           GLsizei_t height);
    PFNGLCOPYTEXTURESUBIMAGE2DPROC iglCopyTextureSubImage2D;

    typedef void(APIENTRYP PFNGLCOPYTEXTURESUBIMAGE3DPROC)(GLuint_t  texture,
                                                           GLint_t   level,
                                                           GLint_t   xoffset,
                                                           GLint_t   yoffset,
                                                           GLint_t   zoffset,
                                                           GLint_t   x,
                                                           GLint_t   y,
                                                           GLsizei_t width,
                                                           GLsizei_t height);
    PFNGLCOPYTEXTURESUBIMAGE3DPROC iglCopyTextureSubImage3D;

    typedef void(APIENTRYP PFNGLTEXTUREPARAMETERFPROC)(GLuint_t texture, GLenum_t pname, GLfloat_t param);
    PFNGLTEXTUREPARAMETERFPROC iglTextureParameterf;

    typedef void(APIENTRYP PFNGLTEXTUREPARAMETERFVPROC)(GLuint_t texture, GLenum_t pname, const GLfloat_t* param);
    PFNGLTEXTUREPARAMETERFVPROC iglTextureParameterfv;

    typedef void(APIENTRYP PFNGLTEXTUREPARAMETERIPROC)(GLuint_t texture, GLenum_t pname, GLint_t param);
    PFNGLTEXTUREPARAMETERIPROC iglTextureParameteri;

    typedef void(APIENTRYP PFNGLTEXTUREPARAMETERIIVPROC)(GLuint_t texture, GLenum_t pname, const GLint_t* params);
    PFNGLTEXTUREPARAMETERIIVPROC iglTextureParameterIiv;

    typedef void(APIENTRYP PFNGLTEXTUREPARAMETERIUIVPROC)(GLuint_t texture, GLenum_t pname, const GLuint_t* params);
    PFNGLTEXTUREPARAMETERIUIVPROC iglTextureParameterIuiv;

    typedef void(APIENTRYP PFNGLTEXTUREPARAMETERIVPROC)(GLuint_t texture, GLenum_t pname, const GLint_t* param);
    PFNGLTEXTUREPARAMETERIVPROC iglTextureParameteriv;

    typedef void(APIENTRYP PFNGLGENERATETEXTUREMIPMAPPROC)(GLuint_t texture);
    PFNGLGENERATETEXTUREMIPMAPPROC iglGenerateTextureMipmap;

    typedef void(APIENTRYP PFNGLBINDTEXTUREUNITPROC)(GLuint_t unit, GLuint_t texture);
    PFNGLBINDTEXTUREUNITPROC iglBindTextureUnit;

    typedef void(APIENTRYP PFNGLGETTEXTUREIMAGEPROC)(GLuint_t  texture,
                                                     GLint_t   level,
                                                     GLenum_t  format,
                                                     GLenum_t  type,
                                                     GLsizei_t bufSize,
                                                     void*   pixels);
    PFNGLGETTEXTUREIMAGEPROC iglGetTextureImage;

    typedef void(APIENTRYP PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC)(GLuint_t  texture,
                                                               GLint_t   level,
                                                               GLsizei_t bufSize,
                                                               void*   pixels);
    PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC iglGetCompressedTextureImage;

    typedef void(APIENTRYP PFNGLGETTEXTURELEVELPARAMETERFVPROC)(GLuint_t   texture,
                                                                GLint_t    level,
                                                                GLenum_t   pname,
                                                                GLfloat_t* params);
    PFNGLGETTEXTURELEVELPARAMETERFVPROC iglGetTextureLevelParameterfv;

    typedef void(APIENTRYP PFNGLGETTEXTURELEVELPARAMETERIVPROC)(GLuint_t texture,
                                                                GLint_t  level,
                                                                GLenum_t pname,
                                                                GLint_t* params);
    PFNGLGETTEXTURELEVELPARAMETERIVPROC iglGetTextureLevelParameteriv;

    typedef void(APIENTRYP PFNGLGETTEXTUREPARAMETERFVPROC)(GLuint_t texture, GLenum_t pname, GLfloat_t* params);
    PFNGLGETTEXTUREPARAMETERFVPROC iglGetTextureParameterfv;

    typedef void(APIENTRYP PFNGLGETTEXTUREPARAMETERIIVPROC)(GLuint_t texture, GLenum_t pname, GLint_t* params);
    PFNGLGETTEXTUREPARAMETERIIVPROC iglGetTextureParameterIiv;

    typedef void(APIENTRYP PFNGLGETTEXTUREPARAMETERIUIVPROC)(GLuint_t texture, GLenum_t pname, GLuint_t* params);
    PFNGLGETTEXTUREPARAMETERIUIVPROC iglGetTextureParameterIuiv;

    typedef void(APIENTRYP PFNGLGETTEXTUREPARAMETERIVPROC)(GLuint_t texture, GLenum_t pname, GLint_t* params);
    PFNGLGETTEXTUREPARAMETERIVPROC iglGetTextureParameteriv;

    typedef void(APIENTRYP PFNGLCREATEVERTEXARRAYSPROC)(GLsizei_t n, GLuint_t* arrays);
    PFNGLCREATEVERTEXARRAYSPROC iglCreateVertexArrays;

    typedef void(APIENTRYP PFNGLDISABLEVERTEXARRAYATTRIBPROC)(GLuint_t vaobj, GLuint_t index);
    PFNGLDISABLEVERTEXARRAYATTRIBPROC iglDisableVertexArrayAttrib;

    typedef void(APIENTRYP PFNGLENABLEVERTEXARRAYATTRIBPROC)(GLuint_t vaobj, GLuint_t index);
    PFNGLENABLEVERTEXARRAYATTRIBPROC iglEnableVertexArrayAttrib;

    typedef void(APIENTRYP PFNGLVERTEXARRAYELEMENTBUFFERPROC)(GLuint_t vaobj, GLuint_t buffer);
    PFNGLVERTEXARRAYELEMENTBUFFERPROC iglVertexArrayElementBuffer;

    typedef void(APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERPROC)(GLuint_t   vaobj,
                                                             GLuint_t   bindingindex,
                                                             GLuint_t   buffer,
                                                             GLintptr offset,
                                                             GLsizei_t  stride);
    PFNGLVERTEXARRAYVERTEXBUFFERPROC iglVertexArrayVertexBuffer;

    typedef void(APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERSPROC)(GLuint_t          vaobj,
                                                              GLuint_t          first,
                                                              GLsizei_t         count,
                                                              const GLuint_t*   buffers,
                                                              const GLintptr* offsets,
                                                              const GLsizei_t*  strides);
    PFNGLVERTEXARRAYVERTEXBUFFERSPROC iglVertexArrayVertexBuffers;

    typedef void(APIENTRYP PFNGLVERTEXARRAYATTRIBBINDINGPROC)(GLuint_t vaobj, GLuint_t attribindex, GLuint_t bindingindex);
    PFNGLVERTEXARRAYATTRIBBINDINGPROC iglVertexArrayAttribBinding;

    typedef void(APIENTRYP PFNGLVERTEXARRAYATTRIBFORMATPROC)(GLuint_t    vaobj,
                                                             GLuint_t    attribindex,
                                                             GLint_t     size,
                                                             GLenum_t    type,
                                                             GLboolean_t normalized,
                                                             GLuint_t    relativeoffset);
    PFNGLVERTEXARRAYATTRIBFORMATPROC iglVertexArrayAttribFormat;

    typedef void(APIENTRYP PFNGLVERTEXARRAYATTRIBIFORMATPROC)(GLuint_t vaobj,
                                                              GLuint_t attribindex,
                                                              GLint_t  size,
                                                              GLenum_t type,
                                                              GLuint_t relativeoffset);
    PFNGLVERTEXARRAYATTRIBIFORMATPROC iglVertexArrayAttribIFormat;

    typedef void(APIENTRYP PFNGLVERTEXARRAYATTRIBLFORMATPROC)(GLuint_t vaobj,
                                                              GLuint_t attribindex,
                                                              GLint_t  size,
                                                              GLenum_t type,
                                                              GLuint_t relativeoffset);
    PFNGLVERTEXARRAYATTRIBLFORMATPROC iglVertexArrayAttribLFormat;

    typedef void(APIENTRYP PFNGLVERTEXARRAYBINDINGDIVISORPROC)(GLuint_t vaobj, GLuint_t bindingindex, GLuint_t divisor);
    PFNGLVERTEXARRAYBINDINGDIVISORPROC iglVertexArrayBindingDivisor;

    typedef void(APIENTRYP PFNGLGETVERTEXARRAYIVPROC)(GLuint_t vaobj, GLenum_t pname, GLint_t* param);
    PFNGLGETVERTEXARRAYIVPROC iglGetVertexArrayiv;

    typedef void(APIENTRYP PFNGLGETVERTEXARRAYINDEXEDIVPROC)(GLuint_t vaobj, GLuint_t index, GLenum_t pname, GLint_t* param);
    PFNGLGETVERTEXARRAYINDEXEDIVPROC iglGetVertexArrayIndexediv;

    typedef void(APIENTRYP PFNGLGETVERTEXARRAYINDEXED64IVPROC)(GLuint_t   vaobj,
                                                               GLuint_t   index,
                                                               GLenum_t   pname,
                                                               GLint64* param);
    PFNGLGETVERTEXARRAYINDEXED64IVPROC iglGetVertexArrayIndexed64iv;

    typedef void(APIENTRYP PFNGLCREATESAMPLERSPROC)(GLsizei_t n, GLuint_t* samplers);
    PFNGLCREATESAMPLERSPROC iglCreateSamplers;

    typedef void(APIENTRYP PFNGLCREATEPROGRAMPIPELINESPROC)(GLsizei_t n, GLuint_t* pipelines);
    PFNGLCREATEPROGRAMPIPELINESPROC iglCreateProgramPipelines;

    typedef void(APIENTRYP PFNGLCREATEQUERIESPROC)(GLenum_t target, GLsizei_t n, GLuint_t* ids);
    PFNGLCREATEQUERIESPROC iglCreateQueries;

    typedef void(APIENTRYP PFNGLGETQUERYBUFFEROBJECTI64VPROC)(GLuint_t id, GLuint_t buffer, GLenum_t pname, GLintptr offset);
    PFNGLGETQUERYBUFFEROBJECTI64VPROC iglGetQueryBufferObjecti64v;

    typedef void(APIENTRYP PFNGLGETQUERYBUFFEROBJECTIVPROC)(GLuint_t id, GLuint_t buffer, GLenum_t pname, GLintptr offset);
    PFNGLGETQUERYBUFFEROBJECTIVPROC iglGetQueryBufferObjectiv;

    typedef void(APIENTRYP PFNGLGETQUERYBUFFEROBJECTUI64VPROC)(GLuint_t id, GLuint_t buffer, GLenum_t pname, GLintptr offset);
    PFNGLGETQUERYBUFFEROBJECTUI64VPROC iglGetQueryBufferObjectui64v;

    typedef void(APIENTRYP PFNGLGETQUERYBUFFEROBJECTUIVPROC)(GLuint_t id, GLuint_t buffer, GLenum_t pname, GLintptr offset);
    PFNGLGETQUERYBUFFEROBJECTUIVPROC iglGetQueryBufferObjectuiv;

    typedef void(APIENTRYP PFNGLMEMORYBARRIERBYREGIONPROC)(GLbitfield_t barriers);
    PFNGLMEMORYBARRIERBYREGIONPROC iglMemoryBarrierByRegion;

    typedef void(APIENTRYP PFNGLGETTEXTURESUBIMAGEPROC)(GLuint_t  texture,
                                                        GLint_t   level,
                                                        GLint_t   xoffset,
                                                        GLint_t   yoffset,
                                                        GLint_t   zoffset,
                                                        GLsizei_t width,
                                                        GLsizei_t height,
                                                        GLsizei_t depth,
                                                        GLenum_t  format,
                                                        GLenum_t  type,
                                                        GLsizei_t bufSize,
                                                        void*   pixels);
    PFNGLGETTEXTURESUBIMAGEPROC iglGetTextureSubImage;

    typedef void(APIENTRYP PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC)(GLuint_t  texture,
                                                                  GLint_t   level,
                                                                  GLint_t   xoffset,
                                                                  GLint_t   yoffset,
                                                                  GLint_t   zoffset,
                                                                  GLsizei_t width,
                                                                  GLsizei_t height,
                                                                  GLsizei_t depth,
                                                                  GLsizei_t bufSize,
                                                                  void*   pixels);
    PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC iglGetCompressedTextureSubImage;

    typedef GLenum_t(APIENTRYP PFNGLGETGRAPHICSRESETSTATUSPROC)(void);
    PFNGLGETGRAPHICSRESETSTATUSPROC iglGetGraphicsResetStatus;

    typedef void(APIENTRYP PFNGLGETNCOMPRESSEDTEXIMAGEPROC)(GLenum_t target, GLint_t lod, GLsizei_t bufSize, void* pixels);
    PFNGLGETNCOMPRESSEDTEXIMAGEPROC iglGetnCompressedTexImage;

    typedef void(APIENTRYP PFNGLGETNTEXIMAGEPROC)(GLenum_t  target,
                                                  GLint_t   level,
                                                  GLenum_t  format,
                                                  GLenum_t  type,
                                                  GLsizei_t bufSize,
                                                  void*   pixels);
    PFNGLGETNTEXIMAGEPROC iglGetnTexImage;

    typedef void(APIENTRYP PFNGLGETNUNIFORMDVPROC)(GLuint_t program, GLint_t location, GLsizei_t bufSize, GLdouble_t* params);
    PFNGLGETNUNIFORMDVPROC iglGetnUniformdv;

    typedef void(APIENTRYP PFNGLGETNUNIFORMFVPROC)(GLuint_t program, GLint_t location, GLsizei_t bufSize, GLfloat_t* params);
    PFNGLGETNUNIFORMFVPROC iglGetnUniformfv;

    typedef void(APIENTRYP PFNGLGETNUNIFORMIVPROC)(GLuint_t program, GLint_t location, GLsizei_t bufSize, GLint_t* params);
    PFNGLGETNUNIFORMIVPROC iglGetnUniformiv;

    typedef void(APIENTRYP PFNGLGETNUNIFORMUIVPROC)(GLuint_t program, GLint_t location, GLsizei_t bufSize, GLuint_t* params);
    PFNGLGETNUNIFORMUIVPROC iglGetnUniformuiv;

    typedef void(APIENTRYP PFNGLREADNPIXELSPROC)(GLint_t   x,
                                                 GLint_t   y,
                                                 GLsizei_t width,
                                                 GLsizei_t height,
                                                 GLenum_t  format,
                                                 GLenum_t  type,
                                                 GLsizei_t bufSize,
                                                 void*   data);
    PFNGLREADNPIXELSPROC iglReadnPixels;

    typedef void(APIENTRYP PFNGLGETNMAPDVPROC)(GLenum_t target, GLenum_t query, GLsizei_t bufSize, GLdouble_t* v);
    PFNGLGETNMAPDVPROC iglGetnMapdv;

    typedef void(APIENTRYP PFNGLGETNMAPFVPROC)(GLenum_t target, GLenum_t query, GLsizei_t bufSize, GLfloat_t* v);
    PFNGLGETNMAPFVPROC iglGetnMapfv;

    typedef void(APIENTRYP PFNGLGETNMAPIVPROC)(GLenum_t target, GLenum_t query, GLsizei_t bufSize, GLint_t* v);
    PFNGLGETNMAPIVPROC iglGetnMapiv;

    typedef void(APIENTRYP PFNGLGETNPIXELMAPFVPROC)(GLenum_t map, GLsizei_t bufSize, GLfloat_t* values);
    PFNGLGETNPIXELMAPFVPROC iglGetnPixelMapfv;

    typedef void(APIENTRYP PFNGLGETNPIXELMAPUIVPROC)(GLenum_t map, GLsizei_t bufSize, GLuint_t* values);
    PFNGLGETNPIXELMAPUIVPROC iglGetnPixelMapuiv;

    typedef void(APIENTRYP PFNGLGETNPIXELMAPUSVPROC)(GLenum_t map, GLsizei_t bufSize, GLushort* values);
    PFNGLGETNPIXELMAPUSVPROC iglGetnPixelMapusv;

    typedef void(APIENTRYP PFNGLGETNPOLYGONSTIPPLEPROC)(GLsizei_t bufSize, GLubyte* pattern);
    PFNGLGETNPOLYGONSTIPPLEPROC iglGetnPolygonStipple;

    typedef void(
        APIENTRYP PFNGLGETNCOLORTABLEPROC)(GLenum_t target, GLenum_t format, GLenum_t type, GLsizei_t bufSize, void* table);
    PFNGLGETNCOLORTABLEPROC iglGetnColorTable;

    typedef void(APIENTRYP PFNGLGETNCONVOLUTIONFILTERPROC)(GLenum_t  target,
                                                           GLenum_t  format,
                                                           GLenum_t  type,
                                                           GLsizei_t bufSize,
                                                           void*   image);
    PFNGLGETNCONVOLUTIONFILTERPROC iglGetnConvolutionFilter;

    typedef void(APIENTRYP PFNGLGETNSEPARABLEFILTERPROC)(GLenum_t  target,
                                                         GLenum_t  format,
                                                         GLenum_t  type,
                                                         GLsizei_t rowBufSize,
                                                         void*   row,
                                                         GLsizei_t columnBufSize,
                                                         void*   column,
                                                         void*   span);
    PFNGLGETNSEPARABLEFILTERPROC iglGetnSeparableFilter;

    typedef void(APIENTRYP PFNGLGETNHISTOGRAMPROC)(GLenum_t    target,
                                                   GLboolean_t reset,
                                                   GLenum_t    format,
                                                   GLenum_t    type,
                                                   GLsizei_t   bufSize,
                                                   void*     values);
    PFNGLGETNHISTOGRAMPROC iglGetnHistogram;

    typedef void(APIENTRYP PFNGLGETNMINMAXPROC)(GLenum_t    target,
                                                GLboolean_t reset,
                                                GLenum_t    format,
                                                GLenum_t    type,
                                                GLsizei_t   bufSize,
                                                void*     values);
    PFNGLGETNMINMAXPROC iglGetnMinmax;

    typedef void(APIENTRYP PFNGLTEXTUREBARRIERPROC)(void);
    PFNGLTEXTUREBARRIERPROC iglTextureBarrier;

  public:
    GLfuncsv450();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
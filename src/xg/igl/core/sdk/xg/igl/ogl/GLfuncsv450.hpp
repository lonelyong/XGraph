#pragma once

#include <xg/igl/ogl/GLfuncsv440.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API GLfuncsv450 : public GLfuncsv440 {

  public:
    typedef void(APIENTRYP PFNGLCLIPCONTROLPROC)(GLenum_t origin, GLenum_t depth);
    PFNGLCLIPCONTROLPROC oglClipControl;

    typedef void(APIENTRYP PFNGLCREATETRANSFORMFEEDBACKSPROC)(GLsizei_t n, GLuint_t* ids);
    PFNGLCREATETRANSFORMFEEDBACKSPROC oglCreateTransformFeedbacks;

    typedef void(APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC)(GLuint_t xfb, GLuint_t index, GLuint_t buffer);
    PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC oglTransformFeedbackBufferBase;

    typedef void(APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC)(GLuint_t xfb, GLuint_t index, GLuint_t buffer, GLintptr offset, GLsizeiptr size);
    PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC oglTransformFeedbackBufferRange;

    typedef void(APIENTRYP PFNGLGETTRANSFORMFEEDBACKIVPROC)(GLuint_t xfb, GLenum_t pname, GLint_t* param);
    PFNGLGETTRANSFORMFEEDBACKIVPROC oglGetTransformFeedbackiv;

    typedef void(APIENTRYP PFNGLGETTRANSFORMFEEDBACKI_VPROC)(GLuint_t xfb, GLenum_t pname, GLuint_t index, GLint_t* param);
    PFNGLGETTRANSFORMFEEDBACKI_VPROC oglGetTransformFeedbacki_v;

    typedef void(APIENTRYP PFNGLGETTRANSFORMFEEDBACKI64_VPROC)(GLuint_t xfb, GLenum_t pname, GLuint_t index, GLint64* param);
    PFNGLGETTRANSFORMFEEDBACKI64_VPROC oglGetTransformFeedbacki64_v;

    typedef void(APIENTRYP PFNGLCREATEBUFFERSPROC)(GLsizei_t n, GLuint_t* buffers);
    PFNGLCREATEBUFFERSPROC oglCreateBuffers;

    typedef void(APIENTRYP PFNGLNAMEDBUFFERSTORAGEPROC)(GLuint_t buffer, GLsizeiptr size, const void* data, GLbitfield_t flags);
    PFNGLNAMEDBUFFERSTORAGEPROC oglNamedBufferStorage;

    typedef void(APIENTRYP PFNGLNAMEDBUFFERDATAPROC)(GLuint_t buffer, GLsizeiptr size, const void* data, GLenum_t usage);
    PFNGLNAMEDBUFFERDATAPROC oglNamedBufferData;

    typedef void(APIENTRYP PFNGLNAMEDBUFFERSUBDATAPROC)(GLuint_t buffer, GLintptr offset, GLsizeiptr size, const void* data);
    PFNGLNAMEDBUFFERSUBDATAPROC oglNamedBufferSubData;

    typedef void(
        APIENTRYP PFNGLCOPYNAMEDBUFFERSUBDATAPROC)(GLuint_t readBuffer, GLuint_t writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
    PFNGLCOPYNAMEDBUFFERSUBDATAPROC oglCopyNamedBufferSubData;

    typedef void(APIENTRYP PFNGLCLEARNAMEDBUFFERDATAPROC)(GLuint_t buffer, GLenum_t internalformat, GLenum_t format, GLenum_t type, const void* data);
    PFNGLCLEARNAMEDBUFFERDATAPROC oglClearNamedBufferData;

    typedef void(APIENTRYP PFNGLCLEARNAMEDBUFFERSUBDATAPROC)(GLuint_t    buffer,
                                                             GLenum_t    internalformat,
                                                             GLintptr    offset,
                                                             GLsizeiptr  size,
                                                             GLenum_t    format,
                                                             GLenum_t    type,
                                                             const void* data);
    PFNGLCLEARNAMEDBUFFERSUBDATAPROC oglClearNamedBufferSubData;

    typedef void*(APIENTRYP PFNGLMAPNAMEDBUFFERPROC)(GLuint_t buffer, GLenum_t access);
    PFNGLMAPNAMEDBUFFERPROC oglMapNamedBuffer;

    typedef void*(APIENTRYP PFNGLMAPNAMEDBUFFERRANGEPROC)(GLuint_t buffer, GLintptr offset, GLsizeiptr length, GLbitfield_t access);
    PFNGLMAPNAMEDBUFFERRANGEPROC oglMapNamedBufferRange;

    typedef GLboolean_t(APIENTRYP PFNGLUNMAPNAMEDBUFFERPROC)(GLuint_t buffer);
    PFNGLUNMAPNAMEDBUFFERPROC oglUnmapNamedBuffer;

    typedef void(APIENTRYP PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC)(GLuint_t buffer, GLintptr offset, GLsizeiptr length);
    PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC oglFlushMappedNamedBufferRange;

    typedef void(APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERIVPROC)(GLuint_t buffer, GLenum_t pname, GLint_t* params);
    PFNGLGETNAMEDBUFFERPARAMETERIVPROC oglGetNamedBufferParameteriv;

    typedef void(APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERI64VPROC)(GLuint_t buffer, GLenum_t pname, GLint64* params);
    PFNGLGETNAMEDBUFFERPARAMETERI64VPROC oglGetNamedBufferParameteri64v;

    typedef void(APIENTRYP PFNGLGETNAMEDBUFFERPOINTERVPROC)(GLuint_t buffer, GLenum_t pname, void** params);
    PFNGLGETNAMEDBUFFERPOINTERVPROC oglGetNamedBufferPointerv;

    typedef void(APIENTRYP PFNGLGETNAMEDBUFFERSUBDATAPROC)(GLuint_t buffer, GLintptr offset, GLsizeiptr size, void* data);
    PFNGLGETNAMEDBUFFERSUBDATAPROC oglGetNamedBufferSubData;

    typedef void(APIENTRYP PFNGLCREATEFRAMEBUFFERSPROC)(GLsizei_t n, GLuint_t* framebuffers);
    PFNGLCREATEFRAMEBUFFERSPROC oglCreateFramebuffers;

    typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC)(GLuint_t framebuffer,
                                                                  GLenum_t attachment,
                                                                  GLenum_t renderbuffertarget,
                                                                  GLuint_t renderbuffer);
    PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC oglNamedFramebufferRenderbuffer;

    typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC)(GLuint_t framebuffer, GLenum_t pname, GLint_t param);
    PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC oglNamedFramebufferParameteri;

    typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREPROC)(GLuint_t framebuffer, GLenum_t attachment, GLuint_t texture, GLint_t level);
    PFNGLNAMEDFRAMEBUFFERTEXTUREPROC oglNamedFramebufferTexture;

    typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC)(GLuint_t framebuffer, GLenum_t attachment, GLuint_t texture, GLint_t level, GLint_t layer);
    PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC oglNamedFramebufferTextureLayer;

    typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC)(GLuint_t framebuffer, GLenum_t buf);
    PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC oglNamedFramebufferDrawBuffer;

    typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC)(GLuint_t framebuffer, GLsizei_t n, const GLenum_t* bufs);
    PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC oglNamedFramebufferDrawBuffers;

    typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC)(GLuint_t framebuffer, GLenum_t src);
    PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC oglNamedFramebufferReadBuffer;

    typedef void(APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC)(GLuint_t framebuffer, GLsizei_t numAttachments, const GLenum_t* attachments);
    PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC oglInvalidateNamedFramebufferData;

    typedef void(APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC)(GLuint_t        framebuffer,
                                                                       GLsizei_t       numAttachments,
                                                                       const GLenum_t* attachments,
                                                                       GLint_t         x,
                                                                       GLint_t         y,
                                                                       GLsizei_t       width,
                                                                       GLsizei_t       height);
    PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC oglInvalidateNamedFramebufferSubData;

    typedef void(APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERIVPROC)(GLuint_t framebuffer, GLenum_t buffer, GLint_t drawbuffer, const GLint_t* value);
    PFNGLCLEARNAMEDFRAMEBUFFERIVPROC oglClearNamedFramebufferiv;

    typedef void(APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC)(GLuint_t framebuffer, GLenum_t buffer, GLint_t drawbuffer, const GLuint_t* value);
    PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC oglClearNamedFramebufferuiv;

    typedef void(APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)(GLuint_t framebuffer, GLenum_t buffer, GLint_t drawbuffer, const GLfloat_t* value);
    PFNGLCLEARNAMEDFRAMEBUFFERFVPROC oglClearNamedFramebufferfv;

    typedef void(APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFIPROC)(GLuint_t framebuffer, GLenum_t buffer, GLint_t drawbuffer, GLfloat_t depth, GLint_t stencil);
    PFNGLCLEARNAMEDFRAMEBUFFERFIPROC oglClearNamedFramebufferfi;

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
    PFNGLBLITNAMEDFRAMEBUFFERPROC oglBlitNamedFramebuffer;

    typedef GLenum_t(APIENTRYP PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC)(GLuint_t framebuffer, GLenum_t target);
    PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC oglCheckNamedFramebufferStatus;

    typedef void(APIENTRYP PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC)(GLuint_t framebuffer, GLenum_t pname, GLint_t* param);
    PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC oglGetNamedFramebufferParameteriv;

    typedef void(APIENTRYP PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLuint_t framebuffer, GLenum_t attachment, GLenum_t pname, GLint_t* params);
    PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC oglGetNamedFramebufferAttachmentParameteriv;

    typedef void(APIENTRYP PFNGLCREATERENDERBUFFERSPROC)(GLsizei_t n, GLuint_t* renderbuffers);
    PFNGLCREATERENDERBUFFERSPROC oglCreateRenderbuffers;

    typedef void(APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEPROC)(GLuint_t renderbuffer, GLenum_t internalformat, GLsizei_t width, GLsizei_t height);
    PFNGLNAMEDRENDERBUFFERSTORAGEPROC oglNamedRenderbufferStorage;

    typedef void(APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLuint_t  renderbuffer,
                                                                         GLsizei_t samples,
                                                                         GLenum_t  internalformat,
                                                                         GLsizei_t width,
                                                                         GLsizei_t height);
    PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC oglNamedRenderbufferStorageMultisample;

    typedef void(APIENTRYP PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC)(GLuint_t renderbuffer, GLenum_t pname, GLint_t* params);
    PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC oglGetNamedRenderbufferParameteriv;

    typedef void(APIENTRYP PFNGLCREATETEXTURESPROC)(GLenum_t target, GLsizei_t n, GLuint_t* textures);
    PFNGLCREATETEXTURESPROC oglCreateTextures;

    typedef void(APIENTRYP PFNGLTEXTUREBUFFERPROC)(GLuint_t texture, GLenum_t internalformat, GLuint_t buffer);
    PFNGLTEXTUREBUFFERPROC oglTextureBuffer;

    typedef void(APIENTRYP PFNGLTEXTUREBUFFERRANGEPROC)(GLuint_t texture, GLenum_t internalformat, GLuint_t buffer, GLintptr offset, GLsizeiptr size);
    PFNGLTEXTUREBUFFERRANGEPROC oglTextureBufferRange;

    typedef void(APIENTRYP PFNGLTEXTURESTORAGE1DPROC)(GLuint_t texture, GLsizei_t levels, GLenum_t internalformat, GLsizei_t width);
    PFNGLTEXTURESTORAGE1DPROC oglTextureStorage1D;

    typedef void(APIENTRYP PFNGLTEXTURESTORAGE2DPROC)(GLuint_t texture, GLsizei_t levels, GLenum_t internalformat, GLsizei_t width, GLsizei_t height);
    PFNGLTEXTURESTORAGE2DPROC oglTextureStorage2D;

    typedef void(
        APIENTRYP PFNGLTEXTURESTORAGE3DPROC)(GLuint_t texture, GLsizei_t levels, GLenum_t internalformat, GLsizei_t width, GLsizei_t height, GLsizei_t depth);
    PFNGLTEXTURESTORAGE3DPROC oglTextureStorage3D;

    typedef void(APIENTRYP PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC)(GLuint_t    texture,
                                                                 GLsizei_t   samples,
                                                                 GLenum_t    internalformat,
                                                                 GLsizei_t   width,
                                                                 GLsizei_t   height,
                                                                 GLboolean_t fixedsamplelocations);
    PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC oglTextureStorage2DMultisample;

    typedef void(APIENTRYP PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC)(GLuint_t    texture,
                                                                 GLsizei_t   samples,
                                                                 GLenum_t    internalformat,
                                                                 GLsizei_t   width,
                                                                 GLsizei_t   height,
                                                                 GLsizei_t   depth,
                                                                 GLboolean_t fixedsamplelocations);
    PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC oglTextureStorage3DMultisample;

    typedef void(APIENTRYP PFNGLTEXTURESUBIMAGE1DPROC)(GLuint_t    texture,
                                                       GLint_t     level,
                                                       GLint_t     xoffset,
                                                       GLsizei_t   width,
                                                       GLenum_t    format,
                                                       GLenum_t    type,
                                                       const void* pixels);
    PFNGLTEXTURESUBIMAGE1DPROC oglTextureSubImage1D;

    typedef void(APIENTRYP PFNGLTEXTURESUBIMAGE2DPROC)(GLuint_t    texture,
                                                       GLint_t     level,
                                                       GLint_t     xoffset,
                                                       GLint_t     yoffset,
                                                       GLsizei_t   width,
                                                       GLsizei_t   height,
                                                       GLenum_t    format,
                                                       GLenum_t    type,
                                                       const void* pixels);
    PFNGLTEXTURESUBIMAGE2DPROC oglTextureSubImage2D;

    typedef void(APIENTRYP PFNGLTEXTURESUBIMAGE3DPROC)(GLuint_t    texture,
                                                       GLint_t     level,
                                                       GLint_t     xoffset,
                                                       GLint_t     yoffset,
                                                       GLint_t     zoffset,
                                                       GLsizei_t   width,
                                                       GLsizei_t   height,
                                                       GLsizei_t   depth,
                                                       GLenum_t    format,
                                                       GLenum_t    type,
                                                       const void* pixels);
    PFNGLTEXTURESUBIMAGE3DPROC oglTextureSubImage3D;

    typedef void(APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC)(GLuint_t    texture,
                                                                 GLint_t     level,
                                                                 GLint_t     xoffset,
                                                                 GLsizei_t   width,
                                                                 GLenum_t    format,
                                                                 GLsizei_t   imageSize,
                                                                 const void* data);
    PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC oglCompressedTextureSubImage1D;

    typedef void(APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC)(GLuint_t    texture,
                                                                 GLint_t     level,
                                                                 GLint_t     xoffset,
                                                                 GLint_t     yoffset,
                                                                 GLsizei_t   width,
                                                                 GLsizei_t   height,
                                                                 GLenum_t    format,
                                                                 GLsizei_t   imageSize,
                                                                 const void* data);
    PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC oglCompressedTextureSubImage2D;

    typedef void(APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC)(GLuint_t    texture,
                                                                 GLint_t     level,
                                                                 GLint_t     xoffset,
                                                                 GLint_t     yoffset,
                                                                 GLint_t     zoffset,
                                                                 GLsizei_t   width,
                                                                 GLsizei_t   height,
                                                                 GLsizei_t   depth,
                                                                 GLenum_t    format,
                                                                 GLsizei_t   imageSize,
                                                                 const void* data);
    PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC oglCompressedTextureSubImage3D;

    typedef void(APIENTRYP PFNGLCOPYTEXTURESUBIMAGE1DPROC)(GLuint_t texture, GLint_t level, GLint_t xoffset, GLint_t x, GLint_t y, GLsizei_t width);
    PFNGLCOPYTEXTURESUBIMAGE1DPROC oglCopyTextureSubImage1D;

    typedef void(APIENTRYP PFNGLCOPYTEXTURESUBIMAGE2DPROC)(GLuint_t  texture,
                                                           GLint_t   level,
                                                           GLint_t   xoffset,
                                                           GLint_t   yoffset,
                                                           GLint_t   x,
                                                           GLint_t   y,
                                                           GLsizei_t width,
                                                           GLsizei_t height);
    PFNGLCOPYTEXTURESUBIMAGE2DPROC oglCopyTextureSubImage2D;

    typedef void(APIENTRYP PFNGLCOPYTEXTURESUBIMAGE3DPROC)(GLuint_t  texture,
                                                           GLint_t   level,
                                                           GLint_t   xoffset,
                                                           GLint_t   yoffset,
                                                           GLint_t   zoffset,
                                                           GLint_t   x,
                                                           GLint_t   y,
                                                           GLsizei_t width,
                                                           GLsizei_t height);
    PFNGLCOPYTEXTURESUBIMAGE3DPROC oglCopyTextureSubImage3D;

    typedef void(APIENTRYP PFNGLTEXTUREPARAMETERFPROC)(GLuint_t texture, GLenum_t pname, GLfloat_t param);
    PFNGLTEXTUREPARAMETERFPROC oglTextureParameterf;

    typedef void(APIENTRYP PFNGLTEXTUREPARAMETERFVPROC)(GLuint_t texture, GLenum_t pname, const GLfloat_t* param);
    PFNGLTEXTUREPARAMETERFVPROC oglTextureParameterfv;

    typedef void(APIENTRYP PFNGLTEXTUREPARAMETERIPROC)(GLuint_t texture, GLenum_t pname, GLint_t param);
    PFNGLTEXTUREPARAMETERIPROC oglTextureParameteri;

    typedef void(APIENTRYP PFNGLTEXTUREPARAMETERIIVPROC)(GLuint_t texture, GLenum_t pname, const GLint_t* params);
    PFNGLTEXTUREPARAMETERIIVPROC oglTextureParameterIiv;

    typedef void(APIENTRYP PFNGLTEXTUREPARAMETERIUIVPROC)(GLuint_t texture, GLenum_t pname, const GLuint_t* params);
    PFNGLTEXTUREPARAMETERIUIVPROC oglTextureParameterIuiv;

    typedef void(APIENTRYP PFNGLTEXTUREPARAMETERIVPROC)(GLuint_t texture, GLenum_t pname, const GLint_t* param);
    PFNGLTEXTUREPARAMETERIVPROC oglTextureParameteriv;

    typedef void(APIENTRYP PFNGLGENERATETEXTUREMIPMAPPROC)(GLuint_t texture);
    PFNGLGENERATETEXTUREMIPMAPPROC oglGenerateTextureMipmap;

    typedef void(APIENTRYP PFNGLBINDTEXTUREUNITPROC)(GLuint_t unit, GLuint_t texture);
    PFNGLBINDTEXTUREUNITPROC oglBindTextureUnit;

    typedef void(APIENTRYP PFNGLGETTEXTUREIMAGEPROC)(GLuint_t texture, GLint_t level, GLenum_t format, GLenum_t type, GLsizei_t bufSize, void* pixels);
    PFNGLGETTEXTUREIMAGEPROC oglGetTextureImage;

    typedef void(APIENTRYP PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC)(GLuint_t texture, GLint_t level, GLsizei_t bufSize, void* pixels);
    PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC oglGetCompressedTextureImage;

    typedef void(APIENTRYP PFNGLGETTEXTURELEVELPARAMETERFVPROC)(GLuint_t texture, GLint_t level, GLenum_t pname, GLfloat_t* params);
    PFNGLGETTEXTURELEVELPARAMETERFVPROC oglGetTextureLevelParameterfv;

    typedef void(APIENTRYP PFNGLGETTEXTURELEVELPARAMETERIVPROC)(GLuint_t texture, GLint_t level, GLenum_t pname, GLint_t* params);
    PFNGLGETTEXTURELEVELPARAMETERIVPROC oglGetTextureLevelParameteriv;

    typedef void(APIENTRYP PFNGLGETTEXTUREPARAMETERFVPROC)(GLuint_t texture, GLenum_t pname, GLfloat_t* params);
    PFNGLGETTEXTUREPARAMETERFVPROC oglGetTextureParameterfv;

    typedef void(APIENTRYP PFNGLGETTEXTUREPARAMETERIIVPROC)(GLuint_t texture, GLenum_t pname, GLint_t* params);
    PFNGLGETTEXTUREPARAMETERIIVPROC oglGetTextureParameterIiv;

    typedef void(APIENTRYP PFNGLGETTEXTUREPARAMETERIUIVPROC)(GLuint_t texture, GLenum_t pname, GLuint_t* params);
    PFNGLGETTEXTUREPARAMETERIUIVPROC oglGetTextureParameterIuiv;

    typedef void(APIENTRYP PFNGLGETTEXTUREPARAMETERIVPROC)(GLuint_t texture, GLenum_t pname, GLint_t* params);
    PFNGLGETTEXTUREPARAMETERIVPROC oglGetTextureParameteriv;

    typedef void(APIENTRYP PFNGLCREATEVERTEXARRAYSPROC)(GLsizei_t n, GLuint_t* arrays);
    PFNGLCREATEVERTEXARRAYSPROC oglCreateVertexArrays;

    typedef void(APIENTRYP PFNGLDISABLEVERTEXARRAYATTRIBPROC)(GLuint_t vaobj, GLuint_t index);
    PFNGLDISABLEVERTEXARRAYATTRIBPROC oglDisableVertexArrayAttrib;

    typedef void(APIENTRYP PFNGLENABLEVERTEXARRAYATTRIBPROC)(GLuint_t vaobj, GLuint_t index);
    PFNGLENABLEVERTEXARRAYATTRIBPROC oglEnableVertexArrayAttrib;

    typedef void(APIENTRYP PFNGLVERTEXARRAYELEMENTBUFFERPROC)(GLuint_t vaobj, GLuint_t buffer);
    PFNGLVERTEXARRAYELEMENTBUFFERPROC oglVertexArrayElementBuffer;

    typedef void(APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERPROC)(GLuint_t vaobj, GLuint_t bindingindex, GLuint_t buffer, GLintptr offset, GLsizei_t stride);
    PFNGLVERTEXARRAYVERTEXBUFFERPROC oglVertexArrayVertexBuffer;

    typedef void(APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERSPROC)(GLuint_t         vaobj,
                                                              GLuint_t         first,
                                                              GLsizei_t        count,
                                                              const GLuint_t*  buffers,
                                                              const GLintptr*  offsets,
                                                              const GLsizei_t* strides);
    PFNGLVERTEXARRAYVERTEXBUFFERSPROC oglVertexArrayVertexBuffers;

    typedef void(APIENTRYP PFNGLVERTEXARRAYATTRIBBINDINGPROC)(GLuint_t vaobj, GLuint_t attribindex, GLuint_t bindingindex);
    PFNGLVERTEXARRAYATTRIBBINDINGPROC oglVertexArrayAttribBinding;

    typedef void(APIENTRYP PFNGLVERTEXARRAYATTRIBFORMATPROC)(GLuint_t    vaobj,
                                                             GLuint_t    attribindex,
                                                             GLint_t     size,
                                                             GLenum_t    type,
                                                             GLboolean_t normalized,
                                                             GLuint_t    relativeoffset);
    PFNGLVERTEXARRAYATTRIBFORMATPROC oglVertexArrayAttribFormat;

    typedef void(APIENTRYP PFNGLVERTEXARRAYATTRIBIFORMATPROC)(GLuint_t vaobj, GLuint_t attribindex, GLint_t size, GLenum_t type, GLuint_t relativeoffset);
    PFNGLVERTEXARRAYATTRIBIFORMATPROC oglVertexArrayAttribIFormat;

    typedef void(APIENTRYP PFNGLVERTEXARRAYATTRIBLFORMATPROC)(GLuint_t vaobj, GLuint_t attribindex, GLint_t size, GLenum_t type, GLuint_t relativeoffset);
    PFNGLVERTEXARRAYATTRIBLFORMATPROC oglVertexArrayAttribLFormat;

    typedef void(APIENTRYP PFNGLVERTEXARRAYBINDINGDIVISORPROC)(GLuint_t vaobj, GLuint_t bindingindex, GLuint_t divisor);
    PFNGLVERTEXARRAYBINDINGDIVISORPROC oglVertexArrayBindingDivisor;

    typedef void(APIENTRYP PFNGLGETVERTEXARRAYIVPROC)(GLuint_t vaobj, GLenum_t pname, GLint_t* param);
    PFNGLGETVERTEXARRAYIVPROC oglGetVertexArrayiv;

    typedef void(APIENTRYP PFNGLGETVERTEXARRAYINDEXEDIVPROC)(GLuint_t vaobj, GLuint_t index, GLenum_t pname, GLint_t* param);
    PFNGLGETVERTEXARRAYINDEXEDIVPROC oglGetVertexArrayIndexediv;

    typedef void(APIENTRYP PFNGLGETVERTEXARRAYINDEXED64IVPROC)(GLuint_t vaobj, GLuint_t index, GLenum_t pname, GLint64* param);
    PFNGLGETVERTEXARRAYINDEXED64IVPROC oglGetVertexArrayIndexed64iv;

    typedef void(APIENTRYP PFNGLCREATESAMPLERSPROC)(GLsizei_t n, GLuint_t* samplers);
    PFNGLCREATESAMPLERSPROC oglCreateSamplers;

    typedef void(APIENTRYP PFNGLCREATEPROGRAMPIPELINESPROC)(GLsizei_t n, GLuint_t* pipelines);
    PFNGLCREATEPROGRAMPIPELINESPROC oglCreateProgramPipelines;

    typedef void(APIENTRYP PFNGLCREATEQUERIESPROC)(GLenum_t target, GLsizei_t n, GLuint_t* ids);
    PFNGLCREATEQUERIESPROC oglCreateQueries;

    typedef void(APIENTRYP PFNGLGETQUERYBUFFEROBJECTI64VPROC)(GLuint_t id, GLuint_t buffer, GLenum_t pname, GLintptr offset);
    PFNGLGETQUERYBUFFEROBJECTI64VPROC oglGetQueryBufferObjecti64v;

    typedef void(APIENTRYP PFNGLGETQUERYBUFFEROBJECTIVPROC)(GLuint_t id, GLuint_t buffer, GLenum_t pname, GLintptr offset);
    PFNGLGETQUERYBUFFEROBJECTIVPROC oglGetQueryBufferObjectiv;

    typedef void(APIENTRYP PFNGLGETQUERYBUFFEROBJECTUI64VPROC)(GLuint_t id, GLuint_t buffer, GLenum_t pname, GLintptr offset);
    PFNGLGETQUERYBUFFEROBJECTUI64VPROC oglGetQueryBufferObjectui64v;

    typedef void(APIENTRYP PFNGLGETQUERYBUFFEROBJECTUIVPROC)(GLuint_t id, GLuint_t buffer, GLenum_t pname, GLintptr offset);
    PFNGLGETQUERYBUFFEROBJECTUIVPROC oglGetQueryBufferObjectuiv;

    typedef void(APIENTRYP PFNGLMEMORYBARRIERBYREGIONPROC)(GLbitfield_t barriers);
    PFNGLMEMORYBARRIERBYREGIONPROC oglMemoryBarrierByRegion;

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
                                                        void*     pixels);
    PFNGLGETTEXTURESUBIMAGEPROC oglGetTextureSubImage;

    typedef void(APIENTRYP PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC)(GLuint_t  texture,
                                                                  GLint_t   level,
                                                                  GLint_t   xoffset,
                                                                  GLint_t   yoffset,
                                                                  GLint_t   zoffset,
                                                                  GLsizei_t width,
                                                                  GLsizei_t height,
                                                                  GLsizei_t depth,
                                                                  GLsizei_t bufSize,
                                                                  void*     pixels);
    PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC oglGetCompressedTextureSubImage;

    typedef GLenum_t(APIENTRYP PFNGLGETGRAPHICSRESETSTATUSPROC)(void);
    PFNGLGETGRAPHICSRESETSTATUSPROC oglGetGraphicsResetStatus;

    typedef void(APIENTRYP PFNGLGETNCOMPRESSEDTEXIMAGEPROC)(GLenum_t target, GLint_t lod, GLsizei_t bufSize, void* pixels);
    PFNGLGETNCOMPRESSEDTEXIMAGEPROC oglGetnCompressedTexImage;

    typedef void(APIENTRYP PFNGLGETNTEXIMAGEPROC)(GLenum_t target, GLint_t level, GLenum_t format, GLenum_t type, GLsizei_t bufSize, void* pixels);
    PFNGLGETNTEXIMAGEPROC oglGetnTexImage;

    typedef void(APIENTRYP PFNGLGETNUNIFORMDVPROC)(GLuint_t program, GLint_t location, GLsizei_t bufSize, GLdouble_t* params);
    PFNGLGETNUNIFORMDVPROC oglGetnUniformdv;

    typedef void(APIENTRYP PFNGLGETNUNIFORMFVPROC)(GLuint_t program, GLint_t location, GLsizei_t bufSize, GLfloat_t* params);
    PFNGLGETNUNIFORMFVPROC oglGetnUniformfv;

    typedef void(APIENTRYP PFNGLGETNUNIFORMIVPROC)(GLuint_t program, GLint_t location, GLsizei_t bufSize, GLint_t* params);
    PFNGLGETNUNIFORMIVPROC oglGetnUniformiv;

    typedef void(APIENTRYP PFNGLGETNUNIFORMUIVPROC)(GLuint_t program, GLint_t location, GLsizei_t bufSize, GLuint_t* params);
    PFNGLGETNUNIFORMUIVPROC oglGetnUniformuiv;

    typedef void(
        APIENTRYP PFNGLREADNPIXELSPROC)(GLint_t x, GLint_t y, GLsizei_t width, GLsizei_t height, GLenum_t format, GLenum_t type, GLsizei_t bufSize, void* data);
    PFNGLREADNPIXELSPROC oglReadnPixels;

    typedef void(APIENTRYP PFNGLGETNMAPDVPROC)(GLenum_t target, GLenum_t query, GLsizei_t bufSize, GLdouble_t* v);
    PFNGLGETNMAPDVPROC oglGetnMapdv;

    typedef void(APIENTRYP PFNGLGETNMAPFVPROC)(GLenum_t target, GLenum_t query, GLsizei_t bufSize, GLfloat_t* v);
    PFNGLGETNMAPFVPROC oglGetnMapfv;

    typedef void(APIENTRYP PFNGLGETNMAPIVPROC)(GLenum_t target, GLenum_t query, GLsizei_t bufSize, GLint_t* v);
    PFNGLGETNMAPIVPROC oglGetnMapiv;

    typedef void(APIENTRYP PFNGLGETNPIXELMAPFVPROC)(GLenum_t map, GLsizei_t bufSize, GLfloat_t* values);
    PFNGLGETNPIXELMAPFVPROC oglGetnPixelMapfv;

    typedef void(APIENTRYP PFNGLGETNPIXELMAPUIVPROC)(GLenum_t map, GLsizei_t bufSize, GLuint_t* values);
    PFNGLGETNPIXELMAPUIVPROC oglGetnPixelMapuiv;

    typedef void(APIENTRYP PFNGLGETNPIXELMAPUSVPROC)(GLenum_t map, GLsizei_t bufSize, GLushort* values);
    PFNGLGETNPIXELMAPUSVPROC oglGetnPixelMapusv;

    typedef void(APIENTRYP PFNGLGETNPOLYGONSTIPPLEPROC)(GLsizei_t bufSize, GLubyte* pattern);
    PFNGLGETNPOLYGONSTIPPLEPROC oglGetnPolygonStipple;

    typedef void(APIENTRYP PFNGLGETNCOLORTABLEPROC)(GLenum_t target, GLenum_t format, GLenum_t type, GLsizei_t bufSize, void* table);
    PFNGLGETNCOLORTABLEPROC oglGetnColorTable;

    typedef void(APIENTRYP PFNGLGETNCONVOLUTIONFILTERPROC)(GLenum_t target, GLenum_t format, GLenum_t type, GLsizei_t bufSize, void* image);
    PFNGLGETNCONVOLUTIONFILTERPROC oglGetnConvolutionFilter;

    typedef void(APIENTRYP PFNGLGETNSEPARABLEFILTERPROC)(GLenum_t  target,
                                                         GLenum_t  format,
                                                         GLenum_t  type,
                                                         GLsizei_t rowBufSize,
                                                         void*     row,
                                                         GLsizei_t columnBufSize,
                                                         void*     column,
                                                         void*     span);
    PFNGLGETNSEPARABLEFILTERPROC oglGetnSeparableFilter;

    typedef void(APIENTRYP PFNGLGETNHISTOGRAMPROC)(GLenum_t target, GLboolean_t reset, GLenum_t format, GLenum_t type, GLsizei_t bufSize, void* values);
    PFNGLGETNHISTOGRAMPROC oglGetnHistogram;

    typedef void(APIENTRYP PFNGLGETNMINMAXPROC)(GLenum_t target, GLboolean_t reset, GLenum_t format, GLenum_t type, GLsizei_t bufSize, void* values);
    PFNGLGETNMINMAXPROC oglGetnMinmax;

    typedef void(APIENTRYP PFNGLTEXTUREBARRIERPROC)(void);
    PFNGLTEXTUREBARRIERPROC oglTextureBarrier;

  public:
    GLfuncsv450();

  protected:
    virtual void loadFuncs(Loader loader) override;
};

} // namespace glr
} // namespace xg
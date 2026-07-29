#pragma once

#include <xg/igl/ogl/GLfuncsv210.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API GLfuncsv300 : public GLfuncsv210 {

  public:
    typedef void(APIENTRYP PFNGLCOLORMASKIPROC)(GLuint_t index, GLboolean_t r, GLboolean_t g, GLboolean_t b, GLboolean_t a);
    PFNGLCOLORMASKIPROC oglColorMaski;

    typedef void(APIENTRYP PFNGLGETBOOLEANI_VPROC)(GLenum_t target, GLuint_t index, GLboolean_t* data);
    PFNGLGETBOOLEANI_VPROC oglGetBooleani_v;

    typedef void(APIENTRYP PFNGLGETINTEGERI_VPROC)(GLenum_t target, GLuint_t index, GLint_t* data);
    PFNGLGETINTEGERI_VPROC oglGetIntegeri_v;

    typedef void(APIENTRYP PFNGLENABLEIPROC)(GLenum_t target, GLuint_t index);
    PFNGLENABLEIPROC oglEnablei;

    typedef void(APIENTRYP PFNGLDISABLEIPROC)(GLenum_t target, GLuint_t index);
    PFNGLDISABLEIPROC oglDisablei;

    typedef GLboolean_t(APIENTRYP PFNGLISENABLEDIPROC)(GLenum_t target, GLuint_t index);
    PFNGLISENABLEDIPROC oglIsEnabledi;

    typedef void(APIENTRYP PFNGLBEGINTRANSFORMFEEDBACKPROC)(GLenum_t primitiveMode);
    PFNGLBEGINTRANSFORMFEEDBACKPROC oglBeginTransformFeedback;

    typedef void(APIENTRYP PFNGLENDTRANSFORMFEEDBACKPROC)(void);
    PFNGLENDTRANSFORMFEEDBACKPROC oglEndTransformFeedback;

    typedef void(APIENTRYP PFNGLBINDBUFFERRANGEPROC)(GLenum_t target, GLuint_t index, GLuint_t buffer, GLintptr offset, GLsizeiptr size);
    PFNGLBINDBUFFERRANGEPROC oglBindBufferRange;

    typedef void(APIENTRYP PFNGLBINDBUFFERBASEPROC)(GLenum_t target, GLuint_t index, GLuint_t buffer);
    PFNGLBINDBUFFERBASEPROC oglBindBufferBase;

    typedef void(APIENTRYP PFNGLTRANSFORMFEEDBACKVARYINGSPROC)(GLuint_t program, GLsizei_t count, const GLchar_t* const* varyings, GLenum_t bufferMode);
    PFNGLTRANSFORMFEEDBACKVARYINGSPROC oglTransformFeedbackVaryings;

    typedef void(APIENTRYP PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)(GLuint_t   program,
                                                                 GLuint_t   index,
                                                                 GLsizei_t  bufSize,
                                                                 GLsizei_t* length,
                                                                 GLsizei_t* size,
                                                                 GLenum_t*  type,
                                                                 GLchar_t*  name);
    PFNGLGETTRANSFORMFEEDBACKVARYINGPROC oglGetTransformFeedbackVarying;

    typedef void(APIENTRYP PFNGLCLAMPCOLORPROC)(GLenum_t target, GLenum_t clamp);
    PFNGLCLAMPCOLORPROC oglClampColor;

    typedef void(APIENTRYP PFNGLBEGINCONDITIONALRENDERPROC)(GLuint_t id, GLenum_t mode);
    PFNGLBEGINCONDITIONALRENDERPROC oglBeginConditionalRender;

    typedef void(APIENTRYP PFNGLENDCONDITIONALRENDERPROC)(void);
    PFNGLENDCONDITIONALRENDERPROC oglEndConditionalRender;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBIPOINTERPROC)(GLuint_t index, GLint_t size, GLenum_t type, GLsizei_t stride, const void* pointer);
    PFNGLVERTEXATTRIBIPOINTERPROC oglVertexAttribIPointer;

    typedef void(APIENTRYP PFNGLGETVERTEXATTRIBIIVPROC)(GLuint_t index, GLenum_t pname, GLint_t* params);
    PFNGLGETVERTEXATTRIBIIVPROC oglGetVertexAttribIiv;

    typedef void(APIENTRYP PFNGLGETVERTEXATTRIBIUIVPROC)(GLuint_t index, GLenum_t pname, GLuint_t* params);
    PFNGLGETVERTEXATTRIBIUIVPROC oglGetVertexAttribIuiv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI1IPROC)(GLuint_t index, GLint_t x);
    PFNGLVERTEXATTRIBI1IPROC oglVertexAttribI1i;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI2IPROC)(GLuint_t index, GLint_t x, GLint_t y);
    PFNGLVERTEXATTRIBI2IPROC oglVertexAttribI2i;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI3IPROC)(GLuint_t index, GLint_t x, GLint_t y, GLint_t z);
    PFNGLVERTEXATTRIBI3IPROC oglVertexAttribI3i;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI4IPROC)(GLuint_t index, GLint_t x, GLint_t y, GLint_t z, GLint_t w);
    PFNGLVERTEXATTRIBI4IPROC oglVertexAttribI4i;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI1UIPROC)(GLuint_t index, GLuint_t x);
    PFNGLVERTEXATTRIBI1UIPROC oglVertexAttribI1ui;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI2UIPROC)(GLuint_t index, GLuint_t x, GLuint_t y);
    PFNGLVERTEXATTRIBI2UIPROC oglVertexAttribI2ui;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI3UIPROC)(GLuint_t index, GLuint_t x, GLuint_t y, GLuint_t z);
    PFNGLVERTEXATTRIBI3UIPROC oglVertexAttribI3ui;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI4UIPROC)(GLuint_t index, GLuint_t x, GLuint_t y, GLuint_t z, GLuint_t w);
    PFNGLVERTEXATTRIBI4UIPROC oglVertexAttribI4ui;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI1IVPROC)(GLuint_t index, const GLint_t* v);
    PFNGLVERTEXATTRIBI1IVPROC oglVertexAttribI1iv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI2IVPROC)(GLuint_t index, const GLint_t* v);
    PFNGLVERTEXATTRIBI2IVPROC oglVertexAttribI2iv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI3IVPROC)(GLuint_t index, const GLint_t* v);
    PFNGLVERTEXATTRIBI3IVPROC oglVertexAttribI3iv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI4IVPROC)(GLuint_t index, const GLint_t* v);
    PFNGLVERTEXATTRIBI4IVPROC oglVertexAttribI4iv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI1UIVPROC)(GLuint_t index, const GLuint_t* v);
    PFNGLVERTEXATTRIBI1UIVPROC oglVertexAttribI1uiv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI2UIVPROC)(GLuint_t index, const GLuint_t* v);
    PFNGLVERTEXATTRIBI2UIVPROC oglVertexAttribI2uiv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI3UIVPROC)(GLuint_t index, const GLuint_t* v);
    PFNGLVERTEXATTRIBI3UIVPROC oglVertexAttribI3uiv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI4UIVPROC)(GLuint_t index, const GLuint_t* v);
    PFNGLVERTEXATTRIBI4UIVPROC oglVertexAttribI4uiv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI4BVPROC)(GLuint_t index, const GLbyte* v);
    PFNGLVERTEXATTRIBI4BVPROC oglVertexAttribI4bv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI4SVPROC)(GLuint_t index, const GLshort* v);
    PFNGLVERTEXATTRIBI4SVPROC oglVertexAttribI4sv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI4UBVPROC)(GLuint_t index, const GLubyte* v);
    PFNGLVERTEXATTRIBI4UBVPROC oglVertexAttribI4ubv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI4USVPROC)(GLuint_t index, const GLushort* v);
    PFNGLVERTEXATTRIBI4USVPROC oglVertexAttribI4usv;

    typedef void(APIENTRYP PFNGLGETUNIFORMUIVPROC)(GLuint_t program, GLint_t location, GLuint_t* params);
    PFNGLGETUNIFORMUIVPROC oglGetUniformuiv;

    typedef void(APIENTRYP PFNGLBINDFRAGDATALOCATIONPROC)(GLuint_t program, GLuint_t color, const GLchar_t* name);
    PFNGLBINDFRAGDATALOCATIONPROC oglBindFragDataLocation;

    typedef GLint_t(APIENTRYP PFNGLGETFRAGDATALOCATIONPROC)(GLuint_t program, const GLchar_t* name);
    PFNGLGETFRAGDATALOCATIONPROC oglGetFragDataLocation;

    typedef void(APIENTRYP PFNGLUNIFORM1UIPROC)(GLint_t location, GLuint_t v0);
    PFNGLUNIFORM1UIPROC oglUniform1ui;

    typedef void(APIENTRYP PFNGLUNIFORM2UIPROC)(GLint_t location, GLuint_t v0, GLuint_t v1);
    PFNGLUNIFORM2UIPROC oglUniform2ui;

    typedef void(APIENTRYP PFNGLUNIFORM3UIPROC)(GLint_t location, GLuint_t v0, GLuint_t v1, GLuint_t v2);
    PFNGLUNIFORM3UIPROC oglUniform3ui;

    typedef void(APIENTRYP PFNGLUNIFORM4UIPROC)(GLint_t location, GLuint_t v0, GLuint_t v1, GLuint_t v2, GLuint_t v3);
    PFNGLUNIFORM4UIPROC oglUniform4ui;

    typedef void(APIENTRYP PFNGLUNIFORM1UIVPROC)(GLint_t location, GLsizei_t count, const GLuint_t* value);
    PFNGLUNIFORM1UIVPROC oglUniform1uiv;

    typedef void(APIENTRYP PFNGLUNIFORM2UIVPROC)(GLint_t location, GLsizei_t count, const GLuint_t* value);
    PFNGLUNIFORM2UIVPROC oglUniform2uiv;

    typedef void(APIENTRYP PFNGLUNIFORM3UIVPROC)(GLint_t location, GLsizei_t count, const GLuint_t* value);
    PFNGLUNIFORM3UIVPROC oglUniform3uiv;

    typedef void(APIENTRYP PFNGLUNIFORM4UIVPROC)(GLint_t location, GLsizei_t count, const GLuint_t* value);
    PFNGLUNIFORM4UIVPROC oglUniform4uiv;

    typedef void(APIENTRYP PFNGLTEXPARAMETERIIVPROC)(GLenum_t target, GLenum_t pname, const GLint_t* params);
    PFNGLTEXPARAMETERIIVPROC oglTexParameterIiv;

    typedef void(APIENTRYP PFNGLTEXPARAMETERIUIVPROC)(GLenum_t target, GLenum_t pname, const GLuint_t* params);
    PFNGLTEXPARAMETERIUIVPROC oglTexParameterIuiv;

    typedef void(APIENTRYP PFNGLGETTEXPARAMETERIIVPROC)(GLenum_t target, GLenum_t pname, GLint_t* params);
    PFNGLGETTEXPARAMETERIIVPROC oglGetTexParameterIiv;

    typedef void(APIENTRYP PFNGLGETTEXPARAMETERIUIVPROC)(GLenum_t target, GLenum_t pname, GLuint_t* params);
    PFNGLGETTEXPARAMETERIUIVPROC oglGetTexParameterIuiv;

    typedef void(APIENTRYP PFNGLCLEARBUFFERIVPROC)(GLenum_t buffer, GLint_t drawbuffer, const GLint_t* value);
    PFNGLCLEARBUFFERIVPROC oglClearBufferiv;

    typedef void(APIENTRYP PFNGLCLEARBUFFERUIVPROC)(GLenum_t buffer, GLint_t drawbuffer, const GLuint_t* value);
    PFNGLCLEARBUFFERUIVPROC oglClearBufferuiv;

    typedef void(APIENTRYP PFNGLCLEARBUFFERFVPROC)(GLenum_t buffer, GLint_t drawbuffer, const GLfloat_t* value);
    PFNGLCLEARBUFFERFVPROC oglClearBufferfv;

    typedef void(APIENTRYP PFNGLCLEARBUFFERFIPROC)(GLenum_t buffer, GLint_t drawbuffer, GLfloat_t depth, GLint_t stencil);
    PFNGLCLEARBUFFERFIPROC oglClearBufferfi;

    typedef const GLubyte*(APIENTRYP PFNGLGETSTRINGIPROC)(GLenum_t name, GLuint_t index);
    PFNGLGETSTRINGIPROC oglGetStringi;

    typedef GLboolean_t(APIENTRYP PFNGLISRENDERBUFFERPROC)(GLuint_t renderbuffer);
    PFNGLISRENDERBUFFERPROC oglIsRenderbuffer;

    typedef void(APIENTRYP PFNGLBINDRENDERBUFFERPROC)(GLenum_t target, GLuint_t renderbuffer);
    PFNGLBINDRENDERBUFFERPROC oglBindRenderbuffer;

    typedef void(APIENTRYP PFNGLDELETERENDERBUFFERSPROC)(GLsizei_t n, const GLuint_t* renderbuffers);
    PFNGLDELETERENDERBUFFERSPROC oglDeleteRenderbuffers;

    typedef void(APIENTRYP PFNGLGENRENDERBUFFERSPROC)(GLsizei_t n, GLuint_t* renderbuffers);
    PFNGLGENRENDERBUFFERSPROC oglGenRenderbuffers;

    typedef void(APIENTRYP PFNGLRENDERBUFFERSTORAGEPROC)(GLenum_t target, GLenum_t internalformat, GLsizei_t width, GLsizei_t height);
    PFNGLRENDERBUFFERSTORAGEPROC oglRenderbufferStorage;

    typedef void(APIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVPROC)(GLenum_t target, GLenum_t pname, GLint_t* params);
    PFNGLGETRENDERBUFFERPARAMETERIVPROC oglGetRenderbufferParameteriv;

    typedef GLboolean_t(APIENTRYP PFNGLISFRAMEBUFFERPROC)(GLuint_t framebuffer);
    PFNGLISFRAMEBUFFERPROC oglIsFramebuffer;

    typedef void(APIENTRYP PFNGLBINDFRAMEBUFFERPROC)(GLenum_t target, GLuint_t framebuffer);
    PFNGLBINDFRAMEBUFFERPROC oglBindFramebuffer;

    typedef void(APIENTRYP PFNGLDELETEFRAMEBUFFERSPROC)(GLsizei_t n, const GLuint_t* framebuffers);
    PFNGLDELETEFRAMEBUFFERSPROC oglDeleteFramebuffers;

    typedef void(APIENTRYP PFNGLGENFRAMEBUFFERSPROC)(GLsizei_t n, GLuint_t* framebuffers);
    PFNGLGENFRAMEBUFFERSPROC oglGenFramebuffers;

    typedef GLenum_t(APIENTRYP PFNGLCHECKFRAMEBUFFERSTATUSPROC)(GLenum_t target);
    PFNGLCHECKFRAMEBUFFERSTATUSPROC oglCheckFramebufferStatus;

    typedef void(APIENTRYP PFNGLFRAMEBUFFERTEXTURE1DPROC)(GLenum_t target, GLenum_t attachment, GLenum_t textarget, GLuint_t texture, GLint_t level);
    PFNGLFRAMEBUFFERTEXTURE1DPROC oglFramebufferTexture1D;

    typedef void(APIENTRYP PFNGLFRAMEBUFFERTEXTURE2DPROC)(GLenum_t target, GLenum_t attachment, GLenum_t textarget, GLuint_t texture, GLint_t level);
    PFNGLFRAMEBUFFERTEXTURE2DPROC oglFramebufferTexture2D;

    typedef void(
        APIENTRYP PFNGLFRAMEBUFFERTEXTURE3DPROC)(GLenum_t target, GLenum_t attachment, GLenum_t textarget, GLuint_t texture, GLint_t level, GLint_t zoffset);
    PFNGLFRAMEBUFFERTEXTURE3DPROC oglFramebufferTexture3D;

    typedef void(APIENTRYP PFNGLFRAMEBUFFERRENDERBUFFERPROC)(GLenum_t target, GLenum_t attachment, GLenum_t renderbuffertarget, GLuint_t renderbuffer);
    PFNGLFRAMEBUFFERRENDERBUFFERPROC oglFramebufferRenderbuffer;

    typedef void(APIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLenum_t target, GLenum_t attachment, GLenum_t pname, GLint_t* params);
    PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC oglGetFramebufferAttachmentParameteriv;

    typedef void(APIENTRYP PFNGLGENERATEMIPMAPPROC)(GLenum_t target);
    PFNGLGENERATEMIPMAPPROC oglGenerateMipmap;

    typedef void(APIENTRYP PFNGLBLITFRAMEBUFFERPROC)(GLint_t      srcX0,
                                                     GLint_t      srcY0,
                                                     GLint_t      srcX1,
                                                     GLint_t      srcY1,
                                                     GLint_t      dstX0,
                                                     GLint_t      dstY0,
                                                     GLint_t      dstX1,
                                                     GLint_t      dstY1,
                                                     GLbitfield_t mask,
                                                     GLenum_t     filter);
    PFNGLBLITFRAMEBUFFERPROC oglBlitFramebuffer;

    typedef void(
        APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLenum_t target, GLsizei_t samples, GLenum_t internalformat, GLsizei_t width, GLsizei_t height);
    PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC oglRenderbufferStorageMultisample;

    typedef void(APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERPROC)(GLenum_t target, GLenum_t attachment, GLuint_t texture, GLint_t level, GLint_t layer);
    PFNGLFRAMEBUFFERTEXTURELAYERPROC oglFramebufferTextureLayer;

    typedef void*(APIENTRYP PFNGLMAPBUFFERRANGEPROC)(GLenum_t target, GLintptr offset, GLsizeiptr length, GLbitfield_t access);
    PFNGLMAPBUFFERRANGEPROC oglMapBufferRange;

    typedef void(APIENTRYP PFNGLFLUSHMAPPEDBUFFERRANGEPROC)(GLenum_t target, GLintptr offset, GLsizeiptr length);
    PFNGLFLUSHMAPPEDBUFFERRANGEPROC oglFlushMappedBufferRange;

    typedef void(APIENTRYP PFNGLBINDVERTEXARRAYPROC)(GLuint_t array);
    PFNGLBINDVERTEXARRAYPROC oglBindVertexArray;

    typedef void(APIENTRYP PFNGLDELETEVERTEXARRAYSPROC)(GLsizei_t n, const GLuint_t* arrays);
    PFNGLDELETEVERTEXARRAYSPROC oglDeleteVertexArrays;

    typedef void(APIENTRYP PFNGLGENVERTEXARRAYSPROC)(GLsizei_t n, GLuint_t* arrays);
    PFNGLGENVERTEXARRAYSPROC oglGenVertexArrays;

    typedef GLboolean_t(APIENTRYP PFNGLISVERTEXARRAYPROC)(GLuint_t array);
    PFNGLISVERTEXARRAYPROC oglIsVertexArray;

  public:
    GLfuncsv300();

  protected:
    virtual void loadFuncs(Loader loader) override;
};

} // namespace glr
} // namespace xg
#pragma once

#include <glr/igl/GLfuncsv210.h>

namespace glr {
class GLR_API GLfuncsv300 : public GLfuncsv210 {
    VI_OBJECT_META;

  public:
    typedef void(APIENTRYP PFNGLCOLORMASKIPROC)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
    PFNGLCOLORMASKIPROC glColorMaski;

    typedef void(APIENTRYP PFNGLGETBOOLEANI_VPROC)(GLenum target, GLuint index, GLboolean* data);
    PFNGLGETBOOLEANI_VPROC glGetBooleani_v;

    typedef void(APIENTRYP PFNGLGETINTEGERI_VPROC)(GLenum target, GLuint index, GLint* data);
    PFNGLGETINTEGERI_VPROC glGetIntegeri_v;

    typedef void(APIENTRYP PFNGLENABLEIPROC)(GLenum target, GLuint index);
    PFNGLENABLEIPROC glEnablei;

    typedef void(APIENTRYP PFNGLDISABLEIPROC)(GLenum target, GLuint index);
    PFNGLDISABLEIPROC glDisablei;

    typedef GLboolean(APIENTRYP PFNGLISENABLEDIPROC)(GLenum target, GLuint index);
    PFNGLISENABLEDIPROC glIsEnabledi;

    typedef void(APIENTRYP PFNGLBEGINTRANSFORMFEEDBACKPROC)(GLenum primitiveMode);
    PFNGLBEGINTRANSFORMFEEDBACKPROC glBeginTransformFeedback;

    typedef void(APIENTRYP PFNGLENDTRANSFORMFEEDBACKPROC)(void);
    PFNGLENDTRANSFORMFEEDBACKPROC glEndTransformFeedback;

    typedef void(APIENTRYP PFNGLBINDBUFFERRANGEPROC)(GLenum     target,
                                                     GLuint     index,
                                                     GLuint     buffer,
                                                     GLintptr   offset,
                                                     GLsizeiptr size);
    PFNGLBINDBUFFERRANGEPROC glBindBufferRange;

    typedef void(APIENTRYP PFNGLBINDBUFFERBASEPROC)(GLenum target, GLuint index, GLuint buffer);
    PFNGLBINDBUFFERBASEPROC glBindBufferBase;

    typedef void(APIENTRYP PFNGLTRANSFORMFEEDBACKVARYINGSPROC)(GLuint               program,
                                                               GLsizei              count,
                                                               const GLchar* const* varyings,
                                                               GLenum               bufferMode);
    PFNGLTRANSFORMFEEDBACKVARYINGSPROC glTransformFeedbackVaryings;

    typedef void(APIENTRYP PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)(GLuint   program,
                                                                 GLuint   index,
                                                                 GLsizei  bufSize,
                                                                 GLsizei* length,
                                                                 GLsizei* size,
                                                                 GLenum*  type,
                                                                 GLchar*  name);
    PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glGetTransformFeedbackVarying;

    typedef void(APIENTRYP PFNGLCLAMPCOLORPROC)(GLenum target, GLenum clamp);
    PFNGLCLAMPCOLORPROC glClampColor;

    typedef void(APIENTRYP PFNGLBEGINCONDITIONALRENDERPROC)(GLuint id, GLenum mode);
    PFNGLBEGINCONDITIONALRENDERPROC glBeginConditionalRender;

    typedef void(APIENTRYP PFNGLENDCONDITIONALRENDERPROC)(void);
    PFNGLENDCONDITIONALRENDERPROC glEndConditionalRender;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBIPOINTERPROC)(GLuint      index,
                                                          GLint       size,
                                                          GLenum      type,
                                                          GLsizei     stride,
                                                          const void* pointer);
    PFNGLVERTEXATTRIBIPOINTERPROC glVertexAttribIPointer;

    typedef void(APIENTRYP PFNGLGETVERTEXATTRIBIIVPROC)(GLuint index, GLenum pname, GLint* params);
    PFNGLGETVERTEXATTRIBIIVPROC glGetVertexAttribIiv;

    typedef void(APIENTRYP PFNGLGETVERTEXATTRIBIUIVPROC)(GLuint index, GLenum pname, GLuint* params);
    PFNGLGETVERTEXATTRIBIUIVPROC glGetVertexAttribIuiv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI1IPROC)(GLuint index, GLint x);
    PFNGLVERTEXATTRIBI1IPROC glVertexAttribI1i;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI2IPROC)(GLuint index, GLint x, GLint y);
    PFNGLVERTEXATTRIBI2IPROC glVertexAttribI2i;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI3IPROC)(GLuint index, GLint x, GLint y, GLint z);
    PFNGLVERTEXATTRIBI3IPROC glVertexAttribI3i;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI4IPROC)(GLuint index, GLint x, GLint y, GLint z, GLint w);
    PFNGLVERTEXATTRIBI4IPROC glVertexAttribI4i;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI1UIPROC)(GLuint index, GLuint x);
    PFNGLVERTEXATTRIBI1UIPROC glVertexAttribI1ui;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI2UIPROC)(GLuint index, GLuint x, GLuint y);
    PFNGLVERTEXATTRIBI2UIPROC glVertexAttribI2ui;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI3UIPROC)(GLuint index, GLuint x, GLuint y, GLuint z);
    PFNGLVERTEXATTRIBI3UIPROC glVertexAttribI3ui;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI4UIPROC)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
    PFNGLVERTEXATTRIBI4UIPROC glVertexAttribI4ui;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI1IVPROC)(GLuint index, const GLint* v);
    PFNGLVERTEXATTRIBI1IVPROC glVertexAttribI1iv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI2IVPROC)(GLuint index, const GLint* v);
    PFNGLVERTEXATTRIBI2IVPROC glVertexAttribI2iv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI3IVPROC)(GLuint index, const GLint* v);
    PFNGLVERTEXATTRIBI3IVPROC glVertexAttribI3iv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI4IVPROC)(GLuint index, const GLint* v);
    PFNGLVERTEXATTRIBI4IVPROC glVertexAttribI4iv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI1UIVPROC)(GLuint index, const GLuint* v);
    PFNGLVERTEXATTRIBI1UIVPROC glVertexAttribI1uiv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI2UIVPROC)(GLuint index, const GLuint* v);
    PFNGLVERTEXATTRIBI2UIVPROC glVertexAttribI2uiv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI3UIVPROC)(GLuint index, const GLuint* v);
    PFNGLVERTEXATTRIBI3UIVPROC glVertexAttribI3uiv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI4UIVPROC)(GLuint index, const GLuint* v);
    PFNGLVERTEXATTRIBI4UIVPROC glVertexAttribI4uiv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI4BVPROC)(GLuint index, const GLbyte* v);
    PFNGLVERTEXATTRIBI4BVPROC glVertexAttribI4bv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI4SVPROC)(GLuint index, const GLshort* v);
    PFNGLVERTEXATTRIBI4SVPROC glVertexAttribI4sv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI4UBVPROC)(GLuint index, const GLubyte* v);
    PFNGLVERTEXATTRIBI4UBVPROC glVertexAttribI4ubv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBI4USVPROC)(GLuint index, const GLushort* v);
    PFNGLVERTEXATTRIBI4USVPROC glVertexAttribI4usv;

    typedef void(APIENTRYP PFNGLGETUNIFORMUIVPROC)(GLuint program, GLint location, GLuint* params);
    PFNGLGETUNIFORMUIVPROC glGetUniformuiv;

    typedef void(APIENTRYP PFNGLBINDFRAGDATALOCATIONPROC)(GLuint program, GLuint color, const GLchar* name);
    PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocation;

    typedef GLint(APIENTRYP PFNGLGETFRAGDATALOCATIONPROC)(GLuint program, const GLchar* name);
    PFNGLGETFRAGDATALOCATIONPROC glGetFragDataLocation;

    typedef void(APIENTRYP PFNGLUNIFORM1UIPROC)(GLint location, GLuint v0);
    PFNGLUNIFORM1UIPROC glUniform1ui;

    typedef void(APIENTRYP PFNGLUNIFORM2UIPROC)(GLint location, GLuint v0, GLuint v1);
    PFNGLUNIFORM2UIPROC glUniform2ui;

    typedef void(APIENTRYP PFNGLUNIFORM3UIPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2);
    PFNGLUNIFORM3UIPROC glUniform3ui;

    typedef void(APIENTRYP PFNGLUNIFORM4UIPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
    PFNGLUNIFORM4UIPROC glUniform4ui;

    typedef void(APIENTRYP PFNGLUNIFORM1UIVPROC)(GLint location, GLsizei count, const GLuint* value);
    PFNGLUNIFORM1UIVPROC glUniform1uiv;

    typedef void(APIENTRYP PFNGLUNIFORM2UIVPROC)(GLint location, GLsizei count, const GLuint* value);
    PFNGLUNIFORM2UIVPROC glUniform2uiv;

    typedef void(APIENTRYP PFNGLUNIFORM3UIVPROC)(GLint location, GLsizei count, const GLuint* value);
    PFNGLUNIFORM3UIVPROC glUniform3uiv;

    typedef void(APIENTRYP PFNGLUNIFORM4UIVPROC)(GLint location, GLsizei count, const GLuint* value);
    PFNGLUNIFORM4UIVPROC glUniform4uiv;

    typedef void(APIENTRYP PFNGLTEXPARAMETERIIVPROC)(GLenum target, GLenum pname, const GLint* params);
    PFNGLTEXPARAMETERIIVPROC glTexParameterIiv;

    typedef void(APIENTRYP PFNGLTEXPARAMETERIUIVPROC)(GLenum target, GLenum pname, const GLuint* params);
    PFNGLTEXPARAMETERIUIVPROC glTexParameterIuiv;

    typedef void(APIENTRYP PFNGLGETTEXPARAMETERIIVPROC)(GLenum target, GLenum pname, GLint* params);
    PFNGLGETTEXPARAMETERIIVPROC glGetTexParameterIiv;

    typedef void(APIENTRYP PFNGLGETTEXPARAMETERIUIVPROC)(GLenum target, GLenum pname, GLuint* params);
    PFNGLGETTEXPARAMETERIUIVPROC glGetTexParameterIuiv;

    typedef void(APIENTRYP PFNGLCLEARBUFFERIVPROC)(GLenum buffer, GLint drawbuffer, const GLint* value);
    PFNGLCLEARBUFFERIVPROC glClearBufferiv;

    typedef void(APIENTRYP PFNGLCLEARBUFFERUIVPROC)(GLenum buffer, GLint drawbuffer, const GLuint* value);
    PFNGLCLEARBUFFERUIVPROC glClearBufferuiv;

    typedef void(APIENTRYP PFNGLCLEARBUFFERFVPROC)(GLenum buffer, GLint drawbuffer, const GLfloat* value);
    PFNGLCLEARBUFFERFVPROC glClearBufferfv;

    typedef void(APIENTRYP PFNGLCLEARBUFFERFIPROC)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
    PFNGLCLEARBUFFERFIPROC glClearBufferfi;

    typedef const GLubyte*(APIENTRYP PFNGLGETSTRINGIPROC)(GLenum name, GLuint index);
    PFNGLGETSTRINGIPROC glGetStringi;

    typedef GLboolean(APIENTRYP PFNGLISRENDERBUFFERPROC)(GLuint renderbuffer);
    PFNGLISRENDERBUFFERPROC glIsRenderbuffer;

    typedef void(APIENTRYP PFNGLBINDRENDERBUFFERPROC)(GLenum target, GLuint renderbuffer);
    PFNGLBINDRENDERBUFFERPROC glBindRenderbuffer;

    typedef void(APIENTRYP PFNGLDELETERENDERBUFFERSPROC)(GLsizei n, const GLuint* renderbuffers);
    PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffers;

    typedef void(APIENTRYP PFNGLGENRENDERBUFFERSPROC)(GLsizei n, GLuint* renderbuffers);
    PFNGLGENRENDERBUFFERSPROC glGenRenderbuffers;

    typedef void(APIENTRYP PFNGLRENDERBUFFERSTORAGEPROC)(GLenum  target,
                                                         GLenum  internalformat,
                                                         GLsizei width,
                                                         GLsizei height);
    PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorage;

    typedef void(APIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint* params);
    PFNGLGETRENDERBUFFERPARAMETERIVPROC glGetRenderbufferParameteriv;

    typedef GLboolean(APIENTRYP PFNGLISFRAMEBUFFERPROC)(GLuint framebuffer);
    PFNGLISFRAMEBUFFERPROC glIsFramebuffer;

    typedef void(APIENTRYP PFNGLBINDFRAMEBUFFERPROC)(GLenum target, GLuint framebuffer);
    PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer;

    typedef void(APIENTRYP PFNGLDELETEFRAMEBUFFERSPROC)(GLsizei n, const GLuint* framebuffers);
    PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers;

    typedef void(APIENTRYP PFNGLGENFRAMEBUFFERSPROC)(GLsizei n, GLuint* framebuffers);
    PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers;

    typedef GLenum(APIENTRYP PFNGLCHECKFRAMEBUFFERSTATUSPROC)(GLenum target);
    PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus;

    typedef void(APIENTRYP PFNGLFRAMEBUFFERTEXTURE1DPROC)(GLenum target,
                                                          GLenum attachment,
                                                          GLenum textarget,
                                                          GLuint texture,
                                                          GLint  level);
    PFNGLFRAMEBUFFERTEXTURE1DPROC glFramebufferTexture1D;

    typedef void(APIENTRYP PFNGLFRAMEBUFFERTEXTURE2DPROC)(GLenum target,
                                                          GLenum attachment,
                                                          GLenum textarget,
                                                          GLuint texture,
                                                          GLint  level);
    PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D;

    typedef void(APIENTRYP PFNGLFRAMEBUFFERTEXTURE3DPROC)(GLenum target,
                                                          GLenum attachment,
                                                          GLenum textarget,
                                                          GLuint texture,
                                                          GLint  level,
                                                          GLint  zoffset);
    PFNGLFRAMEBUFFERTEXTURE3DPROC glFramebufferTexture3D;

    typedef void(APIENTRYP PFNGLFRAMEBUFFERRENDERBUFFERPROC)(GLenum target,
                                                             GLenum attachment,
                                                             GLenum renderbuffertarget,
                                                             GLuint renderbuffer);
    PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer;

    typedef void(APIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLenum target,
                                                                         GLenum attachment,
                                                                         GLenum pname,
                                                                         GLint* params);
    PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetFramebufferAttachmentParameteriv;

    typedef void(APIENTRYP PFNGLGENERATEMIPMAPPROC)(GLenum target);
    PFNGLGENERATEMIPMAPPROC glGenerateMipmap;

    typedef void(APIENTRYP PFNGLBLITFRAMEBUFFERPROC)(GLint      srcX0,
                                                     GLint      srcY0,
                                                     GLint      srcX1,
                                                     GLint      srcY1,
                                                     GLint      dstX0,
                                                     GLint      dstY0,
                                                     GLint      dstX1,
                                                     GLint      dstY1,
                                                     GLbitfield mask,
                                                     GLenum     filter);
    PFNGLBLITFRAMEBUFFERPROC glBlitFramebuffer;

    typedef void(APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLenum  target,
                                                                    GLsizei samples,
                                                                    GLenum  internalformat,
                                                                    GLsizei width,
                                                                    GLsizei height);
    PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glRenderbufferStorageMultisample;

    typedef void(APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERPROC)(GLenum target,
                                                             GLenum attachment,
                                                             GLuint texture,
                                                             GLint  level,
                                                             GLint  layer);
    PFNGLFRAMEBUFFERTEXTURELAYERPROC glFramebufferTextureLayer;

    typedef void*(APIENTRYP PFNGLMAPBUFFERRANGEPROC)(GLenum     target,
                                                     GLintptr   offset,
                                                     GLsizeiptr length,
                                                     GLbitfield access);
    PFNGLMAPBUFFERRANGEPROC glMapBufferRange;

    typedef void(APIENTRYP PFNGLFLUSHMAPPEDBUFFERRANGEPROC)(GLenum target, GLintptr offset, GLsizeiptr length);
    PFNGLFLUSHMAPPEDBUFFERRANGEPROC glFlushMappedBufferRange;

    typedef void(APIENTRYP PFNGLBINDVERTEXARRAYPROC)(GLuint array);
    PFNGLBINDVERTEXARRAYPROC glBindVertexArray;

    typedef void(APIENTRYP PFNGLDELETEVERTEXARRAYSPROC)(GLsizei n, const GLuint* arrays);
    PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;

    typedef void(APIENTRYP PFNGLGENVERTEXARRAYSPROC)(GLsizei n, GLuint* arrays);
    PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;

    typedef GLboolean(APIENTRYP PFNGLISVERTEXARRAYPROC)(GLuint array);
    PFNGLISVERTEXARRAYPROC glIsVertexArray;

  public:
    GLfuncsv300();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
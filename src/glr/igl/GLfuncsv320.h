#pragma once

#include <glr/igl/GLfuncsv310.h>

namespace glr {
class GLR_API GLfuncsv320 : public GLfuncsv310 {
  public:
    using GLint64  = GLint64_t;
    using GLuint64 = GLuint64_t;
    using GLenum   = GLenum_t;
    typedef struct __GLsync *GLsync;

  public:
    typedef void(APIENTRYP PFNGLDRAWELEMENTSBASEVERTEXPROC)(GLenum      mode,
                                                            GLsizei     count,
                                                            GLenum      type,
                                                            const void* indices,
                                                            GLint       basevertex);
    PFNGLDRAWELEMENTSBASEVERTEXPROC glDrawElementsBaseVertex;

    typedef void(APIENTRYP PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)(GLenum      mode,
                                                                 GLuint      start,
                                                                 GLuint      end,
                                                                 GLsizei     count,
                                                                 GLenum      type,
                                                                 const void* indices,
                                                                 GLint       basevertex);
    PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glDrawRangeElementsBaseVertex;

    typedef void(APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)(GLenum      mode,
                                                                     GLsizei     count,
                                                                     GLenum      type,
                                                                     const void* indices,
                                                                     GLsizei     instancecount,
                                                                     GLint       basevertex);
    PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glDrawElementsInstancedBaseVertex;

    typedef void(APIENTRYP PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)(GLenum             mode,
                                                                 const GLsizei*     count,
                                                                 GLenum             type,
                                                                 const void* const* indices,
                                                                 GLsizei            drawcount,
                                                                 const GLint*       basevertex);
    PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glMultiDrawElementsBaseVertex;

    typedef void(APIENTRYP PFNGLPROVOKINGVERTEXPROC)(GLenum mode);
    PFNGLPROVOKINGVERTEXPROC glProvokingVertex;

    typedef GLsync(APIENTRYP PFNGLFENCESYNCPROC)(GLenum condition, GLbitfield flags);
    PFNGLFENCESYNCPROC glFenceSync;

    typedef GLboolean(APIENTRYP PFNGLISSYNCPROC)(GLsync sync);
    PFNGLISSYNCPROC glIsSync;

    typedef void(APIENTRYP PFNGLDELETESYNCPROC)(GLsync sync);
    PFNGLDELETESYNCPROC glDeleteSync;

    typedef GLenum(APIENTRYP PFNGLCLIENTWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
    PFNGLCLIENTWAITSYNCPROC glClientWaitSync;

    typedef void(APIENTRYP PFNGLWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
    PFNGLWAITSYNCPROC glWaitSync;

    typedef void(APIENTRYP PFNGLGETINTEGER64VPROC)(GLenum pname, GLint64* data);
    PFNGLGETINTEGER64VPROC glGetInteger64v;

    typedef void(
        APIENTRYP PFNGLGETSYNCIVPROC)(GLsync sync, GLenum pname, GLsizei count, GLsizei* length, GLint* values);
    PFNGLGETSYNCIVPROC glGetSynciv;

    typedef void(APIENTRYP PFNGLGETINTEGER64I_VPROC)(GLenum target, GLuint index, GLint64* data);
    PFNGLGETINTEGER64I_VPROC glGetInteger64i_v;

    typedef void(APIENTRYP PFNGLGETBUFFERPARAMETERI64VPROC)(GLenum target, GLenum pname, GLint64* params);
    PFNGLGETBUFFERPARAMETERI64VPROC glGetBufferParameteri64v;

    typedef void(APIENTRYP PFNGLFRAMEBUFFERTEXTUREPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level);
    PFNGLFRAMEBUFFERTEXTUREPROC glFramebufferTexture;

    typedef void(APIENTRYP PFNGLTEXIMAGE2DMULTISAMPLEPROC)(GLenum    target,
                                                           GLsizei   samples,
                                                           GLenum    internalformat,
                                                           GLsizei   width,
                                                           GLsizei   height,
                                                           GLboolean fixedsamplelocations);
    PFNGLTEXIMAGE2DMULTISAMPLEPROC glTexImage2DMultisample;

    typedef void(APIENTRYP PFNGLTEXIMAGE3DMULTISAMPLEPROC)(GLenum    target,
                                                           GLsizei   samples,
                                                           GLenum    internalformat,
                                                           GLsizei   width,
                                                           GLsizei   height,
                                                           GLsizei   depth,
                                                           GLboolean fixedsamplelocations);
    PFNGLTEXIMAGE3DMULTISAMPLEPROC glTexImage3DMultisample;

    typedef void(APIENTRYP PFNGLGETMULTISAMPLEFVPROC)(GLenum pname, GLuint index, GLfloat* val);
    PFNGLGETMULTISAMPLEFVPROC glGetMultisamplefv;

    typedef void(APIENTRYP PFNGLSAMPLEMASKIPROC)(GLuint maskNumber, GLbitfield mask);
    PFNGLSAMPLEMASKIPROC glSampleMaski;

  public:
    GLfuncsv320();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
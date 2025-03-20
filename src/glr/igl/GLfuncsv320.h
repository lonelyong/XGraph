#pragma once

#include <glr/igl/GLfuncsv310.h>

namespace glr {
class GLR_API GLfuncsv320 : public GLfuncsv310 {

  public:
    using GLint64  = GLint64_t;
    using GLuint64 = GLuint64_t;
    using GLenum_t   = GLenum_t;
    typedef struct __GLsync *GLsync;

  public:
    typedef void(APIENTRYP PFNGLDRAWELEMENTSBASEVERTEXPROC)(GLenum_t      mode,
                                                            GLsizei_t     count,
                                                            GLenum_t      type,
                                                            const void* indices,
                                                            GLint_t       basevertex);
    PFNGLDRAWELEMENTSBASEVERTEXPROC iglDrawElementsBaseVertex;

    typedef void(APIENTRYP PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)(GLenum_t      mode,
                                                                 GLuint_t      start,
                                                                 GLuint_t      end,
                                                                 GLsizei_t     count,
                                                                 GLenum_t      type,
                                                                 const void* indices,
                                                                 GLint_t       basevertex);
    PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC iglDrawRangeElementsBaseVertex;

    typedef void(APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)(GLenum_t      mode,
                                                                     GLsizei_t     count,
                                                                     GLenum_t      type,
                                                                     const void* indices,
                                                                     GLsizei_t     instancecount,
                                                                     GLint_t       basevertex);
    PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC iglDrawElementsInstancedBaseVertex;

    typedef void(APIENTRYP PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)(GLenum_t             mode,
                                                                 const GLsizei_t*     count,
                                                                 GLenum_t             type,
                                                                 const void* const* indices,
                                                                 GLsizei_t            drawcount,
                                                                 const GLint_t*       basevertex);
    PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC iglMultiDrawElementsBaseVertex;

    typedef void(APIENTRYP PFNGLPROVOKINGVERTEXPROC)(GLenum_t mode);
    PFNGLPROVOKINGVERTEXPROC iglProvokingVertex;

    typedef GLsync(APIENTRYP PFNGLFENCESYNCPROC)(GLenum_t condition, GLbitfield_t flags);
    PFNGLFENCESYNCPROC iglFenceSync;

    typedef GLboolean_t(APIENTRYP PFNGLISSYNCPROC)(GLsync sync);
    PFNGLISSYNCPROC iglIsSync;

    typedef void(APIENTRYP PFNGLDELETESYNCPROC)(GLsync sync);
    PFNGLDELETESYNCPROC iglDeleteSync;

    typedef GLenum_t(APIENTRYP PFNGLCLIENTWAITSYNCPROC)(GLsync sync, GLbitfield_t flags, GLuint64 timeout);
    PFNGLCLIENTWAITSYNCPROC iglClientWaitSync;

    typedef void(APIENTRYP PFNGLWAITSYNCPROC)(GLsync sync, GLbitfield_t flags, GLuint64 timeout);
    PFNGLWAITSYNCPROC iglWaitSync;

    typedef void(APIENTRYP PFNGLGETINTEGER64VPROC)(GLenum_t pname, GLint64* data);
    PFNGLGETINTEGER64VPROC iglGetInteger64v;

    typedef void(
        APIENTRYP PFNGLGETSYNCIVPROC)(GLsync sync, GLenum_t pname, GLsizei_t count, GLsizei_t* length, GLint_t* values);
    PFNGLGETSYNCIVPROC iglGetSynciv;

    typedef void(APIENTRYP PFNGLGETINTEGER64I_VPROC)(GLenum_t target, GLuint_t index, GLint64* data);
    PFNGLGETINTEGER64I_VPROC iglGetInteger64i_v;

    typedef void(APIENTRYP PFNGLGETBUFFERPARAMETERI64VPROC)(GLenum_t target, GLenum_t pname, GLint64* params);
    PFNGLGETBUFFERPARAMETERI64VPROC iglGetBufferParameteri64v;

    typedef void(APIENTRYP PFNGLFRAMEBUFFERTEXTUREPROC)(GLenum_t target, GLenum_t attachment, GLuint_t texture, GLint_t level);
    PFNGLFRAMEBUFFERTEXTUREPROC iglFramebufferTexture;

    typedef void(APIENTRYP PFNGLTEXIMAGE2DMULTISAMPLEPROC)(GLenum_t    target,
                                                           GLsizei_t   samples,
                                                           GLenum_t    internalformat,
                                                           GLsizei_t   width,
                                                           GLsizei_t   height,
                                                           GLboolean_t fixedsamplelocations);
    PFNGLTEXIMAGE2DMULTISAMPLEPROC iglTexImage2DMultisample;

    typedef void(APIENTRYP PFNGLTEXIMAGE3DMULTISAMPLEPROC)(GLenum_t    target,
                                                           GLsizei_t   samples,
                                                           GLenum_t    internalformat,
                                                           GLsizei_t   width,
                                                           GLsizei_t   height,
                                                           GLsizei_t   depth,
                                                           GLboolean_t fixedsamplelocations);
    PFNGLTEXIMAGE3DMULTISAMPLEPROC iglTexImage3DMultisample;

    typedef void(APIENTRYP PFNGLGETMULTISAMPLEFVPROC)(GLenum_t pname, GLuint_t index, GLfloat_t* val);
    PFNGLGETMULTISAMPLEFVPROC iglGetMultisamplefv;

    typedef void(APIENTRYP PFNGLSAMPLEMASKIPROC)(GLuint_t maskNumber, GLbitfield_t mask);
    PFNGLSAMPLEMASKIPROC iglSampleMaski;

  public:
    GLfuncsv320();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
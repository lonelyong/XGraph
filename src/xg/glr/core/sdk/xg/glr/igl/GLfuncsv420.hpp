#pragma once

#include <xg/glr/igl/GLfuncsv410.hpp>

namespace xg {
namespace glr {
class GLR_API GLfuncsv420 : public GLfuncsv410 {

  public:
    typedef void(APIENTRYP PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)(GLenum_t  mode,
                                                                     GLint_t   first,
                                                                     GLsizei_t count,
                                                                     GLsizei_t instancecount,
                                                                     GLuint_t  baseinstance);
    PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC iglDrawArraysInstancedBaseInstance;

    typedef void(APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)(GLenum_t      mode,
                                                                       GLsizei_t     count,
                                                                       GLenum_t      type,
                                                                       const void* indices,
                                                                       GLsizei_t     instancecount,
                                                                       GLuint_t      baseinstance);
    PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC iglDrawElementsInstancedBaseInstance;

    typedef void(APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)(GLenum_t      mode,
                                                                                 GLsizei_t     count,
                                                                                 GLenum_t      type,
                                                                                 const void* indices,
                                                                                 GLsizei_t     instancecount,
                                                                                 GLint_t       basevertex,
                                                                                 GLuint_t      baseinstance);
    PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC iglDrawElementsInstancedBaseVertexBaseInstance;

    typedef void(APIENTRYP PFNGLGETINTERNALFORMATIVPROC)(GLenum_t  target,
                                                         GLenum_t  internalformat,
                                                         GLenum_t  pname,
                                                         GLsizei_t count,
                                                         GLint_t*  params);
    PFNGLGETINTERNALFORMATIVPROC iglGetInternalformativ;

    typedef void(APIENTRYP PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)(GLuint_t program,
                                                                    GLuint_t bufferIndex,
                                                                    GLenum_t pname,
                                                                    GLint_t* params);
    PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC iglGetActiveAtomicCounterBufferiv;

    typedef void(APIENTRYP PFNGLBINDIMAGETEXTUREPROC)(GLuint_t    unit,
                                                      GLuint_t    texture,
                                                      GLint_t     level,
                                                      GLboolean_t layered,
                                                      GLint_t     layer,
                                                      GLenum_t    access,
                                                      GLenum_t    format);
    PFNGLBINDIMAGETEXTUREPROC iglBindImageTexture;

    typedef void(APIENTRYP PFNGLMEMORYBARRIERPROC)(GLbitfield_t barriers);
    PFNGLMEMORYBARRIERPROC iglMemoryBarrier;

    typedef void(APIENTRYP PFNGLTEXSTORAGE1DPROC)(GLenum_t target, GLsizei_t levels, GLenum_t internalformat, GLsizei_t width);
    PFNGLTEXSTORAGE1DPROC iglTexStorage1D;

    typedef void(APIENTRYP PFNGLTEXSTORAGE2DPROC)(GLenum_t  target,
                                                  GLsizei_t levels,
                                                  GLenum_t  internalformat,
                                                  GLsizei_t width,
                                                  GLsizei_t height);
    PFNGLTEXSTORAGE2DPROC iglTexStorage2D;

    typedef void(APIENTRYP PFNGLTEXSTORAGE3DPROC)(GLenum_t  target,
                                                  GLsizei_t levels,
                                                  GLenum_t  internalformat,
                                                  GLsizei_t width,
                                                  GLsizei_t height,
                                                  GLsizei_t depth);
    PFNGLTEXSTORAGE3DPROC iglTexStorage3D;

    typedef void(APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)(GLenum_t mode, GLuint_t id, GLsizei_t instancecount);
    PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC iglDrawTransformFeedbackInstanced;

    typedef void(APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)(GLenum_t  mode,
                                                                          GLuint_t  id,
                                                                          GLuint_t  stream,
                                                                          GLsizei_t instancecount);
    PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC iglDrawTransformFeedbackStreamInstanced;

  public:
    GLfuncsv420();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
} // namespace xg
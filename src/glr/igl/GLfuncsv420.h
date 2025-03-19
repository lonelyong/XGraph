#pragma once

#include <glr/igl/GLfuncsv410.h>

namespace glr {
class GLR_API GLfuncsv420 : public GLfuncsv410 {
  public:
    typedef void(APIENTRYP PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)(GLenum  mode,
                                                                     GLint   first,
                                                                     GLsizei count,
                                                                     GLsizei instancecount,
                                                                     GLuint  baseinstance);
    PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC glDrawArraysInstancedBaseInstance;

    typedef void(APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)(GLenum      mode,
                                                                       GLsizei     count,
                                                                       GLenum      type,
                                                                       const void* indices,
                                                                       GLsizei     instancecount,
                                                                       GLuint      baseinstance);
    PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC glDrawElementsInstancedBaseInstance;

    typedef void(APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)(GLenum      mode,
                                                                                 GLsizei     count,
                                                                                 GLenum      type,
                                                                                 const void* indices,
                                                                                 GLsizei     instancecount,
                                                                                 GLint       basevertex,
                                                                                 GLuint      baseinstance);
    PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC glDrawElementsInstancedBaseVertexBaseInstance;

    typedef void(APIENTRYP PFNGLGETINTERNALFORMATIVPROC)(GLenum  target,
                                                         GLenum  internalformat,
                                                         GLenum  pname,
                                                         GLsizei count,
                                                         GLint*  params);
    PFNGLGETINTERNALFORMATIVPROC glGetInternalformativ;

    typedef void(APIENTRYP PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)(GLuint program,
                                                                    GLuint bufferIndex,
                                                                    GLenum pname,
                                                                    GLint* params);
    PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC glGetActiveAtomicCounterBufferiv;

    typedef void(APIENTRYP PFNGLBINDIMAGETEXTUREPROC)(GLuint    unit,
                                                      GLuint    texture,
                                                      GLint     level,
                                                      GLboolean layered,
                                                      GLint     layer,
                                                      GLenum    access,
                                                      GLenum    format);
    PFNGLBINDIMAGETEXTUREPROC glBindImageTexture;

    typedef void(APIENTRYP PFNGLMEMORYBARRIERPROC)(GLbitfield barriers);
    PFNGLMEMORYBARRIERPROC glMemoryBarrier;

    typedef void(APIENTRYP PFNGLTEXSTORAGE1DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
    PFNGLTEXSTORAGE1DPROC glTexStorage1D;

    typedef void(APIENTRYP PFNGLTEXSTORAGE2DPROC)(GLenum  target,
                                                  GLsizei levels,
                                                  GLenum  internalformat,
                                                  GLsizei width,
                                                  GLsizei height);
    PFNGLTEXSTORAGE2DPROC glTexStorage2D;

    typedef void(APIENTRYP PFNGLTEXSTORAGE3DPROC)(GLenum  target,
                                                  GLsizei levels,
                                                  GLenum  internalformat,
                                                  GLsizei width,
                                                  GLsizei height,
                                                  GLsizei depth);
    PFNGLTEXSTORAGE3DPROC glTexStorage3D;

    typedef void(APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)(GLenum mode, GLuint id, GLsizei instancecount);
    PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC glDrawTransformFeedbackInstanced;

    typedef void(APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)(GLenum  mode,
                                                                          GLuint  id,
                                                                          GLuint  stream,
                                                                          GLsizei instancecount);
    PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC glDrawTransformFeedbackStreamInstanced;

  public:
    GLfuncsv420();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
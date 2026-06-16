#pragma once

#include <xg/glr/igl/GLfuncsv300.h>

namespace glr {
class GLR_API GLfuncsv310 : public GLfuncsv300 {

  public:
    typedef void(APIENTRYP PFNGLDRAWARRAYSINSTANCEDPROC)(GLenum_t  mode,
                                                         GLint_t   first,
                                                         GLsizei_t count,
                                                         GLsizei_t instancecount);
    PFNGLDRAWARRAYSINSTANCEDPROC iglDrawArraysInstanced;

    typedef void(APIENTRYP PFNGLDRAWELEMENTSINSTANCEDPROC)(GLenum_t      mode,
                                                           GLsizei_t     count,
                                                           GLenum_t      type,
                                                           const void* indices,
                                                           GLsizei_t     instancecount);
    PFNGLDRAWELEMENTSINSTANCEDPROC iglDrawElementsInstanced;

    typedef void(APIENTRYP PFNGLTEXBUFFERPROC)(GLenum_t target, GLenum_t internalformat, GLuint_t buffer);
    PFNGLTEXBUFFERPROC iglTexBuffer;

    typedef void(APIENTRYP PFNGLPRIMITIVERESTARTINDEXPROC)(GLuint_t index);
    PFNGLPRIMITIVERESTARTINDEXPROC iglPrimitiveRestartIndex;

    typedef void(APIENTRYP PFNGLCOPYBUFFERSUBDATAPROC)(GLenum_t     readTarget,
                                                       GLenum_t     writeTarget,
                                                       GLintptr   readOffset,
                                                       GLintptr   writeOffset,
                                                       GLsizeiptr size);
    PFNGLCOPYBUFFERSUBDATAPROC iglCopyBufferSubData;

    typedef void(APIENTRYP PFNGLGETUNIFORMINDICESPROC)(GLuint_t               program,
                                                       GLsizei_t              uniformCount,
                                                       const GLchar_t* const* uniformNames,
                                                       GLuint_t*              uniformIndices);
    PFNGLGETUNIFORMINDICESPROC iglGetUniformIndices;

    typedef void(APIENTRYP PFNGLGETACTIVEUNIFORMSIVPROC)(GLuint_t        program,
                                                         GLsizei_t       uniformCount,
                                                         const GLuint_t* uniformIndices,
                                                         GLenum_t        pname,
                                                         GLint_t*        params);
    PFNGLGETACTIVEUNIFORMSIVPROC iglGetActiveUniformsiv;

    typedef void(APIENTRYP PFNGLGETACTIVEUNIFORMNAMEPROC)(GLuint_t   program,
                                                          GLuint_t   uniformIndex,
                                                          GLsizei_t  bufSize,
                                                          GLsizei_t* length,
                                                          GLchar_t*  uniformName);
    PFNGLGETACTIVEUNIFORMNAMEPROC iglGetActiveUniformName;

    typedef GLuint_t(APIENTRYP PFNGLGETUNIFORMBLOCKINDEXPROC)(GLuint_t program, const GLchar_t* uniformBlockName);
    PFNGLGETUNIFORMBLOCKINDEXPROC iglGetUniformBlockIndex;

    typedef void(APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKIVPROC)(GLuint_t program,
                                                             GLuint_t uniformBlockIndex,
                                                             GLenum_t pname,
                                                             GLint_t* params);
    PFNGLGETACTIVEUNIFORMBLOCKIVPROC iglGetActiveUniformBlockiv;

    typedef void(APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)(GLuint_t   program,
                                                               GLuint_t   uniformBlockIndex,
                                                               GLsizei_t  bufSize,
                                                               GLsizei_t* length,
                                                               GLchar_t*  uniformBlockName);
    PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC iglGetActiveUniformBlockName;

    typedef void(APIENTRYP PFNGLUNIFORMBLOCKBINDINGPROC)(GLuint_t program,
                                                         GLuint_t uniformBlockIndex,
                                                         GLuint_t uniformBlockBinding);
    PFNGLUNIFORMBLOCKBINDINGPROC iglUniformBlockBinding;

  public:
    GLfuncsv310();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
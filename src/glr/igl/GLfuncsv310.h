#pragma once

#include <glr/igl/GLfuncsv300.h>

namespace glr {
class GLR_API GLfuncsv310 : public GLfuncsv300 {
  public:
    typedef void(APIENTRYP PFNGLDRAWARRAYSINSTANCEDPROC)(GLenum  mode,
                                                         GLint   first,
                                                         GLsizei count,
                                                         GLsizei instancecount);
    PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced;

    typedef void(APIENTRYP PFNGLDRAWELEMENTSINSTANCEDPROC)(GLenum      mode,
                                                           GLsizei     count,
                                                           GLenum      type,
                                                           const void* indices,
                                                           GLsizei     instancecount);
    PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced;

    typedef void(APIENTRYP PFNGLTEXBUFFERPROC)(GLenum target, GLenum internalformat, GLuint buffer);
    PFNGLTEXBUFFERPROC glTexBuffer;

    typedef void(APIENTRYP PFNGLPRIMITIVERESTARTINDEXPROC)(GLuint index);
    PFNGLPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndex;

    typedef void(APIENTRYP PFNGLCOPYBUFFERSUBDATAPROC)(GLenum     readTarget,
                                                       GLenum     writeTarget,
                                                       GLintptr   readOffset,
                                                       GLintptr   writeOffset,
                                                       GLsizeiptr size);
    PFNGLCOPYBUFFERSUBDATAPROC glCopyBufferSubData;

    typedef void(APIENTRYP PFNGLGETUNIFORMINDICESPROC)(GLuint               program,
                                                       GLsizei              uniformCount,
                                                       const GLchar* const* uniformNames,
                                                       GLuint*              uniformIndices);
    PFNGLGETUNIFORMINDICESPROC glGetUniformIndices;

    typedef void(APIENTRYP PFNGLGETACTIVEUNIFORMSIVPROC)(GLuint        program,
                                                         GLsizei       uniformCount,
                                                         const GLuint* uniformIndices,
                                                         GLenum        pname,
                                                         GLint*        params);
    PFNGLGETACTIVEUNIFORMSIVPROC glGetActiveUniformsiv;

    typedef void(APIENTRYP PFNGLGETACTIVEUNIFORMNAMEPROC)(GLuint   program,
                                                          GLuint   uniformIndex,
                                                          GLsizei  bufSize,
                                                          GLsizei* length,
                                                          GLchar*  uniformName);
    PFNGLGETACTIVEUNIFORMNAMEPROC glGetActiveUniformName;

    typedef GLuint(APIENTRYP PFNGLGETUNIFORMBLOCKINDEXPROC)(GLuint program, const GLchar* uniformBlockName);
    PFNGLGETUNIFORMBLOCKINDEXPROC glGetUniformBlockIndex;

    typedef void(APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKIVPROC)(GLuint program,
                                                             GLuint uniformBlockIndex,
                                                             GLenum pname,
                                                             GLint* params);
    PFNGLGETACTIVEUNIFORMBLOCKIVPROC glGetActiveUniformBlockiv;

    typedef void(APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)(GLuint   program,
                                                               GLuint   uniformBlockIndex,
                                                               GLsizei  bufSize,
                                                               GLsizei* length,
                                                               GLchar*  uniformBlockName);
    PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glGetActiveUniformBlockName;

    typedef void(APIENTRYP PFNGLUNIFORMBLOCKBINDINGPROC)(GLuint program,
                                                         GLuint uniformBlockIndex,
                                                         GLuint uniformBlockBinding);
    PFNGLUNIFORMBLOCKBINDINGPROC glUniformBlockBinding;

  public:
    GLfuncsv310();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
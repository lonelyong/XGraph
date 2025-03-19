#pragma once

#include <glr/igl/GLfuncsv450.h>

namespace glr {
class GLR_API GLfuncsv460 : public GLfuncsv450 {
  public:
    typedef void(APIENTRYP PFNGLSPECIALIZESHADERPROC)(GLuint        shader,
                                                      const GLchar* pEntryPoint,
                                                      GLuint        numSpecializationConstants,
                                                      const GLuint* pConstantIndex,
                                                      const GLuint* pConstantValue);
    PFNGLSPECIALIZESHADERPROC glSpecializeShader;

    typedef void(APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC)(GLenum      mode,
                                                                  const void* indirect,
                                                                  GLintptr    drawcount,
                                                                  GLsizei     maxdrawcount,
                                                                  GLsizei     stride);
    PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC glMultiDrawArraysIndirectCount;

    typedef void(APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC)(GLenum      mode,
                                                                    GLenum      type,
                                                                    const void* indirect,
                                                                    GLintptr    drawcount,
                                                                    GLsizei     maxdrawcount,
                                                                    GLsizei     stride);
    PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC glMultiDrawElementsIndirectCount;

    typedef void(APIENTRYP PFNGLPOLYGONOFFSETCLAMPPROC)(GLfloat factor, GLfloat units, GLfloat clamp);
    PFNGLPOLYGONOFFSETCLAMPPROC glPolygonOffsetClamp;


  public:
    GLfuncsv460();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
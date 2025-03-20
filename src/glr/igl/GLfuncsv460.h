#pragma once

#include <glr/igl/GLfuncsv450.h>

namespace glr {
class GLR_API GLfuncsv460 : public GLfuncsv450 {

  public:
    typedef void(APIENTRYP PFNGLSPECIALIZESHADERPROC)(GLuint_t        shader,
                                                      const GLchar_t* pEntryPoint,
                                                      GLuint_t        numSpecializationConstants,
                                                      const GLuint_t* pConstantIndex,
                                                      const GLuint_t* pConstantValue);
    PFNGLSPECIALIZESHADERPROC iglSpecializeShader;

    typedef void(APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC)(GLenum_t      mode,
                                                                  const void* indirect,
                                                                  GLintptr    drawcount,
                                                                  GLsizei_t     maxdrawcount,
                                                                  GLsizei_t     stride);
    PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC iglMultiDrawArraysIndirectCount;

    typedef void(APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC)(GLenum_t      mode,
                                                                    GLenum_t      type,
                                                                    const void* indirect,
                                                                    GLintptr    drawcount,
                                                                    GLsizei_t     maxdrawcount,
                                                                    GLsizei_t     stride);
    PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC iglMultiDrawElementsIndirectCount;

    typedef void(APIENTRYP PFNGLPOLYGONOFFSETCLAMPPROC)(GLfloat_t factor, GLfloat_t units, GLfloat_t clamp);
    PFNGLPOLYGONOFFSETCLAMPPROC iglPolygonOffsetClamp;


  public:
    GLfuncsv460();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
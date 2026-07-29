#pragma once

#include <xg/igl/ogl/GLfuncsv450.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API GLfuncsv460 : public GLfuncsv450 {

  public:
    typedef void(APIENTRYP PFNGLSPECIALIZESHADERPROC)(GLuint_t        shader,
                                                      const GLchar_t* pEntryPoint,
                                                      GLuint_t        numSpecializationConstants,
                                                      const GLuint_t* pConstantIndex,
                                                      const GLuint_t* pConstantValue);
    PFNGLSPECIALIZESHADERPROC oglSpecializeShader;

    typedef void(
        APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC)(GLenum_t mode, const void* indirect, GLintptr drawcount, GLsizei_t maxdrawcount, GLsizei_t stride);
    PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC oglMultiDrawArraysIndirectCount;

    typedef void(APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC)(GLenum_t    mode,
                                                                    GLenum_t    type,
                                                                    const void* indirect,
                                                                    GLintptr    drawcount,
                                                                    GLsizei_t   maxdrawcount,
                                                                    GLsizei_t   stride);
    PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC oglMultiDrawElementsIndirectCount;

    typedef void(APIENTRYP PFNGLPOLYGONOFFSETCLAMPPROC)(GLfloat_t factor, GLfloat_t units, GLfloat_t clamp);
    PFNGLPOLYGONOFFSETCLAMPPROC oglPolygonOffsetClamp;


  public:
    GLfuncsv460();

  protected:
    virtual void loadFuncs(Loader loader) override;
};

} // namespace glr
} // namespace xg
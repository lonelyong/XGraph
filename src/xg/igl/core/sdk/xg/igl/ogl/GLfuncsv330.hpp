#pragma once

#include <xg/igl/ogl/GLfuncsv320.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API GLfuncsv330 : public GLfuncsv320 {

  public:
    typedef void(APIENTRYP PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)(GLuint_t program, GLuint_t colorNumber, GLuint_t index, const GLchar_t* name);
    PFNGLBINDFRAGDATALOCATIONINDEXEDPROC oglBindFragDataLocationIndexed;

    typedef GLint_t(APIENTRYP PFNGLGETFRAGDATAINDEXPROC)(GLuint_t program, const GLchar_t* name);
    PFNGLGETFRAGDATAINDEXPROC oglGetFragDataIndex;

    typedef void(APIENTRYP PFNGLGENSAMPLERSPROC)(GLsizei_t count, GLuint_t* samplers);
    PFNGLGENSAMPLERSPROC oglGenSamplers;

    typedef void(APIENTRYP PFNGLDELETESAMPLERSPROC)(GLsizei_t count, const GLuint_t* samplers);
    PFNGLDELETESAMPLERSPROC oglDeleteSamplers;

    typedef GLboolean_t(APIENTRYP PFNGLISSAMPLERPROC)(GLuint_t sampler);
    PFNGLISSAMPLERPROC oglIsSampler;

    typedef void(APIENTRYP PFNGLBINDSAMPLERPROC)(GLuint_t unit, GLuint_t sampler);
    PFNGLBINDSAMPLERPROC oglBindSampler;

    typedef void(APIENTRYP PFNGLSAMPLERPARAMETERIPROC)(GLuint_t sampler, GLenum_t pname, GLint_t param);
    PFNGLSAMPLERPARAMETERIPROC oglSamplerParameteri;

    typedef void(APIENTRYP PFNGLSAMPLERPARAMETERIVPROC)(GLuint_t sampler, GLenum_t pname, const GLint_t* param);
    PFNGLSAMPLERPARAMETERIVPROC oglSamplerParameteriv;

    typedef void(APIENTRYP PFNGLSAMPLERPARAMETERFPROC)(GLuint_t sampler, GLenum_t pname, GLfloat_t param);
    PFNGLSAMPLERPARAMETERFPROC oglSamplerParameterf;

    typedef void(APIENTRYP PFNGLSAMPLERPARAMETERFVPROC)(GLuint_t sampler, GLenum_t pname, const GLfloat_t* param);
    PFNGLSAMPLERPARAMETERFVPROC oglSamplerParameterfv;

    typedef void(APIENTRYP PFNGLSAMPLERPARAMETERIIVPROC)(GLuint_t sampler, GLenum_t pname, const GLint_t* param);
    PFNGLSAMPLERPARAMETERIIVPROC oglSamplerParameterIiv;

    typedef void(APIENTRYP PFNGLSAMPLERPARAMETERIUIVPROC)(GLuint_t sampler, GLenum_t pname, const GLuint_t* param);
    PFNGLSAMPLERPARAMETERIUIVPROC oglSamplerParameterIuiv;

    typedef void(APIENTRYP PFNGLGETSAMPLERPARAMETERIVPROC)(GLuint_t sampler, GLenum_t pname, GLint_t* params);
    PFNGLGETSAMPLERPARAMETERIVPROC oglGetSamplerParameteriv;

    typedef void(APIENTRYP PFNGLGETSAMPLERPARAMETERIIVPROC)(GLuint_t sampler, GLenum_t pname, GLint_t* params);
    PFNGLGETSAMPLERPARAMETERIIVPROC oglGetSamplerParameterIiv;

    typedef void(APIENTRYP PFNGLGETSAMPLERPARAMETERFVPROC)(GLuint_t sampler, GLenum_t pname, GLfloat_t* params);
    PFNGLGETSAMPLERPARAMETERFVPROC oglGetSamplerParameterfv;

    typedef void(APIENTRYP PFNGLGETSAMPLERPARAMETERIUIVPROC)(GLuint_t sampler, GLenum_t pname, GLuint_t* params);
    PFNGLGETSAMPLERPARAMETERIUIVPROC oglGetSamplerParameterIuiv;

    typedef void(APIENTRYP PFNGLQUERYCOUNTERPROC)(GLuint_t id, GLenum_t target);
    PFNGLQUERYCOUNTERPROC oglQueryCounter;

    typedef void(APIENTRYP PFNGLGETQUERYOBJECTI64VPROC)(GLuint_t id, GLenum_t pname, GLint64* params);
    PFNGLGETQUERYOBJECTI64VPROC oglGetQueryObjecti64v;

    typedef void(APIENTRYP PFNGLGETQUERYOBJECTUI64VPROC)(GLuint_t id, GLenum_t pname, GLuint64* params);
    PFNGLGETQUERYOBJECTUI64VPROC oglGetQueryObjectui64v;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBDIVISORPROC)(GLuint_t index, GLuint_t divisor);
    PFNGLVERTEXATTRIBDIVISORPROC oglVertexAttribDivisor;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBP1UIPROC)(GLuint_t index, GLenum_t type, GLboolean_t normalized, GLuint_t value);
    PFNGLVERTEXATTRIBP1UIPROC oglVertexAttribP1ui;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBP1UIVPROC)(GLuint_t index, GLenum_t type, GLboolean_t normalized, const GLuint_t* value);
    PFNGLVERTEXATTRIBP1UIVPROC oglVertexAttribP1uiv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBP2UIPROC)(GLuint_t index, GLenum_t type, GLboolean_t normalized, GLuint_t value);
    PFNGLVERTEXATTRIBP2UIPROC oglVertexAttribP2ui;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBP2UIVPROC)(GLuint_t index, GLenum_t type, GLboolean_t normalized, const GLuint_t* value);
    PFNGLVERTEXATTRIBP2UIVPROC oglVertexAttribP2uiv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBP3UIPROC)(GLuint_t index, GLenum_t type, GLboolean_t normalized, GLuint_t value);
    PFNGLVERTEXATTRIBP3UIPROC oglVertexAttribP3ui;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBP3UIVPROC)(GLuint_t index, GLenum_t type, GLboolean_t normalized, const GLuint_t* value);
    PFNGLVERTEXATTRIBP3UIVPROC oglVertexAttribP3uiv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBP4UIPROC)(GLuint_t index, GLenum_t type, GLboolean_t normalized, GLuint_t value);
    PFNGLVERTEXATTRIBP4UIPROC oglVertexAttribP4ui;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBP4UIVPROC)(GLuint_t index, GLenum_t type, GLboolean_t normalized, const GLuint_t* value);
    PFNGLVERTEXATTRIBP4UIVPROC oglVertexAttribP4uiv;

    typedef void(APIENTRYP PFNGLVERTEXP2UIPROC)(GLenum_t type, GLuint_t value);
    PFNGLVERTEXP2UIPROC oglVertexP2ui;

    typedef void(APIENTRYP PFNGLVERTEXP2UIVPROC)(GLenum_t type, const GLuint_t* value);
    PFNGLVERTEXP2UIVPROC oglVertexP2uiv;

    typedef void(APIENTRYP PFNGLVERTEXP3UIPROC)(GLenum_t type, GLuint_t value);
    PFNGLVERTEXP3UIPROC oglVertexP3ui;

    typedef void(APIENTRYP PFNGLVERTEXP3UIVPROC)(GLenum_t type, const GLuint_t* value);
    PFNGLVERTEXP3UIVPROC oglVertexP3uiv;

    typedef void(APIENTRYP PFNGLVERTEXP4UIPROC)(GLenum_t type, GLuint_t value);
    PFNGLVERTEXP4UIPROC oglVertexP4ui;

    typedef void(APIENTRYP PFNGLVERTEXP4UIVPROC)(GLenum_t type, const GLuint_t* value);
    PFNGLVERTEXP4UIVPROC oglVertexP4uiv;

    typedef void(APIENTRYP PFNGLTEXCOORDP1UIPROC)(GLenum_t type, GLuint_t coords);
    PFNGLTEXCOORDP1UIPROC oglTexCoordP1ui;

    typedef void(APIENTRYP PFNGLTEXCOORDP1UIVPROC)(GLenum_t type, const GLuint_t* coords);
    PFNGLTEXCOORDP1UIVPROC oglTexCoordP1uiv;

    typedef void(APIENTRYP PFNGLTEXCOORDP2UIPROC)(GLenum_t type, GLuint_t coords);
    PFNGLTEXCOORDP2UIPROC oglTexCoordP2ui;

    typedef void(APIENTRYP PFNGLTEXCOORDP2UIVPROC)(GLenum_t type, const GLuint_t* coords);
    PFNGLTEXCOORDP2UIVPROC oglTexCoordP2uiv;

    typedef void(APIENTRYP PFNGLTEXCOORDP3UIPROC)(GLenum_t type, GLuint_t coords);
    PFNGLTEXCOORDP3UIPROC oglTexCoordP3ui;

    typedef void(APIENTRYP PFNGLTEXCOORDP3UIVPROC)(GLenum_t type, const GLuint_t* coords);
    PFNGLTEXCOORDP3UIVPROC oglTexCoordP3uiv;

    typedef void(APIENTRYP PFNGLTEXCOORDP4UIPROC)(GLenum_t type, GLuint_t coords);
    PFNGLTEXCOORDP4UIPROC oglTexCoordP4ui;

    typedef void(APIENTRYP PFNGLTEXCOORDP4UIVPROC)(GLenum_t type, const GLuint_t* coords);
    PFNGLTEXCOORDP4UIVPROC oglTexCoordP4uiv;

    typedef void(APIENTRYP PFNGLMULTITEXCOORDP1UIPROC)(GLenum_t texture, GLenum_t type, GLuint_t coords);
    PFNGLMULTITEXCOORDP1UIPROC oglMultiTexCoordP1ui;

    typedef void(APIENTRYP PFNGLMULTITEXCOORDP1UIVPROC)(GLenum_t texture, GLenum_t type, const GLuint_t* coords);
    PFNGLMULTITEXCOORDP1UIVPROC oglMultiTexCoordP1uiv;

    typedef void(APIENTRYP PFNGLMULTITEXCOORDP2UIPROC)(GLenum_t texture, GLenum_t type, GLuint_t coords);
    PFNGLMULTITEXCOORDP2UIPROC oglMultiTexCoordP2ui;

    typedef void(APIENTRYP PFNGLMULTITEXCOORDP2UIVPROC)(GLenum_t texture, GLenum_t type, const GLuint_t* coords);
    PFNGLMULTITEXCOORDP2UIVPROC oglMultiTexCoordP2uiv;

    typedef void(APIENTRYP PFNGLMULTITEXCOORDP3UIPROC)(GLenum_t texture, GLenum_t type, GLuint_t coords);
    PFNGLMULTITEXCOORDP3UIPROC oglMultiTexCoordP3ui;

    typedef void(APIENTRYP PFNGLMULTITEXCOORDP3UIVPROC)(GLenum_t texture, GLenum_t type, const GLuint_t* coords);
    PFNGLMULTITEXCOORDP3UIVPROC oglMultiTexCoordP3uiv;

    typedef void(APIENTRYP PFNGLMULTITEXCOORDP4UIPROC)(GLenum_t texture, GLenum_t type, GLuint_t coords);
    PFNGLMULTITEXCOORDP4UIPROC oglMultiTexCoordP4ui;

    typedef void(APIENTRYP PFNGLMULTITEXCOORDP4UIVPROC)(GLenum_t texture, GLenum_t type, const GLuint_t* coords);
    PFNGLMULTITEXCOORDP4UIVPROC oglMultiTexCoordP4uiv;

    typedef void(APIENTRYP PFNGLNORMALP3UIPROC)(GLenum_t type, GLuint_t coords);
    PFNGLNORMALP3UIPROC oglNormalP3ui;

    typedef void(APIENTRYP PFNGLNORMALP3UIVPROC)(GLenum_t type, const GLuint_t* coords);
    PFNGLNORMALP3UIVPROC oglNormalP3uiv;

    typedef void(APIENTRYP PFNGLCOLORP3UIPROC)(GLenum_t type, GLuint_t color);
    PFNGLCOLORP3UIPROC oglColorP3ui;

    typedef void(APIENTRYP PFNGLCOLORP3UIVPROC)(GLenum_t type, const GLuint_t* color);
    PFNGLCOLORP3UIVPROC oglColorP3uiv;

    typedef void(APIENTRYP PFNGLCOLORP4UIPROC)(GLenum_t type, GLuint_t color);
    PFNGLCOLORP4UIPROC oglColorP4ui;

    typedef void(APIENTRYP PFNGLCOLORP4UIVPROC)(GLenum_t type, const GLuint_t* color);
    PFNGLCOLORP4UIVPROC oglColorP4uiv;

    typedef void(APIENTRYP PFNGLSECONDARYCOLORP3UIPROC)(GLenum_t type, GLuint_t color);
    PFNGLSECONDARYCOLORP3UIPROC oglSecondaryColorP3ui;

    typedef void(APIENTRYP PFNGLSECONDARYCOLORP3UIVPROC)(GLenum_t type, const GLuint_t* color);
    PFNGLSECONDARYCOLORP3UIVPROC oglSecondaryColorP3uiv;

  public:
    GLfuncsv330();

  protected:
    virtual void loadFuncs(Loader loader) override;
};

} // namespace glr
} // namespace xg
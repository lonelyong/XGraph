#pragma once

#include <xg/glr/igl/GLfuncsv320.h>

namespace glr {
class GLR_API GLfuncsv330 : public GLfuncsv320 {

  public:
    typedef void(APIENTRYP PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)(GLuint_t        program,
                                                                 GLuint_t        colorNumber,
                                                                 GLuint_t        index,
                                                                 const GLchar_t* name);
    PFNGLBINDFRAGDATALOCATIONINDEXEDPROC iglBindFragDataLocationIndexed;

    typedef GLint_t(APIENTRYP PFNGLGETFRAGDATAINDEXPROC)(GLuint_t program, const GLchar_t* name);
    PFNGLGETFRAGDATAINDEXPROC iglGetFragDataIndex;

    typedef void(APIENTRYP PFNGLGENSAMPLERSPROC)(GLsizei_t count, GLuint_t* samplers);
    PFNGLGENSAMPLERSPROC iglGenSamplers;

    typedef void(APIENTRYP PFNGLDELETESAMPLERSPROC)(GLsizei_t count, const GLuint_t* samplers);
    PFNGLDELETESAMPLERSPROC iglDeleteSamplers;

    typedef GLboolean_t(APIENTRYP PFNGLISSAMPLERPROC)(GLuint_t sampler);
    PFNGLISSAMPLERPROC iglIsSampler;

    typedef void(APIENTRYP PFNGLBINDSAMPLERPROC)(GLuint_t unit, GLuint_t sampler);
    PFNGLBINDSAMPLERPROC iglBindSampler;

    typedef void(APIENTRYP PFNGLSAMPLERPARAMETERIPROC)(GLuint_t sampler, GLenum_t pname, GLint_t param);
    PFNGLSAMPLERPARAMETERIPROC iglSamplerParameteri;

    typedef void(APIENTRYP PFNGLSAMPLERPARAMETERIVPROC)(GLuint_t sampler, GLenum_t pname, const GLint_t* param);
    PFNGLSAMPLERPARAMETERIVPROC iglSamplerParameteriv;

    typedef void(APIENTRYP PFNGLSAMPLERPARAMETERFPROC)(GLuint_t sampler, GLenum_t pname, GLfloat_t param);
    PFNGLSAMPLERPARAMETERFPROC iglSamplerParameterf;

    typedef void(APIENTRYP PFNGLSAMPLERPARAMETERFVPROC)(GLuint_t sampler, GLenum_t pname, const GLfloat_t* param);
    PFNGLSAMPLERPARAMETERFVPROC iglSamplerParameterfv;

    typedef void(APIENTRYP PFNGLSAMPLERPARAMETERIIVPROC)(GLuint_t sampler, GLenum_t pname, const GLint_t* param);
    PFNGLSAMPLERPARAMETERIIVPROC iglSamplerParameterIiv;

    typedef void(APIENTRYP PFNGLSAMPLERPARAMETERIUIVPROC)(GLuint_t sampler, GLenum_t pname, const GLuint_t* param);
    PFNGLSAMPLERPARAMETERIUIVPROC iglSamplerParameterIuiv;

    typedef void(APIENTRYP PFNGLGETSAMPLERPARAMETERIVPROC)(GLuint_t sampler, GLenum_t pname, GLint_t* params);
    PFNGLGETSAMPLERPARAMETERIVPROC iglGetSamplerParameteriv;

    typedef void(APIENTRYP PFNGLGETSAMPLERPARAMETERIIVPROC)(GLuint_t sampler, GLenum_t pname, GLint_t* params);
    PFNGLGETSAMPLERPARAMETERIIVPROC iglGetSamplerParameterIiv;

    typedef void(APIENTRYP PFNGLGETSAMPLERPARAMETERFVPROC)(GLuint_t sampler, GLenum_t pname, GLfloat_t* params);
    PFNGLGETSAMPLERPARAMETERFVPROC iglGetSamplerParameterfv;

    typedef void(APIENTRYP PFNGLGETSAMPLERPARAMETERIUIVPROC)(GLuint_t sampler, GLenum_t pname, GLuint_t* params);
    PFNGLGETSAMPLERPARAMETERIUIVPROC iglGetSamplerParameterIuiv;

    typedef void(APIENTRYP PFNGLQUERYCOUNTERPROC)(GLuint_t id, GLenum_t target);
    PFNGLQUERYCOUNTERPROC iglQueryCounter;

    typedef void(APIENTRYP PFNGLGETQUERYOBJECTI64VPROC)(GLuint_t id, GLenum_t pname, GLint64* params);
    PFNGLGETQUERYOBJECTI64VPROC iglGetQueryObjecti64v;

    typedef void(APIENTRYP PFNGLGETQUERYOBJECTUI64VPROC)(GLuint_t id, GLenum_t pname, GLuint64* params);
    PFNGLGETQUERYOBJECTUI64VPROC iglGetQueryObjectui64v;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBDIVISORPROC)(GLuint_t index, GLuint_t divisor);
    PFNGLVERTEXATTRIBDIVISORPROC iglVertexAttribDivisor;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBP1UIPROC)(GLuint_t index, GLenum_t type, GLboolean_t normalized, GLuint_t value);
    PFNGLVERTEXATTRIBP1UIPROC iglVertexAttribP1ui;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBP1UIVPROC)(GLuint_t        index,
                                                       GLenum_t        type,
                                                       GLboolean_t     normalized,
                                                       const GLuint_t* value);
    PFNGLVERTEXATTRIBP1UIVPROC iglVertexAttribP1uiv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBP2UIPROC)(GLuint_t index, GLenum_t type, GLboolean_t normalized, GLuint_t value);
    PFNGLVERTEXATTRIBP2UIPROC iglVertexAttribP2ui;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBP2UIVPROC)(GLuint_t        index,
                                                       GLenum_t        type,
                                                       GLboolean_t     normalized,
                                                       const GLuint_t* value);
    PFNGLVERTEXATTRIBP2UIVPROC iglVertexAttribP2uiv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBP3UIPROC)(GLuint_t index, GLenum_t type, GLboolean_t normalized, GLuint_t value);
    PFNGLVERTEXATTRIBP3UIPROC iglVertexAttribP3ui;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBP3UIVPROC)(GLuint_t        index,
                                                       GLenum_t        type,
                                                       GLboolean_t     normalized,
                                                       const GLuint_t* value);
    PFNGLVERTEXATTRIBP3UIVPROC iglVertexAttribP3uiv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBP4UIPROC)(GLuint_t index, GLenum_t type, GLboolean_t normalized, GLuint_t value);
    PFNGLVERTEXATTRIBP4UIPROC iglVertexAttribP4ui;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBP4UIVPROC)(GLuint_t        index,
                                                       GLenum_t        type,
                                                       GLboolean_t     normalized,
                                                       const GLuint_t* value);
    PFNGLVERTEXATTRIBP4UIVPROC iglVertexAttribP4uiv;

    typedef void(APIENTRYP PFNGLVERTEXP2UIPROC)(GLenum_t type, GLuint_t value);
    PFNGLVERTEXP2UIPROC iglVertexP2ui;

    typedef void(APIENTRYP PFNGLVERTEXP2UIVPROC)(GLenum_t type, const GLuint_t* value);
    PFNGLVERTEXP2UIVPROC iglVertexP2uiv;

    typedef void(APIENTRYP PFNGLVERTEXP3UIPROC)(GLenum_t type, GLuint_t value);
    PFNGLVERTEXP3UIPROC iglVertexP3ui;

    typedef void(APIENTRYP PFNGLVERTEXP3UIVPROC)(GLenum_t type, const GLuint_t* value);
    PFNGLVERTEXP3UIVPROC iglVertexP3uiv;

    typedef void(APIENTRYP PFNGLVERTEXP4UIPROC)(GLenum_t type, GLuint_t value);
    PFNGLVERTEXP4UIPROC iglVertexP4ui;

    typedef void(APIENTRYP PFNGLVERTEXP4UIVPROC)(GLenum_t type, const GLuint_t* value);
    PFNGLVERTEXP4UIVPROC iglVertexP4uiv;

    typedef void(APIENTRYP PFNGLTEXCOORDP1UIPROC)(GLenum_t type, GLuint_t coords);
    PFNGLTEXCOORDP1UIPROC iglTexCoordP1ui;

    typedef void(APIENTRYP PFNGLTEXCOORDP1UIVPROC)(GLenum_t type, const GLuint_t* coords);
    PFNGLTEXCOORDP1UIVPROC iglTexCoordP1uiv;

    typedef void(APIENTRYP PFNGLTEXCOORDP2UIPROC)(GLenum_t type, GLuint_t coords);
    PFNGLTEXCOORDP2UIPROC iglTexCoordP2ui;

    typedef void(APIENTRYP PFNGLTEXCOORDP2UIVPROC)(GLenum_t type, const GLuint_t* coords);
    PFNGLTEXCOORDP2UIVPROC iglTexCoordP2uiv;

    typedef void(APIENTRYP PFNGLTEXCOORDP3UIPROC)(GLenum_t type, GLuint_t coords);
    PFNGLTEXCOORDP3UIPROC iglTexCoordP3ui;

    typedef void(APIENTRYP PFNGLTEXCOORDP3UIVPROC)(GLenum_t type, const GLuint_t* coords);
    PFNGLTEXCOORDP3UIVPROC iglTexCoordP3uiv;

    typedef void(APIENTRYP PFNGLTEXCOORDP4UIPROC)(GLenum_t type, GLuint_t coords);
    PFNGLTEXCOORDP4UIPROC iglTexCoordP4ui;

    typedef void(APIENTRYP PFNGLTEXCOORDP4UIVPROC)(GLenum_t type, const GLuint_t* coords);
    PFNGLTEXCOORDP4UIVPROC iglTexCoordP4uiv;

    typedef void(APIENTRYP PFNGLMULTITEXCOORDP1UIPROC)(GLenum_t texture, GLenum_t type, GLuint_t coords);
    PFNGLMULTITEXCOORDP1UIPROC iglMultiTexCoordP1ui;

    typedef void(APIENTRYP PFNGLMULTITEXCOORDP1UIVPROC)(GLenum_t texture, GLenum_t type, const GLuint_t* coords);
    PFNGLMULTITEXCOORDP1UIVPROC iglMultiTexCoordP1uiv;

    typedef void(APIENTRYP PFNGLMULTITEXCOORDP2UIPROC)(GLenum_t texture, GLenum_t type, GLuint_t coords);
    PFNGLMULTITEXCOORDP2UIPROC iglMultiTexCoordP2ui;

    typedef void(APIENTRYP PFNGLMULTITEXCOORDP2UIVPROC)(GLenum_t texture, GLenum_t type, const GLuint_t* coords);
    PFNGLMULTITEXCOORDP2UIVPROC iglMultiTexCoordP2uiv;

    typedef void(APIENTRYP PFNGLMULTITEXCOORDP3UIPROC)(GLenum_t texture, GLenum_t type, GLuint_t coords);
    PFNGLMULTITEXCOORDP3UIPROC iglMultiTexCoordP3ui;

    typedef void(APIENTRYP PFNGLMULTITEXCOORDP3UIVPROC)(GLenum_t texture, GLenum_t type, const GLuint_t* coords);
    PFNGLMULTITEXCOORDP3UIVPROC iglMultiTexCoordP3uiv;

    typedef void(APIENTRYP PFNGLMULTITEXCOORDP4UIPROC)(GLenum_t texture, GLenum_t type, GLuint_t coords);
    PFNGLMULTITEXCOORDP4UIPROC iglMultiTexCoordP4ui;

    typedef void(APIENTRYP PFNGLMULTITEXCOORDP4UIVPROC)(GLenum_t texture, GLenum_t type, const GLuint_t* coords);
    PFNGLMULTITEXCOORDP4UIVPROC iglMultiTexCoordP4uiv;

    typedef void(APIENTRYP PFNGLNORMALP3UIPROC)(GLenum_t type, GLuint_t coords);
    PFNGLNORMALP3UIPROC iglNormalP3ui;

    typedef void(APIENTRYP PFNGLNORMALP3UIVPROC)(GLenum_t type, const GLuint_t* coords);
    PFNGLNORMALP3UIVPROC iglNormalP3uiv;

    typedef void(APIENTRYP PFNGLCOLORP3UIPROC)(GLenum_t type, GLuint_t color);
    PFNGLCOLORP3UIPROC iglColorP3ui;

    typedef void(APIENTRYP PFNGLCOLORP3UIVPROC)(GLenum_t type, const GLuint_t* color);
    PFNGLCOLORP3UIVPROC iglColorP3uiv;

    typedef void(APIENTRYP PFNGLCOLORP4UIPROC)(GLenum_t type, GLuint_t color);
    PFNGLCOLORP4UIPROC iglColorP4ui;

    typedef void(APIENTRYP PFNGLCOLORP4UIVPROC)(GLenum_t type, const GLuint_t* color);
    PFNGLCOLORP4UIVPROC iglColorP4uiv;

    typedef void(APIENTRYP PFNGLSECONDARYCOLORP3UIPROC)(GLenum_t type, GLuint_t color);
    PFNGLSECONDARYCOLORP3UIPROC iglSecondaryColorP3ui;

    typedef void(APIENTRYP PFNGLSECONDARYCOLORP3UIVPROC)(GLenum_t type, const GLuint_t* color);
    PFNGLSECONDARYCOLORP3UIVPROC iglSecondaryColorP3uiv;

  public:
    GLfuncsv330();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
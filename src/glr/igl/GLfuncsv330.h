#pragma once

#include <glr/igl/GLfuncsv320.h>

namespace glr {
class GLR_API GLfuncsv330 : public GLfuncsv320 {
  public:
    typedef void(APIENTRYP PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)(GLuint        program,
                                                                 GLuint        colorNumber,
                                                                 GLuint        index,
                                                                 const GLchar* name);
    PFNGLBINDFRAGDATALOCATIONINDEXEDPROC glBindFragDataLocationIndexed;

    typedef GLint(APIENTRYP PFNGLGETFRAGDATAINDEXPROC)(GLuint program, const GLchar* name);
    PFNGLGETFRAGDATAINDEXPROC glGetFragDataIndex;

    typedef void(APIENTRYP PFNGLGENSAMPLERSPROC)(GLsizei count, GLuint* samplers);
    PFNGLGENSAMPLERSPROC glGenSamplers;

    typedef void(APIENTRYP PFNGLDELETESAMPLERSPROC)(GLsizei count, const GLuint* samplers);
    PFNGLDELETESAMPLERSPROC glDeleteSamplers;

    typedef GLboolean(APIENTRYP PFNGLISSAMPLERPROC)(GLuint sampler);
    PFNGLISSAMPLERPROC glIsSampler;

    typedef void(APIENTRYP PFNGLBINDSAMPLERPROC)(GLuint unit, GLuint sampler);
    PFNGLBINDSAMPLERPROC glBindSampler;

    typedef void(APIENTRYP PFNGLSAMPLERPARAMETERIPROC)(GLuint sampler, GLenum pname, GLint param);
    PFNGLSAMPLERPARAMETERIPROC glSamplerParameteri;

    typedef void(APIENTRYP PFNGLSAMPLERPARAMETERIVPROC)(GLuint sampler, GLenum pname, const GLint* param);
    PFNGLSAMPLERPARAMETERIVPROC glSamplerParameteriv;

    typedef void(APIENTRYP PFNGLSAMPLERPARAMETERFPROC)(GLuint sampler, GLenum pname, GLfloat param);
    PFNGLSAMPLERPARAMETERFPROC glSamplerParameterf;

    typedef void(APIENTRYP PFNGLSAMPLERPARAMETERFVPROC)(GLuint sampler, GLenum pname, const GLfloat* param);
    PFNGLSAMPLERPARAMETERFVPROC glSamplerParameterfv;

    typedef void(APIENTRYP PFNGLSAMPLERPARAMETERIIVPROC)(GLuint sampler, GLenum pname, const GLint* param);
    PFNGLSAMPLERPARAMETERIIVPROC glSamplerParameterIiv;

    typedef void(APIENTRYP PFNGLSAMPLERPARAMETERIUIVPROC)(GLuint sampler, GLenum pname, const GLuint* param);
    PFNGLSAMPLERPARAMETERIUIVPROC glSamplerParameterIuiv;

    typedef void(APIENTRYP PFNGLGETSAMPLERPARAMETERIVPROC)(GLuint sampler, GLenum pname, GLint* params);
    PFNGLGETSAMPLERPARAMETERIVPROC glGetSamplerParameteriv;

    typedef void(APIENTRYP PFNGLGETSAMPLERPARAMETERIIVPROC)(GLuint sampler, GLenum pname, GLint* params);
    PFNGLGETSAMPLERPARAMETERIIVPROC glGetSamplerParameterIiv;

    typedef void(APIENTRYP PFNGLGETSAMPLERPARAMETERFVPROC)(GLuint sampler, GLenum pname, GLfloat* params);
    PFNGLGETSAMPLERPARAMETERFVPROC glGetSamplerParameterfv;

    typedef void(APIENTRYP PFNGLGETSAMPLERPARAMETERIUIVPROC)(GLuint sampler, GLenum pname, GLuint* params);
    PFNGLGETSAMPLERPARAMETERIUIVPROC glGetSamplerParameterIuiv;

    typedef void(APIENTRYP PFNGLQUERYCOUNTERPROC)(GLuint id, GLenum target);
    PFNGLQUERYCOUNTERPROC glQueryCounter;

    typedef void(APIENTRYP PFNGLGETQUERYOBJECTI64VPROC)(GLuint id, GLenum pname, GLint64* params);
    PFNGLGETQUERYOBJECTI64VPROC glGetQueryObjecti64v;

    typedef void(APIENTRYP PFNGLGETQUERYOBJECTUI64VPROC)(GLuint id, GLenum pname, GLuint64* params);
    PFNGLGETQUERYOBJECTUI64VPROC glGetQueryObjectui64v;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBDIVISORPROC)(GLuint index, GLuint divisor);
    PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisor;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBP1UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
    PFNGLVERTEXATTRIBP1UIPROC glVertexAttribP1ui;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBP1UIVPROC)(GLuint        index,
                                                       GLenum        type,
                                                       GLboolean     normalized,
                                                       const GLuint* value);
    PFNGLVERTEXATTRIBP1UIVPROC glVertexAttribP1uiv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBP2UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
    PFNGLVERTEXATTRIBP2UIPROC glVertexAttribP2ui;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBP2UIVPROC)(GLuint        index,
                                                       GLenum        type,
                                                       GLboolean     normalized,
                                                       const GLuint* value);
    PFNGLVERTEXATTRIBP2UIVPROC glVertexAttribP2uiv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBP3UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
    PFNGLVERTEXATTRIBP3UIPROC glVertexAttribP3ui;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBP3UIVPROC)(GLuint        index,
                                                       GLenum        type,
                                                       GLboolean     normalized,
                                                       const GLuint* value);
    PFNGLVERTEXATTRIBP3UIVPROC glVertexAttribP3uiv;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBP4UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
    PFNGLVERTEXATTRIBP4UIPROC glVertexAttribP4ui;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBP4UIVPROC)(GLuint        index,
                                                       GLenum        type,
                                                       GLboolean     normalized,
                                                       const GLuint* value);
    PFNGLVERTEXATTRIBP4UIVPROC glVertexAttribP4uiv;

    typedef void(APIENTRYP PFNGLVERTEXP2UIPROC)(GLenum type, GLuint value);
    PFNGLVERTEXP2UIPROC glVertexP2ui;

    typedef void(APIENTRYP PFNGLVERTEXP2UIVPROC)(GLenum type, const GLuint* value);
    PFNGLVERTEXP2UIVPROC glVertexP2uiv;

    typedef void(APIENTRYP PFNGLVERTEXP3UIPROC)(GLenum type, GLuint value);
    PFNGLVERTEXP3UIPROC glVertexP3ui;

    typedef void(APIENTRYP PFNGLVERTEXP3UIVPROC)(GLenum type, const GLuint* value);
    PFNGLVERTEXP3UIVPROC glVertexP3uiv;

    typedef void(APIENTRYP PFNGLVERTEXP4UIPROC)(GLenum type, GLuint value);
    PFNGLVERTEXP4UIPROC glVertexP4ui;

    typedef void(APIENTRYP PFNGLVERTEXP4UIVPROC)(GLenum type, const GLuint* value);
    PFNGLVERTEXP4UIVPROC glVertexP4uiv;

    typedef void(APIENTRYP PFNGLTEXCOORDP1UIPROC)(GLenum type, GLuint coords);
    PFNGLTEXCOORDP1UIPROC glTexCoordP1ui;

    typedef void(APIENTRYP PFNGLTEXCOORDP1UIVPROC)(GLenum type, const GLuint* coords);
    PFNGLTEXCOORDP1UIVPROC glTexCoordP1uiv;

    typedef void(APIENTRYP PFNGLTEXCOORDP2UIPROC)(GLenum type, GLuint coords);
    PFNGLTEXCOORDP2UIPROC glTexCoordP2ui;

    typedef void(APIENTRYP PFNGLTEXCOORDP2UIVPROC)(GLenum type, const GLuint* coords);
    PFNGLTEXCOORDP2UIVPROC glTexCoordP2uiv;

    typedef void(APIENTRYP PFNGLTEXCOORDP3UIPROC)(GLenum type, GLuint coords);
    PFNGLTEXCOORDP3UIPROC glTexCoordP3ui;

    typedef void(APIENTRYP PFNGLTEXCOORDP3UIVPROC)(GLenum type, const GLuint* coords);
    PFNGLTEXCOORDP3UIVPROC glTexCoordP3uiv;

    typedef void(APIENTRYP PFNGLTEXCOORDP4UIPROC)(GLenum type, GLuint coords);
    PFNGLTEXCOORDP4UIPROC glTexCoordP4ui;

    typedef void(APIENTRYP PFNGLTEXCOORDP4UIVPROC)(GLenum type, const GLuint* coords);
    PFNGLTEXCOORDP4UIVPROC glTexCoordP4uiv;

    typedef void(APIENTRYP PFNGLMULTITEXCOORDP1UIPROC)(GLenum texture, GLenum type, GLuint coords);
    PFNGLMULTITEXCOORDP1UIPROC glMultiTexCoordP1ui;

    typedef void(APIENTRYP PFNGLMULTITEXCOORDP1UIVPROC)(GLenum texture, GLenum type, const GLuint* coords);
    PFNGLMULTITEXCOORDP1UIVPROC glMultiTexCoordP1uiv;

    typedef void(APIENTRYP PFNGLMULTITEXCOORDP2UIPROC)(GLenum texture, GLenum type, GLuint coords);
    PFNGLMULTITEXCOORDP2UIPROC glMultiTexCoordP2ui;

    typedef void(APIENTRYP PFNGLMULTITEXCOORDP2UIVPROC)(GLenum texture, GLenum type, const GLuint* coords);
    PFNGLMULTITEXCOORDP2UIVPROC glMultiTexCoordP2uiv;

    typedef void(APIENTRYP PFNGLMULTITEXCOORDP3UIPROC)(GLenum texture, GLenum type, GLuint coords);
    PFNGLMULTITEXCOORDP3UIPROC glMultiTexCoordP3ui;

    typedef void(APIENTRYP PFNGLMULTITEXCOORDP3UIVPROC)(GLenum texture, GLenum type, const GLuint* coords);
    PFNGLMULTITEXCOORDP3UIVPROC glMultiTexCoordP3uiv;

    typedef void(APIENTRYP PFNGLMULTITEXCOORDP4UIPROC)(GLenum texture, GLenum type, GLuint coords);
    PFNGLMULTITEXCOORDP4UIPROC glMultiTexCoordP4ui;

    typedef void(APIENTRYP PFNGLMULTITEXCOORDP4UIVPROC)(GLenum texture, GLenum type, const GLuint* coords);
    PFNGLMULTITEXCOORDP4UIVPROC glMultiTexCoordP4uiv;

    typedef void(APIENTRYP PFNGLNORMALP3UIPROC)(GLenum type, GLuint coords);
    PFNGLNORMALP3UIPROC glNormalP3ui;

    typedef void(APIENTRYP PFNGLNORMALP3UIVPROC)(GLenum type, const GLuint* coords);
    PFNGLNORMALP3UIVPROC glNormalP3uiv;

    typedef void(APIENTRYP PFNGLCOLORP3UIPROC)(GLenum type, GLuint color);
    PFNGLCOLORP3UIPROC glColorP3ui;

    typedef void(APIENTRYP PFNGLCOLORP3UIVPROC)(GLenum type, const GLuint* color);
    PFNGLCOLORP3UIVPROC glColorP3uiv;

    typedef void(APIENTRYP PFNGLCOLORP4UIPROC)(GLenum type, GLuint color);
    PFNGLCOLORP4UIPROC glColorP4ui;

    typedef void(APIENTRYP PFNGLCOLORP4UIVPROC)(GLenum type, const GLuint* color);
    PFNGLCOLORP4UIVPROC glColorP4uiv;

    typedef void(APIENTRYP PFNGLSECONDARYCOLORP3UIPROC)(GLenum type, GLuint color);
    PFNGLSECONDARYCOLORP3UIPROC glSecondaryColorP3ui;

    typedef void(APIENTRYP PFNGLSECONDARYCOLORP3UIVPROC)(GLenum type, const GLuint* color);
    PFNGLSECONDARYCOLORP3UIVPROC glSecondaryColorP3uiv;

  public:
    GLfuncsv330();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
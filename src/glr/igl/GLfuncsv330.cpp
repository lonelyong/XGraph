#include "GLfuncsv330.h"

namespace glr {
glr::GLfuncsv330::GLfuncsv330()
  : glBindFragDataLocationIndexed(nullptr)
  , glBindSampler(nullptr)
  , glColorP3uiv(nullptr)
  , glColorP3ui(nullptr)
  , glColorP4uiv(nullptr)
  , glColorP4ui(nullptr)
  , glDeleteSamplers(nullptr)
  , glGenSamplers(nullptr)
  , glGetFragDataIndex(nullptr)
  , glGetQueryObjecti64v(nullptr)
  , glGetQueryObjectui64v(nullptr)
  , glGetSamplerParameterIiv(nullptr)
  , glGetSamplerParameterIuiv(nullptr)
  , glGetSamplerParameterfv(nullptr)
  , glGetSamplerParameteriv(nullptr)
  , glIsSampler(nullptr)
  , glMultiTexCoordP1uiv(nullptr)
  , glMultiTexCoordP1ui(nullptr)
  , glMultiTexCoordP2uiv(nullptr)
  , glMultiTexCoordP2ui(nullptr)
  , glMultiTexCoordP3uiv(nullptr)
  , glMultiTexCoordP3ui(nullptr)
  , glMultiTexCoordP4uiv(nullptr)
  , glMultiTexCoordP4ui(nullptr)
  , glNormalP3uiv(nullptr)
  , glNormalP3ui(nullptr)
  , glQueryCounter(nullptr)
  , glSamplerParameterIiv(nullptr)
  , glSamplerParameterIuiv(nullptr)
  , glSamplerParameterfv(nullptr)
  , glSamplerParameterf(nullptr)
  , glSamplerParameteriv(nullptr)
  , glSamplerParameteri(nullptr)
  , glSecondaryColorP3uiv(nullptr)
  , glSecondaryColorP3ui(nullptr)
  , glTexCoordP1uiv(nullptr)
  , glTexCoordP1ui(nullptr)
  , glTexCoordP2uiv(nullptr)
  , glTexCoordP2ui(nullptr)
  , glTexCoordP3uiv(nullptr)
  , glTexCoordP3ui(nullptr)
  , glTexCoordP4uiv(nullptr)
  , glTexCoordP4ui(nullptr)
  , glVertexAttribDivisor(nullptr)
  , glVertexAttribP1uiv(nullptr)
  , glVertexAttribP1ui(nullptr)
  , glVertexAttribP2uiv(nullptr)
  , glVertexAttribP2ui(nullptr)
  , glVertexAttribP3uiv(nullptr)
  , glVertexAttribP3ui(nullptr)
  , glVertexAttribP4uiv(nullptr)
  , glVertexAttribP4ui(nullptr)
  , glVertexP2uiv(nullptr)
  , glVertexP2ui(nullptr)
  , glVertexP3uiv(nullptr)
  , glVertexP3ui(nullptr)
  , glVertexP4uiv(nullptr)
  , glVertexP4ui(nullptr) {
}

void glr::GLfuncsv330::loadFuncs(Loader loader) {
    GLfuncsv320::loadFuncs(loader);
    glBindFragDataLocationIndexed =
        reinterpret_cast<PFNGLBINDFRAGDATALOCATIONINDEXEDPROC>(loader("glBindFragDataLocationIndexed"));
    glBindSampler             = reinterpret_cast<PFNGLBINDSAMPLERPROC>(loader("glBindSampler"));
    glColorP3uiv              = reinterpret_cast<PFNGLCOLORP3UIVPROC>(loader("glColorP3uiv"));
    glColorP3ui               = reinterpret_cast<PFNGLCOLORP3UIPROC>(loader("glColorP3ui"));
    glColorP4uiv              = reinterpret_cast<PFNGLCOLORP4UIVPROC>(loader("glColorP4uiv"));
    glColorP4ui               = reinterpret_cast<PFNGLCOLORP4UIPROC>(loader("glColorP4ui"));
    glDeleteSamplers          = reinterpret_cast<PFNGLDELETESAMPLERSPROC>(loader("glDeleteSamplers"));
    glGenSamplers             = reinterpret_cast<PFNGLGENSAMPLERSPROC>(loader("glGenSamplers"));
    glGetFragDataIndex        = reinterpret_cast<PFNGLGETFRAGDATAINDEXPROC>(loader("glGetFragDataIndex"));
    glGetQueryObjecti64v      = reinterpret_cast<PFNGLGETQUERYOBJECTI64VPROC>(loader("glGetQueryObjecti64v"));
    glGetQueryObjectui64v     = reinterpret_cast<PFNGLGETQUERYOBJECTUI64VPROC>(loader("glGetQueryObjectui64v"));
    glGetSamplerParameterIiv  = reinterpret_cast<PFNGLGETSAMPLERPARAMETERIIVPROC>(loader("glGetSamplerParameterIiv"));
    glGetSamplerParameterIuiv = reinterpret_cast<PFNGLGETSAMPLERPARAMETERIUIVPROC>(loader("glGetSamplerParameterIuiv"));
    glGetSamplerParameterfv   = reinterpret_cast<PFNGLGETSAMPLERPARAMETERFVPROC>(loader("glGetSamplerParameterfv"));
    glGetSamplerParameteriv   = reinterpret_cast<PFNGLGETSAMPLERPARAMETERIVPROC>(loader("glGetSamplerParameteriv"));
    glIsSampler               = reinterpret_cast<PFNGLISSAMPLERPROC>(loader("glIsSampler"));
    glMultiTexCoordP1uiv      = reinterpret_cast<PFNGLMULTITEXCOORDP1UIVPROC>(loader("glMultiTexCoordP1uiv"));
    glMultiTexCoordP1ui       = reinterpret_cast<PFNGLMULTITEXCOORDP1UIPROC>(loader("glMultiTexCoordP1ui"));
    glMultiTexCoordP2uiv      = reinterpret_cast<PFNGLMULTITEXCOORDP2UIVPROC>(loader("glMultiTexCoordP2uiv"));
    glMultiTexCoordP2ui       = reinterpret_cast<PFNGLMULTITEXCOORDP2UIPROC>(loader("glMultiTexCoordP2ui"));
    glMultiTexCoordP3uiv      = reinterpret_cast<PFNGLMULTITEXCOORDP3UIVPROC>(loader("glMultiTexCoordP3uiv"));
    glMultiTexCoordP3ui       = reinterpret_cast<PFNGLMULTITEXCOORDP3UIPROC>(loader("glMultiTexCoordP3ui"));
    glMultiTexCoordP4uiv      = reinterpret_cast<PFNGLMULTITEXCOORDP4UIVPROC>(loader("glMultiTexCoordP4uiv"));
    glMultiTexCoordP4ui       = reinterpret_cast<PFNGLMULTITEXCOORDP4UIPROC>(loader("glMultiTexCoordP4ui"));
    glNormalP3uiv             = reinterpret_cast<PFNGLNORMALP3UIVPROC>(loader("glNormalP3uiv"));
    glNormalP3ui              = reinterpret_cast<PFNGLNORMALP3UIPROC>(loader("glNormalP3ui"));
    glQueryCounter            = reinterpret_cast<PFNGLQUERYCOUNTERPROC>(loader("glQueryCounter"));
    glSamplerParameterIiv     = reinterpret_cast<PFNGLSAMPLERPARAMETERIIVPROC>(loader("glSamplerParameterIiv"));
    glSamplerParameterIuiv    = reinterpret_cast<PFNGLSAMPLERPARAMETERIUIVPROC>(loader("glSamplerParameterIuiv"));
    glSamplerParameterfv      = reinterpret_cast<PFNGLSAMPLERPARAMETERFVPROC>(loader("glSamplerParameterfv"));
    glSamplerParameterf       = reinterpret_cast<PFNGLSAMPLERPARAMETERFPROC>(loader("glSamplerParameterf"));
    glSamplerParameteriv      = reinterpret_cast<PFNGLSAMPLERPARAMETERIVPROC>(loader("glSamplerParameteriv"));
    glSamplerParameteri       = reinterpret_cast<PFNGLSAMPLERPARAMETERIPROC>(loader("glSamplerParameteri"));
    glSecondaryColorP3uiv     = reinterpret_cast<PFNGLSECONDARYCOLORP3UIVPROC>(loader("glSecondaryColorP3uiv"));
    glSecondaryColorP3ui      = reinterpret_cast<PFNGLSECONDARYCOLORP3UIPROC>(loader("glSecondaryColorP3ui"));
    glTexCoordP1uiv           = reinterpret_cast<PFNGLTEXCOORDP1UIVPROC>(loader("glTexCoordP1uiv"));
    glTexCoordP1ui            = reinterpret_cast<PFNGLTEXCOORDP1UIPROC>(loader("glTexCoordP1ui"));
    glTexCoordP2uiv           = reinterpret_cast<PFNGLTEXCOORDP2UIVPROC>(loader("glTexCoordP2uiv"));
    glTexCoordP2ui            = reinterpret_cast<PFNGLTEXCOORDP2UIPROC>(loader("glTexCoordP2ui"));
    glTexCoordP3uiv           = reinterpret_cast<PFNGLTEXCOORDP3UIVPROC>(loader("glTexCoordP3uiv"));
    glTexCoordP3ui            = reinterpret_cast<PFNGLTEXCOORDP3UIPROC>(loader("glTexCoordP3ui"));
    glTexCoordP4uiv           = reinterpret_cast<PFNGLTEXCOORDP4UIVPROC>(loader("glTexCoordP4uiv"));
    glTexCoordP4ui            = reinterpret_cast<PFNGLTEXCOORDP4UIPROC>(loader("glTexCoordP4ui"));
    glVertexAttribDivisor     = reinterpret_cast<PFNGLVERTEXATTRIBDIVISORPROC>(loader("glVertexAttribDivisor"));
    glVertexAttribP1uiv       = reinterpret_cast<PFNGLVERTEXATTRIBP1UIVPROC>(loader("glVertexAttribP1uiv"));
    glVertexAttribP1ui        = reinterpret_cast<PFNGLVERTEXATTRIBP1UIPROC>(loader("glVertexAttribP1ui"));
    glVertexAttribP2uiv       = reinterpret_cast<PFNGLVERTEXATTRIBP2UIVPROC>(loader("glVertexAttribP2uiv"));
    glVertexAttribP2ui        = reinterpret_cast<PFNGLVERTEXATTRIBP2UIPROC>(loader("glVertexAttribP2ui"));
    glVertexAttribP3uiv       = reinterpret_cast<PFNGLVERTEXATTRIBP3UIVPROC>(loader("glVertexAttribP3uiv"));
    glVertexAttribP3ui        = reinterpret_cast<PFNGLVERTEXATTRIBP3UIPROC>(loader("glVertexAttribP3ui"));
    glVertexAttribP4uiv       = reinterpret_cast<PFNGLVERTEXATTRIBP4UIVPROC>(loader("glVertexAttribP4uiv"));
    glVertexAttribP4ui        = reinterpret_cast<PFNGLVERTEXATTRIBP4UIPROC>(loader("glVertexAttribP4ui"));
    glVertexP2uiv             = reinterpret_cast<PFNGLVERTEXP2UIVPROC>(loader("glVertexP2uiv"));
    glVertexP2ui              = reinterpret_cast<PFNGLVERTEXP2UIPROC>(loader("glVertexP2ui"));
    glVertexP3uiv             = reinterpret_cast<PFNGLVERTEXP3UIVPROC>(loader("glVertexP3uiv"));
    glVertexP3ui              = reinterpret_cast<PFNGLVERTEXP3UIPROC>(loader("glVertexP3ui"));
    glVertexP4uiv             = reinterpret_cast<PFNGLVERTEXP4UIVPROC>(loader("glVertexP4uiv"));
    glVertexP4ui              = reinterpret_cast<PFNGLVERTEXP4UIPROC>(loader("glVertexP4ui"));
}
}



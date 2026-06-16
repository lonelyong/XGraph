#include <xg/glr/igl/GLfuncsv330.hpp>

namespace xg {
namespace glr {


glr::GLfuncsv330::GLfuncsv330()
  : iglBindFragDataLocationIndexed(nullptr)
  , iglBindSampler(nullptr)
  , iglColorP3uiv(nullptr)
  , iglColorP3ui(nullptr)
  , iglColorP4uiv(nullptr)
  , iglColorP4ui(nullptr)
  , iglDeleteSamplers(nullptr)
  , iglGenSamplers(nullptr)
  , iglGetFragDataIndex(nullptr)
  , iglGetQueryObjecti64v(nullptr)
  , iglGetQueryObjectui64v(nullptr)
  , iglGetSamplerParameterIiv(nullptr)
  , iglGetSamplerParameterIuiv(nullptr)
  , iglGetSamplerParameterfv(nullptr)
  , iglGetSamplerParameteriv(nullptr)
  , iglIsSampler(nullptr)
  , iglMultiTexCoordP1uiv(nullptr)
  , iglMultiTexCoordP1ui(nullptr)
  , iglMultiTexCoordP2uiv(nullptr)
  , iglMultiTexCoordP2ui(nullptr)
  , iglMultiTexCoordP3uiv(nullptr)
  , iglMultiTexCoordP3ui(nullptr)
  , iglMultiTexCoordP4uiv(nullptr)
  , iglMultiTexCoordP4ui(nullptr)
  , iglNormalP3uiv(nullptr)
  , iglNormalP3ui(nullptr)
  , iglQueryCounter(nullptr)
  , iglSamplerParameterIiv(nullptr)
  , iglSamplerParameterIuiv(nullptr)
  , iglSamplerParameterfv(nullptr)
  , iglSamplerParameterf(nullptr)
  , iglSamplerParameteriv(nullptr)
  , iglSamplerParameteri(nullptr)
  , iglSecondaryColorP3uiv(nullptr)
  , iglSecondaryColorP3ui(nullptr)
  , iglTexCoordP1uiv(nullptr)
  , iglTexCoordP1ui(nullptr)
  , iglTexCoordP2uiv(nullptr)
  , iglTexCoordP2ui(nullptr)
  , iglTexCoordP3uiv(nullptr)
  , iglTexCoordP3ui(nullptr)
  , iglTexCoordP4uiv(nullptr)
  , iglTexCoordP4ui(nullptr)
  , iglVertexAttribDivisor(nullptr)
  , iglVertexAttribP1uiv(nullptr)
  , iglVertexAttribP1ui(nullptr)
  , iglVertexAttribP2uiv(nullptr)
  , iglVertexAttribP2ui(nullptr)
  , iglVertexAttribP3uiv(nullptr)
  , iglVertexAttribP3ui(nullptr)
  , iglVertexAttribP4uiv(nullptr)
  , iglVertexAttribP4ui(nullptr)
  , iglVertexP2uiv(nullptr)
  , iglVertexP2ui(nullptr)
  , iglVertexP3uiv(nullptr)
  , iglVertexP3ui(nullptr)
  , iglVertexP4uiv(nullptr)
  , iglVertexP4ui(nullptr) {
}

void glr::GLfuncsv330::loadFuncs(Loader loader) {
    GLfuncsv320::loadFuncs(loader);
    iglBindFragDataLocationIndexed =
        reinterpret_cast<PFNGLBINDFRAGDATALOCATIONINDEXEDPROC>(loader("glBindFragDataLocationIndexed"));
    iglBindSampler             = reinterpret_cast<PFNGLBINDSAMPLERPROC>(loader("glBindSampler"));
    iglColorP3uiv              = reinterpret_cast<PFNGLCOLORP3UIVPROC>(loader("glColorP3uiv"));
    iglColorP3ui               = reinterpret_cast<PFNGLCOLORP3UIPROC>(loader("glColorP3ui"));
    iglColorP4uiv              = reinterpret_cast<PFNGLCOLORP4UIVPROC>(loader("glColorP4uiv"));
    iglColorP4ui               = reinterpret_cast<PFNGLCOLORP4UIPROC>(loader("glColorP4ui"));
    iglDeleteSamplers          = reinterpret_cast<PFNGLDELETESAMPLERSPROC>(loader("glDeleteSamplers"));
    iglGenSamplers             = reinterpret_cast<PFNGLGENSAMPLERSPROC>(loader("glGenSamplers"));
    iglGetFragDataIndex        = reinterpret_cast<PFNGLGETFRAGDATAINDEXPROC>(loader("glGetFragDataIndex"));
    iglGetQueryObjecti64v      = reinterpret_cast<PFNGLGETQUERYOBJECTI64VPROC>(loader("glGetQueryObjecti64v"));
    iglGetQueryObjectui64v     = reinterpret_cast<PFNGLGETQUERYOBJECTUI64VPROC>(loader("glGetQueryObjectui64v"));
    iglGetSamplerParameterIiv  = reinterpret_cast<PFNGLGETSAMPLERPARAMETERIIVPROC>(loader("glGetSamplerParameterIiv"));
    iglGetSamplerParameterIuiv = reinterpret_cast<PFNGLGETSAMPLERPARAMETERIUIVPROC>(loader("glGetSamplerParameterIuiv"));
    iglGetSamplerParameterfv   = reinterpret_cast<PFNGLGETSAMPLERPARAMETERFVPROC>(loader("glGetSamplerParameterfv"));
    iglGetSamplerParameteriv   = reinterpret_cast<PFNGLGETSAMPLERPARAMETERIVPROC>(loader("glGetSamplerParameteriv"));
    iglIsSampler               = reinterpret_cast<PFNGLISSAMPLERPROC>(loader("glIsSampler"));
    iglMultiTexCoordP1uiv      = reinterpret_cast<PFNGLMULTITEXCOORDP1UIVPROC>(loader("glMultiTexCoordP1uiv"));
    iglMultiTexCoordP1ui       = reinterpret_cast<PFNGLMULTITEXCOORDP1UIPROC>(loader("glMultiTexCoordP1ui"));
    iglMultiTexCoordP2uiv      = reinterpret_cast<PFNGLMULTITEXCOORDP2UIVPROC>(loader("glMultiTexCoordP2uiv"));
    iglMultiTexCoordP2ui       = reinterpret_cast<PFNGLMULTITEXCOORDP2UIPROC>(loader("glMultiTexCoordP2ui"));
    iglMultiTexCoordP3uiv      = reinterpret_cast<PFNGLMULTITEXCOORDP3UIVPROC>(loader("glMultiTexCoordP3uiv"));
    iglMultiTexCoordP3ui       = reinterpret_cast<PFNGLMULTITEXCOORDP3UIPROC>(loader("glMultiTexCoordP3ui"));
    iglMultiTexCoordP4uiv      = reinterpret_cast<PFNGLMULTITEXCOORDP4UIVPROC>(loader("glMultiTexCoordP4uiv"));
    iglMultiTexCoordP4ui       = reinterpret_cast<PFNGLMULTITEXCOORDP4UIPROC>(loader("glMultiTexCoordP4ui"));
    iglNormalP3uiv             = reinterpret_cast<PFNGLNORMALP3UIVPROC>(loader("glNormalP3uiv"));
    iglNormalP3ui              = reinterpret_cast<PFNGLNORMALP3UIPROC>(loader("glNormalP3ui"));
    iglQueryCounter            = reinterpret_cast<PFNGLQUERYCOUNTERPROC>(loader("glQueryCounter"));
    iglSamplerParameterIiv     = reinterpret_cast<PFNGLSAMPLERPARAMETERIIVPROC>(loader("glSamplerParameterIiv"));
    iglSamplerParameterIuiv    = reinterpret_cast<PFNGLSAMPLERPARAMETERIUIVPROC>(loader("glSamplerParameterIuiv"));
    iglSamplerParameterfv      = reinterpret_cast<PFNGLSAMPLERPARAMETERFVPROC>(loader("glSamplerParameterfv"));
    iglSamplerParameterf       = reinterpret_cast<PFNGLSAMPLERPARAMETERFPROC>(loader("glSamplerParameterf"));
    iglSamplerParameteriv      = reinterpret_cast<PFNGLSAMPLERPARAMETERIVPROC>(loader("glSamplerParameteriv"));
    iglSamplerParameteri       = reinterpret_cast<PFNGLSAMPLERPARAMETERIPROC>(loader("glSamplerParameteri"));
    iglSecondaryColorP3uiv     = reinterpret_cast<PFNGLSECONDARYCOLORP3UIVPROC>(loader("glSecondaryColorP3uiv"));
    iglSecondaryColorP3ui      = reinterpret_cast<PFNGLSECONDARYCOLORP3UIPROC>(loader("glSecondaryColorP3ui"));
    iglTexCoordP1uiv           = reinterpret_cast<PFNGLTEXCOORDP1UIVPROC>(loader("glTexCoordP1uiv"));
    iglTexCoordP1ui            = reinterpret_cast<PFNGLTEXCOORDP1UIPROC>(loader("glTexCoordP1ui"));
    iglTexCoordP2uiv           = reinterpret_cast<PFNGLTEXCOORDP2UIVPROC>(loader("glTexCoordP2uiv"));
    iglTexCoordP2ui            = reinterpret_cast<PFNGLTEXCOORDP2UIPROC>(loader("glTexCoordP2ui"));
    iglTexCoordP3uiv           = reinterpret_cast<PFNGLTEXCOORDP3UIVPROC>(loader("glTexCoordP3uiv"));
    iglTexCoordP3ui            = reinterpret_cast<PFNGLTEXCOORDP3UIPROC>(loader("glTexCoordP3ui"));
    iglTexCoordP4uiv           = reinterpret_cast<PFNGLTEXCOORDP4UIVPROC>(loader("glTexCoordP4uiv"));
    iglTexCoordP4ui            = reinterpret_cast<PFNGLTEXCOORDP4UIPROC>(loader("glTexCoordP4ui"));
    iglVertexAttribDivisor     = reinterpret_cast<PFNGLVERTEXATTRIBDIVISORPROC>(loader("glVertexAttribDivisor"));
    iglVertexAttribP1uiv       = reinterpret_cast<PFNGLVERTEXATTRIBP1UIVPROC>(loader("glVertexAttribP1uiv"));
    iglVertexAttribP1ui        = reinterpret_cast<PFNGLVERTEXATTRIBP1UIPROC>(loader("glVertexAttribP1ui"));
    iglVertexAttribP2uiv       = reinterpret_cast<PFNGLVERTEXATTRIBP2UIVPROC>(loader("glVertexAttribP2uiv"));
    iglVertexAttribP2ui        = reinterpret_cast<PFNGLVERTEXATTRIBP2UIPROC>(loader("glVertexAttribP2ui"));
    iglVertexAttribP3uiv       = reinterpret_cast<PFNGLVERTEXATTRIBP3UIVPROC>(loader("glVertexAttribP3uiv"));
    iglVertexAttribP3ui        = reinterpret_cast<PFNGLVERTEXATTRIBP3UIPROC>(loader("glVertexAttribP3ui"));
    iglVertexAttribP4uiv       = reinterpret_cast<PFNGLVERTEXATTRIBP4UIVPROC>(loader("glVertexAttribP4uiv"));
    iglVertexAttribP4ui        = reinterpret_cast<PFNGLVERTEXATTRIBP4UIPROC>(loader("glVertexAttribP4ui"));
    iglVertexP2uiv             = reinterpret_cast<PFNGLVERTEXP2UIVPROC>(loader("glVertexP2uiv"));
    iglVertexP2ui              = reinterpret_cast<PFNGLVERTEXP2UIPROC>(loader("glVertexP2ui"));
    iglVertexP3uiv             = reinterpret_cast<PFNGLVERTEXP3UIVPROC>(loader("glVertexP3uiv"));
    iglVertexP3ui              = reinterpret_cast<PFNGLVERTEXP3UIPROC>(loader("glVertexP3ui"));
    iglVertexP4uiv             = reinterpret_cast<PFNGLVERTEXP4UIVPROC>(loader("glVertexP4uiv"));
    iglVertexP4ui              = reinterpret_cast<PFNGLVERTEXP4UIPROC>(loader("glVertexP4ui"));
}
} // namespace glr
} // namespace xg



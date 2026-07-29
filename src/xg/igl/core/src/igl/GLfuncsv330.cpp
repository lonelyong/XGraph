#include <xg/igl/ogl/GLfuncsv330.hpp>

namespace xg
{
namespace glr
{


xg::glr::GLfuncsv330::GLfuncsv330()
  : oglBindFragDataLocationIndexed(nullptr)
  , oglBindSampler(nullptr)
  , oglColorP3uiv(nullptr)
  , oglColorP3ui(nullptr)
  , oglColorP4uiv(nullptr)
  , oglColorP4ui(nullptr)
  , oglDeleteSamplers(nullptr)
  , oglGenSamplers(nullptr)
  , oglGetFragDataIndex(nullptr)
  , oglGetQueryObjecti64v(nullptr)
  , oglGetQueryObjectui64v(nullptr)
  , oglGetSamplerParameterIiv(nullptr)
  , oglGetSamplerParameterIuiv(nullptr)
  , oglGetSamplerParameterfv(nullptr)
  , oglGetSamplerParameteriv(nullptr)
  , oglIsSampler(nullptr)
  , oglMultiTexCoordP1uiv(nullptr)
  , oglMultiTexCoordP1ui(nullptr)
  , oglMultiTexCoordP2uiv(nullptr)
  , oglMultiTexCoordP2ui(nullptr)
  , oglMultiTexCoordP3uiv(nullptr)
  , oglMultiTexCoordP3ui(nullptr)
  , oglMultiTexCoordP4uiv(nullptr)
  , oglMultiTexCoordP4ui(nullptr)
  , oglNormalP3uiv(nullptr)
  , oglNormalP3ui(nullptr)
  , oglQueryCounter(nullptr)
  , oglSamplerParameterIiv(nullptr)
  , oglSamplerParameterIuiv(nullptr)
  , oglSamplerParameterfv(nullptr)
  , oglSamplerParameterf(nullptr)
  , oglSamplerParameteriv(nullptr)
  , oglSamplerParameteri(nullptr)
  , oglSecondaryColorP3uiv(nullptr)
  , oglSecondaryColorP3ui(nullptr)
  , oglTexCoordP1uiv(nullptr)
  , oglTexCoordP1ui(nullptr)
  , oglTexCoordP2uiv(nullptr)
  , oglTexCoordP2ui(nullptr)
  , oglTexCoordP3uiv(nullptr)
  , oglTexCoordP3ui(nullptr)
  , oglTexCoordP4uiv(nullptr)
  , oglTexCoordP4ui(nullptr)
  , oglVertexAttribDivisor(nullptr)
  , oglVertexAttribP1uiv(nullptr)
  , oglVertexAttribP1ui(nullptr)
  , oglVertexAttribP2uiv(nullptr)
  , oglVertexAttribP2ui(nullptr)
  , oglVertexAttribP3uiv(nullptr)
  , oglVertexAttribP3ui(nullptr)
  , oglVertexAttribP4uiv(nullptr)
  , oglVertexAttribP4ui(nullptr)
  , oglVertexP2uiv(nullptr)
  , oglVertexP2ui(nullptr)
  , oglVertexP3uiv(nullptr)
  , oglVertexP3ui(nullptr)
  , oglVertexP4uiv(nullptr)
  , oglVertexP4ui(nullptr)
{}

void xg::glr::GLfuncsv330::loadFuncs(Loader loader)
{
    GLfuncsv320::loadFuncs(loader);
    oglBindFragDataLocationIndexed = reinterpret_cast<PFNGLBINDFRAGDATALOCATIONINDEXEDPROC>(loader("glBindFragDataLocationIndexed"));
    oglBindSampler                 = reinterpret_cast<PFNGLBINDSAMPLERPROC>(loader("glBindSampler"));
    oglColorP3uiv                  = reinterpret_cast<PFNGLCOLORP3UIVPROC>(loader("glColorP3uiv"));
    oglColorP3ui                   = reinterpret_cast<PFNGLCOLORP3UIPROC>(loader("glColorP3ui"));
    oglColorP4uiv                  = reinterpret_cast<PFNGLCOLORP4UIVPROC>(loader("glColorP4uiv"));
    oglColorP4ui                   = reinterpret_cast<PFNGLCOLORP4UIPROC>(loader("glColorP4ui"));
    oglDeleteSamplers              = reinterpret_cast<PFNGLDELETESAMPLERSPROC>(loader("glDeleteSamplers"));
    oglGenSamplers                 = reinterpret_cast<PFNGLGENSAMPLERSPROC>(loader("glGenSamplers"));
    oglGetFragDataIndex            = reinterpret_cast<PFNGLGETFRAGDATAINDEXPROC>(loader("glGetFragDataIndex"));
    oglGetQueryObjecti64v          = reinterpret_cast<PFNGLGETQUERYOBJECTI64VPROC>(loader("glGetQueryObjecti64v"));
    oglGetQueryObjectui64v         = reinterpret_cast<PFNGLGETQUERYOBJECTUI64VPROC>(loader("glGetQueryObjectui64v"));
    oglGetSamplerParameterIiv      = reinterpret_cast<PFNGLGETSAMPLERPARAMETERIIVPROC>(loader("glGetSamplerParameterIiv"));
    oglGetSamplerParameterIuiv     = reinterpret_cast<PFNGLGETSAMPLERPARAMETERIUIVPROC>(loader("glGetSamplerParameterIuiv"));
    oglGetSamplerParameterfv       = reinterpret_cast<PFNGLGETSAMPLERPARAMETERFVPROC>(loader("glGetSamplerParameterfv"));
    oglGetSamplerParameteriv       = reinterpret_cast<PFNGLGETSAMPLERPARAMETERIVPROC>(loader("glGetSamplerParameteriv"));
    oglIsSampler                   = reinterpret_cast<PFNGLISSAMPLERPROC>(loader("glIsSampler"));
    oglMultiTexCoordP1uiv          = reinterpret_cast<PFNGLMULTITEXCOORDP1UIVPROC>(loader("glMultiTexCoordP1uiv"));
    oglMultiTexCoordP1ui           = reinterpret_cast<PFNGLMULTITEXCOORDP1UIPROC>(loader("glMultiTexCoordP1ui"));
    oglMultiTexCoordP2uiv          = reinterpret_cast<PFNGLMULTITEXCOORDP2UIVPROC>(loader("glMultiTexCoordP2uiv"));
    oglMultiTexCoordP2ui           = reinterpret_cast<PFNGLMULTITEXCOORDP2UIPROC>(loader("glMultiTexCoordP2ui"));
    oglMultiTexCoordP3uiv          = reinterpret_cast<PFNGLMULTITEXCOORDP3UIVPROC>(loader("glMultiTexCoordP3uiv"));
    oglMultiTexCoordP3ui           = reinterpret_cast<PFNGLMULTITEXCOORDP3UIPROC>(loader("glMultiTexCoordP3ui"));
    oglMultiTexCoordP4uiv          = reinterpret_cast<PFNGLMULTITEXCOORDP4UIVPROC>(loader("glMultiTexCoordP4uiv"));
    oglMultiTexCoordP4ui           = reinterpret_cast<PFNGLMULTITEXCOORDP4UIPROC>(loader("glMultiTexCoordP4ui"));
    oglNormalP3uiv                 = reinterpret_cast<PFNGLNORMALP3UIVPROC>(loader("glNormalP3uiv"));
    oglNormalP3ui                  = reinterpret_cast<PFNGLNORMALP3UIPROC>(loader("glNormalP3ui"));
    oglQueryCounter                = reinterpret_cast<PFNGLQUERYCOUNTERPROC>(loader("glQueryCounter"));
    oglSamplerParameterIiv         = reinterpret_cast<PFNGLSAMPLERPARAMETERIIVPROC>(loader("glSamplerParameterIiv"));
    oglSamplerParameterIuiv        = reinterpret_cast<PFNGLSAMPLERPARAMETERIUIVPROC>(loader("glSamplerParameterIuiv"));
    oglSamplerParameterfv          = reinterpret_cast<PFNGLSAMPLERPARAMETERFVPROC>(loader("glSamplerParameterfv"));
    oglSamplerParameterf           = reinterpret_cast<PFNGLSAMPLERPARAMETERFPROC>(loader("glSamplerParameterf"));
    oglSamplerParameteriv          = reinterpret_cast<PFNGLSAMPLERPARAMETERIVPROC>(loader("glSamplerParameteriv"));
    oglSamplerParameteri           = reinterpret_cast<PFNGLSAMPLERPARAMETERIPROC>(loader("glSamplerParameteri"));
    oglSecondaryColorP3uiv         = reinterpret_cast<PFNGLSECONDARYCOLORP3UIVPROC>(loader("glSecondaryColorP3uiv"));
    oglSecondaryColorP3ui          = reinterpret_cast<PFNGLSECONDARYCOLORP3UIPROC>(loader("glSecondaryColorP3ui"));
    oglTexCoordP1uiv               = reinterpret_cast<PFNGLTEXCOORDP1UIVPROC>(loader("glTexCoordP1uiv"));
    oglTexCoordP1ui                = reinterpret_cast<PFNGLTEXCOORDP1UIPROC>(loader("glTexCoordP1ui"));
    oglTexCoordP2uiv               = reinterpret_cast<PFNGLTEXCOORDP2UIVPROC>(loader("glTexCoordP2uiv"));
    oglTexCoordP2ui                = reinterpret_cast<PFNGLTEXCOORDP2UIPROC>(loader("glTexCoordP2ui"));
    oglTexCoordP3uiv               = reinterpret_cast<PFNGLTEXCOORDP3UIVPROC>(loader("glTexCoordP3uiv"));
    oglTexCoordP3ui                = reinterpret_cast<PFNGLTEXCOORDP3UIPROC>(loader("glTexCoordP3ui"));
    oglTexCoordP4uiv               = reinterpret_cast<PFNGLTEXCOORDP4UIVPROC>(loader("glTexCoordP4uiv"));
    oglTexCoordP4ui                = reinterpret_cast<PFNGLTEXCOORDP4UIPROC>(loader("glTexCoordP4ui"));
    oglVertexAttribDivisor         = reinterpret_cast<PFNGLVERTEXATTRIBDIVISORPROC>(loader("glVertexAttribDivisor"));
    oglVertexAttribP1uiv           = reinterpret_cast<PFNGLVERTEXATTRIBP1UIVPROC>(loader("glVertexAttribP1uiv"));
    oglVertexAttribP1ui            = reinterpret_cast<PFNGLVERTEXATTRIBP1UIPROC>(loader("glVertexAttribP1ui"));
    oglVertexAttribP2uiv           = reinterpret_cast<PFNGLVERTEXATTRIBP2UIVPROC>(loader("glVertexAttribP2uiv"));
    oglVertexAttribP2ui            = reinterpret_cast<PFNGLVERTEXATTRIBP2UIPROC>(loader("glVertexAttribP2ui"));
    oglVertexAttribP3uiv           = reinterpret_cast<PFNGLVERTEXATTRIBP3UIVPROC>(loader("glVertexAttribP3uiv"));
    oglVertexAttribP3ui            = reinterpret_cast<PFNGLVERTEXATTRIBP3UIPROC>(loader("glVertexAttribP3ui"));
    oglVertexAttribP4uiv           = reinterpret_cast<PFNGLVERTEXATTRIBP4UIVPROC>(loader("glVertexAttribP4uiv"));
    oglVertexAttribP4ui            = reinterpret_cast<PFNGLVERTEXATTRIBP4UIPROC>(loader("glVertexAttribP4ui"));
    oglVertexP2uiv                 = reinterpret_cast<PFNGLVERTEXP2UIVPROC>(loader("glVertexP2uiv"));
    oglVertexP2ui                  = reinterpret_cast<PFNGLVERTEXP2UIPROC>(loader("glVertexP2ui"));
    oglVertexP3uiv                 = reinterpret_cast<PFNGLVERTEXP3UIVPROC>(loader("glVertexP3uiv"));
    oglVertexP3ui                  = reinterpret_cast<PFNGLVERTEXP3UIPROC>(loader("glVertexP3ui"));
    oglVertexP4uiv                 = reinterpret_cast<PFNGLVERTEXP4UIVPROC>(loader("glVertexP4uiv"));
    oglVertexP4ui                  = reinterpret_cast<PFNGLVERTEXP4UIPROC>(loader("glVertexP4ui"));
}

} // namespace glr
} // namespace xg

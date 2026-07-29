#include <xg/igl/ogl/GLfuncsv320.hpp>

namespace xg
{
namespace glr
{


xg::glr::GLfuncsv320::GLfuncsv320()
  : oglClientWaitSync(nullptr)
  , oglDeleteSync(nullptr)
  , oglDrawElementsBaseVertex(nullptr)
  , oglDrawElementsInstancedBaseVertex(nullptr)
  , oglDrawRangeElementsBaseVertex(nullptr)
  , oglFenceSync(nullptr)
  , oglFramebufferTexture(nullptr)
  , oglGetBufferParameteri64v(nullptr)
  , oglGetInteger64i_v(nullptr)
  , oglGetInteger64v(nullptr)
  , oglGetMultisamplefv(nullptr)
  , oglGetSynciv(nullptr)
  , oglIsSync(nullptr)
  , oglMultiDrawElementsBaseVertex(nullptr)
  , oglProvokingVertex(nullptr)
  , oglSampleMaski(nullptr)
  , oglTexImage2DMultisample(nullptr)
  , oglTexImage3DMultisample(nullptr)
  , oglWaitSync(nullptr)
{}

void xg::glr::GLfuncsv320::loadFuncs(Loader loader)
{
    GLfuncsv310::loadFuncs(loader);
    oglClientWaitSync                  = reinterpret_cast<PFNGLCLIENTWAITSYNCPROC>(loader("glClientWaitSync"));
    oglDeleteSync                      = reinterpret_cast<PFNGLDELETESYNCPROC>(loader("glDeleteSync"));
    oglDrawElementsBaseVertex          = reinterpret_cast<PFNGLDRAWELEMENTSBASEVERTEXPROC>(loader("glDrawElementsBaseVertex"));
    oglDrawElementsInstancedBaseVertex = reinterpret_cast<PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC>(loader("glDrawElementsInstancedBaseVertex"));
    oglDrawRangeElementsBaseVertex     = reinterpret_cast<PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC>(loader("glDrawRangeElementsBaseVertex"));
    oglFenceSync                       = reinterpret_cast<PFNGLFENCESYNCPROC>(loader("glFenceSync"));
    oglFramebufferTexture              = reinterpret_cast<PFNGLFRAMEBUFFERTEXTUREPROC>(loader("glFramebufferTexture"));
    oglGetBufferParameteri64v          = reinterpret_cast<PFNGLGETBUFFERPARAMETERI64VPROC>(loader("glGetBufferParameteri64v"));
    oglGetInteger64i_v                 = reinterpret_cast<PFNGLGETINTEGER64I_VPROC>(loader("glGetInteger64i_v"));
    oglGetInteger64v                   = reinterpret_cast<PFNGLGETINTEGER64VPROC>(loader("glGetInteger64v"));
    oglGetMultisamplefv                = reinterpret_cast<PFNGLGETMULTISAMPLEFVPROC>(loader("glGetMultisamplefv"));
    oglGetSynciv                       = reinterpret_cast<PFNGLGETSYNCIVPROC>(loader("glGetSynciv"));
    oglIsSync                          = reinterpret_cast<PFNGLISSYNCPROC>(loader("glIsSync"));
    oglMultiDrawElementsBaseVertex     = reinterpret_cast<PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC>(loader("glMultiDrawElementsBaseVertex"));
    oglProvokingVertex                 = reinterpret_cast<PFNGLPROVOKINGVERTEXPROC>(loader("glProvokingVertex"));
    oglSampleMaski                     = reinterpret_cast<PFNGLSAMPLEMASKIPROC>(loader("glSampleMaski"));
    oglTexImage2DMultisample           = reinterpret_cast<PFNGLTEXIMAGE2DMULTISAMPLEPROC>(loader("glTexImage2DMultisample"));
    oglTexImage3DMultisample           = reinterpret_cast<PFNGLTEXIMAGE3DMULTISAMPLEPROC>(loader("glTexImage3DMultisample"));
    oglWaitSync                        = reinterpret_cast<PFNGLWAITSYNCPROC>(loader("glWaitSync"));
}

} // namespace glr
} // namespace xg

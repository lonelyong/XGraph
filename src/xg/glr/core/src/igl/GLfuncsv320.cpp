#include <xg/glr/igl/GLfuncsv320.hpp>

namespace xg {
namespace glr {


xg::glr::GLfuncsv320::GLfuncsv320()
  : iglClientWaitSync(nullptr)
  , iglDeleteSync(nullptr)
  , iglDrawElementsBaseVertex(nullptr)
  , iglDrawElementsInstancedBaseVertex(nullptr)
  , iglDrawRangeElementsBaseVertex(nullptr)
  , iglFenceSync(nullptr)
  , iglFramebufferTexture(nullptr)
  , iglGetBufferParameteri64v(nullptr)
  , iglGetInteger64i_v(nullptr)
  , iglGetInteger64v(nullptr)
  , iglGetMultisamplefv(nullptr)
  , iglGetSynciv(nullptr)
  , iglIsSync(nullptr)
  , iglMultiDrawElementsBaseVertex(nullptr)
  , iglProvokingVertex(nullptr)
  , iglSampleMaski(nullptr)
  , iglTexImage2DMultisample(nullptr)
  , iglTexImage3DMultisample(nullptr)
  , iglWaitSync(nullptr) {
}

void xg::glr::GLfuncsv320::loadFuncs(Loader loader) {
    GLfuncsv310::loadFuncs(loader);
    iglClientWaitSync         = reinterpret_cast<PFNGLCLIENTWAITSYNCPROC>(loader("glClientWaitSync"));
    iglDeleteSync             = reinterpret_cast<PFNGLDELETESYNCPROC>(loader("glDeleteSync"));
    iglDrawElementsBaseVertex = reinterpret_cast<PFNGLDRAWELEMENTSBASEVERTEXPROC>(loader("glDrawElementsBaseVertex"));
    iglDrawElementsInstancedBaseVertex =
        reinterpret_cast<PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC>(loader("glDrawElementsInstancedBaseVertex"));
    iglDrawRangeElementsBaseVertex =
        reinterpret_cast<PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC>(loader("glDrawRangeElementsBaseVertex"));
    iglFenceSync              = reinterpret_cast<PFNGLFENCESYNCPROC>(loader("glFenceSync"));
    iglFramebufferTexture     = reinterpret_cast<PFNGLFRAMEBUFFERTEXTUREPROC>(loader("glFramebufferTexture"));
    iglGetBufferParameteri64v = reinterpret_cast<PFNGLGETBUFFERPARAMETERI64VPROC>(loader("glGetBufferParameteri64v"));
    iglGetInteger64i_v        = reinterpret_cast<PFNGLGETINTEGER64I_VPROC>(loader("glGetInteger64i_v"));
    iglGetInteger64v          = reinterpret_cast<PFNGLGETINTEGER64VPROC>(loader("glGetInteger64v"));
    iglGetMultisamplefv       = reinterpret_cast<PFNGLGETMULTISAMPLEFVPROC>(loader("glGetMultisamplefv"));
    iglGetSynciv              = reinterpret_cast<PFNGLGETSYNCIVPROC>(loader("glGetSynciv"));
    iglIsSync                 = reinterpret_cast<PFNGLISSYNCPROC>(loader("glIsSync"));
    iglMultiDrawElementsBaseVertex =
        reinterpret_cast<PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC>(loader("glMultiDrawElementsBaseVertex"));
    iglProvokingVertex       = reinterpret_cast<PFNGLPROVOKINGVERTEXPROC>(loader("glProvokingVertex"));
    iglSampleMaski           = reinterpret_cast<PFNGLSAMPLEMASKIPROC>(loader("glSampleMaski"));
    iglTexImage2DMultisample = reinterpret_cast<PFNGLTEXIMAGE2DMULTISAMPLEPROC>(loader("glTexImage2DMultisample"));
    iglTexImage3DMultisample = reinterpret_cast<PFNGLTEXIMAGE3DMULTISAMPLEPROC>(loader("glTexImage3DMultisample"));
    iglWaitSync              = reinterpret_cast<PFNGLWAITSYNCPROC>(loader("glWaitSync"));
}
} // namespace glr
} // namespace xg


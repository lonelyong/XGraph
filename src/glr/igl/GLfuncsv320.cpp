#include "GLfuncsv320.h"

namespace glr {

VI_OBJECT_META_IMPL(GLfuncsv320, GLfuncsv310);

glr::GLfuncsv320::GLfuncsv320()
  : glClientWaitSync(nullptr)
  , glDeleteSync(nullptr)
  , glDrawElementsBaseVertex(nullptr)
  , glDrawElementsInstancedBaseVertex(nullptr)
  , glDrawRangeElementsBaseVertex(nullptr)
  , glFenceSync(nullptr)
  , glFramebufferTexture(nullptr)
  , glGetBufferParameteri64v(nullptr)
  , glGetInteger64i_v(nullptr)
  , glGetInteger64v(nullptr)
  , glGetMultisamplefv(nullptr)
  , glGetSynciv(nullptr)
  , glIsSync(nullptr)
  , glMultiDrawElementsBaseVertex(nullptr)
  , glProvokingVertex(nullptr)
  , glSampleMaski(nullptr)
  , glTexImage2DMultisample(nullptr)
  , glTexImage3DMultisample(nullptr)
  , glWaitSync(nullptr) {
}

void glr::GLfuncsv320::loadFuncs(Loader loader) {
    GLfuncsv310::loadFuncs(loader);
    glClientWaitSync         = reinterpret_cast<PFNGLCLIENTWAITSYNCPROC>(loader("glClientWaitSync"));
    glDeleteSync             = reinterpret_cast<PFNGLDELETESYNCPROC>(loader("glDeleteSync"));
    glDrawElementsBaseVertex = reinterpret_cast<PFNGLDRAWELEMENTSBASEVERTEXPROC>(loader("glDrawElementsBaseVertex"));
    glDrawElementsInstancedBaseVertex =
        reinterpret_cast<PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC>(loader("glDrawElementsInstancedBaseVertex"));
    glDrawRangeElementsBaseVertex =
        reinterpret_cast<PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC>(loader("glDrawRangeElementsBaseVertex"));
    glFenceSync              = reinterpret_cast<PFNGLFENCESYNCPROC>(loader("glFenceSync"));
    glFramebufferTexture     = reinterpret_cast<PFNGLFRAMEBUFFERTEXTUREPROC>(loader("glFramebufferTexture"));
    glGetBufferParameteri64v = reinterpret_cast<PFNGLGETBUFFERPARAMETERI64VPROC>(loader("glGetBufferParameteri64v"));
    glGetInteger64i_v        = reinterpret_cast<PFNGLGETINTEGER64I_VPROC>(loader("glGetInteger64i_v"));
    glGetInteger64v          = reinterpret_cast<PFNGLGETINTEGER64VPROC>(loader("glGetInteger64v"));
    glGetMultisamplefv       = reinterpret_cast<PFNGLGETMULTISAMPLEFVPROC>(loader("glGetMultisamplefv"));
    glGetSynciv              = reinterpret_cast<PFNGLGETSYNCIVPROC>(loader("glGetSynciv"));
    glIsSync                 = reinterpret_cast<PFNGLISSYNCPROC>(loader("glIsSync"));
    glMultiDrawElementsBaseVertex =
        reinterpret_cast<PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC>(loader("glMultiDrawElementsBaseVertex"));
    glProvokingVertex       = reinterpret_cast<PFNGLPROVOKINGVERTEXPROC>(loader("glProvokingVertex"));
    glSampleMaski           = reinterpret_cast<PFNGLSAMPLEMASKIPROC>(loader("glSampleMaski"));
    glTexImage2DMultisample = reinterpret_cast<PFNGLTEXIMAGE2DMULTISAMPLEPROC>(loader("glTexImage2DMultisample"));
    glTexImage3DMultisample = reinterpret_cast<PFNGLTEXIMAGE3DMULTISAMPLEPROC>(loader("glTexImage3DMultisample"));
    glWaitSync              = reinterpret_cast<PFNGLWAITSYNCPROC>(loader("glWaitSync"));
}
}


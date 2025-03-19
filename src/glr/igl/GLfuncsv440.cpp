#include "GLfuncsv440.h"

namespace glr {

VI_OBJECT_META_IMPL(GLfuncsv440, GLfuncsv430);


GLfuncsv440::GLfuncsv440()
  : glBindBuffersBase(nullptr)
  , glBindBuffersRange(nullptr)
  , glBindImageTextures(nullptr)
  , glBindSamplers(nullptr)
  , glBindTextures(nullptr)
  , glBindVertexBuffers(nullptr)
  , glBufferStorage(nullptr)
  , glClearTexImage(nullptr)
  , glClearTexSubImage(nullptr) {
}

void GLfuncsv440::loadFuncs(Loader loader) {
    GLfuncsv430::loadFuncs(loader);
    glBindBuffersBase   = reinterpret_cast<PFNGLBINDBUFFERSBASEPROC>(loader("glBindBuffersBase"));
    glBindBuffersRange  = reinterpret_cast<PFNGLBINDBUFFERSRANGEPROC>(loader("glBindBuffersRange"));
    glBindImageTextures = reinterpret_cast<PFNGLBINDIMAGETEXTURESPROC>(loader("glBindImageTextures"));
    glBindSamplers      = reinterpret_cast<PFNGLBINDSAMPLERSPROC>(loader("glBindSamplers"));
    glBindTextures      = reinterpret_cast<PFNGLBINDTEXTURESPROC>(loader("glBindTextures"));
    glBindVertexBuffers = reinterpret_cast<PFNGLBINDVERTEXBUFFERSPROC>(loader("glBindVertexBuffers"));
    glBufferStorage     = reinterpret_cast<PFNGLBUFFERSTORAGEPROC>(loader("glBufferStorage"));
    glClearTexImage     = reinterpret_cast<PFNGLCLEARTEXIMAGEPROC>(loader("glClearTexImage"));
    glClearTexSubImage  = reinterpret_cast<PFNGLCLEARTEXSUBIMAGEPROC>(loader("glClearTexSubImage"));
}



} // namespace glr

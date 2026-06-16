#include <xg/glr/igl/GLfuncsv440.h>

namespace xg {
namespace glr {



GLfuncsv440::GLfuncsv440()
  : iglBindBuffersBase(nullptr)
  , iglBindBuffersRange(nullptr)
  , iglBindImageTextures(nullptr)
  , iglBindSamplers(nullptr)
  , iglBindTextures(nullptr)
  , iglBindVertexBuffers(nullptr)
  , iglBufferStorage(nullptr)
  , iglClearTexImage(nullptr)
  , iglClearTexSubImage(nullptr) {
}

void GLfuncsv440::loadFuncs(Loader loader) {
    GLfuncsv430::loadFuncs(loader);
    iglBindBuffersBase   = reinterpret_cast<PFNGLBINDBUFFERSBASEPROC>(loader("glBindBuffersBase"));
    iglBindBuffersRange  = reinterpret_cast<PFNGLBINDBUFFERSRANGEPROC>(loader("glBindBuffersRange"));
    iglBindImageTextures = reinterpret_cast<PFNGLBINDIMAGETEXTURESPROC>(loader("glBindImageTextures"));
    iglBindSamplers      = reinterpret_cast<PFNGLBINDSAMPLERSPROC>(loader("glBindSamplers"));
    iglBindTextures      = reinterpret_cast<PFNGLBINDTEXTURESPROC>(loader("glBindTextures"));
    iglBindVertexBuffers = reinterpret_cast<PFNGLBINDVERTEXBUFFERSPROC>(loader("glBindVertexBuffers"));
    iglBufferStorage     = reinterpret_cast<PFNGLBUFFERSTORAGEPROC>(loader("glBufferStorage"));
    iglClearTexImage     = reinterpret_cast<PFNGLCLEARTEXIMAGEPROC>(loader("glClearTexImage"));
    iglClearTexSubImage  = reinterpret_cast<PFNGLCLEARTEXSUBIMAGEPROC>(loader("glClearTexSubImage"));
}



} // namespace glr
} // namespace xg

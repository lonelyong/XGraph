#include <xg/igl/ogl/GLfuncsv440.hpp>

namespace xg
{
namespace glr
{



GLfuncsv440::GLfuncsv440()
  : oglBindBuffersBase(nullptr)
  , oglBindBuffersRange(nullptr)
  , oglBindImageTextures(nullptr)
  , oglBindSamplers(nullptr)
  , oglBindTextures(nullptr)
  , oglBindVertexBuffers(nullptr)
  , oglBufferStorage(nullptr)
  , oglClearTexImage(nullptr)
  , oglClearTexSubImage(nullptr)
{}

void GLfuncsv440::loadFuncs(Loader loader)
{
    GLfuncsv430::loadFuncs(loader);
    oglBindBuffersBase   = reinterpret_cast<PFNGLBINDBUFFERSBASEPROC>(loader("glBindBuffersBase"));
    oglBindBuffersRange  = reinterpret_cast<PFNGLBINDBUFFERSRANGEPROC>(loader("glBindBuffersRange"));
    oglBindImageTextures = reinterpret_cast<PFNGLBINDIMAGETEXTURESPROC>(loader("glBindImageTextures"));
    oglBindSamplers      = reinterpret_cast<PFNGLBINDSAMPLERSPROC>(loader("glBindSamplers"));
    oglBindTextures      = reinterpret_cast<PFNGLBINDTEXTURESPROC>(loader("glBindTextures"));
    oglBindVertexBuffers = reinterpret_cast<PFNGLBINDVERTEXBUFFERSPROC>(loader("glBindVertexBuffers"));
    oglBufferStorage     = reinterpret_cast<PFNGLBUFFERSTORAGEPROC>(loader("glBufferStorage"));
    oglClearTexImage     = reinterpret_cast<PFNGLCLEARTEXIMAGEPROC>(loader("glClearTexImage"));
    oglClearTexSubImage  = reinterpret_cast<PFNGLCLEARTEXSUBIMAGEPROC>(loader("glClearTexSubImage"));
}



} // namespace glr
} // namespace xg

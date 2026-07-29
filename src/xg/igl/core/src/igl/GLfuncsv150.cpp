#include <xg/igl/ogl/GLfuncsv150.hpp>

namespace xg
{
namespace glr
{


GLfuncsv150::GLfuncsv150()
  : oglBeginQuery(nullptr)
  , oglBindBuffer(nullptr)
  , oglBufferData(nullptr)
  , oglBufferSubData(nullptr)
  , oglDeleteBuffers(nullptr)
  , oglDeleteQueries(nullptr)
  , oglEndQuery(nullptr)
  , oglGenBuffers(nullptr)
  , oglGenQueries(nullptr)
  , oglGetBufferParameteriv(nullptr)
  , oglGetBufferPointerv(nullptr)
  , oglGetBufferSubData(nullptr)
  , oglGetQueryObjectiv(nullptr)
  , oglGetQueryObjectuiv(nullptr)
  , oglGetQueryiv(nullptr)
  , oglIsBuffer(nullptr)
  , oglIsQuery(nullptr)
  , oglMapBuffer(nullptr)
  , oglUnmapBuffer(nullptr)
{}

void GLfuncsv150::loadFuncs(Loader loader)
{
    GLfuncsv140::loadFuncs(loader);
    oglBeginQuery           = reinterpret_cast<PFNGLBEGINQUERYPROC>(loader("glBeginQuery"));
    oglBindBuffer           = reinterpret_cast<PFNGLBINDBUFFERPROC>(loader("glBindBuffer"));
    oglBufferData           = reinterpret_cast<PFNGLBUFFERDATAPROC>(loader("glBufferData"));
    oglBufferSubData        = reinterpret_cast<PFNGLBUFFERSUBDATAPROC>(loader("glBufferSubData"));
    oglDeleteBuffers        = reinterpret_cast<PFNGLDELETEBUFFERSPROC>(loader("glDeleteBuffers"));
    oglDeleteQueries        = reinterpret_cast<PFNGLDELETEQUERIESPROC>(loader("glDeleteQueries"));
    oglEndQuery             = reinterpret_cast<PFNGLENDQUERYPROC>(loader("glEndQuery"));
    oglGenBuffers           = reinterpret_cast<PFNGLGENBUFFERSPROC>(loader("glGenBuffers"));
    oglGenQueries           = reinterpret_cast<PFNGLGENQUERIESPROC>(loader("glGenQueries"));
    oglGetBufferParameteriv = reinterpret_cast<PFNGLGETBUFFERPARAMETERIVPROC>(loader("glGetBufferParameteriv"));
    oglGetBufferPointerv    = reinterpret_cast<PFNGLGETBUFFERPOINTERVPROC>(loader("glGetBufferPointerv"));
    oglGetBufferSubData     = reinterpret_cast<PFNGLGETBUFFERSUBDATAPROC>(loader("glGetBufferSubData"));
    oglGetQueryObjectiv     = reinterpret_cast<PFNGLGETQUERYOBJECTIVPROC>(loader("glGetQueryObjectiv"));
    oglGetQueryObjectuiv    = reinterpret_cast<PFNGLGETQUERYOBJECTUIVPROC>(loader("glGetQueryObjectuiv"));
    oglGetQueryiv           = reinterpret_cast<PFNGLGETQUERYIVPROC>(loader("glGetQueryiv"));
    oglIsBuffer             = reinterpret_cast<PFNGLISBUFFERPROC>(loader("glIsBuffer"));
    oglIsQuery              = reinterpret_cast<PFNGLISQUERYPROC>(loader("glIsQuery"));
    oglMapBuffer            = reinterpret_cast<PFNGLMAPBUFFERPROC>(loader("glMapBuffer"));
    oglUnmapBuffer          = reinterpret_cast<PFNGLUNMAPBUFFERPROC>(loader("glUnmapBuffer"));
}

} // namespace glr
} // namespace xg

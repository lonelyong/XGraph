#include <glr/igl/GLfuncsv150.h>


namespace glr {


GLfuncsv150::GLfuncsv150()
  : iglBeginQuery(nullptr)
  , iglBindBuffer(nullptr)
  , iglBufferData(nullptr)
  , iglBufferSubData(nullptr)
  , iglDeleteBuffers(nullptr)
  , iglDeleteQueries(nullptr)
  , iglEndQuery(nullptr)
  , iglGenBuffers(nullptr)
  , iglGenQueries(nullptr)
  , iglGetBufferParameteriv(nullptr)
  , iglGetBufferPointerv(nullptr)
  , iglGetBufferSubData(nullptr)
  , iglGetQueryObjectiv(nullptr)
  , iglGetQueryObjectuiv(nullptr)
  , iglGetQueryiv(nullptr)
  , iglIsBuffer(nullptr)
  , iglIsQuery(nullptr)
  , iglMapBuffer(nullptr)
  , iglUnmapBuffer(nullptr) {
}
void GLfuncsv150::loadFuncs(Loader loader) {
    GLfuncsv140::loadFuncs(loader);
    iglBeginQuery           = reinterpret_cast<PFNGLBEGINQUERYPROC>(loader("glBeginQuery"));
    iglBindBuffer           = reinterpret_cast<PFNGLBINDBUFFERPROC>(loader("glBindBuffer"));
    iglBufferData           = reinterpret_cast<PFNGLBUFFERDATAPROC>(loader("glBufferData"));
    iglBufferSubData        = reinterpret_cast<PFNGLBUFFERSUBDATAPROC>(loader("glBufferSubData"));
    iglDeleteBuffers        = reinterpret_cast<PFNGLDELETEBUFFERSPROC>(loader("glDeleteBuffers"));
    iglDeleteQueries        = reinterpret_cast<PFNGLDELETEQUERIESPROC>(loader("glDeleteQueries"));
    iglEndQuery             = reinterpret_cast<PFNGLENDQUERYPROC>(loader("glEndQuery"));
    iglGenBuffers           = reinterpret_cast<PFNGLGENBUFFERSPROC>(loader("glGenBuffers"));
    iglGenQueries           = reinterpret_cast<PFNGLGENQUERIESPROC>(loader("glGenQueries"));
    iglGetBufferParameteriv = reinterpret_cast<PFNGLGETBUFFERPARAMETERIVPROC>(loader("glGetBufferParameteriv"));
    iglGetBufferPointerv    = reinterpret_cast<PFNGLGETBUFFERPOINTERVPROC>(loader("glGetBufferPointerv"));
    iglGetBufferSubData     = reinterpret_cast<PFNGLGETBUFFERSUBDATAPROC>(loader("glGetBufferSubData"));
    iglGetQueryObjectiv     = reinterpret_cast<PFNGLGETQUERYOBJECTIVPROC>(loader("glGetQueryObjectiv"));
    iglGetQueryObjectuiv    = reinterpret_cast<PFNGLGETQUERYOBJECTUIVPROC>(loader("glGetQueryObjectuiv"));
    iglGetQueryiv           = reinterpret_cast<PFNGLGETQUERYIVPROC>(loader("glGetQueryiv"));
    iglIsBuffer             = reinterpret_cast<PFNGLISBUFFERPROC>(loader("glIsBuffer"));
    iglIsQuery              = reinterpret_cast<PFNGLISQUERYPROC>(loader("glIsQuery"));
    iglMapBuffer            = reinterpret_cast<PFNGLMAPBUFFERPROC>(loader("glMapBuffer"));
    iglUnmapBuffer          = reinterpret_cast<PFNGLUNMAPBUFFERPROC>(loader("glUnmapBuffer"));
}
} // namespace glr

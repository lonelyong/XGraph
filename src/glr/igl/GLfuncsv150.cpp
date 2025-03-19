#include <glr/igl/GLfuncsv150.h>


namespace glr {

VI_OBJECT_META_IMPL(GLfuncsv150, GLfuncsv140);

GLfuncsv150::GLfuncsv150()
  : glBeginQuery(nullptr)
  , glBindBuffer(nullptr)
  , glBufferData(nullptr)
  , glBufferSubData(nullptr)
  , glDeleteBuffers(nullptr)
  , glDeleteQueries(nullptr)
  , glEndQuery(nullptr)
  , glGenBuffers(nullptr)
  , glGenQueries(nullptr)
  , glGetBufferParameteriv(nullptr)
  , glGetBufferPointerv(nullptr)
  , glGetBufferSubData(nullptr)
  , glGetQueryObjectiv(nullptr)
  , glGetQueryObjectuiv(nullptr)
  , glGetQueryiv(nullptr)
  , glIsBuffer(nullptr)
  , glIsQuery(nullptr)
  , glMapBuffer(nullptr)
  , glUnmapBuffer(nullptr) {
}
void GLfuncsv150::loadFuncs(Loader loader) {
    GLfuncsv140::loadFuncs(loader);
    glBeginQuery           = reinterpret_cast<PFNGLBEGINQUERYPROC>(loader("glBeginQuery"));
    glBindBuffer           = reinterpret_cast<PFNGLBINDBUFFERPROC>(loader("glBindBuffer"));
    glBufferData           = reinterpret_cast<PFNGLBUFFERDATAPROC>(loader("glBufferData"));
    glBufferSubData        = reinterpret_cast<PFNGLBUFFERSUBDATAPROC>(loader("glBufferSubData"));
    glDeleteBuffers        = reinterpret_cast<PFNGLDELETEBUFFERSPROC>(loader("glDeleteBuffers"));
    glDeleteQueries        = reinterpret_cast<PFNGLDELETEQUERIESPROC>(loader("glDeleteQueries"));
    glEndQuery             = reinterpret_cast<PFNGLENDQUERYPROC>(loader("glEndQuery"));
    glGenBuffers           = reinterpret_cast<PFNGLGENBUFFERSPROC>(loader("glGenBuffers"));
    glGenQueries           = reinterpret_cast<PFNGLGENQUERIESPROC>(loader("glGenQueries"));
    glGetBufferParameteriv = reinterpret_cast<PFNGLGETBUFFERPARAMETERIVPROC>(loader("glGetBufferParameteriv"));
    glGetBufferPointerv    = reinterpret_cast<PFNGLGETBUFFERPOINTERVPROC>(loader("glGetBufferPointerv"));
    glGetBufferSubData     = reinterpret_cast<PFNGLGETBUFFERSUBDATAPROC>(loader("glGetBufferSubData"));
    glGetQueryObjectiv     = reinterpret_cast<PFNGLGETQUERYOBJECTIVPROC>(loader("glGetQueryObjectiv"));
    glGetQueryObjectuiv    = reinterpret_cast<PFNGLGETQUERYOBJECTUIVPROC>(loader("glGetQueryObjectuiv"));
    glGetQueryiv           = reinterpret_cast<PFNGLGETQUERYIVPROC>(loader("glGetQueryiv"));
    glIsBuffer             = reinterpret_cast<PFNGLISBUFFERPROC>(loader("glIsBuffer"));
    glIsQuery              = reinterpret_cast<PFNGLISQUERYPROC>(loader("glIsQuery"));
    glMapBuffer            = reinterpret_cast<PFNGLMAPBUFFERPROC>(loader("glMapBuffer"));
    glUnmapBuffer          = reinterpret_cast<PFNGLUNMAPBUFFERPROC>(loader("glUnmapBuffer"));
}
} // namespace glr

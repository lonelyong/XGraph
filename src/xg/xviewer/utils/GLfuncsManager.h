#pragma once

namespace osg {
class GraphicsContext;
}

namespace glr {
class GLfuncs;
}

namespace xviewer {
class GLfuncsManager {
  private:
    GLfuncsManager() = default;

  public:
    static GLfuncsManager& instance();

  public:
    bool registerByContext(osg::GraphicsContext* ctx);

    glr::GLfuncs* getByContext(osg::GraphicsContext* ctx) const;

    glr::GLfuncs* getOrRegisterByContext(osg::GraphicsContext* ctx);
};
} // namespace  xviewer

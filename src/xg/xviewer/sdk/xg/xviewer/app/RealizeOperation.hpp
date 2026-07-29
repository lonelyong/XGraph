#pragma once

#include <osg/GraphicsThread>

namespace osg
{

class GraphicsContext;

}

namespace xg
{
namespace xviewer
{

/**
 * @brief Graphics operation executed during the realize phase of an OSG
 *        GraphicsContext.
 *
 * In OSG, the realize phase occurs when a GraphicsContext is first created
 * and bound to a window or pixel device. At that point, any attached
 * GraphicsOperation (via GraphicsContext::add() or setRealizeOperation())
 * has its operator() invoked, providing a hook to perform one-time OpenGL
 * initialization such as:
 *   - Setting up default OpenGL state (e.g., glEnable, glClearColor)
 *   - Loading and compiling shaders
 *   - Initializing extensions (GLEW, etc.)
 *   - Configuring swap control or vsync
 *
 * This is guaranteed to run in the graphics thread with a current OpenGL
 * context, making it safe for GL calls.
 */
class RealizeOperation : public osg::GraphicsOperation {
  public:
    /**
     * @brief Constructs a RealizeOperation.
     */
    RealizeOperation();

  public:
    /**
     * @brief Called automatically by OSG when the GraphicsContext is realized.
     *
     * Override this method to inject custom OpenGL initialization logic.
     * The GraphicsContext is guaranteed to be current in the calling thread.
     *
     * @param gc The OSG GraphicsContext being realized.
     */
    virtual void operator()(osg::GraphicsContext* gc) override;
};

} // namespace xviewer
} // namespace xg
#include "GlfwViewer.hpp"

#include <functional>
#include <iostream>
#include <memory>

#include <GLFW/glfw3.h>
#include <vine/Ptr.hpp>

#include <xg/igl/app/Viewer.hpp>
#include <xg/igl/engine/Camera.hpp>
#include <xg/igl/engine/CameraManipulator.hpp>
#include <xg/igl/engine/Event.hpp>
#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/Renderer.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

class GraphicContextGlfwImpl : public GraphicContextGlfw {
  public:
    GraphicContextGlfwImpl(const Traits& traits)
      : wnd_(nullptr)
      , traits_(traits)
      , size_({})
      , cursor_pt_({})
    {}

    virtual ~GraphicContextGlfwImpl()
    {
        if (wnd_) {
            // d->ctx->releaseGLObjects();
            glfwDestroyWindow(wnd_);
        }
    }

  public:
    virtual void makeCurrent() override
    {
        if (!isRealized())
            realize();
        glfwMakeContextCurrent(wnd_);
    }

    virtual void swapBuffers() override
    { glfwSwapBuffers(wnd_); }

    virtual bool realize() override
    {
        if (isRealized())
            return true;
        auto w = traits_.width, h = traits_.height;

        // glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_EGL_CONTEXT_API);
        glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
        auto wnd = glfwCreateWindow(w, h, "GlfwViewer", NULL, NULL);
        if (!wnd) {
            std::cout << "Failed to create a render window using GLFW." << std::endl;
            return false;
        }
        glfwMakeContextCurrent(wnd);

        using GLFWFrameBufferSizeCallback = std::function<void(GLFWwindow*, int, int)>;
        using GLFWKeyCallback             = std::function<void(GLFWwindow * window, int key, int scancode, int action, int mods)>;
        using GLFWMouseButtonCallback     = std::function<void(GLFWwindow*, int, int, int)>;
        using GLFWCursorPosCallback       = std::function<void(GLFWwindow*, double, double)>;
        using GLFWScrollCallback          = std::function<void(GLFWwindow*, double, double)>;
        static GLFWFrameBufferSizeCallback framebuffer_size_callback;
        static GLFWKeyCallback             key_callback;
        static GLFWMouseButtonCallback     mouse_button_callback;
        static GLFWCursorPosCallback       cursor_pos_callback;
        static GLFWScrollCallback          scroll_callback;

        framebuffer_size_callback = [this](GLFWwindow* wnd, int w, int h) { this->framebuffer_size_callback(wnd, w, h); };
        key_callback          = [this](GLFWwindow* wnd, int key, int scancode, int action, int mods) { this->key_callback(wnd, key, scancode, action, mods); };
        mouse_button_callback = [this](GLFWwindow* wnd, int button, int action, int mods) { this->mouse_button_callback(wnd, button, action, mods); };
        cursor_pos_callback   = [this](GLFWwindow* wnd, double x, double y) { this->cursor_position_callback(wnd, x, y); };
        scroll_callback       = [this](GLFWwindow* wnd, double x, double y) { this->scroll_callback(wnd, x, y); };

        glfwSetFramebufferSizeCallback(
            wnd,
            (GLFWframebuffersizefun)[](GLFWwindow * wnd, int w, int h) {
                static auto callback = framebuffer_size_callback;
                callback(wnd, w, h);
            });
        glfwSetKeyCallback(
            wnd,
            (GLFWkeyfun)[](GLFWwindow * wnd, int key, int scancode, int action, int mods) {
                static auto callback = key_callback;
                callback(wnd, key, scancode, action, mods);
            });
        glfwSetMouseButtonCallback(
            wnd,
            (GLFWmousebuttonfun)[](GLFWwindow * wnd, int button, int action, int mods) {
                auto callback = mouse_button_callback;
                callback(wnd, button, action, mods);
            });
        glfwSetCursorPosCallback(
            wnd,
            (GLFWcursorposfun)[](GLFWwindow * wnd, double x, double y) {
                auto callback = cursor_pos_callback;
                callback(wnd, x, y);
            });
        glfwSetScrollCallback(
            wnd,
            (GLFWscrollfun)[](GLFWwindow * wnd, double x, double y) {
                auto callback = scroll_callback;
                callback(wnd, x, y);
            });

        wnd_  = wnd;
        size_ = Vec2f(w, h);
        if (traits_.visible) {
            auto monitor = glfwGetPrimaryMonitor();
            if (monitor) {
                int mx, my, mw, mh;
                glfwGetMonitorWorkarea(monitor, &mx, &my, &mw, &mh);
                glfwSetWindowPos(wnd, (mw - w) * 0.5, (mh - h) * 0.5);
            }
            glfwShowWindow(wnd_);
        }
        return GraphicContext::realize();
    }

    virtual int getWidth() const override
    { return size_.x; }

    virtual int getHeight() const override
    { return size_.y; }

    bool isWindowShouldClose() const
    { return glfwWindowShouldClose(wnd_); }

    void pollEvents()
    { glfwPollEvents(); }

  private:
    void error_callback(int error, const char* desc)
    {}

    void key_callback(GLFWwindow* wnd, int key, int scancode, int action, int mods)
    {
        if (action == GLFW_PRESS) { return; }
        switch (key) {
        case GLFW_KEY_ESCAPE:
        {
            glfwSetWindowShouldClose(wnd, GL_TRUE);
        } break;

        default: break;
        }
    }

    void framebuffer_size_callback(GLFWwindow* wnd, int w, int h)
    {
        size_ = Vec2f(w, h);
        if (w == 0 || h == 0)
            return;
        notify(Event::createWindowResizeEvent(this, w, h));
    }

    void mouse_button_callback(GLFWwindow* wnd, int button, int action, int mods)
    {
        auto btn = BUTTON_LEFT;
        if (button == GLFW_MOUSE_BUTTON_LEFT)
            btn = BUTTON_LEFT;
        else if (button == GLFW_MOUSE_BUTTON_MIDDLE)
            btn = BUTTON_MIDDLE;
        else if (button == GLFW_MOUSE_BUTTON_RIGHT)
            btn = BUTTON_RIGHT;
        if (action == GLFW_PRESS) { notify(Event::createMouseButtonPressEvent(this, btn, cursor_pt_.x, cursor_pt_.y)); }
        else if (action == GLFW_RELEASE) {
            notify(Event::createMouseButtonReleaseEvent(this, btn, cursor_pt_.x, cursor_pt_.y));
        }
    }

    void cursor_position_callback(GLFWwindow* wnd, double x, double y)
    {
        cursor_pt_ = Vec2f(x, y);
        notify(Event::createMouseMoveEvent(this, x, y));
    }

    void scroll_callback(GLFWwindow* wnd, double x, double y)
    { notify(Event::createMouseWheelEvent(this, y * 10)); }

  private:
    Traits      traits_;
    GLFWwindow* wnd_;
    Vec2f       size_;
    Vec2f       cursor_pt_;
};

GraphicContextGlfw* GraphicContextGlfw::create(const Traits& traits)
{ return new GraphicContextGlfwImpl(traits); }

struct GlfwViewer::Data {
    vine::RefPtr<Renderer>               renderer;
    vine::RefPtr<GraphicContextGlfwImpl> ctx;
    bool                                 is_initialized = false;
};

GlfwViewer::GlfwViewer()
  : d(new Data())
{}

GlfwViewer::~GlfwViewer()
{ delete d; }

bool GlfwViewer::initialize()
{
    if (d->is_initialized)
        return true;

    auto renderer = vine::RefPtr(new Renderer());
    auto cam      = renderer->getCamera();
    auto cm       = vine::RefPtr(new StandardCameraManipulator(cam));
    auto ctx      = vine::RefPtr(new GraphicContextGlfwImpl({}));
    ctx->realize();

    if (!ctx->isRealized())
        return false;

    renderer->setContext(ctx.get());
    renderer->setCameraManipulator(cm.get());

    cam->setClearDepth(1.0);
    cam->setClearStencil(1);
    cam->setClearColor(Vec4f(0., 0., 0., 1.));
    cam->setClearMask(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    cm->init(ctx->getWidth(), ctx->getHeight());
    addRenderer(renderer.get());

    auto funcs = ctx->getFuncs();

    funcs->oglPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    funcs->oglEnable(IGL_TEXTURE_2D);
    funcs->oglEnable(IGL_PROGRAM_POINT_SIZE);
    // funcs->oglEnable(GL_CULL_FACE);
    funcs->oglDisable(IGL_CULL_FACE);
    // funcs->oglCullFace(GL_BACK);
    funcs->oglFrontFace(IGL_CCW);
    funcs->oglEnable(IGL_DEPTH_TEST);
    funcs->oglDepthFunc(IGL_LESS);
    funcs->oglDepthRange(0, 1);

    d->renderer       = renderer;
    d->ctx            = ctx;
    d->is_initialized = true;
    return true;
}

bool GlfwViewer::isInitialized() const
{ return d->is_initialized; }

int GlfwViewer::run()
{
    if (!isInitialized()) { initialize(); }
    if (!isInitialized()) { return -1; }

    auto& ctx = *d->ctx.get();
    while (!ctx.isWindowShouldClose()) {
        ctx.pollEvents();
        frame();
        ctx.swapBuffers();
    }
    return 0;
}

} // namespace glr
} // namespace xg
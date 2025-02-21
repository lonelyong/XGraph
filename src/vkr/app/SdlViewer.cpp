#include "SdlViewer.h"

#include <functional>
#include <iostream>
#include <memory>

#include <SDL3/SDL.h>

#include <vine/core/Ptr.h>

#include <vkr/engine/Camera.h>
#include <vkr/engine/CameraManipulator.h>
#include <vkr/engine/Event.h>
#include <vkr/engine/GraphicContext.h>
#include <vkr/engine/Renderer.h>
#include <vkr/viewer/Viewer.h>

namespace vkr {
namespace {
class SdlGraphicContext : public GraphicContext {
  public:
    SdlGraphicContext()
      : sdl_wnd_(nullptr)
      , sdl_ctx_(nullptr)
      , done_(false)
      , size_(800, 600) {}

    virtual ~SdlGraphicContext() {
        if (sdl_wnd_) {
            SDL_GL_DestroyContext(sdl_ctx_);
            SDL_DestroyWindow(sdl_wnd_);
        }
    }

  public:
    virtual void swapBuffers() override { SDL_GL_SwapWindow(sdl_wnd_); }

    virtual bool realize() override {
        if (isRealized()) return true;

        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cout << "SDL init failed." << std::endl;
        }

        SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

        auto* sdl_wnd = SDL_CreateWindow("SdlViewer", size_.x, size_.y, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
        if (sdl_wnd == NULL) {
            std::cout << "Failed to create a window using SDL." << std::endl;
            return false;
        }
        SDL_SetWindowPosition(sdl_wnd, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);


        auto sdl_ctx = SDL_GL_CreateContext(sdl_wnd);
        if (sdl_ctx == NULL) {
            SDL_DestroyWindow(sdl_wnd);
            // SDL_Quit();
            std::cout << "Failed to create a sdl context." << std::endl;
            return false;
        }

        SDL_GL_SetSwapInterval(0);
        SDL_GL_MakeCurrent(sdl_wnd, sdl_ctx);

        SDL_ShowWindow(sdl_wnd);
        SDL_GL_MakeCurrent(sdl_wnd_, sdl_ctx);
        sdl_wnd_ = sdl_wnd;
        sdl_ctx_ = sdl_ctx;
        return GraphicContext::realize();
    }

    virtual int getWidth() const override { return size_.x; }

    virtual int getHeight() const override { return size_.y; }

    void pollEvents() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (done_) break;

            if (event.type == SDL_EVENT_QUIT) {
                done_ = true;
                break;
            }
            if (event.window.windowID != SDL_GetWindowID(sdl_wnd_)) return;

            if (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED) {
                done_ = true;
                break;
            }
            else if (event.window.type == SDL_EVENT_WINDOW_RESIZED) {
                if (event.window.data1 == 0 || event.window.data2 == 0) continue;
                notify(Event::createResizeEvent(this, event.window.data1, event.window.data2));
            }

            if (event.type == SDL_EVENT_MOUSE_MOTION) {
                notify(Event::createMouseMoveEvent(this, event.motion.x, event.motion.y));
            }
            else if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
                auto btn = ButtonNone;
                if (event.button.button == SDL_BUTTON_LEFT)
                    btn = ButtonLeft;
                else if (event.button.button == SDL_BUTTON_MIDDLE)
                    btn = ButtonMiddle;
                else if (event.button.button == SDL_BUTTON_RIGHT)
                    btn = ButtonRight;
                notify(Event::createMousePressEvent(this, btn, event.button.x, event.button.y));
            }
            else if (event.type == SDL_EVENT_MOUSE_BUTTON_UP) {
                auto btn = ButtonNone;
                if (event.button.button == SDL_BUTTON_LEFT)
                    btn = ButtonLeft;
                else if (event.button.button == SDL_BUTTON_MIDDLE)
                    btn = ButtonMiddle;
                else if (event.button.button == SDL_BUTTON_RIGHT)
                    btn = ButtonRight;
                notify(Event::createMouseReleaseEvent(this, btn, event.button.x, event.button.y));
            }
            else if (event.type == SDL_EVENT_MOUSE_WHEEL) {
                notify(Event::createMouseWheelEvent(this, event.wheel.y * 10));
            }
        }
    }

    bool isDone() const { return done_; }

  private:
    SDL_Window*   sdl_wnd_;
    SDL_GLContext sdl_ctx_;
    Vec2i         size_;
    bool          done_;
};
} // namespace

struct SdlViewer::Data {
    vine::RefPtr<Renderer>          renderer;
    vine::RefPtr<SdlGraphicContext> ctx;
    bool                            is_initialized = false;
};

SdlViewer::SdlViewer()
  : d(new Data()) {
}

SdlViewer::~SdlViewer() {
    delete d;
}

bool SdlViewer::initialize() {
    if (d->is_initialized) return true;

    auto renderer = vine::RefPtr(new Renderer());
    auto cam      = renderer->getCamera();
    auto cm       = vine::RefPtr(new StandardCameraManipulator(cam));
    auto ctx      = vine::RefPtr(new SdlGraphicContext());
    ctx->realize();
    if (!ctx->isRealized()) {
        return false;
    }
    renderer->setContext(ctx.get());
    renderer->setCameraManipulator(cm.get());

    cam->setClearDepth(1.0);
    cam->setClearStencil(1);
    cam->setClearColor(Vec4f(0., 0., 0., 1.));
    // cam->setClearMask(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    cm->init(ctx->getWidth(), ctx->getHeight());

    addRenderer(renderer.get());


    d->renderer       = renderer;
    d->ctx            = ctx;
    d->is_initialized = true;
    return true;
}

bool SdlViewer::isInitialized() const {
    return d->is_initialized;
}

int SdlViewer::run() {
    if (!isInitialized()) {
        initialize();
    }
    if (!isInitialized()) {
        return -1;
    }
    auto& ctx = *d->ctx.get();
    while (!ctx.isDone()) {
        ctx.pollEvents();
        frame();
        ctx.swapBuffers();
    }
    return 0;
}
} // namespace vkr
#include <xg/glr/engine/Event.h>

#include <xg/glr/engine/GraphicContext.h>

namespace xg {
namespace glr {
V_OBJECT_META_IMPL(Event, Object);

struct Event::Data {
    GraphicContext* ctx;
    EventType       type;
    MouseButton     mouse_btn   = BUTTON_NONE;
    int             mouse_x     = 0;
    int             mouse_y     = 0;
    int             mouse_delta = 0;
    int             size_width  = 0;
    int             size_height = 0;
};

Event::Event(GraphicContext* ctx, EventType type)
  : d(new Data()) {
    d->ctx  = ctx;
    d->type = type;
}
EventType Event::getType() const {
    return d->type;
}

int Event::getWidth() const {
    return d->size_width;
}

int Event::getHeight() const {
    return d->size_height;
}

int Event::getMouseX() const {
    return d->mouse_x;
}

int Event::getMouseY() const {
    return d->mouse_y;
}

MouseButton Event::getMouseButton() const {
    return d->mouse_btn;
}

int Event::getMouseDelta() const {
    return d->mouse_delta;
}

GraphicContext* Event::getContext() const {
    return d->ctx;
}

Event* Event::createMouseButtonPressEvent(GraphicContext* ctx, MouseButton button, int x, int y) {
    auto e          = new Event(ctx, EVENT_MOUSE_BUTTON_PRESS);
    e->d->mouse_btn = button;
    e->d->mouse_x   = x;
    e->d->mouse_y   = y;
    return e;
}
Event* Event::createMouseMoveEvent(GraphicContext* ctx, int x, int y) {
    auto e        = new Event(ctx, EVENT_MOUSE_MOVE);
    e->d->mouse_x = x;
    e->d->mouse_y = y;
    return e;
}
Event* Event::createMouseButtonReleaseEvent(GraphicContext* ctx, MouseButton button, int x, int y) {
    auto e          = new Event(ctx, EVENT_MOUSE_BUTTON_RELEASE);
    e->d->mouse_btn = button;
    e->d->mouse_x   = x;
    e->d->mouse_y   = y;
    return e;
}
Event* Event::createMouseWheelEvent(GraphicContext* ctx, int delta) {
    auto e            = new Event(ctx, EVENT_MOUSE_WHEEL);
    e->d->mouse_delta = delta;
    return e;
}
Event* Event::createWindowResizeEvent(GraphicContext* ctx, int w, int h) {
    auto e            = new Event(ctx, EVENT_WINDOW_RESIZE);
    e->d->size_width  = w;
    e->d->size_height = h;
    return e;
}

V_OBJECT_META_IMPL(EventHandler, Object);

bool EventHandler::handle(Event* e) {
    return false;
}
} // namespace glr
} // namespace xg
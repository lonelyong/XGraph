#pragma once

#include <xg/glr/glr_global.hpp>

#include <xg/glr/engine/Object.h>

namespace xg {
namespace glr {
class GraphicContext;

enum EventType
{
    EVENT_MOUSE_BUTTON_PRESS,
    EVENT_MOUSE_MOVE,
    EVENT_MOUSE_BUTTON_RELEASE,
    EVENT_MOUSE_WHEEL,
    EVENT_WINDOW_RESIZE
};

enum MouseButton
{
    BUTTON_NONE,
    BUTTON_LEFT = 1,
    BUTTON_MIDDLE,
    BUTTON_RIGHT
};

enum Key
{

};

class GLR_API Event : public Object {
    V_OBJECT_META_DECL

  private:
    Event(GraphicContext* ctx, EventType type);

  public:
    EventType       getType() const;
    int             getWidth() const;
    int             getHeight() const;
    int             getMouseX() const;
    int             getMouseY() const;
    int             getMouseDelta() const;
    MouseButton     getMouseButton() const;
    GraphicContext* getContext() const;

  public:
    static Event* createMouseButtonPressEvent(GraphicContext* ctx, MouseButton button, int x, int y);
    static Event* createMouseMoveEvent(GraphicContext* ctx, int x, int y);
    static Event* createMouseButtonReleaseEvent(GraphicContext* ctx, MouseButton button, int x, int y);
    static Event* createMouseWheelEvent(GraphicContext* ctx, int delta);
    static Event* createWindowResizeEvent(GraphicContext* ctx, int w, int h);

  private:
    struct Data; Data* const d;;
};

class GLR_API EventHandler : public Object {
    V_OBJECT_META_DECL

  public:
    virtual bool handle(Event* e);
};
} // namespace glr
} // namespace xg
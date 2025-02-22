#pragma once

#include <vkr/vkr_global.h>

#include <vkr/engine/Object.h>

namespace vkr {
class GraphicContext;

enum EventType
{
    MousePress,
    MouseMove,
    MouseRelease,
    MouseWheel,
    Resize
};

enum MouseButton
{
    ButtonNone,
    ButtonLeft = 1,
    ButtonMiddle,
    ButtonRight
};

enum Key
{

};

class VKR_API Event : public Object {
    VI_OBJECT_META;

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
    static Event* createMousePressEvent(GraphicContext* ctx, MouseButton button, int x, int y);
    static Event* createMouseMoveEvent(GraphicContext* ctx, int x, int y);
    static Event* createMouseReleaseEvent(GraphicContext* ctx, MouseButton button, int x, int y);
    static Event* createMouseWheelEvent(GraphicContext* ctx, int delta);
    static Event* createResizeEvent(GraphicContext* ctx, int w, int h);

  private:
    VI_OBJECT_DATA;
};

class VKR_API EventHandler : public Object {
    VI_OBJECT_META;

  public:
    virtual bool handle(Event* e);
};
} // namespace vkr
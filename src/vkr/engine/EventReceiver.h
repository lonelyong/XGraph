#pragma once

#include <vkr/vkr_global.h>

#include <vkr/engine/Object.h>

namespace vkr {
class Event;
class EventHandler;
class UpdateCallback;
class UpdateContext;

class VKR_API EventReceiver : public Object {
    VI_OBJECT_META;
    VI_DISABLE_COPY_MOVE(EventReceiver);

  public:
    EventReceiver();
    virtual ~EventReceiver();

  public:
    virtual bool handleEvent(Event* e);
    void         addEventHandler(EventHandler* handler);
    void         removeEventHandler(EventHandler* handler);

    virtual void update(UpdateContext* ctx);
    void         addUpdateCallback(UpdateCallback* callback);
    void         removeUpdateCallback(UpdateCallback* callback);

  private:
    VI_OBJECT_DATA;
};
} // namespace vkr
#pragma once

#include <xg/glr/glr_global.h>

#include <xg/glr/engine/Object.h>

namespace xg {
namespace glr {
class Event;
class EventHandler;
class UpdateCallback;
class UpdateContext;

class GLR_API EventReceiver : public Object {
    V_OBJECT_META_DECL

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
    struct Data; Data* const d;;
};
} // namespace glr
} // namespace xg
#pragma once

#include <xg/igl/glr_global.hpp>

#include <xg/igl/engine/Object.hpp>

namespace xg
{
namespace glr
{

class Event;
class EventHandler;
class UpdateCallback;
class UpdateContext;

class IGL_CORE_API EventReceiver : public Object {
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
    struct Data;
    Data* const d;
};

} // namespace glr
} // namespace xg
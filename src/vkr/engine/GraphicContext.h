#pragma once

#include <vkr/vkr_global.h>

#include <vkr/engine/Event.h>
#include <vkr/engine/Object.h>

namespace vkr {
class State;
class GLVersionInfo;

class VKR_API GraphicContext : public Object {
    VI_OBJECT_META;

    friend class Renderer;

  public:
    class EventQueue : public Object {
      public:
        EventQueue();

      public:
        void   push(Event* e);
        Event* pop();
        void   clear();
        int    size() const;

      private:
        struct Data;
        Data* const d;
    };

  protected:
    GraphicContext();
    virtual ~GraphicContext();

  public:
    int    getId() const;
    State* getState() const;

    virtual int getWidth() const  = 0;
    virtual int getHeight() const = 0;

    virtual bool realize();
    virtual bool isRealized() const;
    virtual void swapBuffers();
    void         notify(Event* e);
    EventQueue*  getEventQueue() const;

  public:
    static GraphicContext* getContextById(int id);

  public:
    struct Data;

  private:
    Data* const d;
};
} // namespace vkr
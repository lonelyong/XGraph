#pragma once

#include <xg/glr/glr_global.hpp>

#include <xg/glr/engine/Event.hpp>
#include <xg/glr/engine/Object.hpp>

namespace xg {
namespace glr
{

class State;
class Capabilities;
class GLfuncs;

class GLR_API GraphicContext : public Object {
    V_OBJECT_META_DECL

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

  public:
    virtual ~GraphicContext();

  public:
    int    getId() const;
    State* getState() const;

    virtual int getWidth() const  = 0;
    virtual int getHeight() const = 0;

    virtual bool realize();
    virtual bool isRealized() const;
    virtual void makeCurrent();
    virtual void swapBuffers();
    void         notify(Event* e);
    EventQueue*  getEventQueue() const;

    GLfuncs* getFuncs() const;

  protected:
    virtual GLfuncs* createGLfuncs();

  public:
    static GraphicContext* getContextById(int id);

  public:
    struct Data;

  private:
    Data* const d;
};

} // namespace glr
} // namespace xg
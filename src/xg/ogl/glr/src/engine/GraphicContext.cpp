#include <xg/glr/engine/GraphicContext.h>

#include <iostream>
#include <queue>

#include <vine/Ptr.hpp>

#include <xgcomm/Text.h>

#include <xg/glr/engine/State.h>
#include <xg/glr/igl/GLfuncs.h>



namespace glr {
V_OBJECT_META_IMPL(GraphicContext, Object);

struct GraphicContext::EventQueue::Data {
    std::queue<vine::RefPtr<Event>> events;
};
static void debugMessageCallback(GLenum_t        source,
                                 GLenum_t        type,
                                 GLuint_t        id,
                                 GLenum_t        severity,
                                 GLsizei_t       length,
                                 const GLchar_t* message,
                                 const void*     userParam) {
    auto ctx = static_cast<const GraphicContext*>(userParam);
    std::cout << message << std::endl;
}

GraphicContext::EventQueue::EventQueue()
  : d(new Data()) {
}

void GraphicContext::EventQueue::push(Event* e) {
    d->events.push(e);
}

Event* GraphicContext::EventQueue::pop() {
    if (d->events.size()) {
        auto e = d->events.front();
        d->events.pop();
        return e.release();
    }
    return nullptr;
}

void GraphicContext::EventQueue::clear() {
    d->events = std::queue<vine::RefPtr<Event>>();
}

int GraphicContext::EventQueue::size() const {
    return static_cast<int>(d->events.size());
}

struct GraphicContext::Data {
    static int               max_id;
    int                      id             = 0;
    bool                     is_initialized = false;
    vine::RefPtr<State>      state;
    vine::RefPtr<EventQueue> events;
    GLfuncs*                 funcs = nullptr;
};

int GraphicContext::Data::max_id = 0;

GraphicContext::GraphicContext()
  : d(new Data()) {
    d->id     = ++Data::max_id;
    d->state  = new State(this);
    d->events = new EventQueue();
}

GraphicContext::~GraphicContext() {
    if (d->funcs) delete d->funcs;
    delete d;
}

int GraphicContext::getId() const {
    return d->id;
}

void GraphicContext::makeCurrent() {
    if (!isRealized()) realize();
}

State* GraphicContext::getState() const {
    return d->state.get();
}

GraphicContext* GraphicContext::getContextById(int id) {
    return nullptr;
}

bool GraphicContext::realize() {
    if (d->is_initialized) return true;

    auto funcs = createGLfuncs();

    funcs->iglEnable(IGL_DEBUG_OUTPUT);
    funcs->iglDebugMessageCallback(debugMessageCallback, this);
    funcs->iglDebugMessageControl(IGL_DONT_CARE, IGL_DONT_CARE, IGL_DONT_CARE, 0, nullptr, IGL_TRUE);

    d->funcs          = funcs;
    d->is_initialized = true;
    return true;
}

bool GraphicContext::isRealized() const {
    return d->is_initialized;
}

void GraphicContext::notify(Event* e) {
    d->events->push(e);
}

void GraphicContext::swapBuffers() {
}

GraphicContext::EventQueue* GraphicContext::getEventQueue() const {
    return d->events.get();
}

GLfuncs* GraphicContext::getFuncs() const {
    return d->funcs;
}
GLfuncs* GraphicContext::createGLfuncs() {
    return GLfuncs::load();
}
} // namespace glr
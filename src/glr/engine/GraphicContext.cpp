#include <glr/engine/GraphicContext.h>

#include <iostream>
#include <queue>

#include <glad/glad.h>

#include <vine/core/Ptr.h>

#include <xgcomm/Text.h>

#include <glr/engine/Capabilities.h>
#include <glr/engine/State.h>
#include <glr/igl/GLfuncs.h>



namespace glr {
VI_OBJECT_META_IMPL(GraphicContext, Object);

struct GraphicContext::EventQueue::Data {
    std::queue<vine::RefPtr<Event>> events;
};
static void debugMessageCallback(GLenum        source,
                                 GLenum        type,
                                 GLuint        id,
                                 GLenum        severity,
                                 GLsizei       length,
                                 const GLchar* message,
                                 const void*   userParam) {
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
    Capabilities             caps;
    vine::RefPtr<GLfuncs>    funcs;
};

int GraphicContext::Data::max_id = 0;

GraphicContext::GraphicContext()
  : d(new Data()) {
    d->id     = ++Data::max_id;
    d->state  = new State(this);
    d->events = new EventQueue();
}

GraphicContext::~GraphicContext() {
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

    d->funcs = GLfuncs::load();

    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(debugMessageCallback, this);
    glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);

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

const Capabilities& GraphicContext::getCapabilities() const {
    return d->caps;
}
GLfuncs* GraphicContext::getFuncs() const {
    return d->funcs.get();
}
} // namespace glr
#pragma once

#include <glr/glr_global.h>

#include <glad/glad.h>

#include <glr/engine/Object.h>

namespace glr {
class State;
class GLR_API GLObject : public Object {
    friend class State;

    VI_OBJECT_META;
    VI_DISABLE_COPY_MOVE(GLObject);

  public:
    GLObject();
    virtual ~GLObject();

  public:
    GLuint getId(State& state) const;
    bool   isCreated(State& state) const;
    void   dirty();
    bool   isDirty(State& state) const;
    GLuint getNbInstances() const;


  protected:
    bool           create(State& state);
    virtual GLuint onCreate(State& state) = 0;
    bool           update(State& state);
    virtual bool   onUpdate(State& state) = 0;
    bool           release(State& state);
    virtual bool   onRelease(State& state) = 0;

  private:
    VI_OBJECT_DATA;
};
} // namespace glr
#pragma once

#include <xg/igl/glr_global.hpp>

#include <xg/igl/ogl/GLdefs.hpp>

#include <xg/igl/engine/Object.hpp>

namespace xg
{
namespace glr
{

class State;

class IGL_CORE_API GLObject : public Object {
    friend class State;

    V_OBJECT_META_DECL

  public:
    GLObject();
    virtual ~GLObject();

  public:
    GLuint_t  getId(State& state) const;
    bool      isCreated(State& state) const;
    void      dirty();
    bool      isDirty(State& state) const;
    GLsizei_t getNumInstances() const;

    bool create(State& state);
    bool update(State& state);
    bool release(State& state);

  protected:
    virtual GLuint_t onCreate(State& state)  = 0;
    virtual bool     onUpdate(State& state)  = 0;
    virtual bool     onRelease(State& state) = 0;

  private:
    struct Data;
    Data* const d;
    ;
};

} // namespace glr
} // namespace xg
#pragma once

#include <glr/glr_global.h>

#include <glr/engine/Object.h>
#include <glr/engine/StateAttribute.h>

namespace glr {
class StateAttribute;
class Program;
class GLR_API StateSet : public Object {
    VI_OBJECT_META;

  public:
    StateSet();
    virtual ~StateSet();

  public:
    void setAttribute(StateAttribute* attr);
    void removeAttribute(StateAttribute* attr);

    StateAttribute* getAttribute(StateAttribute::Type type) const;

    size_t          getNbAttributes() const;
    StateAttribute* getAttributeAt(size_t i);

    Program* getShader() const;

    void setShader(Program* shader);

  private:
    VI_OBJECT_DATA;
};
} // namespace glr
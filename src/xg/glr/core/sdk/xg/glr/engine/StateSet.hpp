#pragma once

#include <xg/glr/glr_global.hpp>

#include <xg/glr/engine/Object.hpp>
#include <xg/glr/engine/StateAttribute.hpp>

namespace xg {
namespace glr {
class StateAttribute;
class Program;
class GLR_API StateSet : public Object {
    V_OBJECT_META_DECL

  public:
    StateSet();
    virtual ~StateSet();

  public:
    void setAttribute(StateAttribute* attr);
    void removeAttribute(StateAttribute* attr);

    StateAttribute* getAttribute(StateAttribute::Type type) const;

    size_t          getNumAttributes() const;
    StateAttribute* getAttributeAt(size_t i);

    Program* getShader() const;

    void setShader(Program* shader);

  private:
    struct Data; Data* const d;;
};
} // namespace glr
} // namespace xg
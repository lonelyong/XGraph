#pragma once

#include <vkr/vkr_global.h>

#include <vkr/engine/Object.h>
#include <vkr/engine/StateAttribute.h>

namespace vkr {
class StateAttribute;
class Shader;
class VKR_API StateSet : public Object {
    VI_OBJECT_META;

  public:
    StateSet();
    virtual ~StateSet();

  public:
    void setAttribute(StateAttribute* attr);

    StateAttribute* getAttribute(StateAttribute::Type type) const;

    size_t          getNbAttributes() const;
    StateAttribute* getAttributeAt(size_t i);

    Shader* getShader() const;

    void setShader(Shader* shader);

  private:
    VI_OBJECT_DATA;
};
} // namespace vkr
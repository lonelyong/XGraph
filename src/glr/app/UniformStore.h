#pragma once

#include <glr/glr_global.h>

#include <string>

#include <glr/engine/Object.h>

namespace glr {
class UniformBase;
class GLR_API UniformStore : public Object {
    VI_OBJECT_META;

    UniformStore();
    UniformStore(const std::string& name);

  public:
    UniformBase* get(const std::string& name) const;

    void set(const std::string& name, UniformBase* uniform);

  private:
    VI_OBJECT_DATA;
};
} // namespace glr

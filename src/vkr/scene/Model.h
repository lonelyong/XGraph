#pragma once

#include <vkr/vkr_global.h>

#include <vkr/scene/Group.h>

namespace vkr {
class Drawable;
class Event;

class VKR_API Model : public Group {
    VI_OBJECT_META;

  public:
    Model();
    virtual ~Model();

  public:
    void addDrawable(Drawable* drawable);
    void removeDrawable(Drawable* drawable);

    int       getNbDrawables() const;
    Drawable* getDrawableAt(int index) const;

  private:
    VI_OBJECT_DATA;
};
} // namespace vkr
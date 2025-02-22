#pragma once

#include <glr/glr_global.h>

#include <glr/scene/Group.h>

namespace glr {
class Drawable;
class Event;

class GLR_API Model : public Group {
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
} // namespace glr
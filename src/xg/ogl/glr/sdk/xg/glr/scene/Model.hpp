#pragma once

#include <xg/glr/glr_global.h>

#include <xg/glr/scene/Group.h>

namespace glr {
class Drawable;
class Event;

class GLR_API Model : public Group {
    V_OBJECT_META_DECL

  public:
    Model();
    virtual ~Model();

  public:
    void addDrawable(Drawable* drawable);
    void removeDrawable(Drawable* drawable);

    int       getNumDrawables() const;
    Drawable* getDrawableAt(int index) const;

  private:
    struct Data; Data* const d;;
};
} // namespace glr
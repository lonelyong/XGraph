#pragma once

#include <xg/igl/glr_global.hpp>

#include <xg/igl/scene/Group.hpp>

namespace xg
{
namespace glr
{

class Drawable;
class Event;

class IGL_CORE_API Model : public Group {
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
    struct Data;
    Data* const d;
    ;
};

} // namespace glr
} // namespace xg
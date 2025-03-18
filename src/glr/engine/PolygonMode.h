#pragma once

#include <glr/engine/StateAttribute.h>

namespace glr {
class GLR_API PolygonMode : public StateAttribute {
    VI_OBJECT_META;

  public:
    enum Mode
    {
        POINT = HGL_POINT,
        LINE  = HGL_LINE,
        FILL  = HGL_FILL
    };

  public:
    PolygonMode();
    PolygonMode(Mode mode);
    virtual ~PolygonMode();

  public:
    virtual Type getType() const override;

    Mode getMode() const;
    void setMode(Mode mode);

  protected:
    virtual void apply(State& state) const override;

  private:
    VI_OBJECT_DATA;
};
} // namespace glr
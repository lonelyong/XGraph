#pragma once

#include <glr/glr_global.h>

#include <glr/engine/StateAttribute.h>
#include <glr/engine/types.h>

namespace glr {
class GLR_API PointParameter : public StateAttribute {
    VI_OBJECT_META;

  public:
    PointParameter();
    PointParameter(int vertices);
    virtual ~PointParameter();

  public:
    virtual Type getType() const override;

    virtual bool equals(const StateAttribute& other) const override;

    void setSize(int vertices);

    int getSize() const;

  protected:
    virtual void apply(State& state) const override;

  private:
    VI_OBJECT_DATA;
};
} // namespace glr
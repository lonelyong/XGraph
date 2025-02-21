#pragma once

#include <vkr/vkrenderer_global.h>

#include <vkr/engine/Object.h>

namespace vkr {
class State;
class VKR_API VKObject : public Object {
    friend class State;

    VI_OBJECT_META;
    VI_DISABLE_COPY_MOVE(VKObject);

  public:
    VKObject();
    virtual ~VKObject();

  public:
    int  getId(State& state) const;
    bool isCreated(State& state) const;
    int  getNbInstances() const;

  protected:
    void         create(State& state);
    virtual int  onCreate(State& state) = 0;
    void         release(State& state);
    virtual void onRelease(State& state) = 0;

  private:
    VI_OBJECT_DATA;
};
} // namespace vkr
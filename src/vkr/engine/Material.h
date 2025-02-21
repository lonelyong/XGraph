#pragma once

#include <vkr/vkrenderer_global.h>

#include <vkr/engine/StateAttribute.h>
#include <vkr/engine/types.h>

namespace vkr {
class VKR_API Material : public StateAttribute {
    VI_OBJECT_META;

  public:
    Material();

  public:
    Vec4f getAmbient() const;
    void  setAmbient(const Vec4f& color);

    Vec4f getDiffuse() const;
    void  setDiffuse(const Vec4f& color);

    Vec4f getSpecular() const;
    void  setSpecular(const Vec4f& color);

    Vec4f getEmission() const;
    void  setEmission(const Vec4f& color);

    float getShininess() const;
    void  setShininess(float shininess);

    Type getType() const;

  protected:
    virtual void apply(State& state) const override;

  private:
    Vec4f a_, d_, s_, e_;
    float sh_;
};
} // namespace vkr
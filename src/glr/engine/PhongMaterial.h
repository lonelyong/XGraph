#pragma once

#include <glr/glr_global.h>

#include <string>

#include <glr/engine/UniformBase.h>
#include <glr/engine/types.h>

namespace glr {
class GLR_API PhongMaterial : public UniformBase {
    VI_OBJECT_META;

  public:
    PhongMaterial();

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

    void                       setName(const std::string& name);
    virtual const std::string& getName() const override;

  protected:
    virtual void apply(State& state) const override;

  private:
    Vec4f a_, d_, s_, e_;
    float sh_;
    // default name: mate
    std::string name_;
};
} // namespace glr
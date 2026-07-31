#pragma once

#include <xg/igl/glr_global.hpp>

#include <string>

#include <xg/igl/engine/UniformBase.hpp>
#include <xg/igl/engine/types.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API PhongMaterial : public UniformBase {
    V_OBJECT_META_DECL

  public:
    PhongMaterial();

  public:
    Vec4f getAmbient() const { return a_; }
    void  setAmbient(const Vec4f& color) { a_ = color; }

    Vec4f getDiffuse() const { return d_; }
    void  setDiffuse(const Vec4f& color) { d_ = color; }

    Vec4f getSpecular() const { return s_; }
    void  setSpecular(const Vec4f& color) { s_ = color; }

    Vec4f getEmission() const { return e_; }
    void  setEmission(const Vec4f& color) { e_ = color; }

    float getShininess() const { return sh_; }
    void  setShininess(float shininess) { sh_ = shininess; }

    Type getType() const override { return PHONG_MATERIAL; }

    void                       setName(const std::string& name) {}
    virtual const std::string& getName() const override { return name_; }

  protected:
    virtual void apply(State& state) const override;

  private:
    Vec4f a_, d_, s_, e_;
    float sh_;
    // default name: mate
    std::string name_;
};

} // namespace glr
} // namespace xg
#pragma once

#include <xg/igl/glr_global.hpp>

#include <string>
#include <vector>

#include <xg/igl/engine/UniformBase.hpp>
#include <xg/igl/engine/types.hpp>

namespace xg
{
namespace glr
{

class GraphicContext;

class IGL_CORE_API PhongLight : public Object {
    V_OBJECT_META_DECL

  public:
    PhongLight();

  public:
    enum Mode
    {
        NO_LIGHT,
        STD_LIGHT,
        HEAD_LIGHT,
        SKY_LIGHT,
    };

  public:
    Vec4f getAmbient() const { return a_; }
    void  setAmbient(const Vec4f& color) { a_ = color; }

    Vec4f getDiffuse() const { return d_; }
    void  setDiffuse(const Vec4f& color) { d_ = color; }

    Vec4f getSpecular() const { return s_; }
    void  setSpecular(const Vec4f& color) { s_ = color; }

    Vec3f getSpotDirection() const { return dir_; }
    void  setSpotDirection(const Vec3f& dir);

    Vec4f getPosition() const { return pos_; }
    void  setPosition(const Vec4f& pos) { pos_ = pos; }

    float getConstantAttenuation() const { return k_c_; }
    void  setConstantAttenuation(float val) { k_c_ = val; }

    float getLinearAttenuation() const { return k_l_; }
    void  setLinearAttenuation(float val) { k_l_ = val; }

    float getQuadraticAttenuation() const { return k_q_; }
    void  settQuadraticAttenuation(float val) { k_q_ = val; }

    float getSpotCutoff() const { return co_; }
    void  setSpotCutoff(float val) { co_ = val; }

    float getSpotExponent() const { return expo_; }
    void  setSpotExponent(float val) { expo_ = val; }

    void setLightMode(Mode mode) { mode_ = mode; }
    Mode getLightMode() const { return mode_; }

  private:
    Vec4f a_, d_, s_;
    Vec4f pos_;
    Vec3f dir_;
    float k_c_, k_l_, k_q_;
    float expo_, co_;
    Mode  mode_;
};

class IGL_CORE_API PhongLights : public UniformBase {
    V_OBJECT_META_DECL
  public:
    PhongLights();

  public:
    void addLight(PhongLight* l);

    void removeLight(PhongLight* l);

    std::vector<PhongLight*> getLights() const { return lights_; }

    virtual Type getType() const override { return PHONG_LIGHTS; }

    void                       setName(const std::string& name) { name_ = name; }
    virtual const std::string& getName() const override { return name_; }

  protected:
    virtual void apply(State& state) const override;

  public:
    static int getMaxLight();

  private:
    std::vector<PhongLight*> lights_;
    // default name: lights
    std::string name_;
};

} // namespace glr
} // namespace xg
#pragma once

#include <xg/glr/glr_global.h>

#include <string>
#include <vector>

#include <xg/glr/engine/UniformBase.h>
#include <xg/glr/engine/types.h>

namespace glr
{

class GraphicContext;

class GLR_API PhongLight : public Object {
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
    Vec4f getAmbient() const;
    void  setAmbient(const Vec4f& color);

    Vec4f getDiffuse() const;
    void  setDiffuse(const Vec4f& color);

    Vec4f getSpecular() const;
    void  setSpecular(const Vec4f& color);

    Vec3f getSpotDirection() const;
    void  setSpotDirection(const Vec3f& dir);

    Vec4f getPosition() const;
    void  setPosition(const Vec4f& pos);

    float getConstantAttenuation() const;
    void  setConstantAttenuation(float val);

    float getLinearAttenuation() const;
    void  setLinearAttenuation(float val);

    float getQuadraticAttenuation() const;
    void  settQuadraticAttenuation(float val);

    float getSpotCutoff() const;
    void  setSpotCutoff(float val);

    float getSpotExponent() const;
    void  setSpotExponent(float val);

    void setLightMode(Mode mode);
    Mode getLightMode() const;

  private:
    Vec4f a_, d_, s_;
    Vec4f pos_;
    Vec3f dir_;
    float k_c_, k_l_, k_q_;
    float expo_, co_;
    Mode  mode_;
};

class GLR_API PhongLights : public UniformBase {
    V_OBJECT_META_DECL
  public:
    PhongLights();

  public:
    void addLight(PhongLight* l);

    void removeLight(PhongLight* l);

    std::vector<PhongLight*> getLights() const;

    virtual Type getType() const override;

    void                       setName(const std::string& name);
    virtual const std::string& getName() const override;

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
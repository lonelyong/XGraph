#pragma once

#include <glr/glrenderer_global.h>

#include <vector>

#include <glr/engine/StateAttribute.h>
#include <glr/engine/types.h>

namespace glr {
class GraphicContext;
class GLR_API Light : public Object {
    VI_OBJECT_META;

  public:
    Light();

  public:
    Vec4f getAmbient() const;
    void  setAmbient(const Vec4f& color);

    Vec4f getDiffuse() const;
    void  setDiffuse(const Vec4f& color);

    Vec4f getSpecular() const;
    void  setSpecular(const Vec4f& color);

    Vec3f getDirection() const;
    void  setDirection(const Vec3f& dir);

    Vec4f getPosition() const;
    void  setPosition(const Vec4f& pos);

    float getConstantAttenuation() const;
    void  setConstantAttenuation(float val);

    float getLinearAttenuation() const;
    void  setLinearAttenuation(float val);

    float getQuadraticAttenuation() const;
    void  settQuadraticAttenuation(float val);

    float getCutoff() const;
    void  setCutoff(float val);

    float getExponent() const;
    void  setExponent(float val);

  private:
    Vec4f a_, d_, s_;
    Vec4f pos_;
    Vec3f dir_;
    float k_c_, k_l_, k_q_;
    float expo_, co_;
    bool  head_ = false;
};

class GLR_API Lights : public StateAttribute {
  public:
    void addLight(Light* l);

    void removeLight(Light* l);

    std::vector<Light*> getLights() const;

    virtual Type getType() const override;

  protected:
    virtual void apply(State& state) const override;

  public:
    static int getMaxLight();

  private:
    std::vector<Light*> lights_;
};
} // namespace glr
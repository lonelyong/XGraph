#include "PhongLight.h"

#include <cmath>
#include <algorithm>

#include <glr/engine/Camera.h>
#include <glr/engine/GraphicContext.h>
#include <glr/engine/Program.h>
#include <glr/engine/State.h>
#include <glr/igl/GLfuncs.h>

namespace glr {
V_OBJECT_META_IMPL(PhongLight, Object);
V_OBJECT_META_IMPL(PhongLights, UniformBase);

PhongLight::PhongLight()
  : a_(Vec4f(0.1f, 0.1f, 0.1f, 1.0f))
  , d_(Vec4f(0.8f, 0.8f, 0.8f, 1.0f))
  , s_(Vec4f(0.1f, 0.1f, 0.1f, 1.0f))
  , pos_(Vec4f(0.f, 0.f, 1.f, 0.0f))
  , dir_(Vec3f(0.f, 0.f, -1.f))
  , k_c_(1.0f)
  , k_l_(0.0f)
  , k_q_(0.0f)
  , expo_(0.f)
  , co_(180)
  , mode_(STD_LIGHT) {
}

Vec4f PhongLight::getAmbient() const {
    return a_;
}
void PhongLight::setAmbient(const Vec4f& color) {
    a_ = color;
}

Vec4f PhongLight::getDiffuse() const {
    return d_;
}
void PhongLight::setDiffuse(const Vec4f& color) {
    d_ = color;
}

Vec4f PhongLight::getSpecular() const {
    return s_;
}
void PhongLight::setSpecular(const Vec4f& color) {
    s_ = color;
}

Vec3f PhongLight::getSpotDirection() const {
    return dir_;
}
void PhongLight::setSpotDirection(const Vec3f& dir) {
    dir_ = glm::normalize(dir);
}

Vec4f PhongLight::getPosition() const {
    return pos_;
}
void PhongLight::setPosition(const Vec4f& pos) {
    pos_ = pos;
}

float PhongLight::getConstantAttenuation() const {
    return k_c_;
}
void PhongLight::setConstantAttenuation(float val) {
    k_c_ = val;
}

float PhongLight::getLinearAttenuation() const {
    return k_l_;
}
void PhongLight::setLinearAttenuation(float val) {
    k_l_ = val;
}

float PhongLight::getQuadraticAttenuation() const {
    return k_q_;
}
void PhongLight::settQuadraticAttenuation(float val) {
    k_q_ = val;
}

float PhongLight::getSpotCutoff() const {
    return co_;
}
void PhongLight::setSpotCutoff(float val) {
    co_ = val;
}

float PhongLight::getSpotExponent() const {
    return expo_;
}
void PhongLight::setSpotExponent(float val) {
    expo_ = val;
}

void PhongLight::setLightMode(Mode mode) {
    mode_ = mode;
}
PhongLight::Mode PhongLight::getLightMode() const {
    return mode_;
}

PhongLights::PhongLights() {
    name_ = "lights";
}

void PhongLights::addLight(PhongLight* l) {
    if (!l) return;
    auto found_at = std::find(lights_.begin(), lights_.end(), l);

    if (found_at != lights_.end()) {
        if (*found_at == l) return;
        lights_.erase(found_at);
    }
    lights_.push_back(l);
}

void PhongLights::removeLight(PhongLight* l) {
    if (!l) return;
    auto found_at = std::find(lights_.begin(), lights_.end(), l);

    if (found_at != lights_.end()) {
        lights_.erase(found_at);
    }
}

std::vector<PhongLight*> PhongLights::getLights() const {
    return lights_;
}

StateAttribute::Type PhongLights::getType() const {
    return PHONG_LIGHTS;
}

void PhongLights::setName(const std::string& name) {
    name_ = name;
}

const std::string& PhongLights::getName() const {
    return name_;
}

void PhongLights::apply(State& state) const {
    auto prog  = state.getCurrentProgram();
    if (prog) {
        auto max_light = getMaxLight();
        for (int i = 0; i < lights_.size(); i++) {
            if (i >= max_light) {
                break;
            }

            auto l    = lights_[i];
            auto mode = l->getLightMode();

            if (mode == PhongLight::NO_LIGHT) continue;

            auto prefix = name_ + "[" + std::to_string(i) + "]";
            prog->set(state, prefix + ".ambient", l->getAmbient());
            prog->set(state, prefix + ".diffuse", l->getDiffuse());
            prog->set(state, prefix + ".specular", l->getSpecular());
            prog->set(state, prefix + ".constantAttenuation", l->getConstantAttenuation());
            prog->set(state, prefix + ".linearAttenuation", l->getLinearAttenuation());
            prog->set(state, prefix + ".quadraticAttenuation", l->getQuadraticAttenuation());
            prog->set(state, prefix + ".spotExponent", l->getSpotExponent());
            prog->set(state, prefix + ".spotCutoff", l->getSpotCutoff());
            prog->set(state, prefix + ".spotCosCutoff", cos(l->getSpotCutoff() * 3.1415926f / 180.f));

            auto dir = l->getSpotDirection();
            auto pos = l->getPosition();
            if (mode == PhongLight::HEAD_LIGHT) {
                auto cam      = state.getCurrentCamera();
                auto view_dir = cam->getViewDir();
                auto view_pos = cam->getViewPos();

                // 平行光
                if (l->getPosition().w == 1.) {
                    pos = Vec4d(view_dir, 1.);
                }
                else {
                    pos = Vec4d(view_pos, 0.);
                    dir = view_dir;
                }
            }
            prog->set(state, prefix + ".spotDirection", dir);
            prog->set(state, prefix + ".position", pos);
        }
        prog->set<int>(state, name_ + "_count", lights_.size() > max_light ? max_light : lights_.size());
    }
}

int PhongLights::getMaxLight() {
    return 8;
}
} // namespace glr
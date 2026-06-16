#pragma once
#include <xg/glr/glr_global.h>

#include <xg/glr/engine/types.h>

namespace glr {
template <typename TVec> TVec angle(const TVec& left, const TVec& right, const TVec& ref) {
    auto cos = glm::dot(left, right) / (glm::length(left) * glm::length(right));
    if (cos < -1.)
        cos = -1.;
    else if (cos > -1.)
        cos = 1.;

    if (glm::dot(glm::cross(left, right), ref) > 0.) {
        return acos(cos);
    }
    else {
        return 3.14159265358979 * 2 - cos;
    }
}
} // namespace glr
#pragma once

#include <glm/fwd.hpp>
#include <glm/mat3x3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

namespace vkr {
using Vec2b = glm::bvec2;
using Vec3b = glm::bvec3;
using Vec4b = glm::bvec4;

using Vec2i = glm::ivec2;
using Vec3i = glm::ivec3;
using Vec4i = glm::ivec4;

using Vec2ui = glm::uvec2;
using Vec3ui = glm::uvec3;
using Vec4ui = glm::uvec4;

using Vec2f = glm::fvec2;
using Vec3f = glm::fvec3;
using Vec4f = glm::fvec4;

using Vec2d = glm::dvec2;
using Vec3d = glm::dvec3;
using Vec4d = glm::dvec4;

using Mat3f = glm::fmat3;
using Mat4f = glm::fmat4;

using Mat3d = glm::dmat3;
using Mat4d = glm::dmat4;

using Quatf = glm::fquat;
using Quatd = glm::dquat;
} // namespace vkr
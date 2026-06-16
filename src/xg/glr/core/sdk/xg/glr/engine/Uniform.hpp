#pragma once
#include <xg/glr/glr_global.hpp>

#include <string>

#include <xg/glr/engine/UniformBase.h>
#include <xg/glr/engine/types.h>

namespace xg {
namespace glr {
class GLR_API Uniform : public UniformBase {
    V_OBJECT_META_DECL

  public:
    enum ValueType
    {
        NO_TYPE = 0,

        BOOL  = IGL_BOOL,      // bool
        BVEC2 = IGL_BOOL_VEC2, // bvec2
        BVEC3 = IGL_BOOL_VEC3, // bvec3
        BVEC4 = IGL_BOOL_VEC4, // bvec4

        INT   = IGL_INT,      // int
        IVEC2 = IGL_INT_VEC2, // ivec2
        IVEC3 = IGL_INT_VEC3, // ivec3
        IVEC4 = IGL_INT_VEC4, // ivec4

        FLOAT   = IGL_FLOAT,      // float
        FVEC2   = IGL_FLOAT_VEC2, // vec2
        FVEC3   = IGL_FLOAT_VEC3, // vec3
        FVEC4   = IGL_FLOAT_VEC4, // vec4
        FMAT3X3 = IGL_FLOAT_MAT3, // mat3
        FMAT4X4 = IGL_FLOAT_MAT4, // mat4

        DOUBLE  = IGL_DOUBLE,      // double
        DVEC2   = IGL_DOUBLE_VEC2, // dvec2
        DVEC3   = IGL_DOUBLE_VEC3, // dvec3
        DVEC4   = IGL_DOUBLE_VEC4, // dvec4
        DMAT3X3 = IGL_DOUBLE_MAT3, // dmat3
        DMAT4X4 = IGL_DOUBLE_MAT4, // dmat4
    };

  public:
    Uniform();
    Uniform(const std::string& name, bool val);
    Uniform(const std::string& name, const Vec2b& val);
    Uniform(const std::string& name, const Vec3b& val);
    Uniform(const std::string& name, const Vec4b& val);

    Uniform(const std::string& name, int val);
    Uniform(const std::string& name, const Vec2i& val);
    Uniform(const std::string& name, const Vec3i& val);
    Uniform(const std::string& name, const Vec4i& val);

    Uniform(const std::string& name, float val);
    Uniform(const std::string& name, const Vec2f& val);
    Uniform(const std::string& name, const Vec3f& val);
    Uniform(const std::string& name, const Vec4f& val);
    Uniform(const std::string& name, const Mat3f& val);
    Uniform(const std::string& name, const Mat4f& val);

    Uniform(const std::string& name, double val);
    Uniform(const std::string& name, const Vec2d& val);
    Uniform(const std::string& name, const Vec3d& val);
    Uniform(const std::string& name, const Vec4d& val);
    Uniform(const std::string& name, const Mat3d& val);
    Uniform(const std::string& name, const Mat4d& val);

    virtual ~Uniform();

  public:
    virtual Type getType() const override;

    ValueType getValueType() const;

    const std::string& getName() const;

    void setValue(bool val);
    void setValue(const Vec2b& val);
    void setValue(const Vec3b& val);
    void setValue(const Vec4b& val);

    void setValue(int val);
    void setValue(const Vec2i& val);
    void setValue(const Vec3i& val);
    void setValue(const Vec4i& val);

    void setValue(float val);
    void setValue(const Vec2f& val);
    void setValue(const Vec3f& val);
    void setValue(const Vec4f& val);
    void setValue(const Mat3f& val);
    void setValue(const Mat4f& val);

    void setValue(double val);
    void setValue(const Vec2d& val);
    void setValue(const Vec3d& val);
    void setValue(const Vec4d& val);
    void setValue(const Mat3d& val);
    void setValue(const Mat4d& val);

    virtual void apply(State& state) const override;

  private:
    struct Data; Data* const d;;
};

} // namespace glr
} // namespace xg
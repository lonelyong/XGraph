#pragma once
#include <xg/igl/glr_global.hpp>

#include <any>
#include <string>

#include <xg/igl/engine/UniformBase.hpp>
#include <xg/igl/engine/types.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API Uniform : public UniformBase {
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
    virtual Type getType() const override { return Type::UNIFORM; }

    ValueType getValueType() const { return type_; }

    const std::string& getName() const override { return name_; }

    void setValue(bool val) { if (type_ == BOOL) { val_ = val; } }
    void setValue(const Vec2b& val) { if (type_ == BVEC2) { val_ = val; } }
    void setValue(const Vec3b& val) { if (type_ == BVEC3) { val_ = val; } }
    void setValue(const Vec4b& val) { if (type_ == BVEC4) { val_ = val; } }

    void setValue(int val) { if (type_ == INT) { val_ = val; } }
    void setValue(const Vec2i& val) { if (type_ == IVEC2) { val_ = val; } }
    void setValue(const Vec3i& val) { if (type_ == IVEC3) { val_ = val; } }
    void setValue(const Vec4i& val) { if (type_ == IVEC4) { val_ = val; } }

    void setValue(float val) { if (type_ == FLOAT) { val_ = val; } }
    void setValue(const Vec2f& val) { if (type_ == FVEC2) { val_ = val; } }
    void setValue(const Vec3f& val) { if (type_ == FVEC3) { val_ = val; } }
    void setValue(const Vec4f& val) { if (type_ == FVEC4) { val_ = val; } }
    void setValue(const Mat3f& val) { if (type_ == FMAT3X3) { val_ = val; } }
    void setValue(const Mat4f& val) { if (type_ == FMAT4X4) { val_ = val; } }

    void setValue(double val) { if (type_ == DOUBLE) { val_ = val; } }
    void setValue(const Vec2d& val) { if (type_ == DVEC2) { val_ = val; } }
    void setValue(const Vec3d& val) { if (type_ == DVEC3) { val_ = val; } }
    void setValue(const Vec4d& val) { if (type_ == DVEC4) { val_ = val; } }
    void setValue(const Mat3d& val) { if (type_ == DMAT3X3) { val_ = val; } }
    void setValue(const Mat4d& val) { if (type_ == DMAT4X4) { val_ = val; } }

    virtual void apply(State& state) const override;

  private:
    std::string name_;
    std::any    val_;
    ValueType   type_ = NO_TYPE;
};

} // namespace glr
} // namespace xg
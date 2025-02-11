#pragma once
#include <glr/glrenderer_global.h>

#include <string>

#include <glad/glad.h>

#include <glr/engine/StateAttribute.h>
#include <glr/engine/types.h>

namespace glr {
class GLR_API Uniform : public StateAttribute {
    VI_OBJECT_META;

  public:
    enum ValueType
    {
        UNDEFINED = 0,

        BOOL  = GL_BOOL,      // bool
        BVEC2 = GL_BOOL_VEC2, // bvec2
        BVEC3 = GL_BOOL_VEC3, // bvec3
        BVEC4 = GL_BOOL_VEC4, // bvec4

        INT   = GL_INT,      // int
        IVEC2 = GL_INT_VEC2, // ivec2
        IVEC3 = GL_INT_VEC3, // ivec3
        IVEC4 = GL_INT_VEC4, // ivec4

        FLOAT   = GL_FLOAT,      // float
        FVEC2   = GL_FLOAT_VEC2, // vec2
        FVEC3   = GL_FLOAT_VEC3, // vec3
        FVEC4   = GL_FLOAT_VEC4, // vec4
        FMAT3X3 = GL_FLOAT_MAT3, // mat3
        FMAT4X4 = GL_FLOAT_MAT4, // mat4

        DOUBLE  = GL_DOUBLE,      // double
        DVEC2   = GL_DOUBLE_VEC2, // dvec2
        DVEC3   = GL_DOUBLE_VEC3, // dvec3
        DVEC4   = GL_DOUBLE_VEC4, // dvec4
        DMAT3X3 = GL_DOUBLE_MAT3, // dmat3
        DMAT4X4 = GL_DOUBLE_MAT4, // dmat4
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
    VI_OBJECT_DATA;
};
} // namespace glr
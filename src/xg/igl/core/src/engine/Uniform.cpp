#include <xg/igl/engine/Uniform.hpp>

#include <any>
#include <string>

#include <xg/igl/engine/Program.hpp>
#include <xg/igl/engine/State.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(Uniform, UniformBase);

Uniform::Uniform() = default;

Uniform::Uniform(const std::string& name, bool val)
  : name_(name)
  , val_(val)
  , type_(BOOL)
{}

Uniform::Uniform(const std::string& name, const Vec2b& val)
  : name_(name)
  , val_(val)
  , type_(BVEC2)
{}

Uniform::Uniform(const std::string& name, const Vec3b& val)
  : name_(name)
  , val_(val)
  , type_(BVEC3)
{}

Uniform::Uniform(const std::string& name, const Vec4b& val)
  : name_(name)
  , val_(val)
  , type_(BVEC4)
{}

Uniform::Uniform(const std::string& name, int val)
  : name_(name)
  , val_(val)
  , type_(INT)
{}

Uniform::Uniform(const std::string& name, const Vec2i& val)
  : name_(name)
  , val_(val)
  , type_(IVEC2)
{}

Uniform::Uniform(const std::string& name, const Vec3i& val)
  : name_(name)
  , val_(val)
  , type_(IVEC3)
{}

Uniform::Uniform(const std::string& name, const Vec4i& val)
  : name_(name)
  , val_(val)
  , type_(IVEC4)
{}

Uniform::Uniform(const std::string& name, float val)
  : name_(name)
  , val_(val)
  , type_(FLOAT)
{}

Uniform::Uniform(const std::string& name, const Vec2f& val)
  : name_(name)
  , val_(val)
  , type_(FVEC2)
{}

Uniform::Uniform(const std::string& name, const Vec3f& val)
  : name_(name)
  , val_(val)
  , type_(FVEC3)
{}

Uniform::Uniform(const std::string& name, const Vec4f& val)
  : name_(name)
  , val_(val)
  , type_(FVEC4)
{}

Uniform::Uniform(const std::string& name, const Mat3f& val)
  : name_(name)
  , val_(val)
  , type_(FMAT3X3)
{}

Uniform::Uniform(const std::string& name, const Mat4f& mat)
  : name_(name)
  , val_(mat)
  , type_(FMAT4X4)
{}

Uniform::Uniform(const std::string& name, double val)
  : name_(name)
  , val_(val)
  , type_(DOUBLE)
{}

Uniform::Uniform(const std::string& name, const Vec2d& val)
  : name_(name)
  , val_(val)
  , type_(DVEC2)
{}

Uniform::Uniform(const std::string& name, const Vec3d& val)
  : name_(name)
  , val_(val)
  , type_(DVEC3)
{}

Uniform::Uniform(const std::string& name, const Vec4d& val)
  : name_(name)
  , val_(val)
  , type_(DVEC4)
{}

Uniform::Uniform(const std::string& name, const Mat3d& val)
  : name_(name)
  , val_(val)
  , type_(DMAT3X3)
{}

Uniform::Uniform(const std::string& name, const Mat4d& mat)
  : name_(name)
  , val_(mat)
  , type_(DMAT4X4)
{}

Uniform::~Uniform() = default;

void Uniform::apply(State& ctx) const
{
    auto shader = ctx.getCurrentProgram();
    if (shader) {
        switch (type_) {
        case BOOL: shader->set(ctx, name_, std::any_cast<bool>(val_)); break;
        case BVEC2: shader->set(ctx, name_, std::any_cast<Vec2b>(val_)); break;
        case BVEC3: shader->set(ctx, name_, std::any_cast<Vec3b>(val_)); break;
        case BVEC4: shader->set(ctx, name_, std::any_cast<Vec4b>(val_)); break;

        case INT: shader->set(ctx, name_, std::any_cast<int>(val_)); break;
        case IVEC2: shader->set(ctx, name_, std::any_cast<Vec2i>(val_)); break;
        case IVEC3: shader->set(ctx, name_, std::any_cast<Vec3i>(val_)); break;
        case IVEC4: shader->set(ctx, name_, std::any_cast<Vec4i>(val_)); break;

        case FLOAT: shader->set(ctx, name_, std::any_cast<float>(val_)); break;
        case FVEC2: shader->set(ctx, name_, std::any_cast<Vec2f>(val_)); break;
        case FVEC3: shader->set(ctx, name_, std::any_cast<Vec3f>(val_)); break;
        case FVEC4: shader->set(ctx, name_, std::any_cast<Vec4f>(val_)); break;
        case FMAT3X3: shader->set(ctx, name_, std::any_cast<Mat3f>(val_)); break;
        case FMAT4X4: shader->set(ctx, name_, std::any_cast<Mat4f>(val_)); break;

        case DOUBLE: shader->set(ctx, name_, std::any_cast<double>(val_)); break;
        case DVEC2: shader->set(ctx, name_, std::any_cast<Vec2d>(val_)); break;
        case DVEC3: shader->set(ctx, name_, std::any_cast<Vec3d>(val_)); break;
        case DVEC4: shader->set(ctx, name_, std::any_cast<Vec4d>(val_)); break;
        case DMAT3X3: shader->set(ctx, name_, std::any_cast<Mat3d>(val_)); break;
        case DMAT4X4: shader->set(ctx, name_, std::any_cast<Mat4d>(val_)); break;
        case NO_TYPE:
        break;
        }
    }
}

} // namespace glr
} // namespace xg
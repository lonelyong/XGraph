#include <vkr/engine/Uniform.h>

#include <any>

#include <vkr/engine/Shader.h>
#include <vkr/engine/State.h>

namespace vkr {
VI_OBJECT_META_IMPL(Uniform, StateAttribute);

struct Uniform::Data {
    std::string name;
    std::any    val;
    ValueType   type;
};

Uniform::Uniform()
  : d(new Data()) {
}

Uniform::Uniform(const std::string& name, bool val)
  : Uniform() {
    d->name = name;
    d->val  = val;
    d->type = BOOL;
}
Uniform::Uniform(const std::string& name, const Vec2b& val)
  : Uniform() {
    d->name = name;
    d->val  = val;
    d->type = BVEC2;
}
Uniform::Uniform(const std::string& name, const Vec3b& val)
  : Uniform() {
    d->name = name;
    d->val  = val;
    d->type = BVEC3;
}
Uniform::Uniform(const std::string& name, const Vec4b& val)
  : Uniform() {
    d->name = name;
    d->val  = val;
    d->type = BVEC4;
}


Uniform::Uniform(const std::string& name, int val)
  : Uniform() {
    d->name = name;
    d->val  = val;
    d->type = INT;
}
Uniform::Uniform(const std::string& name, const Vec2i& val)
  : Uniform() {
    d->name = name;
    d->val  = val;
    d->type = IVEC2;
}
Uniform::Uniform(const std::string& name, const Vec3i& val)
  : Uniform() {
    d->name = name;
    d->val  = val;
    d->type = IVEC3;
}
Uniform::Uniform(const std::string& name, const Vec4i& val)
  : Uniform() {
    d->name = name;
    d->val  = val;
    d->type = IVEC4;
}


Uniform::Uniform(const std::string& name, float val)
  : Uniform() {
    d->name = name;
    d->val  = val;
    d->type = FLOAT;
}
Uniform::Uniform(const std::string& name, const Vec2f& val)
  : Uniform() {
    d->name = name;
    d->val  = val;
    d->type = FVEC2;
}
Uniform::Uniform(const std::string& name, const Vec3f& val)
  : Uniform() {
    d->name = name;
    d->val  = val;
    d->type = FVEC3;
}
Uniform::Uniform(const std::string& name, const Vec4f& val)
  : Uniform() {
    d->name = name;
    d->val  = val;
    d->type = FVEC4;
}
Uniform::Uniform(const std::string& name, const Mat3f& val)
  : Uniform() {
    d->name = name;
    d->val  = val;
    d->type = FMAT3X3;
}
Uniform::Uniform(const std::string& name, const Mat4f& mat)
  : Uniform() {
    d->name = name;
    d->val  = mat;
    d->type = FMAT4X4;
}

Uniform::Uniform(const std::string& name, double val)
  : Uniform() {
    d->name = name;
    d->val  = val;
    d->type = DOUBLE;
}
Uniform::Uniform(const std::string& name, const Vec2d& val)
  : Uniform() {
    d->name = name;
    d->val  = val;
    d->type = DVEC2;
}
Uniform::Uniform(const std::string& name, const Vec3d& val)
  : Uniform() {
    d->name = name;
    d->val  = val;
    d->type = DVEC3;
}
Uniform::Uniform(const std::string& name, const Vec4d& val)
  : Uniform() {
    d->name = name;
    d->val  = val;
    d->type = DVEC4;
}
Uniform::Uniform(const std::string& name, const Mat3d& val)
  : Uniform() {
    d->name = name;
    d->val  = val;
    d->type = DMAT3X3;
}
Uniform::Uniform(const std::string& name, const Mat4d& mat)
  : Uniform() {
    d->name = name;
    d->val  = mat;
    d->type = DMAT4X4;
}

Uniform::~Uniform() {
    delete d;
}

StateAttribute::Type Uniform::getType() const {
    return Type::ATTR_UNIFORM;
}

Uniform::ValueType Uniform::getValueType() const {
    return d->type;
}

void Uniform::setValue(bool val) {
    if (d->type == BOOL) {
        d->val = val;
    }
}
void Uniform::setValue(const Vec2b& val) {
    if (d->type == BVEC2) {
        d->val = val;
    }
}
void Uniform::setValue(const Vec3b& val) {
    if (d->type == BVEC3) {
        d->val = val;
    }
}
void Uniform::setValue(const Vec4b& val) {
    if (d->type == BVEC4) {
        d->val = val;
    }
}

void Uniform::setValue(int val) {
    if (d->type == INT) {
        d->val = val;
    }
}
void Uniform::setValue(const Vec2i& val) {
    if (d->type == IVEC2) {
        d->val = val;
    }
}
void Uniform::setValue(const Vec3i& val) {
    if (d->type == IVEC3) {
        d->val = val;
    }
}
void Uniform::setValue(const Vec4i& val) {
    if (d->type == IVEC4) {
        d->val = val;
    }
}

void Uniform::setValue(float val) {
    if (d->type == FLOAT) {
        d->val = val;
    }
}
void Uniform::setValue(const Vec2f& val) {
    if (d->type == FVEC2) {
        d->val = val;
    }
}
void Uniform::setValue(const Vec3f& val) {
    if (d->type == FVEC3) {
        d->val = val;
    }
}
void Uniform::setValue(const Vec4f& val) {
    if (d->type == FVEC4) {
        d->val = val;
    }
}
void Uniform::setValue(const Mat3f& val) {
    if (d->type == FMAT3X3) {
        d->val = val;
    }
}
void Uniform::setValue(const Mat4f& val) {
    if (d->type == FMAT4X4) {
        d->val = val;
    }
}

void Uniform::setValue(double val) {
    if (d->type == DOUBLE) {
        d->val = val;
    }
}
void Uniform::setValue(const Vec2d& val) {
    if (d->type == DVEC2) {
        d->val = val;
    }
}
void Uniform::setValue(const Vec3d& val) {
    if (d->type == DVEC3) {
        d->val = val;
    }
}
void Uniform::setValue(const Vec4d& val) {
    if (d->type == DVEC4) {
        d->val = val;
    }
}
void Uniform::setValue(const Mat3d& val) {
    if (d->type == DMAT3X3) {
        d->val = val;
    }
}
void Uniform::setValue(const Mat4d& val) {
    if (d->type == DMAT4X4) {
        d->val = val;
    }
}


void Uniform::apply(State& ctx) const {
    auto shader = ctx.getCurrentShader();
    if (shader) {
        switch (d->type) {
        case BOOL: shader->set(ctx, d->name, std::any_cast<bool>(d->val)); break;
        case BVEC2: shader->set(ctx, d->name, std::any_cast<Vec2b>(d->val)); break;
        case BVEC3: shader->set(ctx, d->name, std::any_cast<Vec3b>(d->val)); break;
        case BVEC4: shader->set(ctx, d->name, std::any_cast<Vec4b>(d->val)); break;

        case INT: shader->set(ctx, d->name, std::any_cast<int>(d->val)); break;
        case IVEC2: shader->set(ctx, d->name, std::any_cast<Vec2i>(d->val)); break;
        case IVEC3: shader->set(ctx, d->name, std::any_cast<Vec3i>(d->val)); break;
        case IVEC4: shader->set(ctx, d->name, std::any_cast<Vec4i>(d->val)); break;

        case FLOAT: shader->set(ctx, d->name, std::any_cast<float>(d->val)); break;
        case FVEC2: shader->set(ctx, d->name, std::any_cast<Vec2f>(d->val)); break;
        case FVEC3: shader->set(ctx, d->name, std::any_cast<Vec3f>(d->val)); break;
        case FVEC4: shader->set(ctx, d->name, std::any_cast<Vec4f>(d->val)); break;
        case FMAT3X3: shader->set(ctx, d->name, std::any_cast<Mat3f>(d->val)); break;
        case FMAT4X4: shader->set(ctx, d->name, std::any_cast<Mat4f>(d->val)); break;

        case DOUBLE: shader->set(ctx, d->name, std::any_cast<double>(d->val)); break;
        case DVEC2: shader->set(ctx, d->name, std::any_cast<Vec2d>(d->val)); break;
        case DVEC3: shader->set(ctx, d->name, std::any_cast<Vec3d>(d->val)); break;
        case DVEC4: shader->set(ctx, d->name, std::any_cast<Vec4d>(d->val)); break;
        case DMAT3X3: shader->set(ctx, d->name, std::any_cast<Mat3d>(d->val)); break;
        case DMAT4X4: shader->set(ctx, d->name, std::any_cast<Mat4d>(d->val)); break;
        }
    }
}

} // namespace vkr
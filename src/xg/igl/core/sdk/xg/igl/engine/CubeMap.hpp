#pragma once

#include <xg/igl/glr_global.hpp>

#include <string>
#include <vector>

#include <vine/Ptr.hpp>

#include <xg/igl/engine/Texture.hpp>

namespace xg
{
namespace glr
{

class Image;
class GLfuncs;

class IGL_CORE_API CubeMap : public Texture {
    V_OBJECT_META_DECL

  public:
    CubeMap();
    virtual ~CubeMap();

  public:
    virtual Type getType() const override { return Type::TEXTURE_CUBE_MAP; }

    void setImages(const std::vector<std::string>& imgs);
    void         setImages(const std::vector<Image*>& imgs);

  protected:
    virtual GLuint_t onCreate(State& ctx) override;
    virtual bool     onUpdate(State& ctx) override;

  private:
    void applyParams(GLfuncs* funcs);
    void applyStorage(GLfuncs* funcs);

  private:
    std::vector<vine::RefPtr<Image>> imgs_;
};

} // namespace glr
} // namespace xg
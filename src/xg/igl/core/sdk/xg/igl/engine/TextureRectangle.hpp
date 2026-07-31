#pragma once

#include <xg/igl/glr_global.hpp>

#include <string>

#include <vine/Ptr.hpp>

#include <xg/igl/engine/Texture.hpp>

namespace xg
{
namespace glr
{

class Image;
class GLfuncs;

class IGL_CORE_API TextureRectangle : public Texture {
    V_OBJECT_META_DECL

  public:
    TextureRectangle();
    virtual ~TextureRectangle();

  public:
    virtual Type getType() const override { return Type::TEXTURE_RECTANGLE; }

    void setWidth(GLsizei_t w);
    void setHeight(GLsizei_t h);

    GLsizei_t getWidth() const { return w_; }
    GLsizei_t getHeight() const { return h_; }

    void setImage(const std::string& img);

    void setImage(Image* image);

  protected:
    virtual GLuint_t onCreate(State& state) override;

    virtual bool onUpdate(State& state) override;

  private:
    void applyParams(GLfuncs* funcs);
    void applyStorage(GLfuncs* funcs);

  private:
    GLsizei_t           w_   = 0;
    GLsizei_t           h_   = 0;
    vine::RefPtr<Image> img_;
};

} // namespace glr
} // namespace xg
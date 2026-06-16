#pragma once

#include <xg/glr/glr_global.hpp>

#include <string>

#include <xg/glr/engine/Texture.h>

namespace xg {
namespace glr {

class Image;
class GLfuncs;

class GLR_API Texture2D : public Texture {
    V_OBJECT_META_DECL

  public:
    Texture2D();
    virtual ~Texture2D();

  public:
    virtual Type getType() const override;

    void setWidth(GLsizei_t w);
    void setHeight(GLsizei_t h);

    GLsizei_t getWidth() const;
    GLsizei_t getHeight() const;

    void setImage(const std::string& img);
    void setImage(Image* image);

  protected:
    virtual GLuint_t onCreate(State& state) override;

    virtual bool onUpdate(State& state) override;

  private:
    void applyParams(GLfuncs* funcs);
    void applyStorage(GLfuncs* funcs);

  private:
    struct Data; Data* const d;;
};
} // namespace glr
} // namespace xg
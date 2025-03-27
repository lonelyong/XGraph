#pragma once

#include <glr/glr_global.h>

#include <string>

#include <glr/engine/Texture.h>

namespace glr {

class Image;
class GLfuncs;

class GLR_API TextureRectangle : public Texture {
    VI_OBJECT_META;

  public:
    TextureRectangle();
    virtual ~TextureRectangle();

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
    VI_OBJECT_DATA;
};
} // namespace glr
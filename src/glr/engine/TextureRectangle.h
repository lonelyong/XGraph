#pragma once

#include <glr/glr_global.h>

#include <string>

#include <glr/engine/Texture.h>

namespace glr {
class Image;

class GLR_API TextureRectangle : public Texture {
    VI_OBJECT_META;

  public:
    TextureRectangle();
    virtual ~TextureRectangle();

  public:
    virtual Type getType() const override;

    void setWidth(GLsizei w);

    void setHeight(GLsizei h);

    GLsizei getWidth() const;

    GLsizei getHeight() const;

    void setImage(const std::string& img);

    void setImage(Image* image);

  protected:
    virtual GLuint onCreate(State& state) override;

    virtual bool onUpdate(State& state) override;

  private:
    VI_OBJECT_DATA;
};
} // namespace glr
#pragma once

#include <glr/glr_global.h>

#include <string>
#include <vector>

#include <glr/engine/Texture.h>

namespace glr {

class Image;
class GLfuncs;

class GLR_API CubeMap : public Texture {
    V_OBJECT_META_DECL

  public:
    CubeMap();
    virtual ~CubeMap();

  public:
    virtual Type getType() const override;
    void         setImages(const std::vector<std::string>& imgs);
    void         setImages(const std::vector<Image*>& imgs);

  protected:
    virtual GLuint_t onCreate(State& ctx) override;
    virtual bool     onUpdate(State& ctx) override;

  private:
    void applyParams(GLfuncs* funcs);
    void applyStorage(GLfuncs* funcs);

  private:
    struct Data; Data* const d;;
};
} // namespace glr
#pragma once

#include <xg/igl/glr_global.hpp>

#include <xg/igl/engine/BufferObject.hpp>

namespace xg
{
namespace glr
{

class Image;

class IGL_CORE_API PixelBufferObject : public BufferObject {
    V_OBJECT_META_DECL

    enum Mode
    {
        MODE_PACK,
        MODE_UNPACK,
    };

  public:
    PixelBufferObject(Mode m = MODE_PACK);

  public:
    virtual Target getTarget() const override;
    virtual Usage  getUsage() const override;

    bool setImage(Image* img);

  protected:
    virtual GLuint_t onCreate(State& state) override;
    virtual bool     onUpdate(State& state) override;

  private:
    struct Data;
    Data* const d;
    ;
};

} // namespace glr
} // namespace xg
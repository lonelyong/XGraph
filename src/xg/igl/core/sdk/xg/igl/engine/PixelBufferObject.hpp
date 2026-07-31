#pragma once

#include <xg/igl/glr_global.hpp>

#include <map>

#include <vine/Ptr.hpp>

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
    virtual Usage  getUsage() const override { return STREAM_READ; }

    bool setImage(Image* img);

  protected:
    virtual GLuint_t onCreate(State& state) override;
    virtual bool     onUpdate(State& state) override;

  private:
    std::map<int, bool>    dirties_;
    Mode                   mode_ = MODE_PACK;
    vine::RefPtr<Image>    img_;
};

} // namespace glr
} // namespace xg
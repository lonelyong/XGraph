#include <xg/igl/engine/PixelBufferObject.hpp>

#include <map>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/Image.hpp>
#include <xg/igl/engine/State.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(PixelBufferObject, BufferObject);

PixelBufferObject::PixelBufferObject(Mode m)
  : mode_(m)
{}

BufferObject::Target PixelBufferObject::getTarget() const
{ return mode_ == MODE_PACK ? PIXEL_PACK_BUFFER : PIXEL_UNPACK_BUFFER; }

GLuint_t PixelBufferObject::onCreate(State& state)
{
    auto id = BufferObject::onCreate(state);
    if (id != IGL_ZERO) {
        if (getTarget() == PIXEL_PACK_BUFFER) {}
    }
    return id;
}

bool PixelBufferObject::setImage(Image* img)
{
    if (mode_ == MODE_PACK)
        return false;
    if (img_ == img)
        return true;
    img_ = img;
    return true;
}

bool PixelBufferObject::onUpdate(State& state)
{ return true; }

} // namespace glr
} // namespace xg
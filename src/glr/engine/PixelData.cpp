#include <glr/engine/PixelData.h>

#include <map>

#include <glr/engine/GraphicContext.h>
#include <glr/engine/State.h>

namespace glr {
V_OBJECT_META_IMPL(PixelData, BindableObject);

struct PixelData::Data {
    std::map<int, bool> dirties;
};

PixelData::PixelData()
  : d(new Data()) {
}

PixelData::DataFormat PixelData::computeDataFormat(InternalFormat ifmt) {
    switch (ifmt) {
    case IF_RED:
    case IF_R8:
    case IF_R16:
    case IF_R16F:
    {
        return DF_RED;
    }
    case IF_R8I:
    case IF_R8UI:
    case IF_R16I:
    case IF_R16UI:
    {
        return DF_RED_INTEGER;
    }
    case IF_RG16I:
    case IF_RG16UI:
    {
        return DF_RG_INTEGER;
    }
    case IF_RG:
    case IF_RG8:
    case IF_RG16:
    case IF_RG16F:
    {
        return DF_RG;
    }

    case IF_RGB:
    case IF_RGBA:
    case IF_RGB8:
    case IF_RGB10:
    case IF_RGB12:
    case IF_RGB16:
    case IF_RGB16F:
    case IF_RGB32F:
    case IF_SRGB:
    case IF_SRGB8:
    {
        return DF_RGB;
    }
    case IF_RGB8I:
    case IF_RGB8UI:
    case IF_RGB16I:
    case IF_RGB16UI:
    case IF_RGB32I:
    case IF_RGB32UI:
    {
        return DF_RGB_INTEGER;
    }
    case IF_RGBA8:
    case IF_RGBA12:
    case IF_RGBA16:
    case IF_RGBA16F:
    case IF_RGBA32F:
    {
        return DF_RGBA;
    }

    case IF_RGBA8I:
    case IF_RGBA8UI:
    case IF_RGBA16I:
    case IF_RGBA16UI:
    case IF_RGBA32I:
    case IF_RGBA32UI:
    {
        return DF_RGBA_INTEGER;
    }
    case IF_DEPTH_COMPONENT:
    case IF_DEPTH_COMPONENT16:
    case IF_DEPTH_COMPONENT24:
    case IF_DEPTH_COMPONENT32:
    case IF_DEPTH_COMPONENT32F:
    {
        return DF_DEPTH_COMPONENT;
    }
    case IF_STENCIL_INDEX:
    case IF_STENCIL_INDEX1:
    case IF_STENCIL_INDEX4:
    case IF_STENCIL_INDEX8:
    case IF_STENCIL_INDEX16:
    {
        return DF_STENCIL_INDEX;
    }
    case IF_DEPTH_STENCIL:
    case IF_DEPTH24_STENCIL8:
    case IF_DEPTH32F_STENCIL8:
    {
        return DF_DEPTH_STENCIL;
    }
    default: return DataFormat(ifmt);
    }
}

PixelData::DataType PixelData::computeDataType(InternalFormat ifmt) {
    switch (ifmt) {
    case IF_RED:
    case IF_R8:
    case IF_RG:
    case IF_RG8:
    case IF_RGB:
    case IF_RGB8:
    case IF_RGBA:
    case IF_RGBA8:
    case IF_SRGB8:
    {
        // 内部存储的是整数，shader中读取此种类型的纹理时，会转换为小数
        return DT_UNSIGNED_BYTE;
    }
    case IF_R8I:
    case IF_RGB8I:
    case IF_RGBA8I:
    {
        return DT_BYTE;
    }
    case IF_R8UI:
    case IF_RGB8UI:
    case IF_RGBA8UI:
    {
        return DT_UNSIGNED_BYTE;
    }
    case IF_R16F:
    case IF_RG16F:
    case IF_RGB16F:
    case IF_RGB32F:
    case IF_RGBA16F:
    case IF_RGBA32F:
    {
        return DT_FLOAT;
    }
    case IF_R16I:
    case IF_RG16I:
    case IF_RGB16I:
    case IF_RGBA16I:
    {
        return DT_SHORT;
    }
    case IF_R16UI:
    case IF_RG16UI:
    case IF_RGB16UI:
    case IF_RGBA16UI:
    {
        return DT_UNSIGNED_SHORT;
    }
    case IF_R16:
    case IF_RG16:
    case IF_RGB16:
    case IF_RGBA16:
    {
        return DT_UNSIGNED_SHORT;
    }
    case IF_RGB32I:
    case IF_RGBA32I:
    {
        return DT_INT;
    }
    case IF_RGB32UI:
    case IF_RGBA32UI:
    {
        return DT_UNSIGNED_INT;
    }
    // glReadPixels不接受
    case IF_RGB10:
    case IF_RGB12:
    case IF_RGBA12:
    {
        return DT_UNSIGNED_BYTE;
    }

    case IF_SRGB:
    {
        return DT_UNKNOW;
    }

    case IF_DEPTH_COMPONENT16:
    case IF_DEPTH_COMPONENT24:
    case IF_DEPTH_COMPONENT32:
    case IF_DEPTH_COMPONENT32F:
    {
        return DT_UNSIGNED_INT;
    }
    case IF_STENCIL_INDEX:
    case IF_STENCIL_INDEX1:
    case IF_STENCIL_INDEX4:
    case IF_STENCIL_INDEX8:
    case IF_STENCIL_INDEX16:
    {
        return DT_UNSIGNED_INT;
    }
    case IF_DEPTH_STENCIL:
    case IF_DEPTH24_STENCIL8:
    {
        return DT_UNSIGNED_INT_24_8;
    }
    case IF_DEPTH32F_STENCIL8:
    {
        return DT_FLOAT_32_UNSIGNED_INT_24_8_REV;
    }
    default: return DT_UNKNOW;
    }
}
} // namespace glr
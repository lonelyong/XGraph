#pragma once

#include <glr/glr_global.h>

#include <glr/engine/BindableObject.h>

namespace glr {
class GLR_API PixelData : public BindableObject {
    VI_OBJECT_META;

  public:
    enum InternalFormat
    {
        //
        // 以下常量，不建议作为内部格式使用，因为没有明确指定精度，一般在旧版GL中会有使用
        IF_DEPTH_COMPONENT = HGL_DEPTH_COMPONENT,
        IF_DEPTH_STENCIL   = HGL_DEPTH_STENCIL,
        IF_STENCIL_INDEX   = HGL_STENCIL_INDEX,
        IF_RED             = HGL_RED,
        IF_RG              = HGL_RG,
        IF_RGB             = HGL_RGB,
        IF_RGBA            = HGL_RGBA,
        //

        // 8结尾：内部存储为无符号整数，纹理采样得到的是小数
        IF_R8     = HGL_R8,
        IF_RG8    = HGL_RG8,
        IF_RGB8   = HGL_RGB8,
        IF_RGBA8  = HGL_RGBA8,
        // 16结尾：内部存储为无符号整数，纹理采样得到的是整数
        IF_R16    = HGL_R16,
        IF_RG16   = HGL_RG16,
        IF_RGB16  = HGL_RGB16,
        IF_RGBA16 = HGL_RGBA16,

        // I结尾的内部格式内部存储为整数，纹理采样得到的也是整数
        IF_R8I     = HGL_R8I,
        IF_RGB8I   = HGL_RGB8I,
        IF_RGBA8I  = HGL_RGBA8I,
        IF_R16I    = HGL_R16I,
        IF_RG16I   = HGL_RG16I,
        IF_RGB16I  = HGL_RGB16I,
        IF_RGBA16I = HGL_RGBA16I,
        IF_RGB32I  = HGL_RGB32I,
        IF_RGBA32I = HGL_RGBA32I,

        IF_R8UI     = HGL_R8UI,
        IF_RGB8UI   = HGL_RGB8UI,
        IF_RGBA8UI  = HGL_RGBA8UI,
        IF_R16UI    = HGL_R16UI,
        IF_RG16UI   = HGL_RG16UI,
        IF_RGB16UI  = HGL_RGB16UI,
        IF_RGBA16UI = HGL_RGBA16UI,
        IF_RGB32UI  = HGL_RGB32UI,
        IF_RGBA32UI = HGL_RGBA32UI,


        IF_R16F    = HGL_R16F,
        IF_RG16F   = HGL_RG16F,
        IF_RGB16F  = HGL_RGB16F,
        IF_RGBA16F = HGL_RGBA16F,
        IF_RGB32F  = HGL_RGB32F,
        IF_RGBA32F = HGL_RGBA32F,

        // glReadPixels不接受
        IF_RGB10  = HGL_RGB10,
        IF_RGB12  = HGL_RGB12,
        IF_RGBA12 = HGL_RGBA12,

        // SRGB
        IF_SRGB  = HGL_SRGB,
        IF_SRGB8 = HGL_SRGB8,

        // DEPTH
        IF_DEPTH_COMPONENT16  = HGL_DEPTH_COMPONENT16,
        IF_DEPTH_COMPONENT24  = HGL_DEPTH_COMPONENT24,
        // 内部存储为整数，精度近高远低
        IF_DEPTH_COMPONENT32  = HGL_DEPTH_COMPONENT32,
        // 内部存储为浮点数，精度更高，远近平面精度相对均匀
        IF_DEPTH_COMPONENT32F = HGL_DEPTH_COMPONENT32F,

        // STENCIL
        IF_STENCIL_INDEX1  = HGL_STENCIL_INDEX1,
        IF_STENCIL_INDEX4  = HGL_STENCIL_INDEX4,
        IF_STENCIL_INDEX8  = HGL_STENCIL_INDEX8,
        IF_STENCIL_INDEX16 = HGL_STENCIL_INDEX16,

        // DEPTH_STENCIL
        IF_DEPTH24_STENCIL8  = HGL_DEPTH24_STENCIL8,
        IF_DEPTH32F_STENCIL8 = HGL_DEPTH32F_STENCIL8
    };

    /*
      glReadPixels
      glTexImage2D
      glTexSubImage2D

      某些类型也可以作为内部格式使用，如HGL_RGBA, HGL_RGB
    */
    enum DataFormat
    {
        DF_RED             = HGL_RED,
        DF_GREEN           = HGL_GREEN,
        DF_BLUE            = HGL_BLUE,
        DF_RG              = HGL_RG,
        DF_RGB             = HGL_RGB,
        DF_BGR             = HGL_BGR,
        DF_RGBA            = HGL_RGBA,
        DF_BGRA            = HGL_BGRA,
        DF_DEPTH_COMPONENT = HGL_DEPTH_COMPONENT,
        DF_STENCIL_INDEX   = HGL_STENCIL_INDEX,
        DF_DEPTH_STENCIL   = HGL_DEPTH_STENCIL,

        // 内部格式的类型为以下类型的的内部格式，内部存储的为整数，在着色器中读取这些格式的纹理时，得到的是整数。
        DF_RED_INTEGER   = HGL_RED_INTEGER,
        DF_GREEN_INTEGER = HGL_GREEN_INTEGER,
        DF_BLUE_INTEGER  = HGL_BLUE_INTEGER,
        DF_RG_INTEGER    = HGL_RG_INTEGER,
        DF_RGB_INTEGER   = HGL_RGB_INTEGER,
        DF_BGR_INTEGER   = HGL_BGR_INTEGER,
        DF_RGBA_INTEGER  = HGL_RGBA_INTEGER,
        DF_BGRA_INTEGER  = HGL_BGRA_INTEGER,

        // GL2
        DF_LUMINANCE_ALPHA = HGL_LUMINANCE_ALPHA,
        DF_LUMINANCE       = HGL_LUMINANCE
    };

    enum DataType
    {
        DT_UNKNOW                         = HGL_ZERO,
        DT_UNSIGNED_BYTE                  = HGL_UNSIGNED_BYTE,
        DT_BYTE                           = HGL_BYTE,
        DT_UNSIGNED_SHORT                 = HGL_UNSIGNED_SHORT,
        DT_SHORT                          = HGL_SHORT,
        DT_UNSIGNED_INT                   = HGL_UNSIGNED_INT,
        DT_INT                            = HGL_INT,
        DT_HALF_FLOAT                     = HGL_HALF_FLOAT,
        DT_FLOAT                          = HGL_FLOAT,
        DT_UNSIGNED_BYTE_3_3_2            = HGL_UNSIGNED_BYTE_3_3_2,
        DT_UNSIGNED_BYTE_2_3_3_REV        = HGL_UNSIGNED_BYTE_2_3_3_REV,
        DT_UNSIGNED_SHORT_5_6_5           = HGL_UNSIGNED_SHORT_5_6_5,
        DT_UNSIGNED_SHORT_5_6_5_REV       = HGL_UNSIGNED_SHORT_5_6_5_REV,
        DT_UNSIGNED_SHORT_4_4_4_4         = HGL_UNSIGNED_SHORT_4_4_4_4,
        DT_UNSIGNED_SHORT_4_4_4_4_REV     = HGL_UNSIGNED_SHORT_4_4_4_4_REV,
        DT_UNSIGNED_SHORT_5_5_5_1         = HGL_UNSIGNED_SHORT_5_5_5_1,
        DT_UNSIGNED_SHORT_1_5_5_5_REV     = HGL_UNSIGNED_SHORT_1_5_5_5_REV,
        DT_UNSIGNED_INT_8_8_8_8           = HGL_UNSIGNED_INT_8_8_8_8,
        DT_UNSIGNED_INT_8_8_8_8_REV       = HGL_UNSIGNED_INT_8_8_8_8_REV,
        DT_UNSIGNED_INT_10_10_10_2        = HGL_UNSIGNED_INT_10_10_10_2,
        DT_UNSIGNED_INT_2_10_10_10_REV    = HGL_UNSIGNED_INT_2_10_10_10_REV,
        DT_UNSIGNED_INT_24_8              = HGL_UNSIGNED_INT_24_8,
        DT_UNSIGNED_INT_10F_11F_11F_REV   = HGL_UNSIGNED_INT_10F_11F_11F_REV,
        DT_UNSIGNED_INT_5_9_9_9_REV       = HGL_UNSIGNED_INT_5_9_9_9_REV,
        DT_FLOAT_32_UNSIGNED_INT_24_8_REV = HGL_FLOAT_32_UNSIGNED_INT_24_8_REV
    };

  public:
    PixelData();

    static DataFormat computeDataFormat(InternalFormat ifmt);
    static DataType   computeDataType(InternalFormat ifmt);

  private:
    VI_OBJECT_DATA;
};
} // namespace glr
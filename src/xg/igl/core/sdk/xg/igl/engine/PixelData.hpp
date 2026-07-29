#pragma once

#include <xg/igl/glr_global.hpp>

#include <xg/igl/engine/BindableObject.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API PixelData : public BindableObject {
    V_OBJECT_META_DECL

  public:
    enum InternalFormat
    {
        //
        // 以下常量，不建议作为内部格式使用，因为没有明确指定精度，一般在旧版GL中会有使用
        IF_DEPTH_COMPONENT = IGL_DEPTH_COMPONENT,
        IF_DEPTH_STENCIL   = IGL_DEPTH_STENCIL,
        IF_STENCIL_INDEX   = IGL_STENCIL_INDEX,
        IF_RED             = IGL_RED,
        IF_RG              = IGL_RG,
        IF_RGB             = IGL_RGB,
        IF_RGBA            = IGL_RGBA,
        //

        // 8结尾：内部存储为无符号整数，纹理采样得到的是小数
        IF_R8     = IGL_R8,
        IF_RG8    = IGL_RG8,
        IF_RGB8   = IGL_RGB8,
        IF_RGBA8  = IGL_RGBA8,
        // 16结尾：内部存储为无符号整数，纹理采样得到的是整数
        IF_R16    = IGL_R16,
        IF_RG16   = IGL_RG16,
        IF_RGB16  = IGL_RGB16,
        IF_RGBA16 = IGL_RGBA16,

        // I结尾的内部格式内部存储为整数，纹理采样得到的也是整数
        IF_R8I     = IGL_R8I,
        IF_RGB8I   = IGL_RGB8I,
        IF_RGBA8I  = IGL_RGBA8I,
        IF_R16I    = IGL_R16I,
        IF_RG16I   = IGL_RG16I,
        IF_RGB16I  = IGL_RGB16I,
        IF_RGBA16I = IGL_RGBA16I,
        IF_RGB32I  = IGL_RGB32I,
        IF_RGBA32I = IGL_RGBA32I,

        IF_R8UI     = IGL_R8UI,
        IF_RGB8UI   = IGL_RGB8UI,
        IF_RGBA8UI  = IGL_RGBA8UI,
        IF_R16UI    = IGL_R16UI,
        IF_RG16UI   = IGL_RG16UI,
        IF_RGB16UI  = IGL_RGB16UI,
        IF_RGBA16UI = IGL_RGBA16UI,
        IF_RGB32UI  = IGL_RGB32UI,
        IF_RGBA32UI = IGL_RGBA32UI,


        IF_R16F    = IGL_R16F,
        IF_RG16F   = IGL_RG16F,
        IF_RGB16F  = IGL_RGB16F,
        IF_RGBA16F = IGL_RGBA16F,
        IF_RGB32F  = IGL_RGB32F,
        IF_RGBA32F = IGL_RGBA32F,

        // glReadPixels不接受
        IF_RGB10  = IGL_RGB10,
        IF_RGB12  = IGL_RGB12,
        IF_RGBA12 = IGL_RGBA12,

        // SRGB
        IF_SRGB  = IGL_SRGB,
        IF_SRGB8 = IGL_SRGB8,

        // DEPTH
        IF_DEPTH_COMPONENT16  = IGL_DEPTH_COMPONENT16,
        IF_DEPTH_COMPONENT24  = IGL_DEPTH_COMPONENT24,
        // 内部存储为整数，精度近高远低
        IF_DEPTH_COMPONENT32  = IGL_DEPTH_COMPONENT32,
        // 内部存储为浮点数，精度更高，远近平面精度相对均匀
        IF_DEPTH_COMPONENT32F = IGL_DEPTH_COMPONENT32F,

        // STENCIL
        IF_STENCIL_INDEX1  = IGL_STENCIL_INDEX1,
        IF_STENCIL_INDEX4  = IGL_STENCIL_INDEX4,
        IF_STENCIL_INDEX8  = IGL_STENCIL_INDEX8,
        IF_STENCIL_INDEX16 = IGL_STENCIL_INDEX16,

        // DEPTH_STENCIL
        IF_DEPTH24_STENCIL8  = IGL_DEPTH24_STENCIL8,
        IF_DEPTH32F_STENCIL8 = IGL_DEPTH32F_STENCIL8
    };

    /*
      funcs->oglReadPixels
      funcs->oglTexImage2D
      funcs->oglTexSubImage2D

      某些类型也可以作为内部格式使用，如IGL_RGBA, IGL_RGB
    */
    enum DataFormat
    {
        DF_RED             = IGL_RED,
        DF_GREEN           = IGL_GREEN,
        DF_BLUE            = IGL_BLUE,
        DF_RG              = IGL_RG,
        DF_RGB             = IGL_RGB,
        DF_BGR             = IGL_BGR,
        DF_RGBA            = IGL_RGBA,
        DF_BGRA            = IGL_BGRA,
        DF_DEPTH_COMPONENT = IGL_DEPTH_COMPONENT,
        DF_STENCIL_INDEX   = IGL_STENCIL_INDEX,
        DF_DEPTH_STENCIL   = IGL_DEPTH_STENCIL,

        // 内部格式的类型为以下类型的的内部格式，内部存储的为整数，在着色器中读取这些格式的纹理时，得到的是整数。
        DF_RED_INTEGER   = IGL_RED_INTEGER,
        DF_GREEN_INTEGER = IGL_GREEN_INTEGER,
        DF_BLUE_INTEGER  = IGL_BLUE_INTEGER,
        DF_RG_INTEGER    = IGL_RG_INTEGER,
        DF_RGB_INTEGER   = IGL_RGB_INTEGER,
        DF_BGR_INTEGER   = IGL_BGR_INTEGER,
        DF_RGBA_INTEGER  = IGL_RGBA_INTEGER,
        DF_BGRA_INTEGER  = IGL_BGRA_INTEGER,

        // GL2
        DF_LUMINANCE_ALPHA = IGL_LUMINANCE_ALPHA,
        DF_LUMINANCE       = IGL_LUMINANCE
    };

    // 像素颜色通道的数据类型
    enum DataType
    {
        DT_UNKNOW                         = IGL_ZERO,
        DT_UNSIGNED_BYTE                  = IGL_UNSIGNED_BYTE,
        DT_BYTE                           = IGL_BYTE,
        DT_UNSIGNED_SHORT                 = IGL_UNSIGNED_SHORT,
        DT_SHORT                          = IGL_SHORT,
        DT_UNSIGNED_INT                   = IGL_UNSIGNED_INT,
        DT_INT                            = IGL_INT,
        DT_HALF_FLOAT                     = IGL_HALF_FLOAT,
        DT_FLOAT                          = IGL_FLOAT,
        DT_UNSIGNED_BYTE_3_3_2            = IGL_UNSIGNED_BYTE_3_3_2,
        DT_UNSIGNED_BYTE_2_3_3_REV        = IGL_UNSIGNED_BYTE_2_3_3_REV,
        DT_UNSIGNED_SHORT_5_6_5           = IGL_UNSIGNED_SHORT_5_6_5,
        DT_UNSIGNED_SHORT_5_6_5_REV       = IGL_UNSIGNED_SHORT_5_6_5_REV,
        DT_UNSIGNED_SHORT_4_4_4_4         = IGL_UNSIGNED_SHORT_4_4_4_4,
        DT_UNSIGNED_SHORT_4_4_4_4_REV     = IGL_UNSIGNED_SHORT_4_4_4_4_REV,
        DT_UNSIGNED_SHORT_5_5_5_1         = IGL_UNSIGNED_SHORT_5_5_5_1,
        DT_UNSIGNED_SHORT_1_5_5_5_REV     = IGL_UNSIGNED_SHORT_1_5_5_5_REV,
        DT_UNSIGNED_INT_8_8_8_8           = IGL_UNSIGNED_INT_8_8_8_8,
        DT_UNSIGNED_INT_8_8_8_8_REV       = IGL_UNSIGNED_INT_8_8_8_8_REV,
        DT_UNSIGNED_INT_10_10_10_2        = IGL_UNSIGNED_INT_10_10_10_2,
        DT_UNSIGNED_INT_2_10_10_10_REV    = IGL_UNSIGNED_INT_2_10_10_10_REV,
        DT_UNSIGNED_INT_24_8              = IGL_UNSIGNED_INT_24_8,
        DT_UNSIGNED_INT_10F_11F_11F_REV   = IGL_UNSIGNED_INT_10F_11F_11F_REV,
        DT_UNSIGNED_INT_5_9_9_9_REV       = IGL_UNSIGNED_INT_5_9_9_9_REV,
        DT_FLOAT_32_UNSIGNED_INT_24_8_REV = IGL_FLOAT_32_UNSIGNED_INT_24_8_REV
    };

  public:
    PixelData();

    static DataFormat computeDataFormat(InternalFormat ifmt);
    static DataType   computeDataType(InternalFormat ifmt);

  private:
    struct Data;
    Data* const d;
    ;
};

} // namespace glr
} // namespace xg
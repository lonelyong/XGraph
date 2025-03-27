#pragma once

#include <glr/glr_global.h>

#include <glr/engine/Object.h>

namespace glr {
class State;
class GLR_API Image : public Object {
    VI_OBJECT_META;
    VI_DISABLE_COPY_MOVE(Image);

  public:
    enum Format
    {
        Unknown,
        R8,
        G8,
        B8,
        RGB888,
        RGBA8888,
    };

  public:
    Image();

  public:
    void setImage(int w, int h, Format format, const unsigned char* data);

    void setImage(int w, int h, Format format, const unsigned char* data, int stride, int offset);

    int getInternalTextureFormat() const;

    int getDataFormat() const;

    int getDataType() const;

    Format getFormat() const;

    int getWidth() const;

    int getHeight() const;

    int getChannels() const;

    int size() const;
    /**
     * @brief
     * @return
     */
    unsigned char* data() const;

    bool isNull() const;

    /**
     * - fmt GL_STENCIL_INDEX, GL_DEPTH_COMPONENT, GL_DEPTH_STENCIL, GL_RED, GL_GREEN, GL_BLUE, GL_RGB, GL_BGR, GL_RGBA, GL_BGRA.
     * - type GL_UNSIGNED_BYTE, GL_BYTE, GL_UNSIGNED_SHORT, GL_SHORT, GL_UNSIGNED_INT, GL_INT,...
     *
     * GL_RED	            GL_UNSIGNED_BYTE	每个颜色通道使用 8 位无符号整数表示（0-255，读取红色通道）(like GL_RED, GL_BLUE)(gl2, gl3, gl4)。
     * GL_RGBA	            GL_UNSIGNED_BYTE	每个颜色通道使用 8 位无符号整数表示（0-255），常见于 RGBA 图像。
     * GL_RGBA              GL_UNSIGNED_SHORT	每个颜色通道使用 16 位无符号整数表示（0-65535），适用于更高精度的图像。
     * GL_RGBA	            GL_UNSIGNED_INT	    每个颜色通道使用 32 位无符号整数表示（0-4294967295）。
     * GL_RGBA	            GL_FLOAT	        每个颜色通道使用 32 位浮动数表示，适用于高动态范围（HDR）图像。
     * GL_RGB	            GL_UNSIGNED_BYTE	每个颜色通道使用 8 位无符号整数表示（0-255）。
     * GL_RGB	            GL_UNSIGNED_SHORT	每个颜色通道使用 16 位无符号整数表示（0-65535）。
     * GL_RGB	            GL_UNSIGNED_INT	    每个颜色通道使用 32 位无符号整数表示（0-4294967295）。
     * GL_RGB	            GL_FLOAT	        每个颜色通道使用 32 位浮动数表示，适用于 HDR 图像。
     * GL_BGRA	            GL_UNSIGNED_BYTE	用 BGRA 顺序表示的颜色数据，通常用于图像文件格式（如BMP）。
     * GL_BGR	            GL_UNSIGNED_BYTE	用 BGR 顺序表示的颜色数据。
     * GL_LUMINANCE       	GL_UNSIGNED_BYTE	灰度图像，使用 8 位无符号整数表示。(gl2)
     * GL_LUMINANCE_ALPHA 	GL_UNSIGNED_BYTE	灰度 + alpha 图像，使用 8 位无符号整数表示每个通道。(gl2)
     *
     *
     * GL_DEPTH_COMPONENT	GL_FLOAT	        32  位浮动数表示的深度值，通常用于深度图。
     * GL_DEPTH_COMPONENT	GL_UNSIGNED_INT	    32  位无符号整数表示的深度值。
     * GL_STENCIL_INDEX	    GL_UNSIGNED_BYTE	8   位无符号整数表示的模板值，常用于模板缓冲区。
     * GL_STENCIL_INDEX	    GL_UNSIGNED_INT	    32  位无符号整数表示的模板值，常用于模板缓冲区。
     */
    static Image* readPixels(State& state, int x, int y, int w, int h, int fmt, int type);

  private:
    struct Data;
    Data* const d;
};
} // namespace glr
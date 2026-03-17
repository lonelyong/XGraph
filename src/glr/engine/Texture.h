#pragma once

#include <glr/glr_global.h>

#include <glr/engine/PixelData.h>

namespace glr {
class GLR_API Texture : public PixelData {
    V_OBJECT_META_DECL

  public:
    enum Type
    {
        TEXTURE_1D             = IGL_TEXTURE_1D,
        TEXTURE_2D             = IGL_TEXTURE_2D,
        TEXTURE_3D             = IGL_TEXTURE_3D,
        TEXTURE_CUBE_MAP       = IGL_TEXTURE_CUBE_MAP,
        // require: gl1.4 or GL_ARB_texture_rectangle
        // mipmap: not supoort
        // repeat: only support clamp_to_edge
        TEXTURE_RECTANGLE      = IGL_TEXTURE_RECTANGLE,
        TEXTURE_2D_MULTISAMPLE = IGL_TEXTURE_2D_MULTISAMPLE
    };

    enum FilterParameter
    {
        MIN_FILTER = IGL_TEXTURE_MIN_FILTER,
        // 
        // Only support LINEAR,NEAREST, use base level
        MAG_FILTER = IGL_TEXTURE_MAG_FILTER
    };

    enum FilterMode
    {
        FILTER_UNSET           = IGL_ZERO,
        // 在Mip基层上执行最邻近过滤
        LINEAR                 = IGL_LINEAR,
        // 在Mip基层上执行最邻近过滤
        NEAREST                = IGL_NEAREST,
        // 在最邻近Mip层，并执行线性过滤
        LINEAR_MIPMAP_NEAREST  = IGL_LINEAR_MIPMAP_NEAREST,
        // 在最邻近Mip层，并执行最邻近过滤
        NEAREST_MIPMAP_NEAREST = IGL_NEAREST_MIPMAP_NEAREST,
        // 在Mip层之间执行线性插补，并执行最邻近过滤
        NEAREST_MIPMAP_LINEAR  = IGL_NEAREST_MIPMAP_LINEAR,
        // 在Mip层之间执⾏线性插补，并执⾏线性过滤，又称三线性Mip贴图
        LINEAR_MIPMAP_LINEAR   = IGL_LINEAR_MIPMAP_LINEAR
    };

    enum WrapMode
    {
        WRAP_UNSET      = IGL_ZERO,
        // Not support in gl3
        CLAMP           = 0x2900,
        CLAMP_TO_EDGE   = IGL_CLAMP_TO_EDGE,
        CLAMP_TO_BORDER = IGL_CLAMP_TO_BORDER,
        // Not suport NPOT
        REPEAT          = IGL_REPEAT,
        MIRROR          = IGL_MIRRORED_REPEAT
    };

    enum WrapParameter
    {
        WRAP_S = IGL_TEXTURE_WRAP_S,
        WRAP_T = IGL_TEXTURE_WRAP_T,
        WRAP_R = IGL_TEXTURE_WRAP_R
    };

  public:
    Texture();
    virtual ~Texture();

  public:
    virtual Type getType() const = 0;

    void setFilter(FilterParameter param, FilterMode mode);

    FilterMode getFilter(FilterParameter param) const;

    void setWrap(WrapParameter param, WrapMode mode);

    WrapMode getWrap(WrapParameter param) const;

    // 如果设置了IMAGE，将使用IMAGE的格式
    void           setInternalFormat(InternalFormat fmt);
    InternalFormat getInternalFormat() const;

    // default value is 1.0 for no anisotropic filtering.
    // only support 2D textures and 3D textures
    // cubemap not support
    void  setMaxAnisotropy(double val);
    float getMaxAnisotropy() const;

    // only support 2D textures and 3D textures
    void setGenerateMipmapLevels(bool val);
    bool getGenerateMipmapLevels() const;

  protected:
    // 绑定到当前活动的纹理单元
    // 经测试(N卡)：
    //  1：同一个纹理单元可以同时在CPU端绑定多个不同类型的纹理而不影响对纹理的操作
    //  2：并且在shader里能访问到该纹理(只有一个sampler，多个不同的sampler未测试)
    virtual bool onBind(State& state) override;
    // 如果当前绑定的纹理单元绑定的纹理是当前对象的话则解绑
    virtual bool onUnbind(State& state) override;
    virtual bool onRelease(State& state) override;

    // 尺寸没变,格式没变，无需重新分配显存，无需重新提交数据
    void dirtyParameters();
    bool isParametersDirty(State& state) const;

    // 尺寸或格式改变，需重新分配显存与上传数据
    void dirtyStorage();
    bool isStorageDirty(State& state) const;

    // 需重新调用glGenerateMipmap
    void dirtyMipmapLevels();
    bool isMipmapLevelsDirty(State& state) const;

  private:
    struct Data; Data* const d;;
};
} // namespace glr
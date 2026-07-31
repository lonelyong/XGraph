#pragma once

#include <xg/igl/glr_global.hpp>

#include <xg/igl/engine/BindableObject.hpp>

namespace xg
{
namespace glr
{

class BufferObject;

/**
 * 顶点属性（VertexAttrib）是描述图形中每个顶点（例如三角形、四边形等）的数据。它们是组成图形的基本元素，每个顶点通常包含多个属性，这些属性用于确定顶点的位置信息、颜色、法线、纹理坐标等。顶点属性的典型示例包括：
 * 位置（Position）：顶点的坐标（通常是三维坐标 (x, y, z)）。
 * 法线（Normal）：描述顶点的法线方向，通常用于光照计算。
 * 颜色（Color）：顶点的颜色值。
 * 纹理坐标（Texture Coordinates）：用来映射纹理到顶点的坐标。
 * 切线（Tangent）：在纹理映射和法线贴图等计算中使用。
 * 点大小（Point Size）：在点绘制模式下，指定顶点的大小。
 * 在OpenGL中，顶点属性通常通过 顶点缓冲区对象（VBO）
 * 存储，每个VBO存储一种或多种类型的顶点属性。顶点数据通常存储为一个数组，数组中的每个元素代表一个顶点的多个属性。比如位置、法线和纹理坐标可以一起存储在一个VBO中，每个顶点可能包含多个属性。
 */


/**
 * @brief glVertexAttribPointer
 */
class VertexAttribPointer : public Object {
    V_OBJECT_META_DECL

  public:
    /**
     * @param index 指定顶点属性的索引。这通常是一个整数值，用于标识顶点属性的位置。例如：位置、法线、颜色等。
     * @param size 每个顶点属性的组件数量。通常是 1（例如，标量值），2（例如，2D 坐标），3（例如，3D
     * 坐标），或者4（例如，RGBA 颜色）。默认值为4。
     * @param type 数据类型。通常是 GL_FLOAT, GL_INT, GL_UNSIGNED_BYTE 等，指定每个组件的类型。
     * @param normalized 是否将整数类型的属性归一化为 [0, 1] 或 [-1, 1]
     * 范围。例如，GL_TRUE会将GL_UNSIGNED_BYTE类型的值转换为 [0, 1]。
     * @param stride
     * 步幅，表示每个顶点之间的字节间隔。即，如果顶点数据是紧凑的，那么步幅就是数据的大小；如果顶点数据包含多个不同属性，步幅是属性之间的间隔。
     * @param pointer
     * 指向缓冲区的指针，告诉OpenGL从哪开始读取数据。通常，这个指针会指向缓冲区中的一个偏移量。例如，缓冲区为x y z r g b
     */
    VertexAttribPointer(GLuint_t index, GLint_t size, GLenum_t type, GLboolean_t normalized, GLsizei_t stride, const GLvoid_t* pointer);

  public:
    void apply(BufferObject* buffer);

  private:
    GLuint_t        index_;
    GLint_t         size_;
    GLenum_t        type_;
    GLboolean_t     normalized_;
    GLsizei_t       stride_;
    const GLvoid_t* pointer_;
};

/**
 * @brief glVertexAttribPointer
 */
class VertexAttribFormat : public Object {
    V_OBJECT_META_DECL

  public:
    VertexAttribFormat(GLuint_t attribindex, GLint_t size, GLenum_t type, GLboolean_t normalized, GLuint_t relativeoffset);
};

class VertexAttribBinding : public Object {
    V_OBJECT_META_DECL

  public:
    VertexAttribBinding();
};

class VertexAttribDivisor : public Object {
    V_OBJECT_META_DECL

  public:
    VertexAttribDivisor();
};

/**
 * glVertexAttribPointer 设置的数据是与当前绑定的VAO相关的,而不是直接与VBO绑定的。
 * 每个VAO保存了顶点属性指针的配置，
 * 因此当你使用一个 VBO
 * 并将其绑定到多个VAO时，可以为每个VAO配置不同的顶点属性指针（即不同的解析方式）,尽管它们都指向相同的VBO。
 */

class IGL_CORE_API VertexArrayObject : public BindableObject {
    V_OBJECT_META_DECL

  public:
    VertexArrayObject();
    virtual ~VertexArrayObject();

  public:
    void                 attachBufferObject(BufferObject* buffer);
    void                 detachBufferObject(BufferObject* buffer);
    void                 setAttribPointer(BufferObject* buffer, VertexAttribPointer* pointer);
    VertexAttribPointer* getAttribPointer(BufferObject* buffer);

  protected:
    virtual GLuint_t onCreate(State& state) override;
    virtual bool     onBind(State& state) override;
    virtual bool     onUnbind(State& state) override;
    virtual bool     onUpdate(State& state) override;
    virtual bool     onRelease(State& state) override;
};

} // namespace glr
} // namespace xg
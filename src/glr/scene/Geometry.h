#pragma once

#include <glr/glr_global.h>

#include <map>
#include <set>
#include <string>
#include <vector>

#include <vine/ge/ge_global.h>

#include <glr/engine/ArrayBuffer.h>
#include <glr/scene/Drawable.h>
#include <glr/scene/PrimitiveSet.h>

VI_GE_NS_BEGIN
class Rect2d;
VI_GE_NS_END

namespace glr {
class Texture;
class CubeMap;

/**

 */
class GLR_API Geometry : public Drawable {
    VI_OBJECT_META;

  public:
    Geometry();
    virtual ~Geometry();

  public:
    ArrayBuffer* getVertexArray() const;
    void         setVertexArray(ArrayBuffer* data);

    ArrayBuffer* getNormalArray() const;
    void         setNormalArray(ArrayBuffer* data);

    ArrayBuffer* getColorArray() const;
    void         setColorArray(ArrayBuffer* data);

    int          getNbTexCoordArrays() const;
    ArrayBuffer* getTexCoordArrayAt(int index) const;
    void         addTexCoordArray(ArrayBuffer* data);
    void         removeTexCoordArray(ArrayBuffer* data);
    void         clearTexCoordArrays();

    int  getVertexAttribLocation() const;
    void setVertexAttribLocation(int loc);

    int  getNormalAttribLocation() const;
    void setNormalAttribLocation(int loc);

    int  getColorAttribLocation() const;
    void setColorAttribLocation(int loc);

    int  getTexCoordAttribLocation(ArrayBuffer* data) const;
    void setTexCoordAttribLocation(ArrayBuffer* data, int loc);

    int          getNbVertexAttribArrays() const;
    ArrayBuffer* getVertexAttribArrayAt(int index) const;
    void         addVertexAttribArray(GLuint loc, ArrayBuffer* data);
    /**
     * @brief 如果data绑定到了多个location,则都会被移除
     * @param data
     */
    void removeVertexAttribArray(ArrayBuffer* data);
    void removeVertexAttribArray(GLuint loc);
    void clearVertexAttribArrays();

    int      getNbTextures() const;
    Texture* getTextureAt(int index) const;
    GLuint   getTextureUnitAt(int index) const;
    void     addTexture(GLuint unit, GLuint loc, Texture* tex);
    void     addTexture(GLuint unit, const std::string& name, Texture* tex);
    void     setTextureAttribLocation(GLuint unit, GLuint loc);
    void     setTextureAttribLocation(GLuint unit, const std::string& loc);
    /**
     * @brief 如果纹理绑定了多个单元，则都会被移除
     * @param tex
     */
    void removeTexture(Texture* tex);
    void removetexture(GLuint unit);
    void clearTextures();

    int           getNbPrimitiveSets() const;
    PrimitiveSet* getPrimitiveSet(int index) const;
    void          addPrimitiveSet(PrimitiveSet* prim);
    void          removePrimitiveSet(PrimitiveSet* prim);
    void          clearPrimitiveSets();

    void draw(State& ctx) override;

  protected:
    virtual void onComputeBoundingBox(BoundingBox& bb) const override;

  public:
    static Geometry* createCube(float size, bool create_tex_coord = false);
    static Geometry* createTexturedQuad(const vine::ge::Rect2d& rect, const vine::ge::Rect2d& uv_rect);

  private:
    VI_OBJECT_DATA;
};
} // namespace glr

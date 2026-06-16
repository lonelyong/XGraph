#pragma once

#include <xg/glr/glr_global.h>

#include <map>
#include <set>
#include <string>
#include <vector>

#include <vine/math/Rect2.hpp>

#include <xg/glr/engine/ArrayBuffer.h>
#include <xg/glr/scene/Drawable.h>
#include <xg/glr/scene/PrimitiveSet.h>

namespace glr
{

class Texture;
class CubeMap;

/**

 */
class GLR_API Geometry : public Drawable {
    V_OBJECT_META_DECL

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

    int          getNumTexCoordArrays() const;
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

    int          getNumVertexAttribArrays() const;
    ArrayBuffer* getVertexAttribArrayAt(int index) const;
    void         addVertexAttribArray(GLuint_t loc, ArrayBuffer* data);
    /**
     * @brief 如果data绑定到了多个location,则都会被移除
     * @param data
     */
    void removeVertexAttribArray(ArrayBuffer* data);
    void removeVertexAttribArray(GLuint_t loc);
    void clearVertexAttribArrays();

    int      getNumTextures() const;
    Texture* getTextureAt(int index) const;
    GLuint_t getTextureUnitAt(int index) const;
    void     addTexture(GLuint_t unit, GLuint_t loc, Texture* tex);
    void     addTexture(GLuint_t unit, const std::string& name, Texture* tex);
    void     setTextureAttribLocation(GLuint_t unit, GLuint_t loc);
    void     setTextureAttribLocation(GLuint_t unit, const std::string& loc);
    /**
     * @brief 如果纹理绑定了多个单元，则都会被移除
     * @param tex
     */
    void removeTexture(Texture* tex);
    void removetexture(GLuint_t unit);
    void clearTextures();

    int           getNumPrimitiveSets() const;
    PrimitiveSet* getPrimitiveSet(int index) const;
    void          addPrimitiveSet(PrimitiveSet* prim);
    void          removePrimitiveSet(PrimitiveSet* prim);
    void          clearPrimitiveSets();

    void draw(State& ctx) override;

  protected:
    virtual void onComputeBoundingBox(BoundingBox& bb) const override;

  public:
    static Geometry* createCube(float size, bool create_tex_coord = false);
    static Geometry* createTexturedQuad(const vine::math::Rect2d& rect, const vine::math::Rect2d& uv_rect);

  private:
    struct Data;
    Data* const d;
    ;
};

} // namespace glr

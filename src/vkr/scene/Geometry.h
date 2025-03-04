#pragma once

#include <vkr/vkr_global.h>

#include <map>
#include <set>
#include <string>
#include <vector>

#include <vine/ge/Rect2.h>

#include <vkr/scene/Drawable.h>
#include <vkr/scene/PrimitiveSet.h>

namespace vkr {
class Texture;
class CubeMap;
class ArrayBuffer;

class VKR_API Geometry : public Drawable {
    VI_OBJECT_META;

  public:
    Geometry();
    virtual ~Geometry();

  public:
    void draw(State& ctx) override;
    void addVertexAttribArray(int loc, ArrayBuffer* data);
    void addTexture(int unit, int loc, Texture* tex);
    void addTexture(int unit, const std::string& name, Texture* tex);
    void addPrimitiveSet(PrimitiveSet* prim);

  protected:
    virtual void onComputeBoundingBox(BoundingBox& bb) const override;

  public:
    static Geometry* createCube(float size,
                                int   vertices_loc,
                                int   normals_loc         = -1,
                                int   tex_2d_coords_loc   = -1,
                                int   cube_map_coords_loc = -1);
    static Geometry* createTexturedQuad(int                     vertices_loc,
                                        int                     norms_loc,
                                        int                     tex_coords_loc,
                                        const vine::ge::Rect2d& rect,
                                        const vine::ge::Rect2d& uv_rect);

  private:
    VI_OBJECT_DATA;
};
} // namespace vkr

#include "ExampleModels.h"

#include <glm/ext.hpp>

#include <vine/ge/Rect2.h>

#include <glr/app/ResourceManager.h>
#include <glr/engine/CubeMap.h>
#include <glr/engine/SkyBox.h>
#include <glr/engine/StateSet.h>
#include <glr/engine/Subroutine.h>
#include <glr/engine/Texture2D.h>
#include <glr/engine/Uniform.h>
#include <glr/scene/Geometry.h>
#include <glr/scene/Model.h>

#include <glr/app/DefaultUniformStore.h>
#include <glr/app/GeometryConfigurer.h>

namespace glr {

using ResMgr = ResourceManager;

Model* ExampleModels::createAxis(float len, const Vec3d& posi) {
    auto shader   = ResMgr::instance()->getInternalShader(ResMgr::EXAMPLE_SAHDER_STD_PHONG);
    auto vertices = new Vec3fArray();
    {
        vertices->push_back(Vec3f());
        vertices->push_back(Vec3f(len, 0, 0));
        vertices->push_back(Vec3f());
        vertices->push_back(Vec3f(0, len, 0));
        vertices->push_back(Vec3f());
        vertices->push_back(Vec3f(0, 0, len));
    }
    auto colors = new Vec4fArray();
    {
        colors->emplace_back(1.f, 0.f, 0.0f, 1.0f);
        colors->emplace_back(1.f, 0.f, 0.0f, 1.0f);
        colors->emplace_back(0.f, 1.f, 0.0f, 1.0f);
        colors->emplace_back(0.f, 1.f, 0.0f, 1.0f);
        colors->emplace_back(0.f, 0.f, 1.0f, 1.0f);
        colors->emplace_back(0.f, 0.f, 1.0f, 1.0f);
    }
    Mat4d mat(1.0);
    mat = glm::translate(mat, posi);

    auto geom = new Geometry();
    geom->setVertexArray(vertices);
    geom->setColorArray(colors);
    geom->addPrimitiveSet(new DrawArrays(PrimitiveSet::MODE_LINES, 0, vertices->size()));

    auto axis = new Model();
    axis->addDrawable(geom);
    axis->setMatrix(mat);
    axis->getOrCreateStateSet()->setShader(shader);
    axis->getOrCreateStateSet()->setAttribute(DefaultUniformStore::instance()->getLightingDisabled());
    GeometryConfigurer::configureStdPhong(geom, axis->getOrCreateStateSet());
    return axis;
}

Model* ExampleModels::createCube(float len, const Vec3d& posi, bool with_tex) {
    auto shader = ResMgr::instance()->getInternalShader(ResMgr::EXAMPLE_SAHDER_STD_PHONG);

    auto geom = Geometry::createCube(len, true);
    if (with_tex) {
        auto tex = ResMgr::instance()->getInternalCubeMap(ResMgr::EXAMPLE_CUBE_MAP1);
        geom->addTexture(GL_TEXTURE0, 0, tex);
    }
    else {
        auto colors = new Vec4fArray();
        colors->push_back({ 0.8f, 0.8f, 0.0f, 1.0f });
        geom->addVertexAttribArray(2, colors);

        auto tex_coords2 = new Vec2fArray();
        tex_coords2->push_back(Vec2f());
        auto tex_coords3 = new Vec3fArray();
        tex_coords3->push_back(Vec3f());
        geom->addVertexAttribArray(3, tex_coords2);
        geom->addVertexAttribArray(4, tex_coords3);
    }



    Mat4d mat(1.0);
    if (with_tex) {
        mat = glm::rotate(mat, glm::radians(90.), Vec3d(1.0, 0., 0.));
    }
    mat = glm::translate(mat, posi);

    auto cube = new Model();
    cube->addDrawable(geom);
    cube->setMatrix(mat);
    cube->getOrCreateStateSet()->setShader(shader);

    GeometryConfigurer::configureStdPhong(geom, cube->getOrCreateStateSet());
    return cube;
}

Model* ExampleModels::createSkyBox() {
    auto skybox = glr::createSkyBox(ResMgr::instance()->getInternalCubeMap(ResMgr::EXAMPLE_CUBE_MAP2));
    return skybox;
}

Model* ExampleModels::createPointCloud(int n) {
    auto pc = new Model();

    auto geom     = new Geometry();
    auto vertices = new Vec3fArray();
    auto colors   = new Vec3fArray();
    vertices->reserve(n);
    colors->reserve(vertices->capacity());
    auto posi_offset = INT16_MAX / 10000.f / 2.f;
    for (size_t i = 0; i < vertices->capacity(); i++) {
        vertices->push_back({ rand() / 10000. - posi_offset, rand() / 10000. - posi_offset, rand() / 10000. });
        colors->push_back({ rand() / static_cast<double>(INT16_MAX),
                            rand() / static_cast<double>(INT16_MAX),
                            rand() / static_cast<double>(INT16_MAX) });
    }
    geom->addVertexAttribArray(0, vertices);
    geom->addVertexAttribArray(1, colors);
    geom->addPrimitiveSet(new DrawArrays(DrawArrays::MODE_POINTS, 0, vertices->size()));
    pc->addDrawable(geom);
    pc->getOrCreateStateSet()->setShader(ResMgr::instance()->getInternalShader(ResMgr::EXAMPLE_SAHDER_POINT_CLOUD));
    return pc;
}

Model* ExampleModels::createImage(const char* file) {
    using namespace vine::ge;
    auto shader = ResMgr::instance()->getInternalShader(ResMgr::EXAMPLE_SAHDER_STD_PHONG);

    auto tex = new Texture2D();
    tex->setImage(file);

    auto img_size = Rect2d(0., 0., tex->getWidth() / 400., tex->getHeight() / 400.);
    auto geom_img = Geometry::createTexturedQuad(img_size, Rect2d(0, 0, 1, 1));
    geom_img->addTexture(0, 0, tex);

    Mat4d mat(1.0);
    mat = glm::rotate(mat, glm::radians(15.), Vec3d(1.0, 1., 0.));
    mat = glm::translate(mat, Vec3d(1, 2, 3));

    auto img = new Model();
    img->setMatrix(mat);
    img->addDrawable(geom_img);
    img->getOrCreateStateSet()->setShader(shader);
    img->getOrCreateStateSet()->setAttribute(DefaultUniformStore::instance()->getLightingDisabled());

    GeometryConfigurer::configureStdPhong(geom_img, img->getOrCreateStateSet());
    return img;
}
} // namespace glr
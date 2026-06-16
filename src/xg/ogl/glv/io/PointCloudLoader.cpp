#include "PointCloudLoader.h"

#include <algorithm>
#include <filesystem>
#include <limits>
#include <locale>

#include <pcl/ModelCoefficients.h>
#include <pcl/features/boundary.h>
#include <pcl/features/normal_3d.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/filters/passthrough.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/search/kdtree.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/surface/poisson.h>

#include <osg/Geode>
#include <osg/Geometry>
#include <osg/MatrixTransform>
#include <osg/PointSprite>

namespace glv {

using Pt     = pcl::PointXYZRGB;
using PtNorm = pcl::PointXYZRGBNormal;
using PC     = pcl::PointCloud<Pt>;
using PCPtr  = PC::Ptr;

enum RenderMode
{
    MODE_PLANE,
    MODE_DEPTH,
    MODE_ORIGINAL
};
enum FileType
{
    TYPE_UNKNOW,
    TYPE_PLY,
    TYPE_PCD
};
namespace {

constexpr RenderMode S_RENDER_MODE = MODE_ORIGINAL;

constexpr const char* S_VS_STR = R"(
#version 330 core
precision highp float;

// defualt
// gl_Vertex = 0
// gl_Normal = 1
// gl_Color = 2
layout(location = 0) in vec3 position;
layout(location = 2) in vec4 color;
// in vec4 osg_Vertex;
// in vec4 osg_Color;
uniform mat4 osg_ModelViewProjectionMatrix;
out vec4 frag_color;
void main() {
    gl_Position = osg_ModelViewProjectionMatrix * vec4(position.x, position.y, position.z, 1.0);
    // gl_PointSize = 15.0;
    gl_PointSize = 3;
    // gl_PointSize = clamp(position.z * 10, 5, 20);
    frag_color = vec4(color.x, color.y, color.z, 1.0);
}
)";
constexpr const char* S_FS_STR = R"(
#version 330 core
precision highp float;
in vec4 frag_color;
out vec4 FragColor;
void main(){
    // vec2 p = gl_PointCoord * 2.0 - vec2(1.0);
    // if(dot(p, p) > sin(atan(p.y, p.x) * 5.0))
    //     discard;
    float dist = length(gl_PointCoord - vec2(0.5, 0.5));
    FragColor = frag_color;
    //FragColor.a = 1.0 - dist;
}
)";


static void xxxx(PCPtr pc) {
    pcl::PointCloud<pcl::Normal>::Ptr      normals(new pcl::PointCloud<pcl::Normal>);
    pcl::search::KdTree<Pt>::Ptr           kdtree(new pcl::search::KdTree<Pt>());
    pcl::NormalEstimation<Pt, pcl::Normal> ne;
    ne.setInputCloud(pc);
    ne.setSearchMethod(kdtree);
    ne.setKSearch(20);
    ne.compute(*normals);

    // pcl::PointCloud<pcl::Boundary>::Ptr                                boundaries(new
    // pcl::PointCloud<pcl::Boundary>); pcl::BoundaryEstimation<pcl::PointXYZ, pcl::Normal, pcl::Boundary> be;
    // be.setInputCloud(pc);
    // be.setInputNormals(normals);
    // be.setSearchMethod(kdtree);
    ////be.setRadiusSearch(10);
    // be.setKSearch(10);
    // be.setAngleThreshold(M_PI / 2);
    // be.compute(*boundaries);
    // pcl::PointCloud<pcl::PointXYZ>::Ptr boundary_points(new pcl::PointCloud<pcl::PointXYZ>);

    pcl::PointCloud<PtNorm>::Ptr cloud_with_normals(new pcl::PointCloud<PtNorm>);
    pcl::concatenateFields(*pc, *normals, *cloud_with_normals);

    pcl::Poisson<PtNorm> poisson;
    poisson.setInputCloud(cloud_with_normals);
    pcl::PolygonMesh mesh;
    poisson.reconstruct(mesh);

    // 5. 保存外表面
    pcl::io::savePLYFile("d:/1.ply", mesh);
}

bool isPlyFile(const std::string& ext) {
    return ext == ".ply";
}

bool isPcdFile(const std::string& ext) {
    return ext == ".pcd";
}

bool isSupportedType(const std::string& file, FileType& type) {
    namespace fs = std::filesystem;
    fs::path path(file);
    if (!path.has_extension()) return false;

    auto file_ext = path.extension().string();
    std::transform(file_ext.begin(), file_ext.end(), file_ext.begin(), ::tolower);
    if (isPlyFile(file_ext))
        type = TYPE_PLY;
    else if (isPcdFile(file_ext))
        type = TYPE_PCD;
    else
        type = TYPE_UNKNOW;

    return type != TYPE_UNKNOW;
}

osg::MatrixTransform* parse(const PCPtr cloud) {
    auto z_lower = 0.f;
    auto z_upper = 1000.f;
    auto z_range = z_upper - z_lower;

    pcl::Normal                            norm;
    pcl::NormalEstimation<Pt, pcl::Normal> normal_estimation;
    pcl::PassThrough<Pt>                   pass;
    pass.setInputCloud(cloud);
    pass.setFilterFieldName("z");
    pass.setFilterLimits(z_lower, z_upper);
    pass.filter(*cloud);

    auto geom     = new osg::Geometry();
    auto vertices = new osg::Vec3Array();
    auto colors   = new osg::Vec4Array();
    vertices->reserve(cloud->size());
    colors->reserve(cloud->size());

    if constexpr (S_RENDER_MODE == MODE_PLANE) {
        PCPtr cloud2(new PC());
        // pass.filter(*cloud2);

        std::vector<pcl::ModelCoefficients::Ptr> vec_plane_coefficients;
        std::vector<pcl::PointIndices::Ptr>      vec_plane_indices;
        // pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne;
        // pcl::PointCloud<pcl::Normal>::Ptr cloud_normals(new pcl::PointCloud<pcl::Normal>);
        // pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>());

        // ne.setSearchMethod(tree);
        // ne.setInputCloud(cloud2);
        // ne.setKSearch(50);
        // ne.compute(*cloud_normals);

        // pcl::SACSegmentationFromNormals<pcl::PointXYZ, pcl::Normal> seg;
        pcl::SACSegmentation<Pt> seg;
        seg.setInputCloud(cloud2);
        seg.setModelType(pcl::SACMODEL_PLANE);
        seg.setMethodType(pcl::SAC_RANSAC);
        seg.setDistanceThreshold(0.01);
        seg.setMaxIterations(100);
        seg.setOptimizeCoefficients(true);

        // seg.setRadiusLimits(0, 0.2);
        // seg.setEpsAngle(0.01);
        // seg.setInputNormals(cloud_normals);
        // pcl::ModelCoefficients::Ptr mcs(new pcl::ModelCoefficients());
        // pcl::PointIndices::Ptr indices(new pcl::PointIndices);
        // seg.segment(*indices, *mcs);
        while (true) {
            pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients);
            pcl::PointIndices::Ptr      inliers(new pcl::PointIndices);
            seg.segment(*inliers, *coefficients);
            if (!inliers->indices.size()) break;
            vec_plane_coefficients.push_back(coefficients);
            vec_plane_indices.push_back(inliers);
            pcl::ExtractIndices<Pt> extract1;
            extract1.setInputCloud(cloud2);
            extract1.setIndices(inliers);
            extract1.setNegative(true);
            extract1.filter(*cloud2);

            // pcl::ExtractIndices<pcl::Normal> extract2;
            // extract2.setInputCloud(cloud_normals);
            // extract2.setIndices(inliers);
            // extract2.setNegative(true);
            // extract2.filter(*cloud_normals);
        }

        std::vector<osg::Vec4> color_map;
        for (int i = 0; i < 256; i++) {
            auto r = rand() / 32767.;
            auto g = rand() / 32767.;
            auto b = rand() / 32767.;
            color_map.emplace_back(r, g, b, 1.0f);
        }

        for (int i = 0; i < vec_plane_indices.size(); i++) {
            auto indices = vec_plane_indices[i];
            for (auto idx : indices->indices) {
                auto& pt = (*cloud)[idx];
                vertices->push_back(osg::Vec3(pt.x, pt.y, pt.z));
                colors->push_back(color_map[i]);
            }
        }
    }
    else if constexpr (S_RENDER_MODE == MODE_DEPTH) {
        auto depth = 0.f;
        for (auto&& pt : *cloud) {
            if (!std::isnormal(pt.x) || !std::isnormal(pt.y) || !std::isnormal(pt.z)) continue;
            vertices->push_back(osg::Vec3(pt.x, pt.y, pt.z));
            depth = (pt.z - z_lower) / z_range * 2.f;
            if (depth <= 1.f) {
                colors->push_back(osg::Vec4(1.f - depth, depth, 0.f, 1.0f));
            }
            else if (depth <= 2.f) {
                colors->push_back(osg::Vec4(0.f, 2.f - depth, depth - 1.f, 1.0f));
            }
        }
    }
    else if constexpr (S_RENDER_MODE == MODE_ORIGINAL) {
        for (auto&& pt : *cloud) {
            if (!std::isnormal(pt.x) || !std::isnormal(pt.y) || !std::isnormal(pt.z)) continue;
            vertices->push_back((osg::Vec3(pt.x, pt.y, pt.z)));
            colors->push_back(osg::Vec4(pt.r / 255., pt.g / 255., pt.b / 255., 1.0f));
        }
    }

    geom->setVertexArray(vertices);
    // geom->setColorArray(colors, osg::Array::BIND_PER_VERTEX);
    geom->setUseVertexArrayObject(true);
    geom->setUseVertexBufferObjects(true);
    geom->setVertexAttribArray(0, vertices, osg::Array::BIND_PER_VERTEX);
    geom->setVertexAttribArray(2, colors, osg::Array::BIND_PER_VERTEX);
    geom->addPrimitiveSet(new osg::DrawArrays(GL_POINTS, 0, vertices->size()));

    auto prog = new osg::Program();
    prog->addShader(new osg::Shader(osg::Shader::VERTEX, S_VS_STR));
    prog->addShader(new osg::Shader(osg::Shader::FRAGMENT, S_FS_STR));

    auto point_sprite = new osg::PointSprite();
    point_sprite->setCoordOriginMode(osg::PointSprite::LOWER_LEFT);

    auto geod = new osg::Geode();
    geod->addDrawable(geom);
    geod->getOrCreateStateSet()->setAttributeAndModes(prog, 1);
    geod->getOrCreateStateSet()->setMode(GL_PROGRAM_POINT_SIZE, 1);
    geod->getOrCreateStateSet()->setTextureAttributeAndModes(0, point_sprite, 1);
    geod->getOrCreateStateSet()->setMode(GL_BLEND, 1);

    auto mt = new osg::MatrixTransform();
    mt->addChild(geod);
    return mt;
}

}; // namespace

osg::MatrixTransform* PointCloudLoader::loadFile(const std::string& file) {
    FileType type;
    if (!isSupportedType(file, type)) return nullptr;
    if (type == TYPE_PLY) {
        auto pc = pcl::make_shared<pcl::PointCloud<Pt>>();
        pcl::io::loadPLYFile<Pt>(file, *pc);
        return parse(pc);
    }
    else if (type == TYPE_PCD) {
        auto pc = pcl::make_shared<pcl::PointCloud<Pt>>();
        pcl::io::loadPCDFile<Pt>(file, *pc);
        return parse(pc);
    }
    return nullptr;
}

bool PointCloudLoader::isSupported(const std::string& file) {
    FileType type;
    return isSupportedType(file, type);
}
} // namespace glv
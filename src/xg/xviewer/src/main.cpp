#include <cstring>
#include <filesystem>
#include <iostream>

#include <QApplication>

#include <xg/xviewer/app/RealizeOperation.hpp>

#include <osg/Material>
#include <osg/MatrixTransform>
#include <osg/ShapeDrawable>

#include <xg/comm/Environment.hpp>
#include <xg/comm/Text.hpp>

#include <xg/xviewer/app/Application.hpp>
#include <xg/xviewer/io/BrepLoader.hpp>
#include <xg/xviewer/io/MeshLoader.hpp>
#include <xg/xviewer/io/OctomapLoader.hpp>
#include <xg/xviewer/io/PointCloudLoader.hpp>
#include <xg/xviewer/modeling/CoordGenerator.hpp>
#include <xg/xviewer/modeling/CurveGenerator.hpp>
#include <xg/xviewer/modeling/DottedCurve.hpp>
#include <xg/xviewer/modeling/MeshCutterVTK.hpp>

#include <xg/xviewer/app/MainWindow.hpp>
#include <xg/xviewer/app/ViewWidget.hpp>
#include <xg/xviewer/app/Viewer.hpp>

osg::Group* CreateExampleModels()
{
    auto root = osg::ref_ptr(new osg::Group());

    xg::xviewer::MeshCutterVTK mesh_cutter;
    mesh_cutter.setMesh("R:\\models\\0731-43#-right.stl");
    mesh_cutter.setPlane(osg::Vec3(0, 0, 30), osg::Vec3(0, 0, 1));
    mesh_cutter.update();

    osg::Vec3Array*  pnts = new osg::Vec3Array();
    std::vector<int> nparts;

    mesh_cutter.getOrderedPoints(*pnts, nparts);

    std::vector<osg::Vec3> pnts2;
    pnts2.reserve(pnts->size());

    for (int i = 0; i < nparts.front(); i++) { pnts2.push_back(pnts->at(i)); }

    // auto dc = createDottedCurve(pnts2, {}, {});

    auto dc = new xg::xviewer::DottedCurve();
    dc->setInputPoints(pnts2);
    // dc->setIsClosed(true);
    dc->downsample(30, 120, 6);
    root->addChild(dc->createGeometry());

    auto pnts3 = dc->getPoints();

    auto dc2       = xg::xviewer::createDottedCurve(pnts3, {}, {});
    auto dc2_model = dc2->createGeometry();
    // dc2_model->setMatrix(osg::Matrix::translate(0,0,-50));
    root->addChild(dc->createGeometry());

    auto mesh = mesh_cutter.createGeometry(true, true, osg::Vec4(1, 0, 0, 1), osg::Vec4(0, 1, 0, 1));
    mesh->setMatrix(osg::Matrix::translate(300, 0, 0));

    root->addChild(mesh);

    return root.release();
}

int main(int argc, char** argv)
{
    using namespace xg::xviewer;

    namespace fs = std::filesystem;
    fs::current_path(xg::getApplicationDir());

    Application app(argc, argv);

    osg::ref_ptr<osg::Group> model;
    if (argc == 1) { model = CreateExampleModels(); }
    else {
        std::string file = argv[1];
        if (MeshLoader::isSupported(file)) { model = MeshLoader().loadFile(file); }
        else if (BrepLoader::isSupported(file)) {
            model = BrepLoader().loadFile(file);
        }
        else if (PointCloudLoader::isSupported(file)) {
            model = PointCloudLoader().loadFile(file);
        }
        else if (OctomapLoader::isSupported(file)) {
            OctomapLoader loader;
            loader.setRenderOption(OctomapLoader::RENDER_AS_BOX_USE_GEOMETRY_SHADER);
            model = loader.loadFile(file);
        }
        else {
            std::cout << std::endl << "Not supported." << std::endl;
            return -2;
        }

        if (!model) {
            std::cout << std::endl << "Load failed." << std::endl;
            return -3;
        }
    }

    auto v = new Viewer();

    auto coord     = createCoord(100, 2, 20, 4, true);
    auto hud_coord = createHudCoord(v->getCamera(), 60, 2, 12, 4);
#if XG_XVIEWER_BUILD_WITH_OSGVERSE
    v->addNodeAsDeferred(model);
    v->addNodeAsCustom(coord);
#endif
    v->addSlave(hud_coord, false, false);
    v->fitToScreen();

    QApplication qapp(argc, argv);
    MainWindow   mwnd;
    mwnd.getViewWidget()->setViewer(v);
    mwnd.show();

    return qapp.exec();
}
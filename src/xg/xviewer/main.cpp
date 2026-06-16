#include <cstring>
#include <filesystem>
#include <iostream>

#include <QApplication>

#include <xviewer/app/RealizeOperation.h>

#include <osg/Material>
#include <osg/MatrixTransform>
#include <osg/ShapeDrawable>

#include <xg/comm/Environment.h>
#include <xg/comm/Text.h>

#include <xviewer/app/Application.h>
#include <xviewer/io/BrepLoader.h>
#include <xviewer/io/MeshLoader.h>
#include <xviewer/io/OctomapLoader.h>
#include <xviewer/io/PointCloudLoader.h>
#include <xviewer/modeling/CoordGenerator.h>
#include <xviewer/modeling/CurveGenerator.h>
#include <xviewer/modeling/DottedCurve.h>
#include <xviewer/modeling/MeshCutterVTK.h>

#include <xviewer/app/MainWindow.h>
#include <xviewer/app/ViewWidget.h>
#include <xviewer/app/Viewer.h>

osg::Group* CreateExampleModels() {
    auto root = osg::ref_ptr(new osg::Group());

    xviewer::MeshCutterVTK mesh_cutter;
    mesh_cutter.setMesh("R:\\models\\0731-43#-right.stl");
    mesh_cutter.setPlane(osg::Vec3(0, 0, 30), osg::Vec3(0, 0, 1));
    mesh_cutter.update();

    osg::Vec3Array*  pnts = new osg::Vec3Array();
    std::vector<int> nparts;

    mesh_cutter.getOrderedPoints(*pnts, nparts);

    std::vector<osg::Vec3> pnts2;
    pnts2.reserve(pnts->size());

    for (int i = 0; i < nparts.front(); i++) {

        pnts2.push_back(pnts->at(i));
    }

    // auto dc = createDottedCurve(pnts2, {}, {});

    auto dc = new xviewer::DottedCurve();
    dc->setInputPoints(pnts2);
    // dc->setIsClosed(true);
    dc->downsample(30, 120, 6);
    root->addChild(dc->createGeometry());

    auto pnts3 = dc->getPoints();

    auto dc2       = xviewer::createDottedCurve(pnts3, {}, {});
    auto dc2_model = dc2->createGeometry();
    // dc2_model->setMatrix(osg::Matrix::translate(0,0,-50));
    root->addChild(dc->createGeometry());

    auto mesh = mesh_cutter.createGeometry(true, true, osg::Vec4(1, 0, 0, 1), osg::Vec4(0, 1, 0, 1));
    mesh->setMatrix(osg::Matrix::translate(300, 0, 0));

    root->addChild(mesh);

    return root.release();
}

int main(int argc, char** argv) {
    using namespace xviewer;

    namespace fs = std::filesystem;
    fs::current_path(xg::getApplicationDir());

    Application app(argc, argv);

    osg::ref_ptr<osg::Group> model;
    if (argc == 1) {
        model = CreateExampleModels();
    }
    else {
        std::string file = argv[1];
        if (MeshLoader::isSupported(file)) {
            model = MeshLoader().loadFile(file);
        }
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

    v->addNodeAsDeferred(model);
    v->addNodeAsCustom(coord);
    v->addSlave(hud_coord, false, false);
    v->fitToScreen();

    QApplication qapp(argc, argv);
    MainWindow   mwnd;
    mwnd.getViewWidget()->setViewer(v);
    mwnd.show();

    return qapp.exec();
}
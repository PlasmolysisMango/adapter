#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/adapterRegistry.h"
#include "pxr/base/plug/registry.h"
#include "pxr/usdImaging/usdImagingGL/engine.h"
#include "pxr/usdImaging/usdImaging/delegate.h"
#include "pxr/usd/usd/stage.h"
#include <iostream>

#include "widget.h"
#include <QApplication>

using namespace pxr;

int main(int argc, char* argv[])
{
    auto &plugreg = PlugRegistry::GetInstance();
    auto ret = plugreg.RegisterPlugins("E:\\github\\usd_atfx\\adapter\\plugInfo.json");
    auto ret2 = plugreg.FindTypeByName("MyPrimAdapter");
    std::cout << ret2.GetTypeName() << std::endl;
    auto stage = UsdStage::Open("E:\\github\\usd_atfx\\adapter\\stage.usda");
    for (auto refer : stage->TraverseAll()) {
        std::cout << refer.GetName() << std::endl;
    }
    auto &usdreg = UsdImagingAdapterRegistry::GetInstance();
    for (auto token : usdreg.GetAdapterKeys()) {
        std::cout << token << std::endl;
    }
    auto ret3 = usdreg.ConstructAdapter(TfToken("MyPrimAdapter"));

    QApplication q(argc, argv);
    OpenGLWidget w;
    w.show();

    UsdImagingGLEngine engine;
    /*UsdGeomCamera cam;
    auto op = cam.AddTranslateOp();
    op.Set(GfVec3d(0,0,20));
    auto fr = cam.GetCamera(1).GetFrustum();
    engine.SetCameraState(fr.ComputeViewMatrix(), fr.ComputeProjectionMatrix());
    engine.SetEnablePresentation(true);*/
    engine.Render(stage->GetPseudoRoot(), UsdImagingGLRenderParams());
    return q.exec();
}
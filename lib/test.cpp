#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/adapterRegistry.h"
#include "pxr/base/plug/registry.h"
#include <iostream>

using namespace pxr;

class MyPrimAdapter : public UsdImagingPrimAdapter
{
public:
    typedef UsdImagingPrimAdapter BaseAdapter;

    void TrackVariability(UsdPrim const &prim,
                          SdfPath const &cachePath,
                          HdDirtyBits *timeVaryingBits,
                          UsdImagingInstancerContext const *instancerContext = nullptr) const override
    {
        std::cout << "TrackVariability" << std::endl;
    }

    void UpdateForTime(UsdPrim const &prim,
                       SdfPath const &cachePath,
                       UsdTimeCode time,
                       HdDirtyBits requestedBits,
                       UsdImagingInstancerContext const *instancerContext = nullptr) const override
    {
        std::cout << "UpdateForTime" << std::endl;
    }

    HdDirtyBits ProcessPropertyChange(UsdPrim const &prim,
                                      SdfPath const &cachePath,
                                      TfToken const &propertyName) override
    {
        std::cout << "ProcessPropertyChange" << std::endl;
        return HdDirtyBits(0);
    }
    void MarkDirty(UsdPrim const &prim,
                   SdfPath const &cachePath,
                   HdDirtyBits dirty,
                   UsdImagingIndexProxy *index) override
    {
        std::cout << "MarkDirty" << std::endl;
    }
    SdfPath Populate(UsdPrim const &prim,
                     UsdImagingIndexProxy *index,
                     UsdImagingInstancerContext const *
                         instancerContext = nullptr) override
    {
        std::cout << "Populate" << std::endl;
        return SdfPath();
    }

    virtual void _RemovePrim(SdfPath const &cachePath,
                             UsdImagingIndexProxy *index) override
    {
        std::cout << "_RemovePrim" << std::endl;
    }
};

TF_REGISTRY_FUNCTION(TfType)
{
    typedef MyPrimAdapter Adapter;
    TfType t = TfType::Define<Adapter, TfType::Bases<Adapter::BaseAdapter> >();
    t.SetFactory< UsdImagingPrimAdapterFactory<Adapter> >();
}
#pragma once

#include <vkr/vkrenderer_global.h>

#include <vkr/viewer/Viewer.h>

namespace vkr {
class Viewer;

class VKR_API SdlViewer : public Viewer{
  public:
    SdlViewer();
    virtual ~SdlViewer();

  public:
    bool initialize();
    bool isInitialized() const;

    virtual int run() override;

  private:
    struct Data;
    Data* const d;
};
}; // namespace vkr
#pragma once

#include <glr/glrenderer_global.h>

#include <glr/viewer/Viewer.h>

namespace glr {
class Viewer;

class GLR_API SdlViewer : public Viewer{
  public:
    SdlViewer();
    virtual ~SdlViewer();

  public:
    void initialize();

    bool isInitialized() const;

    virtual int run() override;

  private:
    struct Data;
    Data* const d;
};
}; // namespace glr
#pragma once

#include "glrenderer_global.h"

#include "Viewer.h"

namespace glr {
class Viewer;

class GLRENDERER_API SdlViewer : public Viewer{
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
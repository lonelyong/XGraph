#pragma once

#include <glr/glr_global.h>

#include <glr/app/Viewer.h>

namespace glr {
class Viewer;

class  SdlViewer : public Viewer{
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
}; // namespace glr
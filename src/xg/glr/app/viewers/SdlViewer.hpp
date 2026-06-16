#pragma once

#include <xg/glr/glr_global.hpp>

#include <xg/glr/app/Viewer.hpp>

namespace xg {
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
} // namespace glr
} // namespace xg 
#pragma once

#include <vkr/vkr_global.h>

#include <vkr/engine/GraphicContext.h>
#include <vkr/app/Viewer.h>

namespace vkr {
class Viewer;

class GraphicContextGlfw : public GraphicContext {
  public:
    struct Traits {
        int  width   = 800;
        int  height  = 600;
        bool visible = true;
    };

  public:
    virtual void swapBuffers() override = 0;

    virtual bool realize() override = 0;

    virtual int getWidth() const override = 0;

    virtual int getHeight() const override = 0;

  public:
    static GraphicContextGlfw* create(const Traits& traits);
};

class VKR_API GlfwViewer : public Viewer {
  public:
    GlfwViewer();
    virtual ~GlfwViewer();

  public:
    bool initialize();

    bool isInitialized() const;

    virtual int run() override;

  private:
    struct Data;
    Data* const d;
};
}; // namespace vkr
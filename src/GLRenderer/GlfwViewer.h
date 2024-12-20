#pragma once

#include "glrenderer_global.h"

#include "GraphicContext.h"
#include "Viewer.h"

namespace glr {
class Viewer;

class GraphicContextGlfw : public GraphicContext {
  public:
    struct Traits {
        int  width   = 800;
        int  height  = 600;
        bool visible = true;
    };

  public:
    virtual void makeCurrent() override = 0;

    virtual void swapBuffers() override = 0;

    virtual void realize() override = 0;

    virtual int getWidth() const override = 0;

    virtual int getHeight() const override = 0;

  public:
    static GraphicContextGlfw* create(const Traits& traits);
};

class GLRENDERER_API GlfwViewer : public Viewer {
  public:
    GlfwViewer();
    virtual ~GlfwViewer();

  public:
    void initialize();

    bool isInitialized() const;

    virtual int run() override;

  private:
    struct Data;
    Data* const d;
};
}; // namespace glr
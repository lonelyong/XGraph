#pragma once

#include <vkr/vkrenderer_global.h>

#include <vector>

#include <vkr/engine/Object.h>

namespace vkr {
class VKR_API PrimitiveSet : public Object {
    VI_OBJECT_META;

  public:
    enum Mode
    {
        MODE_POINTS,        //= GL_POINTS,
        MODE_LINES,         //= GL_LINES,
        MODE_LINE_LOOP,     //= GL_LINE_LOOP,
        MODE_LINE_STRIP,    //= GL_LINE_STRIP,
        MODE_TRIANGLES,     //= GL_TRIANGLES,
        MODE_TRIANGLE_TRIP, //= GL_TRIANGLE_STRIP,
        MODE_TRIANGLE_FAN,  //= GL_TRIANGLE_FAN,
        // no support in gl,// 3
        MODE_QUADS, //= GL_QUADS
    };

  public:
    PrimitiveSet();
    PrimitiveSet(Mode mode, int insts);

  public:
    Mode getMode() const;
    void setMode(Mode mode);

    int  getInstances() const;
    void setInstances(int insts);

  private:
    Mode mode_      = MODE_TRIANGLES;
    int  instances_ = 1;

  public:
    virtual void draw() = 0;
};

class VKR_API DrawArrays : public PrimitiveSet {
    VI_OBJECT_META;

  public:
    DrawArrays();
    DrawArrays(Mode mode, int offset, int count);
    DrawArrays(Mode mode, int offset, int count, int insts);

  public:
    int  getOffset() const;
    void setOffset(int offset);

    int  getCount() const;
    void setCount(int count);

    virtual void draw() override;

  private:
    int offset_ = 0;
    int count_  = 0;
};

class VKR_API DrawElementsUInt : public PrimitiveSet {
    VI_OBJECT_META;

  public:
    DrawElementsUInt();
    DrawElementsUInt(Mode mode);
    DrawElementsUInt(Mode mode, int insts);

  public:
    void              setIndices(std::vector<int> indices);
    std::vector<int>& getIndices();

    virtual void draw() override;

  private:
    std::vector<int> indices_;
};
}; // namespace vkr
#pragma once

#include <iterator>

#include <xg/igl/engine/BufferObject.hpp>
#include <xg/igl/engine/types.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API ArrayBuffer : public BufferObject {
    V_OBJECT_META_DECL

  public:
    enum Type
    {
        ARRAY_UNKNOW = 0,

        ARRAY_INT8,
        ARRAY_INT16,
        ARRAY_INT32,

        ARRAY_UINT8,
        ARRAY_UINT16,
        ARRAY_UINT32,

        ARRAY_FLOAT,
        ARRAY_DOUBLE,

        ARRAY_VEC2F,
        ARRAY_VEC3F,
        ARRAY_VEC4F,

        ARRAY_VEC2I,
        ARRAY_VEC3I,
        ARRAY_VEC4I,

        ARRAY_VEC2D,
        ARRAY_VEC3D,
        ARRAY_VEC4D
    };

  public:
    virtual Type        getType() const          = 0;
    virtual GLsizei_t   size() const             = 0;
    virtual void        resize(GLsizei_t size)   = 0;
    virtual void        reserve(GLsizei_t size)  = 0;
    virtual void        clear()                  = 0;
    virtual GLsizei_t   capacity() const         = 0;
    virtual bool        empty() const            = 0;
    virtual void*       data_ptr()               = 0;
    virtual const void* data_ptr() const         = 0;
    virtual GLsizei_t   sizeOfItem() const       = 0;
    virtual void*       valueAt(GLsizei_t index) = 0;
};

template <typename T>
class Array : public ArrayBuffer {
    V_OBJECT_META_DECL

  public:
    using item_type = T;

  public:
    Array();
    virtual ~Array();

    class IGL_CORE_API iterator {
      public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type        = T;
        using difference_type   = GLsizei_t;
        using pointer           = T*;
        using reference         = T&;

        iterator(Array<T>* arr, GLsizei_t pos);
        iterator(const Array<T>::iterator& otehr);

        void            operator++();
        void            operator++(difference_type i);
        void            operator--();
        void            operator--(difference_type i);
        iterator        operator+(difference_type d) const;
        iterator        operator-(difference_type d) const;
        iterator&       operator+=(difference_type d);
        iterator&       operator-=(difference_type d);
        difference_type operator-(const Array<T>::iterator& other) const;

        reference operator*();
        reference operator->();

        bool operator!=(const Array<T>::iterator& it) const;
        bool operator==(const Array<T>::iterator& it) const;

      private:
        Array<T>* arr_;
        GLsizei_t pos_;
    };

    class IGL_CORE_API const_iterator {
      public:
        const_iterator(const Array<T>* arr, GLsizei_t pos);
        const_iterator(const Array<T>::const_iterator& otehr);

        void     operator++();
        void     operator++(int i);
        void     operator--();
        void     operator--(int i);
        const T& operator*() const;
        bool     operator!=(const Array<T>::const_iterator& it) const;
        bool     operator==(const Array<T>::const_iterator& it) const;

      private:
        const Array<T>* arr_;
        GLsizei_t       pos_;
    };

    friend class iterator;
    friend class const_iterator;

  public:
    virtual Type        getType() const override;
    virtual GLsizei_t   size() const override;
    virtual T*          data();
    virtual const T*    data() const;
    virtual void*       data_ptr() override;
    virtual const void* data_ptr() const override;
    virtual T&          at(GLsizei_t index);
    virtual const T&    at(GLsizei_t index) const;
    virtual void*       valueAt(GLsizei_t index) override;
    virtual void        resize(GLsizei_t size) override;
    virtual void        reserve(GLsizei_t size) override;
    virtual void        clear() override;
    virtual void        push_back(const T& val);

    template <typename... TArgs>
    void emplace_back(TArgs&&... args)
    { push_back(T(args...)); }

    virtual T&             front();
    virtual const T&       front() const;
    virtual T&             back();
    virtual const T&       back() const;
    virtual GLsizei_t      capacity() const override;
    virtual GLsizei_t      sizeOfItem() const override;
    virtual iterator       begin();
    virtual const_iterator cbegin() const;
    virtual iterator       end();
    virtual const_iterator cend() const;

    virtual Target getTarget() const override;
    virtual Usage  getUsage() const override;

    bool empty() const override;

  protected:
    virtual GLuint_t onCreate(State& state) override;
    virtual bool     onUpdate(State& state) override;

  private:
    struct Data;
    Data* const d;
    ;
};

V_TMPL_OBJECT_META_IMPL(template <typename T>, Array<T>, ArrayBuffer)

using Int8Array   = Array<int8_t>;
using Int16Array  = Array<int16_t>;
using Int32Array  = Array<int32_t>;
using UInt8Array  = Array<uint8_t>;
using UInt16Array = Array<uint16_t>;
using UInt32Array = Array<uint32_t>;
using FloatArray  = Array<float>;
using DoubleArray = Array<double>;
using Vec2fArray  = Array<Vec2f>;
using Vec3fArray  = Array<Vec3f>;
using Vec4fArray  = Array<Vec4f>;
using Vec2iArray  = Array<Vec2i>;
using Vec3iArray  = Array<Vec3i>;
using Vec4iArray  = Array<Vec4i>;
using Vec2dArray  = Array<Vec2d>;
using Vec3dArray  = Array<Vec3d>;
using Vec4dArray  = Array<Vec4d>;

} // namespace glr
} // namespace xg
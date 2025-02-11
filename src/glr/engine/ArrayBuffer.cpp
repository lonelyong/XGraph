#include <glr/engine/ArrayBuffer.h>

#include <vector>


VI_OBJECT_META_IMPL(glr::ArrayBuffer, glr::BufferObject);
VI_TMPL_OBJECT_META_IMPL(template <typename T>, glr::Array<T>, glr::ArrayBuffer);

namespace glr {


template <typename T> struct Array<T>::Data {
    std::vector<T> impl;
};

template <typename T>
Array<T>::Array()
  : d(new Data()) {
}

template <typename T> Array<T>::~Array() {
    delete d;
}

template <typename T> Array<T>::Type Array<T>::getType() const {
    if constexpr (std::is_same<T, int8_t>::value) {
        return ARRAY_INT8;
    }
    else if constexpr (std::is_same<T, int16_t>::value) {
        return ARRAY_INT16;
    }
    else if constexpr (std::is_same<T, int32_t>::value) {
        return ARRAY_INT32;
    }
    else if constexpr (std::is_same<T, uint8_t>::value) {
        return ARRAY_UINT8;
    }
    else if constexpr (std::is_same<T, uint16_t>::value) {
        return ARRAY_UINT16;
    }
    else if constexpr (std::is_same<T, uint32_t>::value) {
        return ARRAY_UINT32;
    }
    else if constexpr (std::is_same<T, float>::value) {
        return ARRAY_FLOAT;
    }
    else if constexpr (std::is_same<T, double>::value) {
        return ARRAY_DOUBLE;
    }

    else if constexpr (std::is_same<T, Vec2f>::value) {
        return ARRAY_VEC2F;
    }
    else if constexpr (std::is_same<T, Vec3f>::value) {
        return ARRAY_VEC3F;
    }
    else if constexpr (std::is_same<T, Vec4f>::value) {
        return ARRAY_VEC4F;
    }
    else if constexpr (std::is_same<T, Vec2i>::value) {
        return ARRAY_VEC2I;
    }
    else if constexpr (std::is_same<T, Vec3i>::value) {
        return ARRAY_VEC3I;
    }
    else if constexpr (std::is_same<T, Vec4i>::value) {
        return ARRAY_VEC4I;
    }
    else if constexpr (std::is_same<T, Vec2d>::value) {
        return ARRAY_VEC2D;
    }
    else if constexpr (std::is_same<T, Vec3d>::value) {
        return ARRAY_VEC3D;
    }
    else if constexpr (std::is_same<T, Vec4d>::value) {
        return ARRAY_VEC4D;
    }

    return ARRAY_UNKNOW;
}

template <typename T> BufferObject::Target Array<T>::getTarget() const {
    return TARGET_ARRAY_BUFFER;
}

template <typename T> BufferObject::Usage Array<T>::getUsage() const {
    return USAGE_STATIC_DRAW;
}

template <typename T> GLsizei Array<T>::size() const {
    return d->impl.size();
}

template <typename T> T* Array<T>::data() {
    return d->impl.data();
}

template <typename T> const T* Array<T>::data() const {
    return d->impl.data();
}

template <typename T> void* Array<T>::data_ptr() {
    return d->impl.data();
}

template <typename T> const void* Array<T>::data_ptr() const {
    return d->impl.data();
}

template <typename T> T& Array<T>::at(GLsizei index) {
    return d->impl[index];
}

template <typename T> const T& Array<T>::at(GLsizei index) const {
    return d->impl[index];
}

template <typename T> void* Array<T>::valueAt(GLsizei index) {
    return &d->impl.at(index);
}

template <typename T> void Array<T>::resize(GLsizei size) {
    d->impl.resize(size);
}

template <typename T> void Array<T>::reserve(GLsizei size) {
    d->impl.reserve(size);
}

template <typename T> void Array<T>::clear() {
    d->impl.clear();
}

template <typename T> void Array<T>::push_back(const T& val) {
    d->impl.push_back(val);
}

template <typename T> T& Array<T>::front() {
    return d->impl.front();
}

template <typename T> const T& Array<T>::front() const {
    return d->impl.front();
}

template <typename T> T& Array<T>::back() {
    return d->impl.back();
}

template <typename T> const T& Array<T>::back() const {
    return d->impl.back();
}

template <typename T> GLsizei Array<T>::capacity() const {
    return d->impl.capacity();
}

template <typename T> bool Array<T>::empty() const {
    return d->impl.empty();
}

template <typename T> GLsizei Array<T>::sizeOfItem() const {
    return sizeof(item_type);
}

template <typename T> GLuint Array<T>::onCreate(State& state) {
    auto id = ArrayBuffer::onCreate(state);
    if (id != GL_ZERO) {
        glBindBuffer(getTarget(), id);
        glBufferData(getTarget(), size() * sizeof(item_type), (void*)data(), getUsage());
        glBindBuffer(getTarget(), 0);
    }
    return id;
}

template <typename T> bool Array<T>::onUpdate(State& state) {
    return true;
}

template <typename T> Array<T>::iterator Array<T>::begin() {
    return Array<T>::iterator(this, 0);
}

template <typename T> Array<T>::const_iterator Array<T>::cbegin() const {
    return Array<T>::const_iterator(this, 0);
}

template <typename T> Array<T>::iterator Array<T>::end() {
    return Array<T>::iterator(this, d->impl.size());
}

template <typename T> Array<T>::const_iterator Array<T>::cend() const {
    return Array<T>::const_iterator(this, d->impl.size());
}

template <typename T>
Array<T>::iterator::iterator(Array<T>* arr, GLsizei pos)
  : arr_(arr)
  , pos_(pos) {
}
template <typename T>
Array<T>::iterator::iterator(const Array<T>::iterator& other)
  : arr_(other.arr_)
  , pos_(other.pos_) {
}
template <typename T> void Array<T>::iterator::operator++() {
    ++pos_;
}
template <typename T> void Array<T>::iterator::operator++(difference_type i) {
    pos_ += i;
}
template <typename T> void Array<T>::iterator::operator--() {
    --pos_;
}
template <typename T> void Array<T>::iterator::operator--(difference_type i) {
    pos_ -= i;
}
template <typename T> Array<T>::iterator Array<T>::iterator::operator+(difference_type d) const {
    return Array<T>::iterator(arr_, pos_ + d);
}
template <typename T> Array<T>::iterator Array<T>::iterator::operator-(difference_type d) const {
    return Array<T>::iterator(arr_, pos_ - d);
}
template <typename T> Array<T>::iterator& Array<T>::iterator::operator+=(difference_type d) {
    pos_ += d;
    return *this;
}
template <typename T> Array<T>::iterator& Array<T>::iterator::operator-=(difference_type d) {
    pos_ -= d;
    return *this;
}
template <typename T>
Array<T>::iterator::difference_type Array<T>::iterator::operator-(const Array<T>::iterator& other) const {
    return pos_ - other.pos_;
}
template <typename T> T& Array<T>::iterator::operator*() {
    return arr_->d->impl[pos_];
}
template <typename T> T& Array<T>::iterator::operator->() {
    return arr_->d->impl.at(pos_);
}
template <typename T> bool Array<T>::iterator::operator!=(const Array<T>::iterator& it) const {
    return !(*this == it);
}
template <typename T> bool Array<T>::iterator::operator==(const Array<T>::iterator& it) const {
    return arr_ == it.arr_ && pos_ == it.pos_;
}

template <typename T>
Array<T>::const_iterator::const_iterator(const Array<T>* arr, GLsizei pos)
  : arr_(arr)
  , pos_(pos) {
}
template <typename T>
Array<T>::const_iterator::const_iterator(const Array<T>::const_iterator& other)
  : arr_(other.arr_)
  , pos_(other.pos_) {
}
template <typename T> void Array<T>::const_iterator::operator++() {
    ++pos_;
}
template <typename T> void Array<T>::const_iterator::operator++(int i) {
    pos_ += i;
}
template <typename T> void Array<T>::const_iterator::operator--() {
    --pos_;
}
template <typename T> void Array<T>::const_iterator::operator--(int i) {
    pos_ -= i;
}
template <typename T> const T& Array<T>::const_iterator::operator*() const {
    return arr_->d->impl[pos_];
}
template <typename T> bool Array<T>::const_iterator::operator!=(const Array<T>::const_iterator& it) const {
    return !(*this == it);
}
template <typename T> bool Array<T>::const_iterator::operator==(const Array<T>::const_iterator& it) const {
    return arr_ == it.arr_ && pos_ == it.pos_;
}

template class Array<int8_t>;
template class Array<int16_t>;
template class Array<int32_t>;
template class Array<uint8_t>;
template class Array<uint16_t>;
template class Array<uint32_t>;
template class Array<float>;
template class Array<double>;
template class Array<Vec2f>;
template class Array<Vec3f>;
template class Array<Vec4f>;
template class Array<Vec2i>;
template class Array<Vec3i>;
template class Array<Vec4i>;
template class Array<Vec2d>;
template class Array<Vec3d>;
template class Array<Vec4d>;
} // namespace glr
#pragma once

#include <algorithm>
#include <cassert>
#include <ranges>

namespace container {

template <std::default_initializable T>
class Container {
public:
    Container() : size_(0), capacity_(0), data_(nullptr) {}

    explicit Container(size_t size) : size_(size), capacity_(size_), data_(new T[capacity_]) {}

    Container(size_t size, const T &val) : size_(size), capacity_(size_), data_(new T[capacity_]) {
        for (int i = 0; i < size_; i++) {
            data_[i] = val;
        }
    }

    Container(const Container &other) : size_(other.size_), capacity_(size_) {
        data_ = new T[size_];
        try {
            std::ranges::copy(other.data_, other.data_ + size_, data_);
        } catch (...) {
            delete[] data_;
            throw;
        }
    }

    Container(Container &&other) noexcept : Container() { swap(other); }

    ~Container() { delete[] data_; }

    Container &operator=(Container other) noexcept {
        swap(other);
        return *this;
    }

    size_t size() const { return size_; }

    size_t capacity() const { return capacity_; }

    bool empty() const { return size_ == 0; }

    const T &front() const {
        assert(!empty() && "front() called on an empty container");
        return data_[0];
    }

    T &front() {
        assert(!empty() && "front() called on an empty container");
        return data_[0];
    }

    const T &back() const {
        assert(!empty() && "back() called on an empty container");
        return data_[size_ - 1];
    }

    T &back() {
        assert(!empty() && "back() called on an empty container");
        return data_[size_ - 1];
    }

    T &operator[](size_t n) {
        assert(n < size_ && "operator[]: out of bounds");
        return data_[n];
    }

    const T &operator[](size_t n) const {
        assert(n < size_ && "operator[]: out of bounds");
        return data_[n];
    }

    void clear() { size_ = 0; }

    void push(const T &val) {
        if (size_ == capacity_) {
            const size_t new_capacity = capacity_ == 0 ? 1 : capacity_ * 2;
            T *new_data = new T[new_capacity];
            std::ranges::copy(data_, data_ + capacity_, new_data);
            delete[] data_;
            capacity_ = new_capacity;
            data_ = new_data;
        }
        data_[size_] = val;
        ++size_;
    }

private:
    void swap(Container &other) noexcept {
        std::swap(other.size_, size_);
        std::swap(other.capacity_, capacity_);
        std::swap(other.data_, data_);
    }

    size_t size_;
    size_t capacity_;
    T *data_;
};

}  // namespace container

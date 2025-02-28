#pragma once

#include <cassert>
#include <cstddef>
#include <utility>

#include "noncopyable.hpp"

namespace memory {

namespace detail {
class Controller : private util::NonCopyable {
public:
    void increase() { ++counter_; }
    void decrease() {
        if (--counter_ == 0) {
            clear();
        }
    }
    std::size_t use_count() const { return counter_; }

protected:
    Controller() = default;
    virtual ~Controller() = default;

private:
    virtual void clear() = 0;

    std::size_t counter_ = 0;
};

template <typename T>
class Handler : public Controller {
public:
    explicit Handler(T *ptr) : data_(ptr) { increase(); }

private:
    void clear() override {
        delete data_;
        delete this;
    }

    T *data_ = nullptr;
};
}  // namespace detail

template <typename T>
class Shared {
public:
    template <typename U>
    friend class Shared;

    explicit Shared(T *ptr = nullptr) : data_(ptr) {
        if (data_ != nullptr) {
            controller_ = new detail::Handler<T>(data_);
        }
    }
    template <typename U>
        requires std::convertible_to<U *, T *>
    explicit Shared(const Shared<U> &other) : data_(other.data_), controller_(other.controller_) {
        if (controller_ != nullptr) {
            controller_->increase();
        }
    }
    Shared(const Shared<T> &other) : data_(other.data_), controller_(other.controller_) {
        if (controller_ != nullptr) {
            controller_->increase();
        }
    }
    template <typename U>
        requires std::convertible_to<U *, T *>
    explicit Shared(Shared<U> &&other) noexcept : Shared() {
        data_ = other.data_;
        other.data_ = nullptr;
        controller_ = other.controller_;
        other.controller_ = nullptr;
    }
    Shared(Shared<T> &&other) noexcept : Shared() { swap(other); }

    template <typename U>
        requires std::convertible_to<U *, T *>
    Shared &operator=(const Shared<U> &other) {
        Shared<T>(other).swap(*this);
        return *this;
    }
    Shared &operator=(const Shared &other) {
        Shared(other).swap(*this);
        return *this;
    }
    template <typename U>
        requires std::convertible_to<U *, T *>
    Shared &operator=(Shared<U> &&other) noexcept {
        Shared<T>(std::move(other)).swap(*this);
        return *this;
    }
    Shared &operator=(Shared &&other) noexcept {
        Shared(std::move(other)).swap(*this);
        return *this;
    }

    ~Shared() {
        if (controller_ != nullptr) {
            controller_->decrease();
        }
    }

    T *get() const { return data_; }
    void swap(Shared &other) {
        std::swap(data_, other.data_);
        std::swap(controller_, other.controller_);
    }
    std::size_t use_count() const { return controller_ == nullptr ? 0 : controller_->use_count(); }

    T &operator*() const { return *data_; }
    T *operator->() const { return get(); }
    explicit operator bool() const { return get() != nullptr; }

private:
    T *data_ = nullptr;
    detail::Controller *controller_ = nullptr;
};

}  // namespace memory
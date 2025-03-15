#pragma once

namespace iter {

class OddIterator {
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = int;
    using difference_type = std::ptrdiff_t;

    explicit OddIterator(int begin = 1) : counter_(begin) {
        if (counter_ % 2 == 0) {
            throw std::invalid_argument("initializer should be odd");
        }
    }

    value_type operator*() const { return counter_; }
    OddIterator& operator++() {
        counter_ += 2;
        return *this;
    }
    OddIterator operator++(int) {
        OddIterator tmp = *this;
        ++(*this);
        return tmp;
    }

    friend bool operator==(const OddIterator& lhs, const OddIterator& rhs) {
        return lhs.counter_ == rhs.counter_;
    }
    friend bool operator!=(const OddIterator& lhs, const OddIterator& rhs) { return !(lhs == rhs); }

private:
    int counter_ = 0;
};

}  // namespace iter

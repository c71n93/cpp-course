#pragma once

namespace inheritance {

class VirtualBase {
public:
    explicit VirtualBase(int vb) : vb(vb) {}

    virtual ~VirtualBase() = default;

    int vb;
};

class Base1 : virtual public VirtualBase {
public:
    explicit Base1(int a) : VirtualBase(2 * a), b1(a) {}

    int b1;
};

class Base2 : virtual public VirtualBase {
public:
    explicit Base2(int a) : VirtualBase(3 * a), b2(a) {}

    int b2;
};

class Derived : public Base1, public Base2 {
public:
    explicit Derived(int a) : VirtualBase(a), Base1(a), Base2(a) {}
};

}  // namespace inheritance

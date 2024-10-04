#pragma once

class Base1 {
public:
    virtual ~Base1() = default;

    virtual int foo() { return 1; }
};

class Base2 {
public:
    virtual ~Base2() = default;

    virtual int foo() { return 2; }
};

class ProxyBase1 : public Base1 {
public:
    int foo() override { return foo1(); }
    virtual int foo1() = 0;
};

class ProxyBase2 : public Base2 {
public:
    int foo() override { return foo2(); }
    virtual int foo2() = 0;
};

class Derived : public ProxyBase1, public ProxyBase2 {
    int foo1() override { return Base1::foo() * 2; }
    int foo2() override { return Base2::foo() * 3; }
};

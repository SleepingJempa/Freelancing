#include <iostream>
using namespace std;

class A {
public:
    void f() { cout << "A::f"; }
    virtual void g() { cout << "A::g"; }
    void h() { cout << "A::h"; f(); g(); }
};
class B : public A {
public:
    void f() { cout << "B::f"; }
    void g() { cout << "B::g"; }
    void h() { cout << "B::h"; f(); g(); }
};

int main() {
    A a;
    B b;
    A* ap = &b;
    ap->f();
    ap->g();
    ap->h();
}
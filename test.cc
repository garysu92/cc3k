using namespace std;
#include <iostream>

class A {
    public:
    virtual void p() {}
};
class B: public A {
    public:
    virtual void p() {cout << "hi b" << endl;}
};
class C: public B {
    public:
};
class D: public A {
public:
    virtual void p() {cout << "hi d" << endl;}
};
class E: public D {
public:
    virtual void p() {cout << "hi e" << endl;}
};


int main() {
    A *a = new C{};
    a->p();

}
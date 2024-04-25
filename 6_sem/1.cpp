#include <iostream>

struct A {
    A() {std::cout << "A_Con\n";}
    A(const A &a) {std::cout << "A_Copy\n";}
    ~A() {std::cout << "A_Des\n";}
};

struct B:A {
    B() {std::cout << "B_Con\n";}
    B(const B &a) {std::cout << "B_Copy\n";}
    ~B() {std::cout << "B_Des\n";}
};

void g() {B bg; throw bg;}

int main() {
    try {A a; g();}
    catch(A&) {std::cout << "A&\n";}
    catch(B&) {std::cout << "B&\n";}
}

#include <iostream>

class A {
    int a;
    public: 
        A(int x = 0):a(x) {}
        int get_a(void) {return this->a;}
};

int main() {
    A obj(17), obj2;
    std::cout << obj.get_a() << std::endl;

    return 0;
}

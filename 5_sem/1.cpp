#include <iostream>

int main() {
    int x = 5;
    auto fl1 = [](int a) {std::cout << a;};
    auto fl2 = [&x]() {std::cout << x;};
    fl1(x);
    fl2();

    return 0;
}

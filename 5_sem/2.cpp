#include <iostream>
#include <map>
#include <functional>

int f1() {return 1;}

int main() {
    std::function <int()> fptr;
    fptr = f1;
    std::cout << fptr() << std::endl;
}

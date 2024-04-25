#include <iostream>

namespace N {
    int f = 2;
    int g = -2;
}

namespace M {
    int f = 3;
    int g = -3;
}

int f = 5;

int main() {
    int f = 1;
    std::cout << ::f << N::f << M::f << std::endl;
    
    using namespace N;
    std::cout << f << g << M::f << std::endl;

    return 0;
}

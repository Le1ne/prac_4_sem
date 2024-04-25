#include <iostream>

int main() {
    char c;
    std::cin >> std::noskipws;

    while (std::cin >> c) {
        std::cout << c;
    }

    return 0;
}
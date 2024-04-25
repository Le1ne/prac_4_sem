#include <iostream>

int main() {
    std::cin.tie(nullptr);
    std::cin >> std::noskipws;
    char cur;
    std::cin >> cur;

    while (!std::cin.eof()) {
        if (!std::isdigit(cur) && !std::cin.eof()) {
            std::cout << cur;
            std::cin >> cur;
        } else if (cur == '0') {
            while (cur == '0' && !std::cin.eof()) {
                std::cin >> cur;
            }

            if (!std::isdigit(cur) || std::cin.eof()) {
                std::cout << '0';
            }
        } else {
            while (std::isdigit(cur) && !std::cin.eof()) {
                std::cout << cur;
                std::cin >> cur;
            }
        }
    }

    return 0;
}

#include <iostream>
#include <string>

int main() {
    std::string str;

    while (std::cin >> str) {
        auto it = str.begin();

        while (*it == '3' || *it == '4') {
            it++;
        }

        while (*it == '1' || *it == '2') {
            it++;
        }

        if (it == str.end()) {
            std::cout << 1 << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    }

    return 0;
}

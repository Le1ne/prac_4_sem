#include <iostream>
#include <string>

class Reverse {
public:
    Reverse(std::string &s) : str(s) {}

    ~Reverse() {
        std::cout << str << std::endl;
    }

private:
    std::string str;
};

void recursive() {
    std::string cur;

    if (std::cin >> cur) {
        try {
            recursive();
        } catch (...) {}
        throw Reverse(cur);
    }
}

int main() {
    try {
        recursive();
    } catch (...) {}

    return 0;
}

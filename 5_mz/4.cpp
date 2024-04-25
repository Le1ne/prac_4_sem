#include <iostream>
#include <vector>
#include <map>

enum {
    MOD = 4294967161
};

int main() {
    std::map<std::pair<unsigned, unsigned>, unsigned> matrix;
    unsigned r, c, v;
    std::cin >> r >> c >> v;

    while (r != 0 || c != 0 || v != MOD) {
        matrix[{r, c}] = v;
        std::cin >> r >> c >> v;
    }

    while (std::cin >> r >> c >> v) {
        matrix[{r, c}] = (matrix[{r, c}] + static_cast<long long>(v)) % MOD;
    }

    for (auto elem: matrix) {
        if (elem.second != 0) {
            std::cout << elem.first.first << ' ' << elem.first.second << ' ' << elem.second << std::endl;
        }
    }

    return 0;
}

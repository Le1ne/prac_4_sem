#include <iostream>
#include <map>
#include <unordered_map>
#include <utility>

enum {
    MOD = 4294967161
};

int main() {
    std::map<std::pair<uint64_t, uint64_t>, uint64_t> A, res;
    std::unordered_map<uint64_t, std::unordered_map<uint64_t, uint64_t>> B;

    uint64_t r, c, v;

    while (std::cin >> r >> c >> v) {
        if (r == 0 && c == 0 && v == 4294967161) {
            break;
        }

        A.insert({{r, c}, v % MOD});
    }

    while (std::cin >> r >> c >> v) {
        B.insert({r, {}});
        B[r][c] = v % MOD;
    }

    for (auto elem: A) {
        auto cur_col = B.find(elem.first.second);

        if (cur_col != B.end()) {
            for (auto cur_elem: cur_col->second) {
                std::pair<uint64_t, uint64_t> cur_pos = {elem.first.first, cur_elem.first};
                res[cur_pos] += elem.second * cur_elem.second % MOD;
                res[cur_pos] %= MOD;
            }
        }
    }

    for (auto elem: res) {
        if (elem.second) {
            std::cout << elem.first.first << " " << elem.first.second << " " << elem.second << std::endl;
        }
    }

    return 0;
}

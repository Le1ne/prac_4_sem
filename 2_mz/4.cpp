#include <iostream>

int main() {
    char prev, cur;
    int cnt = 1;

    if (!(std::cin >> std::noskipws >> prev)) {
        return 0;
    }

    while (std::cin.get(cur)) {
        if (cur != prev) {
            if (cnt > 4) {
                std::cout << '#' << prev << std::hex << cnt << '#';
            } else if (prev != '#') {
                for (int i = 0; i < cnt; ++i) {
                    std::cout << prev;
                }
            } else {
                std::cout << '#' << '#' << std::hex << cnt << '#';
            }

            cnt = 1;
        } else {
            cnt++;
        }

        prev = cur;
    }

    if (cnt != 0) {
        if ((cnt > 4) || (prev == '#')) {
            std::cout << '#' << prev << std::hex << cnt << '#';
        } else {
            for (int i = 0; i < cnt; ++i) {
                std::cout << prev;
            }
        }
    }

    return 0;
}

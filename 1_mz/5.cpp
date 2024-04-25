#include <iostream>

int main() {
    uint32_t cur, res = 0;
    int total_oct = 4, cnt_in = 0;

    while (total_oct == 4) {
        std::cin >> std::hex >> cur;

        if (cnt_in % 17 == 0) {
            cnt_in = 1;

            continue;
        }

        cnt_in++;
        res = cur;
        int i = 1;

        for (; i < 4 && !std::cin.eof(); ++i) {
            std::cin >> std::hex >> cur;
            cnt_in++;
            res <<= 8;
            res += cur;
        }

        if (i == total_oct) {
            std::cout << res << std::endl;
        } else {
            break;
        }
    }

    return 0;
}

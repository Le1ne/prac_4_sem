#include <iostream>
#include <cmath>

void S(std::string &processing_str, int idx);
void A(std::string &processing_str, int idx);

void S(std::string &processing_str, int idx) {
    int length = processing_str.length();
    
    if (idx == length) {
        return;
    }
    
    std::cout << 'a';

    if (processing_str[idx + 1] == 'x') {
        S(processing_str, idx + 1);
    } else if (processing_str[idx + 1] == 'y') {
        A(processing_str, idx + 1);
    }

    std::cout << 'd';
}

void A(std::string &processing_str, int idx) {
    int length = processing_str.length();
    
    if (idx == length) {
        return;
    }

    std::cout << 'b';

    A(processing_str, idx + 1);

    std::cout << 'c';
}

int main() {
    int k;
    std::cin >> k;

    if (k % 2 == 1) {
        return 0;
    } else {
        int pr_str_size = k / 2;
        int middle_cnt = pr_str_size - 2;
        int cnt_x = middle_cnt, cnt_y = 0;

        while (cnt_y <= middle_cnt) {
            std::string processing_str = "x";
            int cur_cnt_x = cnt_x, cur_cnt_y = cnt_y;

            while (cur_cnt_x > 0) {
                processing_str += "x";
                cur_cnt_x--;
            }

            while (cur_cnt_y > 0) {
                processing_str += "y";
                cur_cnt_y--;
            }

            processing_str += "y";

            S(processing_str, 0);

            std::cout << std::endl;

            cnt_x--;
            cnt_y++;
        }
    }

    return 0;
}

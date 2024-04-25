#include <iostream>
#include <vector>
#include <algorithm>

bool cmp(const int &a, const int &b) {
    int a_ = a;
    int b_ = b;
    int cnt_a = 0;
    int cnt_b = 0;

    while (a_ > 0) {
        if (a_ % 2 == 1) {
            cnt_a++;
        }

        a_ /= 2;
    }

    while (b_ > 0) {
        if (b_ % 2 == 1) {
            cnt_b++;
        }

        b_ /= 2;
    }

    return cnt_a < cnt_b;
}

int main() {
    int cur = 0;
    std::vector<int> seq;

    while (std::cin >> cur) {
        seq.push_back(cur);
    }

    std::stable_sort(seq.begin(), seq.end(), cmp);

    for (auto i : seq) {
        std::cout << i << std::endl;
    }

    return 0;
}

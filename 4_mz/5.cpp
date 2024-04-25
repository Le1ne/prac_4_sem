#include <iostream>
#include <list>

int main() {
    std::list<int> seq;
    int cur = 0;

    while ((std::cin >> cur) && (cur != 0)) {
        seq.push_back(cur);
    }

    while (std::cin >> cur) {
        if (cur < 0) {
            int pos = -cur;
            auto it = seq.begin();

            if ((pos - 1 >= 0) && static_cast<size_t>((pos - 1)) < seq.size()) {
                std::advance(it, pos - 1);
                seq.erase(it);
            }
        } else {
            auto it = seq.begin();
            int value;
            std::cin >> value;

            if ((cur - 1 >= 0) && static_cast<size_t>(cur - 1) < seq.size()) {
                std::advance(it, cur - 1);
                seq.insert(it, value);
            } else {
                seq.push_back(value);
            }
        }
    }

    for (auto elem: seq) {
        std::cout << elem << std::endl;
    }

    seq.clear();

    return 0;
}

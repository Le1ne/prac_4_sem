#include <iostream>
#include <vector>

void process(std::vector<int64_t>& vec, const int64_t value) {
    int total_elems = 0;

    for (auto it = vec.begin(); it != vec.end(); ++it) {
        if (*it >= value) {
            total_elems++;
        }
    }

    vec.reserve(vec.size() + total_elems);

    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
        if (*it >= value) {
            vec.push_back(*it);
        }
    }
}

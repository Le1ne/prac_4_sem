#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

void process(const std::vector<int> &v1, std::vector<int> &v2) {
    if (v1.size() == 0 || v2.size() == 0) {
        return;
    }

    std::set<int> v1_c(v1.begin(), v1.end());

    for (auto idx = v1_c.rbegin(); idx != v1_c.rend(); ++idx) {
        if (*idx >= 0 && *idx < static_cast<int>(v2.size())) {
            v2.erase(v2.begin() + *idx);
        }
    }
}

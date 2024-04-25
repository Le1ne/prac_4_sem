#include <iostream>
#include <vector>

void process(const std::vector<uint64_t> &numbers, std::vector<uint64_t> &output, int step) {
    auto num_it = numbers.begin();
    auto output_it = output.rbegin();

    while (num_it < numbers.end() && output_it < output.rend()) {
        *output_it += *num_it;
        num_it += step;
        output_it++;
    }
}

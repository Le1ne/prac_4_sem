#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

class Sum {
    double res;
    int cnt;
public:
    Sum() : res(0), cnt(0) {}

    void operator()(const double &num) {
        cnt++;
        res += num;
    }

    double mean() const {
        return res / cnt;
    }
};

int main() {
    std::vector<double> seq;
    double cur;

    while (std::cin >> cur) {
        seq.push_back(cur);
    }

    int size = static_cast<int>(seq.size());
    int cut = size / 10;
    seq.erase(seq.begin(), seq.begin() + cut);
    seq.erase(seq.end() - cut, seq.end());

    std::stable_sort(seq.begin(), seq.end());

    size = static_cast<int>(seq.size());
    cut = size / 10;
    seq.erase(seq.begin(), seq.begin() + cut);
    seq.erase(seq.end() - cut, seq.end());

    Sum res = std::for_each(seq.begin(), seq.end(), Sum());
    std::cout << std::fixed << std::setprecision(10) << res.mean() << std::endl;

    return 0;
}

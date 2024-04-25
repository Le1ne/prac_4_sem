#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    long double x, pre_avg = 0.0, pre_quad = 0.0;
    int cnt = 0;

    while (std::cin >> x) {
        pre_avg += x;
        pre_quad += x * x;
        cnt++;
    }

    long double avg = pre_avg / cnt;
    long double quad = std::sqrt((pre_quad - pre_avg * pre_avg / cnt) / cnt);

    std::cout << std::fixed << std::setprecision(10) << avg << ' ' << quad << std::endl;

    return 0;
}

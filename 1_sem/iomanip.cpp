#include <iostream>
#include <iomanip>

int main() {
    std::cout << std::setw(5) << 10 << 20 << std::endl;
    double a = 4.1236243235;
    std::cout << std::fixed << std::showpoint << std::setprecision(6) << a << std::endl;

    return 0;
}

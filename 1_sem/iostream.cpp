#include <iostream>

int main() {
    int x;
    double y;
    char str[80];
    std::cin >> x >> y;
    std::cin.getline(str, 79);
    std::cin.getline(str, 79);
    std::cout << "x = " << x << "y = " << y << "str = " << str << std::endl;

    return 0;
}
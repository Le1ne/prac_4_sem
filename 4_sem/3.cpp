#include <iostream>

template <class T> 
    void swap(T &a, T &b) {
        T tmp; tmp = a; a = b; b = tmp;
    }

template <class T>
    T abs(T x) {
        return x > 0 ? x : -x;
    }



int main() {
    int i = 10, j = 20;
    long l1 = 1000, l2 = 2;
    swap(i, j);
    swap(l1, l2);

    int a = -25;
    long l = -10000;
    double z = -3.14;

    std::cout << abs(i) << abs<int>(l) << abs(z);

    return 0;
}

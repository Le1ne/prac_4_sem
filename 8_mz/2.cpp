#include <iostream>

class Result {
public:
    Result(int64_t val) : res(val) {};

    int64_t get() const {
        return res;
    }

private:
    int64_t res;
};

class Return {};

// Модифицированная функция Аккермана. Растёт очень быстро даже при малых значениях a, b, k

void func(int64_t a, int64_t b, unsigned k) {
    if (k == 0) {
        throw Result(a + b);
    } else if (k > 0 && b == 1) {
        throw Result(a);
    } else if (k > 0 && b > 0) {
        try {
            func(a, b - 1, k);
        } catch (Result &cur) {
            func(a, cur.get(), k - 1);
        }

        catch (Return &cur) {}
    }

    throw Return();
}

int main() {
    int64_t a, b;
    unsigned k;

    while (std::cin >> a >> b >> k) {
        try {
            func(a, b, k);
        } catch (Result &cur) {
            std::cout << cur.get() << std::endl;
        }

        catch (Return &cur) {}
    }

    return 0;
}

#include <iostream>

class BinaryNumber {
public:
    BinaryNumber(const std::string &s = "0") {
        num = s;
    };

    operator std::string() const {
        return num;
    }

    const BinaryNumber &operator++() {
        for (int i = num.length() - 1; i >= 0; --i) {
            if (num[i] == '0') {
                num[i] = '1';

                return *this;
            } else {
                num[i] = '0';
            }
        }

        num = '1' + num;

        return *this;
    }

private:
    std::string num;
};

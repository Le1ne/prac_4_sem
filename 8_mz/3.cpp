#include <iostream>

class S {
public:
    S() {
        if (std::cin >> num) {
            cin_flag = true;
            got_num_flag = true;
        }
    }

    S(const S &&v) {
        num = v.num;
        got_num_flag = v.got_num_flag;
        int cur;

        if (std::cin >> cur) {
            num += cur;
            cin_flag = true;
        } else {
            cin_flag = false;
        }
    }

    ~S() {
        if (!cin_flag && got_num_flag) {
            std::cout << num << std::endl;
        }
    }

    explicit operator bool() const {
        return cin_flag;
    }

private:
    int num = 0;
    bool cin_flag = false;
    bool got_num_flag = false;
};

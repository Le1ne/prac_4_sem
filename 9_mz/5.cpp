#include <iostream>

int main() {
    std::string left_part, right_part;
    bool exist = false;
    bool s_exist = false;
    bool left_correct = false;
    bool s_to_eps = false;
    bool shorting = false;
    bool context_free = true;
    bool s_right = false;

    while (std::cin >> left_part >> right_part) {
        exist = true;

        if (right_part == "_") {
            if (left_part == "S") {
                s_exist = true;
                s_to_eps = true;

                continue;
            }

            shorting = true;
        }
        
        if (left_part == "S") {
            s_exist = true;
            left_correct = true;
        }
        
        for (char ch : left_part) {
            if (isupper(ch)) {
                left_correct = true;
            }
        }

        if (!left_correct) {
            std::cout << -1 << std::endl;

            return 0;
        }

        if (left_part.length() > right_part.length()) {
            shorting = true;
        }

        if (left_part.length() > 1) {
            context_free = false;
        }

        for (char ch : right_part) {
            if (ch == 'S') {
                s_right = true;
            }
        }
    }

    if (s_right && s_to_eps) {
        shorting = true;
    }

    if (!exist || !s_exist) {
        std::cout << -1 << std::endl;
    } else if (context_free && shorting) {
        std::cout << 2 << std::endl;
    } else if (context_free && !shorting) {
        std::cout << 23 << std::endl;
    } else {
        std::cout << 10 << std::endl;
    }

    return 0;
}

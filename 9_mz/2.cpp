#include <iostream>

int main() {
    char cur_sym;
    int k, m, check_k, check_m;

    std::cin >> std::noskipws >> cur_sym;

    while (!std::cin.eof()) {
        k = 0, m = 0;

        if (isspace(cur_sym)) {
            while (isspace(cur_sym) && !std::cin.eof()) {
                std::cin >> cur_sym;
            }

            continue;
        } else if (cur_sym != '0' && !std::cin.eof()) {
            while (!isspace(cur_sym) && !std::cin.eof()) {
                std::cin >> cur_sym;
            }

            std::cout << 0 << std::endl;

            continue;
        }

        k++;

        while (std::cin >> cur_sym && cur_sym == '0' && !std::cin.eof()) {
            k++;
        }

        if (cur_sym == '1') {
            m++;
        } else {
            while (!isspace(cur_sym) && !std::cin.eof()) {
                std::cin >> cur_sym;
            }
            
            std::cout << 0 << std::endl;

            continue;
        }

        while (std::cin >> cur_sym && cur_sym == '1' && !std::cin.eof()) {
            m++;
        }

        if (isspace(cur_sym) && !std::cin.eof()) {
            std::cout << 1 << std::endl;

            continue;
        } else if (cur_sym != '0' && !std::cin.eof()) {
            while (!isspace(cur_sym) && !std::cin.eof()) {
                std::cin >> cur_sym;
            }

            std::cout << 0 << std::endl;

            continue;
        }

        bool is_correct = true, is_checking = true;

        while (is_checking) {
            check_k = 0, check_m = 0;

            if (isspace(cur_sym) || std::cin.eof()) {
                is_checking = false;

                continue;
            } else if (cur_sym != '0' && cur_sym != '1') {
                is_correct = false;

                break;
            }

            check_k++;

            while (std::cin >> cur_sym && cur_sym == '0' && !std::cin.eof()) {
                check_k++;
            }

            if (cur_sym != '1' || check_k != k) {
                while (!isspace(cur_sym) && !std::cin.eof()) {
                    std::cin >> cur_sym;
                }
                
                is_correct = false;

                break;
            }

            check_m++;

            while (std::cin >> cur_sym && cur_sym == '1' && !std::cin.eof()) {
                check_m++;
            }

            if (cur_sym != '0' && !isspace(cur_sym) && !std::cin.eof()) {
                while (!isspace(cur_sym) && !std::cin.eof()) {
                    std::cin >> cur_sym;
                }

                is_correct = false;

                break;
            }
            
            if (check_m != m) {
                while (!isspace(cur_sym) && !std::cin.eof()) {
                    std::cin >> cur_sym;
                }
                
                is_correct = false;

                break;
            }
        }

        std::cout << is_correct << std::endl;
    }

    return 0;
}

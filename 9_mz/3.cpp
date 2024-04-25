#include <iostream>

int main() {
    int k, n;
    char cur_sym;
    
    std::cin >> std::noskipws >> cur_sym;

    while (!std::cin.eof()) {
        k = 0, n = 0;

        if (isspace(cur_sym)) {
            while (isspace(cur_sym) && !std::cin.eof()) {
                std::cin >> cur_sym;
            }
        
            continue;
        } else if (cur_sym != 'a' && !std::cin.eof()) {
            while (!isspace(cur_sym) && !std::cin.eof()) {
                std::cin >> cur_sym;
            }

            std::cout << 0 << std::endl;

            continue;
        }

        k++;

        while (std::cin >> cur_sym && cur_sym == 'a' && !std::cin.eof()) {
            k++;
        }

        if (cur_sym == '0') {
            n++;
        } else {
            while (!isspace(cur_sym) && !std::cin.eof()) {
                std::cin >> cur_sym;
            }

            std::cout << 0 << std::endl;

            continue;
        }

        while (std::cin >> cur_sym && cur_sym == '0' && !std::cin.eof()) {
            n++;
        }

        if (cur_sym == 'b') {
            k--;
        } else {
            while (!isspace(cur_sym) && !std::cin.eof()) {
                std::cin >> cur_sym;
            }

            std::cout << 0 << std::endl;

            continue;
        }

        while (std::cin >> cur_sym && cur_sym == 'b' && !std::cin.eof()) {
            k--;
        }

        if (k != 0) {
            while (!isspace(cur_sym) && !std::cin.eof()) {
                std::cin >> cur_sym;
            }
            
            std::cout << 0 << std::endl;

            continue;
        }

        if (cur_sym == '1') {
            n--;
        } else {
            while (!isspace(cur_sym) && !std::cin.eof()) {
                std::cin >> cur_sym;
            }

            std::cout << 0 << std::endl;

            continue;
        }

        while (std::cin >> cur_sym && cur_sym == '1' && !std::cin.eof()) {
            n--;
        }

        if (n != 0) {
            while (!isspace(cur_sym) && !std::cin.eof()) {
                std::cin >> cur_sym;
            }

            std::cout << 0 << std::endl;

            continue;
        }

        if (!isspace(cur_sym) && !std::cin.eof()) {
            while (!isspace(cur_sym) && !std::cin.eof()) {
                std::cin >> cur_sym;
            }
            
            std::cout << 0 << std::endl;

            continue;
        }

        std::cout << 1 << std::endl;
    }

    return 0;
}

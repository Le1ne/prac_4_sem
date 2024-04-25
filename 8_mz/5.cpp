#include <iostream>
#include <chrono>
#include <string>

int main() {
    int difference = 0;
    std::string prev;
    std::cin >> prev;

    int year_val {std::stoi(prev.substr(0, prev.find("-")))};
    int month_val {std::stoi(prev.substr(prev.find("-") + 1, prev.rfind("-")))};
    int day_val {std::stoi(prev.substr(prev.rfind("-") + 1))};

    std::chrono::year_month_day prev_date {
        std::chrono::year(year_val), std::chrono::month(month_val), std::chrono::day(day_val)
    };

    std::string cur;

    while (std::cin >> cur) {
        int new_year_val {std::stoi(cur.substr(0, cur.find("-")))};
        int new_month_val {std::stoi(cur.substr(cur.find("-") + 1, cur.rfind("-")))};
        int new_day_val {std::stoi(cur.substr(cur.rfind("-") + 1))};

        std::chrono::year_month_day cur_date {
            std::chrono::year(new_year_val), std::chrono::month(new_month_val), std::chrono::day(new_day_val)
        };

        difference += abs(std::chrono::sys_days{cur_date} - std::chrono::sys_days{prev_date}).count();
        prev_date = cur_date;
    }

    std::cout << difference << std::endl;

    return 0;
}

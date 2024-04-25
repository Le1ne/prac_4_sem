#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <set>

class Date {
public:
    Date(const std::string &date) {
        std::string tmp = date;
        std::string sep = "/";
        std::string year_s = tmp.substr(0, tmp.find(sep));
        std::string month_s = tmp.substr(tmp.find(sep) + 1, tmp.rfind(sep));
        std::string day_s = tmp.substr(tmp.rfind(sep) + 1);
        day = stoi(day_s);
        month = stoi(month_s);
        year = stoi(year_s);
    }

    std::string date() {
        std::stringstream date_stream;
        date_stream << year << "/";

        if (month < 10) {
            date_stream << "0" << month;
        } else {
            date_stream << month;
        }

        date_stream << "/";

        if (day < 10) {
            date_stream << "0" << day;
        } else {
            date_stream << day;
        }

        return date_stream.str();
    }

private:
    int day;
    int month;
    int year;
};

int main() {
    std::map<std::string, std::map<std::string, int>> students;
    std::set<std::string> dates;
    std::string surname;
    std::string date;
    int grade;

    while (std::cin >> surname >> date >> grade) {
        Date cur_date(date);
        students[surname][cur_date.date()] = grade;
        dates.insert(cur_date.date());
    }

    std::cout << "." << " ";

    for (const auto& i: dates) {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    for (auto student : students) {
        std::cout << student.first << " ";

        for (const auto& date : dates) {
            if (students[student.first].count(date)) {
                std::cout << student.second[date] << " ";
            } else {
                std::cout << ". ";
            }
        }

        std::cout << std::endl;
    }

    return 0;
}

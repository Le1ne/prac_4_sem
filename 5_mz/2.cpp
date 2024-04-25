#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>

int main() {
    std::map <std::string, std::vector<int>> students;
    std::string surname;
    int grade;

    while (std::cin >> surname >> grade) {
        students[surname].push_back(grade);
    }

    for (auto i = students.begin(); i != students.end(); i++) {
        int total_cnt = 0, res = 0;
        
        for (auto j = (i->second).begin(); j != (i->second).end(); j++) {
            res += *j;
            total_cnt++;
        }

        double mean = (double)res / total_cnt;
        std::cout << i->first << " " << mean << std::endl;
    }

    return 0;
}

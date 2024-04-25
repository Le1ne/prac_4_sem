#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <sstream>
#include <memory>
#include <algorithm>
#include <map>
#include <functional>
#include <cmath>
#include <sstream>

class FigureFactory {
public:
    static FigureFactory &instance() {
        static FigureFactory instance;

        return instance;
    }

    static Figure *create_figure(const std::string& input) {
        std::stringstream stream;
        std::string type, value_1, value_2;
        stream << input;
        stream >> type;

        if (type == "R") {
            stream >> value_1 >> value_2;

            return Rectangle::make(value_1 + " " + value_2);
        } else if (type == "C") {
            stream >> value_1;

            return Circle::make(value_1);
        } else if (type == "S") {
            stream >> value_1;

            return Square::make(value_1);
        }

        return nullptr;
    }
};

int main() {
    std::vector<Figure *> figures;
    std::string data;

    while (std::getline(std::cin, data)) {
        auto figure = FigureFactory::instance().create_figure(data);
        figures.push_back(figure);
    }

    std::stable_sort(figures.begin(), figures.end(), [](const auto &a, const auto &b) {
        return (a->get_square()) < (b->get_square());
    });

    for (auto fig_it = figures.begin(); fig_it != figures.end(); ++fig_it) {
        std::cout << (*fig_it)->to_string() << std::endl;
        delete *fig_it;
    }

    return 0;
}

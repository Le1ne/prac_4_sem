#include <string>
#include <sstream>
#include <cmath>

class Rectangle : public Figure {
public:
    Rectangle(double h, double w) : height(h), weight(w) {};

    double get_square() const override {
        return height * weight;
    }

    static Rectangle* make(std::string data) {
        std::istringstream input(data);
        double h, w;
        input >> h >> w;

        return new Rectangle(h, w);
    }
private:
    double height;
    double weight;
};

class Square : public Figure {
public:
    Square(double s) : side(s) {};

    double get_square() const override {
        return side * side;
    }

    static Square* make(std::string data) {
        std::istringstream input(data);
        double s;
        input >> s;

        return new Square(s);
    }
private:
    double side;
};

class Circle : public Figure {
public:
    Circle(double r) : radius(r) {};

    double get_square() const override {
        return M_PI * radius * radius;
    }

    static Circle* make(std::string data) {
        std::istringstream input(data);
        double r;
        input >> r;

        return new Circle(r);
    }
private:
    double radius;
};

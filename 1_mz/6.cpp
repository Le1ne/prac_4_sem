#include <iostream>
#include <iomanip>

class Point {
public:
    explicit Point(double x = 0.0, double y = 0.0) : x_(x), y_(y) {}

    double x() const {
        return x_;
    }

    double y() const {
        return y_;
    }

private:
    double x_;
    double y_;
};

class Line {
public:
    explicit Line(Point first = Point(), Point second = Point()) {
        a_ = second.y() - first.y();
        b_ = first.x() - second.x();
        c_ = first.x() * second.y() - second.x() * first.y();
    }

    double a() const {
        return a_;
    }

    double b() const {
        return b_;
    }

    double c() const {
        return c_;
    }

private:
    double a_, b_, c_;
};

void intersection(Line &first, Line &second) {
    double a1 = first.a();
    double a2 = second.a();
    double b1 = first.b();
    double b2 = second.b();
    double c1 = first.c();
    double c2 = second.c();

    double det = a1 * b2 - a2 * b1;
    double det_x = c1 * b2 - c2 * b1;
    double det_y = a1 * c2 - a2 * c1;

    if (det == 0) {
        if ((det_x == 0) && (det_y == 0)) {
            std::cout << 2 << std::endl;

            return;
        } else {
            std::cout << 0 << std::endl;

            return;
        }
    }

    double x = det_x / det;
    double y = det_y / det;

    if (x == -0) {
        x = -x;
    }

    if (y == -0) {
        y = -y;
    }

    std::cout << 1 << ' ' << std::fixed << std::setprecision(5) << x << ' ' << y << std::endl;
}

int main() {
    double x1, y1, x2, y2, x3, y3, x4, y4;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    Point p_1(x1, y1), p_2(x2, y2), p_3(x3, y3), p_4(x4, y4);
    Line l_1(p_1, p_2), l_2(p_3, p_4);
    intersection(l_1, l_2);

    return 0;
}

#include <iostream>

class Figure {
public:
    virtual bool equals(const Figure *func) const = 0;

    virtual ~Figure() {}
};

class Rectangle : public Figure {
public:
    Rectangle(int x, int y) : width(x), height(y) {}

    bool equals(const Figure *func) const override {
        const Rectangle *rec = dynamic_cast<const Rectangle *>(func);

        if (rec == nullptr) {
            return false;
        }

        return width == rec->width && height == rec->height;
    }

private:
    int width, height;
};

class Triangle : public Figure {
public:
    Triangle(int x, int y, int z) : first(x), second(y), third(z) {}

    bool equals(const Figure *func) const override {
        const Triangle *tri = dynamic_cast<const Triangle *>(func);

        if (tri == nullptr) {
            return false;
        }

        return first == tri->first && second == tri->second && third == tri->third;
    }

private:
    int first, second, third;
};

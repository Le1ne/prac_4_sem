#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

namespace numbers {
    class complex {
        double real;
        double image;
    public:
        complex(double x = 0.0, double y = 0.0) : real(x), image(y) {}

        explicit complex(const std::string str) {
            std::string tmp = str;
            tmp.erase(tmp.begin());
            tmp.erase(tmp.end() - 1);
            std::string comma = ",";
            std::string real_tmp = tmp.substr(0, tmp.find(comma));
            std::string image_tmp = tmp.substr(tmp.find(comma) + 1);
            real = stod(real_tmp);
            image = stod(image_tmp);
        }

        std::string to_string() const {
            std::stringstream str_in;
            str_in << std::setprecision(10) << '(' << real << ',' << image << ')';

            return str_in.str();
        }

        double re() const {
            return real;
        }

        double im() const {
            return image;
        }

        double abs2() const {
            return real * real + image * image;
        }

        double abs() const {
            return std::sqrt(this->abs2());
        }

        complex operator+=(const complex &num) {
            real += num.real;
            image += num.image;

            return *this;
        }

        complex operator-=(const complex &num) {
            real -= num.real;
            image -= num.image;

            return *this;
        }

        complex operator*=(const complex &num) {
            double t_re = real, t_im = image;
            real = t_re * num.real - t_im * num.image;
            image = t_im * num.real + t_re * num.image;

            return *this; 
        }

        complex operator/=(const complex &num) {
            double t_re = real, t_im = image;
            real = (t_re * num.real + t_im * num.image) / num.abs2();
            image = (t_im * num.real - t_re * num.image) / num.abs2();

            return *this;
        }

        friend complex operator+(const complex &first, const complex &second) {
            complex res = first;
            res += second;

            return res;
        }

        friend complex operator-(const complex &first, const complex &second) {
            complex res = first;
            res -= second;

            return res;
        }

        friend complex operator*(const complex &first, const complex &second) {
            complex res = first;
            res *= second;

            return res;
        }

        friend complex operator/(const complex &first, const complex &second) {
            complex res = first;
            res /= second;

            return res;
        }

        complex operator~() const {
            return complex(real, -image);
        }

        complex operator-() const {
            return complex(-real, -image);
        }
    };
};

#include <iostream>
#include <vector>
#include <complex>
#include <utility>
#include <array>
#include <limits>

namespace Equations {
    template<class Num>
    std::pair<bool, std::vector<std::complex<Num>>> quadratic(const std::array<std::complex<Num>, 3> &coef) {
        Num eps = std::numeric_limits<Num>::epsilon() * 32;
        std::complex<Num> a = coef[2], b = coef[1], c = coef[0];

        if ((std::norm(a)) < eps && (std::norm(b) < eps) && (std::norm(c) < eps)) {
            return {false, {}};
        } else if ((std::norm(a) < eps) && (std::norm(b) < eps)) {
            return {true, {}};
        } else if (std::norm(a) < eps) {
            std::complex<Num> sol = -c / b;

            return {true, {sol}}; 
        }

        std::complex<Num> discrim = b * b - std::complex<Num>(4) * a * c;
        std::complex<Num> first = (-b - std::sqrt(discrim)) / (std::complex<Num>(2) * a);
        std::complex<Num> second = (-b + std::sqrt(discrim)) / (std::complex<Num>(2) * a);

        return {true, {first, second}};
    }
}

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <functional>
#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"

using namespace numbers;

int main(int argc, char **argv) {
    complex c(argv[1]);
    double r = std::stod(argv[2]);
    int n = std::stoi(argv[3]);
    std::vector<std::string> exp;

    for (int i = 4; i < argc; ++i) {
        exp.push_back(argv[i]);
    }

    double delta = 2 * M_PI / n;
    complex step(delta, 0);
    complex res;

    for (int i = 0; i < n; ++i) {
        double a = delta * i;
        double b = delta * (i + 1);
        double t = (a + b) / 2;
        complex z(c.re() + r * (cos(t)), c.im() + r * sin(t));
        complex trig(cos(t), sin(t));
        complex Ri(0, r);
        res += eval(exp, z) * trig * Ri * step;
    }

    std::cout << res.to_string() << std::endl;

    return 0;
}

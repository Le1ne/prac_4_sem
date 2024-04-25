#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <functional>

namespace numbers {
    complex eval(const std::vector<std::string> &args, const complex &z) {
        complex_stack st;

        std::map<std::string, std::function<void()>> mp{
                {"z", [&st, &z]() { st = st << z; }},
                {";", [&st]() { st = ~st; }},
                {"!", [&st]() { st = st << +st; }},
                {"+", [&st]() {
                    complex z1 = +st;
                    st = ~st;
                    complex z2 = +st;
                    st = ~st;
                    st = st << (z2 + z1);
                }},
                {"-", [&st]() {
                    complex z1 = +st;
                    st = ~st;
                    complex z2 = +st;
                    st = ~st;
                    st = st << (z2 - z1);
                }},
                {"*", [&st]() {
                    complex z1 = +st;
                    st = ~st;
                    complex z2 = +st;
                    st = ~st;
                    st = st << (z2 * z1);
                }},
                {"/", [&st]() {
                    complex z1 = +st;
                    st = ~st;
                    complex z2 = +st;
                    st = ~st;
                    st = st << (z2 / z1);
                }},
                {"~", [&st]() {
                    complex z = +st;
                    st = ~st;
                    st = st << ~z;
                }},
                {"#", [&st]() {
                    complex z = +st;
                    st = ~st;
                    st = st << -z;
                }}
        };

        for (const auto &s: args) {
            if (s[0] != '(') {
                mp[s]();
            } else {
                st = st << complex(s);
            }
        }

        return +st;
    }
};

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

void erase_states(std::multimap<std::string, std::string> &raw_rules, std::vector<std::string> &states,
                  const std::string& state) {
    states.push_back(state);

    for (auto rule = raw_rules.lower_bound(state); rule != raw_rules.upper_bound(state); ++rule) {
        for (char ch: rule->second) {
            if (std::isupper(ch) && std::find(states.begin(), states.end(), std::string(1, ch)) == states.end()) {
                erase_states(raw_rules, states, std::string(1, ch));
            }
        }
    }
}

int main() {
    std::multimap<std::string, std::string> raw_rules;
    std::string left, right;

    while (std::cin >> left >> right) {
        raw_rules.insert({left, right});
    }

    std::vector<std::string> states;
    erase_states(raw_rules, states, "S");

    for (auto & raw_rule : raw_rules) {
        if (std::find(states.begin(), states.end(), raw_rule.first) != states.end()) {
            std::cout << raw_rule.first << ' ' << raw_rule.second << std::endl;
        }
    }

    return 0;
}

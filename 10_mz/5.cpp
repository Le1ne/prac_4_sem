#include <iostream>
#include <string>
#include <stack>

int main() {
    std::string input;
    std::cin >> input;
    std::stack<std::string> operands;

    for (char ch: input) {
        if (std::isalpha(ch)) {
            operands.push(std::string(1, ch));
        } else if (ch == '/' || ch == '*' || ch == '+' || ch == '-') {
            std::string second_op = operands.top();
            operands.pop();
            std::string first_op = operands.top();
            operands.pop();
            operands.push("(" + first_op + ch + second_op + ")");
        }
    }

    std::cout << operands.top() << std::endl;

    return 0;
}

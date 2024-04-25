#include <iostream>

template <class T, int SIZE=5>
class Stack {
    T st[SIZE];
    int top;
public: 
    Stack() {
        top = 0;
    }

    void push(T a) {
        if (top == SIZE) {
            std::cout << "Полон" << std::endl;
            st[top++] = a;
        }
    }

    T pop();
};

template <class T, int SIZE>
T Stack<T, SIZE>::pop() {
    if (top == 0) {
        std::cout << "Stack is empty" << std:: endl;
    } else {
        return st[--top];
    }
}

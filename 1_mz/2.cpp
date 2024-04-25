#include <iostream>

class A {
public:
    A() {
        std::cin >> a_;
    }
    
    ~A() {  
        if (to_print_)
        std::cout << a_ << std::endl;
    }

    A(const A& a) {
        to_print_ = true;
        std::cin >> a_;
        a_ += a.get();
    }
    
    int get() const {return a_;};
private:
    int a_;
    bool to_print_ = false;
};

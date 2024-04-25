#include <iostream>

class C {

};

class Stack {
    C *ptr;
    int used;
    int alloc;
public:
    Stack(int u = 0, int a = 8) : used(u), alloc(a) {
        ptr = static_cast<C*>(::operator new(alloc *sizeof(C)));
    }

    Stack(const Stack &v) : used(v.used), alloc(v.alloc) {
        for (int i = 0; i < used; ++i) {
            new(ptr + i)C(v.ptr[i]);
        }
    }

    ~Stack() {
        for (int i = 0; i < used; ++i) {
            ptr[i].~C();
        }

        ::operator delete(ptr);
    }
};

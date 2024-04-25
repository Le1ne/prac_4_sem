#include <iostream>

void *operator new(size_t size);

void operator delete(void *);

struct MyCl {
    MyCl() {}
    ~MyCl() {}
};

int main() {
    MyCl *pp = static_cast <MyCl>(::operator new(sizeof(MyCl)));
    MyCl *ptr = new(pp)MyCl;
    ptr->~MyCl();
    ::operator delete(pp);

    return 0;
}

#include <iostream>
#include <cstring>

class String {
    int len;
    char *str;
public:
    String(int x = 1) {
        len = x;
        str = new char[x];
        str[0] = '\0';
    }
    
    String(const char *s) {
        len = std::strlen(s) + 1;
        str = new char[len];
        strcpy(str, s);
    }
    
    String(const String & v) {
        len = v.len;
        str = new char[len];
        strcpy(str, v.str);
    }

    ~String() {
        delete [] str;
    }

    void print(void) {
        std::cout << str << std::endl;
    }
};

int main(void) {
    String s1, s2("abc"), s3 = s2, s4(100);
    s3.print();

    return 0;
}

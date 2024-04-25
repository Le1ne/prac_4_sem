#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>

namespace numbers {
    class complex_stack {
        complex *arr;
        size_t elem_cnt;
        size_t arr_size;
    public:
        complex_stack(size_t elems = 0, size_t size = 32) : elem_cnt(elems), arr_size(size) {
            arr = static_cast<complex *>(::operator new(arr_size * sizeof(complex)));
        }
 
        complex_stack(const complex_stack &stack, bool is_appending = false) : elem_cnt(stack.elem_cnt + is_appending), \
                    arr_size(stack.arr_size) {
            arr_size = elem_cnt >= arr_size ? arr_size * 2 : arr_size;
            arr = static_cast<complex *>(::operator new(arr_size * sizeof(complex)));
 
            for (size_t i = 0; i < elem_cnt; ++i) {
                arr[i] = stack.arr[i];
            }
        }
 
        ~complex_stack() {
            for (size_t i = 0; i < elem_cnt; ++i) {
                arr[i].~complex();
            }
            
            ::operator delete(arr);
        }
 
        size_t size() const {
            return elem_cnt;
        }
 
        complex &operator[](size_t index) const {
            return arr[index];
        }
 
        complex_stack operator<<(const complex elem_add) const {
            complex_stack res(*this, true);
            res[elem_cnt] = elem_add;
 
            return res;
        }
 
        complex operator+() const {
            return arr[elem_cnt - 1];
        }
 
        complex_stack operator~() const {
            complex_stack res(elem_cnt - 1, arr_size);
 
            for (size_t i = 0; i < elem_cnt - 1; ++i) {
                res[i] = arr[i];
            }
 
            return res;
        }
 
        complex_stack &operator=(const complex_stack &new_stack) {
            complex_stack tmp(new_stack);
            elem_cnt = new_stack.elem_cnt;
            arr_size = new_stack.arr_size;
            std::swap(tmp.arr, this->arr);

            return *this;
        }
    };
};

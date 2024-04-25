#include <functional>
#include <vector>

template<class Iter, class Func>
void myapply(Iter begin, Iter end, Func f) {
    while (begin != end) {
        f(*begin++);
    }
}

template<class Iter, class Predicate>
std::vector<std::reference_wrapper<typename std::iterator_traits<Iter>::value_type>> myfilter2(Iter begin, Iter end, \
                                                                                                Predicate pred) {
    std::vector<std::reference_wrapper<typename std::iterator_traits<Iter>::value_type>> res;

    while (begin != end) {
        if (pred(*begin)) {
            res.push_back(*begin);
        }

        ++begin;
    }

    return res;
}

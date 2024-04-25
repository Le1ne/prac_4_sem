#include <algorithm>
#include <functional>

template<class Iter>
void selection_sort(Iter begin, Iter end) {
    Iter i, j, min_it;

    for (i = begin; i != end; i++) {
        min_it = i;
        j = i;
        j++;

        while (j != end) {
            if (*j < *min_it) {
                min_it = j;
            }

            j++;
        }

        if (min_it != i) {
            std::iter_swap(min_it, i);
        }
    }
}

template<class Iter, class Func>
void selection_sort(Iter begin, Iter end, Func cmp) {
    Iter i, j, min_it;

    for (i = begin; i != end; i++) {
        min_it = i;
        j = i;
        j++;

        while (j != end) {
            if (cmp(*j, *min_it)) {
                min_it = j;
            }

            j++;
        }

        if (min_it != i) {
            std::iter_swap(min_it, i);
        }
    }
}

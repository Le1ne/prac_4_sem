template <class T>
typename T::value_type my_max(const T &a) {
    typename T::value_type res = *(a.begin());

    for (auto i : a) {
        if (i > res) {
            res = i;
        }
    }

    return res;
}

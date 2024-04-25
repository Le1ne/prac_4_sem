template <class T>
typename T::value_type last_5_sum(const T &stl) {
    typename T::value_type res{};
    
    if (stl.size() < 5u) {
        return res;
    }

    typename T::const_reverse_iterator it = a.crbegin();

    for (int i = 0; i < 5; ++i) {
        res += *it;
        ++it;
    }

    return res;    
}

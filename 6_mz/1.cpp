template<class T>
typename T::value_type process(const T &c) {
    typename T::value_type default_value{};

    if (c.empty()) {
        return default_value;
    }

    auto it = c.end();
    it--;
    typename T::value_type res{};

    for (int i = 0; i < 5; ++i) {
        if (i == 0 || i == 2 || i == 4) {
            res += *it;
        }

        if (it == c.begin()) {
            return res;
        }

        it--;
    }

    return res;
}

template<class Container, class Predicate>
Container myfilter(const Container &c, Predicate pred) {
    Container res;

    for (auto elem : c) {
        if (pred(elem)) {
            res.insert(res.end(), elem);
        }
    }

    return res;
}

template <class T>
void duplicate(T &stl) {
    for (auto it = stl.begin(); it != stl.end(); it++) {
        it = stl.insert(it, *it);
        it++;
    }
}

#include <iostream>
#include <string>
#include <stdexcept>

class StringView {
public:
    StringView(std::string &s, size_t begin = 0, size_t count = std::string::npos) : str_view(&s) {
        if (s.size() > begin) {
            s_begin = begin;

            if (s.size() - begin >= count) {
                s_count = count;
            } else {
                s_count = s.size() - begin;
            }
        } else {
            s_begin = 0;
            s_count = 0;
        }
    }

    StringView(const StringView &sv, size_t begin = 0, size_t count = std::string::npos) : str_view(sv.str_view),
                    s_begin(sv.s_begin + begin), s_count(count == std::string::npos ? sv.s_count - begin : count) {
        if (sv.s_count > begin) {
            s_begin = sv.s_begin + begin;

            if (sv.size() - begin >= count) {
                s_count = count;
            } else {
                s_count = sv.size() - begin;
            }
        } else {
            s_begin = sv.s_begin;
            s_count = 0;
        }
    }

    size_t length() const { return s_count; }

    size_t size() const { return s_count; }

    const char &operator[](size_t idx) const {
        if (idx >= s_count) {
            throw std::out_of_range("");
        }

        return (*str_view)[s_begin + idx];
    }

    char &operator[](size_t idx) {
        if (idx >= s_count) {
            throw std::out_of_range("");
        }

        return (*str_view)[s_begin + idx];
    }

    std::string str(size_t begin = 0, size_t count = std::string::npos) const {
        if (begin > s_count) {
            begin = s_count;
            count = 0;
        }

        if (begin + count > s_count) {
            count = s_count - begin;
        }

        return str_view->substr(s_begin + begin, count);
    }

    using iterator = std::string::iterator;
    using const_iterator = std::string::const_iterator;
    using reverse_iterator = std::string::reverse_iterator;
    using const_reverse_iterator = std::string::const_reverse_iterator;

    iterator begin() const { return str_view->begin() + s_begin; }

    iterator end() const { return str_view->begin() + s_begin + s_count; }

    const_iterator cbegin() const { return str_view->cbegin() + s_begin; }

    const_iterator cend() const { return str_view->cbegin() + s_begin + s_count; }

    reverse_iterator rbegin() const { return str_view->rend() - s_begin - s_count; }

    reverse_iterator rend() const { return str_view->rend() - s_begin; }

    const_reverse_iterator crbegin() const { return str_view->crend() - s_begin - s_count; }

    const_reverse_iterator crend() const { return str_view->crend() - s_begin; }

    char &at(size_t idx) {
        if (idx >= s_count) {
            throw std::out_of_range("");
        }

        return str_view->at(s_begin + idx);
    }

    const char &at(size_t idx) const {
        if (idx >= s_count) {
            throw std::out_of_range("");
        }

        return str_view->at(s_begin + idx);
    }

    bool operator==(const StringView &str) const {
        std::string str1 = str_view->substr(s_begin, s_count);
        std::string str2 = str.str_view->substr(str.s_begin, str.s_count);

        return str1 == str2;
    }

    bool operator!=(const StringView &str) const {
        return !(*this == str);
    }

    bool operator<(const StringView &str) const {
        std::string str1 = str_view->substr(s_begin, s_count);
        std::string str2 = str.str_view->substr(str.s_begin, str.s_count);

        return str1 < str2;
    }

    bool operator>(const StringView &str) const {
        return str < *this;
    }

    bool operator<=(const StringView &str) const {
        return !(*this > str);
    }

    bool operator>=(const StringView &str) const {
        return !(*this < str);
    }

private:
    std::string *str_view;
    size_t s_begin;
    size_t s_count;
};

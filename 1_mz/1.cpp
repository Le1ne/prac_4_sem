class Sum {
public:
    Sum(long long a, long long b): a_(a), b_(b) {}
    Sum(Sum s, long long c): a_(s.get()), b_(c) {}
    long long get() const {
        return a_ + b_;
    }     
private:
    long long a_;
    long long b_;
};

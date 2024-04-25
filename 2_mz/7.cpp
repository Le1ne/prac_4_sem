#include <vector>
#include <iterator>

class Matrix {
public:
    Matrix() {
        matrix = std::vector<std::vector<int>>(3, std::vector<int>(3));
    }

    int &operator[](int i, int j) {
        return matrix[i][j];
    }

    std::vector<std::vector<int>>::iterator begin() {
        return matrix.begin();
    }

    std::vector<std::vector<int>>::iterator end() {
        return matrix.end();
    }

private:
    std::vector<std::vector<int>> matrix;
};

#include <iostream>

namespace Game {
    template<class Type>
    class Coord {
    public:
        typedef Type value_type;
        Type row;
        Type col;

        Coord(Type row = value_type(), Type col = value_type()) : row(row), col(col) {}
    };

    template<class Type>
    typename Type::value_type dist(const Type &dimension, const Type &first_coord, const Type &second_coord) {
        typename Type::value_type dx = second_coord.col - first_coord.col;
        typename Type::value_type dy = second_coord.col / 2 - first_coord.col / 2 + second_coord.row - first_coord.row;
        typename Type::value_type a_dx = abs(dx);
        typename Type::value_type a_dy = abs(dy);

        if ((dx < 0 && dy < 0) || (dx >= 0 && dy >= 0)) {
            return std::max(a_dx, a_dy);
        } else {
            return a_dx + a_dy;
        }
    }
};

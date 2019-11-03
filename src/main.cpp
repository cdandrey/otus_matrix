
#include "../lib/matrix.h"

#include <iostream>
#include <cassert>

int main(int,char**)
{
    Matrix<double, -1> matrix;
    assert(matrix.size() == 0);

    auto a = matrix[0][0];
    assert(a == -1);
    assert(matrix.size() == 0);

    matrix[100][100] = 333;

    assert(matrix[100][100] == 333);
    assert(matrix.size() == 1);

    matrix[0][0] = 111;
    matrix[99][1000] = 222;
    matrix[100][101] = 444;

    for (auto x : matrix)
        std::cout << x << std::endl;

    return 0;
}

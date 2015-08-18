// @mission: 计算两个稀疏矩阵相加

#include "common/matrix2.h"
using namespace mustard;

typedef matrix::sparse_matrix<int> matrix_t;

matrix_t add(const matrix_t & a, const matrix_t & b);

int main()
{
    matrix_t * a = matrix::read_sparse_matrix<int>();
    matrix_t * b = matrix::read_sparse_matrix<int>();

    matrix_t c = add(*a, *b);

    matrix::print_as_common(c);

    delete a;
    delete b;

    return 0;
}

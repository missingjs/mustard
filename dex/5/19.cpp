// @mission: 寻找矩阵中的马鞍点，既是第i行最小值，同时也是第j列最大值

#include "common/matrix2.h"
using namespace mustard;

typedef matrix::common_matrix<int> matrix_t;

void print_saddle_points(const matrix_t & m);

int main()
{
    matrix_t * m = matrix::read_common_matrix<int>();

    print_saddle_points(*m);

    delete m;
    return 0;
}

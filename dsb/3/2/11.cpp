// @brief: 输出迷宫全部路径，并求解最短路径及其长度

#include "common/matrix.h"
using namespace mustard;

typedef mtx::matrix<int> matrix_t;

void print_path(matrix_t * m, int start_row, int start_col);

int main()
{
    matrix_t * m = mtx::read<int>();

    int sr = 0, sc = 0;
    std::cin >> sr >> sc;

    print_path(m, sr, sc);

    mtx::free(m);

    return 0;
}

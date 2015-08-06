// @brief: 输出迷宫全部路径，并求解最短路径及其长度

#include "common/matrix.h"
using namespace mustard;

typedef mtx::matrix<int> matrix_t;

// 提供起点和终点
void print_path(matrix_t * m, int br, int bc, int er, int ec);

int main()
{
    matrix_t * m = mtx::read<int>();

    int br = 0, bc = 0, er = 0, ec = 0;
    std::cin >> br >> bc >> er >> ec;

    print_path(m, br, bc, er, ec);

    mtx::free(m);

    return 0;
}

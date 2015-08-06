// @brief: 利用队列求解迷宫，输出所有最短路径

#include "common/matrix.h"
using namespace mustard;

typedef mtx::matrix<int> matrix_t;

void show_path(matrix_t * m, int br, int bc, int er, int ec);

int main()
{
    matrix_t * m = mtx::read<int>();

    int br,bc,er,ec;
    std::cin >> br >> bc >> er >> ec;

    show_path(m, br, bc, er, ec);

    mtx::free(m);

    return 0;
}

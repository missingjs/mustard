// @mission: 解决迷宫问题，输出所有路径，并指出一条最短路径。先用递归形式实现，再改写为非递归

#include "common/matrix.h"
using namespace mustard;

typedef mtx::matrix<int> matrix_t;

void show_path(matrix_t * m, int br, int bc, int er, int ec);

void show_path_2(matrix_t * m, int br, int bc, int er, int ec);

int main()
{
    matrix_t * m = mtx::read<int>();

    int br, bc, er, ec;
    std::cin >> br >> bc >> er >> ec;

    show_path(m, br, bc, er, ec);

    show_path_2(m, br, bc, er, ec);

    mtx::free(m);

    return 0;
}

// @mission: 实现树形选择排序
#include "trees.def.h"
#include "common/array.h"
using namespace mustard;

int main()
{
    int n = 0;
    int * arr = array::read<int>(n);

    int len = 0;
    _ts * t = build_complete_tree(arr, n, len);

    tree_select_output(t, len, arr, n);

    array::print(arr, n);

    delete[] arr;
    delete[] t;
    return 0;
}

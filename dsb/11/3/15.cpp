// @mission: 非递归实现快速排序
#include "15.def.h"
#include "common/array.h"
using namespace mustard;

int main()
{
    int n = 0;
    int * arr = array::read<int>(n);

    non_recursive_qsort(arr, n);

    array::print(arr, n);

    delete[] arr;
    return 0;
}

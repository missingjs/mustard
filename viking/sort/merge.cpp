// @mission: 实现归并排序
#include "merge.def.h"
#include "common/array.h"
using namespace mustard;

int main()
{
    int n = 0;
    int * arr = array::read<int>(n);

    merge_sort(arr, n);

    array::print(arr, n);

    delete[] arr;
    return 0;
}

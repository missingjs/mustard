// @mission: 实现快速排序
#include "quick.def.h"
#include "common/array.h"
using namespace mustard;

int main()
{
    int n = 0;
    int * arr = array::read<int>(n);

    quick_sort(arr, n);

    array::print(arr, n);

    delete[] arr;
    return 0;
}

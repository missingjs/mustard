// @mission: 实现基数排序，参加排序的整数大于0,小于1000
#include "radix.def.h"
#include "common/array.h"
using namespace mustard;

int main()
{
    int n = 0;
    int * arr = array::read<int>(n);

    radix_sort(arr, n);

    array::print(arr, n);

    delete[] arr;
    return 0;
}

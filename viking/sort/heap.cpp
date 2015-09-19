// @mission: 实现堆排序
#include "heap.def.h"
#include "common/array.h"
using namespace mustard;

int main()
{
    int n = 0;
    int * arr = array::read<int>(n);

    heap_sort(arr, n);

    array::print(arr, n);

    delete[] arr;
    return 0;
}

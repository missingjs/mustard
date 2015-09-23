// @mission: 基于队列实现快速排序算法
#include "16.def.h"
#include "common/array.h"
using namespace mustard;

int main()
{
    int n = 0;
    int * arr = array::read<int>(n);

    qsort_based_on_queue(arr, n);

    array::print(arr, n);

    delete[] arr;
    return 0;
}

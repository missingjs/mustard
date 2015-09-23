// @mission: 实现双向冒泡排序算法
#include "14.def.h"
#include "common/array.h"
using namespace mustard;

int main()
{
    int n = 0;
    int * arr = array::read<int>(n);

    bi_directional_bubble_sort(arr, n);

    array::print(arr, n);

    delete[] arr;
    return 0;
}

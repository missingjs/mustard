// @mission: 实现冒泡排序
#include "bubble.def.h"
#include "common/array.h"
using namespace mustard;

int main()
{
    int n = 0;
    int * arr = array::read<int>(n);

    bubble_sort(arr, n);

    array::print(arr, n);

    delete[] arr;

    return 0;
}

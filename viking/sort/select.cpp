// @mission: 实现简单选择排序
#include "select.def.h"
#include "common/array.h"
using namespace mustard;

int main()
{
    int n = 0;
    int * arr = array::read<int>(n);

    select_sort(arr, n);

    array::print(arr, n);

    delete[] arr;
    return 0;
}

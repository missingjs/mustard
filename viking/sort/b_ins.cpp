// @mission: 实现二分插入排序
#include "b_ins.def.h"
#include "common/array.h"
using namespace mustard;

int main()
{
    int n = 0;
    int * arr = array::read<int>(n);

    b_ins_sort(arr, n);

    array::print(arr, n);

    delete[] arr;
    return 0;
}

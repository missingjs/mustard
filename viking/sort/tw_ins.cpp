// @mission: 实现2-路插入排序
#include "tw_ins.def.h"
#include "common/array.h"
using namespace mustard;

int main()
{
    int n = 0;
    int * arr = array::read<int>(n);

    tw_ins_sort(arr, n);

    array::print(arr, n);

    delete[] arr;
    return 0;
}

// @mission: 实现计数排序。对每个元素，扫描整个数组，统计出有多少个元素比该元素小，根据个数可确定排序后的位置
#include "21.def.h"
#include "common/array.h"
using namespace mustard;

int main()
{
    int n = 0;
    int * arr = array::read<int>(n);

    counter_sort(arr, n);

    array::print(arr, n);

    delete[] arr;
    return 0;
}

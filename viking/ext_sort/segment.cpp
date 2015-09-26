// @mission: 给定内存可容纳的最大记录数，利用堆排序实现置换-选择算法，将输入序列分成若干有序子序列
#include "segment.def.h"
#include "common/array.h"
using namespace mustard;

int main()
{
    int n = 0;
    int * arr = array::read<int>(n);

    int m = 0;
    std::cin >> m;

    segment(arr, n, m);

    delete[] arr;
    return 0;
}

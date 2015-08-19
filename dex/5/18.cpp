// @mission: 实现将数组循环右移k位，元素移动或交换复杂度为O(n)，n为数组长度

void shift(int * arr, int len, int k);

#include "common/array.h"
using namespace mustard;

int main()
{
    int len = 0;
    int * arr = array::read<int>(len);

    int k = 0;
    std::cin >> k;

    shift(arr, len, k);

    array::print(arr, len);

    array::free(arr);

    return 0;
}

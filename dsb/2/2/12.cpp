// @brief: 从顺序表中删除所有值为x的元素, 要求空间复杂度为O(1)
// @return: 返回处理后数的长度
int remove_x(int * arr, int len, int x);

#include <iostream>
#include "common/array.h"
using namespace mustard;

int main()
{
    int len = 0;
    std::cin >> len;

    int * arr = array_read<int>(len);

    int x = 0;
    std::cin >> x;

    int new_len = remove_x(arr, len, x);

    array_print(arr, new_len);

    return 0;
}


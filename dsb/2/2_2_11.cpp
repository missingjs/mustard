// @brief: 将顺序表所有元素逆置
void reverse(int * arr, int len);

#include <iostream>
#include "common/array.h"
using namespace mustard;

int main()
{
    int len = 0;
    std::cin >> len;

    int * arr = array_read<int>(len);
    reverse(arr, len);

    array_print(arr, len);

    return 0;
}


// @brief: 顺序表L，元素为整形数据，将L中所有小于0元素放在前半部分，大于等于0元素放于后半部
void z_partition(int * arr, int len);

#include <iostream>
#include "common/array.h"
using namespace mustard;

int main()
{
    int * arr = NULL;
    int len = 0;

    arr = array_n_read<int>(len);

    z_partition(arr, len);

    array_print(arr, len);

    array_free(arr);

    return 0;
}


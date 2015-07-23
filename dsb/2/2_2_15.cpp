// @brief: 从顺序表中删除重复元素，并使剩余元素间的相对次序保持不变
// @return: 处理后数组长度
int unify(int * arr, int len);

#include <iostream>
#include "common/array.h"
using namespace mustard;

int main()
{
    int * arr = NULL, len = 0;

    arr = array_n_read<int>(len);

    len = unify(arr, len);

    array_print(arr, len);

    array_free(arr);

    return 0;
}


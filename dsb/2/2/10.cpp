#include <iostream>
#include <cstring>
#include "common/array.h"
using namespace mustard;

// !!!
// arr数组内元素递增有序排列，将x插入其中
// 返回插入x后数组的长度
int insert(int * arr, int len, int x);

int main()
{
    int *arr = NULL, len = 0;
    arr = array_n_read<int>(len);

    if (len > 0) {
        int * new_arr = new int[len+1];
        memcpy(new_arr, arr, len * sizeof(int));
        array_free(arr);
        arr = new_arr;
    }

    int x = 0;
    std::cin >> x;

    len = insert(arr, len, x);

    array_print(arr, len);

    return 0;
}

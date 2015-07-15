#include <iostream>

#include "common/array.h"
using namespace mustard;

void reverse(int * arr, int len);

int main()
{
    int len = 0;
    std::cin >> len;

    int * arr = array_read<int>(len);
    reverse(arr, len);

    array_print(arr, len);

    return 0;
}

void reverse(int * arr, int len)
{
    if (arr == NULL || len < 0) {
        return;
    }

    int mid = len / 2;
    int temp = 0;
    for (int i = 0; i < mid; ++i) {
        temp = arr[i];
        arr[i] = arr[len - 1 - i];
        arr[len - 1 - i] = temp;
    }
}

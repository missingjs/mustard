#include <iostream>
#include "common/array.h"
using namespace mustard;

void z_partition(int * arr, int len);

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

void z_partition(int * arr, int len)
{
    if (arr == NULL || len <= 0) {
        return;
    }

    int i = 0, j = len - 1;
    int temp = 0;
    while (i < j) {
        while (i < j && arr[i] < 0) {
            ++i;
        }
        while (i < j && arr[j] >= 0) {
            --j;
        }
        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}

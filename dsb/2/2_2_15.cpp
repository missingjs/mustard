#include <iostream>
#include "common/array.h"
using namespace mustard;

int unify(int * arr, int len);

int main()
{
    int * arr = NULL, len = 0;

    arr = array_n_read<int>(len);

    len = unify(arr, len);

    array_print(arr, len);

    array_free(arr);

    return 0;
}

int unify(int * arr, int len)
{
    if (arr == NULL || len <= 0) {
        return 0;
    }

    int i = 0, j = 1;
    while (j < len) {
        int k = 0;
        for (; k <= i; ++k) {
            if (arr[k] == arr[j]) {
                break;
            }
        }
        if (k > i) {
            if (k != j) {
                arr[k] = arr[j];
            }
            ++i;
        }
        ++j;
    }
    return (i+1);
}

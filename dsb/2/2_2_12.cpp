#include <iostream>

#include "common/array.h"
using namespace mustard;

int remove_x(int * arr, int len, int x);

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

int remove_x(int * arr, int len, int x)
{
    if (arr == NULL || len <= 0) {
        return 0;
    }

    /*
    int k = 0;
    for (int i = 0; i < len; ++i) {
        if (arr[i] != x) {
            if (k > 0) {
                arr[i-k] = arr[i];
            }
        } else {
            ++k;
        }
    }

    return len - k;
    */

    int p = 0;
    for (int i = 0; i < len; ++i) {
        if (arr[i] != x) {
            if (i != p) {
                arr[p] = arr[i];
            }
            ++p;
        }
    }
    return p;
}

#include "b_ins.def.h"
#include <iostream>

int _find_pos(int * arr, int low, int high, int k)
{
    int mid = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (k == arr[mid]) {
            return mid;
        }
        else if (k < arr[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}

void b_ins_sort(int * arr, int n)
{
    if (!arr || n <= 0) {
        return;
    }

    for (int i = 1; i < n; ++i) {
        int j = _find_pos(arr, 0, i - 1, arr[i]);
        if (j != i) {
            int t = arr[i];
            for (int k = i - 1; k >= j; --k) {
                arr[k+1] = arr[k];
            }
            arr[j] = t;
        }
    }
}

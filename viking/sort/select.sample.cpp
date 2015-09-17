#include "select.def.h"

void select_sort(int * arr, int n)
{
    if (!arr || n <= 0) {
        return;
    }

    int i = 0, tmp = 0;
    while (i < n - 1) {
        int mi = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[mi]) {
                mi = j;
            }
        }
        tmp = arr[i];
        arr[i] = arr[mi];
        arr[mi] = tmp;
        ++i;
    }
}

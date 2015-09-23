#include "21.def.h"

int _count(int * arr, int n, int k)
{
    int c = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < k) {
            ++c;
        }
    }
    return c;
}

void counter_sort(int * arr, int n)
{
    if (!arr || n <= 1) {
        return;
    }

    int * b = new int[n];
    bool * c = new bool[n];
    for (int i = 0; i < n; ++i) {
        b[i] = false;
    }

    for (int i = 0; i < n; ++i) {
        int k = _count(arr, n, arr[i]);
        while (c[k]) {
            ++k;
        }
        b[k] = arr[i];
        c[k] = true;
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = b[i];
    }

    delete[] b;
    delete[] c;
}

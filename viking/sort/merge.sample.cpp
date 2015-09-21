#include "merge.def.h"
#include <cstring>

void _merge(int * a, int ai, int aj,
        int * b, int bi, int bj,
        int * c)
{
    int ap = ai, bp = bi, cp = 0;
    while (ap < aj && bp < bj) {
        if (a[ap] < b[bp]) {
            c[cp++] = a[ap++];
        }
        else {
            c[cp++] = b[bp++];
        }
    }
    while (ap < aj) {
        c[cp++] = a[ap++];
    }
    while (bp < bj) {
        c[cp++] = b[bp++];
    }
}

void _ms(int * arr, int * d, int i, int j)
{
    if (j - i <= 0) {
        return;
    }

    int mid = (i + j) / 2;

    _ms(arr, d, i, mid);
    _ms(arr, d, mid + 1, j);

    _merge(arr, i, mid + 1, arr, mid + 1, j + 1, d);
    memcpy(arr + i, d, sizeof(int) * (j-i+1));
}

void merge_sort(int * arr, int n)
{
    if (!arr || n <= 1) {
        return;
    }

    int * d = new int[n];
    memcpy(d, arr, sizeof(int) * n);

    _ms(arr, d, 0, n - 1);

    delete[] d;
}

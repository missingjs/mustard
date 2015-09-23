#include "16.def.h"
#include <queue>

struct _qs
{
    int i, j;
    _qs(int i = -1, int j = -1)
        : i(i), j(j)
    {}
};

int _partition(int * arr, int i, int j)
{
    int k = arr[i];

    while (i < j) {
        while (i < j && arr[j] > k) {
            --j;
        }
        if (i != j) {
            arr[i] = arr[j];
        }
        while (i < j && arr[i] <= k) {
            ++i;
        }
        if (i != j) {
            arr[j] = arr[i];
        }
    }
    arr[i] = k;
    return i;
}

void qsort_based_on_queue(int * arr, int n)
{
    if (!arr || n <= 1) {
        return;
    }

    std::queue<_qs> qu;
    qu.push(_qs(0, n-1));

    while (!qu.empty()) {
        _qs f = qu.front();
        qu.pop();
        int p = _partition(arr, f.i, f.j);
        if (p - f.i > 1) {
            qu.push(_qs(f.i, p - 1));
        }
        if (f.j - p > 1) {
            qu.push(_qs(p + 1, f.j));
        }
    }
}

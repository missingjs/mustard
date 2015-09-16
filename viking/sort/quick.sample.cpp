#include "quick.def.h"


int _partition(int * arr, int i, int j)
{
    int pv = arr[i];

    int low = i, high = j - 1;
    while (low < high) {
        for (; low < high && arr[high] > pv; --high)
            ;;
        arr[low] = arr[high];
        for (; low < high && arr[low] <= pv; ++low)
            ;;
        arr[high] = arr[low];
    }
    arr[high] = pv;
    return high;
}

void _qsort(int * arr, int i, int j)
{
    if (j - i <= 1) {
        return;
    }

    int p = _partition(arr, i, j);
    _qsort(arr, i, p);
    _qsort(arr, p + 1, j);
}

void quick_sort(int * arr, int n)
{
    if (!arr || n <= 0) {
        return;
    }

    _qsort(arr, 0, n);
}

#include "shell.def.h"
#include "common/array.h"
using namespace mustard;

void _insert_sort(int * arr, int n, int d)
{
    for (int i = d; i < n; i += d) {
        int j = i - d;
        for (; j >= 0 && arr[j] > arr[i]; j -= d)
            ;;
        int t = arr[i];
        for (int k = i - d; k > j; k -= d) {
            arr[k + d] = arr[k];
        }
        arr[j + d] = t;
    }
}

void shell_sort(int * arr, int n, int * delt, int k)
{
    for (int i = 0; i < k; ++i) {
        _insert_sort(arr, n, delt[i]);
    }
}

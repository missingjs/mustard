#include "tw_ins.def.h"
#include "common/array.h"
using namespace mustard;

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

void tw_ins_sort(int * arr, int n)
{
    if (!arr || n <= 0) {
        return;
    }

    int * d = new int[n];

    d[0] = arr[0];

    int first = 0, last = 1;

    for (int i = 1; i < n; ++i) {
        if (arr[i] > d[0]) {
            int p = _find_pos(d, 0, last - 1, arr[i]);
            for (int k = last - 1; k >= p; --k) {
                d[k+1] = d[k];
            }
            d[p] = arr[i];
            ++last;
        }
        else {
            if (first == 0) {
                d[n-1] = arr[i];
                first = n-1;
            }
            else {
                int p = _find_pos(d, first, n - 1, arr[i]);
                for (int k = first; k < p; ++k) {
                    d[k-1] = d[k];
                }
                d[p-1] = arr[i];
                --first;
            }
        }
    }
//    array::print(d, n);

    int i = 0, j = first;
    for (; j < n; ++j, ++i) {
        arr[i] = d[j];
    }

    for (j = 0; j < last; ++j, ++i) {
        arr[i] = d[j];
    }

    delete[] d;
}

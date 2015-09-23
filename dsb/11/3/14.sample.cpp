#include "14.def.h"

void bi_directional_bubble_sort(int * arr, int n)
{
    if (!arr || n <= 1) {
        return;
    }

    int low = 0, high = n-1, i, tmp;
    while (low < high) {
        for (i = low; i < high; ++i) {
            if (arr[i] > arr[i+1]) {
                tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
            }
        }
        --high;

        for (i = high; i > low; --i) {
            if (arr[i] < arr[i-1]) {
                tmp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = tmp;
            }
        }
        ++low;
    }
}

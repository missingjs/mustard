#include "bubble.def.h"

void bubble_sort(int * arr, int n)
{
    if (!arr || n <= 0) {
        return;
    }

    int tmp = 0;

    for (int end = n; end > 1; --end) {
        for (int i = 0; i < end - 1; ++i) {
            if (arr[i] > arr[i+1]) {
                tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
            }
        }
    }
}

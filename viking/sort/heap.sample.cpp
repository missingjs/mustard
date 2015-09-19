#include "heap.def.h"
#include "common/array.h"
using namespace mustard;

void _adjust_heap(int * h, int s, int N)
{
    int L = 0, R = 0, tmp = 0, K = 0;
    while ((s << 1) <= N) {
        L = s * 2;
        R = L + 1;

        if (R <= N) {
            K = (h[L] > h[R]) ? L : R;
        }
        else {
            K = L;
        }

        if (h[s] < h[K]) {
            tmp = h[s];
            h[s] = h[K];
            h[K] = tmp;
        }
        else {
            break;
        }
        s = K;
    }
}

void _make_heap(int * h, int N)
{
    for (int i = N / 2; i > 0; --i) {
        _adjust_heap(h, i, N);
    }
}

void heap_sort(int * arr, int n)
{
    if (!arr || n <= 1) {
        return;
    }

    _make_heap(arr - 1, n);

    int last = n - 1, tmp = 0;
    while (true) {
        tmp = arr[0];
        arr[0] = arr[last];
        arr[last] = tmp;
        --last;
        if (last <= 1) {
            break;
        }
        _adjust_heap(arr - 1, 1, last + 1);
    }
}

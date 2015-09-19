#include "heap2.def.h"

void _adjust(int * h, int s, int N)
{
    int L, R, K, tmp;
    while ((s << 1) <= N) {
        L = s << 1;
        R = L + 1;
        if (R <= N) {
            K = (h[L] <= h[R]) ? L : R;
        }
        else {
            K = L;
        }

        if (h[s] > h[K]) {
            tmp = h[s];
            h[s] = h[K];
            h[K] = tmp;
            s = K;
        }
        else {
            break;
        }
    }
}

void make_heap(int * h, int N)
{
    if (!h || N <= 1) {
        return;
    }

    for (int i = N / 2; i > 0; --i) {
        _adjust(h, i, N);
    }
}

void push_heap(int * h, int N, int i)
{
    int j = N + 1;
    h[j] = i;

    int tmp;
    while (j > 1) {
        if (h[j] < h[j/2]) {
            tmp = h[j];
            h[j] = h[j/2];
            h[j/2] = tmp;
            j /= 2;
        }
        else {
            break;
        }
    }
}

int pop_heap(int * h, int N)
{
    int r = h[1];
    if (N == 1) {
        return r;
    }

    int tmp;
    tmp = h[N];
    h[N] = h[1];
    h[1] = tmp;

    _adjust(h, 1, N-1);

    return r;
}


#include "segment.def.h"
#include <iostream>

void _adjust_heap(int * h, int n, int s)
{
    while ((s << 1) <= n) {
        int L = s << 1, R = L + 1;
        int t;
        if (R > n || h[L] < h[R]) {
            t = L;
        }
        else {
            t = R;
        }

        if (h[t] < h[s]) {
            int tmp = h[t];
            h[t] = h[s];
            h[s] = tmp;
            s = t;
        }
        else {
            break;
        }
    }
}

void _make_heap(int * h, int n)
{
    for (int i = n/2; i > 0; --i) {
        _adjust_heap(h, n, i);
    }
}

void segment(int * arr, int n, int m)
{
    if (!arr || n <= 0 || n <= m) {
        return;
    }

    int * h = new int[m];
    --h;

    int i = 0;
    // init heap
    for (int j = 1; j <= m; ++j, ++i) {
        h[j] = arr[i];
    }

    while (i < n) {
        _make_heap(h, m);

        int mini = h[1];
        int k = m, next = 0;
        while (k > 0 && i < n) {
            std::cout << h[1] << ' ';
            next = arr[i++];
            if (next > mini) {
                h[1] = next;
            }
            else {
                h[1] = h[k];
                --k;
                h[k+1] = next;
            }
            _adjust_heap(h, k, 1);
        }

        while (k > 0) {
            std::cout << h[1] << ' ';
            h[1] = h[k];
            --k;
            _adjust_heap(h, k, 1);
        }
        std::cout << '\n';
    }

    delete[] (h+1);
}

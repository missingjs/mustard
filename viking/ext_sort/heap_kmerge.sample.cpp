#include "heap_kmerge.def.h"
#include "lose_tree.sample.cpp"

void _adjust(int * heap, int k, int i, Array * group)
{
    int p = 0, t = 0;
    while (i * 2 <= k) {
        int L = i * 2, R = L + 1;
        if (R > k) {
            p = L;
        }
        else if (group[heap[L]].get() < group[heap[R]].get()) {
            p = L;
        }
        else {
            p = R;
        }

        if (group[heap[p]].get() < group[heap[i]].get()) {
            t = heap[p];
            heap[p] = heap[i];
            heap[i] = t;
            i = p;
        }
        else {
            break;
        }
    }
}

void kmerge_by_heap(Array * group, int k, int * output)
{
    int * heap = new int[k+1];

    for (int i = 0; i < k; ++i) {
        heap[i+1] = i;
    }

    for (int j = k/2; j > 1; --j) {
        _adjust(heap, k, j, group);
    }

    int size = k, p = 0;
    int MAX = std::numeric_limits<int>::max();
    int v = 0;
    while ((v = group[heap[1]].get()) < MAX) {
        output[p++] = group[heap[1]].get();
        group[heap[1]].next();
        _adjust(heap, size, 1, group);
    }
}

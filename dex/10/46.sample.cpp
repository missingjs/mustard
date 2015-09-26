#include "46.def.h"

int _partition(node_t ** arr, int i, int j)
{
    node_t * pv = arr[i];
    int d = pv->data;
    while (i < j) {
        while (i < j && arr[j]->data > d) {
            --j;
        }
        if (i != j) {
            arr[i] = arr[j];
        }
        while (i < j && arr[i]->data <= d) {
            ++i;
        }
        if (i != j) {
            arr[j] = arr[i];
        }
    }
    arr[i] = pv;
    return i;
}

void _qsort(node_t ** arr, int i, int j)
{
    if (i >= j) {
        return;
    }

    int k = _partition(arr, i, j);
    _qsort(arr, i, k - 1);
    _qsort(arr, k + 1, j);
}

int _len(node_t * h)
{
    int i = 0;
    node_t * p = h;

    while (p) {
        ++i;
        p = p->next;
    }
    return i;
}

node_t * list_qsort(node_t * h)
{
    int n = _len(h);

    node_t ** arr = new node_t*[n];
    int i = 0;
    node_t * p = h;
    while (i < n) {
        arr[i++] = p;
        p = p->next;
    }

    _qsort(arr, 0, n - 1);

    node_t head, *last = &head;
    for (int i = 0; i < n; ++i) {
        last->next = arr[i];
        last = arr[i];
    }
    last->next = NULL;

    delete[] arr;
    return head.next;
}

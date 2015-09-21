#include "radix.def.h"
#include <cstddef>
#include <cstring>

struct rd
{
    int i;
    rd * next;
    rd(int i = 0)
        : i(i), next(NULL)
    {}
};

struct rd_head
{
    rd * first;
    rd * last;
    rd_head()
        : first(NULL), last(NULL)
    {}
};

rd * _to_list(int * arr, int n)
{
    rd head, *last = &head;
    for (int i = 0; i < n; ++i) {
        last->next = new rd(arr[i]);
        last = last->next;
    }
    return head.next;
}

int _get_k(int num, int bit)
{
    int i = 0, r = 0;
    while (i <= bit) {
        r = num % 10;
        num /= 10;
        ++i;
    }
    return r;
}

void _dump(rd * h, int * arr)
{
    int i = 0;
    for (rd * p = h; p; p = p->next) {
        arr[i++] = p->i;
    }
}

void _destroy(rd * h)
{
    rd * p = NULL;
    while (h) {
        p = h;
        h = h->next;
        delete p;
    }
}

void radix_sort(int * arr, int n)
{
    if (!arr || n <= 1) {
        return;
    }

    rd L;
    L.next = _to_list(arr, n);

    rd_head * head = new rd_head[10];
    memset(head, 0, sizeof(rd_head) * 10);

    for (int d = 0; d < 3; ++d) {
        for (rd * p = L.next; p; ) {
            rd * r = p;
            p = p->next;
            int k = _get_k(r->i, d);
            if (head[k].last) {
                head[k].last->next = r;
                head[k].last = r;
            }
            else {
                head[k].first = head[k].last = r;
            }
        }

        rd * last = &L;
        for (int j = 0; j < 10; ++j) {
            if (head[j].first) {
                last->next = head[j].first;
                last = head[j].last;
                head[j].first = head[j].last = NULL;
            }
        }
        last->next = NULL;
    }

    _dump(L.next, arr);

    _destroy(L.next);
}

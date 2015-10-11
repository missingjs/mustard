#include <cstddef>

#include "poly.cpp"

void _insert(poly_t & head, poly_t * n)
{
    poly_t * p = &head;
    while (p->next && p->next->e > n->e) {
        p = p->next;
    }

    if (p->next) {
        if (p->next->e == n->e) {
            p->next->c += n->c;
            delete n;
        }
        else {
            n->next = p->next;
            p->next = n;
        }
    }
    else {
        p->next = n;
    }
}

poly_t * multiply_a(poly_t * p1, poly_t * p2)
{
    if (!p1 || !p2) {
        return NULL;
    }

    poly_t head;

    for (poly_t * t1 = p1; t1; t1 = t1->next) {
        for (poly_t * t2 = p2; t2; t2 = t2->next) {
            int c = t1->c * t2->c;
            int e = t1->e + t2->e;
            poly_t * n = new poly_t(c,e);
            _insert(head, n);
        }
    }

    return head.next;
}

void _merge(poly_t & h1, poly_t & h2)
{
    poly_t H, *last = &H;
    poly_t *p1 = h1.next, *p2 = h2.next;
    poly_t * t = NULL;
    while (p1 && p2) {
        if (p1->e > p2->e) {
            t = p1;
            p1 = p1->next;
        }
        else if (p1->e < p2->e) {
            t = p2;
            p2 = p2->next;
        }
        else {
            t = p1;
            p1 = p1->next;
            t->c += p2->c;
            poly_t * T = p2;
            p2 = p2->next;
            delete T;
        }
        last->next = t;
        last = t;
    }
    if (p1) {
        last->next = p1;
    }
    else if (p2) {
        last->next = p2;
    }
    h1.next = H.next;
}

poly_t * multiply_b(poly_t * p1, poly_t * p2)
{
    if (!p1 || !p2) {
        return NULL;
    }

    poly_t h1;
    for (poly_t * t1 = p1; t1; t1 = t1->next) {
        poly_t h2, *last = &h2;
        for (poly_t * t2 = p2; t2; t2 = t2->next) {
            int c = t1->c * t2->c;
            int e = t1->e + t2->e;
            poly_t * n = new poly_t(c,e);
            last->next = n;
            last = n;
        }
        _merge(h1, h2);
    }

    return h1.next;
}

struct _P
{
    int e;
    poly_t * py;
    _P(int e = 0, poly_t * py = NULL)
        : e(e), py(py)
    {}
};

int _partition(_P * arr, int i, int j)
{
    _P t = arr[i];
    while (i < j) {
        while (i < j && arr[j].e <= t.e) {
            --j;
        }
        arr[i] = arr[j];
        while (i < j && arr[i].e > t.e) {
            ++i;
        }
        arr[j] = arr[i];
    }
    arr[i] = t;
    return i;
}

void _qsort(_P * arr, int i, int j)
{
    if (i >= j) {
        return;
    }

    int pv = _partition(arr, i, j);
    _qsort(arr, i, pv - 1);
    _qsort(arr, pv + 1, j);
}

poly_t * multiply_c(poly_t * p1, poly_t * p2)
{
    if (!p1 || !p2) {
        return NULL;
    }

    poly_t head, *last = &head;
    int C = 0;
    for (poly_t * t1 = p1; t1; t1 = t1->next) {
        for (poly_t * t2 = p2; t2; t2 = t2->next) {
            int c = t1->c * t2->c;
            int e = t1->e + t2->e;
            poly_t * n = new poly_t(c,e);
            last->next = n;
            last = n;
            ++C;
        }
    }

    _P * arr = new _P[C];
    int i = 0;
    for (poly_t * p = head.next; p; p = p->next, ++i) {
        arr[i].e = p->e;
        arr[i].py = p;
    }

    _qsort(arr, 0, C-1);

    i = 0;
    head.next = NULL, last = &head;
    while (i < C) {
        int j = i + 1;
        while (j < C && arr[j].e == arr[i].e) {
            arr[i].py->c += arr[j].py->c;
            delete arr[j].py;
            ++j;
        }
        last->next = arr[i].py;
        last = arr[i].py;
        i = j;
    }
    last->next = NULL;
    
    delete[] arr;
    return head.next;
}


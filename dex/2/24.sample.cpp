#include <stddef.h>
#include "common/slist.h"
using namespace mustard;

typedef slist::node<int> node_t;

node_t * merge_descend(node_t * a, node_t * b)
{
    node_t * h = NULL;
    node_t * t = NULL;
    node_t *pa = a, *pb = b;

    while (pa && pb) {
        if (pa->data < pb->data) {
            t = pa;
            pa = pa->next;
            t->next = h;
            h = t;
        } else if (pa->data > pb->data) {
            t = pb;
            pb = pb->next;
            t->next = h;
            h = t;
        } else {
            t = pb;
            pb = pb->next;
            t->next = h;
            h = t;
            t = pa;
            pa = pa->next;
            t->next = h;
            h = t;
        }
    }

    while (pa) {
        t = pa;
        pa = pa->next;
        t->next = h;
        h = t;
    }

    while (pb) {
        t = pb;
        pb = pb->next;
        t->next = h;
        h = t;
    }

    return h;

}

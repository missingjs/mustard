#include <stddef.h>
#include "common/dlist.h"
using namespace mustard;

typedef dlist::node<int> node_t;

node_t * swap_first(node_t * tail, int x)
{
    if (tail == NULL || tail->next == tail) {
        return tail;
    }

    node_t * head = tail->next;

    node_t * p = head;
    for (; p->data != x; ) {
        p = p->next;
        if (p == head) {
            break;
        }
    }

    if (p->data != x) {
        return tail;
    }

    node_t * q = p->next;

    if (q->next == p) { // only 2 nodes, and contains 'x'
        return tail->next;
    }

    node_t *p0 = p->prev, *q2 = q->next;
    
    p0->next = q;
    q->prev = p0;

    q2->prev = p;
    p->next = q2;

    q->next = p;
    p->prev = q;

    if (p == tail) {
        tail = q;
    } else if (q == tail) {
        tail = p;
    }

    return tail;
}

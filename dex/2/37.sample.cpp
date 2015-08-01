#include "common/dlist.h"
using namespace mustard;

typedef dlist::node<int> node_t;

void adjust(node_t * head)
{
    if (head == NULL || head->next == head) {
        return;
    }

    int c = 1;
    node_t * p = head->next;
    node_t * tail = head->prev;
    while (p != tail) {
        p = p->next;
        ++c;
        if (p == tail) {
            break;
        }

        node_t * t = p;
        p = p->next;
        ++c;

        node_t *q = t->prev, *p1 = t->next;
        q->next = p1;
        p1->prev = q;

        node_t * t1 = tail->next;
        tail->next = t1->prev = t;
        t->next = t1;
        t->prev = tail;
    }
}

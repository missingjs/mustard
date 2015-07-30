#include <stddef.h>
#include "common/dlist.h"
using namespace mustard;

typedef dlist::node<int> node_t;

node_t * reverse(node_t * tail)
{
    if (tail == NULL || tail->next == tail) {
        return tail;
    } else if (tail->next->next == tail) {
        return tail->next;
    }

    node_t * head = tail->next;
    node_t * q = head;

    node_t * p = head->next;
    tail->next = NULL;
    for (; p; ) {
        node_t * t = p;
        p = p->next;
        t->next = q;
        q->prev = t;
        q = t;
    }

    head->next = tail;
    tail->prev = head;

    return head;
}

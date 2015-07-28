#include <stddef.h>
#include "common/dlist.h"
using namespace mustard;

typedef dlist::node<int> node_t;

dlist::node<int> * find_first_and_swap(dlist::node<int> * n, int x)
{
    if (n == NULL) {
        return NULL;
    }

    node_t head;
    head.next = n;

    node_t * p = n;
    for (; p != NULL && p->data != x; p = p->next)
        ;;

    if (!p) {
        return n;
    }

    node_t * next = p->next;
    if (!next) {
        return n;
    }

    n->prev = &head;

    node_t *prev = p->prev;

    node_t *n2 = next->next;

    next->next = p;
    p->prev = next;

    next->prev = prev;
    prev->next = next;

    p->next = n2;
    if (n2) {
        n2->prev = p;
    }

    head.next->prev = NULL;
    return head.next;
}

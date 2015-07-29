#include <stddef.h>
#include "common/dlist.h"
#include "12.h"
using namespace mustard;

typedef dlist::node<cell> node_t;

node_t * locate_node(node_t * h, int data)
{
    if (h == NULL) {
        return NULL;
    }

    node_t head;
    head.next = h;
    h->prev = &head;

    node_t * p = h;
    for (; p && p->data.data != data; p = p->next)
        ;;

    if (p) {
        p->data.freq += 1;
        node_t * q = p->prev;
        for (; q != &head && q->data.freq < p->data.freq; q = q->prev)
            ;;
        if (q != p->prev) {
            node_t *p0 = p->prev, *p2 = p->next;
            p0->next = p2;
            if (p2) {
                p2->prev = p0;
            }

            node_t * q2 = q->next;
            q->next = p;
            p->next = q2;
            q2->prev = p;
            p->prev = q;
        }
    }

    head.next->prev = NULL;
    return head.next;
}

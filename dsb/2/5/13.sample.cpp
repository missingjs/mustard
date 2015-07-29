#include <stddef.h>
#include "common/slist.h"
using namespace mustard;

typedef slist::node<int> node_t;

slist::node<int> * reverse_circular_list(slist::node<int> * tail)
{
    if (tail == NULL) {
        return NULL;
    } else if (tail->next == tail) {
        return tail;
    }

    node_t * head = tail->next;

    // head of new reversed list
    node_t * p = head;

    // head of old partial list
    node_t * q = p->next;

    // init new reversed list
    head->next = tail;

    for (; q != head; ) {
        node_t * t = q;
        q = q->next;
        t->next = p;
        p = t;
    }

    return head;
}

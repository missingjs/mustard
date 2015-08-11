#include "common/slist.h"
using namespace mustard;

typedef slist::node<char> node_t;

node_t * replace(node_t * s, int i, int j, node_t * t)
{
    if (!s) {
        return NULL;
    }

    node_t head, *last = &head;
    int k = 1;
    node_t * p = s;
    while (k < i) {
        node_t * n = new node_t(p->data);
        last->next = n;
        last = n;
        p = p->next;
        ++k;
    }

    k = 1;
    while (p && k <= j) {
        p = p->next;
        ++k;
    }

    node_t * q = t;
    while (q) {
        node_t * n = new node_t(q->data);
        last->next = n;
        last = n;
        q = q->next;
    }

    while (p) {
        node_t * n = new node_t(p->data);
        last->next = n;
        last = n;
        p = p->next;
    }

    return head.next;
}

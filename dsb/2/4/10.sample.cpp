#include <stddef.h>
#include "common/dlist.h"
using namespace mustard;

typedef dlist::node<int> node_t;

void insert_before(dlist::node<int> * head, int x, int y)
{
    if (head == NULL || head->next == NULL) {
        return;
    }

    for (node_t * p = head->next; p; p = p->next) {
        if (p->data == x) {
            node_t * n = new node_t(y);
            node_t * bf = p->prev;
            bf->next = n;
            n->prev = bf;
            n->next = p;
            p->prev = n;
        }
    }
}

void insert_after(dlist::node<int> * head, int x, int y)
{
    if (head == NULL || head->next == NULL) {
        return;
    }

    for (node_t * p = head->next; p != NULL; p = p->next) {
        if (p->data == x) {
            node_t * n = new node_t(y);
            node_t * af = p->next;
            p->next = n;
            n->prev = p;
            n->next = af;
            if (af != NULL) {
                af->prev = n;
            }
            p = n;
        }
    }
}

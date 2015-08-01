#include "common/dlist.h"
#include "38_cell.h"
using namespace mustard;

typedef cell<int> cell_t;
typedef dlist::node<cell_t> node_t;

int visit(node_t * head, const int * v, int len)
{
    if (head == NULL || head->next == head) {
        return 0;
    }

    int vc = 0;
    for (int i = 0; i < len; ++i) {
        node_t * p = head->next;
        while (p != head && p->data.data != v[i]) {
            p = p->next;
        }

        if (p == head) {
            continue;
        }

        ++vc;
        p->data.freq++;

        node_t * t = p->prev;
        while (t != head && t->data.freq < p->data.freq) {
            t = t->prev;
        }

        if (t != p->prev) {
            node_t * p2 = p->next;
            node_t * p0 = p->prev;
            p0->next = p2;
            p2->prev = p0;

            node_t * t2 = t->next;
            t2->prev = p;
            p->next = t2;
            t->next = p;
            p->prev = t;
        }
    }

    return vc;
}

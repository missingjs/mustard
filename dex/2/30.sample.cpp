#include "common/slist.h"
using namespace mustard;

typedef slist::node<int> node_t;

bool forward(node_t * & pb, node_t * & pc, int & bc);

node_t * process(node_t * a, node_t * b, node_t * c)
{
    if (a == NULL || b == NULL || c == NULL) {
        return a;
    }

    node_t ah;
    ah.next = a;

    node_t *pa = a, *pa_last = &ah, *pb = b, *pc = c;
    int bc = 0;

    bool fw = forward(pb, pc, bc);

    while (pa && fw) {
        if (pa->data < bc) {
            pa_last = pa;
            pa = pa->next;
        } else {
            if (pa->data == bc) {
                pa = pa->next;
                delete pa_last->next;
                pa_last->next = pa;
            }
            fw = forward(pb, pc, bc);
        }
    }

    return ah.next;
}

bool forward(node_t * & pb, node_t * & pc, int & bc)
{
    while (pb && pc) {
        if (pb->data < pc->data) {
            pb = pb->next;
        } else if (pc->data < pb->data) {
            pc = pc->next;
        } else {
            bc = pb->data;
            pb = pb->next;
            pc = pc->next;
            return true;
        }
    }
    return false;
}

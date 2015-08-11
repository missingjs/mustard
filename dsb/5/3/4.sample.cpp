#include "common/slist.h"
using namespace mustard;

typedef slist::node<char> node_t;

node_t * remove_sub(node_t * s, node_t * t)
{
    if (!s) {
        return NULL;
    } else if (!t) {
        return s;
    }

    node_t head;
    head.next = s;

    node_t *last = &head, *ps = s, *pt = t;
    while (ps) {
        if (ps->data == t->data) {
            node_t *i = ps->next, *j = t->next;
            while (i && j) {
                if (i->data == j->data) {
                    i = i->next;
                    j = j->next;
                } else {
                    break;
                }
            }
            if (!j) {
                last->next = i;
                while (ps != i) {
                    node_t * t = ps;
                    ps = ps->next;
                    delete t;
                }
            } else if (!i) {
                break;
            } else {
                last = ps;
                ps = ps->next;
            }
        } else {
            last = ps;
            ps = ps->next;
        }
    }

    return head.next;
}

#include "def.h"
#include "common/slist.h"
using namespace mustard;

typedef dex_2::poly_term<int,int> term_t;
typedef slist::node<term_t> node_t;

node_t * to_derivative(node_t * tail)
{
    if (tail == NULL) {
        return NULL;
    } else if (tail->next == tail && tail->data.exp == 0) {
        delete tail;
        return NULL;
    }
    
    node_t head;
    head.next = tail->next;
    tail->next = NULL;

    node_t *p = head.next, *last = &head;
    while (p) {
        int c = p->data.coef;
        int e = p->data.exp;
        if (e == 0) {
            node_t * t = p;
            p = p->next;
            last->next = p;
            delete t;
        } else {
            c *= e;
            --e;
            p->data.coef = c;
            p->data.exp = e;
            last = p;
            p = p->next;
        }
    }

    last->next = head.next;

    return last;
}

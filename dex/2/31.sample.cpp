#include <cctype>
#include "common/slist.h"
using namespace mustard;

typedef slist::node<char> node_t;

void split(node_t * h, node_t * & alpha, node_t * & digit, node_t * & punct)
{
    if (h == NULL) {
        alpha = digit = punct = NULL;
        return;
    }

    node_t ah, dh, ph;
    node_t *pa = &ah, *pd = &dh, *pp = &ph;

    node_t * q = h;
    for (; q; ) {
        node_t * t = q;
        q = q->next;
        char ch = t->data;
        if (isdigit(ch)) {
            pd->next = t;
            pd = t;
        } else if (isalpha(ch)) {
            pa->next = t;
            pa = t;
        } else {
            pp->next = t;
            pp = t;
        }
    }

    if (pa != &ah) {
        pa->next = ah.next;
        alpha = pa;
    }

    if (pd != &dh) {
        pd->next = dh.next;
        digit = pd;
    }

    if (pp != &ph) {
        pp->next = ph.next;
        punct = pp;
    }
}

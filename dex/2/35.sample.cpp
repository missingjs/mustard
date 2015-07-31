#include "common/xlist.h"
using namespace mustard;

typedef xlist::node<int> node_t;

bool insert(xlist::linked_list<int> * head, int i, int x)
{
    if (head == NULL || i <= 0) {
        return false;
    }

    int c = 1;
    node_t *p = head->left, *last = NULL, *t = NULL;
    while (p && c < i) {
        t = p;
        p = _xor(p->ptr, last);
        ++c;
        last = t;
    }

    if (c < i) {
        return false;
    }

    node_t * n = new node_t(x);
    if (last) {
        node_t * last_prev = _xor(last->ptr, p);
        last->ptr = _xor(last_prev, n);
    } else {
        head->left = n;
    }

    n->ptr = _xor(last, p);

    if (p) {
        node_t * p_next = _xor(p->ptr, last);
        p->ptr = _xor(p_next, n);
    } else {
        head->right = n;
    }

    return true;
}


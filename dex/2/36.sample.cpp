#include "common/xlist.h"
using namespace mustard;

typedef xlist::node<int> node_t;

bool remove_nth(xlist::linked_list<int> * head, int i)
{
    if (head == NULL || head->left == NULL || i <= 0) {
        return false;
    }

    node_t *p = head->left, *last = NULL, *t = NULL;
    int c = 1;
    while (p && c < i) {
        t = p;
        p = _xor(p->ptr, last);
        last = t;
        ++c;
    }

    if (!p) {
        return false;
    }

    node_t *q1 = last, *p1 = _xor(p->ptr, q1);

    if (c == 1) {
        head->left = p1;
    }

    if (p == head->right) {
        head->right = q1;
    }
    
    if (q1) {
        node_t * q2 = _xor(q1->ptr, p);
        q1->ptr = _xor(q2, p1);
    }

    if (p1) {
        node_t * p2 = _xor(p1->ptr, p);
        p1->ptr = _xor(q1, p2);
    }

    delete p;

    return true;
}

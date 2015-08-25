#include "58.def.h"

node_t * find_in_order(node_t * root, char p)
{
    if (!root) {
        return NULL;
    }

    node_t * n = root;
    while (n->data.ltype != bitree::THREAD_LINK) {
        n = n->lc;
    }

    while (n && n != root && n->data.data != p) {
        if (n->data.rtype == bitree::THREAD_LINK) {
            n = n->rc;
        } else {
            n = n->rc;
            while (n->data.ltype != bitree::THREAD_LINK) {
                n = n->lc;
            }
        }
    }

    if (!n || n == root) {
        return NULL;
    } else {
        return n;
    }
}

void insert(node_t * p, node_t * x)
{
    x = x->lc;

    node_t * q = x;
    while (q->data.ltype == bitree::NODE_LINK) {
        q = q->lc;
    }

    if (p->data.ltype == bitree::THREAD_LINK) {
        q->lc = p->lc;
        x->rc = p;
        p->data.ltype = bitree::NODE_LINK;
        p->lc = x;
    } else {
        node_t * t = p->lc;
        node_t * t1 = t;
        while (t1->data.ltype == bitree::NODE_LINK) {
            t1 = t1->lc;
        }

        q->lc = t1->lc;

        t1->lc = x;
        x->data.rtype = bitree::NODE_LINK;
        x->rc = t;

        p->lc = x;
    }
}

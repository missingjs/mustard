#include "29.def.h"

node_t * insert(node_t * root, int k)
{
    if (!root) {
        return new node_t(k);
    }

    node_t * p = root;
    while (p && p->data != k) {
        if (k < p->data) {
            if (!p->lc) {
                p->lc = new node_t(k);
            }
            p = p->lc;
        }
        else {
            if (!p->rc) {
                p->rc = new node_t(k);
            }
            p = p->rc;
        }
    }
    return root;
}

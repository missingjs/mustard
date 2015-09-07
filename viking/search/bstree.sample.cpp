#include "bstree.def.h"

void _insert(node_t * & n, int k)
{
    if (!n) {
        n = new node_t(k);
        return;
    }

    if (k < n->data) {
        _insert(n->lc, k);
    } else if (k > n->data) {
        _insert(n->rc, k);
    }
}

node_t * create_bst(int * arr, int n)
{
    node_t * root = NULL;
    for (int i = 0; i < n; ++i) {
        _insert(root, arr[i]);
    }
    return root;
}

void _rm(node_t * & n, int k)
{
    if (!n) {
        return;
    } else if (k < n->data) {
        _rm(n->lc, k);
    } else if (k > n->data) {
        _rm(n->rc, k);
    } else {
        node_t * t = n;
        if (!n->lc && !n->rc) {
            n = NULL;
            delete t;
        } else if (!n->lc) {
            n = n->rc;
        } else if (!n->rc) {
            n = n->lc;
        } else {
            node_t ** p = &t->lc;
            while ((*p)->rc) {
                p = &(*p)->rc;
            }
            t = *p;
            n->data = t->data;
            *p = t->lc;
            delete t;
        }
    }
}

node_t * remove(node_t * root, int * del, int n)
{
    node_t * r = root;
    for (int i = 0; i < n; ++i) {
        _rm(r, del[i]);
    }
    return r;
}

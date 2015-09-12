#include "39.def.h"

node_t * _find_x(node_t * root, int x)
{
    if (!root) {
        return NULL;
    }
    
    if (root->data == x) {
        return NULL;
    }

    if (x < root->data) {
        node_t * p = _find_x(root->lc, x);
        if (p) {
            return p;
        } else {
            return root;
        }
    }
    else {
        return _find_x(root->rc, x);
    }
}

bool _split(node_t * root, node_t * p,
        node_t * & t1, node_t * & t2)
{
    if (!root) {
        return false;
    }

    node_t *L = NULL, *R = NULL;

    if (_split(root->lc, p, L, R)) {
        root->lc = R;
        t1 = L;
        t2 = root;
        return true;
    }

    if (root == p) {
        t1 = root->lc;
        t2 = root;
        root->lc = NULL;
        return true;
    }

    if (_split(root->rc, p, L, R)) {
        root->rc = L;
        t1 = root;
        t2 = R;
        return true;
    }

    return false;
}

void split(node_t * root, int x, node_t * & t1, node_t * & t2)
{
    if (!root) {
        return;
    }

    node_t * p = _find_x(root, x);
    if (!p) {
        if (root->data > x) {
            t2 = root;
        }
        else {
            t1 = root;
        }
        return;
    }

    _split(root, p, t1, t2);
}

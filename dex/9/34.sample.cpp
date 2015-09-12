#include "34.def.h"

node_t * _find_x(node_t * root, int x)
{
    if (!root) {
        return NULL;
    }

    if (root->data == x) {
        return root;
    }

    if (root->data > x) {
        node_t * t = _find_x(root->lc, x);
        if (t) {
            return t;
        }
        else {
            return root;
        }
    }
    else {
        return _find_x(root->rc, x);
    }
}

bool _found = false;

node_t * _release(node_t * root, node_t * p)
{
    if (!root) {
        return root;
    }

    node_t *lc = root->lc, *rc = root->rc;

    node_t * t = _release(lc, p);

    if (!_found) {
        if (root == p) {
            _found = true;
            delete root;
        }
        else {
            t = root;
        }
    }
    else {
        delete root;
    }

    rc = _release(rc, p);
    if (root == t) {
        root->rc = rc;
    }

    return t;
}

node_t * release_ge(node_t * root, int x)
{
    if (!root) {
        return NULL;
    }

    node_t * p = _find_x(root, x);
    if (!p) {
        return root;
    }

    _found = false;

    return _release(root, p);
}

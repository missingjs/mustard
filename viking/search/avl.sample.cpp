#include "avl.def.h"
#include <map>

std::map<node_t*, int>  _f_map;

void _put(node_t * n)
{
    _f_map[n] = 0;
}

void _set(node_t * n, int f)
{
    _f_map[n] = f;
}

int _get(node_t * n)
{
    return _f_map[n];
}

void _right_rotate(node_t * & n)
{
    node_t * lc = n->lc;
    n->lc = lc->rc;
    lc->rc = n;
    n = lc;
}

void _left_rotate(node_t * & n)
{
    node_t * rc = n->rc;
    n->rc = rc->lc;
    rc->lc = n;
    n = rc;
}

void _left_balance(node_t * & n)
{
    node_t * lc = n->lc;
    if (_get(lc) == 1) {
        _set(n, 0);
        _set(lc, 0);
        _right_rotate(n);
    } else {
        node_t * lcrc = lc->rc;
        switch (_get(lcrc)) {
            case 1:
                _set(lc, 0); _set(n, -1); break;
            case 0:
                _set(lc, 0); _set(n, 0); break;
            case -1:
                _set(lc, 1); _set(n, 0); break;
        }
        _set(lcrc, 0);
        _left_rotate(n->lc);
        _right_rotate(n);
    }
}

void _right_balance(node_t * & n)
{
    node_t * rc = n->rc;
    if (_get(rc) == -1) {
        _set(n, 0);
        _set(rc, 0);
        _left_rotate(n);
    } else {
        node_t * rclc = rc->lc;
        switch (_get(rclc)) {
            case 1:
                _set(rc, -1); _set(n, 0); break;
            case 0:
                _set(rc, 0); _set(n, 0); break;
            case -1:
                _set(rc, 0); _set(n, 1); break;
        }
        _set(rclc, 0);
        _right_rotate(n->rc);
        _left_rotate(n);
    }
}

void _avl_insert(node_t * & n, int k, bool & inc)
{
    if (!n) {
        n = new node_t(k);
        _put(n);
        inc = true;
        return;
    } else if (n->data == k) {
        inc = false;
        return;
    }

    if (k < n->data) {
        _avl_insert(n->lc, k, inc);
        if (!inc) {
            return;
        }
        switch (_get(n)) {
            case -1:
                _set(n, 0); inc = false; break;
            case 0:
                _set(n, 1); inc = true; break;
            case 1:
                _left_balance(n); inc = false; break;
        }
    } else {
        _avl_insert(n->rc, k, inc);
        if (!inc) {
            return;
        }
        switch (_get(n)) {
            case 1:
                _set(n, 0); inc = false; break;
            case 0:
                _set(n, -1); inc = true; break;
            case -1:
                _right_balance(n); inc = false; break;
        }
    }
}

void _insert(node_t * & root, int k)
{
    bool inc = false;
    _avl_insert(root, k, inc);
}

node_t * create_avl(int * arr, int n)
{
    if (!arr || n <= 0) {
        return NULL;
    }

    node_t * root = NULL;
    for (int i = 0; i < n; ++i) {
        _insert(root, arr[i]);
    }

    return root;
}

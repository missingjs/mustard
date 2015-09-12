#include "33.def.h"

node_t * _find_x(node_t * p, int x)
{
    if (!p) {
        return NULL;
    }

    if (p->data == x) {
        return p;
    }
    else if (p->data > x) {
        node_t * t = _find_x(p->lc, x);
        if (t) {
            return t;
        }
        else {
            return p;
        }
    }
    else {
        return _find_x(p->rc, x);
    }
}

bool _found = false;

void _rprint_until(node_t * root, node_t * p)
{
    if (!root) {
        return;
    }

    if (_found) {
        return;
    }

    _rprint_until(root->rc, p);
    if (_found) {
        return;
    }
    std::cout << root->data << ' ';
    if (root == p) {
        _found = true;
        return;
    }
    else {
        _rprint_until(root->lc, p);
    }
}

void print_ge(node_t * root, int x)
{
    if (!root) {
        return;
    }

    node_t * p = _find_x(root, x);
    if (!p) {
        return;
    }

    _found = false;
    _rprint_until(root, p);
    std::cout << '\n';
}

#include "51.def.h"

int _cmp(char c1, char c2)
{
    if (c1 == '+' || c1 == '-') {
        if (c2 == '+' || c2 == '-') {
            return 1;
        } else {
            return -1;
        }
    } else {
        return 1;
    }
}

bool _is_leaf(node_t * root)
{
    return !root->lc && !root->rc;
}

void _se(node_t * root, char * & p)
{
    if (!root) {
        return;
    }

    if (root->lc) {
        int c = _cmp(root->lc->data, root->data);
        bool leaf = _is_leaf(root->lc);
        if (!leaf && c < 0) {
            *p++ = '(';
        }
        _se(root->lc, p);
        if (!leaf && c < 0) {
            *p++ = ')';
        }
    }

    *p++ = root->data;

    if (root->rc) {
        int c = _cmp(root->data, root->rc->data);
        bool leaf = _is_leaf(root->rc);
        if (!leaf && c > 0) {
            *p++ = '(';
        }
        _se(root->rc, p);
        if (!leaf && c > 0) {
            *p++ = ')';
        }
    }
}

void show_expr(node_t * root, char * output)
{
    char * p = output;
    _se(root, p);
    *p = 0;
}

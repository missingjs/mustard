#include "36.def.h"

bool _is_b(node_t * root, int & depth)
{
    if (!root) {
        depth = 0;
        return true;
    }

    int left_d = 0, right_d = 0;
    if (!_is_b(root->lc, left_d) || !_is_b(root->rc, right_d)) {
        return false;
    }

    if (root->lc && root->lc->data > root->data) {
        return false;
    }
    if (root->rc && root->rc->data < root->data) {
        return false;
    }

    int k = left_d - right_d;
    if (k == 0 || k == -1 || k == 1) {
        depth = (left_d > right_d ? left_d : right_d) + 1;
        return true;
    }
    else
        return false;
}

bool is_balance(node_t * root)
{
    int depth = 0;
    // TODO
    return _is_b(root, depth);
}

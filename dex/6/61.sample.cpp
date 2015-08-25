#include "61.def.h"
#include <queue>

void _g(node_t * root, int seq, int & degree)
{
    if (root->lc) {
        _g(root->lc, 1, degree);
    }
    if (root->rc) {
        _g(root->rc, seq + 1, degree);
    } else if (seq > degree) {
        degree = seq;
    }
}

int _gd1(node_t * root)
{
    int deg = 0;
    _g(root, 1, deg);
}

int _gd2(node_t * root)
{
    std::queue<node_t*> qu;
    qu.push(root);

    int max_d = 0;
    while (!qu.empty()) {
        node_t * f = qu.front();
        qu.pop();
        f = f->lc;
        int c = 0;
        while (f) {
            qu.push(f);
            ++c;
            f = f->rc;
        }
        if (c > max_d) {
            max_d = c;
        }
    }

    return max_d;
}

int get_degree(node_t * root)
{
    if (!root) {
        return 0;
    }
    int d1 = _gd1(root);
    int d2 = _gd2(root);
    if (d1 != d2) {
        return -1;
    }
    return d1;
}

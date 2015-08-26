#include "71.def.h"

void _p(node_t * root, int level)
{
    if (!root) {
        return;
    }

    for (int i = 1; i < level; ++i) {
        std::cout << "  ";
    }
    std::cout << root->data << '\n';

    _p(root->lc, level + 1);
    _p(root->rc, level);
}

void print_level(node_t * root)
{
    if (!root) {
        return ;
    }

    _p(root, 1);
}

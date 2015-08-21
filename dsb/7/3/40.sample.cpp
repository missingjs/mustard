#include "common/bitree.h"
using namespace mustard;

typedef bitree::node<char> node_t;

void _rp(node_t * root, int level)
{
    if (!root) {
        return;
    }

    _rp(root->rc, level + 1);

    for (int i = 0; i < level; ++i) {
        std::cout << "  ";
    }
    std::cout << root->data << '\n';

    _rp(root->lc, level + 1);
}

void rotate_print(node_t * root)
{
    if (!root) {
        std::cout << "[empty bitree\n";
        return;
    }

    _rp(root, 0);
}

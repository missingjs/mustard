// @mission: 输出一棵二叉树所有叶子结点到根结点的路径

#include "common/bitree.h"
using namespace mustard;

typedef bitree::node<char> node_t;

void print_all_path(node_t * root);

int main()
{
    node_t * root = bitree::read<char>();

    print_all_path(root);

    delete root;

    return 0;
}

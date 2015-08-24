// @mission: 二叉树后序遍历的非递归算法

#include "common/bitree.h"
using namespace mustard;

typedef bitree::node<char> node_t;

void print_post_order(node_t * root);

int main()
{
    node_t * root = bitree::read<char>();
    print_post_order(root);
    bitree::free(root);
    return 0;
}

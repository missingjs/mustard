// @mission: 利用栈的基本操作写出中序遍历的非递归形式算法

#include "common/bitree.h"
using namespace mustard;

typedef bitree::node<char> node_t;

void print_in_order(node_t * root);

int main()
{
    node_t * root = bitree::read<char>();
    print_in_order(root);
    bitree::free(root);
    return 0;
}

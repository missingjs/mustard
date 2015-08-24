// @mission: 二叉链表结点只增设一个双亲域以指示双亲结点，不设栈进行中序遍历

#include "40.def.h"

int main()
{
    node_t * root = bitree::read<pnode>();
    init(root);
    in_order_traverse(root);
    bitree::free(root);
    return 0;
}

// @mission: 将两棵二叉排序树合并为一棵
#include "38.def.h"

int main()
{
    node_t * t1 = bitree::read<int>(
            bitree::PARENT_CHILD_FORMAT);
    node_t * t2 = bitree::read<int>(
            bitree::PARENT_CHILD_FORMAT);

    bitree::print(t1);
    bitree::print(t2);

    node_t * root = merge(t1, t2);

    bitree::print(root);

    bitree::free(root);

    return 0;
}

// @mission: 编写时间复杂度为O(logn + m)的算法，删除二叉排序树中所有关键字不小于x的结点，n为树结点个数，m为被删除结点个数
#include "34.def.h"

int main()
{
    int x = 0;
    std::cin >> x;

    node_t * root = bitree::read<int>(
            bitree::PARENT_CHILD_FORMAT);
    bitree::print(root);

    root = release_ge(root, x);
    bitree::print(root);

    bitree::free(root);
    return 0;
}

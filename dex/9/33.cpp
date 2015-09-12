// @mission: 编写递归算法，从大到小输出给定二叉排序树中所有关键字不小于x的数据元素。要求算法时间复杂度为O(logn+m)，n为排序树结点个数，m为输出的关键字个数
#include "33.def.h"

int main()
{
    int x = 0;
    std::cin >> x;

    node_t * root = bitree::read<int>(bitree::PARENT_CHILD_FORMAT);
    bitree::print(root);

    print_ge(root, x);

    bitree::free(root);
    return 0;
}

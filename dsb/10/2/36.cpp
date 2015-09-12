// @mission: 判断一个二叉树是否为平衡二叉树
#include "36.def.h"

int main()
{
    node_t * root = bitree::read<int>(bitree::PARENT_CHILD_FORMAT);

    bitree::print(root, bitree::HIERARCHY_FORMAT);

    bool r = is_balance(root);

    std::cout << std::boolalpha << r << '\n';

    bitree::free(root);

    return 0;
}

// @mission: 将一棵二叉排序树分裂为两棵，其中一棵所有结点关键字小于等于x，另一棵所有结点大于x
#include "39.def.h"

int main()
{
    node_t * root = bitree::read<int>(
            bitree::PARENT_CHILD_FORMAT);
    int x = 0;
    std::cin >> x;

    node_t *t1 = NULL, *t2 = NULL;

    bitree::print(root);

    split(root, x, t1, t2);

    bitree::print(t1);
    bitree::print(t2);

    bitree::free(t1);
    bitree::free(t2);

    return 0;
}

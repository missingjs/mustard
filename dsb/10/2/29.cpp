// @mission: 设计在二叉排序树中插入指定关键字的非递归算法
#include "29.def.h"
#include "common/array.h"

int main()
{
    int n = 0;
    int * arr = array::read<int>(n);

    node_t * root = NULL;

    for (int i = 0; i < n; ++i) {
        root = insert(root, arr[i]);
    }

    bitree::print(root, bitree::HIERARCHY_FORMAT);

    bitree::free(root);
    delete[] arr;

    return 0;
}

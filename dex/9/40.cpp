// @mission: 在平衡二叉排序树的每个结点中增设一个lsize域，其值为它的左子树的结点数加1，试写一时间复杂度为O(logn)的算法，确定树中第k小的结点的位置
#include "40.def.h"

int main()
{
    node_t * root = bitree::read<int>(
            bitree::PARENT_CHILD_FORMAT);

    int k = 0;
    std::cin >> k;

    snode * sr = to_stree(root);

    snode * n = find_kth(sr, k);

    if (n) {
        std::cout << '[' << n->data << ']' << '\n';
    }
    else {
        std::cout << "None\n";
    }

    bitree::free(root);
    release(sr);
    return 0;
}

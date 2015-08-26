// @mission: 已知一棵树的由根至叶子结点按层次输入的结点序列及每个结点的度（每层中自左至右输入），试写出构造此树的孩子-兄弟链表的算法
#include "68.def.h"
#include "common/array.h"

int main()
{
    int n = 0;
    char * ch = array::read<char>(n);
    int * degree = array::read<int>(n);

    node_t * root = build_by_seq_degree(n, ch, degree);

    bitree::print(root, bitree::CHILD_SIBLING_FORMAT);

    bitree::free(root);

    delete[] ch;
    delete[] degree;

    return 0;
}

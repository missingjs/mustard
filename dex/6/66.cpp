// @mission: 有n个结点的树T采用了双亲表示法，写出由此建立树的孩子-兄弟链表算法
#include "66.def.h"
#include "common/array.h"

int main()
{
    int n = 0;
    char * ch = array::read<char>(n);
    int * pr = array::read<int>(n);

    node_t * root = create_child_sibling(n, ch, pr);

    bitree::print(root, bitree::CHILD_SIBLING_FORMAT);

    bitree::free(root);
    delete[] ch;
    delete[] pr;

    return 0;
}

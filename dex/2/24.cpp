// @brief: 两个元素递增有序的单链表A，B，将A和B归并为一个元素递减排列的线性表C，利用原表空间构造

#include "common/slist.h"
using namespace mustard;

typedef slist::node<int> node_t;

node_t * merge_descend(node_t * a, node_t * b);

int main()
{
    node_t * a = slist::read<int>();
    node_t * b = slist::read<int>();

    node_t * c = merge_descend(a, b);

    slist::print(c);
    slist::free(c);

    return 0;
}

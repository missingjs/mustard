// @brief: 两个单链表，其元素均递增有序。试归并两个链表，并保持元素递增有序，空间复杂度限定为O(1)

#include <iostream>
#include "common/slist.h"
using namespace mustard;

slist::node<int> * merge(slist::node<int> * n1, slist::node<int> * n2);

int main()
{
    typedef slist::node<int> node_t;

    node_t * n1 = slist::read<int>();
    node_t * n2 = slist::read<int>();
    node_t * N = merge(n1, n2);

    slist::print(N);
    slist::free(N);

    return 0;
}

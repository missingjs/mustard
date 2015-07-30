// @brief: 一个含两个以上结点的循环双链表，将第一个元素值为x的结点与后继结点交换

#include "common/dlist.h"
using namespace mustard;

typedef dlist::node<int> node_t;

node_t * swap_first(node_t * tail, int x);

int main()
{
    node_t * h = dlist::read<int>();
    node_t * tail = dlist::make_circular(h);

    int x = 0;
    std::cin >> x;

    tail = swap_first(tail, x);

    h = de_circular(tail);

    dlist::print(h);
    dlist::free(h);

    return 0;
}

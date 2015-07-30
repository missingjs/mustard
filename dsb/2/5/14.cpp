// @brief: 一个循环双链表，删除第一个元素值为x的结点

#include "common/dlist.h"
using namespace mustard;

dlist::node<int> * remove_first(dlist::node<int> * tail, int x);

int main()
{
    dlist::node<int> * h = dlist::read<int>();
    dlist::node<int> * tail = dlist::make_circular(h);

    int x = 0;
    std::cin >> x;

    tail = remove_first(tail, x);

    h = de_circular(tail);
    dlist::print(h);
    dlist::free(h);

    return 0;
}

// @brief: 设有一个双链表h，设计一个算法查找第一个元素值为x的结点，将其与后继结点进行交换

#include <iostream>
#include "common/dlist.h"
using namespace mustard;

dlist::node<int> * find_first_and_swap(dlist::node<int> * n, int x);

int main()
{
    dlist::node<int> * f = dlist::read<int>();

    int x = 0;
    std::cin >> x;

    f = find_first_and_swap(f, x);

    dlist::print(f);
    dlist::free(f);

    return 0;
}

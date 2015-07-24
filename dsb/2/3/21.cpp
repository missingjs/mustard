// @brief: 带头结点单链表，元素无序，删除满足min <= x <= max之间的元素结点

#include <iostream>
#include "common/slist.h"
using namespace mustard;

void remove_range(slist::node<int> * h, int min, int max);

int main()
{
    typedef slist::node<int> node_t;

    node_t * h = slist::read<int>();
    h = slist::add_head(h);

    int min = 0, max = 0;
    std::cin >> min >> max;

    remove_range(h, min, max);

    slist::print(h->next);
    slist::free(h);

    return 0;
}

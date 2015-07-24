// @brief: C为带头结点的单链表，将奇数位和偶数位元素分别拆分，得到两个链表

#include <iostream>
#include "common/slist.h"
using namespace mustard;

void split(slist::node<int> * head, slist::node<int> * &L1, slist::node<int> * &L2);

typedef slist::node<int> node_t;

int main()
{
    node_t * head = slist::read<int>();
    head = add_head(head);

    node_t *L1 = NULL, *L2 = NULL;
    split(head, L1, L2);

    std::cout << "original list: ";
    slist::print(head->next);

    std::cout << "L1: ";
    slist::print(L1);

    std::cout << "L2: ";
    slist::print(L2);

    slist::free(head);
    slist::free(L1);
    slist::free(L2);

    return 0;
}

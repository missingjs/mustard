// @brief: 对带头结点的单链表进行递增排序

#include <iostream>
#include "common/slist.h"
using namespace mustard;

void slist_sort(slist::node<int> * head);

int main()
{
    slist::node<int> * front = slist::read<int>();
    slist::node<int> head;
    head.next = front;

    slist_sort(&head);

    slist::print(head.next);
    slist::free(head.next);

    return 0;
}

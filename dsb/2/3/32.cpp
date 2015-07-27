// @brief: 递增有序带头结点的单链表，向其插入值x，保持有序

#include <iostream>
#include "common/slist.h"
using namespace mustard;

void insert(slist::node<int> * head, int x);

int main()
{
    slist::node<int> * front = slist::read<int>();
    slist::node<int> head;
    head.next = front;

    int x;
    std::cin >> x;

    insert(&head, x);

    slist::print(head.next);
    slist::free(head.next);

    return 0;
}

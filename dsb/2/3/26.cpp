// @brief: 从带头结点的单链表中删除一个最小值结点

#include "common/slist.h"
using namespace mustard;

void remove_min(slist::node<int> * head);

int main()
{
    slist::node<int> * front = slist::read<int>();

    slist::node<int> head;
    head.next = front;

    remove_min(&head);

    slist::print(head.next);
    slist::free(head.next);

    return 0;
}

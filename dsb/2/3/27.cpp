// @brief: 将带头结点单链表逆置，空间复杂度为O(1)

#include "common/slist.h"
using namespace mustard;

void reverse(slist::node<int> * head);

int main()
{
    slist::node<int> * front = slist::read<int>();

    slist::node<int> head;
    head.next = front;

    reverse(&head);

    slist::print(head.next);
    slist::free(head.next);

    return 0;
}

// @brief: 分别在带头结点的双链表中元素值为x的结点之前、之后插入元素值为y的结点，分别编写各自算法

#include <iostream>
#include "common/dlist.h"
using namespace mustard;

void insert_before(dlist::node<int> * head, int x, int y);

void insert_after(dlist::node<int> * head, int x, int y);

int main()
{
    dlist::node<int> * front = dlist::read<int>();
    dlist::node<int> head;
    head.next = front;
    front->prev = &head;

    int x = 0, y = 0;
    std::cin >> x >> y;

    insert_before(&head, x, y);

    insert_after(&head, x, y);

    dlist::print(head.next);
    dlist::free(head.next);

    return 0;
}

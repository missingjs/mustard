// @brief: A为带头结点单链表，将A元素按奇偶数拆分为两个链表，并保持原来相对顺序
#include "common/slist.h"
using namespace mustard;

void split(slist::node<int> * head_a, slist::node<int> * &b, slist::node<int> * &c);

int main()
{
    slist::node<int> * a = slist::read<int>();
    slist::node<int> head;
    head.next = a;

    slist::node<int> *b = NULL, *c = NULL;

    split(&head, b, c);

    slist::print(b);
    slist::print(c);

    slist::free(b);
    slist::free(c);

    return 0;
}

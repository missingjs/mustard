// @brief: 带头结点双向循环线性链表L=(a1,a2,...,an)，写一时间复杂度为O(n)的算法，将L改造为L=(a1,a3,...,an,...,a4,a2)

#include "common/dlist.h"
using namespace mustard;

typedef dlist::node<int> node_t;

void adjust(node_t * head);

int main()
{
    node_t * h = dlist::read<int>();
    node_t * tail = dlist::make_circular(h);

    node_t head;
    if (tail) {
        head.next = tail->next;
        tail->next = &head;
        head.next->prev = &head;
        head.prev = tail;
    } else {
        head.next = head.prev = &head;
    }

    adjust(&head);

    // de-circular
    if (head.next != &head) {
        head.prev->next = NULL;
    } else {
        head.next = head.prev = NULL;
    }

    dlist::print(head.next);
    dlist::free(head.next);

    return 0;
}

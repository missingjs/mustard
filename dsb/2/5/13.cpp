// @brief: 将一个循环单链表逆置

#include "common/slist.h"
using namespace mustard;

slist::node<int> * reverse_circular_list(slist::node<int> * tail);

int main()
{
    slist::node<int> * h = slist::read<int>();
    slist::node<int> * tail = slist::make_circular(h);

    tail = reverse_circular_list(tail);
    if (tail) {
        h = tail->next;
    } else {
        h = NULL;
    }

    slist::print(h);
    slist::free(h);

    return 0;
}


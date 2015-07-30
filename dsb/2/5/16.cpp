// @bfief: 倒置一个循环双链表

#include "common/dlist.h"
using namespace mustard;

typedef dlist::node<int> node_t;

node_t * reverse(node_t * tail);

int main()
{
    node_t * h = dlist::read<int>();
    node_t * tail = dlist::make_circular(h);

    tail = reverse(tail);

    h = de_circular(tail);

    dlist::print(h);
    dlist::free(h);

    return 0;
}

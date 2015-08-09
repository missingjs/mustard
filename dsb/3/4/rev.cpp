// @mission: 利用递归倒置单链表，并改写为非递归形式

#include "common/slist.h"
using namespace mustard;

typedef slist::node<int> node_t;

node_t * reverse(node_t * h);
node_t * reverse2(node_t * h);

int main()
{
    node_t * h = slist::read<int>();
    node_t * h2 = slist::clone(h);

    h = reverse(h);
    h2 = reverse2(h2);

    slist::print(h);
    slist::print(h2);

    slist::free(h);
    slist::free(h2);

    return 0;
}

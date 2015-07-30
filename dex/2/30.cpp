// @brief: A,B,C是三个递增有序的线性表，对A作如下操作：删去既在B中又在C中出现的元素。以单链表形式存储，且不得申请额外空间存储中间结果

#include "common/slist.h"
using namespace mustard;

typedef slist::node<int> node_t;

node_t * process(node_t * a, node_t * b, node_t * c);

int main()
{
    node_t * a = slist::read<int>();
    node_t * b = slist::read<int>();
    node_t * c = slist::read<int>();

    a = process(a, b, c);

    slist::print(a);

    slist::free(a);
    slist::free(b);
    slist::free(c);

    return 0;
}


// @brief: 删除非有序单链表中值域重复的结点

#include "common/slist.h"
using namespace mustard;

void remove_dup_unseq(slist::node<int> * h);

int main()
{
    slist::node<int> * h = slist::read<int>();

    remove_dup_unseq(h);

    slist::print(h);
    slist::free(h);

    return 0;
}

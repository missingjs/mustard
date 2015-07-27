// @brief: 删除递增单链表值域重复的结点

#include "common/slist.h"
using namespace mustard;

void remove_dup(slist::node<int> * h);

int main()
{
    slist::node<int> * h = slist::read<int>();

    remove_dup(h);

    slist::print(h);
    slist::free(h);

    return 0;
}

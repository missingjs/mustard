// @brief: 判断单链表L是否递增

#include <iostream>
#include "common/slist.h"
using namespace mustard;

bool is_increment(slist::node<int> * h);

int main()
{
    slist::node<int> * h = slist::read<int>();

    bool is_inc = is_increment(h);

    slist::free(h);

    std::cout << is_inc << std::endl;

    return 0;
}

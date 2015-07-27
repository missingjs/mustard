// @brief: 两个单链表A和B，判断B是否是A的子序列
#include <iostream>
#include "common/slist.h"
using namespace mustard;

bool is_sub_list(slist::node<int> * a, slist::node<int> * b);

int main()
{
    slist::node<int> * a = slist::read<int>();
    slist::node<int> * b = slist::read<int>();

    std::cout << std::boolalpha << is_sub_list(a, b) << '\n';

    slist::free(a);
    slist::free(b);

    return 0;
}

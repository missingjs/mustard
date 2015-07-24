// @brief: 删除单链表L中值为x的结点的直接前驱

#include <iostream>
#include "common/slist.h"
using namespace mustard;

// @return: 返回处理后链表首结点
slist::node<int> * remove_prev_x(slist::node<int> * head, int x); 

int main()
{
    slist::node<int> * head = slist::read<int>();

    int x = 0;
    std::cin >> x;

    head = remove_prev_x(head, x);

    slist::print(head);
    slist::free(head);

    return 0;
}

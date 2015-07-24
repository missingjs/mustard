// @brief: 删除递增有序链表中m和n之间的元素(m <= x <= n)

#include <iostream>
#include "common/slist.h"
using namespace mustard;

// @return: 返回处理后的表头指针
slist::node<int> * remove_range(slist::node<int> * h, int min, int max);

int main()
{
    typedef slist::node<int> node_t;

    node_t * h = slist::read<int>();

    int min = 0, max = 0;
    std::cin >> min >> max;

    h = remove_range(h, min, max);

    slist::print(h);
    slist::free(h);

    return 0;
}

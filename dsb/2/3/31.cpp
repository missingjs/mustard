// @brief: 递增有序单链表A、B、C分别存储一个集合，试实现A=Av(B^C)，并使A仍保持递增，要求算法时间 复杂度为O(|A|+|B|+|C|)

#include "common/slist.h"
using namespace mustard;

slist::node<int> * process(slist::node<int> * a, slist::node<int> * b, slist::node<int> * c);

int main()
{
    slist::node<int> * a = slist::read<int>();
    slist::node<int> * b = slist::read<int>();
    slist::node<int> * c = slist::read<int>();

    a = process(a, b, c);
    slist::print(a);

    slist::free(a);
    slist::free(b);
    slist::free(c);

    return 0;
}

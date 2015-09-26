// @mission: 对单链表实现快速排序
#include "46.def.h"

int main()
{
    node_t * h = slist::read<int>();

    h = list_qsort(h);

    slist::print(h);

    slist::free(h);
    return 0;
}

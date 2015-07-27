// @brief: 三个非递减有序（可能存在重复值）单链表ABC，使A中留下3表中均包含值的结点，释放其它结点，限定算法时间复杂度为O(|A|+|B|+|C|)
#include "common/slist.h"
using namespace mustard;

typedef slist::node<int> node_t;

node_t * unify(node_t * a, node_t * b, node_t * c);

int main()
{
    node_t * a = slist::read<int>();
    node_t * b = slist::read<int>();
    node_t * c = slist::read<int>();

    a = unify(a, b, c);
    slist::print(a);

    slist::free(a);

    return 0;
}

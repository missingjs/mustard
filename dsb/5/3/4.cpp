// @mission: 给定子串，从主串中删除全部子串

#include "common/slist.h"
using namespace mustard;

typedef slist::node<char> node_t;

node_t * remove_sub(node_t * s, node_t * t);

int main()
{
    node_t * s = slist::read<char>();
    node_t * t = slist::read<char>();

    s = remove_sub(s, t);

    slist::print(s);

    slist::free(s);
    slist::free(t);

    return 0;
}

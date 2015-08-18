// @mission: 以链表结构（带头结点）表示字符串，实现基于此结构的KMP算法，并打印主串中所有匹配位置（位置计数从0开始）

#include "common/slist.h"
using namespace mustard;

typedef slist::node<char> node_t;

void linked_kmp(node_t * str, node_t * pat);

int main()
{
    node_t * str = slist::read<char>();
    node_t * pat = slist::read<char>();

    str = add_head(str);
    pat = add_head(pat);

    linked_kmp(str, pat);

    slist::free(str);
    slist::free(pat);

    return 0;
}

